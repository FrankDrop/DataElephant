/* Include files */

#include <stddef.h>
#include "blas.h"
#include "wabs_perceptionmodel_VPT_Limbic_v3_adj_sfun.h"
#include "c8_wabs_perceptionmodel_VPT_Limbic_v3_adj.h"
#include <math.h>
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
static const char * c8_debug_family_names[12] = { "epsilon", "n", "alpha", "idx",
  "I", "nx", "R", "nargin", "nargout", "v", "u", "Eul" };

static const char * c8_b_debug_family_names[4] = { "nargin", "nargout", "u", "S"
};

static const char * c8_c_debug_family_names[4] = { "nargin", "nargout", "Rot",
  "Eul" };

/* Function Declarations */
static void initialize_c8_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SFc8_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance);
static void initialize_params_c8_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SFc8_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance);
static void enable_c8_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SFc8_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance);
static void disable_c8_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SFc8_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance);
static void c8_update_debugger_state_c8_wabs_perceptionmodel_VPT_Limbic_v3_a
  (SFc8_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c8_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SFc8_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance);
static void set_sim_state_c8_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SFc8_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance,
   const mxArray *c8_st);
static void finalize_c8_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SFc8_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance);
static void sf_gateway_c8_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SFc8_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance);
static void mdl_start_c8_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SFc8_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance);
static void c8_chartstep_c8_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SFc8_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance);
static void initSimStructsc8_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SFc8_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c8_machineNumber, uint32_T
  c8_chartNumber, uint32_T c8_instanceNumber);
static const mxArray *c8_sf_marshallOut(void *chartInstanceVoid, void *c8_inData);
static void c8_emlrt_marshallIn
  (SFc8_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance,
   const mxArray *c8_b_Eul, const char_T *c8_identifier, real_T c8_y[3]);
static void c8_b_emlrt_marshallIn
  (SFc8_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance,
   const mxArray *c8_b_u, const emlrtMsgIdentifier *c8_parentId, real_T c8_y[3]);
static void c8_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData);
static const mxArray *c8_b_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static real_T c8_c_emlrt_marshallIn
  (SFc8_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance,
   const mxArray *c8_b_u, const emlrtMsgIdentifier *c8_parentId);
static void c8_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData);
static const mxArray *c8_c_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static void c8_d_emlrt_marshallIn
  (SFc8_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance,
   const mxArray *c8_b_u, const emlrtMsgIdentifier *c8_parentId, real_T c8_y[9]);
static void c8_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData);
static const mxArray *c8_d_sf_marshallOut(void *chartInstanceVoid, real_T
  c8_inData_data[], int32_T *c8_inData_sizes);
static void c8_e_emlrt_marshallIn
  (SFc8_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance,
   const mxArray *c8_b_u, const emlrtMsgIdentifier *c8_parentId, real_T
   c8_y_data[], int32_T *c8_y_sizes);
static void c8_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, real_T c8_outData_data[], int32_T
  *c8_outData_sizes);
static void c8_info_helper(const mxArray **c8_info);
static const mxArray *c8_emlrt_marshallOut(const char * c8_b_u);
static const mxArray *c8_b_emlrt_marshallOut(const uint32_T c8_b_u);
static void c8_b_info_helper(const mxArray **c8_info);
static void c8_c_info_helper(const mxArray **c8_info);
static real_T c8_rdivide
  (SFc8_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance,
   real_T c8_x, real_T c8_y);
static void c8_cross(SFc8_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct
                     *chartInstance, real_T c8_a[3], real_T c8_b[3], real_T
                     c8_c[3]);
static real_T c8_norm(SFc8_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *
                      chartInstance, real_T c8_x[3]);
static void c8_below_threshold
  (SFc8_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance);
static void c8_eml_switch_helper
  (SFc8_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance);
static real_T c8_dot(SFc8_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct
                     *chartInstance, real_T c8_a[3], real_T c8_b[3]);
static real_T c8_eml_xdotc
  (SFc8_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance,
   real_T c8_x[3], real_T c8_y[3]);
static real_T c8_acos(SFc8_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *
                      chartInstance, real_T c8_x);
static void c8_eml_error
  (SFc8_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance);
static void c8_eye(SFc8_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct
                   *chartInstance, real_T c8_I[9]);
static void c8_expm(SFc8_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct
                    *chartInstance, real_T c8_A[9], real_T c8_F[9]);
static void c8_PadeApproximantOfDegree
  (SFc8_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance,
   real_T c8_A[9], real_T c8_m, real_T c8_F[9]);
static void c8_eml_scalar_eg
  (SFc8_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance);
static void c8_eml_xgemm
  (SFc8_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance,
   real_T c8_A[9], real_T c8_B[9], real_T c8_C[9], real_T c8_b_C[9]);
static void c8_mldivide
  (SFc8_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance,
   real_T c8_A[9], real_T c8_B[9], real_T c8_Y[9]);
static void c8_eml_warning
  (SFc8_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance);
static void c8_b_eml_scalar_eg
  (SFc8_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance);
static real_T c8_atan2(SFc8_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct
  *chartInstance, real_T c8_y, real_T c8_x);
static real_T c8_mpower
  (SFc8_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance,
   real_T c8_a);
static void c8_b_eml_error
  (SFc8_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance);
static const mxArray *c8_e_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static int32_T c8_f_emlrt_marshallIn
  (SFc8_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance,
   const mxArray *c8_b_u, const emlrtMsgIdentifier *c8_parentId);
static void c8_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData);
static uint8_T c8_g_emlrt_marshallIn
  (SFc8_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance,
   const mxArray *c8_b_is_active_c8_wabs_perceptionmodel_VPT_Limbic_v3_adj,
   const char_T *c8_identifier);
static uint8_T c8_h_emlrt_marshallIn
  (SFc8_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance,
   const mxArray *c8_b_u, const emlrtMsgIdentifier *c8_parentId);
static void c8_b_acos(SFc8_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *
                      chartInstance, real_T *c8_x);
static void c8_b_eml_xgemm
  (SFc8_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance,
   real_T c8_A[9], real_T c8_B[9], real_T c8_C[9]);
static void init_dsm_address_info
  (SFc8_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance);
static void init_simulink_io_address
  (SFc8_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c8_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SFc8_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance)
{
  chartInstance->c8_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c8_is_active_c8_wabs_perceptionmodel_VPT_Limbic_v3_adj = 0U;
}

static void initialize_params_c8_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SFc8_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c8_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SFc8_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c8_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SFc8_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c8_update_debugger_state_c8_wabs_perceptionmodel_VPT_Limbic_v3_a
  (SFc8_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c8_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SFc8_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance)
{
  const mxArray *c8_st;
  const mxArray *c8_y = NULL;
  int32_T c8_i0;
  real_T c8_b_u[3];
  const mxArray *c8_b_y = NULL;
  uint8_T c8_hoistedGlobal;
  uint8_T c8_c_u;
  const mxArray *c8_c_y = NULL;
  c8_st = NULL;
  c8_st = NULL;
  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_createcellmatrix(2, 1), false);
  for (c8_i0 = 0; c8_i0 < 3; c8_i0++) {
    c8_b_u[c8_i0] = (*chartInstance->c8_Eul)[c8_i0];
  }

  c8_b_y = NULL;
  sf_mex_assign(&c8_b_y, sf_mex_create("y", c8_b_u, 0, 0U, 1U, 0U, 1, 3), false);
  sf_mex_setcell(c8_y, 0, c8_b_y);
  c8_hoistedGlobal =
    chartInstance->c8_is_active_c8_wabs_perceptionmodel_VPT_Limbic_v3_adj;
  c8_c_u = c8_hoistedGlobal;
  c8_c_y = NULL;
  sf_mex_assign(&c8_c_y, sf_mex_create("y", &c8_c_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c8_y, 1, c8_c_y);
  sf_mex_assign(&c8_st, c8_y, false);
  return c8_st;
}

static void set_sim_state_c8_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SFc8_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance,
   const mxArray *c8_st)
{
  const mxArray *c8_b_u;
  real_T c8_dv0[3];
  int32_T c8_i1;
  chartInstance->c8_doneDoubleBufferReInit = true;
  c8_b_u = sf_mex_dup(c8_st);
  c8_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c8_b_u, 0)),
                      "Eul", c8_dv0);
  for (c8_i1 = 0; c8_i1 < 3; c8_i1++) {
    (*chartInstance->c8_Eul)[c8_i1] = c8_dv0[c8_i1];
  }

  chartInstance->c8_is_active_c8_wabs_perceptionmodel_VPT_Limbic_v3_adj =
    c8_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c8_b_u, 1)),
    "is_active_c8_wabs_perceptionmodel_VPT_Limbic_v3_adj");
  sf_mex_destroy(&c8_b_u);
  c8_update_debugger_state_c8_wabs_perceptionmodel_VPT_Limbic_v3_a(chartInstance);
  sf_mex_destroy(&c8_st);
}

static void finalize_c8_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SFc8_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c8_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SFc8_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance)
{
  int32_T c8_i2;
  int32_T c8_i3;
  int32_T c8_i4;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 7U, chartInstance->c8_sfEvent);
  for (c8_i2 = 0; c8_i2 < 3; c8_i2++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c8_v)[c8_i2], 0U);
  }

  for (c8_i3 = 0; c8_i3 < 3; c8_i3++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c8_u)[c8_i3], 1U);
  }

  chartInstance->c8_sfEvent = CALL_EVENT;
  c8_chartstep_c8_wabs_perceptionmodel_VPT_Limbic_v3_adj(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY
    (_wabs_perceptionmodel_VPT_Limbic_v3_adjMachineNumber_,
     chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c8_i4 = 0; c8_i4 < 3; c8_i4++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c8_Eul)[c8_i4], 2U);
  }
}

static void mdl_start_c8_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SFc8_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c8_chartstep_c8_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SFc8_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance)
{
  int32_T c8_i5;
  real_T c8_b_v[3];
  int32_T c8_i6;
  real_T c8_b_u[3];
  uint32_T c8_debug_family_var_map[12];
  real_T c8_epsilon;
  real_T c8_n[3];
  real_T c8_alpha;
  int32_T c8_idx_sizes;
  real_T c8_idx_data[1];
  real_T c8_I[9];
  real_T c8_nx[9];
  real_T c8_R[9];
  real_T c8_nargin = 2.0;
  real_T c8_nargout = 1.0;
  real_T c8_b_Eul[3];
  int32_T c8_i7;
  real_T c8_c_u[3];
  int32_T c8_i8;
  real_T c8_c_v[3];
  real_T c8_A[3];
  int32_T c8_i9;
  real_T c8_d_u[3];
  int32_T c8_i10;
  real_T c8_d_v[3];
  real_T c8_dv1[3];
  int32_T c8_i11;
  real_T c8_dv2[3];
  real_T c8_B;
  real_T c8_y;
  real_T c8_b_y;
  real_T c8_c_y;
  int32_T c8_i12;
  int32_T c8_i13;
  real_T c8_e_u[3];
  int32_T c8_i14;
  real_T c8_e_v[3];
  real_T c8_b_A;
  int32_T c8_i15;
  real_T c8_f_u[3];
  int32_T c8_i16;
  real_T c8_f_v[3];
  real_T c8_b_B;
  real_T c8_d_y;
  real_T c8_d0;
  int32_T c8_i17;
  int32_T c8_ixstart;
  real_T c8_mtmp;
  real_T c8_x;
  boolean_T c8_b;
  int32_T c8_ix;
  int32_T c8_b_ix;
  real_T c8_b_x;
  boolean_T c8_b_b;
  int32_T c8_a;
  int32_T c8_b_a;
  int32_T c8_i18;
  int32_T c8_c_ix;
  real_T c8_c_a;
  real_T c8_c_b;
  boolean_T c8_p;
  real_T c8_b_mtmp;
  real_T c8_minval;
  int32_T c8_i19;
  boolean_T c8_c_x[3];
  int32_T c8_idx;
  static int32_T c8_iv0[1] = { 1 };

  int32_T c8_ii_sizes;
  int32_T c8_ii;
  int32_T c8_b_ii;
  int32_T c8_ii_data[1];
  int32_T c8_loop_ub;
  int32_T c8_i20;
  real_T c8_dv3[9];
  int32_T c8_i21;
  int32_T c8_b_idx;
  int32_T c8_i22;
  int32_T c8_i23;
  real_T c8_g_u[3];
  uint32_T c8_b_debug_family_var_map[4];
  real_T c8_b_nargin = 1.0;
  real_T c8_b_nargout = 1.0;
  real_T c8_dv4[9];
  int32_T c8_i24;
  int32_T c8_i25;
  real_T c8_d_a[9];
  real_T c8_d_b;
  int32_T c8_i26;
  int32_T c8_i27;
  real_T c8_e_a[9];
  real_T c8_dv5[9];
  int32_T c8_i28;
  int32_T c8_i29;
  int32_T c8_i30;
  int32_T c8_i31;
  int32_T c8_i32;
  real_T c8_Rot[9];
  real_T c8_c_nargin = 1.0;
  real_T c8_c_nargout = 1.0;
  real_T c8_d_x;
  real_T c8_e_x;
  real_T c8_d1;
  real_T c8_d2;
  real_T c8_d3;
  int32_T c8_i33;
  boolean_T exitg1;
  boolean_T exitg2;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 7U, chartInstance->c8_sfEvent);
  for (c8_i5 = 0; c8_i5 < 3; c8_i5++) {
    c8_b_v[c8_i5] = (*chartInstance->c8_v)[c8_i5];
  }

  for (c8_i6 = 0; c8_i6 < 3; c8_i6++) {
    c8_b_u[c8_i6] = (*chartInstance->c8_u)[c8_i6];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 12U, 12U, c8_debug_family_names,
    c8_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_epsilon, 0U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_n, 1U, c8_sf_marshallOut,
    c8_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_alpha, 2U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN_IMPORTABLE(c8_idx_data, (const int32_T *)
    &c8_idx_sizes, NULL, 0, 3, (void *)c8_d_sf_marshallOut, (void *)
    c8_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_I, 4U, c8_c_sf_marshallOut,
    c8_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_nx, 5U, c8_c_sf_marshallOut,
    c8_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_R, 6U, c8_c_sf_marshallOut,
    c8_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargin, 7U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargout, 8U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c8_b_v, 9U, c8_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c8_b_u, 10U, c8_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_b_Eul, 11U, c8_sf_marshallOut,
    c8_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 3);
  c8_rdivide(chartInstance, 0.31415926535897931, 180.0);
  c8_epsilon = 0.0017453292519943296;
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 11);
  for (c8_i7 = 0; c8_i7 < 3; c8_i7++) {
    c8_c_u[c8_i7] = c8_b_u[c8_i7];
  }

  for (c8_i8 = 0; c8_i8 < 3; c8_i8++) {
    c8_c_v[c8_i8] = c8_b_v[c8_i8];
  }

  c8_cross(chartInstance, c8_c_u, c8_c_v, c8_A);
  for (c8_i9 = 0; c8_i9 < 3; c8_i9++) {
    c8_d_u[c8_i9] = c8_b_u[c8_i9];
  }

  for (c8_i10 = 0; c8_i10 < 3; c8_i10++) {
    c8_d_v[c8_i10] = c8_b_v[c8_i10];
  }

  c8_cross(chartInstance, c8_d_u, c8_d_v, c8_dv1);
  for (c8_i11 = 0; c8_i11 < 3; c8_i11++) {
    c8_dv2[c8_i11] = c8_dv1[c8_i11];
  }

  c8_B = c8_norm(chartInstance, c8_dv2);
  c8_y = c8_B;
  c8_b_y = c8_y;
  c8_c_y = c8_b_y;
  for (c8_i12 = 0; c8_i12 < 3; c8_i12++) {
    c8_n[c8_i12] = c8_A[c8_i12] / c8_c_y;
  }

  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 14);
  for (c8_i13 = 0; c8_i13 < 3; c8_i13++) {
    c8_e_u[c8_i13] = c8_b_u[c8_i13];
  }

  for (c8_i14 = 0; c8_i14 < 3; c8_i14++) {
    c8_e_v[c8_i14] = c8_b_v[c8_i14];
  }

  c8_b_A = c8_dot(chartInstance, c8_e_u, c8_e_v);
  for (c8_i15 = 0; c8_i15 < 3; c8_i15++) {
    c8_f_u[c8_i15] = c8_b_u[c8_i15];
  }

  for (c8_i16 = 0; c8_i16 < 3; c8_i16++) {
    c8_f_v[c8_i16] = c8_b_v[c8_i16];
  }

  c8_b_B = c8_norm(chartInstance, c8_f_u) * c8_norm(chartInstance, c8_f_v);
  c8_d_y = c8_rdivide(chartInstance, c8_b_A, c8_b_B);
  c8_d0 = c8_d_y;
  c8_b_acos(chartInstance, &c8_d0);
  c8_alpha = c8_d0;
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 20);
  if (CV_EML_IF(0, 1, 0, CV_RELATIONAL_EVAL(4U, 0U, 0, 3.1415926535897931 -
        c8_alpha, 0.0017453292519943296, -1, 3U, 3.1415926535897931 - c8_alpha <=
        0.0017453292519943296))) {
    _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 21);
    for (c8_i17 = 0; c8_i17 < 3; c8_i17++) {
      c8_A[c8_i17] = c8_b_u[c8_i17];
    }

    c8_ixstart = 1;
    c8_mtmp = c8_A[0];
    c8_x = c8_mtmp;
    c8_b = muDoubleScalarIsNaN(c8_x);
    if (c8_b) {
      c8_eml_switch_helper(chartInstance);
      c8_eml_switch_helper(chartInstance);
      c8_ix = 2;
      exitg2 = false;
      while ((exitg2 == false) && (c8_ix < 4)) {
        c8_b_ix = c8_ix - 1;
        c8_ixstart = c8_b_ix + 1;
        c8_b_x = c8_A[c8_b_ix];
        c8_b_b = muDoubleScalarIsNaN(c8_b_x);
        if (!c8_b_b) {
          c8_mtmp = c8_A[c8_b_ix];
          exitg2 = true;
        } else {
          c8_ix++;
        }
      }
    }

    if (c8_ixstart < 3) {
      c8_a = c8_ixstart;
      c8_b_a = c8_a + 1;
      c8_i18 = c8_b_a;
      c8_eml_switch_helper(chartInstance);
      c8_eml_switch_helper(chartInstance);
      for (c8_c_ix = c8_i18; c8_c_ix < 4; c8_c_ix++) {
        c8_b_ix = c8_c_ix - 1;
        c8_c_a = c8_A[c8_b_ix];
        c8_c_b = c8_mtmp;
        c8_p = (c8_c_a < c8_c_b);
        if (c8_p) {
          c8_mtmp = c8_A[c8_b_ix];
        }
      }
    }

    c8_b_mtmp = c8_mtmp;
    c8_minval = c8_b_mtmp;
    for (c8_i19 = 0; c8_i19 < 3; c8_i19++) {
      c8_c_x[c8_i19] = (c8_b_u[c8_i19] == c8_minval);
    }

    c8_idx = 0;
    c8_ii_sizes = c8_iv0[0];
    c8_eml_switch_helper(chartInstance);
    c8_ii = 1;
    exitg1 = false;
    while ((exitg1 == false) && (c8_ii < 4)) {
      c8_b_ii = c8_ii;
      if (c8_c_x[c8_b_ii - 1]) {
        c8_idx = 1;
        _SFD_EML_ARRAY_BOUNDS_CHECK("", 1, 1, c8_ii_sizes, 1, 0);
        c8_ii_data[0] = c8_b_ii;
        exitg1 = true;
      } else {
        c8_ii++;
      }
    }

    if (c8_idx == 0) {
      c8_ii_sizes = 0;
    }

    c8_idx_sizes = c8_ii_sizes;
    c8_loop_ub = c8_ii_sizes - 1;
    for (c8_i20 = 0; c8_i20 <= c8_loop_ub; c8_i20++) {
      c8_idx_data[c8_i20] = (real_T)c8_ii_data[c8_i20];
    }

    _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 22);
    c8_eye(chartInstance, c8_dv3);
    for (c8_i21 = 0; c8_i21 < 9; c8_i21++) {
      c8_I[c8_i21] = c8_dv3[c8_i21];
    }

    _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 23);
    (real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("idx", 1, 1, c8_idx_sizes, 1, 0);
    c8_b_idx = (int32_T)c8_idx_data[0] - 1;
    for (c8_i22 = 0; c8_i22 < 3; c8_i22++) {
      c8_n[c8_i22] = c8_I[c8_i22 + 3 * c8_b_idx];
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 27);
  for (c8_i23 = 0; c8_i23 < 3; c8_i23++) {
    c8_g_u[c8_i23] = c8_n[c8_i23];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 4U, c8_b_debug_family_names,
    c8_b_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_b_nargin, 0U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_b_nargout, 1U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_g_u, 2U, c8_sf_marshallOut,
    c8_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_nx, 3U, c8_c_sf_marshallOut,
    c8_c_sf_marshallIn);
  CV_EML_FCN(0, 1);
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 52);
  c8_nx[0] = 0.0;
  c8_nx[3] = -c8_g_u[2];
  c8_nx[6] = c8_g_u[1];
  c8_nx[1] = c8_g_u[2];
  c8_nx[4] = 0.0;
  c8_nx[7] = -c8_g_u[0];
  c8_nx[2] = -c8_g_u[1];
  c8_nx[5] = c8_g_u[0];
  c8_nx[8] = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, -52);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 37);
  if (CV_EML_IF(0, 1, 1, CV_RELATIONAL_EVAL(4U, 0U, 1, c8_alpha,
        0.0017453292519943296, -1, 3U, c8_alpha <= 0.0017453292519943296))) {
    _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 38);
    c8_eye(chartInstance, c8_dv4);
    for (c8_i24 = 0; c8_i24 < 9; c8_i24++) {
      c8_R[c8_i24] = c8_dv4[c8_i24];
    }
  } else {
    _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 40);
    for (c8_i25 = 0; c8_i25 < 9; c8_i25++) {
      c8_d_a[c8_i25] = c8_nx[c8_i25];
    }

    c8_d_b = c8_alpha;
    for (c8_i26 = 0; c8_i26 < 9; c8_i26++) {
      c8_d_a[c8_i26] *= c8_d_b;
    }

    for (c8_i27 = 0; c8_i27 < 9; c8_i27++) {
      c8_e_a[c8_i27] = c8_d_a[c8_i27];
    }

    c8_expm(chartInstance, c8_e_a, c8_dv5);
    for (c8_i28 = 0; c8_i28 < 9; c8_i28++) {
      c8_R[c8_i28] = c8_dv5[c8_i28];
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 43);
  c8_i29 = 0;
  for (c8_i30 = 0; c8_i30 < 3; c8_i30++) {
    c8_i31 = 0;
    for (c8_i32 = 0; c8_i32 < 3; c8_i32++) {
      c8_Rot[c8_i32 + c8_i29] = c8_R[c8_i31 + c8_i30];
      c8_i31 += 3;
    }

    c8_i29 += 3;
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 4U, c8_c_debug_family_names,
    c8_b_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_c_nargin, 0U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_c_nargout, 1U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_Rot, 2U, c8_c_sf_marshallOut,
    c8_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c8_b_Eul, 3U, c8_sf_marshallOut,
    c8_sf_marshallIn);
  CV_EML_FCN(0, 2);
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 56);
  c8_d_x = c8_mpower(chartInstance, c8_Rot[5]) + c8_mpower(chartInstance,
    c8_Rot[8]);
  c8_e_x = c8_d_x;
  if (c8_e_x < 0.0) {
    c8_b_eml_error(chartInstance);
  }

  c8_e_x = muDoubleScalarSqrt(c8_e_x);
  c8_d1 = c8_atan2(chartInstance, c8_Rot[5], c8_Rot[8]);
  c8_d2 = c8_atan2(chartInstance, -c8_Rot[2], c8_e_x);
  c8_d3 = c8_atan2(chartInstance, c8_Rot[1], c8_Rot[0]);
  c8_b_Eul[0] = c8_d1;
  c8_b_Eul[1] = c8_d2;
  c8_b_Eul[2] = c8_d3;
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, -56);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, -43);
  _SFD_SYMBOL_SCOPE_POP();
  for (c8_i33 = 0; c8_i33 < 3; c8_i33++) {
    (*chartInstance->c8_Eul)[c8_i33] = c8_b_Eul[c8_i33];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, chartInstance->c8_sfEvent);
}

