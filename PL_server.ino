#include <SPI.h>
/*Private Libraries*/
#include "ethernet.h"
#include "defines.h"
#include "led_man.h"
//#include "lora.h"
/*The ethernet controller class*/
pl_ethernet net_man;
/*led_manager*/
pl_led_man led_man;
/*Lora manager*/
//pl_lora_man lora_man;

typedef struct{
  bool*   lora_state;
  bool*   net_state;
}PERI_STATES;
static PERI_STATES peri_states;

void setup() {

#ifdef DEBUG_ENABLED
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  Serial.println("Starting PL Server");
#endif
  /*Initiate the LEDS*/
  led_man.init_led();
  led_man.all_off();
  led_man.app_state(APP_OK);

  pinMode(RFM95_CS_PIN,OUTPUT);
  digitalWrite(RFM95_CS_PIN,HIGH); //deselect the lora to make sure it doesnt mess with the ethernet

  /*Init ethernet*/
  peri_states.net_state = net_man.net_init();

  /*init lora*/
  //peri_states.lora_state = lora_man.lora_init();
}


void loop() {



  //This is our worker function for the ethernet must be called regularly
  //net_man.check_net();
  delay(250);
}

