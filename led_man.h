#ifndef __LED_MAN__
#define __LED_MAN__
#include <stdint.h>
#include "defines.h"

#define NW_LED            0
#define APP_LED           1
#define LORA_LED          2

typedef struct{
  uint32_t  net_colour;
  uint32_t  app_colour;
  uint32_t  lora_colour;
}LED_DATA;

class pl_led_man{
  public:
    void init_led(void);
    void all_off(void);
    void network_state(int);
    void app_state(int);
    void lora_state(int);
  private:
    void all_colour(uint32_t);
    void show_pix(void);
    LED_DATA  led_data;
};

#endif

