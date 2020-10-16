/***************************************************************************
* File Name: PWFusion_VL53L3C.cpp
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
#include "PWFusion_VL53L3C.h"

#define BASE_ADDR 0x52


// Initialize the VL53L3C driver and wait for the sensor to boot.  Note, this
// function will block until the VL53L3C completes its boot sequence.  
void VL53L3C::begin(TwoWire &i2cPort)
{
  dev.pParent = this;
  _i2cPort = &i2cPort;
  
  (void)VL53LX_software_reset(&dev);
  (void)VL53LX_WaitDeviceBooted(&dev);
  (void)VL53LX_DataInit(&dev);
}


// Instruct VL53L3C to begin capture distance measurments
VL53LX_Error VL53L3C::startMeasurement()
{
  return VL53LX_StartMeasurement(&dev);
}


// Instruct VL53L3C to stop capturing distance measurments and enter
// low power comsumption state.
VL53LX_Error VL53L3C::stopMeasurement()
{
  return VL53LX_StopMeasurement(&dev);
}


// Return true if a distance measurment is complete and ready to be 
// read
bool VL53L3C::dataIsReady()
{
  uint8_t ready = false;
  (void)VL53LX_GetMeasurementDataReady(&dev, &ready);

  return (ready != 0);
}


// Instruct the VL53L3C to begine a new distance measurment
VL53LX_Error VL53L3C::startNextMeasurement()
{
  return VL53LX_ClearInterruptAndStartMeasurement(&dev);
}


// Return the measured distance(s) from the VL53L3C sensor
VL53LX_Error VL53L3C::getMeasurmentData(MeasurmentResult *pResult)
{
  VL53LX_MultiRangingData_t rangingData;
  VL53LX_Error status = VL53LX_ERROR_INVALID_PARAMS;

  if (pResult != NULL)
  {
    pResult->numObjs = 0;
    status = VL53LX_GetMultiRangingData(&dev, &rangingData);

    if (status == VL53LX_ERROR_NONE)
    {
      pResult->numObjs = rangingData.NumberOfObjectsFound;
      for(int i=0; i<VL53LX_MAX_RANGE_RESULTS; i++)
      {
        pResult->rangeData[i].AmbientRate = (float)rangingData.RangeData[i].AmbientRateRtnMegaCps / 65536.0;
        pResult->rangeData[i].Range       = rangingData.RangeData[i].RangeMilliMeter;
        pResult->rangeData[i].RangeMax    = rangingData.RangeData[i].RangeMaxMilliMeter;
        pResult->rangeData[i].RangeMin    = rangingData.RangeData[i].RangeMinMilliMeter;
        pResult->rangeData[i].Sigma       = (float)rangingData.RangeData[i].SigmaMilliMeter / 65536.0;
        pResult->rangeData[i].SignalRate  = (float)rangingData.RangeData[i].SignalRateRtnMegaCps / 65536.0;
      }
    }
  }

  return status;
}


// Set the distance mode.  Short mode works the best in all lighting conditions,
// but the maximum measurable distance is limited.  Long mode can measure the furthest,
// but may not function properly in brightly lit enviroments.
VL53LX_Error VL53L3C::setDistanceMode(DistMode mode)
{
  VL53LX_DistanceModes internalMode;

  internalMode = (mode == DIST_SHORT) ? VL53LX_DISTANCEMODE_SHORT :
                    (mode == DIST_MEDIUM) ? VL53LX_DISTANCEMODE_MEDIUM : VL53LX_DISTANCEMODE_LONG;

  return VL53LX_SetDistanceMode(&dev, internalMode);
}


// Set the measuremnt sample period in microseconds.  Longer periods result in 
// more accurate measurements.
VL53LX_Error VL53L3C::setTimingBudget(uint32_t timeUs)
{
  return VL53LX_SetMeasurementTimingBudgetMicroSeconds(&dev, timeUs);
}


// See VL53L3C C API documentation for more information
VL53LX_Error VL53L3C::setTuningParameter(uint16_t paramId, int32_t value)
{
  return VL53LX_SetTuningParameter(&dev, paramId, value);
}


// Write raw I2C data to the VL53L3C
bool VL53L3C::write(uint16_t index, uint8_t *pData, uint32_t count)
{
  _i2cPort->beginTransmission(BASE_ADDR>>1);  
  _i2cPort->write(index >> 8); 
  _i2cPort->write(index & 0xFF); 

  for (int i=0; i<count; i++)
  {
    _i2cPort->write(pData[i]);
  }

  return (_i2cPort->endTransmission(true) != 0);
}


// Read raw I2C data from the VL53L3C
bool VL53L3C::read(uint16_t index, uint8_t *pData, uint32_t count)
{
   uint16_t result = 0;

  _i2cPort->beginTransmission(BASE_ADDR>>1);  
  _i2cPort->write(index >> 8); 
  _i2cPort->write(index & 0xFF);       
  _i2cPort->endTransmission(false);  

  if (Wire.requestFrom(BASE_ADDR>>1, count) != 0)
  {
    for (int i=0; i<count; i++)
    {
      *pData++ = Wire.read();
    }
  }

  return true;
}