static void initSimStructsc8_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SFc8_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c8_machineNumber, uint32_T
  c8_chartNumber, uint32_T c8_instanceNumber)
{
  (void)c8_machineNumber;
  (void)c8_chartNumber;
  (void)c8_instanceNumber;
}

static const mxArray *c8_sf_marshallOut(void *chartInstanceVoid, void *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int32_T c8_i34;
  real_T c8_b_inData[3];
  int32_T c8_i35;
  real_T c8_b_u[3];
  const mxArray *c8_y = NULL;
  SFc8_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance;
  chartInstance = (SFc8_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *)
    chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  for (c8_i34 = 0; c8_i34 < 3; c8_i34++) {
    c8_b_inData[c8_i34] = (*(real_T (*)[3])c8_inData)[c8_i34];
  }

  for (c8_i35 = 0; c8_i35 < 3; c8_i35++) {
    c8_b_u[c8_i35] = c8_b_inData[c8_i35];
  }

  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_b_u, 0, 0U, 1U, 0U, 1, 3), false);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, false);
  return c8_mxArrayOutData;
}

static void c8_emlrt_marshallIn
  (SFc8_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance,
   const mxArray *c8_b_Eul, const char_T *c8_identifier, real_T c8_y[3])
{
  emlrtMsgIdentifier c8_thisId;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_b_Eul), &c8_thisId, c8_y);
  sf_mex_destroy(&c8_b_Eul);
}

static void c8_b_emlrt_marshallIn
  (SFc8_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance,
   const mxArray *c8_b_u, const emlrtMsgIdentifier *c8_parentId, real_T c8_y[3])
{
  real_T c8_dv6[3];
  int32_T c8_i36;
  (void)chartInstance;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_b_u), c8_dv6, 1, 0, 0U, 1, 0U, 1, 3);
  for (c8_i36 = 0; c8_i36 < 3; c8_i36++) {
    c8_y[c8_i36] = c8_dv6[c8_i36];
  }

  sf_mex_destroy(&c8_b_u);
}

static void c8_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData)
{
  const mxArray *c8_b_Eul;
  const char_T *c8_identifier;
  emlrtMsgIdentifier c8_thisId;
  real_T c8_y[3];
  int32_T c8_i37;
  SFc8_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance;
  chartInstance = (SFc8_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *)
    chartInstanceVoid;
  c8_b_Eul = sf_mex_dup(c8_mxArrayInData);
  c8_identifier = c8_varName;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_b_Eul), &c8_thisId, c8_y);
  sf_mex_destroy(&c8_b_Eul);
  for (c8_i37 = 0; c8_i37 < 3; c8_i37++) {
    (*(real_T (*)[3])c8_outData)[c8_i37] = c8_y[c8_i37];
  }

  sf_mex_destroy(&c8_mxArrayInData);
}

static const mxArray *c8_b_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  real_T c8_b_u;
  const mxArray *c8_y = NULL;
  SFc8_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance;
  chartInstance = (SFc8_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *)
    chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  c8_b_u = *(real_T *)c8_inData;
  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", &c8_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, false);
  return c8_mxArrayOutData;
}

static real_T c8_c_emlrt_marshallIn
  (SFc8_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance,
   const mxArray *c8_b_u, const emlrtMsgIdentifier *c8_parentId)
{
  real_T c8_y;
  real_T c8_d4;
  (void)chartInstance;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_b_u), &c8_d4, 1, 0, 0U, 0, 0U, 0);
  c8_y = c8_d4;
  sf_mex_destroy(&c8_b_u);
  return c8_y;
}

static void c8_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData)
{
  const mxArray *c8_nargout;
  const char_T *c8_identifier;
  emlrtMsgIdentifier c8_thisId;
  real_T c8_y;
  SFc8_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance;
  chartInstance = (SFc8_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *)
    chartInstanceVoid;
  c8_nargout = sf_mex_dup(c8_mxArrayInData);
  c8_identifier = c8_varName;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_y = c8_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_nargout), &c8_thisId);
  sf_mex_destroy(&c8_nargout);
  *(real_T *)c8_outData = c8_y;
  sf_mex_destroy(&c8_mxArrayInData);
}

static const mxArray *c8_c_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int32_T c8_i38;
  int32_T c8_i39;
  int32_T c8_i40;
  real_T c8_b_inData[9];
  int32_T c8_i41;
  int32_T c8_i42;
  int32_T c8_i43;
  real_T c8_b_u[9];
  const mxArray *c8_y = NULL;
  SFc8_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance;
  chartInstance = (SFc8_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *)
    chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  c8_i38 = 0;
  for (c8_i39 = 0; c8_i39 < 3; c8_i39++) {
    for (c8_i40 = 0; c8_i40 < 3; c8_i40++) {
      c8_b_inData[c8_i40 + c8_i38] = (*(real_T (*)[9])c8_inData)[c8_i40 + c8_i38];
    }

    c8_i38 += 3;
  }

  c8_i41 = 0;
  for (c8_i42 = 0; c8_i42 < 3; c8_i42++) {
    for (c8_i43 = 0; c8_i43 < 3; c8_i43++) {
      c8_b_u[c8_i43 + c8_i41] = c8_b_inData[c8_i43 + c8_i41];
    }

    c8_i41 += 3;
  }

  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_b_u, 0, 0U, 1U, 0U, 2, 3, 3), false);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, false);
  return c8_mxArrayOutData;
}

static void c8_d_emlrt_marshallIn
  (SFc8_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance,
   const mxArray *c8_b_u, const emlrtMsgIdentifier *c8_parentId, real_T c8_y[9])
{
  real_T c8_dv7[9];
  int32_T c8_i44;
  (void)chartInstance;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_b_u), c8_dv7, 1, 0, 0U, 1, 0U, 2, 3,
                3);
  for (c8_i44 = 0; c8_i44 < 9; c8_i44++) {
    c8_y[c8_i44] = c8_dv7[c8_i44];
  }

  sf_mex_destroy(&c8_b_u);
}

static void c8_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData)
{
  const mxArray *c8_R;
  const char_T *c8_identifier;
  emlrtMsgIdentifier c8_thisId;
  real_T c8_y[9];
  int32_T c8_i45;
  int32_T c8_i46;
  int32_T c8_i47;
  SFc8_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance;
  chartInstance = (SFc8_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *)
    chartInstanceVoid;
  c8_R = sf_mex_dup(c8_mxArrayInData);
  c8_identifier = c8_varName;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_R), &c8_thisId, c8_y);
  sf_mex_destroy(&c8_R);
  c8_i45 = 0;
  for (c8_i46 = 0; c8_i46 < 3; c8_i46++) {
    for (c8_i47 = 0; c8_i47 < 3; c8_i47++) {
      (*(real_T (*)[9])c8_outData)[c8_i47 + c8_i45] = c8_y[c8_i47 + c8_i45];
    }

    c8_i45 += 3;
  }

  sf_mex_destroy(&c8_mxArrayInData);
}

static const mxArray *c8_d_sf_marshallOut(void *chartInstanceVoid, real_T
  c8_inData_data[], int32_T *c8_inData_sizes)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int32_T c8_b_inData_sizes;
  int32_T c8_loop_ub;
  int32_T c8_i48;
  real_T c8_b_inData_data[1];
  int32_T c8_u_sizes;
  int32_T c8_b_loop_ub;
  int32_T c8_i49;
  real_T c8_u_data[1];
  const mxArray *c8_y = NULL;
  SFc8_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance;
  chartInstance = (SFc8_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *)
    chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  c8_b_inData_sizes = *c8_inData_sizes;
  c8_loop_ub = *c8_inData_sizes - 1;
  for (c8_i48 = 0; c8_i48 <= c8_loop_ub; c8_i48++) {
    c8_b_inData_data[c8_i48] = c8_inData_data[c8_i48];
  }

  c8_u_sizes = c8_b_inData_sizes;
  c8_b_loop_ub = c8_b_inData_sizes - 1;
  for (c8_i49 = 0; c8_i49 <= c8_b_loop_ub; c8_i49++) {
    c8_u_data[c8_i49] = c8_b_inData_data[c8_i49];
  }

  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_u_data, 0, 0U, 1U, 0U, 1,
    c8_u_sizes), false);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, false);
  return c8_mxArrayOutData;
}

static void c8_e_emlrt_marshallIn
  (SFc8_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance,
   const mxArray *c8_b_u, const emlrtMsgIdentifier *c8_parentId, real_T
   c8_y_data[], int32_T *c8_y_sizes)
{
  static uint32_T c8_uv0[1] = { 1U };

  uint32_T c8_uv1[1];
  static boolean_T c8_bv0[1] = { true };

  boolean_T c8_bv1[1];
  int32_T c8_tmp_sizes;
  real_T c8_tmp_data[1];
  int32_T c8_loop_ub;
  int32_T c8_i50;
  (void)chartInstance;
  c8_uv1[0] = c8_uv0[0];
  c8_bv1[0] = c8_bv0[0];
  sf_mex_import_vs(c8_parentId, sf_mex_dup(c8_b_u), c8_tmp_data, 1, 0, 0U, 1, 0U,
                   1, c8_bv1, c8_uv1, &c8_tmp_sizes);
  *c8_y_sizes = c8_tmp_sizes;
  c8_loop_ub = c8_tmp_sizes - 1;
  for (c8_i50 = 0; c8_i50 <= c8_loop_ub; c8_i50++) {
    c8_y_data[c8_i50] = c8_tmp_data[c8_i50];
  }

  sf_mex_destroy(&c8_b_u);
}

static void c8_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, real_T c8_outData_data[], int32_T
  *c8_outData_sizes)
{
  const mxArray *c8_idx;
  const char_T *c8_identifier;
  emlrtMsgIdentifier c8_thisId;
  int32_T c8_y_sizes;
  real_T c8_y_data[1];
  int32_T c8_loop_ub;
  int32_T c8_i51;
  SFc8_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance;
  chartInstance = (SFc8_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *)
    chartInstanceVoid;
  c8_idx = sf_mex_dup(c8_mxArrayInData);
  c8_identifier = c8_varName;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_idx), &c8_thisId, c8_y_data,
                        &c8_y_sizes);
  sf_mex_destroy(&c8_idx);
  *c8_outData_sizes = c8_y_sizes;
  c8_loop_ub = c8_y_sizes - 1;
  for (c8_i51 = 0; c8_i51 <= c8_loop_ub; c8_i51++) {
    c8_outData_data[c8_i51] = c8_y_data[c8_i51];
  }

  sf_mex_destroy(&c8_mxArrayInData);
}

const mxArray
  *sf_c8_wabs_perceptionmodel_VPT_Limbic_v3_adj_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c8_nameCaptureInfo = NULL;
  c8_nameCaptureInfo = NULL;
  sf_mex_assign(&c8_nameCaptureInfo, sf_mex_createstruct("structure", 2, 161, 1),
                false);
  c8_info_helper(&c8_nameCaptureInfo);
  c8_b_info_helper(&c8_nameCaptureInfo);
  c8_c_info_helper(&c8_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c8_nameCaptureInfo);
  return c8_nameCaptureInfo;
}

