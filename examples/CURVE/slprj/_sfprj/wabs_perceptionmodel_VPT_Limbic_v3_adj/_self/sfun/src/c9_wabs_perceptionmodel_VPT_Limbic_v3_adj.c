/* Include files */

#include <stddef.h>
#include "blas.h"
#include "wabs_perceptionmodel_VPT_Limbic_v3_adj_sfun.h"
#include "c9_wabs_perceptionmodel_VPT_Limbic_v3_adj.h"
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
static const char * c9_debug_family_names[8] = { "r", "p", "y", "RPYrot",
  "nargin", "nargout", "RPY", "DCM" };

/* Function Declarations */
static void initialize_c9_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SFc9_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance);
static void initialize_params_c9_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SFc9_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance);
static void enable_c9_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SFc9_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance);
static void disable_c9_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SFc9_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance);
static void c9_update_debugger_state_c9_wabs_perceptionmodel_VPT_Limbic_v3_a
  (SFc9_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c9_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SFc9_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance);
static void set_sim_state_c9_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SFc9_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance,
   const mxArray *c9_st);
static void finalize_c9_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SFc9_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance);
static void sf_gateway_c9_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SFc9_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance);
static void mdl_start_c9_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SFc9_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance);
static void initSimStructsc9_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SFc9_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c9_machineNumber, uint32_T
  c9_chartNumber, uint32_T c9_instanceNumber);
static const mxArray *c9_sf_marshallOut(void *chartInstanceVoid, void *c9_inData);
static void c9_emlrt_marshallIn
  (SFc9_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance,
   const mxArray *c9_b_DCM, const char_T *c9_identifier, real_T c9_y[9]);
static void c9_b_emlrt_marshallIn
  (SFc9_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance,
   const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId, real_T c9_y[9]);
static void c9_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static const mxArray *c9_b_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static const mxArray *c9_c_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static real_T c9_c_emlrt_marshallIn
  (SFc9_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance,
   const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId);
static void c9_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static void c9_info_helper(const mxArray **c9_info);
static const mxArray *c9_emlrt_marshallOut(const char * c9_u);
static const mxArray *c9_b_emlrt_marshallOut(const uint32_T c9_u);
static const mxArray *c9_d_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static int32_T c9_d_emlrt_marshallIn
  (SFc9_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance,
   const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId);
static void c9_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static uint8_T c9_e_emlrt_marshallIn
  (SFc9_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance,
   const mxArray *c9_b_is_active_c9_wabs_perceptionmodel_VPT_Limbic_v3_adj,
   const char_T *c9_identifier);
static uint8_T c9_f_emlrt_marshallIn
  (SFc9_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance,
   const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId);
static void init_dsm_address_info
  (SFc9_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance);
static void init_simulink_io_address
  (SFc9_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c9_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SFc9_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance)
{
  chartInstance->c9_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c9_is_active_c9_wabs_perceptionmodel_VPT_Limbic_v3_adj = 0U;
}

static void initialize_params_c9_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SFc9_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c9_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SFc9_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c9_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SFc9_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c9_update_debugger_state_c9_wabs_perceptionmodel_VPT_Limbic_v3_a
  (SFc9_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c9_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SFc9_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance)
{
  const mxArray *c9_st;
  const mxArray *c9_y = NULL;
  int32_T c9_i0;
  real_T c9_u[9];
  const mxArray *c9_b_y = NULL;
  uint8_T c9_hoistedGlobal;
  uint8_T c9_b_u;
  const mxArray *c9_c_y = NULL;
  c9_st = NULL;
  c9_st = NULL;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_createcellmatrix(2, 1), false);
  for (c9_i0 = 0; c9_i0 < 9; c9_i0++) {
    c9_u[c9_i0] = (*chartInstance->c9_DCM)[c9_i0];
  }

  c9_b_y = NULL;
  sf_mex_assign(&c9_b_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 2, 3, 3), false);
  sf_mex_setcell(c9_y, 0, c9_b_y);
  c9_hoistedGlobal =
    chartInstance->c9_is_active_c9_wabs_perceptionmodel_VPT_Limbic_v3_adj;
  c9_b_u = c9_hoistedGlobal;
  c9_c_y = NULL;
  sf_mex_assign(&c9_c_y, sf_mex_create("y", &c9_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c9_y, 1, c9_c_y);
  sf_mex_assign(&c9_st, c9_y, false);
  return c9_st;
}

