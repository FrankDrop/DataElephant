/* Include files */

#include <stddef.h>
#include "blas.h"
#include "wabs_perceptionmodel_VPT_Limbic_v3_adj_sfun.h"
#include "c10_wabs_perceptionmodel_VPT_Limbic_v3_adj.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "wabs_perceptionmodel_VPT_Limbic_v3_adj_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c10_debug_family_names[4] = { "nargin", "nargout", "u", "S"
};

/* Function Declarations */
static void initialize_c10_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SFc10_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance);
static void initialize_params_c10_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SFc10_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance);
static void enable_c10_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SFc10_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance);
static void disable_c10_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SFc10_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance);
static void c10_update_debugger_state_c10_wabs_perceptionmodel_VPT_Limbic_v3
  (SFc10_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c10_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SFc10_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance);
static void set_sim_state_c10_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SFc10_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance,
   const mxArray *c10_st);
static void finalize_c10_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SFc10_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance);
static void sf_gateway_c10_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SFc10_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance);
static void mdl_start_c10_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SFc10_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance);
static void initSimStructsc10_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SFc10_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c10_machineNumber, uint32_T
  c10_chartNumber, uint32_T c10_instanceNumber);
static const mxArray *c10_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static void c10_emlrt_marshallIn
  (SFc10_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance,
   const mxArray *c10_b_S, const char_T *c10_identifier, real_T c10_y[9]);
static void c10_b_emlrt_marshallIn
  (SFc10_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance,
   const mxArray *c10_b_u, const emlrtMsgIdentifier *c10_parentId, real_T c10_y
   [9]);
static void c10_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData);
static const mxArray *c10_b_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static const mxArray *c10_c_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static real_T c10_c_emlrt_marshallIn
  (SFc10_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance,
   const mxArray *c10_b_u, const emlrtMsgIdentifier *c10_parentId);
static void c10_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData);
static const mxArray *c10_d_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static int32_T c10_d_emlrt_marshallIn
  (SFc10_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance,
   const mxArray *c10_b_u, const emlrtMsgIdentifier *c10_parentId);
static void c10_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData);
static uint8_T c10_e_emlrt_marshallIn
  (SFc10_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance,
   const mxArray *c10_b_is_active_c10_wabs_perceptionmodel_VPT_Limbic_v3_adj,
   const char_T *c10_identifier);
static uint8_T c10_f_emlrt_marshallIn
  (SFc10_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance,
   const mxArray *c10_b_u, const emlrtMsgIdentifier *c10_parentId);
static void init_dsm_address_info
  (SFc10_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance);
static void init_simulink_io_address
  (SFc10_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c10_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SFc10_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance)
{
  chartInstance->c10_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c10_is_active_c10_wabs_perceptionmodel_VPT_Limbic_v3_adj = 0U;
}

static void initialize_params_c10_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SFc10_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c10_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SFc10_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c10_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SFc10_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c10_update_debugger_state_c10_wabs_perceptionmodel_VPT_Limbic_v3
  (SFc10_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c10_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SFc10_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance)
{
  const mxArray *c10_st;
  const mxArray *c10_y = NULL;
  int32_T c10_i0;
  real_T c10_b_u[9];
  const mxArray *c10_b_y = NULL;
  uint8_T c10_hoistedGlobal;
  uint8_T c10_c_u;
  const mxArray *c10_c_y = NULL;
  c10_st = NULL;
  c10_st = NULL;
  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_createcellmatrix(2, 1), false);
  for (c10_i0 = 0; c10_i0 < 9; c10_i0++) {
    c10_b_u[c10_i0] = (*chartInstance->c10_S)[c10_i0];
  }

  c10_b_y = NULL;
  sf_mex_assign(&c10_b_y, sf_mex_create("y", c10_b_u, 0, 0U, 1U, 0U, 2, 3, 3),
                false);
  sf_mex_setcell(c10_y, 0, c10_b_y);
  c10_hoistedGlobal =
    chartInstance->c10_is_active_c10_wabs_perceptionmodel_VPT_Limbic_v3_adj;
  c10_c_u = c10_hoistedGlobal;
  c10_c_y = NULL;
  sf_mex_assign(&c10_c_y, sf_mex_create("y", &c10_c_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c10_y, 1, c10_c_y);
  sf_mex_assign(&c10_st, c10_y, false);
  return c10_st;
}