static void c8_info_helper(const mxArray **c8_info)
{
  const mxArray *c8_rhs0 = NULL;
  const mxArray *c8_lhs0 = NULL;
  const mxArray *c8_rhs1 = NULL;
  const mxArray *c8_lhs1 = NULL;
  const mxArray *c8_rhs2 = NULL;
  const mxArray *c8_lhs2 = NULL;
  const mxArray *c8_rhs3 = NULL;
  const mxArray *c8_lhs3 = NULL;
  const mxArray *c8_rhs4 = NULL;
  const mxArray *c8_lhs4 = NULL;
  const mxArray *c8_rhs5 = NULL;
  const mxArray *c8_lhs5 = NULL;
  const mxArray *c8_rhs6 = NULL;
  const mxArray *c8_lhs6 = NULL;
  const mxArray *c8_rhs7 = NULL;
  const mxArray *c8_lhs7 = NULL;
  const mxArray *c8_rhs8 = NULL;
  const mxArray *c8_lhs8 = NULL;
  const mxArray *c8_rhs9 = NULL;
  const mxArray *c8_lhs9 = NULL;
  const mxArray *c8_rhs10 = NULL;
  const mxArray *c8_lhs10 = NULL;
  const mxArray *c8_rhs11 = NULL;
  const mxArray *c8_lhs11 = NULL;
  const mxArray *c8_rhs12 = NULL;
  const mxArray *c8_lhs12 = NULL;
  const mxArray *c8_rhs13 = NULL;
  const mxArray *c8_lhs13 = NULL;
  const mxArray *c8_rhs14 = NULL;
  const mxArray *c8_lhs14 = NULL;
  const mxArray *c8_rhs15 = NULL;
  const mxArray *c8_lhs15 = NULL;
  const mxArray *c8_rhs16 = NULL;
  const mxArray *c8_lhs16 = NULL;
  const mxArray *c8_rhs17 = NULL;
  const mxArray *c8_lhs17 = NULL;
  const mxArray *c8_rhs18 = NULL;
  const mxArray *c8_lhs18 = NULL;
  const mxArray *c8_rhs19 = NULL;
  const mxArray *c8_lhs19 = NULL;
  const mxArray *c8_rhs20 = NULL;
  const mxArray *c8_lhs20 = NULL;
  const mxArray *c8_rhs21 = NULL;
  const mxArray *c8_lhs21 = NULL;
  const mxArray *c8_rhs22 = NULL;
  const mxArray *c8_lhs22 = NULL;
  const mxArray *c8_rhs23 = NULL;
  const mxArray *c8_lhs23 = NULL;
  const mxArray *c8_rhs24 = NULL;
  const mxArray *c8_lhs24 = NULL;
  const mxArray *c8_rhs25 = NULL;
  const mxArray *c8_lhs25 = NULL;
  const mxArray *c8_rhs26 = NULL;
  const mxArray *c8_lhs26 = NULL;
  const mxArray *c8_rhs27 = NULL;
  const mxArray *c8_lhs27 = NULL;
  const mxArray *c8_rhs28 = NULL;
  const mxArray *c8_lhs28 = NULL;
  const mxArray *c8_rhs29 = NULL;
  const mxArray *c8_lhs29 = NULL;
  const mxArray *c8_rhs30 = NULL;
  const mxArray *c8_lhs30 = NULL;
  const mxArray *c8_rhs31 = NULL;
  const mxArray *c8_lhs31 = NULL;
  const mxArray *c8_rhs32 = NULL;
  const mxArray *c8_lhs32 = NULL;
  const mxArray *c8_rhs33 = NULL;
  const mxArray *c8_lhs33 = NULL;
  const mxArray *c8_rhs34 = NULL;
  const mxArray *c8_lhs34 = NULL;
  const mxArray *c8_rhs35 = NULL;
  const mxArray *c8_lhs35 = NULL;
  const mxArray *c8_rhs36 = NULL;
  const mxArray *c8_lhs36 = NULL;
  const mxArray *c8_rhs37 = NULL;
  const mxArray *c8_lhs37 = NULL;
  const mxArray *c8_rhs38 = NULL;
  const mxArray *c8_lhs38 = NULL;
  const mxArray *c8_rhs39 = NULL;
  const mxArray *c8_lhs39 = NULL;
  const mxArray *c8_rhs40 = NULL;
  const mxArray *c8_lhs40 = NULL;
  const mxArray *c8_rhs41 = NULL;
  const mxArray *c8_lhs41 = NULL;
  const mxArray *c8_rhs42 = NULL;
  const mxArray *c8_lhs42 = NULL;
  const mxArray *c8_rhs43 = NULL;
  const mxArray *c8_lhs43 = NULL;
  const mxArray *c8_rhs44 = NULL;
  const mxArray *c8_lhs44 = NULL;
  const mxArray *c8_rhs45 = NULL;
  const mxArray *c8_lhs45 = NULL;
  const mxArray *c8_rhs46 = NULL;
  const mxArray *c8_lhs46 = NULL;
  const mxArray *c8_rhs47 = NULL;
  const mxArray *c8_lhs47 = NULL;
  const mxArray *c8_rhs48 = NULL;
  const mxArray *c8_lhs48 = NULL;
  const mxArray *c8_rhs49 = NULL;
  const mxArray *c8_lhs49 = NULL;
  const mxArray *c8_rhs50 = NULL;
  const mxArray *c8_lhs50 = NULL;
  const mxArray *c8_rhs51 = NULL;
  const mxArray *c8_lhs51 = NULL;
  const mxArray *c8_rhs52 = NULL;
  const mxArray *c8_lhs52 = NULL;
  const mxArray *c8_rhs53 = NULL;
  const mxArray *c8_lhs53 = NULL;
  const mxArray *c8_rhs54 = NULL;
  const mxArray *c8_lhs54 = NULL;
  const mxArray *c8_rhs55 = NULL;
  const mxArray *c8_lhs55 = NULL;
  const mxArray *c8_rhs56 = NULL;
  const mxArray *c8_lhs56 = NULL;
  const mxArray *c8_rhs57 = NULL;
  const mxArray *c8_lhs57 = NULL;
  const mxArray *c8_rhs58 = NULL;
  const mxArray *c8_lhs58 = NULL;
  const mxArray *c8_rhs59 = NULL;
  const mxArray *c8_lhs59 = NULL;
  const mxArray *c8_rhs60 = NULL;
  const mxArray *c8_lhs60 = NULL;
  const mxArray *c8_rhs61 = NULL;
  const mxArray *c8_lhs61 = NULL;
  const mxArray *c8_rhs62 = NULL;
  const mxArray *c8_lhs62 = NULL;
  const mxArray *c8_rhs63 = NULL;
  const mxArray *c8_lhs63 = NULL;
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("mrdivide"), "name", "name", 0);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1410807648U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1370009886U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c8_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs0), "rhs", "rhs", 0);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs0), "lhs", "lhs", 0);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 1);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 1);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1389717774U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c8_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs1), "rhs", "rhs", 1);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs1), "lhs", "lhs", 1);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 2);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("rdivide"), "name", "name", 2);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1363713880U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c8_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs2), "rhs", "rhs", 2);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs2), "lhs", "lhs", 2);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 3);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1395931856U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c8_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs3), "rhs", "rhs", 3);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs3), "lhs", "lhs", 3);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 4);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1286818796U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c8_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs4), "rhs", "rhs", 4);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs4), "lhs", "lhs", 4);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("eml_div"), "name", "name", 5);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 5);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1386423952U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c8_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs5), "rhs", "rhs", 5);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs5), "lhs", "lhs", 5);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 6);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 6);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1410807770U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c8_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs6), "rhs", "rhs", 6);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs6), "lhs", "lhs", 6);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(""), "context", "context", 7);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("cross"), "name", "name", 7);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/specfun/cross.m"), "resolved",
                  "resolved", 7);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1286818842U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c8_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs7), "rhs", "rhs", 7);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs7), "lhs", "lhs", 7);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(""), "context", "context", 8);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("norm"), "name", "name", 8);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m"), "resolved",
                  "resolved", 8);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1363713868U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c8_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs8), "rhs", "rhs", 8);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs8), "lhs", "lhs", 8);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!genpnorm"),
                  "context", "context", 9);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 9);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c8_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs9), "rhs", "rhs", 9);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs9), "lhs", "lhs", 9);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!genpnorm"),
                  "context", "context", 10);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 10);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1395931856U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c8_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!genpnorm"),
                  "context", "context", 11);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("eml_xnrm2"), "name", "name",
                  11);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xnrm2.m"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1375980692U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c8_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xnrm2.m"), "context",
                  "context", 12);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("coder.internal.blas.inline"),
                  "name", "name", 12);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/inline.p"),
                  "resolved", "resolved", 12);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1410807772U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c8_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xnrm2.m"), "context",
                  "context", 13);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("coder.internal.blas.xnrm2"),
                  "name", "name", 13);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xnrm2.p"),
                  "resolved", "resolved", 13);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1410807770U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c8_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xnrm2.p"),
                  "context", "context", 14);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 14);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 14);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1410807770U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c8_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xnrm2.p!below_threshold"),
                  "context", "context", 15);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("coder.internal.blas.threshold"),
                  "name", "name", 15);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "resolved", "resolved", 15);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1410807772U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c8_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "context", "context", 16);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 16);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 16);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1393330858U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c8_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xnrm2.p"),
                  "context", "context", 17);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("coder.internal.refblas.xnrm2"),
                  "name", "name", 17);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xnrm2.p"),
                  "resolved", "resolved", 17);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1410807772U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c8_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xnrm2.p"),
                  "context", "context", 18);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("realmin"), "name", "name", 18);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m"), "resolved",
                  "resolved", 18);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1307651242U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c8_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m"), "context",
                  "context", 19);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("eml_realmin"), "name", "name",
                  19);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmin.m"), "resolved",
                  "resolved", 19);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1307651244U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c8_rhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmin.m"), "context",
                  "context", 20);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("eml_float_model"), "name",
                  "name", 20);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                  "resolved", "resolved", 20);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1326727996U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c8_rhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xnrm2.p"),
                  "context", "context", 21);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("coder.internal.indexMinus"),
                  "name", "name", 21);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexMinus.m"),
                  "resolved", "resolved", 21);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1372583160U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c8_rhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs21), "lhs", "lhs",
                  21);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xnrm2.p"),
                  "context", "context", 22);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("coder.internal.indexTimes"),
                  "name", "name", 22);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 22);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexTimes.m"),
                  "resolved", "resolved", 22);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1372583160U), "fileTimeLo",
                  "fileTimeLo", 22);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c8_rhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs22), "rhs", "rhs",
                  22);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs22), "lhs", "lhs",
                  22);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xnrm2.p"),
                  "context", "context", 23);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 23);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 23);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 23);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1372583160U), "fileTimeLo",
                  "fileTimeLo", 23);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 23);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 23);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 23);
  sf_mex_assign(&c8_rhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs23), "rhs", "rhs",
                  23);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs23), "lhs", "lhs",
                  23);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xnrm2.p"),
                  "context", "context", 24);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 24);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 24);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 24);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1397257422U), "fileTimeLo",
                  "fileTimeLo", 24);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 24);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 24);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 24);
  sf_mex_assign(&c8_rhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs24), "rhs", "rhs",
                  24);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs24), "lhs", "lhs",
                  24);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 25);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("isfi"), "name", "name", 25);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 25);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m"), "resolved",
                  "resolved", 25);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1346510358U), "fileTimeLo",
                  "fileTimeLo", 25);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 25);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 25);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 25);
  sf_mex_assign(&c8_rhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs25), "rhs", "rhs",
                  25);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs25), "lhs", "lhs",
                  25);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m"), "context",
                  "context", 26);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("isnumerictype"), "name",
                  "name", 26);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 26);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isnumerictype.m"), "resolved",
                  "resolved", 26);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1398875598U), "fileTimeLo",
                  "fileTimeLo", 26);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 26);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 26);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 26);
  sf_mex_assign(&c8_rhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs26), "rhs", "rhs",
                  26);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs26), "lhs", "lhs",
                  26);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 27);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("intmax"), "name", "name", 27);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 27);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 27);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1362261882U), "fileTimeLo",
                  "fileTimeLo", 27);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 27);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 27);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 27);
  sf_mex_assign(&c8_rhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs27), "rhs", "rhs",
                  27);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs27), "lhs", "lhs",
                  27);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "context",
                  "context", 28);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 28);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 28);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 28);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1393330858U), "fileTimeLo",
                  "fileTimeLo", 28);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 28);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 28);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 28);
  sf_mex_assign(&c8_rhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs28), "rhs", "rhs",
                  28);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs28), "lhs", "lhs",
                  28);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 29);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("intmin"), "name", "name", 29);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 29);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 29);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1362261882U), "fileTimeLo",
                  "fileTimeLo", 29);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 29);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 29);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 29);
  sf_mex_assign(&c8_rhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs29), "rhs", "rhs",
                  29);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs29), "lhs", "lhs",
                  29);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "context",
                  "context", 30);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 30);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 30);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 30);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1393330858U), "fileTimeLo",
                  "fileTimeLo", 30);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 30);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 30);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 30);
  sf_mex_assign(&c8_rhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs30), "rhs", "rhs",
                  30);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs30), "lhs", "lhs",
                  30);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xnrm2.p"),
                  "context", "context", 31);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("abs"), "name", "name", 31);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 31);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 31);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1363713852U), "fileTimeLo",
                  "fileTimeLo", 31);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 31);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 31);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 31);
  sf_mex_assign(&c8_rhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs31), "rhs", "rhs",
                  31);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs31), "lhs", "lhs",
                  31);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 32);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 32);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 32);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 32);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1395931856U), "fileTimeLo",
                  "fileTimeLo", 32);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 32);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 32);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 32);
  sf_mex_assign(&c8_rhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs32), "rhs", "rhs",
                  32);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs32), "lhs", "lhs",
                  32);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 33);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("eml_scalar_abs"), "name",
                  "name", 33);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 33);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m"),
                  "resolved", "resolved", 33);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1286818712U), "fileTimeLo",
                  "fileTimeLo", 33);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 33);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 33);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 33);
  sf_mex_assign(&c8_rhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs33), "rhs", "rhs",
                  33);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs33), "lhs", "lhs",
                  33);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(""), "context", "context", 34);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("dot"), "name", "name", 34);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 34);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m"), "resolved",
                  "resolved", 34);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1360282354U), "fileTimeLo",
                  "fileTimeLo", 34);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 34);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 34);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 34);
  sf_mex_assign(&c8_rhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs34), "rhs", "rhs",
                  34);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs34), "lhs", "lhs",
                  34);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m"), "context",
                  "context", 35);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("isequal"), "name", "name", 35);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 35);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "resolved",
                  "resolved", 35);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1286818758U), "fileTimeLo",
                  "fileTimeLo", 35);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 35);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 35);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 35);
  sf_mex_assign(&c8_rhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs35), "rhs", "rhs",
                  35);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs35), "lhs", "lhs",
                  35);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "context",
                  "context", 36);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("eml_isequal_core"), "name",
                  "name", 36);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 36);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m"),
                  "resolved", "resolved", 36);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1286818786U), "fileTimeLo",
                  "fileTimeLo", 36);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 36);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 36);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 36);
  sf_mex_assign(&c8_rhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs36), "rhs", "rhs",
                  36);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs36), "lhs", "lhs",
                  36);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m!isequal_scalar"),
                  "context", "context", 37);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("isnan"), "name", "name", 37);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 37);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved",
                  "resolved", 37);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1363713858U), "fileTimeLo",
                  "fileTimeLo", 37);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 37);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 37);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 37);
  sf_mex_assign(&c8_rhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs37), "rhs", "rhs",
                  37);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs37), "lhs", "lhs",
                  37);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "context",
                  "context", 38);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 38);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 38);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 38);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1395931856U), "fileTimeLo",
                  "fileTimeLo", 38);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 38);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 38);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 38);
  sf_mex_assign(&c8_rhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs38), "rhs", "rhs",
                  38);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs38), "lhs", "lhs",
                  38);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m"), "context",
                  "context", 39);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 39);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 39);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 39);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 39);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 39);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 39);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 39);
  sf_mex_assign(&c8_rhs39, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs39, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs39), "rhs", "rhs",
                  39);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs39), "lhs", "lhs",
                  39);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m"), "context",
                  "context", 40);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 40);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 40);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 40);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1375980688U), "fileTimeLo",
                  "fileTimeLo", 40);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 40);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 40);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 40);
  sf_mex_assign(&c8_rhs40, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs40, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs40), "rhs", "rhs",
                  40);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs40), "lhs", "lhs",
                  40);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 41);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 41);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 41);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 41);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1410807770U), "fileTimeLo",
                  "fileTimeLo", 41);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 41);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 41);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 41);
  sf_mex_assign(&c8_rhs41, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs41, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs41), "rhs", "rhs",
                  41);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs41), "lhs", "lhs",
                  41);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/specfun/dot.m!vdot"), "context",
                  "context", 42);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("eml_xdotc"), "name", "name",
                  42);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 42);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotc.m"),
                  "resolved", "resolved", 42);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1375980690U), "fileTimeLo",
                  "fileTimeLo", 42);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 42);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 42);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 42);
  sf_mex_assign(&c8_rhs42, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs42, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs42), "rhs", "rhs",
                  42);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs42), "lhs", "lhs",
                  42);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotc.m"), "context",
                  "context", 43);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("coder.internal.blas.inline"),
                  "name", "name", 43);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 43);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/inline.p"),
                  "resolved", "resolved", 43);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1410807772U), "fileTimeLo",
                  "fileTimeLo", 43);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 43);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 43);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 43);
  sf_mex_assign(&c8_rhs43, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs43, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs43), "rhs", "rhs",
                  43);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs43), "lhs", "lhs",
                  43);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotc.m"), "context",
                  "context", 44);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("coder.internal.blas.xdotc"),
                  "name", "name", 44);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 44);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xdotc.p"),
                  "resolved", "resolved", 44);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1410807770U), "fileTimeLo",
                  "fileTimeLo", 44);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 44);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 44);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 44);
  sf_mex_assign(&c8_rhs44, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs44, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs44), "rhs", "rhs",
                  44);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs44), "lhs", "lhs",
                  44);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xdotc.p"),
                  "context", "context", 45);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("coder.internal.blas.xdot"),
                  "name", "name", 45);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 45);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xdot.p"),
                  "resolved", "resolved", 45);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1410807772U), "fileTimeLo",
                  "fileTimeLo", 45);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 45);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 45);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 45);
  sf_mex_assign(&c8_rhs45, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs45, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs45), "rhs", "rhs",
                  45);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs45), "lhs", "lhs",
                  45);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xdot.p"),
                  "context", "context", 46);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 46);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 46);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 46);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1410807770U), "fileTimeLo",
                  "fileTimeLo", 46);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 46);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 46);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 46);
  sf_mex_assign(&c8_rhs46, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs46, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs46), "rhs", "rhs",
                  46);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs46), "lhs", "lhs",
                  46);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xdot.p!below_threshold"),
                  "context", "context", 47);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("coder.internal.blas.threshold"),
                  "name", "name", 47);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 47);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "resolved", "resolved", 47);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1410807772U), "fileTimeLo",
                  "fileTimeLo", 47);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 47);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 47);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 47);
  sf_mex_assign(&c8_rhs47, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs47, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs47), "rhs", "rhs",
                  47);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs47), "lhs", "lhs",
                  47);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xdot.p"),
                  "context", "context", 48);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("coder.internal.refblas.xdot"),
                  "name", "name", 48);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 48);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdot.p"),
                  "resolved", "resolved", 48);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1410807772U), "fileTimeLo",
                  "fileTimeLo", 48);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 48);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 48);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 48);
  sf_mex_assign(&c8_rhs48, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs48, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs48), "rhs", "rhs",
                  48);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs48), "lhs", "lhs",
                  48);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdot.p"),
                  "context", "context", 49);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("coder.internal.refblas.xdotx"),
                  "name", "name", 49);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 49);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdotx.p"),
                  "resolved", "resolved", 49);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1410807772U), "fileTimeLo",
                  "fileTimeLo", 49);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 49);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 49);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 49);
  sf_mex_assign(&c8_rhs49, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs49, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs49), "rhs", "rhs",
                  49);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs49), "lhs", "lhs",
                  49);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdotx.p"),
                  "context", "context", 50);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 50);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 50);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 50);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1410807770U), "fileTimeLo",
                  "fileTimeLo", 50);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 50);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 50);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 50);
  sf_mex_assign(&c8_rhs50, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs50, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs50), "rhs", "rhs",
                  50);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs50), "lhs", "lhs",
                  50);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdotx.p"),
                  "context", "context", 51);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("coder.internal.indexMinus"),
                  "name", "name", 51);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 51);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexMinus.m"),
                  "resolved", "resolved", 51);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1372583160U), "fileTimeLo",
                  "fileTimeLo", 51);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 51);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 51);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 51);
  sf_mex_assign(&c8_rhs51, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs51, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs51), "rhs", "rhs",
                  51);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs51), "lhs", "lhs",
                  51);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdotx.p"),
                  "context", "context", 52);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("coder.internal.indexTimes"),
                  "name", "name", 52);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 52);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexTimes.m"),
                  "resolved", "resolved", 52);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1372583160U), "fileTimeLo",
                  "fileTimeLo", 52);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 52);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 52);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 52);
  sf_mex_assign(&c8_rhs52, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs52, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs52), "rhs", "rhs",
                  52);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs52), "lhs", "lhs",
                  52);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdotx.p"),
                  "context", "context", 53);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 53);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 53);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 53);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1372583160U), "fileTimeLo",
                  "fileTimeLo", 53);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 53);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 53);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 53);
  sf_mex_assign(&c8_rhs53, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs53, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs53), "rhs", "rhs",
                  53);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs53), "lhs", "lhs",
                  53);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdotx.p"),
                  "context", "context", 54);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 54);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 54);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 54);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1397257422U), "fileTimeLo",
                  "fileTimeLo", 54);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 54);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 54);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 54);
  sf_mex_assign(&c8_rhs54, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs54, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs54), "rhs", "rhs",
                  54);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs54), "lhs", "lhs",
                  54);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(""), "context", "context", 55);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("acos"), "name", "name", 55);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 55);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/acos.m"), "resolved",
                  "resolved", 55);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1395328492U), "fileTimeLo",
                  "fileTimeLo", 55);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 55);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 55);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 55);
  sf_mex_assign(&c8_rhs55, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs55, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs55), "rhs", "rhs",
                  55);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs55), "lhs", "lhs",
                  55);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/acos.m"), "context",
                  "context", 56);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("eml_error"), "name", "name",
                  56);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 56);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m"), "resolved",
                  "resolved", 56);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1343830358U), "fileTimeLo",
                  "fileTimeLo", 56);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 56);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 56);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 56);
  sf_mex_assign(&c8_rhs56, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs56, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs56), "rhs", "rhs",
                  56);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs56), "lhs", "lhs",
                  56);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/acos.m"), "context",
                  "context", 57);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("eml_scalar_acos"), "name",
                  "name", 57);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 57);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_acos.m"),
                  "resolved", "resolved", 57);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1343830376U), "fileTimeLo",
                  "fileTimeLo", 57);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 57);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 57);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 57);
  sf_mex_assign(&c8_rhs57, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs57, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs57), "rhs", "rhs",
                  57);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs57), "lhs", "lhs",
                  57);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(""), "context", "context", 58);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("min"), "name", "name", 58);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 58);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m"), "resolved",
                  "resolved", 58);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1311255318U), "fileTimeLo",
                  "fileTimeLo", 58);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 58);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 58);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 58);
  sf_mex_assign(&c8_rhs58, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs58, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs58), "rhs", "rhs",
                  58);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs58), "lhs", "lhs",
                  58);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m"), "context",
                  "context", 59);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("eml_min_or_max"), "name",
                  "name", 59);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 59);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m"),
                  "resolved", "resolved", 59);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1378295984U), "fileTimeLo",
                  "fileTimeLo", 59);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 59);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 59);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 59);
  sf_mex_assign(&c8_rhs59, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs59, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs59), "rhs", "rhs",
                  59);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs59), "lhs", "lhs",
                  59);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum"),
                  "context", "context", 60);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("eml_const_nonsingleton_dim"),
                  "name", "name", 60);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 60);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_const_nonsingleton_dim.m"),
                  "resolved", "resolved", 60);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1372582416U), "fileTimeLo",
                  "fileTimeLo", 60);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 60);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 60);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 60);
  sf_mex_assign(&c8_rhs60, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs60, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs60), "rhs", "rhs",
                  60);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs60), "lhs", "lhs",
                  60);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_const_nonsingleton_dim.m"),
                  "context", "context", 61);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "coder.internal.constNonSingletonDim"), "name", "name", 61);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 61);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/constNonSingletonDim.m"),
                  "resolved", "resolved", 61);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1372583160U), "fileTimeLo",
                  "fileTimeLo", 61);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 61);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 61);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 61);
  sf_mex_assign(&c8_rhs61, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs61, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs61), "rhs", "rhs",
                  61);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs61), "lhs", "lhs",
                  61);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum"),
                  "context", "context", 62);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 62);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 62);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 62);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1375980688U), "fileTimeLo",
                  "fileTimeLo", 62);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 62);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 62);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 62);
  sf_mex_assign(&c8_rhs62, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs62, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs62), "rhs", "rhs",
                  62);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs62), "lhs", "lhs",
                  62);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum"),
                  "context", "context", 63);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 63);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 63);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 63);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 63);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 63);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 63);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 63);
  sf_mex_assign(&c8_rhs63, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs63, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs63), "rhs", "rhs",
                  63);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs63), "lhs", "lhs",
                  63);
  sf_mex_destroy(&c8_rhs0);
  sf_mex_destroy(&c8_lhs0);
  sf_mex_destroy(&c8_rhs1);
  sf_mex_destroy(&c8_lhs1);
  sf_mex_destroy(&c8_rhs2);
  sf_mex_destroy(&c8_lhs2);
  sf_mex_destroy(&c8_rhs3);
  sf_mex_destroy(&c8_lhs3);
  sf_mex_destroy(&c8_rhs4);
  sf_mex_destroy(&c8_lhs4);
  sf_mex_destroy(&c8_rhs5);
  sf_mex_destroy(&c8_lhs5);
  sf_mex_destroy(&c8_rhs6);
  sf_mex_destroy(&c8_lhs6);
  sf_mex_destroy(&c8_rhs7);
  sf_mex_destroy(&c8_lhs7);
  sf_mex_destroy(&c8_rhs8);
  sf_mex_destroy(&c8_lhs8);
  sf_mex_destroy(&c8_rhs9);
  sf_mex_destroy(&c8_lhs9);
  sf_mex_destroy(&c8_rhs10);
  sf_mex_destroy(&c8_lhs10);
  sf_mex_destroy(&c8_rhs11);
  sf_mex_destroy(&c8_lhs11);
  sf_mex_destroy(&c8_rhs12);
  sf_mex_destroy(&c8_lhs12);
  sf_mex_destroy(&c8_rhs13);
  sf_mex_destroy(&c8_lhs13);
  sf_mex_destroy(&c8_rhs14);
  sf_mex_destroy(&c8_lhs14);
  sf_mex_destroy(&c8_rhs15);
  sf_mex_destroy(&c8_lhs15);
  sf_mex_destroy(&c8_rhs16);
  sf_mex_destroy(&c8_lhs16);
  sf_mex_destroy(&c8_rhs17);
  sf_mex_destroy(&c8_lhs17);
  sf_mex_destroy(&c8_rhs18);
  sf_mex_destroy(&c8_lhs18);
  sf_mex_destroy(&c8_rhs19);
  sf_mex_destroy(&c8_lhs19);
  sf_mex_destroy(&c8_rhs20);
  sf_mex_destroy(&c8_lhs20);
  sf_mex_destroy(&c8_rhs21);
  sf_mex_destroy(&c8_lhs21);
  sf_mex_destroy(&c8_rhs22);
  sf_mex_destroy(&c8_lhs22);
  sf_mex_destroy(&c8_rhs23);
  sf_mex_destroy(&c8_lhs23);
  sf_mex_destroy(&c8_rhs24);
  sf_mex_destroy(&c8_lhs24);
  sf_mex_destroy(&c8_rhs25);
  sf_mex_destroy(&c8_lhs25);
  sf_mex_destroy(&c8_rhs26);
  sf_mex_destroy(&c8_lhs26);
  sf_mex_destroy(&c8_rhs27);
  sf_mex_destroy(&c8_lhs27);
  sf_mex_destroy(&c8_rhs28);
  sf_mex_destroy(&c8_lhs28);
  sf_mex_destroy(&c8_rhs29);
  sf_mex_destroy(&c8_lhs29);
  sf_mex_destroy(&c8_rhs30);
  sf_mex_destroy(&c8_lhs30);
  sf_mex_destroy(&c8_rhs31);
  sf_mex_destroy(&c8_lhs31);
  sf_mex_destroy(&c8_rhs32);
  sf_mex_destroy(&c8_lhs32);
  sf_mex_destroy(&c8_rhs33);
  sf_mex_destroy(&c8_lhs33);
  sf_mex_destroy(&c8_rhs34);
  sf_mex_destroy(&c8_lhs34);
  sf_mex_destroy(&c8_rhs35);
  sf_mex_destroy(&c8_lhs35);
  sf_mex_destroy(&c8_rhs36);
  sf_mex_destroy(&c8_lhs36);
  sf_mex_destroy(&c8_rhs37);
  sf_mex_destroy(&c8_lhs37);
  sf_mex_destroy(&c8_rhs38);
  sf_mex_destroy(&c8_lhs38);
  sf_mex_destroy(&c8_rhs39);
  sf_mex_destroy(&c8_lhs39);
  sf_mex_destroy(&c8_rhs40);
  sf_mex_destroy(&c8_lhs40);
  sf_mex_destroy(&c8_rhs41);
  sf_mex_destroy(&c8_lhs41);
  sf_mex_destroy(&c8_rhs42);
  sf_mex_destroy(&c8_lhs42);
  sf_mex_destroy(&c8_rhs43);
  sf_mex_destroy(&c8_lhs43);
  sf_mex_destroy(&c8_rhs44);
  sf_mex_destroy(&c8_lhs44);
  sf_mex_destroy(&c8_rhs45);
  sf_mex_destroy(&c8_lhs45);
  sf_mex_destroy(&c8_rhs46);
  sf_mex_destroy(&c8_lhs46);
  sf_mex_destroy(&c8_rhs47);
  sf_mex_destroy(&c8_lhs47);
  sf_mex_destroy(&c8_rhs48);
  sf_mex_destroy(&c8_lhs48);
  sf_mex_destroy(&c8_rhs49);
  sf_mex_destroy(&c8_lhs49);
  sf_mex_destroy(&c8_rhs50);
  sf_mex_destroy(&c8_lhs50);
  sf_mex_destroy(&c8_rhs51);
  sf_mex_destroy(&c8_lhs51);
  sf_mex_destroy(&c8_rhs52);
  sf_mex_destroy(&c8_lhs52);
  sf_mex_destroy(&c8_rhs53);
  sf_mex_destroy(&c8_lhs53);
  sf_mex_destroy(&c8_rhs54);
  sf_mex_destroy(&c8_lhs54);
  sf_mex_destroy(&c8_rhs55);
  sf_mex_destroy(&c8_lhs55);
  sf_mex_destroy(&c8_rhs56);
  sf_mex_destroy(&c8_lhs56);
  sf_mex_destroy(&c8_rhs57);
  sf_mex_destroy(&c8_lhs57);
  sf_mex_destroy(&c8_rhs58);
  sf_mex_destroy(&c8_lhs58);
  sf_mex_destroy(&c8_rhs59);
  sf_mex_destroy(&c8_lhs59);
  sf_mex_destroy(&c8_rhs60);
  sf_mex_destroy(&c8_lhs60);
  sf_mex_destroy(&c8_rhs61);
  sf_mex_destroy(&c8_lhs61);
  sf_mex_destroy(&c8_rhs62);
  sf_mex_destroy(&c8_lhs62);
  sf_mex_destroy(&c8_rhs63);
  sf_mex_destroy(&c8_lhs63);
}

