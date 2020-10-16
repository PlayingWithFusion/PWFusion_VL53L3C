
/*******************************************************************************
 * Copyright (c) 2020, STMicroelectronics - All Rights Reserved

 This file is part of VL53LX Core and is dual licensed,
 either 'STMicroelectronics
 Proprietary license'
 or 'BSD 3-clause "New" or "Revised" License' , at your option.

********************************************************************************

 'STMicroelectronics Proprietary license'

********************************************************************************

 License terms: STMicroelectronics Proprietary in accordance with licensing
 terms at www.st.com/sla0081

 STMicroelectronics confidential
 Reproduction and Communication of this document is strictly prohibited unless
 specifically authorized in writing by STMicroelectronics.


********************************************************************************

 Alternatively, VL53LX Core may be distributed under the terms of
 'BSD 3-clause "New" or "Revised" License', in which case the following
 provisions apply instead of the ones
 mentioned above :

********************************************************************************

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


********************************************************************************

*/




#ifndef _VL53LX_API_PRESET_MODES_H_
#define _VL53LX_API_PRESET_MODES_H_

#include "vl53lx_ll_def.h"
#include "vl53lx_dmax_structs.h"

#ifdef __cplusplus
extern "C" {
#endif




VL53LX_Error VL53LX_init_refspadchar_config_struct(
	VL53LX_refspadchar_config_t     *pdata);




VL53LX_Error VL53LX_init_ssc_config_struct(
	VL53LX_ssc_config_t     *pdata);




VL53LX_Error VL53LX_init_xtalk_config_struct(
		VL53LX_customer_nvm_managed_t *pnvm,
		VL53LX_xtalk_config_t   *pdata);



VL53LX_Error VL53LX_init_xtalk_extract_config_struct(
		VL53LX_xtalkextract_config_t   *pdata);



VL53LX_Error VL53LX_init_offset_cal_config_struct(
	VL53LX_offsetcal_config_t   *pdata);



VL53LX_Error VL53LX_init_zone_cal_config_struct(
	VL53LX_zonecal_config_t   *pdata);



VL53LX_Error VL53LX_init_hist_post_process_config_struct(
	uint8_t                              xtalk_compensation_enable,
	VL53LX_hist_post_process_config_t   *pdata);




VL53LX_Error VL53LX_init_dmax_calibration_data_struct(
	VL53LX_dmax_calibration_data_t   *pdata);




VL53LX_Error VL53LX_init_tuning_parm_storage_struct(
	VL53LX_tuning_parm_storage_t   *pdata);



VL53LX_Error VL53LX_init_hist_gen3_dmax_config_struct(
	VL53LX_hist_gen3_dmax_config_t   *pdata);




VL53LX_Error VL53LX_preset_mode_standard_ranging(
	VL53LX_static_config_t     *pstatic,
	VL53LX_histogram_config_t  *phistogram,
	VL53LX_general_config_t    *pgeneral,
	VL53LX_timing_config_t     *ptiming,
	VL53LX_dynamic_config_t    *pdynamic,
	VL53LX_system_control_t    *psystem,
	VL53LX_tuning_parm_storage_t *ptuning_parms,
	VL53LX_zone_config_t       *pzone_cfg);



VL53LX_Error VL53LX_preset_mode_standard_ranging_short_range(
	VL53LX_static_config_t     *pstatic,
	VL53LX_histogram_config_t  *phistogram,
	VL53LX_general_config_t    *pgeneral,
	VL53LX_timing_config_t     *ptiming,
	VL53LX_dynamic_config_t    *pdynamic,
	VL53LX_system_control_t    *psystem,
	VL53LX_tuning_parm_storage_t *ptuning_parms,
	VL53LX_zone_config_t       *pzone_cfg);




VL53LX_Error VL53LX_preset_mode_standard_ranging_long_range(
	VL53LX_static_config_t     *pstatic,
	VL53LX_histogram_config_t  *phistogram,
	VL53LX_general_config_t    *pgeneral,
	VL53LX_timing_config_t     *ptiming,
	VL53LX_dynamic_config_t    *pdynamic,
	VL53LX_system_control_t    *psystem,
	VL53LX_tuning_parm_storage_t *ptuning_parms,
	VL53LX_zone_config_t       *pzone_cfg);




VL53LX_Error VL53LX_preset_mode_standard_ranging_mm1_cal(
	VL53LX_static_config_t     *pstatic,
	VL53LX_histogram_config_t  *phistogram,
	VL53LX_general_config_t    *pgeneral,
	VL53LX_timing_config_t     *ptiming,
	VL53LX_dynamic_config_t    *pdynamic,
	VL53LX_system_control_t    *psystem,
	VL53LX_tuning_parm_storage_t *ptuning_parms,
	VL53LX_zone_config_t       *pzone_cfg);




VL53LX_Error VL53LX_preset_mode_standard_ranging_mm2_cal(
	VL53LX_static_config_t     *pstatic,
	VL53LX_histogram_config_t  *phistogram,
	VL53LX_general_config_t    *pgeneral,
	VL53LX_timing_config_t     *ptiming,
	VL53LX_dynamic_config_t    *pdynamic,
	VL53LX_system_control_t    *psystem,
	VL53LX_tuning_parm_storage_t *ptuning_parms,
	VL53LX_zone_config_t       *pzone_cfg);




VL53LX_Error VL53LX_preset_mode_timed_ranging(

	VL53LX_static_config_t    *pstatic,
	VL53LX_histogram_config_t *phistogram,
	VL53LX_general_config_t   *pgeneral,
	VL53LX_timing_config_t    *ptiming,
	VL53LX_dynamic_config_t   *pdynamic,
	VL53LX_system_control_t   *psystem,
	VL53LX_tuning_parm_storage_t *ptuning_parms,
	VL53LX_zone_config_t      *pzone_cfg);



VL53LX_Error VL53LX_preset_mode_timed_ranging_short_range(

	VL53LX_static_config_t    *pstatic,
	VL53LX_histogram_config_t *phistogram,
	VL53LX_general_config_t   *pgeneral,
	VL53LX_timing_config_t    *ptiming,
	VL53LX_dynamic_config_t   *pdynamic,
	VL53LX_system_control_t   *psystem,
	VL53LX_tuning_parm_storage_t *ptuning_parms,
	VL53LX_zone_config_t      *pzone_cfg);



VL53LX_Error VL53LX_preset_mode_timed_ranging_long_range(

	VL53LX_static_config_t    *pstatic,
	VL53LX_histogram_config_t *phistogram,
	VL53LX_general_config_t   *pgeneral,
	VL53LX_timing_config_t    *ptiming,
	VL53LX_dynamic_config_t   *pdynamic,
	VL53LX_system_control_t   *psystem,
	VL53LX_tuning_parm_storage_t *ptuning_parms,
	VL53LX_zone_config_t      *pzone_cfg);



VL53LX_Error VL53LX_preset_mode_low_power_auto_ranging(

	VL53LX_static_config_t    *pstatic,
	VL53LX_histogram_config_t *phistogram,
	VL53LX_general_config_t   *pgeneral,
	VL53LX_timing_config_t    *ptiming,
	VL53LX_dynamic_config_t   *pdynamic,
	VL53LX_system_control_t   *psystem,
	VL53LX_tuning_parm_storage_t *ptuning_parms,
	VL53LX_zone_config_t      *pzone_cfg,
	VL53LX_low_power_auto_data_t *plpadata);



VL53LX_Error VL53LX_preset_mode_low_power_auto_short_ranging(

	VL53LX_static_config_t    *pstatic,
	VL53LX_histogram_config_t *phistogram,
	VL53LX_general_config_t   *pgeneral,
	VL53LX_timing_config_t    *ptiming,
	VL53LX_dynamic_config_t   *pdynamic,
	VL53LX_system_control_t   *psystem,
	VL53LX_tuning_parm_storage_t *ptuning_parms,
	VL53LX_zone_config_t      *pzone_cfg,
	VL53LX_low_power_auto_data_t *plpadata);



VL53LX_Error VL53LX_preset_mode_low_power_auto_long_ranging(

	VL53LX_static_config_t    *pstatic,
	VL53LX_histogram_config_t *phistogram,
	VL53LX_general_config_t   *pgeneral,
	VL53LX_timing_config_t    *ptiming,
	VL53LX_dynamic_config_t   *pdynamic,
	VL53LX_system_control_t   *psystem,
	VL53LX_tuning_parm_storage_t *ptuning_parms,
	VL53LX_zone_config_t      *pzone_cfg,
	VL53LX_low_power_auto_data_t *plpadata);



VL53LX_Error VL53LX_preset_mode_histogram_ranging(
	VL53LX_hist_post_process_config_t *phistpostprocess,
	VL53LX_static_config_t            *pstatic,
	VL53LX_histogram_config_t         *phistogram,
	VL53LX_general_config_t           *pgeneral,
	VL53LX_timing_config_t            *ptiming,
	VL53LX_dynamic_config_t           *pdynamic,
	VL53LX_system_control_t           *psystem,
	VL53LX_tuning_parm_storage_t      *ptuning_parms,
	VL53LX_zone_config_t              *pzone_cfg);




VL53LX_Error VL53LX_preset_mode_histogram_ranging_with_mm1(
	VL53LX_hist_post_process_config_t *phistpostprocess,
	VL53LX_static_config_t            *pstatic,
	VL53LX_histogram_config_t         *phistogram,
	VL53LX_general_config_t           *pgeneral,
	VL53LX_timing_config_t            *ptiming,
	VL53LX_dynamic_config_t           *pdynamic,
	VL53LX_system_control_t           *psystem,
	VL53LX_tuning_parm_storage_t      *ptuning_parms,
	VL53LX_zone_config_t              *pzone_cfg);




VL53LX_Error VL53LX_preset_mode_histogram_ranging_with_mm2(
	VL53LX_hist_post_process_config_t *phistpostprocess,
	VL53LX_static_config_t            *pstatic,
	VL53LX_histogram_config_t         *phistogram,
	VL53LX_general_config_t           *pgeneral,
	VL53LX_timing_config_t            *ptiming,
	VL53LX_dynamic_config_t           *pdynamic,
	VL53LX_system_control_t           *psystem,
	VL53LX_tuning_parm_storage_t      *ptuning_parms,
	VL53LX_zone_config_t              *pzone_cfg);




VL53LX_Error VL53LX_preset_mode_histogram_ranging_mm1_cal(
	VL53LX_hist_post_process_config_t *phistpostprocess,
	VL53LX_static_config_t            *pstatic,
	VL53LX_histogram_config_t         *phistogram,
	VL53LX_general_config_t           *pgeneral,
	VL53LX_timing_config_t            *ptiming,
	VL53LX_dynamic_config_t           *pdynamic,
	VL53LX_system_control_t           *psystem,
	VL53LX_tuning_parm_storage_t      *ptuning_parms,
	VL53LX_zone_config_t              *pzone_cfg);




VL53LX_Error VL53LX_preset_mode_histogram_ranging_mm2_cal(
	VL53LX_hist_post_process_config_t *phistpostprocess,
	VL53LX_static_config_t            *pstatic,
	VL53LX_histogram_config_t         *phistogram,
	VL53LX_general_config_t           *pgeneral,
	VL53LX_timing_config_t            *ptiming,
	VL53LX_dynamic_config_t           *pdynamic,
	VL53LX_system_control_t           *psystem,
	VL53LX_tuning_parm_storage_t      *ptuning_parms,
	VL53LX_zone_config_t              *pzone_cfg);




VL53LX_Error VL53LX_preset_mode_histogram_ranging_ref(
	VL53LX_hist_post_process_config_t *phistpostprocess,
	VL53LX_static_config_t            *pstatic,
	VL53LX_histogram_config_t         *phistogram,
	VL53LX_general_config_t           *pgeneral,
	VL53LX_timing_config_t            *ptiming,
	VL53LX_dynamic_config_t           *pdynamic,
	VL53LX_system_control_t           *psystem,
	VL53LX_tuning_parm_storage_t      *ptuning_parms,
	VL53LX_zone_config_t              *pzone_cfg);



VL53LX_Error VL53LX_preset_mode_histogram_characterisation(
	VL53LX_hist_post_process_config_t *phistpostprocess,
	VL53LX_static_config_t            *pstatic,
	VL53LX_histogram_config_t         *phistogram,
	VL53LX_general_config_t           *pgeneral,
	VL53LX_timing_config_t            *ptiming,
	VL53LX_dynamic_config_t           *pdynamic,
	VL53LX_system_control_t           *psystem,
	VL53LX_tuning_parm_storage_t      *ptuning_parms,
	VL53LX_zone_config_t              *pzone_cfg);




VL53LX_Error VL53LX_preset_mode_histogram_xtalk_planar(
	VL53LX_hist_post_process_config_t *phistpostprocess,
	VL53LX_static_config_t            *pstatic,
	VL53LX_histogram_config_t         *phistogram,
	VL53LX_general_config_t           *pgeneral,
	VL53LX_timing_config_t            *ptiming,
	VL53LX_dynamic_config_t           *pdynamic,
	VL53LX_system_control_t           *psystem,
	VL53LX_tuning_parm_storage_t      *ptuning_parms,
	VL53LX_zone_config_t              *pzone_cfg);




VL53LX_Error VL53LX_preset_mode_histogram_xtalk_mm1(
	VL53LX_hist_post_process_config_t *phistpostprocess,
	VL53LX_static_config_t            *pstatic,
	VL53LX_histogram_config_t         *phistogram,
	VL53LX_general_config_t           *pgeneral,
	VL53LX_timing_config_t            *ptiming,
	VL53LX_dynamic_config_t           *pdynamic,
	VL53LX_system_control_t           *psystem,
	VL53LX_tuning_parm_storage_t      *ptuning_parms,
	VL53LX_zone_config_t              *pzone_cfg);




VL53LX_Error VL53LX_preset_mode_histogram_xtalk_mm2(
	VL53LX_hist_post_process_config_t *phistpostprocess,
	VL53LX_static_config_t            *pstatic,
	VL53LX_histogram_config_t         *phistogram,
	VL53LX_general_config_t           *pgeneral,
	VL53LX_timing_config_t            *ptiming,
	VL53LX_dynamic_config_t           *pdynamic,
	VL53LX_system_control_t           *psystem,
	VL53LX_tuning_parm_storage_t      *ptuning_parms,
	VL53LX_zone_config_t              *pzone_cfg);



VL53LX_Error VL53LX_preset_mode_histogram_multizone(
	VL53LX_hist_post_process_config_t *phistpostprocess,
	VL53LX_static_config_t            *pstatic,
	VL53LX_histogram_config_t         *phistogram,
	VL53LX_general_config_t           *pgeneral,
	VL53LX_timing_config_t            *ptiming,
	VL53LX_dynamic_config_t           *pdynamic,
	VL53LX_system_control_t           *psystem,
	VL53LX_tuning_parm_storage_t      *ptuning_parms,
	VL53LX_zone_config_t              *pzone_cfg);



VL53LX_Error VL53LX_preset_mode_histogram_multizone_short_range(
	VL53LX_hist_post_process_config_t *phistpostprocess,
	VL53LX_static_config_t            *pstatic,
	VL53LX_histogram_config_t         *phistogram,
	VL53LX_general_config_t           *pgeneral,
	VL53LX_timing_config_t            *ptiming,
	VL53LX_dynamic_config_t           *pdynamic,
	VL53LX_system_control_t           *psystem,
	VL53LX_tuning_parm_storage_t      *ptuning_parms,
	VL53LX_zone_config_t              *pzone_cfg);



VL53LX_Error VL53LX_preset_mode_histogram_multizone_long_range(
	VL53LX_hist_post_process_config_t *phistpostprocess,
	VL53LX_static_config_t            *pstatic,
	VL53LX_histogram_config_t         *phistogram,
	VL53LX_general_config_t           *pgeneral,
	VL53LX_timing_config_t            *ptiming,
	VL53LX_dynamic_config_t           *pdynamic,
	VL53LX_system_control_t           *psystem,
	VL53LX_tuning_parm_storage_t      *ptuning_parms,
	VL53LX_zone_config_t              *pzone_cfg);



VL53LX_Error VL53LX_preset_mode_histogram_ranging_short_timing(
	VL53LX_hist_post_process_config_t *phistpostprocess,
	VL53LX_static_config_t            *pstatic,
	VL53LX_histogram_config_t         *phistogram,
	VL53LX_general_config_t           *pgeneral,
	VL53LX_timing_config_t            *ptiming,
	VL53LX_dynamic_config_t           *pdynamic,
	VL53LX_system_control_t           *psystem,
	VL53LX_tuning_parm_storage_t      *ptuning_parms,
	VL53LX_zone_config_t              *pzone_cfg);



VL53LX_Error VL53LX_preset_mode_histogram_long_range(
	VL53LX_hist_post_process_config_t *phistpostprocess,
	VL53LX_static_config_t            *pstatic,
	VL53LX_histogram_config_t         *phistogram,
	VL53LX_general_config_t           *pgeneral,
	VL53LX_timing_config_t            *ptiming,
	VL53LX_dynamic_config_t           *pdynamic,
	VL53LX_system_control_t           *psystem,
	VL53LX_tuning_parm_storage_t      *ptuning_parms,
	VL53LX_zone_config_t              *pzone_cfg);



VL53LX_Error VL53LX_preset_mode_histogram_medium_range(
	VL53LX_hist_post_process_config_t *phistpostprocess,
	VL53LX_static_config_t            *pstatic,
	VL53LX_histogram_config_t         *phistogram,
	VL53LX_general_config_t           *pgeneral,
	VL53LX_timing_config_t            *ptiming,
	VL53LX_dynamic_config_t           *pdynamic,
	VL53LX_system_control_t           *psystem,
	VL53LX_tuning_parm_storage_t      *ptuning_parms,
	VL53LX_zone_config_t              *pzone_cfg);



VL53LX_Error VL53LX_preset_mode_histogram_short_range(
	VL53LX_hist_post_process_config_t *phistpostprocess,
	VL53LX_static_config_t            *pstatic,
	VL53LX_histogram_config_t         *phistogram,
	VL53LX_general_config_t           *pgeneral,
	VL53LX_timing_config_t            *ptiming,
	VL53LX_dynamic_config_t           *pdynamic,
	VL53LX_system_control_t           *psystem,
	VL53LX_tuning_parm_storage_t      *ptuning_parms,
	VL53LX_zone_config_t              *pzone_cfg);



VL53LX_Error VL53LX_preset_mode_special_histogram_short_range(
	VL53LX_hist_post_process_config_t *phistpostprocess,
	VL53LX_static_config_t            *pstatic,
	VL53LX_histogram_config_t         *phistogram,
	VL53LX_general_config_t           *pgeneral,
	VL53LX_timing_config_t            *ptiming,
	VL53LX_dynamic_config_t           *pdynamic,
	VL53LX_system_control_t           *psystem,
	VL53LX_tuning_parm_storage_t      *ptuning_parms,
	VL53LX_zone_config_t              *pzone_cfg);



VL53LX_Error VL53LX_preset_mode_histogram_long_range_mm1(
	VL53LX_hist_post_process_config_t *phistpostprocess,
	VL53LX_static_config_t            *pstatic,
	VL53LX_histogram_config_t         *phistogram,
	VL53LX_general_config_t           *pgeneral,
	VL53LX_timing_config_t            *ptiming,
	VL53LX_dynamic_config_t           *pdynamic,
	VL53LX_system_control_t           *psystem,
	VL53LX_tuning_parm_storage_t      *ptuning_parms,
	VL53LX_zone_config_t              *pzone_cfg);



VL53LX_Error VL53LX_preset_mode_histogram_long_range_mm2(
	VL53LX_hist_post_process_config_t *phistpostprocess,
	VL53LX_static_config_t            *pstatic,
	VL53LX_histogram_config_t         *phistogram,
	VL53LX_general_config_t           *pgeneral,
	VL53LX_timing_config_t            *ptiming,
	VL53LX_dynamic_config_t           *pdynamic,
	VL53LX_system_control_t           *psystem,
	VL53LX_tuning_parm_storage_t      *ptuning_parms,
	VL53LX_zone_config_t              *pzone_cfg);



VL53LX_Error VL53LX_preset_mode_histogram_medium_range_mm1(
	VL53LX_hist_post_process_config_t *phistpostprocess,
	VL53LX_static_config_t            *pstatic,
	VL53LX_histogram_config_t         *phistogram,
	VL53LX_general_config_t           *pgeneral,
	VL53LX_timing_config_t            *ptiming,
	VL53LX_dynamic_config_t           *pdynamic,
	VL53LX_system_control_t           *psystem,
	VL53LX_tuning_parm_storage_t      *ptuning_parms,
	VL53LX_zone_config_t              *pzone_cfg);



VL53LX_Error VL53LX_preset_mode_histogram_medium_range_mm2(
	VL53LX_hist_post_process_config_t *phistpostprocess,
	VL53LX_static_config_t            *pstatic,
	VL53LX_histogram_config_t         *phistogram,
	VL53LX_general_config_t           *pgeneral,
	VL53LX_timing_config_t            *ptiming,
	VL53LX_dynamic_config_t           *pdynamic,
	VL53LX_system_control_t           *psystem,
	VL53LX_tuning_parm_storage_t      *ptuning_parms,
	VL53LX_zone_config_t              *pzone_cfg);



VL53LX_Error VL53LX_preset_mode_histogram_short_range_mm1(
	VL53LX_hist_post_process_config_t *phistpostprocess,
	VL53LX_static_config_t            *pstatic,
	VL53LX_histogram_config_t         *phistogram,
	VL53LX_general_config_t           *pgeneral,
	VL53LX_timing_config_t            *ptiming,
	VL53LX_dynamic_config_t           *pdynamic,
	VL53LX_system_control_t           *psystem,
	VL53LX_tuning_parm_storage_t      *ptuning_parms,
	VL53LX_zone_config_t              *pzone_cfg);



VL53LX_Error VL53LX_preset_mode_histogram_short_range_mm2(
	VL53LX_hist_post_process_config_t *phistpostprocess,
	VL53LX_static_config_t            *pstatic,
	VL53LX_histogram_config_t         *phistogram,
	VL53LX_general_config_t           *pgeneral,
	VL53LX_timing_config_t            *ptiming,
	VL53LX_dynamic_config_t           *pdynamic,
	VL53LX_system_control_t           *psystem,
	VL53LX_tuning_parm_storage_t      *ptuning_parms,
	VL53LX_zone_config_t              *pzone_cfg);



VL53LX_Error VL53LX_preset_mode_olt(
	VL53LX_static_config_t     *pstatic,
	VL53LX_histogram_config_t  *phistogram,
	VL53LX_general_config_t    *pgeneral,
	VL53LX_timing_config_t     *ptiming,
	VL53LX_dynamic_config_t    *pdynamic,
	VL53LX_system_control_t    *psystem,
	VL53LX_tuning_parm_storage_t *ptuning_parms,
	VL53LX_zone_config_t       *pzone_cfg);



VL53LX_Error VL53LX_preset_mode_singleshot_ranging(

	VL53LX_static_config_t    *pstatic,
	VL53LX_histogram_config_t *phistogram,
	VL53LX_general_config_t   *pgeneral,
	VL53LX_timing_config_t    *ptiming,
	VL53LX_dynamic_config_t   *pdynamic,
	VL53LX_system_control_t   *psystem,
	VL53LX_tuning_parm_storage_t *ptuning_parms,
	VL53LX_zone_config_t      *pzone_cfg);




void VL53LX_copy_hist_cfg_to_static_cfg(
	VL53LX_histogram_config_t  *phistogram,
	VL53LX_static_config_t     *pstatic,
	VL53LX_general_config_t    *pgeneral,
	VL53LX_timing_config_t     *ptiming,
	VL53LX_dynamic_config_t    *pdynamic);



void VL53LX_copy_hist_bins_to_static_cfg(
	VL53LX_histogram_config_t *phistogram,
	VL53LX_static_config_t    *pstatic,
	VL53LX_timing_config_t    *ptiming);

#ifdef __cplusplus
}
#endif

#endif
