#ifndef __c9_wabs_perceptionmodel_VPT_Limbic_v3_adj_h__
#define __c9_wabs_perceptionmodel_VPT_Limbic_v3_adj_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc9_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct
#define typedef_SFc9_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c9_sfEvent;
  boolean_T c9_isStable;
  boolean_T c9_doneDoubleBufferReInit;
  uint8_T c9_is_active_c9_wabs_perceptionmodel_VPT_Limbic_v3_adj;
  real_T (*c9_RPY)[3];
  real_T (*c9_DCM)[9];
} SFc9_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct;

#endif                                 /*typedef_SFc9_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c9_wabs_perceptionmodel_VPT_Limbic_v3_adj_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c9_wabs_perceptionmodel_VPT_Limbic_v3_adj_get_check_sum(mxArray
  *plhs[]);
extern void c9_wabs_perceptionmodel_VPT_Limbic_v3_adj_method_dispatcher
  (SimStruct *S, int_T method, void *data);

#endif