static void set_sim_state_c10_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SFc10_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance,
   const mxArray *c10_st)
{
  const mxArray *c10_b_u;
  real_T c10_dv0[9];
  int32_T c10_i1;
  chartInstance->c10_doneDoubleBufferReInit = true;
  c10_b_u = sf_mex_dup(c10_st);
  c10_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c10_b_u, 0)),
                       "S", c10_dv0);
  for (c10_i1 = 0; c10_i1 < 9; c10_i1++) {
    (*chartInstance->c10_S)[c10_i1] = c10_dv0[c10_i1];
  }

  chartInstance->c10_is_active_c10_wabs_perceptionmodel_VPT_Limbic_v3_adj =
    c10_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c10_b_u, 1)),
    "is_active_c10_wabs_perceptionmodel_VPT_Limbic_v3_adj");
  sf_mex_destroy(&c10_b_u);
  c10_update_debugger_state_c10_wabs_perceptionmodel_VPT_Limbic_v3(chartInstance);
  sf_mex_destroy(&c10_st);
}

static void finalize_c10_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SFc10_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c10_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SFc10_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance)
{
  int32_T c10_i2;
  int32_T c10_i3;
  real_T c10_b_u[3];
  uint32_T c10_debug_family_var_map[4];
  real_T c10_nargin = 1.0;
  real_T c10_nargout = 1.0;
  real_T c10_b_S[9];
  int32_T c10_i4;
  int32_T c10_i5;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 9U, chartInstance->c10_sfEvent);
  for (c10_i2 = 0; c10_i2 < 3; c10_i2++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c10_u)[c10_i2], 0U);
  }

  chartInstance->c10_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 9U, chartInstance->c10_sfEvent);
  for (c10_i3 = 0; c10_i3 < 3; c10_i3++) {
    c10_b_u[c10_i3] = (*chartInstance->c10_u)[c10_i3];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 4U, c10_debug_family_names,
    c10_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_nargin, 0U, c10_c_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_nargout, 1U, c10_c_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c10_b_u, 2U, c10_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c10_b_S, 3U, c10_sf_marshallOut,
    c10_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 3);
  c10_b_S[0] = 0.0;
  c10_b_S[3] = -c10_b_u[2];
  c10_b_S[6] = c10_b_u[1];
  c10_b_S[1] = c10_b_u[2];
  c10_b_S[4] = 0.0;
  c10_b_S[7] = -c10_b_u[0];
  c10_b_S[2] = -c10_b_u[1];
  c10_b_S[5] = c10_b_u[0];
  c10_b_S[8] = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, -3);
  _SFD_SYMBOL_SCOPE_POP();
  for (c10_i4 = 0; c10_i4 < 9; c10_i4++) {
    (*chartInstance->c10_S)[c10_i4] = c10_b_S[c10_i4];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 9U, chartInstance->c10_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY
    (_wabs_perceptionmodel_VPT_Limbic_v3_adjMachineNumber_,
     chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c10_i5 = 0; c10_i5 < 9; c10_i5++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c10_S)[c10_i5], 1U);
  }
}

static void mdl_start_c10_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SFc10_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void initSimStructsc10_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SFc10_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c10_machineNumber, uint32_T
  c10_chartNumber, uint32_T c10_instanceNumber)
{
  (void)c10_machineNumber;
  (void)c10_chartNumber;
  (void)c10_instanceNumber;
}