static void set_sim_state_c9_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SFc9_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance,
   const mxArray *c9_st)
{
  const mxArray *c9_u;
  real_T c9_dv0[9];
  int32_T c9_i1;
  chartInstance->c9_doneDoubleBufferReInit = true;
  c9_u = sf_mex_dup(c9_st);
  c9_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c9_u, 0)), "DCM",
                      c9_dv0);
  for (c9_i1 = 0; c9_i1 < 9; c9_i1++) {
    (*chartInstance->c9_DCM)[c9_i1] = c9_dv0[c9_i1];
  }

  chartInstance->c9_is_active_c9_wabs_perceptionmodel_VPT_Limbic_v3_adj =
    c9_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c9_u, 1)),
    "is_active_c9_wabs_perceptionmodel_VPT_Limbic_v3_adj");
  sf_mex_destroy(&c9_u);
  c9_update_debugger_state_c9_wabs_perceptionmodel_VPT_Limbic_v3_a(chartInstance);
  sf_mex_destroy(&c9_st);
}

static void finalize_c9_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SFc9_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c9_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SFc9_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance)
{
  int32_T c9_i2;
  int32_T c9_i3;
  real_T c9_b_RPY[3];
  uint32_T c9_debug_family_var_map[8];
  real_T c9_r;
  real_T c9_p;
  real_T c9_y;
  real_T c9_RPYrot[9];
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 1.0;
  real_T c9_b_DCM[9];
  real_T c9_x;
  real_T c9_b_x;
  real_T c9_c_x;
  real_T c9_d_x;
  real_T c9_e_x;
  real_T c9_f_x;
  real_T c9_g_x;
  real_T c9_h_x;
  real_T c9_i_x;
  real_T c9_j_x;
  real_T c9_k_x;
  real_T c9_l_x;
  real_T c9_m_x;
  real_T c9_n_x;
  real_T c9_o_x;
  real_T c9_p_x;
  real_T c9_q_x;
  real_T c9_r_x;
  real_T c9_s_x;
  real_T c9_t_x;
  real_T c9_u_x;
  real_T c9_v_x;
  real_T c9_w_x;
  real_T c9_x_x;
  real_T c9_y_x;
  real_T c9_ab_x;
  real_T c9_bb_x;
  real_T c9_cb_x;
  real_T c9_db_x;
  real_T c9_eb_x;
  real_T c9_fb_x;
  real_T c9_gb_x;
  real_T c9_hb_x;
  real_T c9_ib_x;
  real_T c9_jb_x;
  real_T c9_kb_x;
  real_T c9_lb_x;
  real_T c9_mb_x;
  real_T c9_nb_x;
  real_T c9_ob_x;
  real_T c9_pb_x;
  real_T c9_qb_x;
  real_T c9_rb_x;
  real_T c9_sb_x;
  real_T c9_tb_x;
  real_T c9_ub_x;
  real_T c9_vb_x;
  real_T c9_wb_x;
  real_T c9_xb_x;
  real_T c9_yb_x;
  real_T c9_ac_x;
  real_T c9_bc_x;
  real_T c9_cc_x;
  real_T c9_dc_x;
  real_T c9_ec_x;
  real_T c9_fc_x;
  real_T c9_gc_x;
  real_T c9_hc_x;
  int32_T c9_i4;
  int32_T c9_i5;
  int32_T c9_i6;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 8U, chartInstance->c9_sfEvent);
  for (c9_i2 = 0; c9_i2 < 3; c9_i2++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c9_RPY)[c9_i2], 0U);
  }

  chartInstance->c9_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 8U, chartInstance->c9_sfEvent);
  for (c9_i3 = 0; c9_i3 < 3; c9_i3++) {
    c9_b_RPY[c9_i3] = (*chartInstance->c9_RPY)[c9_i3];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 8U, 8U, c9_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_r, 0U, c9_c_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_p, 1U, c9_c_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_y, 2U, c9_c_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_RPYrot, 3U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 4U, c9_c_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 5U, c9_c_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_b_RPY, 6U, c9_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_b_DCM, 7U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 5);
  c9_r = c9_b_RPY[0];
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 6);
  c9_p = c9_b_RPY[1];
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 7);
  c9_y = c9_b_RPY[2];
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_x = c9_y;
  c9_b_x = c9_x;
  c9_b_x = muDoubleScalarCos(c9_b_x);
  c9_c_x = c9_p;
  c9_d_x = c9_c_x;
  c9_d_x = muDoubleScalarCos(c9_d_x);
  c9_e_x = c9_y;
  c9_f_x = c9_e_x;
  c9_f_x = muDoubleScalarCos(c9_f_x);
  c9_g_x = c9_p;
  c9_h_x = c9_g_x;
  c9_h_x = muDoubleScalarSin(c9_h_x);
  c9_i_x = c9_r;
  c9_j_x = c9_i_x;
  c9_j_x = muDoubleScalarSin(c9_j_x);
  c9_k_x = c9_y;
  c9_l_x = c9_k_x;
  c9_l_x = muDoubleScalarSin(c9_l_x);
  c9_m_x = c9_r;
  c9_n_x = c9_m_x;
  c9_n_x = muDoubleScalarCos(c9_n_x);
  c9_o_x = c9_y;
  c9_p_x = c9_o_x;
  c9_p_x = muDoubleScalarCos(c9_p_x);
  c9_q_x = c9_p;
  c9_r_x = c9_q_x;
  c9_r_x = muDoubleScalarSin(c9_r_x);
  c9_s_x = c9_r;
  c9_t_x = c9_s_x;
  c9_t_x = muDoubleScalarCos(c9_t_x);
  c9_u_x = c9_y;
  c9_v_x = c9_u_x;
  c9_v_x = muDoubleScalarSin(c9_v_x);
  c9_w_x = c9_r;
  c9_x_x = c9_w_x;
  c9_x_x = muDoubleScalarSin(c9_x_x);
  c9_y_x = c9_y;
  c9_ab_x = c9_y_x;
  c9_ab_x = muDoubleScalarSin(c9_ab_x);
  c9_bb_x = c9_p;
  c9_cb_x = c9_bb_x;
  c9_cb_x = muDoubleScalarCos(c9_cb_x);
  c9_db_x = c9_y;
  c9_eb_x = c9_db_x;
  c9_eb_x = muDoubleScalarSin(c9_eb_x);
  c9_fb_x = c9_p;
  c9_gb_x = c9_fb_x;
  c9_gb_x = muDoubleScalarSin(c9_gb_x);
  c9_hb_x = c9_r;
  c9_ib_x = c9_hb_x;
  c9_ib_x = muDoubleScalarSin(c9_ib_x);
  c9_jb_x = c9_y;
  c9_kb_x = c9_jb_x;
  c9_kb_x = muDoubleScalarCos(c9_kb_x);
  c9_lb_x = c9_r;
  c9_mb_x = c9_lb_x;
  c9_mb_x = muDoubleScalarCos(c9_mb_x);
  c9_nb_x = c9_y;
  c9_ob_x = c9_nb_x;
  c9_ob_x = muDoubleScalarSin(c9_ob_x);
  c9_pb_x = c9_p;
  c9_qb_x = c9_pb_x;
  c9_qb_x = muDoubleScalarSin(c9_qb_x);
  c9_rb_x = c9_r;
  c9_sb_x = c9_rb_x;
  c9_sb_x = muDoubleScalarCos(c9_sb_x);
  c9_tb_x = c9_y;
  c9_ub_x = c9_tb_x;
  c9_ub_x = muDoubleScalarCos(c9_ub_x);
  c9_vb_x = c9_r;
  c9_wb_x = c9_vb_x;
  c9_wb_x = muDoubleScalarSin(c9_wb_x);
  c9_xb_x = c9_p;
  c9_yb_x = c9_xb_x;
  c9_yb_x = muDoubleScalarSin(c9_yb_x);
  c9_ac_x = c9_p;
  c9_bc_x = c9_ac_x;
  c9_bc_x = muDoubleScalarCos(c9_bc_x);
  c9_cc_x = c9_r;
  c9_dc_x = c9_cc_x;
  c9_dc_x = muDoubleScalarSin(c9_dc_x);
  c9_ec_x = c9_p;
  c9_fc_x = c9_ec_x;
  c9_fc_x = muDoubleScalarCos(c9_fc_x);
  c9_gc_x = c9_r;
  c9_hc_x = c9_gc_x;
  c9_hc_x = muDoubleScalarCos(c9_hc_x);
  c9_RPYrot[0] = c9_b_x * c9_d_x;
  c9_RPYrot[3] = c9_f_x * c9_h_x * c9_j_x - c9_l_x * c9_n_x;
  c9_RPYrot[6] = c9_p_x * c9_r_x * c9_t_x + c9_v_x * c9_x_x;
  c9_RPYrot[1] = c9_ab_x * c9_cb_x;
  c9_RPYrot[4] = c9_eb_x * c9_gb_x * c9_ib_x + c9_kb_x * c9_mb_x;
  c9_RPYrot[7] = c9_ob_x * c9_qb_x * c9_sb_x - c9_ub_x * c9_wb_x;
  c9_RPYrot[2] = -c9_yb_x;
  c9_RPYrot[5] = c9_bc_x * c9_dc_x;
  c9_RPYrot[8] = c9_fc_x * c9_hc_x;
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 12);
  for (c9_i4 = 0; c9_i4 < 9; c9_i4++) {
    c9_b_DCM[c9_i4] = c9_RPYrot[c9_i4];
  }

  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, -12);
  _SFD_SYMBOL_SCOPE_POP();
  for (c9_i5 = 0; c9_i5 < 9; c9_i5++) {
    (*chartInstance->c9_DCM)[c9_i5] = c9_b_DCM[c9_i5];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 8U, chartInstance->c9_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY
    (_wabs_perceptionmodel_VPT_Limbic_v3_adjMachineNumber_,
     chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c9_i6 = 0; c9_i6 < 9; c9_i6++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c9_DCM)[c9_i6], 1U);
  }
}