static const mxArray *c8_emlrt_marshallOut(const char * c8_b_u)
{
  const mxArray *c8_y = NULL;
  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_b_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c8_b_u)), false);
  return c8_y;
}

static const mxArray *c8_b_emlrt_marshallOut(const uint32_T c8_b_u)
{
  const mxArray *c8_y = NULL;
  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", &c8_b_u, 7, 0U, 0U, 0U, 0), false);
  return c8_y;
}

static void c8_b_info_helper(const mxArray **c8_info)
{
  const mxArray *c8_rhs64 = NULL;
  const mxArray *c8_lhs64 = NULL;
  const mxArray *c8_rhs65 = NULL;
  const mxArray *c8_lhs65 = NULL;
  const mxArray *c8_rhs66 = NULL;
  const mxArray *c8_lhs66 = NULL;
  const mxArray *c8_rhs67 = NULL;
  const mxArray *c8_lhs67 = NULL;
  const mxArray *c8_rhs68 = NULL;
  const mxArray *c8_lhs68 = NULL;
  const mxArray *c8_rhs69 = NULL;
  const mxArray *c8_lhs69 = NULL;
  const mxArray *c8_rhs70 = NULL;
  const mxArray *c8_lhs70 = NULL;
  const mxArray *c8_rhs71 = NULL;
  const mxArray *c8_lhs71 = NULL;
  const mxArray *c8_rhs72 = NULL;
  const mxArray *c8_lhs72 = NULL;
  const mxArray *c8_rhs73 = NULL;
  const mxArray *c8_lhs73 = NULL;
  const mxArray *c8_rhs74 = NULL;
  const mxArray *c8_lhs74 = NULL;
  const mxArray *c8_rhs75 = NULL;
  const mxArray *c8_lhs75 = NULL;
  const mxArray *c8_rhs76 = NULL;
  const mxArray *c8_lhs76 = NULL;
  const mxArray *c8_rhs77 = NULL;
  const mxArray *c8_lhs77 = NULL;
  const mxArray *c8_rhs78 = NULL;
  const mxArray *c8_lhs78 = NULL;
  const mxArray *c8_rhs79 = NULL;
  const mxArray *c8_lhs79 = NULL;
  const mxArray *c8_rhs80 = NULL;
  const mxArray *c8_lhs80 = NULL;
  const mxArray *c8_rhs81 = NULL;
  const mxArray *c8_lhs81 = NULL;
  const mxArray *c8_rhs82 = NULL;
  const mxArray *c8_lhs82 = NULL;
  const mxArray *c8_rhs83 = NULL;
  const mxArray *c8_lhs83 = NULL;
  const mxArray *c8_rhs84 = NULL;
  const mxArray *c8_lhs84 = NULL;
  const mxArray *c8_rhs85 = NULL;
  const mxArray *c8_lhs85 = NULL;
  const mxArray *c8_rhs86 = NULL;
  const mxArray *c8_lhs86 = NULL;
  const mxArray *c8_rhs87 = NULL;
  const mxArray *c8_lhs87 = NULL;
  const mxArray *c8_rhs88 = NULL;
  const mxArray *c8_lhs88 = NULL;
  const mxArray *c8_rhs89 = NULL;
  const mxArray *c8_lhs89 = NULL;
  const mxArray *c8_rhs90 = NULL;
  const mxArray *c8_lhs90 = NULL;
  const mxArray *c8_rhs91 = NULL;
  const mxArray *c8_lhs91 = NULL;
  const mxArray *c8_rhs92 = NULL;
  const mxArray *c8_lhs92 = NULL;
  const mxArray *c8_rhs93 = NULL;
  const mxArray *c8_lhs93 = NULL;
  const mxArray *c8_rhs94 = NULL;
  const mxArray *c8_lhs94 = NULL;
  const mxArray *c8_rhs95 = NULL;
  const mxArray *c8_lhs95 = NULL;
  const mxArray *c8_rhs96 = NULL;
  const mxArray *c8_lhs96 = NULL;
  const mxArray *c8_rhs97 = NULL;
  const mxArray *c8_lhs97 = NULL;
  const mxArray *c8_rhs98 = NULL;
  const mxArray *c8_lhs98 = NULL;
  const mxArray *c8_rhs99 = NULL;
  const mxArray *c8_lhs99 = NULL;
  const mxArray *c8_rhs100 = NULL;
  const mxArray *c8_lhs100 = NULL;
  const mxArray *c8_rhs101 = NULL;
  const mxArray *c8_lhs101 = NULL;
  const mxArray *c8_rhs102 = NULL;
  const mxArray *c8_lhs102 = NULL;
  const mxArray *c8_rhs103 = NULL;
  const mxArray *c8_lhs103 = NULL;
  const mxArray *c8_rhs104 = NULL;
  const mxArray *c8_lhs104 = NULL;
  const mxArray *c8_rhs105 = NULL;
  const mxArray *c8_lhs105 = NULL;
  const mxArray *c8_rhs106 = NULL;
  const mxArray *c8_lhs106 = NULL;
  const mxArray *c8_rhs107 = NULL;
  const mxArray *c8_lhs107 = NULL;
  const mxArray *c8_rhs108 = NULL;
  const mxArray *c8_lhs108 = NULL;
  const mxArray *c8_rhs109 = NULL;
  const mxArray *c8_lhs109 = NULL;
  const mxArray *c8_rhs110 = NULL;
  const mxArray *c8_lhs110 = NULL;
  const mxArray *c8_rhs111 = NULL;
  const mxArray *c8_lhs111 = NULL;
  const mxArray *c8_rhs112 = NULL;
  const mxArray *c8_lhs112 = NULL;
  const mxArray *c8_rhs113 = NULL;
  const mxArray *c8_lhs113 = NULL;
  const mxArray *c8_rhs114 = NULL;
  const mxArray *c8_lhs114 = NULL;
  const mxArray *c8_rhs115 = NULL;
  const mxArray *c8_lhs115 = NULL;
  const mxArray *c8_rhs116 = NULL;
  const mxArray *c8_lhs116 = NULL;
  const mxArray *c8_rhs117 = NULL;
  const mxArray *c8_lhs117 = NULL;
  const mxArray *c8_rhs118 = NULL;
  const mxArray *c8_lhs118 = NULL;
  const mxArray *c8_rhs119 = NULL;
  const mxArray *c8_lhs119 = NULL;
  const mxArray *c8_rhs120 = NULL;
  const mxArray *c8_lhs120 = NULL;
  const mxArray *c8_rhs121 = NULL;
  const mxArray *c8_lhs121 = NULL;
  const mxArray *c8_rhs122 = NULL;
  const mxArray *c8_lhs122 = NULL;
  const mxArray *c8_rhs123 = NULL;
  const mxArray *c8_lhs123 = NULL;
  const mxArray *c8_rhs124 = NULL;
  const mxArray *c8_lhs124 = NULL;
  const mxArray *c8_rhs125 = NULL;
  const mxArray *c8_lhs125 = NULL;
  const mxArray *c8_rhs126 = NULL;
  const mxArray *c8_lhs126 = NULL;
  const mxArray *c8_rhs127 = NULL;
  const mxArray *c8_lhs127 = NULL;
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub"),
                  "context", "context", 64);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 64);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 64);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 64);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 64);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 64);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 64);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 64);
  sf_mex_assign(&c8_rhs64, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs64, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs64), "rhs", "rhs",
                  64);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs64), "lhs", "lhs",
                  64);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub"),
                  "context", "context", 65);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("isnan"), "name", "name", 65);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 65);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved",
                  "resolved", 65);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1363713858U), "fileTimeLo",
                  "fileTimeLo", 65);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 65);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 65);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 65);
  sf_mex_assign(&c8_rhs65, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs65, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs65), "rhs", "rhs",
                  65);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs65), "lhs", "lhs",
                  65);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub"),
                  "context", "context", 66);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 66);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 66);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 66);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1372582416U), "fileTimeLo",
                  "fileTimeLo", 66);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 66);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 66);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 66);
  sf_mex_assign(&c8_rhs66, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs66, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs66), "rhs", "rhs",
                  66);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs66), "lhs", "lhs",
                  66);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"), "context",
                  "context", 67);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 67);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 67);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 67);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1372583160U), "fileTimeLo",
                  "fileTimeLo", 67);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 67);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 67);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 67);
  sf_mex_assign(&c8_rhs67, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs67, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs67), "rhs", "rhs",
                  67);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs67), "lhs", "lhs",
                  67);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub"),
                  "context", "context", 68);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 68);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 68);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 68);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1397257422U), "fileTimeLo",
                  "fileTimeLo", 68);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 68);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 68);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 68);
  sf_mex_assign(&c8_rhs68, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs68, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs68), "rhs", "rhs",
                  68);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs68), "lhs", "lhs",
                  68);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub"),
                  "context", "context", 69);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("eml_relop"), "name", "name",
                  69);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("function_handle"),
                  "dominantType", "dominantType", 69);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_relop.m"), "resolved",
                  "resolved", 69);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1342451182U), "fileTimeLo",
                  "fileTimeLo", 69);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 69);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 69);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 69);
  sf_mex_assign(&c8_rhs69, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs69, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs69), "rhs", "rhs",
                  69);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs69), "lhs", "lhs",
                  69);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(""), "context", "context", 70);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("find"), "name", "name", 70);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 70);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/find.m"), "resolved",
                  "resolved", 70);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1303146206U), "fileTimeLo",
                  "fileTimeLo", 70);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 70);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 70);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 70);
  sf_mex_assign(&c8_rhs70, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs70, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs70), "rhs", "rhs",
                  70);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs70), "lhs", "lhs",
                  70);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/find.m!eml_find"),
                  "context", "context", 71);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 71);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 71);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 71);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 71);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 71);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 71);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 71);
  sf_mex_assign(&c8_rhs71, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs71, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs71), "rhs", "rhs",
                  71);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs71), "lhs", "lhs",
                  71);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/find.m!eml_find"),
                  "context", "context", 72);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 72);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("logical"), "dominantType",
                  "dominantType", 72);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 72);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1375980688U), "fileTimeLo",
                  "fileTimeLo", 72);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 72);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 72);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 72);
  sf_mex_assign(&c8_rhs72, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs72, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs72), "rhs", "rhs",
                  72);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs72), "lhs", "lhs",
                  72);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 73);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 73);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("logical"), "dominantType",
                  "dominantType", 73);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 73);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1410807770U), "fileTimeLo",
                  "fileTimeLo", 73);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 73);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 73);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 73);
  sf_mex_assign(&c8_rhs73, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs73, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs73), "rhs", "rhs",
                  73);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs73), "lhs", "lhs",
                  73);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/find.m!eml_find"),
                  "context", "context", 74);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("floor"), "name", "name", 74);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 74);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 74);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1363713854U), "fileTimeLo",
                  "fileTimeLo", 74);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 74);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 74);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 74);
  sf_mex_assign(&c8_rhs74, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs74, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs74), "rhs", "rhs",
                  74);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs74), "lhs", "lhs",
                  74);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 75);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 75);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 75);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 75);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1395931856U), "fileTimeLo",
                  "fileTimeLo", 75);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 75);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 75);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 75);
  sf_mex_assign(&c8_rhs75, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs75, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs75), "rhs", "rhs",
                  75);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs75), "lhs", "lhs",
                  75);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 76);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("eml_scalar_floor"), "name",
                  "name", 76);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 76);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m"),
                  "resolved", "resolved", 76);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1286818726U), "fileTimeLo",
                  "fileTimeLo", 76);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 76);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 76);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 76);
  sf_mex_assign(&c8_rhs76, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs76, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs76), "rhs", "rhs",
                  76);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs76), "lhs", "lhs",
                  76);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/find.m!eml_find"),
                  "context", "context", 77);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("min"), "name", "name", 77);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 77);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m"), "resolved",
                  "resolved", 77);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1311255318U), "fileTimeLo",
                  "fileTimeLo", 77);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 77);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 77);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 77);
  sf_mex_assign(&c8_rhs77, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs77, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs77), "rhs", "rhs",
                  77);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs77), "lhs", "lhs",
                  77);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 78);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 78);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 78);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 78);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1375980688U), "fileTimeLo",
                  "fileTimeLo", 78);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 78);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 78);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 78);
  sf_mex_assign(&c8_rhs78, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs78, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs78), "rhs", "rhs",
                  78);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs78), "lhs", "lhs",
                  78);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 79);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 79);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 79);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 79);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1410807770U), "fileTimeLo",
                  "fileTimeLo", 79);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 79);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 79);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 79);
  sf_mex_assign(&c8_rhs79, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs79, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs79), "rhs", "rhs",
                  79);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs79), "lhs", "lhs",
                  79);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 80);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 80);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 80);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 80);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1375980688U), "fileTimeLo",
                  "fileTimeLo", 80);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 80);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 80);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 80);
  sf_mex_assign(&c8_rhs80, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs80, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs80), "rhs", "rhs",
                  80);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs80), "lhs", "lhs",
                  80);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "context", "context", 81);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("coder.internal.scalexpAlloc"),
                  "name", "name", 81);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 81);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalexpAlloc.p"),
                  "resolved", "resolved", 81);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1410807770U), "fileTimeLo",
                  "fileTimeLo", 81);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 81);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 81);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 81);
  sf_mex_assign(&c8_rhs81, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs81, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs81), "rhs", "rhs",
                  81);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs81), "lhs", "lhs",
                  81);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 82);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 82);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 82);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 82);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 82);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 82);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 82);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 82);
  sf_mex_assign(&c8_rhs82, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs82, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs82), "rhs", "rhs",
                  82);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs82), "lhs", "lhs",
                  82);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                  "context", "context", 83);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 83);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 83);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 83);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1375980688U), "fileTimeLo",
                  "fileTimeLo", 83);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 83);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 83);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 83);
  sf_mex_assign(&c8_rhs83, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs83, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs83), "rhs", "rhs",
                  83);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs83), "lhs", "lhs",
                  83);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                  "context", "context", 84);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 84);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 84);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 84);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1395931856U), "fileTimeLo",
                  "fileTimeLo", 84);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 84);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 84);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 84);
  sf_mex_assign(&c8_rhs84, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs84, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs84), "rhs", "rhs",
                  84);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs84), "lhs", "lhs",
                  84);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/find.m!eml_find"),
                  "context", "context", 85);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 85);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 85);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 85);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1397257422U), "fileTimeLo",
                  "fileTimeLo", 85);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 85);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 85);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 85);
  sf_mex_assign(&c8_rhs85, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs85, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs85), "rhs", "rhs",
                  85);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs85), "lhs", "lhs",
                  85);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/find.m!eml_find"),
                  "context", "context", 86);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 86);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 86);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 86);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1372582416U), "fileTimeLo",
                  "fileTimeLo", 86);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 86);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 86);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 86);
  sf_mex_assign(&c8_rhs86, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs86, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs86), "rhs", "rhs",
                  86);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs86), "lhs", "lhs",
                  86);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"), "context",
                  "context", 87);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 87);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 87);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 87);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1372583160U), "fileTimeLo",
                  "fileTimeLo", 87);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 87);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 87);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 87);
  sf_mex_assign(&c8_rhs87, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs87, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs87), "rhs", "rhs",
                  87);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs87), "lhs", "lhs",
                  87);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(""), "context", "context", 88);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("eye"), "name", "name", 88);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 88);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m"), "resolved",
                  "resolved", 88);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1406813148U), "fileTimeLo",
                  "fileTimeLo", 88);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 88);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 88);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 88);
  sf_mex_assign(&c8_rhs88, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs88, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs88), "rhs", "rhs",
                  88);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs88), "lhs", "lhs",
                  88);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m"), "context",
                  "context", 89);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("eml_assert_valid_size_arg"),
                  "name", "name", 89);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 89);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m"),
                  "resolved", "resolved", 89);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1368183030U), "fileTimeLo",
                  "fileTimeLo", 89);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 89);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 89);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 89);
  sf_mex_assign(&c8_rhs89, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs89, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs89), "rhs", "rhs",
                  89);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs89), "lhs", "lhs",
                  89);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m"),
                  "context", "context", 90);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 90);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 90);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 90);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1395931856U), "fileTimeLo",
                  "fileTimeLo", 90);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 90);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 90);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 90);
  sf_mex_assign(&c8_rhs90, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs90, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs90), "rhs", "rhs",
                  90);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs90), "lhs", "lhs",
                  90);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isintegral"),
                  "context", "context", 91);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("isinf"), "name", "name", 91);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 91);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m"), "resolved",
                  "resolved", 91);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1363713856U), "fileTimeLo",
                  "fileTimeLo", 91);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 91);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 91);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 91);
  sf_mex_assign(&c8_rhs91, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs91, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs91), "rhs", "rhs",
                  91);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs91), "lhs", "lhs",
                  91);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m"), "context",
                  "context", 92);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 92);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 92);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 92);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1395931856U), "fileTimeLo",
                  "fileTimeLo", 92);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 92);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 92);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 92);
  sf_mex_assign(&c8_rhs92, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs92, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs92), "rhs", "rhs",
                  92);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs92), "lhs", "lhs",
                  92);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isinbounds"),
                  "context", "context", 93);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("eml_is_integer_class"), "name",
                  "name", 93);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 93);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_integer_class.m"),
                  "resolved", "resolved", 93);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1286818782U), "fileTimeLo",
                  "fileTimeLo", 93);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 93);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 93);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 93);
  sf_mex_assign(&c8_rhs93, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs93, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs93), "rhs", "rhs",
                  93);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs93), "lhs", "lhs",
                  93);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isinbounds"),
                  "context", "context", 94);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("intmax"), "name", "name", 94);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 94);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 94);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1362261882U), "fileTimeLo",
                  "fileTimeLo", 94);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 94);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 94);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 94);
  sf_mex_assign(&c8_rhs94, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs94, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs94), "rhs", "rhs",
                  94);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs94), "lhs", "lhs",
                  94);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isinbounds"),
                  "context", "context", 95);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("intmin"), "name", "name", 95);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 95);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 95);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1362261882U), "fileTimeLo",
                  "fileTimeLo", 95);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 95);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 95);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 95);
  sf_mex_assign(&c8_rhs95, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs95, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs95), "rhs", "rhs",
                  95);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs95), "lhs", "lhs",
                  95);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isinbounds"),
                  "context", "context", 96);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("coder.internal.indexIntRelop"),
                  "name", "name", 96);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 96);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m"),
                  "resolved", "resolved", 96);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1326728322U), "fileTimeLo",
                  "fileTimeLo", 96);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 96);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 96);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 96);
  sf_mex_assign(&c8_rhs96, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs96, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs96), "rhs", "rhs",
                  96);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs96), "lhs", "lhs",
                  96);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m!apply_float_relop"),
                  "context", "context", 97);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 97);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 97);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 97);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1393330858U), "fileTimeLo",
                  "fileTimeLo", 97);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 97);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 97);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 97);
  sf_mex_assign(&c8_rhs97, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs97, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs97), "rhs", "rhs",
                  97);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs97), "lhs", "lhs",
                  97);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m!float_class_contains_indexIntClass"),
                  "context", "context", 98);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("eml_float_model"), "name",
                  "name", 98);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 98);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                  "resolved", "resolved", 98);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1326727996U), "fileTimeLo",
                  "fileTimeLo", 98);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 98);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 98);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 98);
  sf_mex_assign(&c8_rhs98, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs98, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs98), "rhs", "rhs",
                  98);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs98), "lhs", "lhs",
                  98);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m!is_signed_indexIntClass"),
                  "context", "context", 99);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("intmin"), "name", "name", 99);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 99);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 99);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1362261882U), "fileTimeLo",
                  "fileTimeLo", 99);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 99);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 99);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 99);
  sf_mex_assign(&c8_rhs99, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs99, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs99), "rhs", "rhs",
                  99);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs99), "lhs", "lhs",
                  99);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m"),
                  "context", "context", 100);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 100);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 100);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 100);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 100);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 100);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 100);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 100);
  sf_mex_assign(&c8_rhs100, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs100, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs100), "rhs", "rhs",
                  100);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs100), "lhs", "lhs",
                  100);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m"),
                  "context", "context", 101);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("intmax"), "name", "name", 101);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 101);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 101);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1362261882U), "fileTimeLo",
                  "fileTimeLo", 101);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 101);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 101);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 101);
  sf_mex_assign(&c8_rhs101, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs101, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs101), "rhs", "rhs",
                  101);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs101), "lhs", "lhs",
                  101);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m"), "context",
                  "context", 102);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 102);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 102);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 102);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1397257422U), "fileTimeLo",
                  "fileTimeLo", 102);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 102);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 102);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 102);
  sf_mex_assign(&c8_rhs102, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs102, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs102), "rhs", "rhs",
                  102);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs102), "lhs", "lhs",
                  102);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(""), "context", "context", 103);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("eml_mtimes_helper"), "name",
                  "name", 103);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 103);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "resolved", "resolved", 103);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1383877294U), "fileTimeLo",
                  "fileTimeLo", 103);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 103);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 103);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 103);
  sf_mex_assign(&c8_rhs103, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs103, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs103), "rhs", "rhs",
                  103);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs103), "lhs", "lhs",
                  103);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m!common_checks"),
                  "context", "context", 104);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 104);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 104);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 104);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1395931856U), "fileTimeLo",
                  "fileTimeLo", 104);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 104);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 104);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 104);
  sf_mex_assign(&c8_rhs104, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs104, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs104), "rhs", "rhs",
                  104);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs104), "lhs", "lhs",
                  104);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(""), "context", "context", 105);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("expm"), "name", "name", 105);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 105);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/expm.m"), "resolved",
                  "resolved", 105);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1381850304U), "fileTimeLo",
                  "fileTimeLo", 105);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 105);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 105);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 105);
  sf_mex_assign(&c8_rhs105, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs105, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs105), "rhs", "rhs",
                  105);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs105), "lhs", "lhs",
                  105);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/expm.m"), "context",
                  "context", 106);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 106);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 106);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 106);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1389717774U), "fileTimeLo",
                  "fileTimeLo", 106);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 106);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 106);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 106);
  sf_mex_assign(&c8_rhs106, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs106, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs106), "rhs", "rhs",
                  106);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs106), "lhs", "lhs",
                  106);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/expm.m"), "context",
                  "context", 107);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("ismatrix"), "name", "name",
                  107);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 107);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/ismatrix.m"), "resolved",
                  "resolved", 107);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1331304858U), "fileTimeLo",
                  "fileTimeLo", 107);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 107);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 107);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 107);
  sf_mex_assign(&c8_rhs107, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs107, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs107), "rhs", "rhs",
                  107);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs107), "lhs", "lhs",
                  107);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/expm.m"), "context",
                  "context", 108);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("norm"), "name", "name", 108);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 108);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m"), "resolved",
                  "resolved", 108);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1363713868U), "fileTimeLo",
                  "fileTimeLo", 108);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 108);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 108);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 108);
  sf_mex_assign(&c8_rhs108, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs108, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs108), "rhs", "rhs",
                  108);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs108), "lhs", "lhs",
                  108);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m"), "context",
                  "context", 109);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 109);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 109);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 109);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1395931856U), "fileTimeLo",
                  "fileTimeLo", 109);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 109);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 109);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 109);
  sf_mex_assign(&c8_rhs109, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs109, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs109), "rhs", "rhs",
                  109);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs109), "lhs", "lhs",
                  109);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!mat1norm"),
                  "context", "context", 110);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("abs"), "name", "name", 110);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 110);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 110);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1363713852U), "fileTimeLo",
                  "fileTimeLo", 110);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 110);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 110);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 110);
  sf_mex_assign(&c8_rhs110, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs110, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs110), "rhs", "rhs",
                  110);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs110), "lhs", "lhs",
                  110);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!mat1norm"),
                  "context", "context", 111);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("isnan"), "name", "name", 111);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 111);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved",
                  "resolved", 111);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1363713858U), "fileTimeLo",
                  "fileTimeLo", 111);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 111);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 111);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 111);
  sf_mex_assign(&c8_rhs111, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs111, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs111), "rhs", "rhs",
                  111);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs111), "lhs", "lhs",
                  111);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!mat1norm"),
                  "context", "context", 112);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("eml_guarded_nan"), "name",
                  "name", 112);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 112);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m"),
                  "resolved", "resolved", 112);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1286818776U), "fileTimeLo",
                  "fileTimeLo", 112);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 112);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 112);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 112);
  sf_mex_assign(&c8_rhs112, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs112, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs112), "rhs", "rhs",
                  112);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs112), "lhs", "lhs",
                  112);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m"),
                  "context", "context", 113);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("eml_is_float_class"), "name",
                  "name", 113);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 113);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m"),
                  "resolved", "resolved", 113);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1286818782U), "fileTimeLo",
                  "fileTimeLo", 113);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 113);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 113);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 113);
  sf_mex_assign(&c8_rhs113, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs113, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs113), "rhs", "rhs",
                  113);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs113), "lhs", "lhs",
                  113);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/expm.m!PadeApproximantOfDegree"),
                  "context", "context", 114);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("eml_mtimes_helper"), "name",
                  "name", 114);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 114);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "resolved", "resolved", 114);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1383877294U), "fileTimeLo",
                  "fileTimeLo", 114);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 114);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 114);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 114);
  sf_mex_assign(&c8_rhs114, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs114, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs114), "rhs", "rhs",
                  114);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs114), "lhs", "lhs",
                  114);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 115);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 115);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 115);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 115);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1323170578U), "fileTimeLo",
                  "fileTimeLo", 115);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 115);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 115);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 115);
  sf_mex_assign(&c8_rhs115, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs115, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs115), "rhs", "rhs",
                  115);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs115), "lhs", "lhs",
                  115);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 116);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 116);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 116);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 116);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1375980688U), "fileTimeLo",
                  "fileTimeLo", 116);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 116);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 116);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 116);
  sf_mex_assign(&c8_rhs116, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs116, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs116), "rhs", "rhs",
                  116);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs116), "lhs", "lhs",
                  116);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 117);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("eml_xgemm"), "name", "name",
                  117);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 117);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"),
                  "resolved", "resolved", 117);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1375980690U), "fileTimeLo",
                  "fileTimeLo", 117);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 117);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 117);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 117);
  sf_mex_assign(&c8_rhs117, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs117, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs117), "rhs", "rhs",
                  117);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs117), "lhs", "lhs",
                  117);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"), "context",
                  "context", 118);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("coder.internal.blas.inline"),
                  "name", "name", 118);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 118);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/inline.p"),
                  "resolved", "resolved", 118);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1410807772U), "fileTimeLo",
                  "fileTimeLo", 118);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 118);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 118);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 118);
  sf_mex_assign(&c8_rhs118, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs118, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs118), "rhs", "rhs",
                  118);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs118), "lhs", "lhs",
                  118);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"), "context",
                  "context", 119);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("coder.internal.blas.xgemm"),
                  "name", "name", 119);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 119);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "resolved", "resolved", 119);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1410807770U), "fileTimeLo",
                  "fileTimeLo", 119);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 119);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 119);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 119);
  sf_mex_assign(&c8_rhs119, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs119, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs119), "rhs", "rhs",
                  119);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs119), "lhs", "lhs",
                  119);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 120);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 120);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 120);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 120);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1410807770U), "fileTimeLo",
                  "fileTimeLo", 120);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 120);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 120);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 120);
  sf_mex_assign(&c8_rhs120, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs120, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs120), "rhs", "rhs",
                  120);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs120), "lhs", "lhs",
                  120);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p!below_threshold"),
                  "context", "context", 121);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("coder.internal.blas.threshold"),
                  "name", "name", 121);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 121);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "resolved", "resolved", 121);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1410807772U), "fileTimeLo",
                  "fileTimeLo", 121);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 121);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 121);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 121);
  sf_mex_assign(&c8_rhs121, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs121, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs121), "rhs", "rhs",
                  121);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs121), "lhs", "lhs",
                  121);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 122);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 122);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 122);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 122);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1410807770U), "fileTimeLo",
                  "fileTimeLo", 122);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 122);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 122);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 122);
  sf_mex_assign(&c8_rhs122, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs122, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs122), "rhs", "rhs",
                  122);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs122), "lhs", "lhs",
                  122);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 123);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("coder.internal.refblas.xgemm"),
                  "name", "name", 123);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 123);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xgemm.p"),
                  "resolved", "resolved", 123);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1410807772U), "fileTimeLo",
                  "fileTimeLo", 123);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 123);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 123);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 123);
  sf_mex_assign(&c8_rhs123, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs123, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs123), "rhs", "rhs",
                  123);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs123), "lhs", "lhs",
                  123);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/expm.m!PadeApproximantOfDegree"),
                  "context", "context", 124);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("mldivide"), "name", "name",
                  124);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 124);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mldivide.p"), "resolved",
                  "resolved", 124);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1410807648U), "fileTimeLo",
                  "fileTimeLo", 124);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 124);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1319729966U), "mFileTimeLo",
                  "mFileTimeLo", 124);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 124);
  sf_mex_assign(&c8_rhs124, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs124, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs124), "rhs", "rhs",
                  124);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs124), "lhs", "lhs",
                  124);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mldivide.p"), "context",
                  "context", 125);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("eml_lusolve"), "name", "name",
                  125);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 125);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m"), "resolved",
                  "resolved", 125);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1370009886U), "fileTimeLo",
                  "fileTimeLo", 125);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 125);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 125);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 125);
  sf_mex_assign(&c8_rhs125, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs125, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs125), "rhs", "rhs",
                  125);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs125), "lhs", "lhs",
                  125);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m!lusolve3x3"),
                  "context", "context", 126);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("eml_xcabs1"), "name", "name",
                  126);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 126);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xcabs1.m"),
                  "resolved", "resolved", 126);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1375980688U), "fileTimeLo",
                  "fileTimeLo", 126);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 126);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 126);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 126);
  sf_mex_assign(&c8_rhs126, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs126, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs126), "rhs", "rhs",
                  126);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs126), "lhs", "lhs",
                  126);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xcabs1.m"),
                  "context", "context", 127);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("coder.internal.refblas.xcabs1"),
                  "name", "name", 127);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 127);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xcabs1.p"),
                  "resolved", "resolved", 127);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1410807772U), "fileTimeLo",
                  "fileTimeLo", 127);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 127);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 127);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 127);
  sf_mex_assign(&c8_rhs127, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs127, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs127), "rhs", "rhs",
                  127);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs127), "lhs", "lhs",
                  127);
  sf_mex_destroy(&c8_rhs64);
  sf_mex_destroy(&c8_lhs64);
  sf_mex_destroy(&c8_rhs65);
  sf_mex_destroy(&c8_lhs65);
  sf_mex_destroy(&c8_rhs66);
  sf_mex_destroy(&c8_lhs66);
  sf_mex_destroy(&c8_rhs67);
  sf_mex_destroy(&c8_lhs67);
  sf_mex_destroy(&c8_rhs68);
  sf_mex_destroy(&c8_lhs68);
  sf_mex_destroy(&c8_rhs69);
  sf_mex_destroy(&c8_lhs69);
  sf_mex_destroy(&c8_rhs70);
  sf_mex_destroy(&c8_lhs70);
  sf_mex_destroy(&c8_rhs71);
  sf_mex_destroy(&c8_lhs71);
  sf_mex_destroy(&c8_rhs72);
  sf_mex_destroy(&c8_lhs72);
  sf_mex_destroy(&c8_rhs73);
  sf_mex_destroy(&c8_lhs73);
  sf_mex_destroy(&c8_rhs74);
  sf_mex_destroy(&c8_lhs74);
  sf_mex_destroy(&c8_rhs75);
  sf_mex_destroy(&c8_lhs75);
  sf_mex_destroy(&c8_rhs76);
  sf_mex_destroy(&c8_lhs76);
  sf_mex_destroy(&c8_rhs77);
  sf_mex_destroy(&c8_lhs77);
  sf_mex_destroy(&c8_rhs78);
  sf_mex_destroy(&c8_lhs78);
  sf_mex_destroy(&c8_rhs79);
  sf_mex_destroy(&c8_lhs79);
  sf_mex_destroy(&c8_rhs80);
  sf_mex_destroy(&c8_lhs80);
  sf_mex_destroy(&c8_rhs81);
  sf_mex_destroy(&c8_lhs81);
  sf_mex_destroy(&c8_rhs82);
  sf_mex_destroy(&c8_lhs82);
  sf_mex_destroy(&c8_rhs83);
  sf_mex_destroy(&c8_lhs83);
  sf_mex_destroy(&c8_rhs84);
  sf_mex_destroy(&c8_lhs84);
  sf_mex_destroy(&c8_rhs85);
  sf_mex_destroy(&c8_lhs85);
  sf_mex_destroy(&c8_rhs86);
  sf_mex_destroy(&c8_lhs86);
  sf_mex_destroy(&c8_rhs87);
  sf_mex_destroy(&c8_lhs87);
  sf_mex_destroy(&c8_rhs88);
  sf_mex_destroy(&c8_lhs88);
  sf_mex_destroy(&c8_rhs89);
  sf_mex_destroy(&c8_lhs89);
  sf_mex_destroy(&c8_rhs90);
  sf_mex_destroy(&c8_lhs90);
  sf_mex_destroy(&c8_rhs91);
  sf_mex_destroy(&c8_lhs91);
  sf_mex_destroy(&c8_rhs92);
  sf_mex_destroy(&c8_lhs92);
  sf_mex_destroy(&c8_rhs93);
  sf_mex_destroy(&c8_lhs93);
  sf_mex_destroy(&c8_rhs94);
  sf_mex_destroy(&c8_lhs94);
  sf_mex_destroy(&c8_rhs95);
  sf_mex_destroy(&c8_lhs95);
  sf_mex_destroy(&c8_rhs96);
  sf_mex_destroy(&c8_lhs96);
  sf_mex_destroy(&c8_rhs97);
  sf_mex_destroy(&c8_lhs97);
  sf_mex_destroy(&c8_rhs98);
  sf_mex_destroy(&c8_lhs98);
  sf_mex_destroy(&c8_rhs99);
  sf_mex_destroy(&c8_lhs99);
  sf_mex_destroy(&c8_rhs100);
  sf_mex_destroy(&c8_lhs100);
  sf_mex_destroy(&c8_rhs101);
  sf_mex_destroy(&c8_lhs101);
  sf_mex_destroy(&c8_rhs102);
  sf_mex_destroy(&c8_lhs102);
  sf_mex_destroy(&c8_rhs103);
  sf_mex_destroy(&c8_lhs103);
  sf_mex_destroy(&c8_rhs104);
  sf_mex_destroy(&c8_lhs104);
  sf_mex_destroy(&c8_rhs105);
  sf_mex_destroy(&c8_lhs105);
  sf_mex_destroy(&c8_rhs106);
  sf_mex_destroy(&c8_lhs106);
  sf_mex_destroy(&c8_rhs107);
  sf_mex_destroy(&c8_lhs107);
  sf_mex_destroy(&c8_rhs108);
  sf_mex_destroy(&c8_lhs108);
  sf_mex_destroy(&c8_rhs109);
  sf_mex_destroy(&c8_lhs109);
  sf_mex_destroy(&c8_rhs110);
  sf_mex_destroy(&c8_lhs110);
  sf_mex_destroy(&c8_rhs111);
  sf_mex_destroy(&c8_lhs111);
  sf_mex_destroy(&c8_rhs112);
  sf_mex_destroy(&c8_lhs112);
  sf_mex_destroy(&c8_rhs113);
  sf_mex_destroy(&c8_lhs113);
  sf_mex_destroy(&c8_rhs114);
  sf_mex_destroy(&c8_lhs114);
  sf_mex_destroy(&c8_rhs115);
  sf_mex_destroy(&c8_lhs115);
  sf_mex_destroy(&c8_rhs116);
  sf_mex_destroy(&c8_lhs116);
  sf_mex_destroy(&c8_rhs117);
  sf_mex_destroy(&c8_lhs117);
  sf_mex_destroy(&c8_rhs118);
  sf_mex_destroy(&c8_lhs118);
  sf_mex_destroy(&c8_rhs119);
  sf_mex_destroy(&c8_lhs119);
  sf_mex_destroy(&c8_rhs120);
  sf_mex_destroy(&c8_lhs120);
  sf_mex_destroy(&c8_rhs121);
  sf_mex_destroy(&c8_lhs121);
  sf_mex_destroy(&c8_rhs122);
  sf_mex_destroy(&c8_lhs122);
  sf_mex_destroy(&c8_rhs123);
  sf_mex_destroy(&c8_lhs123);
  sf_mex_destroy(&c8_rhs124);
  sf_mex_destroy(&c8_lhs124);
  sf_mex_destroy(&c8_rhs125);
  sf_mex_destroy(&c8_lhs125);
  sf_mex_destroy(&c8_rhs126);
  sf_mex_destroy(&c8_lhs126);
  sf_mex_destroy(&c8_rhs127);
  sf_mex_destroy(&c8_lhs127);
}

