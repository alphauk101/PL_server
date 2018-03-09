#include "led_man.h"
#include "Adafruit_NeoPixel.h"


Adafruit_NeoPixel pixels = Adafruit_NeoPixel(PIXELS, LED_PIN, NEO_GRB + NEO_KHZ800);

void pl_led_man::init_led()
{
  pixels.begin(); // This initializes the NeoPixel library.

  all_colour(pixels.Color(255, 0, 0));
  delay(250);
  all_colour(pixels.Color(0, 255, 0));
  delay(250);
  all_colour(pixels.Color(0, 0, 255));
  delay(250);
  all_colour(pixels.Color(255, 255, 255));
  delay(500);
  pixels.clear();
}

void pl_led_man::all_off()
{
  pixels.clear();
  pixels.show();
}

void pl_led_man::all_colour(uint32_t colour)
{
  pixels.setPixelColor(0, colour);
  pixels.setPixelColor(1, colour);
  pixels.setPixelColor(2, colour);
  pixels.show();
}

void pl_led_man::network_state(int state)
{
  switch (state) {
    case NETWORK_BUSY:
      pixels.setPixelColor(NW_LED, pixels.Color(255, 255, 0));
      break;
    case NETWORK_OK:
      pixels.setPixelColor(NW_LED, pixels.Color(0, 255, 0));
      break;
    case NETWORK_FAIL:
      pixels.setPixelColor(NW_LED, pixels.Color(255, 0, 0));
      break;
    default:
      break;
  }
  pixels.show();
}

