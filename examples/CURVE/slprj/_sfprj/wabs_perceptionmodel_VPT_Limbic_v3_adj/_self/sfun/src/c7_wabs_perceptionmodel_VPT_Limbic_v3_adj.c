/* Include files */

#include <stddef.h>
#include "blas.h"
#include "wabs_perceptionmodel_VPT_Limbic_v3_adj_sfun.h"
#include "c7_wabs_perceptionmodel_VPT_Limbic_v3_adj.h"
#include "mwmathutil.h"
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
static const char * c7_debug_family_names[4] = { "nargin", "nargout", "Rot",
  "Eul" };

/* Function Declarations */
static void initialize_c7_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SFc7_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance);
static void initialize_params_c7_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SFc7_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance);
static void enable_c7_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SFc7_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance);
static void disable_c7_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SFc7_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance);
static void c7_update_debugger_state_c7_wabs_perceptionmodel_VPT_Limbic_v3_a
  (SFc7_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c7_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SFc7_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance);
static void set_sim_state_c7_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SFc7_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance,
   const mxArray *c7_st);
static void finalize_c7_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SFc7_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance);
static void sf_gateway_c7_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SFc7_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance);
static void mdl_start_c7_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SFc7_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance);
static void initSimStructsc7_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SFc7_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c7_machineNumber, uint32_T
  c7_chartNumber, uint32_T c7_instanceNumber);
static const mxArray *c7_sf_marshallOut(void *chartInstanceVoid, void *c7_inData);
static void c7_emlrt_marshallIn
  (SFc7_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance,
   const mxArray *c7_b_Eul, const char_T *c7_identifier, real_T c7_y[3]);
static void c7_b_emlrt_marshallIn
  (SFc7_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance,
   const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId, real_T c7_y[3]);
static void c7_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData);
static const mxArray *c7_b_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static const mxArray *c7_c_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static real_T c7_c_emlrt_marshallIn
  (SFc7_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance,
   const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId);
static void c7_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData);
static void c7_info_helper(const mxArray **c7_info);
static const mxArray *c7_emlrt_marshallOut(const char * c7_u);
static const mxArray *c7_b_emlrt_marshallOut(const uint32_T c7_u);
static real_T c7_atan2(SFc7_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct
  *chartInstance, real_T c7_y, real_T c7_x);
static void c7_eml_scalar_eg
  (SFc7_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance);
static real_T c7_mpower
  (SFc7_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance,
   real_T c7_a);
static void c7_eml_error
  (SFc7_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance);
static const mxArray *c7_d_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static int32_T c7_d_emlrt_marshallIn
  (SFc7_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance,
   const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId);
static void c7_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData);
static uint8_T c7_e_emlrt_marshallIn
  (SFc7_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance,
   const mxArray *c7_b_is_active_c7_wabs_perceptionmodel_VPT_Limbic_v3_adj,
   const char_T *c7_identifier);
static uint8_T c7_f_emlrt_marshallIn
  (SFc7_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance,
   const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId);
static void init_dsm_address_info
  (SFc7_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance);
static void init_simulink_io_address
  (SFc7_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c7_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SFc7_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance)
{
  chartInstance->c7_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c7_is_active_c7_wabs_perceptionmodel_VPT_Limbic_v3_adj = 0U;
}

static void initialize_params_c7_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SFc7_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c7_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SFc7_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c7_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SFc7_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c7_update_debugger_state_c7_wabs_perceptionmodel_VPT_Limbic_v3_a
  (SFc7_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c7_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SFc7_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance)
{
  const mxArray *c7_st;
  const mxArray *c7_y = NULL;
  int32_T c7_i0;
  real_T c7_u[3];
  const mxArray *c7_b_y = NULL;
  uint8_T c7_hoistedGlobal;
  uint8_T c7_b_u;
  const mxArray *c7_c_y = NULL;
  c7_st = NULL;
  c7_st = NULL;
  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_createcellmatrix(2, 1), false);
  for (c7_i0 = 0; c7_i0 < 3; c7_i0++) {
    c7_u[c7_i0] = (*chartInstance->c7_Eul)[c7_i0];
  }

  c7_b_y = NULL;
  sf_mex_assign(&c7_b_y, sf_mex_create("y", c7_u, 0, 0U, 1U, 0U, 1, 3), false);
  sf_mex_setcell(c7_y, 0, c7_b_y);
  c7_hoistedGlobal =
    chartInstance->c7_is_active_c7_wabs_perceptionmodel_VPT_Limbic_v3_adj;
  c7_b_u = c7_hoistedGlobal;
  c7_c_y = NULL;
  sf_mex_assign(&c7_c_y, sf_mex_create("y", &c7_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c7_y, 1, c7_c_y);
  sf_mex_assign(&c7_st, c7_y, false);
  return c7_st;
}