static void c8_c_info_helper(const mxArray **c8_info)
{
  const mxArray *c8_rhs128 = NULL;
  const mxArray *c8_lhs128 = NULL;
  const mxArray *c8_rhs129 = NULL;
  const mxArray *c8_lhs129 = NULL;
  const mxArray *c8_rhs130 = NULL;
  const mxArray *c8_lhs130 = NULL;
  const mxArray *c8_rhs131 = NULL;
  const mxArray *c8_lhs131 = NULL;
  const mxArray *c8_rhs132 = NULL;
  const mxArray *c8_lhs132 = NULL;
  const mxArray *c8_rhs133 = NULL;
  const mxArray *c8_lhs133 = NULL;
  const mxArray *c8_rhs134 = NULL;
  const mxArray *c8_lhs134 = NULL;
  const mxArray *c8_rhs135 = NULL;
  const mxArray *c8_lhs135 = NULL;
  const mxArray *c8_rhs136 = NULL;
  const mxArray *c8_lhs136 = NULL;
  const mxArray *c8_rhs137 = NULL;
  const mxArray *c8_lhs137 = NULL;
  const mxArray *c8_rhs138 = NULL;
  const mxArray *c8_lhs138 = NULL;
  const mxArray *c8_rhs139 = NULL;
  const mxArray *c8_lhs139 = NULL;
  const mxArray *c8_rhs140 = NULL;
  const mxArray *c8_lhs140 = NULL;
  const mxArray *c8_rhs141 = NULL;
  const mxArray *c8_lhs141 = NULL;
  const mxArray *c8_rhs142 = NULL;
  const mxArray *c8_lhs142 = NULL;
  const mxArray *c8_rhs143 = NULL;
  const mxArray *c8_lhs143 = NULL;
  const mxArray *c8_rhs144 = NULL;
  const mxArray *c8_lhs144 = NULL;
  const mxArray *c8_rhs145 = NULL;
  const mxArray *c8_lhs145 = NULL;
  const mxArray *c8_rhs146 = NULL;
  const mxArray *c8_lhs146 = NULL;
  const mxArray *c8_rhs147 = NULL;
  const mxArray *c8_lhs147 = NULL;
  const mxArray *c8_rhs148 = NULL;
  const mxArray *c8_lhs148 = NULL;
  const mxArray *c8_rhs149 = NULL;
  const mxArray *c8_lhs149 = NULL;
  const mxArray *c8_rhs150 = NULL;
  const mxArray *c8_lhs150 = NULL;
  const mxArray *c8_rhs151 = NULL;
  const mxArray *c8_lhs151 = NULL;
  const mxArray *c8_rhs152 = NULL;
  const mxArray *c8_lhs152 = NULL;
  const mxArray *c8_rhs153 = NULL;
  const mxArray *c8_lhs153 = NULL;
  const mxArray *c8_rhs154 = NULL;
  const mxArray *c8_lhs154 = NULL;
  const mxArray *c8_rhs155 = NULL;
  const mxArray *c8_lhs155 = NULL;
  const mxArray *c8_rhs156 = NULL;
  const mxArray *c8_lhs156 = NULL;
  const mxArray *c8_rhs157 = NULL;
  const mxArray *c8_lhs157 = NULL;
  const mxArray *c8_rhs158 = NULL;
  const mxArray *c8_lhs158 = NULL;
  const mxArray *c8_rhs159 = NULL;
  const mxArray *c8_lhs159 = NULL;
  const mxArray *c8_rhs160 = NULL;
  const mxArray *c8_lhs160 = NULL;
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xcabs1.p"),
                  "context", "context", 128);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("abs"), "name", "name", 128);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 128);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 128);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1363713852U), "fileTimeLo",
                  "fileTimeLo", 128);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 128);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 128);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 128);
  sf_mex_assign(&c8_rhs128, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs128, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs128), "rhs", "rhs",
                  128);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs128), "lhs", "lhs",
                  128);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m!lusolve3x3"),
                  "context", "context", 129);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("rdivide"), "name", "name", 129);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 129);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 129);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1363713880U), "fileTimeLo",
                  "fileTimeLo", 129);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 129);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 129);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 129);
  sf_mex_assign(&c8_rhs129, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs129, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs129), "rhs", "rhs",
                  129);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs129), "lhs", "lhs",
                  129);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m!warn_singular"),
                  "context", "context", 130);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("eml_warning"), "name", "name",
                  130);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 130);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_warning.m"), "resolved",
                  "resolved", 130);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1286818802U), "fileTimeLo",
                  "fileTimeLo", 130);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 130);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 130);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 130);
  sf_mex_assign(&c8_rhs130, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs130, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs130), "rhs", "rhs",
                  130);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs130), "lhs", "lhs",
                  130);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m!lusolve3x3"),
                  "context", "context", 131);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 131);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 131);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 131);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1375980688U), "fileTimeLo",
                  "fileTimeLo", 131);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 131);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 131);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 131);
  sf_mex_assign(&c8_rhs131, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs131, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs131), "rhs", "rhs",
                  131);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs131), "lhs", "lhs",
                  131);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m!lusolve3x3"),
                  "context", "context", 132);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 132);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 132);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 132);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1397257422U), "fileTimeLo",
                  "fileTimeLo", 132);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 132);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 132);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 132);
  sf_mex_assign(&c8_rhs132, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs132, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs132), "rhs", "rhs",
                  132);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs132), "lhs", "lhs",
                  132);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/expm.m"), "context",
                  "context", 133);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("log2"), "name", "name", 133);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 133);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/log2.m"), "resolved",
                  "resolved", 133);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1395328502U), "fileTimeLo",
                  "fileTimeLo", 133);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 133);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 133);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 133);
  sf_mex_assign(&c8_rhs133, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs133, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs133), "rhs", "rhs",
                  133);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs133), "lhs", "lhs",
                  133);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/log2.m!scalar_frexp"),
                  "context", "context", 134);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("isfinite"), "name", "name",
                  134);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 134);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m"), "resolved",
                  "resolved", 134);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1363713856U), "fileTimeLo",
                  "fileTimeLo", 134);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 134);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 134);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 134);
  sf_mex_assign(&c8_rhs134, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs134, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs134), "rhs", "rhs",
                  134);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs134), "lhs", "lhs",
                  134);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m"), "context",
                  "context", 135);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 135);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 135);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 135);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1395931856U), "fileTimeLo",
                  "fileTimeLo", 135);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 135);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 135);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 135);
  sf_mex_assign(&c8_rhs135, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs135, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs135), "rhs", "rhs",
                  135);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs135), "lhs", "lhs",
                  135);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m"), "context",
                  "context", 136);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("isinf"), "name", "name", 136);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 136);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m"), "resolved",
                  "resolved", 136);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1363713856U), "fileTimeLo",
                  "fileTimeLo", 136);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 136);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 136);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 136);
  sf_mex_assign(&c8_rhs136, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs136, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs136), "rhs", "rhs",
                  136);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs136), "lhs", "lhs",
                  136);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m"), "context",
                  "context", 137);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("isnan"), "name", "name", 137);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 137);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved",
                  "resolved", 137);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1363713858U), "fileTimeLo",
                  "fileTimeLo", 137);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 137);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 137);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 137);
  sf_mex_assign(&c8_rhs137, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs137, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs137), "rhs", "rhs",
                  137);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs137), "lhs", "lhs",
                  137);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/expm.m"), "context",
                  "context", 138);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("pow2"), "name", "name", 138);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 138);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/pow2.m"), "resolved",
                  "resolved", 138);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1343830382U), "fileTimeLo",
                  "fileTimeLo", 138);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 138);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 138);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 138);
  sf_mex_assign(&c8_rhs138, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs138, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs138), "rhs", "rhs",
                  138);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs138), "lhs", "lhs",
                  138);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/pow2.m"), "context",
                  "context", 139);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("eml_scalar_pow2"), "name",
                  "name", 139);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 139);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_pow2.m"),
                  "resolved", "resolved", 139);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1286818732U), "fileTimeLo",
                  "fileTimeLo", 139);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 139);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 139);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 139);
  sf_mex_assign(&c8_rhs139, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs139, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs139), "rhs", "rhs",
                  139);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs139), "lhs", "lhs",
                  139);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_pow2.m"),
                  "context", "context", 140);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("power"), "name", "name", 140);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 140);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m"), "resolved",
                  "resolved", 140);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1395328506U), "fileTimeLo",
                  "fileTimeLo", 140);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 140);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 140);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 140);
  sf_mex_assign(&c8_rhs140, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs140, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs140), "rhs", "rhs",
                  140);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs140), "lhs", "lhs",
                  140);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m"), "context",
                  "context", 141);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 141);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 141);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 141);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1395931856U), "fileTimeLo",
                  "fileTimeLo", 141);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 141);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 141);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 141);
  sf_mex_assign(&c8_rhs141, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs141, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs141), "rhs", "rhs",
                  141);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs141), "lhs", "lhs",
                  141);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 142);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 142);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 142);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 142);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1375980688U), "fileTimeLo",
                  "fileTimeLo", 142);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 142);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 142);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 142);
  sf_mex_assign(&c8_rhs142, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs142, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs142), "rhs", "rhs",
                  142);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs142), "lhs", "lhs",
                  142);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 143);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 143);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 143);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 143);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1375980688U), "fileTimeLo",
                  "fileTimeLo", 143);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 143);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 143);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 143);
  sf_mex_assign(&c8_rhs143, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs143, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs143), "rhs", "rhs",
                  143);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs143), "lhs", "lhs",
                  143);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "context", "context", 144);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("coder.internal.scalexpAlloc"),
                  "name", "name", 144);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 144);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalexpAlloc.p"),
                  "resolved", "resolved", 144);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1410807770U), "fileTimeLo",
                  "fileTimeLo", 144);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 144);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 144);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 144);
  sf_mex_assign(&c8_rhs144, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs144, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs144), "rhs", "rhs",
                  144);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs144), "lhs", "lhs",
                  144);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 145);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("floor"), "name", "name", 145);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 145);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 145);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1363713854U), "fileTimeLo",
                  "fileTimeLo", 145);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 145);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 145);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 145);
  sf_mex_assign(&c8_rhs145, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs145, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs145), "rhs", "rhs",
                  145);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs145), "lhs", "lhs",
                  145);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 146);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("eml_error"), "name", "name",
                  146);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 146);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m"), "resolved",
                  "resolved", 146);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1343830358U), "fileTimeLo",
                  "fileTimeLo", 146);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 146);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 146);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 146);
  sf_mex_assign(&c8_rhs146, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs146, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs146), "rhs", "rhs",
                  146);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs146), "lhs", "lhs",
                  146);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!scalar_float_power"),
                  "context", "context", 147);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 147);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 147);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 147);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1375980688U), "fileTimeLo",
                  "fileTimeLo", 147);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 147);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 147);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 147);
  sf_mex_assign(&c8_rhs147, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs147, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs147), "rhs", "rhs",
                  147);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs147), "lhs", "lhs",
                  147);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/expm.m"), "context",
                  "context", 148);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("eml_div"), "name", "name", 148);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 148);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 148);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1386423952U), "fileTimeLo",
                  "fileTimeLo", 148);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 148);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 148);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 148);
  sf_mex_assign(&c8_rhs148, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs148, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs148), "rhs", "rhs",
                  148);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs148), "lhs", "lhs",
                  148);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/expm.m"), "context",
                  "context", 149);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("eml_mtimes_helper"), "name",
                  "name", 149);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 149);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "resolved", "resolved", 149);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1383877294U), "fileTimeLo",
                  "fileTimeLo", 149);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 149);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 149);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 149);
  sf_mex_assign(&c8_rhs149, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs149, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs149), "rhs", "rhs",
                  149);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs149), "lhs", "lhs",
                  149);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(""), "context", "context", 150);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("atan2"), "name", "name", 150);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 150);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan2.m"), "resolved",
                  "resolved", 150);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1395328496U), "fileTimeLo",
                  "fileTimeLo", 150);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 150);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 150);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 150);
  sf_mex_assign(&c8_rhs150, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs150, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs150), "rhs", "rhs",
                  150);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs150), "lhs", "lhs",
                  150);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan2.m"), "context",
                  "context", 151);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 151);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 151);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 151);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1375980688U), "fileTimeLo",
                  "fileTimeLo", 151);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 151);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 151);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 151);
  sf_mex_assign(&c8_rhs151, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs151, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs151), "rhs", "rhs",
                  151);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs151), "lhs", "lhs",
                  151);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan2.m"), "context",
                  "context", 152);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 152);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 152);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 152);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1375980688U), "fileTimeLo",
                  "fileTimeLo", 152);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 152);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 152);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 152);
  sf_mex_assign(&c8_rhs152, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs152, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs152), "rhs", "rhs",
                  152);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs152), "lhs", "lhs",
                  152);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan2.m"), "context",
                  "context", 153);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("eml_scalar_atan2"), "name",
                  "name", 153);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 153);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_atan2.m"),
                  "resolved", "resolved", 153);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1286818720U), "fileTimeLo",
                  "fileTimeLo", 153);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 153);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 153);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 153);
  sf_mex_assign(&c8_rhs153, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs153, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs153), "rhs", "rhs",
                  153);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs153), "lhs", "lhs",
                  153);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(""), "context", "context", 154);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("mpower"), "name", "name", 154);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 154);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "resolved",
                  "resolved", 154);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1363713878U), "fileTimeLo",
                  "fileTimeLo", 154);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 154);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 154);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 154);
  sf_mex_assign(&c8_rhs154, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs154, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs154), "rhs", "rhs",
                  154);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs154), "lhs", "lhs",
                  154);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 155);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 155);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 155);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 155);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1395931856U), "fileTimeLo",
                  "fileTimeLo", 155);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 155);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 155);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 155);
  sf_mex_assign(&c8_rhs155, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs155, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs155), "rhs", "rhs",
                  155);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs155), "lhs", "lhs",
                  155);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 156);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("ismatrix"), "name", "name",
                  156);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 156);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/ismatrix.m"), "resolved",
                  "resolved", 156);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1331304858U), "fileTimeLo",
                  "fileTimeLo", 156);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 156);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 156);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 156);
  sf_mex_assign(&c8_rhs156, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs156, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs156), "rhs", "rhs",
                  156);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs156), "lhs", "lhs",
                  156);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 157);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("power"), "name", "name", 157);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 157);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m"), "resolved",
                  "resolved", 157);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1395328506U), "fileTimeLo",
                  "fileTimeLo", 157);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 157);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 157);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 157);
  sf_mex_assign(&c8_rhs157, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs157, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs157), "rhs", "rhs",
                  157);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs157), "lhs", "lhs",
                  157);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(""), "context", "context", 158);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("sqrt"), "name", "name", 158);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 158);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m"), "resolved",
                  "resolved", 158);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1343830386U), "fileTimeLo",
                  "fileTimeLo", 158);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 158);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 158);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 158);
  sf_mex_assign(&c8_rhs158, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs158, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs158), "rhs", "rhs",
                  158);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs158), "lhs", "lhs",
                  158);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m"), "context",
                  "context", 159);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("eml_error"), "name", "name",
                  159);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 159);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m"), "resolved",
                  "resolved", 159);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1343830358U), "fileTimeLo",
                  "fileTimeLo", 159);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 159);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 159);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 159);
  sf_mex_assign(&c8_rhs159, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs159, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs159), "rhs", "rhs",
                  159);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs159), "lhs", "lhs",
                  159);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m"), "context",
                  "context", 160);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("eml_scalar_sqrt"), "name",
                  "name", 160);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 160);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m"),
                  "resolved", "resolved", 160);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1286818738U), "fileTimeLo",
                  "fileTimeLo", 160);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 160);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 160);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 160);
  sf_mex_assign(&c8_rhs160, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs160, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs160), "rhs", "rhs",
                  160);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs160), "lhs", "lhs",
                  160);
  sf_mex_destroy(&c8_rhs128);
  sf_mex_destroy(&c8_lhs128);
  sf_mex_destroy(&c8_rhs129);
  sf_mex_destroy(&c8_lhs129);
  sf_mex_destroy(&c8_rhs130);
  sf_mex_destroy(&c8_lhs130);
  sf_mex_destroy(&c8_rhs131);
  sf_mex_destroy(&c8_lhs131);
  sf_mex_destroy(&c8_rhs132);
  sf_mex_destroy(&c8_lhs132);
  sf_mex_destroy(&c8_rhs133);
  sf_mex_destroy(&c8_lhs133);
  sf_mex_destroy(&c8_rhs134);
  sf_mex_destroy(&c8_lhs134);
  sf_mex_destroy(&c8_rhs135);
  sf_mex_destroy(&c8_lhs135);
  sf_mex_destroy(&c8_rhs136);
  sf_mex_destroy(&c8_lhs136);
  sf_mex_destroy(&c8_rhs137);
  sf_mex_destroy(&c8_lhs137);
  sf_mex_destroy(&c8_rhs138);
  sf_mex_destroy(&c8_lhs138);
  sf_mex_destroy(&c8_rhs139);
  sf_mex_destroy(&c8_lhs139);
  sf_mex_destroy(&c8_rhs140);
  sf_mex_destroy(&c8_lhs140);
  sf_mex_destroy(&c8_rhs141);
  sf_mex_destroy(&c8_lhs141);
  sf_mex_destroy(&c8_rhs142);
  sf_mex_destroy(&c8_lhs142);
  sf_mex_destroy(&c8_rhs143);
  sf_mex_destroy(&c8_lhs143);
  sf_mex_destroy(&c8_rhs144);
  sf_mex_destroy(&c8_lhs144);
  sf_mex_destroy(&c8_rhs145);
  sf_mex_destroy(&c8_lhs145);
  sf_mex_destroy(&c8_rhs146);
  sf_mex_destroy(&c8_lhs146);
  sf_mex_destroy(&c8_rhs147);
  sf_mex_destroy(&c8_lhs147);
  sf_mex_destroy(&c8_rhs148);
  sf_mex_destroy(&c8_lhs148);
  sf_mex_destroy(&c8_rhs149);
  sf_mex_destroy(&c8_lhs149);
  sf_mex_destroy(&c8_rhs150);
  sf_mex_destroy(&c8_lhs150);
  sf_mex_destroy(&c8_rhs151);
  sf_mex_destroy(&c8_lhs151);
  sf_mex_destroy(&c8_rhs152);
  sf_mex_destroy(&c8_lhs152);
  sf_mex_destroy(&c8_rhs153);
  sf_mex_destroy(&c8_lhs153);
  sf_mex_destroy(&c8_rhs154);
  sf_mex_destroy(&c8_lhs154);
  sf_mex_destroy(&c8_rhs155);
  sf_mex_destroy(&c8_lhs155);
  sf_mex_destroy(&c8_rhs156);
  sf_mex_destroy(&c8_lhs156);
  sf_mex_destroy(&c8_rhs157);
  sf_mex_destroy(&c8_lhs157);
  sf_mex_destroy(&c8_rhs158);
  sf_mex_destroy(&c8_lhs158);
  sf_mex_destroy(&c8_rhs159);
  sf_mex_destroy(&c8_lhs159);
  sf_mex_destroy(&c8_rhs160);
  sf_mex_destroy(&c8_lhs160);
}

