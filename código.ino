#include <ESP8266WiFi.h>

const char* ssid = "SSID DE LA RED";
const char* password = "CONTRASEÑA DE LA RED";
const IPAddress staticIP(192, 168, 1, 180);
const IPAddress gateway(192, 168, 1, 1);
const IPAddress subnet(255, 255, 255, 0);

WiFiServer server(80);

const int relayPin = D8;  // Pin connected to the relay module

void setup() {
  Serial.begin(115200);
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, LOW);

  WiFi.config(staticIP, gateway, subnet);
  
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Conectando...");
  }
  Serial.println("Conexion exitosa, IP: ");
  Serial.println(WiFi.localIP());
  server.begin();
}

void loop() {
  WiFiClient client = server.available();
  if (client) {
    String request = client.readStringUntil('\r');
    client.flush();

    if (request.indexOf("/relay/on") != -1) {
      digitalWrite(relayPin, HIGH);
      delay(3000);
      client.println("Encendido durante 3 segundos.");
      Serial.println("---ON---");
      digitalWrite(relayPin, LOW);
      Serial.println("---OFF---");
    }

    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html");
    client.println();
    client.println("<!DOCTYPE HTML>");
    client.println("<html>");
    client.println("<head>");
    client.println("<style>");
    client.println("body { background-color: #708090; text-align: center; }");
    client.println("button { font-size: 40px; height: 500px; width: 500px; background-color: #6495ED; color: #FFFFFF; font-weight: bold; border: 2px solid black; border-radius: 50px; }");
    client.println("</style>");
    client.println("</head>");
    client.println("<body>");
    client.println("<button onclick=\"turnOnRelay()\">ABRIR / CERRAR</button>");
    client.println("</body>");
    client.println("<script>function turnOnRelay(){var xhr = new XMLHttpRequest();xhr.open('GET', '/relay/on', true);xhr.send();}</script>");
    client.println("</html>");
    delay(5);
    client.stop();
  }
}