static void set_sim_state_c7_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SFc7_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance,
   const mxArray *c7_st)
{
  const mxArray *c7_u;
  real_T c7_dv0[3];
  int32_T c7_i1;
  chartInstance->c7_doneDoubleBufferReInit = true;
  c7_u = sf_mex_dup(c7_st);
  c7_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c7_u, 0)), "Eul",
                      c7_dv0);
  for (c7_i1 = 0; c7_i1 < 3; c7_i1++) {
    (*chartInstance->c7_Eul)[c7_i1] = c7_dv0[c7_i1];
  }

  chartInstance->c7_is_active_c7_wabs_perceptionmodel_VPT_Limbic_v3_adj =
    c7_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c7_u, 1)),
    "is_active_c7_wabs_perceptionmodel_VPT_Limbic_v3_adj");
  sf_mex_destroy(&c7_u);
  c7_update_debugger_state_c7_wabs_perceptionmodel_VPT_Limbic_v3_a(chartInstance);
  sf_mex_destroy(&c7_st);
}

static void finalize_c7_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SFc7_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c7_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SFc7_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance)
{
  int32_T c7_i2;
  real_T c7_b_Rot[9];
  uint32_T c7_debug_family_var_map[4];
  real_T c7_nargin = 1.0;
  real_T c7_nargout = 1.0;
  real_T c7_b_Eul[3];
  real_T c7_x;
  real_T c7_b_x;
  real_T c7_d0;
  real_T c7_d1;
  real_T c7_d2;
  int32_T c7_i3;
  int32_T c7_i4;
  int32_T c7_i5;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 6U, chartInstance->c7_sfEvent);
  chartInstance->c7_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 6U, chartInstance->c7_sfEvent);
  for (c7_i2 = 0; c7_i2 < 9; c7_i2++) {
    c7_b_Rot[c7_i2] = (*chartInstance->c7_Rot)[c7_i2];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 4U, c7_debug_family_names,
    c7_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargin, 0U, c7_c_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargout, 1U, c7_c_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c7_b_Rot, 2U, c7_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_b_Eul, 3U, c7_sf_marshallOut,
    c7_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 4);
  c7_x = c7_mpower(chartInstance, c7_b_Rot[5]) + c7_mpower(chartInstance,
    c7_b_Rot[8]);
  c7_b_x = c7_x;
  if (c7_b_x < 0.0) {
    c7_eml_error(chartInstance);
  }

  c7_b_x = muDoubleScalarSqrt(c7_b_x);
  c7_d0 = c7_atan2(chartInstance, c7_b_Rot[5], c7_b_Rot[8]);
  c7_d1 = c7_atan2(chartInstance, -c7_b_Rot[2], c7_b_x);
  c7_d2 = c7_atan2(chartInstance, c7_b_Rot[1], c7_b_Rot[0]);
  c7_b_Eul[0] = c7_d0;
  c7_b_Eul[1] = c7_d1;
  c7_b_Eul[2] = c7_d2;
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, -4);
  _SFD_SYMBOL_SCOPE_POP();
  for (c7_i3 = 0; c7_i3 < 3; c7_i3++) {
    (*chartInstance->c7_Eul)[c7_i3] = c7_b_Eul[c7_i3];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, chartInstance->c7_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY
    (_wabs_perceptionmodel_VPT_Limbic_v3_adjMachineNumber_,
     chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c7_i4 = 0; c7_i4 < 3; c7_i4++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c7_Eul)[c7_i4], 0U);
  }

  for (c7_i5 = 0; c7_i5 < 9; c7_i5++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c7_Rot)[c7_i5], 1U);
  }
}