static void mdl_start_c9_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SFc9_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void initSimStructsc9_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SFc9_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c9_machineNumber, uint32_T
  c9_chartNumber, uint32_T c9_instanceNumber)
{
  (void)c9_machineNumber;
  (void)c9_chartNumber;
  (void)c9_instanceNumber;
}

static const mxArray *c9_sf_marshallOut(void *chartInstanceVoid, void *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i7;
  int32_T c9_i8;
  int32_T c9_i9;
  real_T c9_b_inData[9];
  int32_T c9_i10;
  int32_T c9_i11;
  int32_T c9_i12;
  real_T c9_u[9];
  const mxArray *c9_y = NULL;
  SFc9_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance;
  chartInstance = (SFc9_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_i7 = 0;
  for (c9_i8 = 0; c9_i8 < 3; c9_i8++) {
    for (c9_i9 = 0; c9_i9 < 3; c9_i9++) {
      c9_b_inData[c9_i9 + c9_i7] = (*(real_T (*)[9])c9_inData)[c9_i9 + c9_i7];
    }

    c9_i7 += 3;
  }

  c9_i10 = 0;
  for (c9_i11 = 0; c9_i11 < 3; c9_i11++) {
    for (c9_i12 = 0; c9_i12 < 3; c9_i12++) {
      c9_u[c9_i12 + c9_i10] = c9_b_inData[c9_i12 + c9_i10];
    }

    c9_i10 += 3;
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 2, 3, 3), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static void c9_emlrt_marshallIn
  (SFc9_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance,
   const mxArray *c9_b_DCM, const char_T *c9_identifier, real_T c9_y[9])
{
  emlrtMsgIdentifier c9_thisId;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_b_DCM), &c9_thisId, c9_y);
  sf_mex_destroy(&c9_b_DCM);
}

