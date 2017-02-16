/* Include files */

#include <stddef.h>
#include "blas.h"
#include "wabs_perceptionmodel_VPT_Limbic_v3_adj_sfun.h"
#include "c5_wabs_perceptionmodel_VPT_Limbic_v3_adj.h"
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
static const char * c5_debug_family_names[8] = { "r", "p", "y", "RPYrot",
  "nargin", "nargout", "RPY", "DCM" };

/* Function Declarations */
static void initialize_c5_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SFc5_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance);
static void initialize_params_c5_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SFc5_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance);
static void enable_c5_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SFc5_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance);
static void disable_c5_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SFc5_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance);
static void c5_update_debugger_state_c5_wabs_perceptionmodel_VPT_Limbic_v3_a
  (SFc5_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c5_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SFc5_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance);
static void set_sim_state_c5_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SFc5_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance,
   const mxArray *c5_st);
static void finalize_c5_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SFc5_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance);
static void sf_gateway_c5_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SFc5_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance);
static void mdl_start_c5_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SFc5_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance);
static void initSimStructsc5_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SFc5_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c5_machineNumber, uint32_T
  c5_chartNumber, uint32_T c5_instanceNumber);
static const mxArray *c5_sf_marshallOut(void *chartInstanceVoid, void *c5_inData);
static void c5_emlrt_marshallIn
  (SFc5_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance,
   const mxArray *c5_b_DCM, const char_T *c5_identifier, real_T c5_y[9]);
static void c5_b_emlrt_marshallIn
  (SFc5_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance,
   const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId, real_T c5_y[9]);
static void c5_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_b_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static const mxArray *c5_c_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static real_T c5_c_emlrt_marshallIn
  (SFc5_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance,
   const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static void c5_info_helper(const mxArray **c5_info);
static const mxArray *c5_emlrt_marshallOut(const char * c5_u);
static const mxArray *c5_b_emlrt_marshallOut(const uint32_T c5_u);
static const mxArray *c5_d_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static int32_T c5_d_emlrt_marshallIn
  (SFc5_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance,
   const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static uint8_T c5_e_emlrt_marshallIn
  (SFc5_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance,
   const mxArray *c5_b_is_active_c5_wabs_perceptionmodel_VPT_Limbic_v3_adj,
   const char_T *c5_identifier);
static uint8_T c5_f_emlrt_marshallIn
  (SFc5_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance,
   const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void init_dsm_address_info
  (SFc5_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance);
static void init_simulink_io_address
  (SFc5_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c5_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SFc5_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance)
{
  chartInstance->c5_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c5_is_active_c5_wabs_perceptionmodel_VPT_Limbic_v3_adj = 0U;
}

static void initialize_params_c5_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SFc5_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c5_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SFc5_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c5_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SFc5_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c5_update_debugger_state_c5_wabs_perceptionmodel_VPT_Limbic_v3_a
  (SFc5_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c5_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SFc5_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance)
{
  const mxArray *c5_st;
  const mxArray *c5_y = NULL;
  int32_T c5_i0;
  real_T c5_u[9];
  const mxArray *c5_b_y = NULL;
  uint8_T c5_hoistedGlobal;
  uint8_T c5_b_u;
  const mxArray *c5_c_y = NULL;
  c5_st = NULL;
  c5_st = NULL;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_createcellmatrix(2, 1), false);
  for (c5_i0 = 0; c5_i0 < 9; c5_i0++) {
    c5_u[c5_i0] = (*chartInstance->c5_DCM)[c5_i0];
  }

  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_u, 0, 0U, 1U, 0U, 2, 3, 3), false);
  sf_mex_setcell(c5_y, 0, c5_b_y);
  c5_hoistedGlobal =
    chartInstance->c5_is_active_c5_wabs_perceptionmodel_VPT_Limbic_v3_adj;
  c5_b_u = c5_hoistedGlobal;
  c5_c_y = NULL;
  sf_mex_assign(&c5_c_y, sf_mex_create("y", &c5_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c5_y, 1, c5_c_y);
  sf_mex_assign(&c5_st, c5_y, false);
  return c5_st;
}

static void set_sim_state_c5_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SFc5_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance,
   const mxArray *c5_st)
{
  const mxArray *c5_u;
  real_T c5_dv0[9];
  int32_T c5_i1;
  chartInstance->c5_doneDoubleBufferReInit = true;
  c5_u = sf_mex_dup(c5_st);
  c5_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c5_u, 0)), "DCM",
                      c5_dv0);
  for (c5_i1 = 0; c5_i1 < 9; c5_i1++) {
    (*chartInstance->c5_DCM)[c5_i1] = c5_dv0[c5_i1];
  }

  chartInstance->c5_is_active_c5_wabs_perceptionmodel_VPT_Limbic_v3_adj =
    c5_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c5_u, 1)),
    "is_active_c5_wabs_perceptionmodel_VPT_Limbic_v3_adj");
  sf_mex_destroy(&c5_u);
  c5_update_debugger_state_c5_wabs_perceptionmodel_VPT_Limbic_v3_a(chartInstance);
  sf_mex_destroy(&c5_st);
}

