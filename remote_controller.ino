#include<IRremote.h>
#include "PhilcoCommands.h"

#define BUTTON_PRESSED 0 /*BUTTON PRESSED VALUE*/
#define BUTTON_PIN 2
#define IRLED_PIN 3
/*#define RECEIVER_PIN 4*/

void setup() {
  Serial.begin(9600);

  pinMode(IRLED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  IrSender.begin(IRLED_PIN, ENABLE_LED_FEEDBACK);
  Serial.print("Start sending IR signal using port ");
  Serial.println(IRLED_PIN);

  /*IrReceiver.begin(RECEIVER_PIN, ENABLE_LED_FEEDBACK);
  Serial.print("Start receiving IR signal using port ");
  Serial.println(RECEIVER_PIN);*/
}

void loop() {
  //receiverIRControlSignal();
  
  if (digitalRead(BUTTON_PIN) == BUTTON_PRESSED) {
    Serial.println("Button pressed");
    sendNetflixOneShotIrSignal();
  }
}

void receiverIRControlSignal() {
  if (IrReceiver.decode()) {
    IrReceiver.printIRResultShort(&Serial);
    IrReceiver.resume();
  }
}

void sendNetflixOneShotIrSignal() {
  /*TODO: Implement strategy pattern to use action methods like this: turnOn(CONST_PHILCO) | turnOn(CONST_LG)*/;

  /*Step 1*/
  philcoTurnOn(); /*turn on TV*/

  /*Step 2*/
  philcoResources(); /*open resource menu*/
  /*click arrow right 3x*/
  philcoArrowRight(); 
  philcoArrowRight();
  philcoArrowRight();

  philcoEnter(); /*press enter*/
  delay(9000); /*waiting 8s + 1s default*/

  /*Step 3*/
  /*press arrow right 4x*/
  philcoArrowRight(); 
  philcoArrowRight(); 
  philcoArrowRight(); 
  philcoArrowRight(); 
  
  philcoEnter(); /*press enter*/
  delay(10000); /*waiting 2s + 1s default*/

  /*Step 4*/
  //philcoEnter(); /*press enter*/
  philcoArrowLeft(); /*press arrow left once*/
  philcoArrowDown(); /*press arrow down once*/
  philcoEnter(); /*press enter*/

  /*Step 5*/
  delay(4000); /*waiting 2s*/
  philcoEnter(); /*press enter*/
  
}
