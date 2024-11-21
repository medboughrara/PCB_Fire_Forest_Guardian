#include <SoftwareSerial.h>


#define RX_PIN 2 
#define TX_PIN 3 

SoftwareSerial bluetooth(TX_PIN, RX_PIN);

void setup() {
  Serial.begin(9600);           
  bluetooth.begin(9600);        
 
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);

  Serial.println("Bluetooth Receiver Initialized");
}

void loop() {
  if (bluetooth.available()) {
   
    String receivedDataString = bluetooth.readStringUntil('\n');
    float receivedData = receivedDataString.toFloat(); 
   
    // Debugging
    Serial.print("Flame Sensor Value Received: ");
    Serial.println(receivedData);

   
    if (receivedData > 2000) {
      digitalWrite(8, LOW);
      digitalWrite(7, HIGH);
    } else {
      digitalWrite(7, LOW);
      digitalWrite(8, HIGH);
    }
  }
}
