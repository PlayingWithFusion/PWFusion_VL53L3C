/***************************************************************************
* File Name: PWFusion_VL53L3C.h
* Processor/Platform: Sparkfun RedBoard Artemis (tested)
* Development Environment: Arduino 1.8.13
*
* Designed for use with with Playing With Fusion VL53L3C TOF sensor
*
*   SEN-36007-L3 VL53L3 Qwiic Time Of Flight Sensor
*   ---> http://www.playingwithfusion.com/productview.php?pdid=22
*
* Copyright © 2020 Playing With Fusion, Inc.
* SOFTWARE LICENSE AGREEMENT: This code is released under the MIT License.
*
* Permission is hereby granted, free of charge, to any person obtaining a
* copy of this software and associated documentation files (the "Software"),
* to deal in the Software without restriction, including without limitation
* the rights to use, copy, modify, merge, publish, distribute, sublicense,
* and/or sell copies of the Software, and to permit persons to whom the
* Software is furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
* FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
* DEALINGS IN THE SOFTWARE.
* **************************************************************************
* REVISION HISTORY:
* Author        Date      Comments
* J. Leonard    2020Aug   Original version
* 
* Playing With Fusion, Inc. invests time and resources developing open-source
* code. Please support Playing With Fusion and continued open-source 
* development by buying products from Playing With Fusion!
**************************************************************************/
#ifndef PWFUSION_VL53L3C_H
#define PWFUSION_VL53L3C_H

#include <Wire.h>
#include <Arduino.h>
#include "vl53lx_api.h"

typedef enum DistMode_e {
  DIST_SHORT,
  DIST_MEDIUM,  
  DIST_LONG,
} DistMode;

typedef struct RangeData_s{
	int16_t RangeMax;  // millimeters
	int16_t RangeMin;  // millimeters
	int16_t Range;     // millimeters

	float SignalRate;  // mega counts per second
	float AmbientRate; // mega counts per second
	float Sigma;       // millimeters
} RangeData;

typedef struct MeasurmentResult_s{
  uint8_t numObjs;  // number of objects found
	RangeData rangeData[VL53LX_MAX_RANGE_RESULTS];
} MeasurmentResult;

class VL53L3C
{
  public:
    void begin(TwoWire &i2cPort = Wire);
    VL53LX_Error startMeasurement();
    VL53LX_Error stopMeasurement();
    bool dataIsReady();
    VL53LX_Error startNextMeasurement();
    VL53LX_Error getMeasurmentData(MeasurmentResult *pResult);
    VL53LX_Error setDistanceMode(DistMode mode);
    VL53LX_Error setTimingBudget(uint32_t timeUs);
    VL53LX_Error setTuningParameter(uint16_t paramId, int32_t value);

    bool write(uint16_t index, uint8_t *pData, uint32_t count);
    bool read(uint16_t index, uint8_t *pData, uint32_t count);

  private:
    TwoWire *_i2cPort;
    VL53LX_Dev_t dev;
};
  
#endif // PWFUSION_VL53L3C_H
