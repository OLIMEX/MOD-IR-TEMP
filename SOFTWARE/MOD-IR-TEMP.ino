//  MOD-IR-TEMP demo code for Arduino
//  to use this demo you must install Adafruit MLX90614 library from Sketch->Include library menu
//
//  If you use OLIMEXINO-32U4 you just simple plug the MOD-IR-TEMP cable to UEXT connector
//
//  otherwise connect MOD-IR-TEMP with jumper wires to Arduino board
//
//  MOD-IR-TEMP Pin.1 GND to Arduino board GND
//  MOD-IR-TEMP Pin.2 +3.3V to Arduino board +3.3V
//  MOD-IR-TEMP Pin.3 SDA to Arduino board pin D2
//  MOD-IR-TEMP Pin.4 SCL to Arduino board pin D3
//
//  MLX90614 has internal and infra red temperature sensors
//
//  the internal sensor can measure temperatures between -40 to +125 C
//  the infra red sensor can measure object temperatures -70 to +380 C
//  with resolution 0.02 and 0.5C accuracy
//  this makes it perfect for non contact measurements of PCB soldering, body temperature etc applications

#include <Wire.h>
#include "Adafruit_MLX90614.h"


Adafruit_MLX90614 modIrTemp = Adafruit_MLX90614();

void setup() {
  pinMode(8,OUTPUT);        //the following two lines enable power supply 3.3V on UEXT connector
  digitalWrite(8,LOW);      //you do not need them if you use wire jumpers
  modIrTemp.begin();  
  Serial.begin(115200);
}

void loop() {

  Serial.print("Ambient = "); Serial.print(modIrTemp.readAmbientTempC()); 
  Serial.print("*C\tObject = "); Serial.println(modIrTemp.readObjectTempC());
   
  delay(1000); // can adjust this for faster/slower updates
}