static const mxArray *c10_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int32_T c10_i6;
  int32_T c10_i7;
  int32_T c10_i8;
  real_T c10_b_inData[9];
  int32_T c10_i9;
  int32_T c10_i10;
  int32_T c10_i11;
  real_T c10_b_u[9];
  const mxArray *c10_y = NULL;
  SFc10_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance;
  chartInstance = (SFc10_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *)
    chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  c10_i6 = 0;
  for (c10_i7 = 0; c10_i7 < 3; c10_i7++) {
    for (c10_i8 = 0; c10_i8 < 3; c10_i8++) {
      c10_b_inData[c10_i8 + c10_i6] = (*(real_T (*)[9])c10_inData)[c10_i8 +
        c10_i6];
    }

    c10_i6 += 3;
  }

  c10_i9 = 0;
  for (c10_i10 = 0; c10_i10 < 3; c10_i10++) {
    for (c10_i11 = 0; c10_i11 < 3; c10_i11++) {
      c10_b_u[c10_i11 + c10_i9] = c10_b_inData[c10_i11 + c10_i9];
    }

    c10_i9 += 3;
  }

  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", c10_b_u, 0, 0U, 1U, 0U, 2, 3, 3),
                false);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, false);
  return c10_mxArrayOutData;
}

static void c10_emlrt_marshallIn
  (SFc10_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance,
   const mxArray *c10_b_S, const char_T *c10_identifier, real_T c10_y[9])
{
  emlrtMsgIdentifier c10_thisId;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_b_S), &c10_thisId, c10_y);
  sf_mex_destroy(&c10_b_S);
}

static void c10_b_emlrt_marshallIn
  (SFc10_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance,
   const mxArray *c10_b_u, const emlrtMsgIdentifier *c10_parentId, real_T c10_y
   [9])
{
  real_T c10_dv1[9];
  int32_T c10_i12;
  (void)chartInstance;
  sf_mex_import(c10_parentId, sf_mex_dup(c10_b_u), c10_dv1, 1, 0, 0U, 1, 0U, 2,
                3, 3);
  for (c10_i12 = 0; c10_i12 < 9; c10_i12++) {
    c10_y[c10_i12] = c10_dv1[c10_i12];
  }

  sf_mex_destroy(&c10_b_u);
}

static void c10_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData)
{
  const mxArray *c10_b_S;
  const char_T *c10_identifier;
  emlrtMsgIdentifier c10_thisId;
  real_T c10_y[9];
  int32_T c10_i13;
  int32_T c10_i14;
  int32_T c10_i15;
  SFc10_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance;
  chartInstance = (SFc10_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *)
    chartInstanceVoid;
  c10_b_S = sf_mex_dup(c10_mxArrayInData);
  c10_identifier = c10_varName;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_b_S), &c10_thisId, c10_y);
  sf_mex_destroy(&c10_b_S);
  c10_i13 = 0;
  for (c10_i14 = 0; c10_i14 < 3; c10_i14++) {
    for (c10_i15 = 0; c10_i15 < 3; c10_i15++) {
      (*(real_T (*)[9])c10_outData)[c10_i15 + c10_i13] = c10_y[c10_i15 + c10_i13];
    }

    c10_i13 += 3;
  }

  sf_mex_destroy(&c10_mxArrayInData);
}

static const mxArray *c10_b_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int32_T c10_i16;
  real_T c10_b_inData[3];
  int32_T c10_i17;
  real_T c10_b_u[3];
  const mxArray *c10_y = NULL;
  SFc10_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance;
  chartInstance = (SFc10_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *)
    chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  for (c10_i16 = 0; c10_i16 < 3; c10_i16++) {
    c10_b_inData[c10_i16] = (*(real_T (*)[3])c10_inData)[c10_i16];
  }

  for (c10_i17 = 0; c10_i17 < 3; c10_i17++) {
    c10_b_u[c10_i17] = c10_b_inData[c10_i17];
  }

  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", c10_b_u, 0, 0U, 1U, 0U, 1, 3), false);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, false);
  return c10_mxArrayOutData;
}

static const mxArray *c10_c_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  real_T c10_b_u;
  const mxArray *c10_y = NULL;
  SFc10_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance;
  chartInstance = (SFc10_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *)
    chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  c10_b_u = *(real_T *)c10_inData;
  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", &c10_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, false);
  return c10_mxArrayOutData;
}

static real_T c10_c_emlrt_marshallIn
  (SFc10_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance,
   const mxArray *c10_b_u, const emlrtMsgIdentifier *c10_parentId)
{
  real_T c10_y;
  real_T c10_d0;
  (void)chartInstance;
  sf_mex_import(c10_parentId, sf_mex_dup(c10_b_u), &c10_d0, 1, 0, 0U, 0, 0U, 0);
  c10_y = c10_d0;
  sf_mex_destroy(&c10_b_u);
  return c10_y;
}

