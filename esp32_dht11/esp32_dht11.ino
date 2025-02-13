#include "DHT.h"

#define pin_LED   2
#define pin_DHT11 5
#define DHTTYPE DHT11

DHT dht(pin_DHT11,DHTTYPE);

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  Serial.begin(9600);
  dht.begin();
}

// the loop function runs over and over again forever
void loop() {
                     
  // Pembacaan Sensor biasanya dalam 2 detik 
  // Baca kelembaban udara (%)
  float h = dht.readHumidity();
  // Baca suhu Celsius (default)
  float t = dht.readTemperature();

  // Periksa apakah pembacaan data gagal dan keluar dari program.
  if (isnan(h) || isnan(t) ) {
    Serial.println(F("Gagal membaca data dari sensor DHT !"));
    return;
  }

  Serial.print(F("Kelembaban: "));
  Serial.print(h);
  Serial.print(F("%  Suhu: "));
  Serial.print(t);
  Serial.println(F("°C "));
  
  delay(2500);
}