static void finalize_c5_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SFc5_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c5_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SFc5_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance)
{
  int32_T c5_i2;
  int32_T c5_i3;
  real_T c5_b_RPY[3];
  uint32_T c5_debug_family_var_map[8];
  real_T c5_r;
  real_T c5_p;
  real_T c5_y;
  real_T c5_RPYrot[9];
  real_T c5_nargin = 1.0;
  real_T c5_nargout = 1.0;
  real_T c5_b_DCM[9];
  real_T c5_x;
  real_T c5_b_x;
  real_T c5_c_x;
  real_T c5_d_x;
  real_T c5_e_x;
  real_T c5_f_x;
  real_T c5_g_x;
  real_T c5_h_x;
  real_T c5_i_x;
  real_T c5_j_x;
  real_T c5_k_x;
  real_T c5_l_x;
  real_T c5_m_x;
  real_T c5_n_x;
  real_T c5_o_x;
  real_T c5_p_x;
  real_T c5_q_x;
  real_T c5_r_x;
  real_T c5_s_x;
  real_T c5_t_x;
  real_T c5_u_x;
  real_T c5_v_x;
  real_T c5_w_x;
  real_T c5_x_x;
  real_T c5_y_x;
  real_T c5_ab_x;
  real_T c5_bb_x;
  real_T c5_cb_x;
  real_T c5_db_x;
  real_T c5_eb_x;
  real_T c5_fb_x;
  real_T c5_gb_x;
  real_T c5_hb_x;
  real_T c5_ib_x;
  real_T c5_jb_x;
  real_T c5_kb_x;
  real_T c5_lb_x;
  real_T c5_mb_x;
  real_T c5_nb_x;
  real_T c5_ob_x;
  real_T c5_pb_x;
  real_T c5_qb_x;
  real_T c5_rb_x;
  real_T c5_sb_x;
  real_T c5_tb_x;
  real_T c5_ub_x;
  real_T c5_vb_x;
  real_T c5_wb_x;
  real_T c5_xb_x;
  real_T c5_yb_x;
  real_T c5_ac_x;
  real_T c5_bc_x;
  real_T c5_cc_x;
  real_T c5_dc_x;
  real_T c5_ec_x;
  real_T c5_fc_x;
  real_T c5_gc_x;
  real_T c5_hc_x;
  int32_T c5_i4;
  int32_T c5_i5;
  int32_T c5_i6;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 4U, chartInstance->c5_sfEvent);
  for (c5_i2 = 0; c5_i2 < 3; c5_i2++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c5_RPY)[c5_i2], 0U);
  }

  chartInstance->c5_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 4U, chartInstance->c5_sfEvent);
  for (c5_i3 = 0; c5_i3 < 3; c5_i3++) {
    c5_b_RPY[c5_i3] = (*chartInstance->c5_RPY)[c5_i3];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 8U, 8U, c5_debug_family_names,
    c5_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_r, 0U, c5_c_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_p, 1U, c5_c_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_y, 2U, c5_c_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_RPYrot, 3U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargin, 4U, c5_c_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargout, 5U, c5_c_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_b_RPY, 6U, c5_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_b_DCM, 7U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 5);
  c5_r = c5_b_RPY[0];
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 6);
  c5_p = c5_b_RPY[1];
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 7);
  c5_y = c5_b_RPY[2];
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 8);
  c5_x = c5_y;
  c5_b_x = c5_x;
  c5_b_x = muDoubleScalarCos(c5_b_x);
  c5_c_x = c5_p;
  c5_d_x = c5_c_x;
  c5_d_x = muDoubleScalarCos(c5_d_x);
  c5_e_x = c5_y;
  c5_f_x = c5_e_x;
  c5_f_x = muDoubleScalarCos(c5_f_x);
  c5_g_x = c5_p;
  c5_h_x = c5_g_x;
  c5_h_x = muDoubleScalarSin(c5_h_x);
  c5_i_x = c5_r;
  c5_j_x = c5_i_x;
  c5_j_x = muDoubleScalarSin(c5_j_x);
  c5_k_x = c5_y;
  c5_l_x = c5_k_x;
  c5_l_x = muDoubleScalarSin(c5_l_x);
  c5_m_x = c5_r;
  c5_n_x = c5_m_x;
  c5_n_x = muDoubleScalarCos(c5_n_x);
  c5_o_x = c5_y;
  c5_p_x = c5_o_x;
  c5_p_x = muDoubleScalarCos(c5_p_x);
  c5_q_x = c5_p;
  c5_r_x = c5_q_x;
  c5_r_x = muDoubleScalarSin(c5_r_x);
  c5_s_x = c5_r;
  c5_t_x = c5_s_x;
  c5_t_x = muDoubleScalarCos(c5_t_x);
  c5_u_x = c5_y;
  c5_v_x = c5_u_x;
  c5_v_x = muDoubleScalarSin(c5_v_x);
  c5_w_x = c5_r;
  c5_x_x = c5_w_x;
  c5_x_x = muDoubleScalarSin(c5_x_x);
  c5_y_x = c5_y;
  c5_ab_x = c5_y_x;
  c5_ab_x = muDoubleScalarSin(c5_ab_x);
  c5_bb_x = c5_p;
  c5_cb_x = c5_bb_x;
  c5_cb_x = muDoubleScalarCos(c5_cb_x);
  c5_db_x = c5_y;
  c5_eb_x = c5_db_x;
  c5_eb_x = muDoubleScalarSin(c5_eb_x);
  c5_fb_x = c5_p;
  c5_gb_x = c5_fb_x;
  c5_gb_x = muDoubleScalarSin(c5_gb_x);
  c5_hb_x = c5_r;
  c5_ib_x = c5_hb_x;
  c5_ib_x = muDoubleScalarSin(c5_ib_x);
  c5_jb_x = c5_y;
  c5_kb_x = c5_jb_x;
  c5_kb_x = muDoubleScalarCos(c5_kb_x);
  c5_lb_x = c5_r;
  c5_mb_x = c5_lb_x;
  c5_mb_x = muDoubleScalarCos(c5_mb_x);
  c5_nb_x = c5_y;
  c5_ob_x = c5_nb_x;
  c5_ob_x = muDoubleScalarSin(c5_ob_x);
  c5_pb_x = c5_p;
  c5_qb_x = c5_pb_x;
  c5_qb_x = muDoubleScalarSin(c5_qb_x);
  c5_rb_x = c5_r;
  c5_sb_x = c5_rb_x;
  c5_sb_x = muDoubleScalarCos(c5_sb_x);
  c5_tb_x = c5_y;
  c5_ub_x = c5_tb_x;
  c5_ub_x = muDoubleScalarCos(c5_ub_x);
  c5_vb_x = c5_r;
  c5_wb_x = c5_vb_x;
  c5_wb_x = muDoubleScalarSin(c5_wb_x);
  c5_xb_x = c5_p;
  c5_yb_x = c5_xb_x;
  c5_yb_x = muDoubleScalarSin(c5_yb_x);
  c5_ac_x = c5_p;
  c5_bc_x = c5_ac_x;
  c5_bc_x = muDoubleScalarCos(c5_bc_x);
  c5_cc_x = c5_r;
  c5_dc_x = c5_cc_x;
  c5_dc_x = muDoubleScalarSin(c5_dc_x);
  c5_ec_x = c5_p;
  c5_fc_x = c5_ec_x;
  c5_fc_x = muDoubleScalarCos(c5_fc_x);
  c5_gc_x = c5_r;
  c5_hc_x = c5_gc_x;
  c5_hc_x = muDoubleScalarCos(c5_hc_x);
  c5_RPYrot[0] = c5_b_x * c5_d_x;
  c5_RPYrot[3] = c5_f_x * c5_h_x * c5_j_x - c5_l_x * c5_n_x;
  c5_RPYrot[6] = c5_p_x * c5_r_x * c5_t_x + c5_v_x * c5_x_x;
  c5_RPYrot[1] = c5_ab_x * c5_cb_x;
  c5_RPYrot[4] = c5_eb_x * c5_gb_x * c5_ib_x + c5_kb_x * c5_mb_x;
  c5_RPYrot[7] = c5_ob_x * c5_qb_x * c5_sb_x - c5_ub_x * c5_wb_x;
  c5_RPYrot[2] = -c5_yb_x;
  c5_RPYrot[5] = c5_bc_x * c5_dc_x;
  c5_RPYrot[8] = c5_fc_x * c5_hc_x;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 12);
  for (c5_i4 = 0; c5_i4 < 9; c5_i4++) {
    c5_b_DCM[c5_i4] = c5_RPYrot[c5_i4];
  }

  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, -12);
  _SFD_SYMBOL_SCOPE_POP();
  for (c5_i5 = 0; c5_i5 < 9; c5_i5++) {
    (*chartInstance->c5_DCM)[c5_i5] = c5_b_DCM[c5_i5];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c5_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY
    (_wabs_perceptionmodel_VPT_Limbic_v3_adjMachineNumber_,
     chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c5_i6 = 0; c5_i6 < 9; c5_i6++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c5_DCM)[c5_i6], 1U);
  }
}

