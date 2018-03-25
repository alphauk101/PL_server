#include "ethernet.h"
extern pl_led_man led_man;

// Initialize the Ethernet client library
// with the IP address and port of the server
// that you want to connect to (port 80 is default for HTTP):
EthernetClient client;

char server[] = "usingnfc.com";


/*MAC address for device*/
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress ip(192, 168, 0, 177);

/*Initialise our ethernet adapter*/
bool* pl_ethernet::net_init() {

  led_man.network_state(NETWORK_BUSY);

  memset(&net_status, 0, sizeof(net_status));

  /*We need to init our hardware and check whether we are functioning or not*/
  debug("Starting ethernet...");

  //if(Ethernet.begin(mac) != 0) 
  Ethernet.begin(mac, ip);
  if(true)
  {
    /*Give the hw a sec to init*/
    delay(1000);
    debug("OK");

   net_status.DHCP_state = Ethernet.maintain();/*Wont do anything at this point but useful to update*/
   net_status.ip_address = Ethernet.localIP();/*Capture the IP address*/

#ifdef DEBUG_ENABLED
    Serial.print("IP: ");
    Serial.print(net_status.ip_address[0]);
    Serial.print(".");
    Serial.print(net_status.ip_address[1]);
    Serial.print(".");
    Serial.print(net_status.ip_address[2]);
    Serial.print(".");
    Serial.println(net_status.ip_address[3]);
#endif

    net_status.HW_status = true;

    debug("Connecting to logon server...");
    /*Send a init state to our server*/

    connect_server(server, 80);
    /*Check whether this was successful*/
    if (net_status.connect_req_state == SUCCESS)
    {
      /*Do req*/
      request_login_stamp();
      /*Disconnect from server*/
      disc_server();
      led_man.network_state(NETWORK_OK);
      debug("Ethernet setup and network connectivity OK");
    } else {
      net_status.HW_status = false;
      debug("Connection to logon server failed.");
    }

  } else {

    debug("Failed to init ethernet hardware");
    /*We cannot connect to the network */
    net_status.HW_status = false;
    led_man.network_state(NETWORK_FAIL);
  }

  return &net_status.HW_status;
}

/*This needs to be called from main regularly*/
void pl_ethernet::check_net()
{
  led_man.network_state(NETWORK_BUSY);
  net_status.DHCP_state = Ethernet.maintain();/*Wont do anything at this point but useful to update*/
  check_dhcpstate();
}

void pl_ethernet::check_dhcpstate()
{
  switch (net_status.DHCP_state)
  {
    case OK:
    case RENEW_SUCCESS:
    case REBIND_SUCCESS:
      /*These are all good states*/
      led_man.network_state(NETWORK_OK);
      net_status.HW_status = true;
      break;
    case RENEW_FAILED:
      debug("RENEW FAILED");
      led_man.network_state(NETWORK_FAIL);
      net_status.HW_status = false;
      break;
    case REBIND_FAIL:
      debug("REBIND FAILED");
      led_man.network_state(NETWORK_FAIL);
      net_status.HW_status = false;
      break;
    default:
      break;
  }


}

/*Sends a time stamp to the login server to show or power up has happened*/
void pl_ethernet::request_login_stamp()
{
  /**Do HTTP get request for login*/
  client.println(HTTP_REQ_LOGIN);
  client.println(HTTP_HOST);
  client.println("Connection: close");
  client.println();
}

void pl_ethernet::connect_server(char* server, int port)
{
#ifdef DEBUG_ENABLED
  Serial.print("Attempt connection to: ");
  Serial.print(server);
  Serial.print(":");
  Serial.println(port, DEC);
#endif
  /*This will make the request and put the state into our struct*/
  net_status.connect_req_state = client.connect(server, port);
  
#ifdef DEBUG_ENABLED
  debug("Client connect state: ");
  Serial.println(net_status.connect_req_state, DEC);
#endif
}

void pl_ethernet::disc_server()
{
  if (!client.connected()) {
    client.stop();
    debug("Disconnected from server.");
  } else {
    debug("ALREADY Disconnected from server.");
  }

}


void pl_ethernet::debug(String msg)
{
#ifdef DEBUG_ENABLED
  Serial.println(msg);
#endif
}

