#include <DHT.h>

#define DHTPIN 2        // DHT22 data pin connected to digital pin 2
#define DHTTYPE DHT22   // DHT 22 (AM2302)

#define LED_PIN 4       // LED connected to pin 4
#define BUZZER_PIN 3    // Buzzer connected to pin 3

float tempThreshold = 30.0;  // Temperature limit (in °C)

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();

  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  digitalWrite(LED_PIN, LOW);
  digitalWrite(BUZZER_PIN, LOW);
}

void loop() {
  float temperature = dht.readTemperature(); // read temp in °C

  // Check for reading failure
  if (isnan(temperature)) {
    Serial.println("Failed to read from DHT22 sensor!");
    delay(2000);
    return;
  }

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  // High temperature condition
  if (temperature > tempThreshold) {
    digitalWrite(LED_PIN, HIGH);
    digitalWrite(BUZZER_PIN, HIGH);
  } 
  else {
    digitalWrite(LED_PIN, LOW);
    digitalWrite(BUZZER_PIN, LOW);
  }

  delay(1000);
}