static void mdl_start_c5_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SFc5_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void initSimStructsc5_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SFc5_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c5_machineNumber, uint32_T
  c5_chartNumber, uint32_T c5_instanceNumber)
{
  (void)c5_machineNumber;
  (void)c5_chartNumber;
  (void)c5_instanceNumber;
}

static const mxArray *c5_sf_marshallOut(void *chartInstanceVoid, void *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i7;
  int32_T c5_i8;
  int32_T c5_i9;
  real_T c5_b_inData[9];
  int32_T c5_i10;
  int32_T c5_i11;
  int32_T c5_i12;
  real_T c5_u[9];
  const mxArray *c5_y = NULL;
  SFc5_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance;
  chartInstance = (SFc5_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *)
    chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_i7 = 0;
  for (c5_i8 = 0; c5_i8 < 3; c5_i8++) {
    for (c5_i9 = 0; c5_i9 < 3; c5_i9++) {
      c5_b_inData[c5_i9 + c5_i7] = (*(real_T (*)[9])c5_inData)[c5_i9 + c5_i7];
    }

    c5_i7 += 3;
  }

  c5_i10 = 0;
  for (c5_i11 = 0; c5_i11 < 3; c5_i11++) {
    for (c5_i12 = 0; c5_i12 < 3; c5_i12++) {
      c5_u[c5_i12 + c5_i10] = c5_b_inData[c5_i12 + c5_i10];
    }

    c5_i10 += 3;
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 0, 0U, 1U, 0U, 2, 3, 3), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static void c5_emlrt_marshallIn
  (SFc5_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance,
   const mxArray *c5_b_DCM, const char_T *c5_identifier, real_T c5_y[9])
{
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_DCM), &c5_thisId, c5_y);
  sf_mex_destroy(&c5_b_DCM);
}

