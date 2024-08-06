#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

IPAddress apIP(55, 55, 55, 55);

const char *ServerSsid = "Nati_WiFi";

ESP8266WebServer server(80);

void wifiServer_Setup()
{
  WiFi.mode(WIFI_AP_STA);
  WiFi.softAPConfig(apIP, apIP, IPAddress(255, 255, 255, 0));

  WiFi.softAP(ServerSsid);

  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);
  server.on("/", handleRoot);
  server.onNotFound(handleNotFound);
  server.begin();
  Serial.println("HTTP server started");
}
void wifiServer_loop()
{
  server.handleClient();
  delay(10);
}
void handleRoot()
{
  char HTML[2000] = "";
  Head(HTML);

  strcat(HTML, "</head>");
  strcat(HTML, "<body>");
  strcat(HTML, "<h2>הסטוריית לחיצות</h2>");
  strcat(HTML, "<table>");
  strcat(HTML, "<tr>");
  strcat(HTML, "<th>Press Resulte</th>");
  strcat(HTML, "<th>Broke A Record</th>");
  strcat(HTML, "</tr>");
  int tmpCnt = cntHistory;
  char timeToString[10];
  do
  {
    if (resultsHistory[tmpCnt]->GetResulte() != -1)
    {
      strcat(HTML, "<tr>");
      strcat(HTML, "<td>");
      itoa(resultsHistory[tmpCnt]->GetResulte(), timeToString, 10);
      strcat(HTML, timeToString);
      strcat(HTML, "</td>");
      strcat(HTML, "<td>");
      if (resultsHistory[tmpCnt]->GetBetterResulte())
        strcat(HTML, "true");
      else
        strcat(HTML, "false");
      strcat(HTML, "</td>");
      strcat(HTML, "</tr>");
    }
    tmpCnt = (tmpCnt == 0) ? 10 : tmpCnt;
    tmpCnt--;
  } while (tmpCnt != cntHistory);
  strcat(HTML, "</table>");
  strcat(HTML, "</body>");
  strcat(HTML, "</html>");
  server.send(200, "text/html", HTML);
}
void handleNotFound()
{
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET) ? "GET" : "POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";

  for (uint8_t i = 0; i < server.args(); i++)
  {
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }
  server.send(404, "text/plain", message);
}
