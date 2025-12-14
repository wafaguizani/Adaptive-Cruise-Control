/*
 * File: ACC_SWC.c
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

#include "ACC_SWC.h"
#include "Platform_Types.h"
#include "ACC_SWC_private.h"
#include <math.h>

/* Named constants for Chart: '<Root>/ACC_Logic' */
#define ACC_SWC_IN_CRUISING            ((uint8)1U)
#define ACC_SWC_IN_FOLLOWING           ((uint8)2U)
#define ACC_SWC_IN_OFF                 ((uint8)3U)

/* PublicStructure Variables for Internal Data */
ARID_DEF_ACC_SWC_T ACC_SWC_ARID_DEF;   /* '<Root>/ACC_Logic' */
float64 rt_roundd(float64 u)
{
  float64 y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

/* Model step function */
void ACC_SWC_Step(void)
{
  float64 tmp_0;
  uint8 rtb_State_Display;
  uint8 tmp;

  /* Chart: '<Root>/ACC_Logic' incorporates:
   *  Inport: '<Root>/Current_Speed'
   *  Inport: '<Root>/Radar_Dist'
   *  Inport: '<Root>/Set_Speed'
   *  Inport: '<Root>/Switch_ACC'
   */
  if (ACC_SWC_ARID_DEF.is_active_c3_ACC_SWC == 0) {
    ACC_SWC_ARID_DEF.is_active_c3_ACC_SWC = 1U;
    ACC_SWC_ARID_DEF.is_c3_ACC_SWC = ACC_SWC_IN_OFF;
    ACC_SWC_ARID_DEF.Accel_Req = 0U;
    ACC_SWC_ARID_DEF.Brake_Req = FALSE;
    rtb_State_Display = 0U;
  } else {
    switch (ACC_SWC_ARID_DEF.is_c3_ACC_SWC) {
     case ACC_SWC_IN_CRUISING:
      rtb_State_Display = 1U;
      if (!Rte_IRead_ACC_SWC_Step_Switch_ACC_Switch_ACC()) {
        ACC_SWC_ARID_DEF.is_c3_ACC_SWC = ACC_SWC_IN_OFF;
        ACC_SWC_ARID_DEF.Accel_Req = 0U;
        ACC_SWC_ARID_DEF.Brake_Req = FALSE;
        rtb_State_Display = 0U;
      } else if (Rte_IRead_ACC_SWC_Step_Radar_Dist_Radar_Dist() < 50) {
        ACC_SWC_ARID_DEF.is_c3_ACC_SWC = ACC_SWC_IN_FOLLOWING;
        rtb_State_Display = 2U;
      } else {
        ACC_SWC_ARID_DEF.Brake_Req = FALSE;
        tmp_0 = rt_roundd(Rte_IRead_ACC_SWC_Step_Set_Speed_Set_Speed() -
                          (float64)
                          Rte_IRead_ACC_SWC_Step_Current_Speed_Current_Speed());
        if (tmp_0 < 256.0) {
          if (tmp_0 >= 0.0) {
            tmp = (uint8)tmp_0;
          } else {
            tmp = 0U;
          }
        } else {
          tmp = ((uint8)(255U));
        }

        if (tmp > 127) {
          ACC_SWC_ARID_DEF.Accel_Req = ((uint8)(255U));
        } else {
          ACC_SWC_ARID_DEF.Accel_Req = (uint8)(tmp << 1);
        }
      }
      break;

     case ACC_SWC_IN_FOLLOWING:
      rtb_State_Display = 2U;
      if (Rte_IRead_ACC_SWC_Step_Radar_Dist_Radar_Dist() > 60) {
        ACC_SWC_ARID_DEF.is_c3_ACC_SWC = ACC_SWC_IN_CRUISING;
        rtb_State_Display = 1U;
      } else if (!Rte_IRead_ACC_SWC_Step_Switch_ACC_Switch_ACC()) {
        ACC_SWC_ARID_DEF.is_c3_ACC_SWC = ACC_SWC_IN_OFF;
        ACC_SWC_ARID_DEF.Accel_Req = 0U;
        ACC_SWC_ARID_DEF.Brake_Req = FALSE;
        rtb_State_Display = 0U;
      } else {
        ACC_SWC_ARID_DEF.Accel_Req = 0U;
        ACC_SWC_ARID_DEF.Brake_Req = TRUE;
      }
      break;

     default:
      /* case IN_OFF: */
      rtb_State_Display = 0U;
      if (Rte_IRead_ACC_SWC_Step_Switch_ACC_Switch_ACC()) {
        ACC_SWC_ARID_DEF.is_c3_ACC_SWC = ACC_SWC_IN_CRUISING;
        rtb_State_Display = 1U;
      }
      break;
    }
  }

  /* End of Chart: '<Root>/ACC_Logic' */

  /* Outport: '<Root>/Accel_Req' */
  Rte_IWrite_ACC_SWC_Step_Accel_Req_Accel_Req(ACC_SWC_ARID_DEF.Accel_Req);

  /* Outport: '<Root>/Brake_Req' */
  Rte_IWrite_ACC_SWC_Step_Brake_Req_Brake_Req(ACC_SWC_ARID_DEF.Brake_Req);

  /* Outport: '<Root>/State_Display' */
  Rte_IWrite_ACC_SWC_Step_State_Display_State_Display(rtb_State_Display);
}

/* Model initialize function */
void ACC_SWC_Init(void)
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