static void c5_b_emlrt_marshallIn
  (SFc5_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance,
   const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId, real_T c5_y[9])
{
  real_T c5_dv1[9];
  int32_T c5_i13;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), c5_dv1, 1, 0, 0U, 1, 0U, 2, 3, 3);
  for (c5_i13 = 0; c5_i13 < 9; c5_i13++) {
    c5_y[c5_i13] = c5_dv1[c5_i13];
  }

  sf_mex_destroy(&c5_u);
}

static void c5_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_b_DCM;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  real_T c5_y[9];
  int32_T c5_i14;
  int32_T c5_i15;
  int32_T c5_i16;
  SFc5_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance;
  chartInstance = (SFc5_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *)
    chartInstanceVoid;
  c5_b_DCM = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_DCM), &c5_thisId, c5_y);
  sf_mex_destroy(&c5_b_DCM);
  c5_i14 = 0;
  for (c5_i15 = 0; c5_i15 < 3; c5_i15++) {
    for (c5_i16 = 0; c5_i16 < 3; c5_i16++) {
      (*(real_T (*)[9])c5_outData)[c5_i16 + c5_i14] = c5_y[c5_i16 + c5_i14];
    }

    c5_i14 += 3;
  }

  sf_mex_destroy(&c5_mxArrayInData);
}

