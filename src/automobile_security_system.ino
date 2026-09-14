
#include <SoftwareSerial.h>

// Bluetooth HC-05 pins
SoftwareSerial BT(10, 11); // RX, TX

// Pin definitions
int lockLED = 2;      // Red LED for lock
int unlockLED = 3;    // Green LED for unlock
int buzzer = 4;       // Buzzer
int relayPin = 7;     // Relay for ignition (motor)

// Authentication variables
String correctPassword = "1234";
bool authenticated = false;

  


void setup() {
  pinMode(lockLED, OUTPUT);
  pinMode(unlockLED, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(relayPin, OUTPUT);

  // Keep everything OFF initially
  digitalWrite(lockLED, LOW);
  digitalWrite(unlockLED, LOW);
  digitalWrite(buzzer, LOW);
  digitalWrite(relayPin, HIGH); // For active-LOW relay, HIGH = OFF

  Serial.begin(9600);
  BT.begin(9600);
  Serial.println("System Ready. Waiting for commands...");
}

void loop() {
  if (BT.available()) {
    String command = BT.readStringUntil('\n');
    command.trim();
    
    Serial.println("Received: " + command);

    if (!authenticated) {
      if (command.startsWith("PWD:")) {
        String pwd = command.substring(4);
        if (pwd == correctPassword) {
          authenticated = true;
          BT.println("ACCESS GRANTED");
          Serial.println("User Authenticated");
        } else {
          BT.println("WRONG PASSWORD");
        }
      } else {
        BT.println("SEND PASSWORD FIRST: PWD:1234");
      }
    } else {
      if (command == "LOCK") {
        digitalWrite(unlockLED, LOW);
        digitalWrite(lockLED, HIGH);
        beepBuzzer(1000);
        digitalWrite(lockLED,LOW);
        digitalWrite(lockLED,HIGH);
        BT.println("CAR LOCKED");
        digitalWrite(lockLED,LOW);

      } 
      else if (command == "UNLOCK") {
        digitalWrite(lockLED, LOW);
        digitalWrite(unlockLED, HIGH);
        beepBuzzer(1000);
        digitalWrite(unlockLED,LOW);
        digitalWrite(unlockLED,HIGH);
        BT.println("CAR UNLOCKED");
        digitalWrite(unlockLED,LOW);
      } 
      else if (command == "START") {
        digitalWrite(relayPin,LOW); // Active-LOW relay ON
        BT.println("ENGINE STARTED");
      } 
      else if (command == "STOP") {
        digitalWrite(relayPin,HIGH); // Active-LOW relay OFF
        BT.println("ENGINE STOPPED");
      } 
      else {
        BT.println("INVALID COMMAND");
      }
    }
  }
}
void beepBuzzer(int duration)
{
  digitalWrite(buzzer,HIGH);
  delay(duration);
  digitalWrite(buzzer,LOW);
}
