#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <WiFiUdp.h>
#include <ESP8266HTTPClient.h>

const char *ssid = "Natipinyan";
const char *pswd = "11223344";

WiFiClient client;
int server_port = 80;

unsigned long Get_Data()
{
    unsigned long ret = -1;
    HTTPClient http;
    String dataURL = "http://api.kits4.me/GEN/api.php?";
    dataURL += "ACT=GET&DEV=1121&CH=1";
    http.begin(client, dataURL);
    int httpCode = http.GET();
    Serial.println(httpCode);
    if (httpCode == HTTP_CODE_OK)
    {
        Serial.print("HTTP response code ");
        Serial.println(httpCode);
        String Res = http.getString();
        Serial.println(Res);
        ret = Res.toInt();
    }
    http.end();
    return ret;
}

void Update_Data(unsigned long data)
{
    HTTPClient http;
    String dataURL = "http://api.kits4.me/GEN/api.php?";
    dataURL += "ACT=SET&DEV=1121&CH=1&VAL=";
    dataURL += String(data);
    http.begin(client, dataURL);
    int httpCode = http.GET();
    Serial.println(httpCode);
    if (httpCode == HTTP_CODE_OK)
    {
        Serial.print("HTTP response code ");
        Serial.println(httpCode);
    }
    http.end();
}