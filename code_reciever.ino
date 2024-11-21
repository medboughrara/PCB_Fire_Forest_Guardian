#include <SoftwareSerial.h>

#define RX_PIN 2 
#define TX_PIN 3 
#define FLAME_SENSOR_PIN A0

SoftwareSerial bluetooth(TX_PIN, RX_PIN);

void setup() {
  Serial.begin(9600);           
  bluetooth.begin(9600);        
 
  pinMode(FLAME_SENSOR_PIN, INPUT);

  Serial.println("Flame Sensor Sender Initialized");
}

void loop() {
  
  int flameValue = analogRead(FLAME_SENSOR_PIN);

  // Send the flame sensor value over Bluetooth
  bluetooth.println(flameValue);

  // Debugging
  Serial.print("Flame Sensor Value Sent: ");
  Serial.println(flameValue);

  delay(500); 
}
