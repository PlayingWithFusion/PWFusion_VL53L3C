
/*******************************************************************************
 This file is part of VL53LX Platform

 Copyright (c) 2020, STMicroelectronics - All Rights Reserved

 License terms: BSD 3-clause "New" or "Revised" License.

 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are met:

 1. Redistributions of source code must retain the above copyright notice, this
 list of conditions and the following disclaimer.

 2. Redistributions in binary form must reproduce the above copyright notice,
 this list of conditions and the following disclaimer in the documentation
 and/or other materials provided with the distribution.

 3. Neither the name of the copyright holder nor the names of its contributors
 may be used to endorse or promote products derived from this software
 without specific prior written permission.

 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/
#include "PWFusion_VL53L3C.h"
#include "vl53lx_platform.h"
#include "vl53lx_platform_log.h"



VL53LX_Error VL53LX_CommsInitialise(
	VL53LX_Dev_t *pdev,
	uint8_t       comms_type,
	uint16_t      comms_speed_khz)
{
	VL53LX_Error status = VL53LX_ERROR_NONE;
	

	return status;
}


VL53LX_Error VL53LX_CommsClose(
	VL53LX_Dev_t *pdev)
{
	VL53LX_Error status = VL53LX_ERROR_NONE;

	return status;
}



VL53LX_Error VL53LX_WriteMulti(
	VL53LX_Dev_t *pdev,
	uint16_t      index,
	uint8_t      *pdata,
	uint32_t      count)
{
	((VL53L3C*)(pdev->pParent))->write(index, pdata, count);

	return VL53LX_ERROR_NONE;
}


VL53LX_Error VL53LX_ReadMulti(
	VL53LX_Dev_t *pdev,
	uint16_t      index,
	uint8_t      *pdata,
	uint32_t      count)
{
  ((VL53L3C*)(pdev->pParent))->read(index, pdata, count);
  
	return VL53LX_ERROR_NONE;
}


VL53LX_Error VL53LX_WrByte(
	VL53LX_Dev_t *pdev,
	uint16_t      index,
	uint8_t       VL53LX_p_003)
{
	VL53LX_Error status         = VL53LX_ERROR_NONE;
	uint8_t  buffer[1];


	buffer[0] = (uint8_t)(VL53LX_p_003);

	status = VL53LX_WriteMulti(pdev, index, buffer, 1);

	return status;
}


VL53LX_Error VL53LX_WrWord(
	VL53LX_Dev_t *pdev,
	uint16_t      index,
	uint16_t      VL53LX_p_003)
{
	VL53LX_Error status         = VL53LX_ERROR_NONE;
	uint8_t  buffer[2];


	buffer[0] = (uint8_t)(VL53LX_p_003 >> 8);
	buffer[1] = (uint8_t)(VL53LX_p_003 &  0x00FF);

	status = VL53LX_WriteMulti(pdev, index, buffer, VL53LX_BYTES_PER_WORD);

	return status;
}


VL53LX_Error VL53LX_WrDWord(
	VL53LX_Dev_t *pdev,
	uint16_t      index,
	uint32_t      VL53LX_p_003)
{
	VL53LX_Error status         = VL53LX_ERROR_NONE;
	uint8_t  buffer[4];


	buffer[0] = (uint8_t) (VL53LX_p_003 >> 24);
	buffer[1] = (uint8_t)((VL53LX_p_003 &  0x00FF0000) >> 16);
	buffer[2] = (uint8_t)((VL53LX_p_003 &  0x0000FF00) >> 8);
	buffer[3] = (uint8_t) (VL53LX_p_003 &  0x000000FF);

	status = VL53LX_WriteMulti(pdev, index, buffer, VL53LX_BYTES_PER_DWORD);

	return status;
}


VL53LX_Error VL53LX_RdByte(
	VL53LX_Dev_t *pdev,
	uint16_t      index,
	uint8_t      *pdata)
{
	VL53LX_Error status         = VL53LX_ERROR_NONE;
	uint8_t  buffer[1] = {0};

	status = VL53LX_ReadMulti(pdev, index, buffer, 1);

	*pdata = buffer[0];

	return status;
}


VL53LX_Error VL53LX_RdWord(
	VL53LX_Dev_t *pdev,
	uint16_t      index,
	uint16_t     *pdata)
{
	VL53LX_Error status         = VL53LX_ERROR_NONE;
	uint8_t  buffer[2]  = {0,0};

	status = VL53LX_ReadMulti(
					pdev,
					index,
					buffer,
					VL53LX_BYTES_PER_WORD);

	*pdata = (uint16_t)(((uint16_t)(buffer[0])<<8) + (uint16_t)buffer[1]);

	return status;
}


VL53LX_Error VL53LX_RdDWord(
	VL53LX_Dev_t *pdev,
	uint16_t      index,
	uint32_t     *pdata)
{
	VL53LX_Error status = VL53LX_ERROR_NONE;
	uint8_t  buffer[4] = {0,0,0,0};

	status = VL53LX_ReadMulti(
					pdev,
					index,
					buffer,
					VL53LX_BYTES_PER_DWORD);

	*pdata = ((uint32_t)buffer[0]<<24) + ((uint32_t)buffer[1]<<16) + ((uint32_t)buffer[2]<<8) + (uint32_t)buffer[3];

	return status;
}



VL53LX_Error VL53LX_WaitUs(
	VL53LX_Dev_t *pdev,
	int32_t       wait_us)
{
	VL53LX_Error status         = VL53LX_ERROR_NONE;
  delayMicroseconds(wait_us);

	return status;
}


VL53LX_Error VL53LX_WaitMs(
	VL53LX_Dev_t *pdev,
	int32_t       wait_ms)
{
  delay(wait_ms);
	return VL53LX_ERROR_NONE;
}



VL53LX_Error VL53LX_GetTimerFrequency(int32_t *ptimer_freq_hz)
{
	*ptimer_freq_hz = 0;

	//trace_print(VL53LX_TRACE_LEVEL_INFO, "VL53LX_GetTimerFrequency: Freq : %dHz\n", *ptimer_freq_hz);
	return VL53LX_ERROR_NONE;
}


VL53LX_Error VL53LX_GetTimerValue(int32_t *ptimer_count)
{
	*ptimer_count = 0;

	//trace_print(VL53LX_TRACE_LEVEL_INFO, "VL53LX_GetTimerValue: Freq : %dHz\n", *ptimer_count);
	return VL53LX_ERROR_NONE;
}




VL53LX_Error VL53LX_GpioSetMode(uint8_t pin, uint8_t mode)
{
	VL53LX_Error status         = VL53LX_ERROR_NONE;
	return status;
}


VL53LX_Error  VL53LX_GpioSetValue(uint8_t pin, uint8_t value)
{
	VL53LX_Error status         = VL53LX_ERROR_NONE;
	return status;

}


VL53LX_Error  VL53LX_GpioGetValue(uint8_t pin, uint8_t *pvalue)
{
	VL53LX_Error status         = VL53LX_ERROR_NONE;
	return status;
}



VL53LX_Error  VL53LX_GpioXshutdown(uint8_t value)
{
	VL53LX_Error status         = VL53LX_ERROR_NONE;
	return status;
}


VL53LX_Error  VL53LX_GpioCommsSelect(uint8_t value)
{
	VL53LX_Error status         = VL53LX_ERROR_NONE;
	return status;
}


VL53LX_Error  VL53LX_GpioPowerEnable(uint8_t value)
{
	VL53LX_Error status         = VL53LX_ERROR_NONE;
	return status;
}


VL53LX_Error  VL53LX_GpioInterruptEnable(void (*function)(void), uint8_t edge_type)
{
	VL53LX_Error status         = VL53LX_ERROR_NONE;

	return status;
}


VL53LX_Error  VL53LX_GpioInterruptDisable(void)
{
	VL53LX_Error status         = VL53LX_ERROR_NONE;

	return status;
}


VL53LX_Error VL53LX_GetTickCount(
	uint32_t *ptick_count_ms)
{
	VL53LX_Error status         = VL53LX_ERROR_NONE;

	return status;

}


VL53LX_Error VL53LX_WaitValueMaskEx(
	VL53LX_Dev_t *pdev,
	uint32_t      timeout_ms,
	uint16_t      index,
	uint8_t       value,
	uint8_t       mask,
	uint32_t      poll_delay_ms)
{
   uint32_t startTimeUs = micros();
   uint32_t timeoutUs = timeout_ms * 1000L;
   uint32_t delta = 0;
   uint8_t done = 0;
   uint8_t dataIn;
   
   while (!done && (delta < timeoutUs))
   {
      delta =  micros() - startTimeUs;
      
      VL53LX_RdByte(pdev, index, &dataIn);
      if ((dataIn & mask) == value)
      {
         done = 1;
      }
      else
      {
         VL53LX_WaitMs(pdev, poll_delay_ms);
      }
   }
   
  return (delta<timeoutUs) ? VL53LX_ERROR_NONE : VL53LX_ERROR_TIME_OUT;
}