static void c9_b_emlrt_marshallIn
  (SFc9_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance,
   const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId, real_T c9_y[9])
{
  real_T c9_dv1[9];
  int32_T c9_i13;
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), c9_dv1, 1, 0, 0U, 1, 0U, 2, 3, 3);
  for (c9_i13 = 0; c9_i13 < 9; c9_i13++) {
    c9_y[c9_i13] = c9_dv1[c9_i13];
  }

  sf_mex_destroy(&c9_u);
}

static void c9_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_b_DCM;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  real_T c9_y[9];
  int32_T c9_i14;
  int32_T c9_i15;
  int32_T c9_i16;
  SFc9_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance;
  chartInstance = (SFc9_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *)
    chartInstanceVoid;
  c9_b_DCM = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_b_DCM), &c9_thisId, c9_y);
  sf_mex_destroy(&c9_b_DCM);
  c9_i14 = 0;
  for (c9_i15 = 0; c9_i15 < 3; c9_i15++) {
    for (c9_i16 = 0; c9_i16 < 3; c9_i16++) {
      (*(real_T (*)[9])c9_outData)[c9_i16 + c9_i14] = c9_y[c9_i16 + c9_i14];
    }

    c9_i14 += 3;
  }

  sf_mex_destroy(&c9_mxArrayInData);
}

