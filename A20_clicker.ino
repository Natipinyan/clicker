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

void LED_On(int Red, int Green, int Blue)
{
  analogWrite(PIN_LED_R, Red);
  analogWrite(PIN_LED_G, Green);
  analogWrite(PIN_LED_B, Blue);
}
void LED_Off()
{
  analogWrite(PIN_LED_R, 0);
  analogWrite(PIN_LED_G, 0);
  analogWrite(PIN_LED_B, 0);
}
