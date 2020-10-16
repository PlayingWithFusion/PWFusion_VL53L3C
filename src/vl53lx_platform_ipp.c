
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




#include "vl53lx_platform_ipp.h"
#include "vl53lx_ll_def.h"
#include "vl53lx_hist_structs.h"
#include "vl53lx_hist_funcs.h"
#include "vl53lx_xtalk.h"


#define LOG_FUNCTION_START(fmt, ...) \
	_LOG_FUNCTION_START(VL53LX_TRACE_MODULE_CORE, fmt, ##__VA_ARGS__)
#define LOG_FUNCTION_END(status, ...) \
	_LOG_FUNCTION_END(VL53LX_TRACE_MODULE_CORE, status, ##__VA_ARGS__)


VL53LX_Error VL53LX_ipp_hist_process_data(
	VL53LX_DEV                         Dev,
	VL53LX_dmax_calibration_data_t    *pdmax_cal,
	VL53LX_hist_gen3_dmax_config_t    *pdmax_cfg,
	VL53LX_hist_post_process_config_t *ppost_cfg,
	VL53LX_histogram_bin_data_t       *pbins,
	VL53LX_xtalk_histogram_data_t     *pxtalk,
	uint8_t                           *pArea1,
	uint8_t                           *pArea2,
	uint8_t                           *phisto_merge_nb,
	VL53LX_range_results_t            *presults)
{



	VL53LX_Error status         = VL53LX_ERROR_NONE;

	SUPPRESS_UNUSED_WARNING(Dev);

	status =
		VL53LX_hist_process_data(
			pdmax_cal,
			pdmax_cfg,
			ppost_cfg,
			pbins,
			pxtalk,
			pArea1,
			pArea2,
			presults,
			phisto_merge_nb);

	return status;
}


VL53LX_Error VL53LX_ipp_hist_ambient_dmax(
	VL53LX_DEV                         Dev,
	uint16_t                           target_reflectance,
	VL53LX_dmax_calibration_data_t    *pdmax_cal,
	VL53LX_hist_gen3_dmax_config_t    *pdmax_cfg,
	VL53LX_histogram_bin_data_t       *pbins,
	int16_t                           *pambient_dmax_mm)
{



    VL53LX_Error status         = VL53LX_ERROR_NONE;

	SUPPRESS_UNUSED_WARNING(Dev);

    status =
    	VL53LX_hist_ambient_dmax(
    		target_reflectance,
    		pdmax_cal,
    		pdmax_cfg,
			pbins,
			pambient_dmax_mm);

	return status;
}


VL53LX_Error VL53LX_ipp_xtalk_calibration_process_data(
	VL53LX_DEV                          Dev,
	VL53LX_xtalk_range_results_t       *pxtalk_ranges,
	VL53LX_xtalk_histogram_data_t      *pxtalk_shape,
	VL53LX_xtalk_calibration_results_t *pxtalk_cal)
{



	VL53LX_Error status         = VL53LX_ERROR_NONE;

	SUPPRESS_UNUSED_WARNING(Dev);

	status =
		VL53LX_xtalk_calibration_process_data(
			pxtalk_ranges,
			pxtalk_shape,
			pxtalk_cal);

	return status;
}


VL53LX_Error VL53LX_ipp_hist_xtalk_correction(
	VL53LX_DEV                     Dev,
	VL53LX_customer_nvm_managed_t *pcustomer,
	VL53LX_dynamic_config_t       *pdyn_cfg,
	VL53LX_xtalk_histogram_data_t *pxtalk_shape,
	VL53LX_histogram_bin_data_t   *pip_hist_data,
	VL53LX_histogram_bin_data_t   *pop_hist_data,
	VL53LX_histogram_bin_data_t   *pxtalk_count_data)
{



	VL53LX_Error status         = VL53LX_ERROR_NONE;

	SUPPRESS_UNUSED_WARNING(Dev);

	status =
		VL53LX_f_046(
			pcustomer,
			pdyn_cfg,
			pxtalk_shape,
			pip_hist_data,
			pop_hist_data,
			pxtalk_count_data);

	return status;
}

VL53LX_Error VL53LX_ipp_generate_dual_reflectance_xtalk_samples(
	VL53LX_DEV                     Dev,
	VL53LX_xtalk_range_results_t  *pxtalk_results,
	uint16_t 			           expected_target_distance_mm,
	uint8_t                        higher_reflectance,
	VL53LX_histogram_bin_data_t	  *pxtalk_avg_samples)
{


	VL53LX_Error status         = VL53LX_ERROR_NONE;

	SUPPRESS_UNUSED_WARNING(Dev);

	status = VL53LX_generate_dual_reflectance_xtalk_samples(
			pxtalk_results,
		    expected_target_distance_mm,
		    higher_reflectance,
		    pxtalk_avg_samples);

	return status;

}