static void mdl_start_c7_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SFc7_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void initSimStructsc7_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SFc7_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c7_machineNumber, uint32_T
  c7_chartNumber, uint32_T c7_instanceNumber)
{
  (void)c7_machineNumber;
  (void)c7_chartNumber;
  (void)c7_instanceNumber;
}

static const mxArray *c7_sf_marshallOut(void *chartInstanceVoid, void *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_i6;
  real_T c7_b_inData[3];
  int32_T c7_i7;
  real_T c7_u[3];
  const mxArray *c7_y = NULL;
  SFc7_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance;
  chartInstance = (SFc7_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *)
    chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  for (c7_i6 = 0; c7_i6 < 3; c7_i6++) {
    c7_b_inData[c7_i6] = (*(real_T (*)[3])c7_inData)[c7_i6];
  }

  for (c7_i7 = 0; c7_i7 < 3; c7_i7++) {
    c7_u[c7_i7] = c7_b_inData[c7_i7];
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 0, 0U, 1U, 0U, 1, 3), false);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static void c7_emlrt_marshallIn
  (SFc7_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance,
   const mxArray *c7_b_Eul, const char_T *c7_identifier, real_T c7_y[3])
{
  emlrtMsgIdentifier c7_thisId;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_b_Eul), &c7_thisId, c7_y);
  sf_mex_destroy(&c7_b_Eul);
}

static void c7_b_emlrt_marshallIn
  (SFc7_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance,
   const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId, real_T c7_y[3])
{
  real_T c7_dv1[3];
  int32_T c7_i8;
  (void)chartInstance;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_u), c7_dv1, 1, 0, 0U, 1, 0U, 1, 3);
  for (c7_i8 = 0; c7_i8 < 3; c7_i8++) {
    c7_y[c7_i8] = c7_dv1[c7_i8];
  }

  sf_mex_destroy(&c7_u);
}

static void c7_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData)
{
  const mxArray *c7_b_Eul;
  const char_T *c7_identifier;
  emlrtMsgIdentifier c7_thisId;
  real_T c7_y[3];
  int32_T c7_i9;
  SFc7_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance;
  chartInstance = (SFc7_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *)
    chartInstanceVoid;
  c7_b_Eul = sf_mex_dup(c7_mxArrayInData);
  c7_identifier = c7_varName;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_b_Eul), &c7_thisId, c7_y);
  sf_mex_destroy(&c7_b_Eul);
  for (c7_i9 = 0; c7_i9 < 3; c7_i9++) {
    (*(real_T (*)[3])c7_outData)[c7_i9] = c7_y[c7_i9];
  }

  sf_mex_destroy(&c7_mxArrayInData);
}

static const mxArray *c7_b_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_i10;
  int32_T c7_i11;
  int32_T c7_i12;
  real_T c7_b_inData[9];
  int32_T c7_i13;
  int32_T c7_i14;
  int32_T c7_i15;
  real_T c7_u[9];
  const mxArray *c7_y = NULL;
  SFc7_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance;
  chartInstance = (SFc7_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *)
    chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  c7_i10 = 0;
  for (c7_i11 = 0; c7_i11 < 3; c7_i11++) {
    for (c7_i12 = 0; c7_i12 < 3; c7_i12++) {
      c7_b_inData[c7_i12 + c7_i10] = (*(real_T (*)[9])c7_inData)[c7_i12 + c7_i10];
    }

    c7_i10 += 3;
  }

  c7_i13 = 0;
  for (c7_i14 = 0; c7_i14 < 3; c7_i14++) {
    for (c7_i15 = 0; c7_i15 < 3; c7_i15++) {
      c7_u[c7_i15 + c7_i13] = c7_b_inData[c7_i15 + c7_i13];
    }

    c7_i13 += 3;
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 0, 0U, 1U, 0U, 2, 3, 3), false);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static const mxArray *c7_c_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  real_T c7_u;
  const mxArray *c7_y = NULL;
  SFc7_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance;
  chartInstance = (SFc7_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *)
    chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  c7_u = *(real_T *)c7_inData;
  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", &c7_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static real_T c7_c_emlrt_marshallIn
  (SFc7_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance,
   const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId)
{
  real_T c7_y;
  real_T c7_d3;
  (void)chartInstance;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_u), &c7_d3, 1, 0, 0U, 0, 0U, 0);
  c7_y = c7_d3;
  sf_mex_destroy(&c7_u);
  return c7_y;
}

