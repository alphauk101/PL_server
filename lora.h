#ifndef __LORA__
#define __LORA__
#include "led_man.h"
#include "defines.h"
#include <SPI.h>
#include "WS_RadioHead/RH_RF95.h"

class pl_lora_man {
  public:
    bool* lora_init(void);
    int16_t rssi(void);
  private:
    void module_reset(void);
    void wait_for_packet(void);
    
    bool OPERATIONAL;/*if set to true the app can assume that the lora is working ok*/
};
#endif
