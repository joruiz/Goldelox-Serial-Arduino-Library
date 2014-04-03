#include <SoftwareSerial.h>
#include "Goldelox_Serial_4DLib.h"
#include "Goldelox_const4D.h"

// pin 3 = TX of display, pin 4 = RX
#define TX_PIN     3
#define RX_PIN     4
#define RESET_PIN  5

SoftwareSerial DisplaySerial(TX_PIN, RX_PIN); 

Goldelox_Serial_4DLib Display(&DisplaySerial, RESET_PIN);

void setup() {

  Serial.begin(9600);
  Serial.println("uSD card images demo program");
  
  Display.reset();
  Display.TimeLimit4D = 2000;
  DisplaySerial.begin(9600);  
  
  Display.media_Init();
}

void loop() {
  
  for(int i = 0x0006; i <= 0x000A; i += 0x0002) {
    Display.media_SetSector(0x000, i);
    Display.media_Image(20,20);
    delay(250);  
  }
}