static const mxArray *c9_b_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i17;
  real_T c9_b_inData[3];
  int32_T c9_i18;
  real_T c9_u[3];
  const mxArray *c9_y = NULL;
  SFc9_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance;
  chartInstance = (SFc9_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i17 = 0; c9_i17 < 3; c9_i17++) {
    c9_b_inData[c9_i17] = (*(real_T (*)[3])c9_inData)[c9_i17];
  }

  for (c9_i18 = 0; c9_i18 < 3; c9_i18++) {
    c9_u[c9_i18] = c9_b_inData[c9_i18];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 3), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_c_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  real_T c9_u;
  const mxArray *c9_y = NULL;
  SFc9_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance;
  chartInstance = (SFc9_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_u = *(real_T *)c9_inData;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", &c9_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static real_T c9_c_emlrt_marshallIn
  (SFc9_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance,
   const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  real_T c9_y;
  real_T c9_d0;
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), &c9_d0, 1, 0, 0U, 0, 0U, 0);
  c9_y = c9_d0;
  sf_mex_destroy(&c9_u);
  return c9_y;
}

static void c9_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_nargout;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  real_T c9_y;
  SFc9_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance;
  chartInstance = (SFc9_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *)
    chartInstanceVoid;
  c9_nargout = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_nargout), &c9_thisId);
  sf_mex_destroy(&c9_nargout);
  *(real_T *)c9_outData = c9_y;
  sf_mex_destroy(&c9_mxArrayInData);
}

const mxArray
  *sf_c9_wabs_perceptionmodel_VPT_Limbic_v3_adj_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c9_nameCaptureInfo = NULL;
  c9_nameCaptureInfo = NULL;
  sf_mex_assign(&c9_nameCaptureInfo, sf_mex_createstruct("structure", 2, 4, 1),
                false);
  c9_info_helper(&c9_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c9_nameCaptureInfo);
  return c9_nameCaptureInfo;
}

static void c9_info_helper(const mxArray **c9_info)
{
  const mxArray *c9_rhs0 = NULL;
  const mxArray *c9_lhs0 = NULL;
  const mxArray *c9_rhs1 = NULL;
  const mxArray *c9_lhs1 = NULL;
  const mxArray *c9_rhs2 = NULL;
  const mxArray *c9_lhs2 = NULL;
  const mxArray *c9_rhs3 = NULL;
  const mxArray *c9_lhs3 = NULL;
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("cos"), "name", "name", 0);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1395328496U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c9_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs0), "rhs", "rhs", 0);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs0), "lhs", "lhs", 0);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m"), "context",
                  "context", 1);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("eml_scalar_cos"), "name",
                  "name", 1);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1286818722U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c9_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs1), "rhs", "rhs", 1);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs1), "lhs", "lhs", 1);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(""), "context", "context", 2);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("sin"), "name", "name", 2);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1395328504U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c9_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs2), "rhs", "rhs", 2);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs2), "lhs", "lhs", 2);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("eml_scalar_sin"), "name",
                  "name", 3);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1286818736U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c9_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs3), "rhs", "rhs", 3);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs3), "lhs", "lhs", 3);
  sf_mex_destroy(&c9_rhs0);
  sf_mex_destroy(&c9_lhs0);
  sf_mex_destroy(&c9_rhs1);
  sf_mex_destroy(&c9_lhs1);
  sf_mex_destroy(&c9_rhs2);
  sf_mex_destroy(&c9_lhs2);
  sf_mex_destroy(&c9_rhs3);
  sf_mex_destroy(&c9_lhs3);
}

static const mxArray *c9_emlrt_marshallOut(const char * c9_u)
{
  const mxArray *c9_y = NULL;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c9_u)), false);
  return c9_y;
}

static const mxArray *c9_b_emlrt_marshallOut(const uint32_T c9_u)
{
  const mxArray *c9_y = NULL;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", &c9_u, 7, 0U, 0U, 0U, 0), false);
  return c9_y;
}