static const mxArray *c5_b_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i17;
  real_T c5_b_inData[3];
  int32_T c5_i18;
  real_T c5_u[3];
  const mxArray *c5_y = NULL;
  SFc5_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance;
  chartInstance = (SFc5_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *)
    chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  for (c5_i17 = 0; c5_i17 < 3; c5_i17++) {
    c5_b_inData[c5_i17] = (*(real_T (*)[3])c5_inData)[c5_i17];
  }

  for (c5_i18 = 0; c5_i18 < 3; c5_i18++) {
    c5_u[c5_i18] = c5_b_inData[c5_i18];
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 0, 0U, 1U, 0U, 1, 3), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static const mxArray *c5_c_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  real_T c5_u;
  const mxArray *c5_y = NULL;
  SFc5_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance;
  chartInstance = (SFc5_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *)
    chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_u = *(real_T *)c5_inData;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", &c5_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static real_T c5_c_emlrt_marshallIn
  (SFc5_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance,
   const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  real_T c5_y;
  real_T c5_d0;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_d0, 1, 0, 0U, 0, 0U, 0);
  c5_y = c5_d0;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void c5_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_nargout;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  real_T c5_y;
  SFc5_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance;
  chartInstance = (SFc5_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *)
    chartInstanceVoid;
  c5_nargout = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_nargout), &c5_thisId);
  sf_mex_destroy(&c5_nargout);
  *(real_T *)c5_outData = c5_y;
  sf_mex_destroy(&c5_mxArrayInData);
}

const mxArray
  *sf_c5_wabs_perceptionmodel_VPT_Limbic_v3_adj_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c5_nameCaptureInfo = NULL;
  c5_nameCaptureInfo = NULL;
  sf_mex_assign(&c5_nameCaptureInfo, sf_mex_createstruct("structure", 2, 4, 1),
                false);
  c5_info_helper(&c5_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c5_nameCaptureInfo);
  return c5_nameCaptureInfo;
}

static void c5_info_helper(const mxArray **c5_info)
{
  const mxArray *c5_rhs0 = NULL;
  const mxArray *c5_lhs0 = NULL;
  const mxArray *c5_rhs1 = NULL;
  const mxArray *c5_lhs1 = NULL;
  const mxArray *c5_rhs2 = NULL;
  const mxArray *c5_lhs2 = NULL;
  const mxArray *c5_rhs3 = NULL;
  const mxArray *c5_lhs3 = NULL;
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("cos"), "name", "name", 0);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1395328496U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c5_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs0), "rhs", "rhs", 0);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs0), "lhs", "lhs", 0);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m"), "context",
                  "context", 1);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_scalar_cos"), "name",
                  "name", 1);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1286818722U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c5_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs1), "rhs", "rhs", 1);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs1), "lhs", "lhs", 1);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(""), "context", "context", 2);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("sin"), "name", "name", 2);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1395328504U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c5_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs2), "rhs", "rhs", 2);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs2), "lhs", "lhs", 2);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_scalar_sin"), "name",
                  "name", 3);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1286818736U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c5_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs3), "rhs", "rhs", 3);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs3), "lhs", "lhs", 3);
  sf_mex_destroy(&c5_rhs0);
  sf_mex_destroy(&c5_lhs0);
  sf_mex_destroy(&c5_rhs1);
  sf_mex_destroy(&c5_lhs1);
  sf_mex_destroy(&c5_rhs2);
  sf_mex_destroy(&c5_lhs2);
  sf_mex_destroy(&c5_rhs3);
  sf_mex_destroy(&c5_lhs3);
}

static const mxArray *c5_emlrt_marshallOut(const char * c5_u)
{
  const mxArray *c5_y = NULL;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c5_u)), false);
  return c5_y;
}

