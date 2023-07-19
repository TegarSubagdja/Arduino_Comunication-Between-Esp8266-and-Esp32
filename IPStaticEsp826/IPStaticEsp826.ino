#include <ESP8266WiFi.h>

const char* ssid = "Nama_SSID_Anda";
const char* password = "Password_Anda";
const char* receiverIP = "IP_ESP32_Tujuan"; // Ganti dengan alamat IP ESP32

void setup() {
  Serial.begin(9600);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
}

void loop() {
  String dataToSend = "Hello from ESP8266";
  sendData(dataToSend);
  delay(5000);
}

void sendData(String data) {
  WiFiClient client;
  if (client.connect(receiverIP, 80)) {
    client.print(data);
    client.stop();
    Serial.println("Data sent successfully");
  } else {
    Serial.println("Connection to receiver failed!");
  }
}
