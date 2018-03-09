#ifndef __DEFINES__
#define __DEFINES__

#define DEBUG_ENABLED
/*HTTP REQUEST DEFINES*/
#define HTTP_HOST       "Host: usingnfc.com"
/*GET for the login*/
#define HTTP_REQ_LOGIN  "GET /dev/lora/test.php HTTP/1.1"

#define NONE               0
#define SUCCESS            1
#define TIMED_OUT         -1
#define INVALID_SERVER    -2
#define TRUNCATED         -3
#define INVALID_RESPONSE  -4

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

#define LED_FULL          125
#endif