static const mxArray *c5_b_emlrt_marshallOut(const uint32_T c5_u)
{
  const mxArray *c5_y = NULL;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", &c5_u, 7, 0U, 0U, 0U, 0), false);
  return c5_y;
}

static const mxArray *c5_d_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_u;
  const mxArray *c5_y = NULL;
  SFc5_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance;
  chartInstance = (SFc5_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *)
    chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_u = *(int32_T *)c5_inData;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", &c5_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, false);
  return c5_mxArrayOutData;
}

static int32_T c5_d_emlrt_marshallIn
  (SFc5_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance,
   const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  int32_T c5_y;
  int32_T c5_i19;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_i19, 1, 6, 0U, 0, 0U, 0);
  c5_y = c5_i19;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void c5_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_b_sfEvent;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  int32_T c5_y;
  SFc5_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance;
  chartInstance = (SFc5_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *)
    chartInstanceVoid;
  c5_b_sfEvent = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_sfEvent),
    &c5_thisId);
  sf_mex_destroy(&c5_b_sfEvent);
  *(int32_T *)c5_outData = c5_y;
  sf_mex_destroy(&c5_mxArrayInData);
}

static uint8_T c5_e_emlrt_marshallIn
  (SFc5_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance,
   const mxArray *c5_b_is_active_c5_wabs_perceptionmodel_VPT_Limbic_v3_adj,
   const char_T *c5_identifier)
{
  uint8_T c5_y;
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c5_b_is_active_c5_wabs_perceptionmodel_VPT_Limbic_v3_adj), &c5_thisId);
  sf_mex_destroy(&c5_b_is_active_c5_wabs_perceptionmodel_VPT_Limbic_v3_adj);
  return c5_y;
}

