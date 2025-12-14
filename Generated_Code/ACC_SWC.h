/*
 * File: ACC_SWC.h
 *
 * Code generated for Simulink model 'ACC_SWC'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Sun Dec 14 11:37:18 2025
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef ACC_SWC_h_
#define ACC_SWC_h_
#ifndef ACC_SWC_COMMON_INCLUDES_
#define ACC_SWC_COMMON_INCLUDES_
#include "Platform_Types.h"
#include "Rte_ACC_SWC.h"
#endif                                 /* ACC_SWC_COMMON_INCLUDES_ */

#include "ACC_SWC_types.h"

/* PublicStructure Variables for Internal Data, for system '<Root>' */
typedef struct {
  uint8 Accel_Req;                     /* '<Root>/ACC_Logic' */
  uint8 is_active_c3_ACC_SWC;          /* '<Root>/ACC_Logic' */
  uint8 is_c3_ACC_SWC;                 /* '<Root>/ACC_Logic' */
  boolean Brake_Req;                   /* '<Root>/ACC_Logic' */
} ARID_DEF_ACC_SWC_T;

/* PublicStructure Variables for Internal Data */
extern ARID_DEF_ACC_SWC_T ACC_SWC_ARID_DEF;/* '<Root>/ACC_Logic' */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'ACC_SWC'
 * '<S1>'   : 'ACC_SWC/ACC_Logic'
 */
#endif                                 /* ACC_SWC_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
