#include "CommandCodes.h"
#include "Helper.h"

#define PHILCO_CONTROLLER_BITS 20

void send(unsigned long long command) {
  IrSender.sendRC6(command, PHILCO_CONTROLLER_BITS);
}

void philcoTurnOn() {
  send(philcoTurnOnCommand);
  Serial.println("Philco TV: turned on");
  delay(30000);
}

void philcoResources() {
  send(philcoResourceCommand);
  Serial.println("Philco TV: resource opened");
  delay(1000);
}

void philcoVolumeUp() {
  send(philcoVolumeUpCommand);
  Serial.println("Philco TV: volume up");
  delay(1500);
}

void philcoVolumeDown() {
  send(philcoVolumeDownCommand);
  Serial.println("Philco TV: volume down");
  delay(1500);
}

void philcoMute() {
  send(philcoVolumeDownCommand);
  Serial.println("Philco TV: volume muted");
  delay(1500);
}

void philcoArrowUp() {
  send(philcoArrowUpCommand);
  Serial.println("Philco TV: arrow up");
  delay(1500);
}

void philcoArrowDown() {
  send(philcoArrowDownCommand);
  Serial.println("Philco TV: arrow down");
  delay(1500);  
}

void philcoArrowLeft() {
  send(philcoArrowLeftCommand);
  Serial.println("Philco TV: arrow left");  
  delay(1500);  
}

void philcoArrowRight() {
  send(philcoArrowRightCommand);
  Serial.println("Philco TV: arrow right");
  delay(1500);
}

void philcoEnter() {
  send(philcoEnterCommand);
  Serial.println("Philco TV: Enter pressed");
  delay(1500);  
}

void philcoHome() {
  send(philcoHomeCommand);
  Serial.println("Philco TV: Home pressed");
  delay(1500);  
}
