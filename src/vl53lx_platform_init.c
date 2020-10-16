
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





#include "vl53lx_platform.h"
#include "vl53lx_platform_init.h"
#include "vl53lx_ll_def.h"


VL53LX_Error VL53LX_platform_init(
	VL53LX_Dev_t *pdev,
	uint8_t       i2c_slave_address,
	uint8_t       comms_type,
	uint16_t      comms_speed_khz)
{


	VL53LX_Error status = VL53LX_ERROR_NONE;



	pdev->i2c_slave_address = i2c_slave_address;
	pdev->comms_type        = comms_type;
	pdev->comms_speed_khz   = comms_speed_khz;

	if (status == VL53LX_ERROR_NONE)
		status =
			VL53LX_CommsInitialise(
				pdev,
				pdev->comms_type,
				pdev->comms_speed_khz);


	if (status == VL53LX_ERROR_NONE)
		status = VL53LX_GpioXshutdown(0);


	if (status == VL53LX_ERROR_NONE)
		status = VL53LX_GpioPowerEnable(0);


	if (status == VL53LX_ERROR_NONE)
		status = VL53LX_GpioCommsSelect(0);


	if (status == VL53LX_ERROR_NONE)
		status = VL53LX_WaitUs(pdev, 1000);


	if (status == VL53LX_ERROR_NONE)
		status = VL53LX_GpioPowerEnable(1);


	if (status == VL53LX_ERROR_NONE)
		status = VL53LX_WaitUs(pdev, 1000);


	if (status == VL53LX_ERROR_NONE)
		status = VL53LX_GpioXshutdown(1);


	if (status == VL53LX_ERROR_NONE)
		status = VL53LX_WaitUs(pdev, 100);

	return status;
}


VL53LX_Error VL53LX_platform_terminate(
		VL53LX_Dev_t *pdev)
{


	VL53LX_Error status = VL53LX_ERROR_NONE;


	if (status == VL53LX_ERROR_NONE)
		status = VL53LX_GpioXshutdown(0);


	if (status == VL53LX_ERROR_NONE)
		status = VL53LX_GpioPowerEnable(0);


	if (status == VL53LX_ERROR_NONE)
		status = VL53LX_CommsClose(pdev);

	return status;
}
