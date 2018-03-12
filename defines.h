#ifndef __DEFINES__
#define __DEFINES__

#define DEBUG_ENABLED
/*HTTP REQUEST DEFINES*/
#define HTTP_HOST       "Host: usingnfc.com"
/*GET for the login*/
#define HTTP_REQ_LOGIN  "GET /dev/lora/test.php HTTP/1.1"

/*Lora module pins*/
#define RFM95_CS_PIN        10/*Chip select*/
#define RFM95_RST_PIN       9/*Reset*/
#define RFM95_INT_PIN       2/*Interrupt GPIO0*/
/*Lora defines*/
#define RF95_FREQ           868.0
#define POWER_LEVEL         23

/*Network states*/
#define NONE               0
#define SUCCESS            1
#define TIMED_OUT         -1
#define INVALID_SERVER    -2
#define TRUNCATED         -3
#define INVALID_RESPONSE  -4

/*defines for states*/
#define OK                0
#define RENEW_FAILED      1
#define RENEW_SUCCESS     2
#define REBIND_FAIL       3
#define REBIND_SUCCESS    4

#define NETWORK_BUSY      0
#define NETWORK_OK        1
#define NETWORK_FAIL      2

#define APP_OK            0
#define APP_ERROR         1

#define LORA_OK           0
#define LORA_BUSY         1
#define LORA_FAIL         2

/*LED defines*/
#define LED_FULL          125/*Brightness ie. the brightess we ever go full bright is abit over whelming*/
#define LED_RED           pixels.Color(LED_FULL, 0, 0)
#define LED_GREEN         pixels.Color(0, LED_FULL, 0)
#define LED_BLUE          pixels.Color(0, 0, LED_FULL)
#define LED_AMBER         pixels.Color(LED_FULL, LED_FULL, 0)
#define LED_WHITE         pixels.Color(LED_FULL, LED_FULL, LED_FULL)

#endif