static const mxArray *c9_d_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_u;
  const mxArray *c9_y = NULL;
  SFc9_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance;
  chartInstance = (SFc9_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_u = *(int32_T *)c9_inData;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", &c9_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static int32_T c9_d_emlrt_marshallIn
  (SFc9_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance,
   const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  int32_T c9_y;
  int32_T c9_i19;
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), &c9_i19, 1, 6, 0U, 0, 0U, 0);
  c9_y = c9_i19;
  sf_mex_destroy(&c9_u);
  return c9_y;
}

static void c9_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_b_sfEvent;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  int32_T c9_y;
  SFc9_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance;
  chartInstance = (SFc9_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *)
    chartInstanceVoid;
  c9_b_sfEvent = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_b_sfEvent),
    &c9_thisId);
  sf_mex_destroy(&c9_b_sfEvent);
  *(int32_T *)c9_outData = c9_y;
  sf_mex_destroy(&c9_mxArrayInData);
}

static uint8_T c9_e_emlrt_marshallIn
  (SFc9_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance,
   const mxArray *c9_b_is_active_c9_wabs_perceptionmodel_VPT_Limbic_v3_adj,
   const char_T *c9_identifier)
{
  uint8_T c9_y;
  emlrtMsgIdentifier c9_thisId;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c9_b_is_active_c9_wabs_perceptionmodel_VPT_Limbic_v3_adj), &c9_thisId);
  sf_mex_destroy(&c9_b_is_active_c9_wabs_perceptionmodel_VPT_Limbic_v3_adj);
  return c9_y;
}

static uint8_T c9_f_emlrt_marshallIn
  (SFc9_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance,
   const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  uint8_T c9_y;
  uint8_T c9_u0;
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), &c9_u0, 1, 3, 0U, 0, 0U, 0);
  c9_y = c9_u0;
  sf_mex_destroy(&c9_u);
  return c9_y;
}

static void init_dsm_address_info
  (SFc9_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address
  (SFc9_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance)
{
  chartInstance->c9_RPY = (real_T (*)[3])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c9_DCM = (real_T (*)[9])ssGetOutputPortSignal_wrapper
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

void sf_c9_wabs_perceptionmodel_VPT_Limbic_v3_adj_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(883773522U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(853685170U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(31244891U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1931396024U);
}

mxArray* sf_c9_wabs_perceptionmodel_VPT_Limbic_v3_adj_get_post_codegen_info(void);
mxArray *sf_c9_wabs_perceptionmodel_VPT_Limbic_v3_adj_get_autoinheritance_info
  (void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("bzFSGeuC13IHN5AjR0tELC");
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
      sf_c9_wabs_perceptionmodel_VPT_Limbic_v3_adj_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c9_wabs_perceptionmodel_VPT_Limbic_v3_adj_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c9_wabs_perceptionmodel_VPT_Limbic_v3_adj_jit_fallback_info(void)
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

mxArray *sf_c9_wabs_perceptionmodel_VPT_Limbic_v3_adj_updateBuildInfo_args_info
  (void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c9_wabs_perceptionmodel_VPT_Limbic_v3_adj_get_post_codegen_info(void)
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
  *sf_get_sim_state_info_c9_wabs_perceptionmodel_VPT_Limbic_v3_adj(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"DCM\",},{M[8],M[0],T\"is_active_c9_wabs_perceptionmodel_VPT_Limbic_v3_adj\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c9_wabs_perceptionmodel_VPT_Limbic_v3_adj_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc9_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc9_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _wabs_perceptionmodel_VPT_Limbic_v3_adjMachineNumber_,
           9,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"RPY");
          _SFD_SET_DATA_PROPS(1,2,0,1,"DCM");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,445);

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c9_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)
            c9_sf_marshallIn);
        }

        _SFD_SET_DATA_VALUE_PTR(0U, *chartInstance->c9_RPY);
        _SFD_SET_DATA_VALUE_PTR(1U, *chartInstance->c9_DCM);
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
  return "e60ukkYwFOidnU2m7OqJVC";
}

static void sf_opaque_initialize_c9_wabs_perceptionmodel_VPT_Limbic_v3_adj(void *
  chartInstanceVar)
{
  chart_debug_initialization
    (((SFc9_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct*)
      chartInstanceVar)->S,0);
  initialize_params_c9_wabs_perceptionmodel_VPT_Limbic_v3_adj
    ((SFc9_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct*)
     chartInstanceVar);
  initialize_c9_wabs_perceptionmodel_VPT_Limbic_v3_adj
    ((SFc9_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct*)
     chartInstanceVar);
}