static real_T c8_rdivide
  (SFc8_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance,
   real_T c8_x, real_T c8_y)
{
  real_T c8_b_x;
  real_T c8_b_y;
  real_T c8_c_x;
  real_T c8_c_y;
  (void)chartInstance;
  c8_b_x = c8_x;
  c8_b_y = c8_y;
  c8_c_x = c8_b_x;
  c8_c_y = c8_b_y;
  return c8_c_x / c8_c_y;
}

static void c8_cross(SFc8_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct
                     *chartInstance, real_T c8_a[3], real_T c8_b[3], real_T
                     c8_c[3])
{
  real_T c8_c1;
  real_T c8_c2;
  real_T c8_c3;
  (void)chartInstance;
  c8_c1 = c8_a[1] * c8_b[2] - c8_a[2] * c8_b[1];
  c8_c2 = c8_a[2] * c8_b[0] - c8_a[0] * c8_b[2];
  c8_c3 = c8_a[0] * c8_b[1] - c8_a[1] * c8_b[0];
  c8_c[0] = c8_c1;
  c8_c[1] = c8_c2;
  c8_c[2] = c8_c3;
}

static real_T c8_norm(SFc8_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *
                      chartInstance, real_T c8_x[3])
{
  real_T c8_y;
  real_T c8_scale;
  int32_T c8_k;
  int32_T c8_b_k;
  real_T c8_b_x;
  real_T c8_c_x;
  real_T c8_absxk;
  real_T c8_t;
  c8_below_threshold(chartInstance);
  c8_y = 0.0;
  c8_scale = 2.2250738585072014E-308;
  c8_eml_switch_helper(chartInstance);
  for (c8_k = 1; c8_k < 4; c8_k++) {
    c8_b_k = c8_k - 1;
    c8_b_x = c8_x[c8_b_k];
    c8_c_x = c8_b_x;
    c8_absxk = muDoubleScalarAbs(c8_c_x);
    if (c8_absxk > c8_scale) {
      c8_t = c8_scale / c8_absxk;
      c8_y = 1.0 + c8_y * c8_t * c8_t;
      c8_scale = c8_absxk;
    } else {
      c8_t = c8_absxk / c8_scale;
      c8_y += c8_t * c8_t;
    }
  }

  return c8_scale * muDoubleScalarSqrt(c8_y);
}

static void c8_below_threshold
  (SFc8_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c8_eml_switch_helper
  (SFc8_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static real_T c8_dot(SFc8_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct
                     *chartInstance, real_T c8_a[3], real_T c8_b[3])
{
  int32_T c8_i52;
  real_T c8_b_a[3];
  int32_T c8_i53;
  real_T c8_b_b[3];
  for (c8_i52 = 0; c8_i52 < 3; c8_i52++) {
    c8_b_a[c8_i52] = c8_a[c8_i52];
  }

  for (c8_i53 = 0; c8_i53 < 3; c8_i53++) {
    c8_b_b[c8_i53] = c8_b[c8_i53];
  }

  return c8_eml_xdotc(chartInstance, c8_b_a, c8_b_b);
}

static real_T c8_eml_xdotc
  (SFc8_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance,
   real_T c8_x[3], real_T c8_y[3])
{
  real_T c8_d;
  int32_T c8_k;
  int32_T c8_b_k;
  c8_d = 0.0;
  c8_eml_switch_helper(chartInstance);
  for (c8_k = 1; c8_k < 4; c8_k++) {
    c8_b_k = c8_k - 1;
    c8_d += c8_x[c8_b_k] * c8_y[c8_b_k];
  }

  return c8_d;
}

static real_T c8_acos(SFc8_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *
                      chartInstance, real_T c8_x)
{
  real_T c8_b_x;
  c8_b_x = c8_x;
  c8_b_acos(chartInstance, &c8_b_x);
  return c8_b_x;
}

static void c8_eml_error
  (SFc8_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance)
{
  int32_T c8_i54;
  static char_T c8_cv0[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'E', 'l', 'F', 'u', 'n', 'D', 'o', 'm', 'a', 'i', 'n',
    'E', 'r', 'r', 'o', 'r' };

  char_T c8_b_u[30];
  const mxArray *c8_y = NULL;
  int32_T c8_i55;
  static char_T c8_cv1[4] = { 'a', 'c', 'o', 's' };

  char_T c8_c_u[4];
  const mxArray *c8_b_y = NULL;
  (void)chartInstance;
  for (c8_i54 = 0; c8_i54 < 30; c8_i54++) {
    c8_b_u[c8_i54] = c8_cv0[c8_i54];
  }

  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_b_u, 10, 0U, 1U, 0U, 2, 1, 30),
                false);
  for (c8_i55 = 0; c8_i55 < 4; c8_i55++) {
    c8_c_u[c8_i55] = c8_cv1[c8_i55];
  }

  c8_b_y = NULL;
  sf_mex_assign(&c8_b_y, sf_mex_create("y", c8_c_u, 10, 0U, 1U, 0U, 2, 1, 4),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    2U, 14, c8_y, 14, c8_b_y));
}

static void c8_eye(SFc8_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct
                   *chartInstance, real_T c8_I[9])
{
  int32_T c8_i56;
  int32_T c8_k;
  int32_T c8_b_k;
  for (c8_i56 = 0; c8_i56 < 9; c8_i56++) {
    c8_I[c8_i56] = 0.0;
  }

  c8_eml_switch_helper(chartInstance);
  for (c8_k = 1; c8_k < 4; c8_k++) {
    c8_b_k = c8_k - 1;
    c8_I[c8_b_k + 3 * c8_b_k] = 1.0;
  }
}

static void c8_expm(SFc8_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct
                    *chartInstance, real_T c8_A[9], real_T c8_F[9])
{
  real_T c8_normA;
  int32_T c8_j;
  real_T c8_b_j;
  real_T c8_s;
  int32_T c8_i;
  real_T c8_b_i;
  real_T c8_x;
  real_T c8_b_x;
  real_T c8_y;
  real_T c8_c_x;
  boolean_T c8_b;
  int32_T c8_c_i;
  real_T c8_d_i;
  static real_T c8_theta[5] = { 0.01495585217958292, 0.253939833006323,
    0.95041789961629319, 2.097847961257068, 5.3719203511481517 };

  int32_T c8_i57;
  real_T c8_b_A[9];
  static real_T c8_dv8[5] = { 3.0, 5.0, 7.0, 9.0, 13.0 };

  real_T c8_d_x;
  real_T c8_e_x;
  real_T c8_f_x;
  real_T c8_g_x;
  boolean_T c8_b_b;
  boolean_T c8_b0;
  real_T c8_h_x;
  boolean_T c8_c_b;
  boolean_T c8_b1;
  boolean_T c8_d_b;
  int32_T c8_eint;
  real_T c8_fdbl;
  int32_T c8_b_eint;
  real_T c8_b_fdbl;
  int32_T c8_c_eint;
  real_T c8_d5;
  real_T c8_d6;
  real_T c8_t;
  real_T c8_b_s;
  real_T c8_b_t;
  real_T c8_c_s;
  real_T c8_a;
  real_T c8_b_a;
  real_T c8_e_b;
  real_T c8_f_b;
  real_T c8_bk;
  real_T c8_g_b;
  real_T c8_br;
  real_T c8_b_y;
  real_T c8_c_y;
  real_T c8_d_y;
  int32_T c8_i58;
  int32_T c8_i59;
  real_T c8_c_A[9];
  real_T c8_d_s;
  int32_T c8_i60;
  int32_T c8_c_j;
  int32_T c8_i61;
  real_T c8_c_a[9];
  int32_T c8_i62;
  int32_T c8_i63;
  real_T c8_d_a[9];
  int32_T c8_i64;
  real_T c8_e_a[9];
  boolean_T exitg1;
  boolean_T exitg2;
  c8_normA = 0.0;
  c8_j = 0;
  exitg2 = false;
  while ((exitg2 == false) && (c8_j < 3)) {
    c8_b_j = 1.0 + (real_T)c8_j;
    c8_s = 0.0;
    for (c8_i = 0; c8_i < 3; c8_i++) {
      c8_b_i = 1.0 + (real_T)c8_i;
      c8_x = c8_A[((int32_T)c8_b_i + 3 * ((int32_T)c8_b_j - 1)) - 1];
      c8_b_x = c8_x;
      c8_y = muDoubleScalarAbs(c8_b_x);
      c8_s += c8_y;
    }

    c8_c_x = c8_s;
    c8_b = muDoubleScalarIsNaN(c8_c_x);
    if (c8_b) {
      c8_normA = rtNaN;
      exitg2 = true;
    } else {
      if (c8_s > c8_normA) {
        c8_normA = c8_s;
      }

      c8_j++;
    }
  }

  if (c8_normA <= 5.3719203511481517) {
    c8_c_i = 0;
    exitg1 = false;
    while ((exitg1 == false) && (c8_c_i < 5)) {
      c8_d_i = 1.0 + (real_T)c8_c_i;
      if (c8_normA <= c8_theta[(int32_T)c8_d_i - 1]) {
        for (c8_i57 = 0; c8_i57 < 9; c8_i57++) {
          c8_b_A[c8_i57] = c8_A[c8_i57];
        }

        c8_PadeApproximantOfDegree(chartInstance, c8_b_A, c8_dv8[(int32_T)c8_d_i
          - 1], c8_F);
        exitg1 = true;
      } else {
        c8_c_i++;
      }
    }
  } else {
    c8_d_x = c8_normA / 5.3719203511481517;
    c8_e_x = c8_d_x;
    c8_f_x = c8_e_x;
    c8_g_x = c8_f_x;
    c8_b_b = muDoubleScalarIsInf(c8_g_x);
    c8_b0 = !c8_b_b;
    c8_h_x = c8_f_x;
    c8_c_b = muDoubleScalarIsNaN(c8_h_x);
    c8_b1 = !c8_c_b;
    c8_d_b = (c8_b0 && c8_b1);
    if (c8_d_b) {
      c8_fdbl = frexp(c8_e_x, &c8_eint);
      c8_b_eint = c8_eint;
      c8_b_fdbl = c8_fdbl;
      c8_c_eint = c8_b_eint;
      c8_d5 = c8_b_fdbl;
      c8_d6 = (real_T)c8_c_eint;
    } else {
      c8_d5 = c8_e_x;
      c8_d6 = 0.0;
    }

    c8_t = c8_d5;
    c8_b_s = c8_d6;
    c8_b_t = c8_t;
    c8_c_s = c8_b_s;
    if (c8_b_t == 0.5) {
      c8_c_s--;
    }

    c8_a = c8_c_s;
    c8_b_a = c8_a;
    c8_e_b = c8_b_a;
    c8_f_b = c8_e_b;
    c8_b_eml_scalar_eg(chartInstance);
    c8_bk = c8_f_b;
    c8_g_b = c8_bk;
    c8_b_eml_scalar_eg(chartInstance);
    c8_br = c8_g_b;
    c8_b_y = muDoubleScalarPower(2.0, c8_br);
    c8_c_y = c8_b_y;
    c8_d_y = c8_c_y;
    for (c8_i58 = 0; c8_i58 < 9; c8_i58++) {
      c8_A[c8_i58] /= c8_d_y;
    }

    for (c8_i59 = 0; c8_i59 < 9; c8_i59++) {
      c8_c_A[c8_i59] = c8_A[c8_i59];
    }

    c8_PadeApproximantOfDegree(chartInstance, c8_c_A, 13.0, c8_F);
    c8_d_s = c8_c_s;
    c8_i60 = (int32_T)c8_d_s;
    _SFD_FOR_LOOP_VECTOR_CHECK(1.0, 1.0, c8_d_s, mxDOUBLE_CLASS, c8_i60);
    for (c8_c_j = 0; c8_c_j < c8_i60; c8_c_j++) {
      for (c8_i61 = 0; c8_i61 < 9; c8_i61++) {
        c8_c_a[c8_i61] = c8_F[c8_i61];
      }

      c8_eml_scalar_eg(chartInstance);
      c8_eml_scalar_eg(chartInstance);
      for (c8_i62 = 0; c8_i62 < 9; c8_i62++) {
        c8_F[c8_i62] = 0.0;
      }

      for (c8_i63 = 0; c8_i63 < 9; c8_i63++) {
        c8_d_a[c8_i63] = c8_c_a[c8_i63];
      }

      for (c8_i64 = 0; c8_i64 < 9; c8_i64++) {
        c8_e_a[c8_i64] = c8_c_a[c8_i64];
      }

      c8_b_eml_xgemm(chartInstance, c8_d_a, c8_e_a, c8_F);
    }
  }
}