static void c10_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData)
{
  const mxArray *c10_nargout;
  const char_T *c10_identifier;
  emlrtMsgIdentifier c10_thisId;
  real_T c10_y;
  SFc10_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance;
  chartInstance = (SFc10_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *)
    chartInstanceVoid;
  c10_nargout = sf_mex_dup(c10_mxArrayInData);
  c10_identifier = c10_varName;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_y = c10_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_nargout),
    &c10_thisId);
  sf_mex_destroy(&c10_nargout);
  *(real_T *)c10_outData = c10_y;
  sf_mex_destroy(&c10_mxArrayInData);
}

const mxArray
  *sf_c10_wabs_perceptionmodel_VPT_Limbic_v3_adj_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c10_nameCaptureInfo = NULL;
  c10_nameCaptureInfo = NULL;
  sf_mex_assign(&c10_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c10_nameCaptureInfo;
}

static const mxArray *c10_d_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int32_T c10_b_u;
  const mxArray *c10_y = NULL;
  SFc10_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance;
  chartInstance = (SFc10_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *)
    chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  c10_b_u = *(int32_T *)c10_inData;
  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", &c10_b_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, false);
  return c10_mxArrayOutData;
}

static int32_T c10_d_emlrt_marshallIn
  (SFc10_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance,
   const mxArray *c10_b_u, const emlrtMsgIdentifier *c10_parentId)
{
  int32_T c10_y;
  int32_T c10_i18;
  (void)chartInstance;
  sf_mex_import(c10_parentId, sf_mex_dup(c10_b_u), &c10_i18, 1, 6, 0U, 0, 0U, 0);
  c10_y = c10_i18;
  sf_mex_destroy(&c10_b_u);
  return c10_y;
}

static void c10_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData)
{
  const mxArray *c10_b_sfEvent;
  const char_T *c10_identifier;
  emlrtMsgIdentifier c10_thisId;
  int32_T c10_y;
  SFc10_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance;
  chartInstance = (SFc10_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *)
    chartInstanceVoid;
  c10_b_sfEvent = sf_mex_dup(c10_mxArrayInData);
  c10_identifier = c10_varName;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_y = c10_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_b_sfEvent),
    &c10_thisId);
  sf_mex_destroy(&c10_b_sfEvent);
  *(int32_T *)c10_outData = c10_y;
  sf_mex_destroy(&c10_mxArrayInData);
}

static uint8_T c10_e_emlrt_marshallIn
  (SFc10_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance,
   const mxArray *c10_b_is_active_c10_wabs_perceptionmodel_VPT_Limbic_v3_adj,
   const char_T *c10_identifier)
{
  uint8_T c10_y;
  emlrtMsgIdentifier c10_thisId;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_y = c10_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c10_b_is_active_c10_wabs_perceptionmodel_VPT_Limbic_v3_adj), &c10_thisId);
  sf_mex_destroy(&c10_b_is_active_c10_wabs_perceptionmodel_VPT_Limbic_v3_adj);
  return c10_y;
}

static uint8_T c10_f_emlrt_marshallIn
  (SFc10_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance,
   const mxArray *c10_b_u, const emlrtMsgIdentifier *c10_parentId)
{
  uint8_T c10_y;
  uint8_T c10_u0;
  (void)chartInstance;
  sf_mex_import(c10_parentId, sf_mex_dup(c10_b_u), &c10_u0, 1, 3, 0U, 0, 0U, 0);
  c10_y = c10_u0;
  sf_mex_destroy(&c10_b_u);
  return c10_y;
}

static void init_dsm_address_info
  (SFc10_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address
  (SFc10_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance)
{
  chartInstance->c10_u = (real_T (*)[3])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c10_S = (real_T (*)[9])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

void sf_c10_wabs_perceptionmodel_VPT_Limbic_v3_adj_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2515051011U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2162698323U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1835436160U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3864118904U);
}

mxArray* sf_c10_wabs_perceptionmodel_VPT_Limbic_v3_adj_get_post_codegen_info
  (void);
