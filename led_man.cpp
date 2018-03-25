#include "led_man.h"
#include "Adafruit_NeoPixel.h"


Adafruit_NeoPixel pixels = Adafruit_NeoPixel(PIXELS, LED_PIN, NEO_GRB + NEO_KHZ800);

void pl_led_man::init_led()
{
  pixels.begin(); // This initializes the NeoPixel library.

  all_colour(LED_RED);
  delay(250);
  all_colour(LED_GREEN);
  delay(250);
  all_colour(LED_BLUE);
  delay(250);
  all_colour(LED_WHITE);
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

<<<<<<< HEAD
<<<<<<< HEAD
void pl_led_man::app_state(int state)
{

  switch (state)
  {
    case APP_OK:
      led_data.app_colour = LED_BLUE;
      break;
    case APP_ERROR:
      led_data.app_colour = LED_RED;
      break;
    default:
      break;
  }
  show_pix();
}

void pl_led_man::lora_state(int state)
{
  switch (state)
  {
    case LORA_OK:
      led_data.lora_colour = LED_GREEN;
      break;
    case LORA_BUSY:
      led_data.lora_colour = LED_AMBER;
      break;
    case LORA_FAIL:
      led_data.lora_colour = LED_RED;
      break;
    default:
      break;
  }
  show_pix();
}

=======
>>>>>>> parent of 8491489... updates
=======
>>>>>>> parent of 8491489... updates
void pl_led_man::network_state(int state)
{
  switch (state) {
    case NETWORK_BUSY:
<<<<<<< HEAD
<<<<<<< HEAD
      led_data.net_colour = LED_AMBER;
      break;
    case NETWORK_OK:
      led_data.net_colour = LED_GREEN;
      break;
    case NETWORK_FAIL:
      led_data.net_colour = LED_RED;
=======
      pixels.setPixelColor(NW_LED, pixels.Color(255, 255, 0));
      break;
    case NETWORK_OK:
      pixels.setPixelColor(NW_LED, pixels.Color(0, 255, 0));
      break;
    case NETWORK_FAIL:
      pixels.setPixelColor(NW_LED, pixels.Color(255, 0, 0));
>>>>>>> parent of 8491489... updates
=======
      pixels.setPixelColor(NW_LED, pixels.Color(255, 255, 0));
      break;
    case NETWORK_OK:
      pixels.setPixelColor(NW_LED, pixels.Color(0, 255, 0));
      break;
    case NETWORK_FAIL:
      pixels.setPixelColor(NW_LED, pixels.Color(255, 0, 0));
>>>>>>> parent of 8491489... updates
      break;
    default:
      break;
  }
  pixels.show();
}

