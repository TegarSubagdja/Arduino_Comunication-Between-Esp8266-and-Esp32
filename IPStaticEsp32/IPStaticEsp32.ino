#include <WiFi.h>
#include <IPAddress.h>

const char* ssid = "Nama_SSID_Anda";
const char* password = "Password_Anda";
const IPAddress staticIP(192, 168, 1, 100); // Alamat IP statis yang ingin digunakan
const IPAddress gateway(192, 168, 1, 1);     // Alamat gateway
const IPAddress subnet(255, 255, 255, 0);   // Subnet mask
WiFiServer server(80);

void setup() {
  Serial.begin(9600);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  // Mengatur IP statis
  WiFi.config(staticIP, gateway, subnet);

  server.begin();
  Serial.println("Connected to WiFi");
}

void loop() {
  WiFiClient client = server.available();
  if (client) {
    while (client.connected()) {
      if (client.available()) {
        String receivedData = client.readStringUntil('\n');
        Serial.println("Received data: " + receivedData);
      }
    }
    client.stop();
  }
}
