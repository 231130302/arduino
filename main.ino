// File: main.ino
// Konfigurasi Arduino ESP8266/ESP32 ke Firebase
// Catatan: Ini adalah file kode sumber untuk mikrokontroler.

#include <ESP8266WiFi.h>
#include <Firebase_ESP_Client.h>

#define WIFI_SSID "NAMA_WIFI"
#define WIFI_PASS "PASSWORD_WIFI"
#define API_KEY "ISI_API_KEY_FIREBASE"
#define DATABASE_URL "ISI_DATABASE_URL"

FirebaseData fbdo;
FirebaseAuth auth;
FirebaseConfig config;

void setup() {
  Serial.begin(115200);
  WiFi.begin(WIFI_SSID, WIFI_PASS);

  config.api_key = API_KEY;
  config.database_url = DATABASE_URL;
  Firebase.begin(&config, &auth);
}

void loop() {
  // Skrip untuk mengirim data suhu dummy ke Firebase
  float dummyTemp = random(25, 35); 
  Firebase.RTDB.setFloat(&fbdo, "/suhu_ruangan", dummyTemp);
  delay(5000);
}