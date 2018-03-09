#ifndef __ETHERNET__
#define __ETHERNET__
#include <Dhcp.h>
#include <Dns.h>
#include <Ethernet.h>
#include <EthernetClient.h>
#include <EthernetUdp.h>
#include "led_man.h"
#include "defines.h"



typedef struct{
  bool        HW_status; /*bool represents hw working or not.*/

  uint8_t     DHCP_state; /*DHCP state*/

  IPAddress   ip_address;/*Our ip addres*/

  uint8_t     connect_req_state;/*last state of the connection request*/
}NET_STATUS;


class pl_ethernet
{
  public:
    bool* net_init(void);
    void check_net(void);
  private:
  void debug(String);
  void connect_server(char*, int);
  void disc_server(void);
  void request_login_stamp(void);
  void check_dhcpstate(void);
  
  NET_STATUS  net_status;
  
};



#endif