static void c8_PadeApproximantOfDegree
  (SFc8_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance,
   real_T c8_A[9], real_T c8_m, real_T c8_F[9])
{
  int32_T c8_i65;
  real_T c8_A2[9];
  int32_T c8_i66;
  real_T c8_b_A[9];
  int32_T c8_i67;
  real_T c8_c_A[9];
  int32_T c8_i68;
  real_T c8_U[9];
  int32_T c8_k;
  real_T c8_b_k;
  int32_T c8_i69;
  real_T c8_y[9];
  int32_T c8_i70;
  int32_T c8_i71;
  real_T c8_d_A[9];
  int32_T c8_i72;
  real_T c8_b_y[9];
  int32_T c8_i73;
  real_T c8_V[9];
  real_T c8_d;
  int32_T c8_i74;
  real_T c8_A3[9];
  int32_T c8_i75;
  real_T c8_b_A2[9];
  int32_T c8_i76;
  real_T c8_c_A2[9];
  int32_T c8_i77;
  int32_T c8_i78;
  int32_T c8_c_k;
  int32_T c8_i79;
  int32_T c8_i80;
  int32_T c8_i81;
  real_T c8_e_A[9];
  int32_T c8_i82;
  real_T c8_c_y[9];
  int32_T c8_i83;
  int32_T c8_i84;
  int32_T c8_i85;
  int32_T c8_i86;
  real_T c8_A4[9];
  int32_T c8_i87;
  real_T c8_b_A3[9];
  int32_T c8_i88;
  real_T c8_d_A2[9];
  int32_T c8_i89;
  int32_T c8_i90;
  real_T c8_d_y[9];
  int32_T c8_i91;
  int32_T c8_d_k;
  int32_T c8_i92;
  int32_T c8_i93;
  int32_T c8_i94;
  real_T c8_f_A[9];
  int32_T c8_i95;
  real_T c8_e_y[9];
  int32_T c8_i96;
  int32_T c8_i97;
  int32_T c8_i98;
  int32_T c8_i99;
  int32_T c8_i100;
  int32_T c8_i101;
  real_T c8_b_A4[9];
  int32_T c8_i102;
  real_T c8_e_A2[9];
  int32_T c8_i103;
  int32_T c8_i104;
  int32_T c8_i105;
  real_T c8_f_y[9];
  int32_T c8_i106;
  int32_T c8_e_k;
  int32_T c8_i107;
  int32_T c8_i108;
  int32_T c8_i109;
  real_T c8_g_A[9];
  int32_T c8_i110;
  real_T c8_g_y[9];
  int32_T c8_i111;
  int32_T c8_i112;
  int32_T c8_i113;
  int32_T c8_i114;
  int32_T c8_i115;
  int32_T c8_i116;
  int32_T c8_i117;
  int32_T c8_i118;
  int32_T c8_i119;
  int32_T c8_f_k;
  int32_T c8_i120;
  int32_T c8_i121;
  int32_T c8_i122;
  int32_T c8_i123;
  int32_T c8_i124;
  real_T c8_c_A4[9];
  int32_T c8_i125;
  real_T c8_h_y[9];
  int32_T c8_i126;
  int32_T c8_i127;
  int32_T c8_i128;
  real_T c8_h_A[9];
  int32_T c8_i129;
  real_T c8_i_y[9];
  int32_T c8_i130;
  int32_T c8_i131;
  int32_T c8_i132;
  int32_T c8_i133;
  int32_T c8_i134;
  int32_T c8_i135;
  real_T c8_d_A4[9];
  int32_T c8_i136;
  real_T c8_j_y[9];
  int32_T c8_i137;
  int32_T c8_i138;
  int32_T c8_i139;
  int32_T c8_i140;
  int32_T c8_g_k;
  int32_T c8_h_k;
  real_T c8_uk;
  int32_T c8_i141;
  real_T c8_b_U[9];
  int32_T c8_i142;
  real_T c8_b_V[9];
  c8_eml_scalar_eg(chartInstance);
  c8_eml_scalar_eg(chartInstance);
  for (c8_i65 = 0; c8_i65 < 9; c8_i65++) {
    c8_A2[c8_i65] = 0.0;
  }

  for (c8_i66 = 0; c8_i66 < 9; c8_i66++) {
    c8_b_A[c8_i66] = c8_A[c8_i66];
  }

  for (c8_i67 = 0; c8_i67 < 9; c8_i67++) {
    c8_c_A[c8_i67] = c8_A[c8_i67];
  }

  c8_b_eml_xgemm(chartInstance, c8_b_A, c8_c_A, c8_A2);
  if (c8_m == 3.0) {
    for (c8_i68 = 0; c8_i68 < 9; c8_i68++) {
      c8_U[c8_i68] = c8_A2[c8_i68];
    }

    for (c8_k = 0; c8_k < 3; c8_k++) {
      c8_b_k = 1.0 + (real_T)c8_k;
      c8_U[((int32_T)c8_b_k + 3 * ((int32_T)c8_b_k - 1)) - 1] += 60.0;
    }

    for (c8_i69 = 0; c8_i69 < 9; c8_i69++) {
      c8_y[c8_i69] = c8_U[c8_i69];
    }

    c8_eml_scalar_eg(chartInstance);
    c8_eml_scalar_eg(chartInstance);
    for (c8_i70 = 0; c8_i70 < 9; c8_i70++) {
      c8_U[c8_i70] = 0.0;
    }

    for (c8_i71 = 0; c8_i71 < 9; c8_i71++) {
      c8_d_A[c8_i71] = c8_A[c8_i71];
    }

    for (c8_i72 = 0; c8_i72 < 9; c8_i72++) {
      c8_b_y[c8_i72] = c8_y[c8_i72];
    }

    c8_b_eml_xgemm(chartInstance, c8_d_A, c8_b_y, c8_U);
    for (c8_i73 = 0; c8_i73 < 9; c8_i73++) {
      c8_V[c8_i73] = 12.0 * c8_A2[c8_i73];
    }

    c8_d = 120.0;
  } else {
    c8_eml_scalar_eg(chartInstance);
    c8_eml_scalar_eg(chartInstance);
    for (c8_i74 = 0; c8_i74 < 9; c8_i74++) {
      c8_A3[c8_i74] = 0.0;
    }

    for (c8_i75 = 0; c8_i75 < 9; c8_i75++) {
      c8_b_A2[c8_i75] = c8_A2[c8_i75];
    }

    for (c8_i76 = 0; c8_i76 < 9; c8_i76++) {
      c8_c_A2[c8_i76] = c8_A2[c8_i76];
    }

    c8_b_eml_xgemm(chartInstance, c8_b_A2, c8_c_A2, c8_A3);
    if (c8_m == 5.0) {
      for (c8_i77 = 0; c8_i77 < 9; c8_i77++) {
        c8_U[c8_i77] = 420.0 * c8_A2[c8_i77];
      }

      for (c8_i78 = 0; c8_i78 < 9; c8_i78++) {
        c8_U[c8_i78] += c8_A3[c8_i78];
      }

      for (c8_c_k = 0; c8_c_k < 3; c8_c_k++) {
        c8_b_k = 1.0 + (real_T)c8_c_k;
        c8_U[((int32_T)c8_b_k + 3 * ((int32_T)c8_b_k - 1)) - 1] += 15120.0;
      }

      for (c8_i79 = 0; c8_i79 < 9; c8_i79++) {
        c8_y[c8_i79] = c8_U[c8_i79];
      }

      c8_eml_scalar_eg(chartInstance);
      c8_eml_scalar_eg(chartInstance);
      for (c8_i80 = 0; c8_i80 < 9; c8_i80++) {
        c8_U[c8_i80] = 0.0;
      }

      for (c8_i81 = 0; c8_i81 < 9; c8_i81++) {
        c8_e_A[c8_i81] = c8_A[c8_i81];
      }

      for (c8_i82 = 0; c8_i82 < 9; c8_i82++) {
        c8_c_y[c8_i82] = c8_y[c8_i82];
      }

      c8_b_eml_xgemm(chartInstance, c8_e_A, c8_c_y, c8_U);
      for (c8_i83 = 0; c8_i83 < 9; c8_i83++) {
        c8_A3[c8_i83] *= 30.0;
      }

      for (c8_i84 = 0; c8_i84 < 9; c8_i84++) {
        c8_A2[c8_i84] *= 3360.0;
      }

      for (c8_i85 = 0; c8_i85 < 9; c8_i85++) {
        c8_V[c8_i85] = c8_A3[c8_i85] + c8_A2[c8_i85];
      }

      c8_d = 30240.0;
    } else {
      c8_eml_scalar_eg(chartInstance);
      c8_eml_scalar_eg(chartInstance);
      for (c8_i86 = 0; c8_i86 < 9; c8_i86++) {
        c8_A4[c8_i86] = 0.0;
      }

      for (c8_i87 = 0; c8_i87 < 9; c8_i87++) {
        c8_b_A3[c8_i87] = c8_A3[c8_i87];
      }

      for (c8_i88 = 0; c8_i88 < 9; c8_i88++) {
        c8_d_A2[c8_i88] = c8_A2[c8_i88];
      }

      c8_b_eml_xgemm(chartInstance, c8_b_A3, c8_d_A2, c8_A4);
      if (c8_m == 7.0) {
        for (c8_i89 = 0; c8_i89 < 9; c8_i89++) {
          c8_U[c8_i89] = 1512.0 * c8_A3[c8_i89];
        }

        for (c8_i90 = 0; c8_i90 < 9; c8_i90++) {
          c8_d_y[c8_i90] = 277200.0 * c8_A2[c8_i90];
        }

        for (c8_i91 = 0; c8_i91 < 9; c8_i91++) {
          c8_U[c8_i91] = (c8_A4[c8_i91] + c8_U[c8_i91]) + c8_d_y[c8_i91];
        }

        for (c8_d_k = 0; c8_d_k < 3; c8_d_k++) {
          c8_b_k = 1.0 + (real_T)c8_d_k;
          c8_U[((int32_T)c8_b_k + 3 * ((int32_T)c8_b_k - 1)) - 1] += 8.64864E+6;
        }

        for (c8_i92 = 0; c8_i92 < 9; c8_i92++) {
          c8_y[c8_i92] = c8_U[c8_i92];
        }

        c8_eml_scalar_eg(chartInstance);
        c8_eml_scalar_eg(chartInstance);
        for (c8_i93 = 0; c8_i93 < 9; c8_i93++) {
          c8_U[c8_i93] = 0.0;
        }

        for (c8_i94 = 0; c8_i94 < 9; c8_i94++) {
          c8_f_A[c8_i94] = c8_A[c8_i94];
        }

        for (c8_i95 = 0; c8_i95 < 9; c8_i95++) {
          c8_e_y[c8_i95] = c8_y[c8_i95];
        }

        c8_b_eml_xgemm(chartInstance, c8_f_A, c8_e_y, c8_U);
        for (c8_i96 = 0; c8_i96 < 9; c8_i96++) {
          c8_A4[c8_i96] *= 56.0;
        }

        for (c8_i97 = 0; c8_i97 < 9; c8_i97++) {
          c8_A3[c8_i97] *= 25200.0;
        }

        for (c8_i98 = 0; c8_i98 < 9; c8_i98++) {
          c8_A2[c8_i98] *= 1.99584E+6;
        }

        for (c8_i99 = 0; c8_i99 < 9; c8_i99++) {
          c8_V[c8_i99] = (c8_A4[c8_i99] + c8_A3[c8_i99]) + c8_A2[c8_i99];
        }

        c8_d = 1.729728E+7;
      } else if (c8_m == 9.0) {
        c8_eml_scalar_eg(chartInstance);
        c8_eml_scalar_eg(chartInstance);
        for (c8_i100 = 0; c8_i100 < 9; c8_i100++) {
          c8_V[c8_i100] = 0.0;
        }

        for (c8_i101 = 0; c8_i101 < 9; c8_i101++) {
          c8_b_A4[c8_i101] = c8_A4[c8_i101];
        }

        for (c8_i102 = 0; c8_i102 < 9; c8_i102++) {
          c8_e_A2[c8_i102] = c8_A2[c8_i102];
        }

        c8_b_eml_xgemm(chartInstance, c8_b_A4, c8_e_A2, c8_V);
        for (c8_i103 = 0; c8_i103 < 9; c8_i103++) {
          c8_U[c8_i103] = 3960.0 * c8_A4[c8_i103];
        }

        for (c8_i104 = 0; c8_i104 < 9; c8_i104++) {
          c8_d_y[c8_i104] = 2.16216E+6 * c8_A3[c8_i104];
        }

        for (c8_i105 = 0; c8_i105 < 9; c8_i105++) {
          c8_f_y[c8_i105] = 3.027024E+8 * c8_A2[c8_i105];
        }

        for (c8_i106 = 0; c8_i106 < 9; c8_i106++) {
          c8_U[c8_i106] = ((c8_V[c8_i106] + c8_U[c8_i106]) + c8_d_y[c8_i106]) +
            c8_f_y[c8_i106];
        }

        for (c8_e_k = 0; c8_e_k < 3; c8_e_k++) {
          c8_b_k = 1.0 + (real_T)c8_e_k;
          c8_U[((int32_T)c8_b_k + 3 * ((int32_T)c8_b_k - 1)) - 1] +=
            8.8216128E+9;
        }

        for (c8_i107 = 0; c8_i107 < 9; c8_i107++) {
          c8_y[c8_i107] = c8_U[c8_i107];
        }

        c8_eml_scalar_eg(chartInstance);
        c8_eml_scalar_eg(chartInstance);
        for (c8_i108 = 0; c8_i108 < 9; c8_i108++) {
          c8_U[c8_i108] = 0.0;
        }

        for (c8_i109 = 0; c8_i109 < 9; c8_i109++) {
          c8_g_A[c8_i109] = c8_A[c8_i109];
        }

        for (c8_i110 = 0; c8_i110 < 9; c8_i110++) {
          c8_g_y[c8_i110] = c8_y[c8_i110];
        }

        c8_b_eml_xgemm(chartInstance, c8_g_A, c8_g_y, c8_U);
        for (c8_i111 = 0; c8_i111 < 9; c8_i111++) {
          c8_V[c8_i111] *= 90.0;
        }

        for (c8_i112 = 0; c8_i112 < 9; c8_i112++) {
          c8_A4[c8_i112] *= 110880.0;
        }

        for (c8_i113 = 0; c8_i113 < 9; c8_i113++) {
          c8_A3[c8_i113] *= 3.027024E+7;
        }

        for (c8_i114 = 0; c8_i114 < 9; c8_i114++) {
          c8_A2[c8_i114] *= 2.0756736E+9;
        }

        for (c8_i115 = 0; c8_i115 < 9; c8_i115++) {
          c8_V[c8_i115] = ((c8_V[c8_i115] + c8_A4[c8_i115]) + c8_A3[c8_i115]) +
            c8_A2[c8_i115];
        }

        c8_d = 1.76432256E+10;
      } else {
        for (c8_i116 = 0; c8_i116 < 9; c8_i116++) {
          c8_U[c8_i116] = 3.352212864E+10 * c8_A4[c8_i116];
        }

        for (c8_i117 = 0; c8_i117 < 9; c8_i117++) {
          c8_d_y[c8_i117] = 1.05594705216E+13 * c8_A3[c8_i117];
        }

        for (c8_i118 = 0; c8_i118 < 9; c8_i118++) {
          c8_f_y[c8_i118] = 1.1873537964288E+15 * c8_A2[c8_i118];
        }

        for (c8_i119 = 0; c8_i119 < 9; c8_i119++) {
          c8_U[c8_i119] = (c8_U[c8_i119] + c8_d_y[c8_i119]) + c8_f_y[c8_i119];
        }

        for (c8_f_k = 0; c8_f_k < 3; c8_f_k++) {
          c8_b_k = 1.0 + (real_T)c8_f_k;
          c8_U[((int32_T)c8_b_k + 3 * ((int32_T)c8_b_k - 1)) - 1] +=
            3.238237626624E+16;
        }

        for (c8_i120 = 0; c8_i120 < 9; c8_i120++) {
          c8_d_y[c8_i120] = 16380.0 * c8_A3[c8_i120];
        }

        for (c8_i121 = 0; c8_i121 < 9; c8_i121++) {
          c8_f_y[c8_i121] = 4.08408E+7 * c8_A2[c8_i121];
        }

        for (c8_i122 = 0; c8_i122 < 9; c8_i122++) {
          c8_d_y[c8_i122] = (c8_A4[c8_i122] + c8_d_y[c8_i122]) + c8_f_y[c8_i122];
        }

        c8_eml_scalar_eg(chartInstance);
        c8_eml_scalar_eg(chartInstance);
        for (c8_i123 = 0; c8_i123 < 9; c8_i123++) {
          c8_f_y[c8_i123] = 0.0;
        }

        for (c8_i124 = 0; c8_i124 < 9; c8_i124++) {
          c8_c_A4[c8_i124] = c8_A4[c8_i124];
        }

        for (c8_i125 = 0; c8_i125 < 9; c8_i125++) {
          c8_h_y[c8_i125] = c8_d_y[c8_i125];
        }

        c8_b_eml_xgemm(chartInstance, c8_c_A4, c8_h_y, c8_f_y);
        for (c8_i126 = 0; c8_i126 < 9; c8_i126++) {
          c8_f_y[c8_i126] += c8_U[c8_i126];
        }

        c8_eml_scalar_eg(chartInstance);
        c8_eml_scalar_eg(chartInstance);
        for (c8_i127 = 0; c8_i127 < 9; c8_i127++) {
          c8_U[c8_i127] = 0.0;
        }

        for (c8_i128 = 0; c8_i128 < 9; c8_i128++) {
          c8_h_A[c8_i128] = c8_A[c8_i128];
        }

        for (c8_i129 = 0; c8_i129 < 9; c8_i129++) {
          c8_i_y[c8_i129] = c8_f_y[c8_i129];
        }

        c8_b_eml_xgemm(chartInstance, c8_h_A, c8_i_y, c8_U);
        for (c8_i130 = 0; c8_i130 < 9; c8_i130++) {
          c8_d_y[c8_i130] = 182.0 * c8_A4[c8_i130];
        }

        for (c8_i131 = 0; c8_i131 < 9; c8_i131++) {
          c8_f_y[c8_i131] = 960960.0 * c8_A3[c8_i131];
        }

        for (c8_i132 = 0; c8_i132 < 9; c8_i132++) {
          c8_y[c8_i132] = 1.32324192E+9 * c8_A2[c8_i132];
        }

        for (c8_i133 = 0; c8_i133 < 9; c8_i133++) {
          c8_d_y[c8_i133] = (c8_d_y[c8_i133] + c8_f_y[c8_i133]) + c8_y[c8_i133];
        }

        c8_eml_scalar_eg(chartInstance);
        c8_eml_scalar_eg(chartInstance);
        for (c8_i134 = 0; c8_i134 < 9; c8_i134++) {
          c8_V[c8_i134] = 0.0;
        }

        for (c8_i135 = 0; c8_i135 < 9; c8_i135++) {
          c8_d_A4[c8_i135] = c8_A4[c8_i135];
        }

        for (c8_i136 = 0; c8_i136 < 9; c8_i136++) {
          c8_j_y[c8_i136] = c8_d_y[c8_i136];
        }

        c8_b_eml_xgemm(chartInstance, c8_d_A4, c8_j_y, c8_V);
        for (c8_i137 = 0; c8_i137 < 9; c8_i137++) {
          c8_A4[c8_i137] *= 6.704425728E+11;
        }

        for (c8_i138 = 0; c8_i138 < 9; c8_i138++) {
          c8_A3[c8_i138] *= 1.29060195264E+14;
        }

        for (c8_i139 = 0; c8_i139 < 9; c8_i139++) {
          c8_A2[c8_i139] *= 7.7717703038976E+15;
        }

        for (c8_i140 = 0; c8_i140 < 9; c8_i140++) {
          c8_V[c8_i140] = ((c8_V[c8_i140] + c8_A4[c8_i140]) + c8_A3[c8_i140]) +
            c8_A2[c8_i140];
        }

        c8_d = 6.476475253248E+16;
      }
    }
  }

  for (c8_g_k = 0; c8_g_k < 3; c8_g_k++) {
    c8_b_k = 1.0 + (real_T)c8_g_k;
    c8_V[((int32_T)c8_b_k + 3 * ((int32_T)c8_b_k - 1)) - 1] += c8_d;
  }

  for (c8_h_k = 0; c8_h_k < 9; c8_h_k++) {
    c8_b_k = 1.0 + (real_T)c8_h_k;
    c8_uk = c8_U[(int32_T)c8_b_k - 1];
    c8_U[(int32_T)c8_b_k - 1] = c8_V[(int32_T)c8_b_k - 1] - c8_uk;
    c8_V[(int32_T)c8_b_k - 1] += c8_uk;
  }

  for (c8_i141 = 0; c8_i141 < 9; c8_i141++) {
    c8_b_U[c8_i141] = c8_U[c8_i141];
  }

  for (c8_i142 = 0; c8_i142 < 9; c8_i142++) {
    c8_b_V[c8_i142] = c8_V[c8_i142];
  }

  c8_mldivide(chartInstance, c8_b_U, c8_b_V, c8_F);
}