static void sf_opaque_enable_c9_wabs_perceptionmodel_VPT_Limbic_v3_adj(void
  *chartInstanceVar)
{
  enable_c9_wabs_perceptionmodel_VPT_Limbic_v3_adj
    ((SFc9_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct*)
     chartInstanceVar);
}

static void sf_opaque_disable_c9_wabs_perceptionmodel_VPT_Limbic_v3_adj(void
  *chartInstanceVar)
{
  disable_c9_wabs_perceptionmodel_VPT_Limbic_v3_adj
    ((SFc9_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct*)
     chartInstanceVar);
}

static void sf_opaque_gateway_c9_wabs_perceptionmodel_VPT_Limbic_v3_adj(void
  *chartInstanceVar)
{
  sf_gateway_c9_wabs_perceptionmodel_VPT_Limbic_v3_adj
    ((SFc9_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct*)
     chartInstanceVar);
}

static const mxArray*
  sf_opaque_get_sim_state_c9_wabs_perceptionmodel_VPT_Limbic_v3_adj(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c9_wabs_perceptionmodel_VPT_Limbic_v3_adj
    ((SFc9_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct*)
     chartInfo->chartInstance);        /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c9_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SimStruct* S, const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c9_wabs_perceptionmodel_VPT_Limbic_v3_adj
    ((SFc9_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct*)
     chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c9_wabs_perceptionmodel_VPT_Limbic_v3_adj(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc9_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct*)
                    chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_wabs_perceptionmodel_VPT_Limbic_v3_adj_optimization_info();
    }

    finalize_c9_wabs_perceptionmodel_VPT_Limbic_v3_adj
      ((SFc9_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct*)
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
  initSimStructsc9_wabs_perceptionmodel_VPT_Limbic_v3_adj
    ((SFc9_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct*)
     chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c9_wabs_perceptionmodel_VPT_Limbic_v3_adj
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
    initialize_params_c9_wabs_perceptionmodel_VPT_Limbic_v3_adj
      ((SFc9_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct*)
       (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c9_wabs_perceptionmodel_VPT_Limbic_v3_adj(SimStruct
  *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct =
      load_wabs_perceptionmodel_VPT_Limbic_v3_adj_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,9);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,9,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,9,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,9);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,9,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,9,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,9);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2435314602U));
  ssSetChecksum1(S,(2100214526U));
  ssSetChecksum2(S,(44165121U));
  ssSetChecksum3(S,(314325450U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c9_wabs_perceptionmodel_VPT_Limbic_v3_adj(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c9_wabs_perceptionmodel_VPT_Limbic_v3_adj(SimStruct *S)
{
  SFc9_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc9_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *)
    utMalloc(sizeof(SFc9_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct));
  memset(chartInstance, 0, sizeof
         (SFc9_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c9_wabs_perceptionmodel_VPT_Limbic_v3_adj;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c9_wabs_perceptionmodel_VPT_Limbic_v3_adj;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c9_wabs_perceptionmodel_VPT_Limbic_v3_adj;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c9_wabs_perceptionmodel_VPT_Limbic_v3_adj;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c9_wabs_perceptionmodel_VPT_Limbic_v3_adj;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c9_wabs_perceptionmodel_VPT_Limbic_v3_adj;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c9_wabs_perceptionmodel_VPT_Limbic_v3_adj;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c9_wabs_perceptionmodel_VPT_Limbic_v3_adj;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW =
    mdlRTW_c9_wabs_perceptionmodel_VPT_Limbic_v3_adj;
  chartInstance->chartInfo.mdlStart =
    mdlStart_c9_wabs_perceptionmodel_VPT_Limbic_v3_adj;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c9_wabs_perceptionmodel_VPT_Limbic_v3_adj;
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

void c9_wabs_perceptionmodel_VPT_Limbic_v3_adj_method_dispatcher(SimStruct *S,
  int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c9_wabs_perceptionmodel_VPT_Limbic_v3_adj(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c9_wabs_perceptionmodel_VPT_Limbic_v3_adj(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c9_wabs_perceptionmodel_VPT_Limbic_v3_adj(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c9_wabs_perceptionmodel_VPT_Limbic_v3_adj_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
