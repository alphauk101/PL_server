#ifndef __LED_MAN__
#define __LED_MAN__
#include <stdint.h>
#include "defines.h"

#define NW_LED            0
#define STATE_LED         1

class pl_led_man{
  public:
    void init_led(void);
    void all_off(void);
    void network_state(int);
  private:
    void all_colour(uint32_t);
};

#endif