mxArray *sf_c10_wabs_perceptionmodel_VPT_Limbic_v3_adj_get_autoinheritance_info
  (void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("NLRmqbrti0AXoMtSp9h7UC");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(3);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo =
      sf_c10_wabs_perceptionmodel_VPT_Limbic_v3_adj_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c10_wabs_perceptionmodel_VPT_Limbic_v3_adj_third_party_uses_info
  (void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c10_wabs_perceptionmodel_VPT_Limbic_v3_adj_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "incompatibleSymbol", };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 3, infoFields);
  mxArray *fallbackReason = mxCreateString("feature_off");
  mxArray *incompatibleSymbol = mxCreateString("");
  mxArray *fallbackType = mxCreateString("early");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c10_wabs_perceptionmodel_VPT_Limbic_v3_adj_updateBuildInfo_args_info
  (void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c10_wabs_perceptionmodel_VPT_Limbic_v3_adj_get_post_codegen_info
  (void)
{
  const char* fieldNames[] = { "exportedFunctionsUsedByThisChart",
    "exportedFunctionsChecksum" };

  mwSize dims[2] = { 1, 1 };

  mxArray* mxPostCodegenInfo = mxCreateStructArray(2, dims, sizeof(fieldNames)/
    sizeof(fieldNames[0]), fieldNames);

  {
    mxArray* mxExportedFunctionsChecksum = mxCreateString("");
    mwSize exp_dims[2] = { 0, 1 };

    mxArray* mxExportedFunctionsUsedByThisChart = mxCreateCellArray(2, exp_dims);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsUsedByThisChart",
               mxExportedFunctionsUsedByThisChart);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsChecksum",
               mxExportedFunctionsChecksum);
  }

  return mxPostCodegenInfo;
}

static const mxArray
  *sf_get_sim_state_info_c10_wabs_perceptionmodel_VPT_Limbic_v3_adj(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"S\",},{M[8],M[0],T\"is_active_c10_wabs_perceptionmodel_VPT_Limbic_v3_adj\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c10_wabs_perceptionmodel_VPT_Limbic_v3_adj_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc10_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc10_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _wabs_perceptionmodel_VPT_Limbic_v3_adjMachineNumber_,
           10,
           1,
           1,
           0,
           2,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize its own list of scripts */
        init_script_number_translation
          (_wabs_perceptionmodel_VPT_Limbic_v3_adjMachineNumber_,
           chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,
             _wabs_perceptionmodel_VPT_Limbic_v3_adjMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _wabs_perceptionmodel_VPT_Limbic_v3_adjMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"u");
          _SFD_SET_DATA_PROPS(1,2,0,1,"S");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,78);

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c10_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c10_sf_marshallOut,(MexInFcnForType)
            c10_sf_marshallIn);
        }

        _SFD_SET_DATA_VALUE_PTR(0U, *chartInstance->c10_u);
        _SFD_SET_DATA_VALUE_PTR(1U, *chartInstance->c10_S);
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _wabs_perceptionmodel_VPT_Limbic_v3_adjMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "ZXTfsdHcXkwGFg0RK1euE";
}

static void sf_opaque_initialize_c10_wabs_perceptionmodel_VPT_Limbic_v3_adj(void
  *chartInstanceVar)
{
  chart_debug_initialization
    (((SFc10_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct*)
      chartInstanceVar)->S,0);
  initialize_params_c10_wabs_perceptionmodel_VPT_Limbic_v3_adj
    ((SFc10_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct*)
     chartInstanceVar);
  initialize_c10_wabs_perceptionmodel_VPT_Limbic_v3_adj
    ((SFc10_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct*)
     chartInstanceVar);
}

static void sf_opaque_enable_c10_wabs_perceptionmodel_VPT_Limbic_v3_adj(void
  *chartInstanceVar)
{
  enable_c10_wabs_perceptionmodel_VPT_Limbic_v3_adj
    ((SFc10_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct*)
     chartInstanceVar);
}

static void sf_opaque_disable_c10_wabs_perceptionmodel_VPT_Limbic_v3_adj(void
  *chartInstanceVar)
{
  disable_c10_wabs_perceptionmodel_VPT_Limbic_v3_adj
    ((SFc10_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct*)
     chartInstanceVar);
}

