// Program : LED Kedap-kedip
//           menggunakan ESP32
// Tanggal : 14 Februari 2025
// Oleh : Ery D.

#define pin_LED   2

void setup() {
  // put your setup code here, to run once:
  pinMode(pin_LED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(pin_LED, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(pin_LED, LOW);    // turn the LED off by making the voltage LOW
  delay(1000); 
}
