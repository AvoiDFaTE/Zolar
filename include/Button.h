#pragma once

#include <Arduino.h>
#include "Button2.h"
#include "Pinout.h"

extern Button2 Button;

void setupButton();
void buttonLoop();