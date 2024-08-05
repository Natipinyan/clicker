#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

IPAddress apIP(55, 55, 55, 55);

const char *ssid = "Michael WiFi";

ESP8266WebServer server(80);

void wifi_Setup()
{
    WiFi.mode(WIFI_AP_STA);
    WiFi.softAPConfig(apIP, apIP, IPAddress(255, 255, 255, 0));

    WiFi.softAP(ssid);

    IPAddress myIP = WiFi.softAPIP();
    Serial.print("AP IP address: ");
    Serial.println(myIP);
    server.on("/", handleRoot);
    server.onNotFound(handleNotFound);
    server.begin();
    Serial.println("HTTP server started");
}
void wifi_loop()
{
    server.handleClient();
    delay(10);
}
