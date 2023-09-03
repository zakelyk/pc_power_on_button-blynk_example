#define BLYNK_TEMPLATE_ID "TMPL6PS9h0OWi"
#define BLYNK_TEMPLATE_NAME "Rizky Lamp ON"
#define BLYNK_AUTH_TOKEN "pUgrM8vWWm5Fj8OyLfQOMUh7sJc5KfYF"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>


// Ganti dengan informasi kredensial Wi-Fi Anda
char ssid[] = "Rizky Lamp";
char pass[] = "#gemini#";

// Ganti dengan token yang Anda dapatkan dari aplikasi Blynk

// Tentukan pin relay
#define RELAY_PIN D2

void setup()
{
  // Mulai serial dan koneksikan ke Wi-Fi serta Blynk
  Serial.begin(9600);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  // Atur pin relay sebagai OUTPUT
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, HIGH);  // Pastikan relay dimatikan saat awal
}

void loop()
{
  Blynk.run();
}

// Fungsi ini akan dipanggil setiap kali tombol di Blynk ditekan atau dilepas
BLYNK_WRITE(V0)
{
  int pinValue = param.asInt();
  Serial.print("BLYNK_WRITE dipanggil dengan nilai: ");
  Serial.println(pinValue);
  if (pinValue == 0) {
    digitalWrite(RELAY_PIN, LOW);  // Aktifkan relay
    delay(500);
  } else {
    digitalWrite(RELAY_PIN, HIGH);
  }
  
}