static void c7_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData)
{
  const mxArray *c7_nargout;
  const char_T *c7_identifier;
  emlrtMsgIdentifier c7_thisId;
  real_T c7_y;
  SFc7_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance;
  chartInstance = (SFc7_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *)
    chartInstanceVoid;
  c7_nargout = sf_mex_dup(c7_mxArrayInData);
  c7_identifier = c7_varName;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_y = c7_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_nargout), &c7_thisId);
  sf_mex_destroy(&c7_nargout);
  *(real_T *)c7_outData = c7_y;
  sf_mex_destroy(&c7_mxArrayInData);
}

const mxArray
  *sf_c7_wabs_perceptionmodel_VPT_Limbic_v3_adj_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c7_nameCaptureInfo = NULL;
  c7_nameCaptureInfo = NULL;
  sf_mex_assign(&c7_nameCaptureInfo, sf_mex_createstruct("structure", 2, 20, 1),
                false);
  c7_info_helper(&c7_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c7_nameCaptureInfo);
  return c7_nameCaptureInfo;
}

static void c7_info_helper(const mxArray **c7_info)
{
  const mxArray *c7_rhs0 = NULL;
  const mxArray *c7_lhs0 = NULL;
  const mxArray *c7_rhs1 = NULL;
  const mxArray *c7_lhs1 = NULL;
  const mxArray *c7_rhs2 = NULL;
  const mxArray *c7_lhs2 = NULL;
  const mxArray *c7_rhs3 = NULL;
  const mxArray *c7_lhs3 = NULL;
  const mxArray *c7_rhs4 = NULL;
  const mxArray *c7_lhs4 = NULL;
  const mxArray *c7_rhs5 = NULL;
  const mxArray *c7_lhs5 = NULL;
  const mxArray *c7_rhs6 = NULL;
  const mxArray *c7_lhs6 = NULL;
  const mxArray *c7_rhs7 = NULL;
  const mxArray *c7_lhs7 = NULL;
  const mxArray *c7_rhs8 = NULL;
  const mxArray *c7_lhs8 = NULL;
  const mxArray *c7_rhs9 = NULL;
  const mxArray *c7_lhs9 = NULL;
  const mxArray *c7_rhs10 = NULL;
  const mxArray *c7_lhs10 = NULL;
  const mxArray *c7_rhs11 = NULL;
  const mxArray *c7_lhs11 = NULL;
  const mxArray *c7_rhs12 = NULL;
  const mxArray *c7_lhs12 = NULL;
  const mxArray *c7_rhs13 = NULL;
  const mxArray *c7_lhs13 = NULL;
  const mxArray *c7_rhs14 = NULL;
  const mxArray *c7_lhs14 = NULL;
  const mxArray *c7_rhs15 = NULL;
  const mxArray *c7_lhs15 = NULL;
  const mxArray *c7_rhs16 = NULL;
  const mxArray *c7_lhs16 = NULL;
  const mxArray *c7_rhs17 = NULL;
  const mxArray *c7_lhs17 = NULL;
  const mxArray *c7_rhs18 = NULL;
  const mxArray *c7_lhs18 = NULL;
  const mxArray *c7_rhs19 = NULL;
  const mxArray *c7_lhs19 = NULL;
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("atan2"), "name", "name", 0);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan2.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1395328496U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c7_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs0), "rhs", "rhs", 0);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs0), "lhs", "lhs", 0);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan2.m"), "context",
                  "context", 1);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 1);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 1);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1375980688U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c7_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs1), "rhs", "rhs", 1);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs1), "lhs", "lhs", 1);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 2);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 2);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1410807770U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c7_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs2), "rhs", "rhs", 2);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs2), "lhs", "lhs", 2);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan2.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 3);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1375980688U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c7_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs3), "rhs", "rhs", 3);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs3), "lhs", "lhs", 3);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "context", "context", 4);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("coder.internal.scalexpAlloc"),
                  "name", "name", 4);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalexpAlloc.p"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1410807770U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c7_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs4), "rhs", "rhs", 4);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs4), "lhs", "lhs", 4);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan2.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("eml_scalar_atan2"), "name",
                  "name", 5);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_atan2.m"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1286818720U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c7_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs5), "rhs", "rhs", 5);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs5), "lhs", "lhs", 5);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(""), "context", "context", 6);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("mpower"), "name", "name", 6);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "resolved",
                  "resolved", 6);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1363713878U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c7_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs6), "rhs", "rhs", 6);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs6), "lhs", "lhs", 6);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 7);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 7);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1395931856U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c7_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs7), "rhs", "rhs", 7);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs7), "lhs", "lhs", 7);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 8);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("ismatrix"), "name", "name", 8);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/ismatrix.m"), "resolved",
                  "resolved", 8);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1331304858U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c7_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs8), "rhs", "rhs", 8);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs8), "lhs", "lhs", 8);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 9);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("power"), "name", "name", 9);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m"), "resolved",
                  "resolved", 9);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1395328506U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c7_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs9), "rhs", "rhs", 9);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs9), "lhs", "lhs", 9);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m"), "context",
                  "context", 10);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 10);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1395931856U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c7_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 11);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 11);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 11);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1375980688U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c7_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 12);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 12);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 12);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1375980688U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c7_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 13);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("floor"), "name", "name", 13);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 13);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1363713854U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c7_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 14);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 14);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 14);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1395931856U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c7_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 15);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("eml_scalar_floor"), "name",
                  "name", 15);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m"),
                  "resolved", "resolved", 15);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1286818726U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c7_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!scalar_float_power"),
                  "context", "context", 16);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 16);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 16);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1375980688U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c7_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(""), "context", "context", 17);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("sqrt"), "name", "name", 17);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m"), "resolved",
                  "resolved", 17);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1343830386U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c7_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m"), "context",
                  "context", 18);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("eml_error"), "name", "name",
                  18);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m"), "resolved",
                  "resolved", 18);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1343830358U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c7_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m"), "context",
                  "context", 19);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("eml_scalar_sqrt"), "name",
                  "name", 19);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c7_info, c7_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m"),
                  "resolved", "resolved", 19);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(1286818738U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c7_info, c7_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c7_rhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c7_lhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c7_info, sf_mex_duplicatearraysafe(&c7_lhs19), "lhs", "lhs",
                  19);
  sf_mex_destroy(&c7_rhs0);
  sf_mex_destroy(&c7_lhs0);
  sf_mex_destroy(&c7_rhs1);
  sf_mex_destroy(&c7_lhs1);
  sf_mex_destroy(&c7_rhs2);
  sf_mex_destroy(&c7_lhs2);
  sf_mex_destroy(&c7_rhs3);
  sf_mex_destroy(&c7_lhs3);
  sf_mex_destroy(&c7_rhs4);
  sf_mex_destroy(&c7_lhs4);
  sf_mex_destroy(&c7_rhs5);
  sf_mex_destroy(&c7_lhs5);
  sf_mex_destroy(&c7_rhs6);
  sf_mex_destroy(&c7_lhs6);
  sf_mex_destroy(&c7_rhs7);
  sf_mex_destroy(&c7_lhs7);
  sf_mex_destroy(&c7_rhs8);
  sf_mex_destroy(&c7_lhs8);
  sf_mex_destroy(&c7_rhs9);
  sf_mex_destroy(&c7_lhs9);
  sf_mex_destroy(&c7_rhs10);
  sf_mex_destroy(&c7_lhs10);
  sf_mex_destroy(&c7_rhs11);
  sf_mex_destroy(&c7_lhs11);
  sf_mex_destroy(&c7_rhs12);
  sf_mex_destroy(&c7_lhs12);
  sf_mex_destroy(&c7_rhs13);
  sf_mex_destroy(&c7_lhs13);
  sf_mex_destroy(&c7_rhs14);
  sf_mex_destroy(&c7_lhs14);
  sf_mex_destroy(&c7_rhs15);
  sf_mex_destroy(&c7_lhs15);
  sf_mex_destroy(&c7_rhs16);
  sf_mex_destroy(&c7_lhs16);
  sf_mex_destroy(&c7_rhs17);
  sf_mex_destroy(&c7_lhs17);
  sf_mex_destroy(&c7_rhs18);
  sf_mex_destroy(&c7_lhs18);
  sf_mex_destroy(&c7_rhs19);
  sf_mex_destroy(&c7_lhs19);
}

