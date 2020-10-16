
/*******************************************************************************
 This file is part of VL53LX Protected

 Copyright (c) 2020, STMicroelectronics - All Rights Reserved

 License terms: STMicroelectronics Proprietary in accordance with licensing
 terms at www.st.com/sla0081

 STMicroelectronics confidential
 Reproduction and Communication of this document is strictly prohibited unless
 specifically authorized in writing by STMicroelectronics.

*/




#ifndef _VL53LX_SIGMA_ESTIMATE_H_
#define _VL53LX_SIGMA_ESTIMATE_H_

#include "vl53lx_types.h"
#include "vl53lx_ll_def.h"

#ifdef __cplusplus
extern "C" {
#endif

#define  VL53LX_D_002  0xFFFF


#define VL53LX_D_008	0xFFFF
#define VL53LX_D_003	0xFFFFFF
#define VL53LX_D_007	0xFFFFFFFF
#define VL53LX_D_005	0x7FFFFFFFFF
#define VL53LX_D_009	0xFFFFFFFFFF
#define VL53LX_D_010	0xFFFFFFFFFFFF
#define VL53LX_D_004	0xFFFFFFFFFFFFFF
#define VL53LX_D_006	0x7FFFFFFFFFFFFFFF
#define VL53LX_D_011	0xFFFFFFFFFFFFFFFF




uint16_t VL53LX_f_034(
	uint8_t	 sigma_estimator__effective_pulse_width_ns,
	uint8_t  sigma_estimator__effective_ambient_width_ns,
	uint8_t	 sigma_estimator__sigma_ref_mm,
	VL53LX_range_data_t  *pdata);




uint16_t VL53LX_f_036(
	uint8_t	 sigma_estimator__effective_pulse_width_ns,
	uint8_t  sigma_estimator__effective_ambient_width_ns,
	uint8_t	 sigma_estimator__sigma_ref_mm,
	VL53LX_range_data_t *pdata);






VL53LX_Error  VL53LX_f_037(
	uint8_t	      sigma_estimator__sigma_ref_mm,
	uint32_t      VL53LX_p_007,
	uint32_t      VL53LX_p_032,
	uint32_t      VL53LX_p_001,
	uint32_t      a_zp,
	uint32_t      c_zp,
	uint32_t      bx,
	uint32_t      ax_zp,
	uint32_t      cx_zp,
	uint32_t      VL53LX_p_028,
	uint16_t      fast_osc_frequency,
	uint16_t      *psigma_est);







VL53LX_Error  VL53LX_f_023(
	uint8_t	      sigma_estimator__sigma_ref_mm,
	uint32_t      VL53LX_p_007,
	uint32_t      VL53LX_p_032,
	uint32_t      VL53LX_p_001,
	uint32_t      a_zp,
	uint32_t      c_zp,
	uint32_t      bx,
	uint32_t      ax_zp,
	uint32_t      cx_zp,
	uint32_t      VL53LX_p_028,
	uint16_t      fast_osc_frequency,
	uint16_t      *psigma_est);



uint32_t VL53LX_f_038(
	uint64_t VL53LX_p_007,
	uint32_t size
	);





uint32_t VL53LX_f_035(
	uint32_t  VL53LX_p_007,
	uint32_t  VL53LX_p_032);


#ifdef __cplusplus
}
#endif

#endif