static void sf_opaque_gateway_c10_wabs_perceptionmodel_VPT_Limbic_v3_adj(void
  *chartInstanceVar)
{
  sf_gateway_c10_wabs_perceptionmodel_VPT_Limbic_v3_adj
    ((SFc10_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct*)
     chartInstanceVar);
}

static const mxArray*
  sf_opaque_get_sim_state_c10_wabs_perceptionmodel_VPT_Limbic_v3_adj(SimStruct*
  S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c10_wabs_perceptionmodel_VPT_Limbic_v3_adj
    ((SFc10_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct*)
     chartInfo->chartInstance);        /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c10_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SimStruct* S, const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c10_wabs_perceptionmodel_VPT_Limbic_v3_adj
    ((SFc10_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct*)
     chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c10_wabs_perceptionmodel_VPT_Limbic_v3_adj(void *
  chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc10_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct*)
                    chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_wabs_perceptionmodel_VPT_Limbic_v3_adj_optimization_info();
    }

    finalize_c10_wabs_perceptionmodel_VPT_Limbic_v3_adj
      ((SFc10_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct*)
       chartInstanceVar);
    utFree(chartInstanceVar);
    if (crtInfo != NULL) {
      utFree(crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc10_wabs_perceptionmodel_VPT_Limbic_v3_adj
    ((SFc10_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct*)
     chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c10_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    initialize_params_c10_wabs_perceptionmodel_VPT_Limbic_v3_adj
      ((SFc10_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct*)
       (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c10_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct =
      load_wabs_perceptionmodel_VPT_Limbic_v3_adj_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      10);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,10,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,10,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,10);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,10,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,10,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 1; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,10);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(366001214U));
  ssSetChecksum1(S,(2614464859U));
  ssSetChecksum2(S,(2301411009U));
  ssSetChecksum3(S,(928166768U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c10_wabs_perceptionmodel_VPT_Limbic_v3_adj(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c10_wabs_perceptionmodel_VPT_Limbic_v3_adj(SimStruct *S)
{
  SFc10_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc10_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *)
    utMalloc(sizeof(SFc10_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct));
  memset(chartInstance, 0, sizeof
         (SFc10_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c10_wabs_perceptionmodel_VPT_Limbic_v3_adj;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c10_wabs_perceptionmodel_VPT_Limbic_v3_adj;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c10_wabs_perceptionmodel_VPT_Limbic_v3_adj;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c10_wabs_perceptionmodel_VPT_Limbic_v3_adj;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c10_wabs_perceptionmodel_VPT_Limbic_v3_adj;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c10_wabs_perceptionmodel_VPT_Limbic_v3_adj;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c10_wabs_perceptionmodel_VPT_Limbic_v3_adj;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c10_wabs_perceptionmodel_VPT_Limbic_v3_adj;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW =
    mdlRTW_c10_wabs_perceptionmodel_VPT_Limbic_v3_adj;
  chartInstance->chartInfo.mdlStart =
    mdlStart_c10_wabs_perceptionmodel_VPT_Limbic_v3_adj;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c10_wabs_perceptionmodel_VPT_Limbic_v3_adj;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.callAtomicSubchartUserFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartAutoFcn = NULL;
  chartInstance->chartInfo.debugInstance = sfGlobalDebugInstanceStruct;
  chartInstance->S = S;
  crtInfo->checksum = SF_RUNTIME_INFO_CHECKSUM;
  crtInfo->instanceInfo = (&(chartInstance->chartInfo));
  crtInfo->isJITEnabled = false;
  crtInfo->compiledInfo = NULL;
  ssSetUserData(S,(void *)(crtInfo));  /* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c10_wabs_perceptionmodel_VPT_Limbic_v3_adj_method_dispatcher(SimStruct *S,
  int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c10_wabs_perceptionmodel_VPT_Limbic_v3_adj(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c10_wabs_perceptionmodel_VPT_Limbic_v3_adj(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c10_wabs_perceptionmodel_VPT_Limbic_v3_adj(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c10_wabs_perceptionmodel_VPT_Limbic_v3_adj_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
