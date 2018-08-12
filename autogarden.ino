#include "Plant.h"
#include <Arduino.h>
#include "Logger.h"

Plant plant(2,3);

void setup() {
  InitializeLogs();
  Logf("Setup");

  plant.Attach();
}

void loop() {
  // put your main code here, to run repeatedly:
  plant.Update();

  delay(500);
}
