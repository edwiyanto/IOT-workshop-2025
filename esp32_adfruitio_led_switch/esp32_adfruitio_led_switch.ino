#include <PubSubClient.h>
#include <WiFi.h>
#include <Arduino.h>

const char* ssid = "nama ssid";
const char* password = "password wifi";
const char* mqttServer = "io.adafruit.com";
const int mqttPort = 1883;
const char* mqttUser = "edwiyanto";
const char* mqttPassword = "key-adafruit-io";
const char* mqttTopicLED = "isi_nama_user/feeds/LED";//"edwiyanto/feeds/LED";

#define LED 2
#define LED_ON HIGH
#define LED_OFF LOW

WiFiClient espClient;
PubSubClient client(espClient);

//--------- WIFI -------------------------------------------

void wifi_connect() {
  Serial.print("Starting connecting WiFi.");
  delay(10);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

//------------------ MQTT ----------------------------------
void mqtt_setup() {
    client.setServer(mqttServer, mqttPort);
    client.setCallback(callback);
    Serial.println("Connecting to MQTT…");
    while (!client.connected()) {        
        String clientId = "Poljan00-";
        clientId += String(random(0xffff), HEX);
        if (client.connect(clientId.c_str(), mqttUser, mqttPassword )) {
            Serial.println("connected");
        } else {
            Serial.print("failed with state  ");
            Serial.println(client.state());
            delay(2000);
        }
    }

    client.subscribe(mqttTopicLED);
}

void callback(char* topic, byte* payload, unsigned int length) {

    Serial.print("Message arrived in topic: ");
    Serial.println(topic);

    String byteRead = "";
    Serial.print("Message: ");
    for (int i = 0; i < length; i++) {
        byteRead += (char)payload[i];
    }    
    Serial.println(byteRead);

    if (byteRead == "OFF"){
        Serial.println("LAMP OFF");
        digitalWrite(LED, LED_OFF);

    }

    if (byteRead == "ON"){
        Serial.println("LAMP ON");
        digitalWrite(LED, LED_ON);

    }

    Serial.println();
    Serial.println(" — — — — — — — — — — — -");

}

//--------- ARDUINO --------------------------------------
void setup() {  
  Serial.begin(115200);
  pinMode(LED,OUTPUT);

  wifi_connect();
  mqtt_setup();  

}

void loop() {
    client.loop();

}