static void c8_eml_scalar_eg
  (SFc8_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c8_eml_xgemm
  (SFc8_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance,
   real_T c8_A[9], real_T c8_B[9], real_T c8_C[9], real_T c8_b_C[9])
{
  int32_T c8_i143;
  int32_T c8_i144;
  real_T c8_b_A[9];
  int32_T c8_i145;
  real_T c8_b_B[9];
  for (c8_i143 = 0; c8_i143 < 9; c8_i143++) {
    c8_b_C[c8_i143] = c8_C[c8_i143];
  }

  for (c8_i144 = 0; c8_i144 < 9; c8_i144++) {
    c8_b_A[c8_i144] = c8_A[c8_i144];
  }

  for (c8_i145 = 0; c8_i145 < 9; c8_i145++) {
    c8_b_B[c8_i145] = c8_B[c8_i145];
  }

  c8_b_eml_xgemm(chartInstance, c8_b_A, c8_b_B, c8_b_C);
}

static void c8_mldivide
  (SFc8_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance,
   real_T c8_A[9], real_T c8_B[9], real_T c8_Y[9])
{
  int32_T c8_i146;
  real_T c8_b_A[9];
  int32_T c8_r1;
  int32_T c8_r2;
  int32_T c8_r3;
  real_T c8_x;
  real_T c8_b_x;
  real_T c8_c_x;
  real_T c8_d_x;
  real_T c8_y;
  real_T c8_e_x;
  real_T c8_f_x;
  real_T c8_b_y;
  real_T c8_maxval;
  real_T c8_g_x;
  real_T c8_h_x;
  real_T c8_i_x;
  real_T c8_j_x;
  real_T c8_c_y;
  real_T c8_k_x;
  real_T c8_l_x;
  real_T c8_d_y;
  real_T c8_a21;
  real_T c8_m_x;
  real_T c8_n_x;
  real_T c8_o_x;
  real_T c8_p_x;
  real_T c8_e_y;
  real_T c8_q_x;
  real_T c8_r_x;
  real_T c8_f_y;
  real_T c8_d;
  real_T c8_s_x;
  real_T c8_t_x;
  real_T c8_u_x;
  real_T c8_v_x;
  real_T c8_g_y;
  real_T c8_w_x;
  real_T c8_x_x;
  real_T c8_h_y;
  real_T c8_b_d;
  real_T c8_y_x;
  real_T c8_ab_x;
  real_T c8_bb_x;
  real_T c8_cb_x;
  real_T c8_i_y;
  real_T c8_db_x;
  real_T c8_eb_x;
  real_T c8_j_y;
  real_T c8_c_d;
  int32_T c8_rtemp;
  int32_T c8_k;
  int32_T c8_b_k;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  for (c8_i146 = 0; c8_i146 < 9; c8_i146++) {
    c8_b_A[c8_i146] = c8_A[c8_i146];
  }

  c8_r1 = 0;
  c8_r2 = 1;
  c8_r3 = 2;
  c8_x = c8_b_A[0];
  c8_b_x = c8_x;
  c8_c_x = c8_b_x;
  c8_d_x = c8_c_x;
  c8_y = muDoubleScalarAbs(c8_d_x);
  c8_e_x = 0.0;
  c8_f_x = c8_e_x;
  c8_b_y = muDoubleScalarAbs(c8_f_x);
  c8_maxval = c8_y + c8_b_y;
  c8_g_x = c8_b_A[1];
  c8_h_x = c8_g_x;
  c8_i_x = c8_h_x;
  c8_j_x = c8_i_x;
  c8_c_y = muDoubleScalarAbs(c8_j_x);
  c8_k_x = 0.0;
  c8_l_x = c8_k_x;
  c8_d_y = muDoubleScalarAbs(c8_l_x);
  c8_a21 = c8_c_y + c8_d_y;
  if (c8_a21 > c8_maxval) {
    c8_maxval = c8_a21;
    c8_r1 = 1;
    c8_r2 = 0;
  }

  c8_m_x = c8_b_A[2];
  c8_n_x = c8_m_x;
  c8_o_x = c8_n_x;
  c8_p_x = c8_o_x;
  c8_e_y = muDoubleScalarAbs(c8_p_x);
  c8_q_x = 0.0;
  c8_r_x = c8_q_x;
  c8_f_y = muDoubleScalarAbs(c8_r_x);
  c8_d = c8_e_y + c8_f_y;
  if (c8_d > c8_maxval) {
    c8_r1 = 2;
    c8_r2 = 1;
    c8_r3 = 0;
  }

  c8_b_A[c8_r2] = c8_rdivide(chartInstance, c8_b_A[c8_r2], c8_b_A[c8_r1]);
  c8_b_A[c8_r3] = c8_rdivide(chartInstance, c8_b_A[c8_r3], c8_b_A[c8_r1]);
  c8_b_A[3 + c8_r2] -= c8_b_A[c8_r2] * c8_b_A[3 + c8_r1];
  c8_b_A[3 + c8_r3] -= c8_b_A[c8_r3] * c8_b_A[3 + c8_r1];
  c8_b_A[6 + c8_r2] -= c8_b_A[c8_r2] * c8_b_A[6 + c8_r1];
  c8_b_A[6 + c8_r3] -= c8_b_A[c8_r3] * c8_b_A[6 + c8_r1];
  c8_s_x = c8_b_A[3 + c8_r3];
  c8_t_x = c8_s_x;
  c8_u_x = c8_t_x;
  c8_v_x = c8_u_x;
  c8_g_y = muDoubleScalarAbs(c8_v_x);
  c8_w_x = 0.0;
  c8_x_x = c8_w_x;
  c8_h_y = muDoubleScalarAbs(c8_x_x);
  c8_b_d = c8_g_y + c8_h_y;
  c8_y_x = c8_b_A[3 + c8_r2];
  c8_ab_x = c8_y_x;
  c8_bb_x = c8_ab_x;
  c8_cb_x = c8_bb_x;
  c8_i_y = muDoubleScalarAbs(c8_cb_x);
  c8_db_x = 0.0;
  c8_eb_x = c8_db_x;
  c8_j_y = muDoubleScalarAbs(c8_eb_x);
  c8_c_d = c8_i_y + c8_j_y;
  if (c8_b_d > c8_c_d) {
    c8_rtemp = c8_r2 + 1;
    c8_r2 = c8_r3;
    c8_r3 = c8_rtemp - 1;
  }

  c8_b_A[3 + c8_r3] = c8_rdivide(chartInstance, c8_b_A[3 + c8_r3], c8_b_A[3 +
    c8_r2]);
  c8_b_A[6 + c8_r3] -= c8_b_A[3 + c8_r3] * c8_b_A[6 + c8_r2];
  guard1 = false;
  guard2 = false;
  if (c8_b_A[c8_r1] == 0.0) {
    guard2 = true;
  } else if (c8_b_A[3 + c8_r2] == 0.0) {
    guard2 = true;
  } else {
    if (c8_b_A[6 + c8_r3] == 0.0) {
      guard1 = true;
    }
  }

  if (guard2 == true) {
    guard1 = true;
  }

  if (guard1 == true) {
    c8_eml_warning(chartInstance);
  }

  c8_eml_scalar_eg(chartInstance);
  c8_eml_switch_helper(chartInstance);
  for (c8_k = 1; c8_k < 4; c8_k++) {
    c8_b_k = c8_k - 1;
    c8_Y[3 * c8_b_k] = c8_B[c8_r1 + 3 * c8_b_k];
    c8_Y[1 + 3 * c8_b_k] = c8_B[c8_r2 + 3 * c8_b_k] - c8_Y[3 * c8_b_k] *
      c8_b_A[c8_r2];
    c8_Y[2 + 3 * c8_b_k] = (c8_B[c8_r3 + 3 * c8_b_k] - c8_Y[3 * c8_b_k] *
      c8_b_A[c8_r3]) - c8_Y[1 + 3 * c8_b_k] * c8_b_A[3 + c8_r3];
    c8_Y[2 + 3 * c8_b_k] = c8_rdivide(chartInstance, c8_Y[2 + 3 * c8_b_k],
      c8_b_A[6 + c8_r3]);
    c8_Y[3 * c8_b_k] -= c8_Y[2 + 3 * c8_b_k] * c8_b_A[6 + c8_r1];
    c8_Y[1 + 3 * c8_b_k] -= c8_Y[2 + 3 * c8_b_k] * c8_b_A[6 + c8_r2];
    c8_Y[1 + 3 * c8_b_k] = c8_rdivide(chartInstance, c8_Y[1 + 3 * c8_b_k],
      c8_b_A[3 + c8_r2]);
    c8_Y[3 * c8_b_k] -= c8_Y[1 + 3 * c8_b_k] * c8_b_A[3 + c8_r1];
    c8_Y[3 * c8_b_k] = c8_rdivide(chartInstance, c8_Y[3 * c8_b_k], c8_b_A[c8_r1]);
  }
}

static void c8_eml_warning
  (SFc8_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance)
{
  int32_T c8_i147;
  static char_T c8_varargin_1[27] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 's', 'i', 'n', 'g', 'u', 'l', 'a', 'r', 'M', 'a',
    't', 'r', 'i', 'x' };

  char_T c8_b_u[27];
  const mxArray *c8_y = NULL;
  (void)chartInstance;
  for (c8_i147 = 0; c8_i147 < 27; c8_i147++) {
    c8_b_u[c8_i147] = c8_varargin_1[c8_i147];
  }

  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_b_u, 10, 0U, 1U, 0U, 2, 1, 27),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "warning", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    1U, 14, c8_y));
}

static void c8_b_eml_scalar_eg
  (SFc8_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static real_T c8_atan2(SFc8_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct
  *chartInstance, real_T c8_y, real_T c8_x)
{
  real_T c8_b_y;
  real_T c8_b_x;
  c8_b_eml_scalar_eg(chartInstance);
  c8_b_y = c8_y;
  c8_b_x = c8_x;
  return muDoubleScalarAtan2(c8_b_y, c8_b_x);
}

static real_T c8_mpower
  (SFc8_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance,
   real_T c8_a)
{
  real_T c8_b_a;
  real_T c8_c_a;
  real_T c8_ak;
  real_T c8_d_a;
  c8_b_a = c8_a;
  c8_c_a = c8_b_a;
  c8_b_eml_scalar_eg(chartInstance);
  c8_ak = c8_c_a;
  c8_d_a = c8_ak;
  c8_b_eml_scalar_eg(chartInstance);
  return c8_d_a * c8_d_a;
}

static void c8_b_eml_error
  (SFc8_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance)
{
  int32_T c8_i148;
  static char_T c8_cv2[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'E', 'l', 'F', 'u', 'n', 'D', 'o', 'm', 'a', 'i', 'n',
    'E', 'r', 'r', 'o', 'r' };

  char_T c8_b_u[30];
  const mxArray *c8_y = NULL;
  int32_T c8_i149;
  static char_T c8_cv3[4] = { 's', 'q', 'r', 't' };

  char_T c8_c_u[4];
  const mxArray *c8_b_y = NULL;
  (void)chartInstance;
  for (c8_i148 = 0; c8_i148 < 30; c8_i148++) {
    c8_b_u[c8_i148] = c8_cv2[c8_i148];
  }

  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_b_u, 10, 0U, 1U, 0U, 2, 1, 30),
                false);
  for (c8_i149 = 0; c8_i149 < 4; c8_i149++) {
    c8_c_u[c8_i149] = c8_cv3[c8_i149];
  }

  c8_b_y = NULL;
  sf_mex_assign(&c8_b_y, sf_mex_create("y", c8_c_u, 10, 0U, 1U, 0U, 2, 1, 4),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    2U, 14, c8_y, 14, c8_b_y));
}

static const mxArray *c8_e_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int32_T c8_b_u;
  const mxArray *c8_y = NULL;
  SFc8_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance;
  chartInstance = (SFc8_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *)
    chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  c8_b_u = *(int32_T *)c8_inData;
  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", &c8_b_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, false);
  return c8_mxArrayOutData;
}

static int32_T c8_f_emlrt_marshallIn
  (SFc8_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance,
   const mxArray *c8_b_u, const emlrtMsgIdentifier *c8_parentId)
{
  int32_T c8_y;
  int32_T c8_i150;
  (void)chartInstance;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_b_u), &c8_i150, 1, 6, 0U, 0, 0U, 0);
  c8_y = c8_i150;
  sf_mex_destroy(&c8_b_u);
  return c8_y;
}

static void c8_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData)
{
  const mxArray *c8_b_sfEvent;
  const char_T *c8_identifier;
  emlrtMsgIdentifier c8_thisId;
  int32_T c8_y;
  SFc8_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance;
  chartInstance = (SFc8_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *)
    chartInstanceVoid;
  c8_b_sfEvent = sf_mex_dup(c8_mxArrayInData);
  c8_identifier = c8_varName;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_y = c8_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_b_sfEvent),
    &c8_thisId);
  sf_mex_destroy(&c8_b_sfEvent);
  *(int32_T *)c8_outData = c8_y;
  sf_mex_destroy(&c8_mxArrayInData);
}

static uint8_T c8_g_emlrt_marshallIn
  (SFc8_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance,
   const mxArray *c8_b_is_active_c8_wabs_perceptionmodel_VPT_Limbic_v3_adj,
   const char_T *c8_identifier)
{
  uint8_T c8_y;
  emlrtMsgIdentifier c8_thisId;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_y = c8_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c8_b_is_active_c8_wabs_perceptionmodel_VPT_Limbic_v3_adj), &c8_thisId);
  sf_mex_destroy(&c8_b_is_active_c8_wabs_perceptionmodel_VPT_Limbic_v3_adj);
  return c8_y;
}

static uint8_T c8_h_emlrt_marshallIn
  (SFc8_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance,
   const mxArray *c8_b_u, const emlrtMsgIdentifier *c8_parentId)
{
  uint8_T c8_y;
  uint8_T c8_u0;
  (void)chartInstance;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_b_u), &c8_u0, 1, 3, 0U, 0, 0U, 0);
  c8_y = c8_u0;
  sf_mex_destroy(&c8_b_u);
  return c8_y;
}

static void c8_b_acos(SFc8_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *
                      chartInstance, real_T *c8_x)
{
  boolean_T guard1 = false;
  guard1 = false;
  if (*c8_x < -1.0) {
    guard1 = true;
  } else {
    if (1.0 < *c8_x) {
      guard1 = true;
    }
  }

  if (guard1 == true) {
    c8_eml_error(chartInstance);
  }

  *c8_x = muDoubleScalarAcos(*c8_x);
}

static void c8_b_eml_xgemm
  (SFc8_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance,
   real_T c8_A[9], real_T c8_B[9], real_T c8_C[9])
{
  int32_T c8_i151;
  int32_T c8_i152;
  int32_T c8_i153;
  int32_T c8_i154;
  int32_T c8_i155;
  (void)chartInstance;
  for (c8_i151 = 0; c8_i151 < 3; c8_i151++) {
    c8_i152 = 0;
    for (c8_i153 = 0; c8_i153 < 3; c8_i153++) {
      c8_C[c8_i152 + c8_i151] = 0.0;
      c8_i154 = 0;
      for (c8_i155 = 0; c8_i155 < 3; c8_i155++) {
        c8_C[c8_i152 + c8_i151] += c8_A[c8_i154 + c8_i151] * c8_B[c8_i155 +
          c8_i152];
        c8_i154 += 3;
      }

      c8_i152 += 3;
    }
  }
}

static void init_dsm_address_info
  (SFc8_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address
  (SFc8_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance)
{
  chartInstance->c8_v = (real_T (*)[3])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c8_u = (real_T (*)[3])ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c8_Eul = (real_T (*)[3])ssGetOutputPortSignal_wrapper
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

void sf_c8_wabs_perceptionmodel_VPT_Limbic_v3_adj_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(900140963U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2582399738U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3445376577U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4132119531U);
}

mxArray* sf_c8_wabs_perceptionmodel_VPT_Limbic_v3_adj_get_post_codegen_info(void);
mxArray *sf_c8_wabs_perceptionmodel_VPT_Limbic_v3_adj_get_autoinheritance_info
  (void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("jy8PU8EPF4m5dxmtn9lgHD");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));
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
      sf_c8_wabs_perceptionmodel_VPT_Limbic_v3_adj_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c8_wabs_perceptionmodel_VPT_Limbic_v3_adj_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c8_wabs_perceptionmodel_VPT_Limbic_v3_adj_jit_fallback_info(void)
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

mxArray *sf_c8_wabs_perceptionmodel_VPT_Limbic_v3_adj_updateBuildInfo_args_info
  (void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c8_wabs_perceptionmodel_VPT_Limbic_v3_adj_get_post_codegen_info(void)
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
  *sf_get_sim_state_info_c8_wabs_perceptionmodel_VPT_Limbic_v3_adj(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"Eul\",},{M[8],M[0],T\"is_active_c8_wabs_perceptionmodel_VPT_Limbic_v3_adj\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c8_wabs_perceptionmodel_VPT_Limbic_v3_adj_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc8_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc8_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _wabs_perceptionmodel_VPT_Limbic_v3_adjMachineNumber_,
           8,
           1,
           1,
           0,
           3,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"v");
          _SFD_SET_DATA_PROPS(1,1,1,0,"u");
          _SFD_SET_DATA_PROPS(2,2,0,1,"Eul");
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
        _SFD_CV_INIT_EML(0,1,3,2,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,982);
        _SFD_CV_INIT_EML_FCN(0,1,"GetSkewSymmetric",1053,-1,1137);
        _SFD_CV_INIT_EML_FCN(0,2,"Rot2Eul",1139,-1,1293);
        _SFD_CV_INIT_EML_IF(0,1,0,431,455,-1,565);
        _SFD_CV_INIT_EML_IF(0,1,1,886,905,922,954);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,0,434,455,-1,3);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,1,889,905,-1,3);

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c8_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c8_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c8_sf_marshallOut,(MexInFcnForType)
            c8_sf_marshallIn);
        }

        _SFD_SET_DATA_VALUE_PTR(0U, *chartInstance->c8_v);
        _SFD_SET_DATA_VALUE_PTR(1U, *chartInstance->c8_u);
        _SFD_SET_DATA_VALUE_PTR(2U, *chartInstance->c8_Eul);
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
  return "68cQBFNF0jQtZ4Xnm2fx4";
}

static void sf_opaque_initialize_c8_wabs_perceptionmodel_VPT_Limbic_v3_adj(void *
  chartInstanceVar)
{
  chart_debug_initialization
    (((SFc8_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct*)
      chartInstanceVar)->S,0);
  initialize_params_c8_wabs_perceptionmodel_VPT_Limbic_v3_adj
    ((SFc8_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct*)
     chartInstanceVar);
  initialize_c8_wabs_perceptionmodel_VPT_Limbic_v3_adj
    ((SFc8_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct*)
     chartInstanceVar);
}

static void sf_opaque_enable_c8_wabs_perceptionmodel_VPT_Limbic_v3_adj(void
  *chartInstanceVar)
{
  enable_c8_wabs_perceptionmodel_VPT_Limbic_v3_adj
    ((SFc8_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct*)
     chartInstanceVar);
}

static void sf_opaque_disable_c8_wabs_perceptionmodel_VPT_Limbic_v3_adj(void
  *chartInstanceVar)
{
  disable_c8_wabs_perceptionmodel_VPT_Limbic_v3_adj
    ((SFc8_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct*)
     chartInstanceVar);
}

static void sf_opaque_gateway_c8_wabs_perceptionmodel_VPT_Limbic_v3_adj(void
  *chartInstanceVar)
{
  sf_gateway_c8_wabs_perceptionmodel_VPT_Limbic_v3_adj
    ((SFc8_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct*)
     chartInstanceVar);
}

static const mxArray*
  sf_opaque_get_sim_state_c8_wabs_perceptionmodel_VPT_Limbic_v3_adj(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c8_wabs_perceptionmodel_VPT_Limbic_v3_adj
    ((SFc8_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct*)
     chartInfo->chartInstance);        /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c8_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SimStruct* S, const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c8_wabs_perceptionmodel_VPT_Limbic_v3_adj
    ((SFc8_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct*)
     chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c8_wabs_perceptionmodel_VPT_Limbic_v3_adj(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc8_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct*)
                    chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_wabs_perceptionmodel_VPT_Limbic_v3_adj_optimization_info();
    }

    finalize_c8_wabs_perceptionmodel_VPT_Limbic_v3_adj
      ((SFc8_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct*)
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
  initSimStructsc8_wabs_perceptionmodel_VPT_Limbic_v3_adj
    ((SFc8_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct*)
     chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c8_wabs_perceptionmodel_VPT_Limbic_v3_adj
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
    initialize_params_c8_wabs_perceptionmodel_VPT_Limbic_v3_adj
      ((SFc8_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct*)
       (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c8_wabs_perceptionmodel_VPT_Limbic_v3_adj(SimStruct
  *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct =
      load_wabs_perceptionmodel_VPT_Limbic_v3_adj_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,8);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,8,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,8,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,8);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,8,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,8,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 2; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,8);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3304834313U));
  ssSetChecksum1(S,(1086332803U));
  ssSetChecksum2(S,(2791854939U));
  ssSetChecksum3(S,(1216572718U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c8_wabs_perceptionmodel_VPT_Limbic_v3_adj(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c8_wabs_perceptionmodel_VPT_Limbic_v3_adj(SimStruct *S)
{
  SFc8_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc8_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *)
    utMalloc(sizeof(SFc8_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct));
  memset(chartInstance, 0, sizeof
         (SFc8_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c8_wabs_perceptionmodel_VPT_Limbic_v3_adj;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c8_wabs_perceptionmodel_VPT_Limbic_v3_adj;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c8_wabs_perceptionmodel_VPT_Limbic_v3_adj;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c8_wabs_perceptionmodel_VPT_Limbic_v3_adj;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c8_wabs_perceptionmodel_VPT_Limbic_v3_adj;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c8_wabs_perceptionmodel_VPT_Limbic_v3_adj;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c8_wabs_perceptionmodel_VPT_Limbic_v3_adj;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c8_wabs_perceptionmodel_VPT_Limbic_v3_adj;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW =
    mdlRTW_c8_wabs_perceptionmodel_VPT_Limbic_v3_adj;
  chartInstance->chartInfo.mdlStart =
    mdlStart_c8_wabs_perceptionmodel_VPT_Limbic_v3_adj;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c8_wabs_perceptionmodel_VPT_Limbic_v3_adj;
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

void c8_wabs_perceptionmodel_VPT_Limbic_v3_adj_method_dispatcher(SimStruct *S,
  int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c8_wabs_perceptionmodel_VPT_Limbic_v3_adj(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c8_wabs_perceptionmodel_VPT_Limbic_v3_adj(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c8_wabs_perceptionmodel_VPT_Limbic_v3_adj(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c8_wabs_perceptionmodel_VPT_Limbic_v3_adj_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
