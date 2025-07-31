#include "Logger.h"
#include "RTC_PCF85063.h"

ESPLogger Logger(LogFilePath);

bool setupLogger() {
  bool result = Logger.begin();
  Logger.setSizeLimit(10 * 1024 * 1024, false); //10 Mb
  return result;
}

bool logAction(const char* record) {
    bool result = Logger.append( record, false );

    if(result){
      printf("%s\nlog contents:\n", record);
      Logger.print();
    }

    return result;
}

bool logMeasurment(measurements_t measurment) {
  char record[256];

  datetime_t currentTime;
  PCF85063_Read_Time(&currentTime);

  sprintf(record, "%u-%02d-%02d %02d:%02d:%02d\t%06.2f\t%05.2f\t%05.2f\t%06.4f\t%+6.2f\t%03d\t%d",

    currentTime.year,
    currentTime.month,
    currentTime.day,

    currentTime.hour,
    currentTime.minute,
    currentTime.second,

    measurment.IntegratedCps,
    measurment.Ash,
    
    0.0,

    measurment.Calibration.FactorA,
    measurment.Calibration.FactorB,
    
    measurment.IntegrationTime,
    0
  );

  return logAction( record );
}

bool logAverage(averaged_t averaged) {
  char record[256];

  datetime_t currentTime;
  PCF85063_Read_Time(&currentTime);
  
  sprintf(record, "%u-%02d-%02d %02d:%02d:%02d\t%06.2f\t%05.2f\t%05.2f\t%06.4f\t%+6.2f\t%03d\t%d",
  
    currentTime.year,
    currentTime.month,
    currentTime.day,

    currentTime.hour,
    currentTime.minute,
    currentTime.second,

    averaged.AvgCps,
    averaged.AvgAsh,

    averaged.RelativeStdDeviation,
    
    averaged.Calibration.FactorA,
    averaged.Calibration.FactorB,
    
    averaged.AvgTime,
    1
  );

  return logAction( record );    
}