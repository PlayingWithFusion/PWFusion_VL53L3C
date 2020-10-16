#include <Wire.h>
#include "PWFusion_VL53L3C.h"

VL53L3C TOF;

void setup() {
  // Initialize I2C and serial port
  Wire.begin();
  Wire.setClock(400000);
  Serial.begin(9600);

  Serial.println(F("Initilizing VL53L3"));
  
  TOF.begin();
  Serial.println(F("VL53L3 Boot Complete"));

  // Set the timing budget (sample period) to 100ms
  TOF.setTimingBudget(100000);

  // Start sampling data
  TOF.startMeasurement();
  Serial.println(F("Starting TOF measurements"));
}

void loop() {
  MeasurmentResult measResult;

  // Has the VL53L3 finished a new distance mesaurement
  if (TOF.dataIsReady())
  {
    // Get the last measurement result and trigger a new measurement
    TOF.getMeasurmentData(&measResult); 
    TOF.startNextMeasurement();
    
    // The VL53L3 can track up to four onject simultaneously.  Prind the 
    // measured distance to each detected onject.
    Serial.print(F("Range Measurement: "));
    for (int i=0; i<measResult.numObjs; i++)
    {
      Serial.print(measResult.rangeData[i].Range);
      Serial.print(F("mm     "));
    }
    Serial.println();
  }
  
}