static uint8_T c5_f_emlrt_marshallIn
  (SFc5_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance,
   const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  uint8_T c5_y;
  uint8_T c5_u0;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_u0, 1, 3, 0U, 0, 0U, 0);
  c5_y = c5_u0;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void init_dsm_address_info
  (SFc5_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address
  (SFc5_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance)
{
  chartInstance->c5_RPY = (real_T (*)[3])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c5_DCM = (real_T (*)[9])ssGetOutputPortSignal_wrapper
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

void sf_c5_wabs_perceptionmodel_VPT_Limbic_v3_adj_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(883773522U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(853685170U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(31244891U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1931396024U);
}

mxArray* sf_c5_wabs_perceptionmodel_VPT_Limbic_v3_adj_get_post_codegen_info(void);
mxArray *sf_c5_wabs_perceptionmodel_VPT_Limbic_v3_adj_get_autoinheritance_info
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
      sf_c5_wabs_perceptionmodel_VPT_Limbic_v3_adj_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c5_wabs_perceptionmodel_VPT_Limbic_v3_adj_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c5_wabs_perceptionmodel_VPT_Limbic_v3_adj_jit_fallback_info(void)
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

mxArray *sf_c5_wabs_perceptionmodel_VPT_Limbic_v3_adj_updateBuildInfo_args_info
  (void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c5_wabs_perceptionmodel_VPT_Limbic_v3_adj_get_post_codegen_info(void)
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
  *sf_get_sim_state_info_c5_wabs_perceptionmodel_VPT_Limbic_v3_adj(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"DCM\",},{M[8],M[0],T\"is_active_c5_wabs_perceptionmodel_VPT_Limbic_v3_adj\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c5_wabs_perceptionmodel_VPT_Limbic_v3_adj_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc5_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc5_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _wabs_perceptionmodel_VPT_Limbic_v3_adjMachineNumber_,
           5,
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
            1.0,0,0,(MexFcnForType)c5_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)
            c5_sf_marshallIn);
        }

        _SFD_SET_DATA_VALUE_PTR(0U, *chartInstance->c5_RPY);
        _SFD_SET_DATA_VALUE_PTR(1U, *chartInstance->c5_DCM);
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

static void sf_opaque_initialize_c5_wabs_perceptionmodel_VPT_Limbic_v3_adj(void *
  chartInstanceVar)
{
  chart_debug_initialization
    (((SFc5_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct*)
      chartInstanceVar)->S,0);
  initialize_params_c5_wabs_perceptionmodel_VPT_Limbic_v3_adj
    ((SFc5_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct*)
     chartInstanceVar);
  initialize_c5_wabs_perceptionmodel_VPT_Limbic_v3_adj
    ((SFc5_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct*)
     chartInstanceVar);
}

static void sf_opaque_enable_c5_wabs_perceptionmodel_VPT_Limbic_v3_adj(void
  *chartInstanceVar)
{
  enable_c5_wabs_perceptionmodel_VPT_Limbic_v3_adj
    ((SFc5_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct*)
     chartInstanceVar);
}

static void sf_opaque_disable_c5_wabs_perceptionmodel_VPT_Limbic_v3_adj(void
  *chartInstanceVar)
{
  disable_c5_wabs_perceptionmodel_VPT_Limbic_v3_adj
    ((SFc5_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct*)
     chartInstanceVar);
}

static void sf_opaque_gateway_c5_wabs_perceptionmodel_VPT_Limbic_v3_adj(void
  *chartInstanceVar)
{
  sf_gateway_c5_wabs_perceptionmodel_VPT_Limbic_v3_adj
    ((SFc5_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct*)
     chartInstanceVar);
}

static const mxArray*
  sf_opaque_get_sim_state_c5_wabs_perceptionmodel_VPT_Limbic_v3_adj(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c5_wabs_perceptionmodel_VPT_Limbic_v3_adj
    ((SFc5_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct*)
     chartInfo->chartInstance);        /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c5_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SimStruct* S, const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c5_wabs_perceptionmodel_VPT_Limbic_v3_adj
    ((SFc5_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct*)
     chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c5_wabs_perceptionmodel_VPT_Limbic_v3_adj(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc5_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct*)
                    chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_wabs_perceptionmodel_VPT_Limbic_v3_adj_optimization_info();
    }

    finalize_c5_wabs_perceptionmodel_VPT_Limbic_v3_adj
      ((SFc5_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct*)
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
  initSimStructsc5_wabs_perceptionmodel_VPT_Limbic_v3_adj
    ((SFc5_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct*)
     chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c5_wabs_perceptionmodel_VPT_Limbic_v3_adj
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
    initialize_params_c5_wabs_perceptionmodel_VPT_Limbic_v3_adj
      ((SFc5_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct*)
       (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c5_wabs_perceptionmodel_VPT_Limbic_v3_adj(SimStruct
  *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct =
      load_wabs_perceptionmodel_VPT_Limbic_v3_adj_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,5);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,5,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,5,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,5);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,5,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,5,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,5);
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

static void mdlRTW_c5_wabs_perceptionmodel_VPT_Limbic_v3_adj(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c5_wabs_perceptionmodel_VPT_Limbic_v3_adj(SimStruct *S)
{
  SFc5_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc5_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *)
    utMalloc(sizeof(SFc5_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct));
  memset(chartInstance, 0, sizeof
         (SFc5_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c5_wabs_perceptionmodel_VPT_Limbic_v3_adj;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c5_wabs_perceptionmodel_VPT_Limbic_v3_adj;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c5_wabs_perceptionmodel_VPT_Limbic_v3_adj;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c5_wabs_perceptionmodel_VPT_Limbic_v3_adj;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c5_wabs_perceptionmodel_VPT_Limbic_v3_adj;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c5_wabs_perceptionmodel_VPT_Limbic_v3_adj;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c5_wabs_perceptionmodel_VPT_Limbic_v3_adj;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c5_wabs_perceptionmodel_VPT_Limbic_v3_adj;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW =
    mdlRTW_c5_wabs_perceptionmodel_VPT_Limbic_v3_adj;
  chartInstance->chartInfo.mdlStart =
    mdlStart_c5_wabs_perceptionmodel_VPT_Limbic_v3_adj;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c5_wabs_perceptionmodel_VPT_Limbic_v3_adj;
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

void c5_wabs_perceptionmodel_VPT_Limbic_v3_adj_method_dispatcher(SimStruct *S,
  int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c5_wabs_perceptionmodel_VPT_Limbic_v3_adj(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c5_wabs_perceptionmodel_VPT_Limbic_v3_adj(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c5_wabs_perceptionmodel_VPT_Limbic_v3_adj(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c5_wabs_perceptionmodel_VPT_Limbic_v3_adj_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