static const mxArray *c7_emlrt_marshallOut(const char * c7_u)
{
  const mxArray *c7_y = NULL;
  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c7_u)), false);
  return c7_y;
}

static const mxArray *c7_b_emlrt_marshallOut(const uint32_T c7_u)
{
  const mxArray *c7_y = NULL;
  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", &c7_u, 7, 0U, 0U, 0U, 0), false);
  return c7_y;
}

static real_T c7_atan2(SFc7_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct
  *chartInstance, real_T c7_y, real_T c7_x)
{
  real_T c7_b_y;
  real_T c7_b_x;
  c7_eml_scalar_eg(chartInstance);
  c7_b_y = c7_y;
  c7_b_x = c7_x;
  return muDoubleScalarAtan2(c7_b_y, c7_b_x);
}

static void c7_eml_scalar_eg
  (SFc7_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static real_T c7_mpower
  (SFc7_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance,
   real_T c7_a)
{
  real_T c7_b_a;
  real_T c7_c_a;
  real_T c7_ak;
  real_T c7_d_a;
  c7_b_a = c7_a;
  c7_c_a = c7_b_a;
  c7_eml_scalar_eg(chartInstance);
  c7_ak = c7_c_a;
  c7_d_a = c7_ak;
  c7_eml_scalar_eg(chartInstance);
  return c7_d_a * c7_d_a;
}

static void c7_eml_error
  (SFc7_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance)
{
  int32_T c7_i16;
  static char_T c7_cv0[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'E', 'l', 'F', 'u', 'n', 'D', 'o', 'm', 'a', 'i', 'n',
    'E', 'r', 'r', 'o', 'r' };

  char_T c7_u[30];
  const mxArray *c7_y = NULL;
  int32_T c7_i17;
  static char_T c7_cv1[4] = { 's', 'q', 'r', 't' };

  char_T c7_b_u[4];
  const mxArray *c7_b_y = NULL;
  (void)chartInstance;
  for (c7_i16 = 0; c7_i16 < 30; c7_i16++) {
    c7_u[c7_i16] = c7_cv0[c7_i16];
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 10, 0U, 1U, 0U, 2, 1, 30), false);
  for (c7_i17 = 0; c7_i17 < 4; c7_i17++) {
    c7_b_u[c7_i17] = c7_cv1[c7_i17];
  }

  c7_b_y = NULL;
  sf_mex_assign(&c7_b_y, sf_mex_create("y", c7_b_u, 10, 0U, 1U, 0U, 2, 1, 4),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    2U, 14, c7_y, 14, c7_b_y));
}

