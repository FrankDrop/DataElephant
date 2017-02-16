#ifndef __c32_kuka_classic_mda_daan_carthesian_h__
#define __c32_kuka_classic_mda_daan_carthesian_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc32_kuka_classic_mda_daan_carthesianInstanceStruct
#define typedef_SFc32_kuka_classic_mda_daan_carthesianInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c32_sfEvent;
  boolean_T c32_isStable;
  boolean_T c32_doneDoubleBufferReInit;
  uint8_T c32_is_active_c32_kuka_classic_mda_daan_carthesian;
  real_T (*c32_RPY)[3];
  real_T (*c32_DCM)[9];
} SFc32_kuka_classic_mda_daan_carthesianInstanceStruct;

#endif                                 /*typedef_SFc32_kuka_classic_mda_daan_carthesianInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c32_kuka_classic_mda_daan_carthesian_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c32_kuka_classic_mda_daan_carthesian_get_check_sum(mxArray *plhs[]);
extern void c32_kuka_classic_mda_daan_carthesian_method_dispatcher(SimStruct *S,
  int_T method, void *data);

#endif
