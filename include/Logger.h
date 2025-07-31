#pragma once

#include <ESPLogger.h>
#include "Constants.h"
#include "Types.h"

/*
LOGGER LINE FORMAT IS
Tab separated WITHOUT HEADERS

Timestamp   CPS Ash Rsd A   B   Int.ime    OperationId
%s          %f  %f  %f  %f  %f  %d         %d

OperationId is:
0 - Measurment
1 - Average performed
*/

bool setupLogger();
bool logMeasurment(measurements_t measurment);
bool logAverage(averaged_t averaged);