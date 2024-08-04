#define PIN_LED_R D7
#define PIN_LED_G D6
#define PIN_LED_B D5

#define NEW_RECORD 20
#define FAILURE 30
#define REDY_TO_PLAY 40

int playerRollStatus = REDY_TO_PLAY;

void LED_setup()
{
    pinMode(PIN_LED_R, OUTPUT);
    pinMode(PIN_LED_G, OUTPUT);
    pinMode(PIN_LED_B, OUTPUT);
}