static const mxArray *c7_d_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_u;
  const mxArray *c7_y = NULL;
  SFc7_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance;
  chartInstance = (SFc7_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *)
    chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  c7_u = *(int32_T *)c7_inData;
  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", &c7_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static int32_T c7_d_emlrt_marshallIn
  (SFc7_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance,
   const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId)
{
  int32_T c7_y;
  int32_T c7_i18;
  (void)chartInstance;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_u), &c7_i18, 1, 6, 0U, 0, 0U, 0);
  c7_y = c7_i18;
  sf_mex_destroy(&c7_u);
  return c7_y;
}

static void c7_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData)
{
  const mxArray *c7_b_sfEvent;
  const char_T *c7_identifier;
  emlrtMsgIdentifier c7_thisId;
  int32_T c7_y;
  SFc7_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance;
  chartInstance = (SFc7_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *)
    chartInstanceVoid;
  c7_b_sfEvent = sf_mex_dup(c7_mxArrayInData);
  c7_identifier = c7_varName;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_y = c7_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_b_sfEvent),
    &c7_thisId);
  sf_mex_destroy(&c7_b_sfEvent);
  *(int32_T *)c7_outData = c7_y;
  sf_mex_destroy(&c7_mxArrayInData);
}

static uint8_T c7_e_emlrt_marshallIn
  (SFc7_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance,
   const mxArray *c7_b_is_active_c7_wabs_perceptionmodel_VPT_Limbic_v3_adj,
   const char_T *c7_identifier)
{
  uint8_T c7_y;
  emlrtMsgIdentifier c7_thisId;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_y = c7_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c7_b_is_active_c7_wabs_perceptionmodel_VPT_Limbic_v3_adj), &c7_thisId);
  sf_mex_destroy(&c7_b_is_active_c7_wabs_perceptionmodel_VPT_Limbic_v3_adj);
  return c7_y;
}

