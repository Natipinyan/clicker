#define DISPLAY_MODE D2
bool isDispalyMode;
bool isSetuped;
void setup()
{
    Serial.begin(9600);
    pinMode(DISPLAY_MODE, INPUT_PULLUP);
    isSetuped = false;
    wifiClient_Setup();
    BTN_setup();
    LED_setup();
}
void loop()
{
    isDispalyMode = (digitalRead(DISPLAY_MODE) == LOW) ? true : false;
    if (isDispalyMode)
    {
        if (!isSetuped)
        {
            wifiServer_Setup();
            isSetuped = true;
        }
        wifiServer_loop();
    }
    else
    {
        if (isSetuped)
        {
            wifiClient_Setup();
            isSetuped = false;
        }
        BTN_loop();
        LED_loop();
    }
}