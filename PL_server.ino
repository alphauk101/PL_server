#include <SPI.h>
/*Private Libraries*/
#include "ethernet.h"
#include "defines.h"
#include "led_man.h"
/*The ethernet controller class*/
pl_ethernet ethernet;
/*led_manager*/
pl_led_man led_man;


void setup() {

#ifdef DEBUG_ENABLED
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  Serial.println("Starting PL Server");

  /*Initiate the LEDS*/
  led_man.init_led();
  led_man.all_off();
  led_man.app_state(APP_OK);
#endif
  pinMode(4,OUTPUT);
  digitalWrite(4,HIGH); //deselect the lora
  ethernet.net_init();
}


void loop() {



  //This is our worker function for the ethernet must be called regularly
  ethernet.check_net();
  delay(250);
}