static uint8_T c7_f_emlrt_marshallIn
  (SFc7_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance,
   const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId)
{
  uint8_T c7_y;
  uint8_T c7_u0;
  (void)chartInstance;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_u), &c7_u0, 1, 3, 0U, 0, 0U, 0);
  c7_y = c7_u0;
  sf_mex_destroy(&c7_u);
  return c7_y;
}

static void init_dsm_address_info
  (SFc7_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address
  (SFc7_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance)
{
  chartInstance->c7_Eul = (real_T (*)[3])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c7_Rot = (real_T (*)[9])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
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

void sf_c7_wabs_perceptionmodel_VPT_Limbic_v3_adj_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(147790535U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2456967462U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2259973372U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2971053914U);
}

mxArray* sf_c7_wabs_perceptionmodel_VPT_Limbic_v3_adj_get_post_codegen_info(void);
mxArray *sf_c7_wabs_perceptionmodel_VPT_Limbic_v3_adj_get_autoinheritance_info
  (void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("leyVQmadPOFqJtNlmZWDjB");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo =
      sf_c7_wabs_perceptionmodel_VPT_Limbic_v3_adj_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c7_wabs_perceptionmodel_VPT_Limbic_v3_adj_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c7_wabs_perceptionmodel_VPT_Limbic_v3_adj_jit_fallback_info(void)
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

mxArray *sf_c7_wabs_perceptionmodel_VPT_Limbic_v3_adj_updateBuildInfo_args_info
  (void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c7_wabs_perceptionmodel_VPT_Limbic_v3_adj_get_post_codegen_info(void)
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
  *sf_get_sim_state_info_c7_wabs_perceptionmodel_VPT_Limbic_v3_adj(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[6],T\"Eul\",},{M[8],M[0],T\"is_active_c7_wabs_perceptionmodel_VPT_Limbic_v3_adj\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c7_wabs_perceptionmodel_VPT_Limbic_v3_adj_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc7_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc7_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _wabs_perceptionmodel_VPT_Limbic_v3_adjMachineNumber_,
           7,
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
          _SFD_SET_DATA_PROPS(0,2,0,1,"Eul");
          _SFD_SET_DATA_PROPS(1,1,1,0,"Rot");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,259);

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c7_sf_marshallOut,(MexInFcnForType)
            c7_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c7_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_VALUE_PTR(0U, *chartInstance->c7_Eul);
        _SFD_SET_DATA_VALUE_PTR(1U, *chartInstance->c7_Rot);
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
  return "MDvDYPHel0JR5LB3X1tAKF";
}

static void sf_opaque_initialize_c7_wabs_perceptionmodel_VPT_Limbic_v3_adj(void *
  chartInstanceVar)
{
  chart_debug_initialization
    (((SFc7_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct*)
      chartInstanceVar)->S,0);
  initialize_params_c7_wabs_perceptionmodel_VPT_Limbic_v3_adj
    ((SFc7_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct*)
     chartInstanceVar);
  initialize_c7_wabs_perceptionmodel_VPT_Limbic_v3_adj
    ((SFc7_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct*)
     chartInstanceVar);
}

static void sf_opaque_enable_c7_wabs_perceptionmodel_VPT_Limbic_v3_adj(void
  *chartInstanceVar)
{
  enable_c7_wabs_perceptionmodel_VPT_Limbic_v3_adj
    ((SFc7_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct*)
     chartInstanceVar);
}

static void sf_opaque_disable_c7_wabs_perceptionmodel_VPT_Limbic_v3_adj(void
  *chartInstanceVar)
{
  disable_c7_wabs_perceptionmodel_VPT_Limbic_v3_adj
    ((SFc7_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct*)
     chartInstanceVar);
}

static void sf_opaque_gateway_c7_wabs_perceptionmodel_VPT_Limbic_v3_adj(void
  *chartInstanceVar)
{
  sf_gateway_c7_wabs_perceptionmodel_VPT_Limbic_v3_adj
    ((SFc7_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct*)
     chartInstanceVar);
}

static const mxArray*
  sf_opaque_get_sim_state_c7_wabs_perceptionmodel_VPT_Limbic_v3_adj(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c7_wabs_perceptionmodel_VPT_Limbic_v3_adj
    ((SFc7_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct*)
     chartInfo->chartInstance);        /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c7_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SimStruct* S, const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c7_wabs_perceptionmodel_VPT_Limbic_v3_adj
    ((SFc7_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct*)
     chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c7_wabs_perceptionmodel_VPT_Limbic_v3_adj(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc7_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct*)
                    chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_wabs_perceptionmodel_VPT_Limbic_v3_adj_optimization_info();
    }

    finalize_c7_wabs_perceptionmodel_VPT_Limbic_v3_adj
      ((SFc7_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct*)
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
  initSimStructsc7_wabs_perceptionmodel_VPT_Limbic_v3_adj
    ((SFc7_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct*)
     chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c7_wabs_perceptionmodel_VPT_Limbic_v3_adj
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
    initialize_params_c7_wabs_perceptionmodel_VPT_Limbic_v3_adj
      ((SFc7_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct*)
       (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c7_wabs_perceptionmodel_VPT_Limbic_v3_adj(SimStruct
  *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct =
      load_wabs_perceptionmodel_VPT_Limbic_v3_adj_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,7);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,7,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,7,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,7);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,7,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,7,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,7);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(931425085U));
  ssSetChecksum1(S,(2163413892U));
  ssSetChecksum2(S,(4073019870U));
  ssSetChecksum3(S,(2859320622U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c7_wabs_perceptionmodel_VPT_Limbic_v3_adj(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c7_wabs_perceptionmodel_VPT_Limbic_v3_adj(SimStruct *S)
{
  SFc7_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc7_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *)
    utMalloc(sizeof(SFc7_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct));
  memset(chartInstance, 0, sizeof
         (SFc7_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c7_wabs_perceptionmodel_VPT_Limbic_v3_adj;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c7_wabs_perceptionmodel_VPT_Limbic_v3_adj;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c7_wabs_perceptionmodel_VPT_Limbic_v3_adj;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c7_wabs_perceptionmodel_VPT_Limbic_v3_adj;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c7_wabs_perceptionmodel_VPT_Limbic_v3_adj;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c7_wabs_perceptionmodel_VPT_Limbic_v3_adj;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c7_wabs_perceptionmodel_VPT_Limbic_v3_adj;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c7_wabs_perceptionmodel_VPT_Limbic_v3_adj;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW =
    mdlRTW_c7_wabs_perceptionmodel_VPT_Limbic_v3_adj;
  chartInstance->chartInfo.mdlStart =
    mdlStart_c7_wabs_perceptionmodel_VPT_Limbic_v3_adj;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c7_wabs_perceptionmodel_VPT_Limbic_v3_adj;
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

void c7_wabs_perceptionmodel_VPT_Limbic_v3_adj_method_dispatcher(SimStruct *S,
  int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c7_wabs_perceptionmodel_VPT_Limbic_v3_adj(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c7_wabs_perceptionmodel_VPT_Limbic_v3_adj(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c7_wabs_perceptionmodel_VPT_Limbic_v3_adj(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c7_wabs_perceptionmodel_VPT_Limbic_v3_adj_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
