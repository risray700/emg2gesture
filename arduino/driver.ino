#include <Servo.h>
#include <Arduino.h>  
#include <stdint.h>   
#include <string.h>   

const int servoPins[5] = {6,5,4,3,2};
Servo servos[5];
const int onboardLED = LED_BUILTIN;  // Typically pin 13

const unsigned long BAUD_RATE = 115200;
const int BUFFER_SIZE = 64;
char serialBuffer[BUFFER_SIZE];
uint8_t bufferIndex = 0;  

void setup() {
  pinMode(onboardLED, OUTPUT);
  //digitalWrite(onboardLED, LOW);
  digitalWrite(onboardLED, HIGH);
  Serial.begin(BAUD_RATE);
  for (int i = 0; i < 5; i++) {
    servos[i].attach(servoPins[i]);
    //servos[i].write(0);  
    delay(100);  
  }
}

void loop() {
  while (Serial.available() > 0) {
    char c = Serial.read();
    
    if (c == '\r' || c == '\n') continue;
    
    Serial.print(c);
    
    if (bufferIndex >= BUFFER_SIZE - 1) {
      if (c == '|') {
        bufferIndex = 0;
      }
      continue;
    }
    
    serialBuffer[bufferIndex++] = c;
    
    if (c == '|') {
      serialBuffer[bufferIndex] = '\0';
      processCommand();
      bufferIndex = 0;
    }
  }
}

void blinkLED() {
  digitalWrite(onboardLED, HIGH);
  delay(50);
  //digitalWrite(onboardLED, LOW);
  delay(50);
}

void processCommand() {
  char* command = strtok(serialBuffer, "|");
  while (command != NULL) {
    if (strlen(command) > 0) {
      if (parseSingleCommand(command)) {
        blinkLED();  // Blink only when command is valid
      }
    }
    command = strtok(NULL, "|");
  }
}

bool parseSingleCommand(char* cmd) {
  int servoIndex, angle;
  if (sscanf(cmd, "SERVO:%d:%d", &servoIndex, &angle) == 2) {
    if (servoIndex >= 0 && servoIndex < 5) {
      angle = constrain(angle, 0, 180);
      servos[servoIndex].write(angle);
      return true;  // Command was valid
    }
  }
  return false;  // Command was invalid
}