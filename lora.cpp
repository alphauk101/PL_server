#include "lora.h"
extern pl_led_man led_man;

// Singleton instance of the radio driver
RH_RF95 rf95(RFM95_CS_PIN, RFM95_INT_PIN);

bool* pl_lora_man::lora_init()
{
  /*First set the lora led to busy*/
  led_man.lora_state(LORA_BUSY);
  /*Once we have done the lora init we can set the led*/

  /*Set reset appropriately*/
  pinMode(RFM95_RST_PIN, OUTPUT);
  digitalWrite(RFM95_RST_PIN, HIGH);
  /*reset the module*/
  this->module_reset();

  if (rf95.init()) {
    if (rf95.setFrequency(RF95_FREQ)) {
      rf95.setTxPower(POWER_LEVEL, false);
      led_man.lora_state(LORA_OK);
      OPERATIONAL = true;
    } else {
      led_man.lora_state(LORA_FAIL);
      OPERATIONAL = false;/*failed setting frequency*/
    }
  } else {
    led_man.lora_state(LORA_FAIL);
    OPERATIONAL = false; /*failed setting frequency*/
  }
  /*The op state may change during the app so we need to be monitor it from the main*/
  return &OPERATIONAL;
}

/*returns the last know RSSI this may be useful*/
int16_t pl_lora_man::rssi()
{
  return rf95.lastRssi();
}

/*Allows the lora to block until packet sent*/
void pl_lora_man::wait_for_packet() {
  rf95.waitPacketSent();
}

/*Reset the module*/
void pl_lora_man::module_reset()
{
  digitalWrite(RFM95_RST_PIN, LOW);
  delay(10);
  digitalWrite(RFM95_RST_PIN, HIGH);
  delay(10);
}

