
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





#ifndef _VL53LX_PLATFORM_USER_CONFIG_H_
#define _VL53LX_PLATFORM_USER_CONFIG_H_

#define    VL53LX_BYTES_PER_WORD              2
#define    VL53LX_BYTES_PER_DWORD             4


#define VL53LX_BOOT_COMPLETION_POLLING_TIMEOUT_MS     500
#define VL53LX_RANGE_COMPLETION_POLLING_TIMEOUT_MS   2000
#define VL53LX_TEST_COMPLETION_POLLING_TIMEOUT_MS   60000

#define VL53LX_POLLING_DELAY_MS                         1


#define VL53LX_TUNINGPARM_PUBLIC_PAGE_BASE_ADDRESS  0x8000
#define VL53LX_TUNINGPARM_PRIVATE_PAGE_BASE_ADDRESS 0xC000

#define VL53LX_GAIN_FACTOR__STANDARD_DEFAULT       0x0800

#define VL53LX_GAIN_FACTOR__HISTOGRAM_DEFAULT      0x0800



#define VL53LX_OFFSET_CAL_MIN_EFFECTIVE_SPADS  0x0500


#define VL53LX_OFFSET_CAL_MAX_PRE_PEAK_RATE_MCPS   0x1900


#define VL53LX_OFFSET_CAL_MAX_SIGMA_MM             0x0040



#define VL53LX_ZONE_CAL_MAX_PRE_PEAK_RATE_MCPS     0x1900


#define VL53LX_ZONE_CAL_MAX_SIGMA_MM               0x0040



#define VL53LX_XTALK_EXTRACT_MAX_SIGMA_MM          0x008C


#define VL53LX_MAX_USER_ZONES                5

#define VL53LX_MAX_RANGE_RESULTS              4



#define VL53LX_MAX_STRING_LENGTH 512

#endif
