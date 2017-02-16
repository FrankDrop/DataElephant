/* Include files */

#include <stddef.h>
#include "blas.h"
#include "wabs_perceptionmodel_VPT_Limbic_v3_adj_sfun.h"
#include "c6_wabs_perceptionmodel_VPT_Limbic_v3_adj.h"
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
static const char * c6_debug_family_names[8] = { "r", "p", "y", "RPYrot",
  "nargin", "nargout", "RPY", "DCM" };

/* Function Declarations */
static void initialize_c6_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SFc6_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance);
static void initialize_params_c6_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SFc6_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance);
static void enable_c6_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SFc6_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance);
static void disable_c6_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SFc6_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance);
static void c6_update_debugger_state_c6_wabs_perceptionmodel_VPT_Limbic_v3_a
  (SFc6_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c6_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SFc6_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance);
static void set_sim_state_c6_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SFc6_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance,
   const mxArray *c6_st);
static void finalize_c6_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SFc6_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance);
static void sf_gateway_c6_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SFc6_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance);
static void mdl_start_c6_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SFc6_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance);
static void initSimStructsc6_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SFc6_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c6_machineNumber, uint32_T
  c6_chartNumber, uint32_T c6_instanceNumber);
static const mxArray *c6_sf_marshallOut(void *chartInstanceVoid, void *c6_inData);
static void c6_emlrt_marshallIn
  (SFc6_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance,
   const mxArray *c6_b_DCM, const char_T *c6_identifier, real_T c6_y[9]);
static void c6_b_emlrt_marshallIn
  (SFc6_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance,
   const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId, real_T c6_y[9]);
static void c6_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static const mxArray *c6_b_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static const mxArray *c6_c_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static real_T c6_c_emlrt_marshallIn
  (SFc6_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance,
   const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId);
static void c6_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static void c6_info_helper(const mxArray **c6_info);
static const mxArray *c6_emlrt_marshallOut(const char * c6_u);
static const mxArray *c6_b_emlrt_marshallOut(const uint32_T c6_u);
static const mxArray *c6_d_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static int32_T c6_d_emlrt_marshallIn
  (SFc6_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance,
   const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId);
static void c6_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static uint8_T c6_e_emlrt_marshallIn
  (SFc6_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance,
   const mxArray *c6_b_is_active_c6_wabs_perceptionmodel_VPT_Limbic_v3_adj,
   const char_T *c6_identifier);
static uint8_T c6_f_emlrt_marshallIn
  (SFc6_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance,
   const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId);
static void init_dsm_address_info
  (SFc6_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance);
static void init_simulink_io_address
  (SFc6_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c6_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SFc6_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance)
{
  chartInstance->c6_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c6_is_active_c6_wabs_perceptionmodel_VPT_Limbic_v3_adj = 0U;
}

static void initialize_params_c6_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SFc6_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c6_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SFc6_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c6_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SFc6_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c6_update_debugger_state_c6_wabs_perceptionmodel_VPT_Limbic_v3_a
  (SFc6_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c6_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SFc6_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance)
{
  const mxArray *c6_st;
  const mxArray *c6_y = NULL;
  int32_T c6_i0;
  real_T c6_u[9];
  const mxArray *c6_b_y = NULL;
  uint8_T c6_hoistedGlobal;
  uint8_T c6_b_u;
  const mxArray *c6_c_y = NULL;
  c6_st = NULL;
  c6_st = NULL;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_createcellmatrix(2, 1), false);
  for (c6_i0 = 0; c6_i0 < 9; c6_i0++) {
    c6_u[c6_i0] = (*chartInstance->c6_DCM)[c6_i0];
  }

  c6_b_y = NULL;
  sf_mex_assign(&c6_b_y, sf_mex_create("y", c6_u, 0, 0U, 1U, 0U, 2, 3, 3), false);
  sf_mex_setcell(c6_y, 0, c6_b_y);
  c6_hoistedGlobal =
    chartInstance->c6_is_active_c6_wabs_perceptionmodel_VPT_Limbic_v3_adj;
  c6_b_u = c6_hoistedGlobal;
  c6_c_y = NULL;
  sf_mex_assign(&c6_c_y, sf_mex_create("y", &c6_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c6_y, 1, c6_c_y);
  sf_mex_assign(&c6_st, c6_y, false);
  return c6_st;
}

static void set_sim_state_c6_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SFc6_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance,
   const mxArray *c6_st)
{
  const mxArray *c6_u;
  real_T c6_dv0[9];
  int32_T c6_i1;
  chartInstance->c6_doneDoubleBufferReInit = true;
  c6_u = sf_mex_dup(c6_st);
  c6_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c6_u, 0)), "DCM",
                      c6_dv0);
  for (c6_i1 = 0; c6_i1 < 9; c6_i1++) {
    (*chartInstance->c6_DCM)[c6_i1] = c6_dv0[c6_i1];
  }

  chartInstance->c6_is_active_c6_wabs_perceptionmodel_VPT_Limbic_v3_adj =
    c6_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c6_u, 1)),
    "is_active_c6_wabs_perceptionmodel_VPT_Limbic_v3_adj");
  sf_mex_destroy(&c6_u);
  c6_update_debugger_state_c6_wabs_perceptionmodel_VPT_Limbic_v3_a(chartInstance);
  sf_mex_destroy(&c6_st);
}

static void finalize_c6_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SFc6_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c6_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SFc6_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance)
{
  int32_T c6_i2;
  int32_T c6_i3;
  real_T c6_b_RPY[3];
  uint32_T c6_debug_family_var_map[8];
  real_T c6_r;
  real_T c6_p;
  real_T c6_y;
  real_T c6_RPYrot[9];
  real_T c6_nargin = 1.0;
  real_T c6_nargout = 1.0;
  real_T c6_b_DCM[9];
  real_T c6_x;
  real_T c6_b_x;
  real_T c6_c_x;
  real_T c6_d_x;
  real_T c6_e_x;
  real_T c6_f_x;
  real_T c6_g_x;
  real_T c6_h_x;
  real_T c6_i_x;
  real_T c6_j_x;
  real_T c6_k_x;
  real_T c6_l_x;
  real_T c6_m_x;
  real_T c6_n_x;
  real_T c6_o_x;
  real_T c6_p_x;
  real_T c6_q_x;
  real_T c6_r_x;
  real_T c6_s_x;
  real_T c6_t_x;
  real_T c6_u_x;
  real_T c6_v_x;
  real_T c6_w_x;
  real_T c6_x_x;
  real_T c6_y_x;
  real_T c6_ab_x;
  real_T c6_bb_x;
  real_T c6_cb_x;
  real_T c6_db_x;
  real_T c6_eb_x;
  real_T c6_fb_x;
  real_T c6_gb_x;
  real_T c6_hb_x;
  real_T c6_ib_x;
  real_T c6_jb_x;
  real_T c6_kb_x;
  real_T c6_lb_x;
  real_T c6_mb_x;
  real_T c6_nb_x;
  real_T c6_ob_x;
  real_T c6_pb_x;
  real_T c6_qb_x;
  real_T c6_rb_x;
  real_T c6_sb_x;
  real_T c6_tb_x;
  real_T c6_ub_x;
  real_T c6_vb_x;
  real_T c6_wb_x;
  real_T c6_xb_x;
  real_T c6_yb_x;
  real_T c6_ac_x;
  real_T c6_bc_x;
  real_T c6_cc_x;
  real_T c6_dc_x;
  real_T c6_ec_x;
  real_T c6_fc_x;
  real_T c6_gc_x;
  real_T c6_hc_x;
  int32_T c6_i4;
  int32_T c6_i5;
  int32_T c6_i6;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 5U, chartInstance->c6_sfEvent);
  for (c6_i2 = 0; c6_i2 < 3; c6_i2++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c6_RPY)[c6_i2], 0U);
  }

  chartInstance->c6_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 5U, chartInstance->c6_sfEvent);
  for (c6_i3 = 0; c6_i3 < 3; c6_i3++) {
    c6_b_RPY[c6_i3] = (*chartInstance->c6_RPY)[c6_i3];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 8U, 8U, c6_debug_family_names,
    c6_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_r, 0U, c6_c_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_p, 1U, c6_c_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_y, 2U, c6_c_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_RPYrot, 3U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_nargin, 4U, c6_c_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_nargout, 5U, c6_c_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c6_b_RPY, 6U, c6_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_b_DCM, 7U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 5);
  c6_r = c6_b_RPY[0];
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 6);
  c6_p = c6_b_RPY[1];
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 7);
  c6_y = c6_b_RPY[2];
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 8);
  c6_x = c6_y;
  c6_b_x = c6_x;
  c6_b_x = muDoubleScalarCos(c6_b_x);
  c6_c_x = c6_p;
  c6_d_x = c6_c_x;
  c6_d_x = muDoubleScalarCos(c6_d_x);
  c6_e_x = c6_y;
  c6_f_x = c6_e_x;
  c6_f_x = muDoubleScalarCos(c6_f_x);
  c6_g_x = c6_p;
  c6_h_x = c6_g_x;
  c6_h_x = muDoubleScalarSin(c6_h_x);
  c6_i_x = c6_r;
  c6_j_x = c6_i_x;
  c6_j_x = muDoubleScalarSin(c6_j_x);
  c6_k_x = c6_y;
  c6_l_x = c6_k_x;
  c6_l_x = muDoubleScalarSin(c6_l_x);
  c6_m_x = c6_r;
  c6_n_x = c6_m_x;
  c6_n_x = muDoubleScalarCos(c6_n_x);
  c6_o_x = c6_y;
  c6_p_x = c6_o_x;
  c6_p_x = muDoubleScalarCos(c6_p_x);
  c6_q_x = c6_p;
  c6_r_x = c6_q_x;
  c6_r_x = muDoubleScalarSin(c6_r_x);
  c6_s_x = c6_r;
  c6_t_x = c6_s_x;
  c6_t_x = muDoubleScalarCos(c6_t_x);
  c6_u_x = c6_y;
  c6_v_x = c6_u_x;
  c6_v_x = muDoubleScalarSin(c6_v_x);
  c6_w_x = c6_r;
  c6_x_x = c6_w_x;
  c6_x_x = muDoubleScalarSin(c6_x_x);
  c6_y_x = c6_y;
  c6_ab_x = c6_y_x;
  c6_ab_x = muDoubleScalarSin(c6_ab_x);
  c6_bb_x = c6_p;
  c6_cb_x = c6_bb_x;
  c6_cb_x = muDoubleScalarCos(c6_cb_x);
  c6_db_x = c6_y;
  c6_eb_x = c6_db_x;
  c6_eb_x = muDoubleScalarSin(c6_eb_x);
  c6_fb_x = c6_p;
  c6_gb_x = c6_fb_x;
  c6_gb_x = muDoubleScalarSin(c6_gb_x);
  c6_hb_x = c6_r;
  c6_ib_x = c6_hb_x;
  c6_ib_x = muDoubleScalarSin(c6_ib_x);
  c6_jb_x = c6_y;
  c6_kb_x = c6_jb_x;
  c6_kb_x = muDoubleScalarCos(c6_kb_x);
  c6_lb_x = c6_r;
  c6_mb_x = c6_lb_x;
  c6_mb_x = muDoubleScalarCos(c6_mb_x);
  c6_nb_x = c6_y;
  c6_ob_x = c6_nb_x;
  c6_ob_x = muDoubleScalarSin(c6_ob_x);
  c6_pb_x = c6_p;
  c6_qb_x = c6_pb_x;
  c6_qb_x = muDoubleScalarSin(c6_qb_x);
  c6_rb_x = c6_r;
  c6_sb_x = c6_rb_x;
  c6_sb_x = muDoubleScalarCos(c6_sb_x);
  c6_tb_x = c6_y;
  c6_ub_x = c6_tb_x;
  c6_ub_x = muDoubleScalarCos(c6_ub_x);
  c6_vb_x = c6_r;
  c6_wb_x = c6_vb_x;
  c6_wb_x = muDoubleScalarSin(c6_wb_x);
  c6_xb_x = c6_p;
  c6_yb_x = c6_xb_x;
  c6_yb_x = muDoubleScalarSin(c6_yb_x);
  c6_ac_x = c6_p;
  c6_bc_x = c6_ac_x;
  c6_bc_x = muDoubleScalarCos(c6_bc_x);
  c6_cc_x = c6_r;
  c6_dc_x = c6_cc_x;
  c6_dc_x = muDoubleScalarSin(c6_dc_x);
  c6_ec_x = c6_p;
  c6_fc_x = c6_ec_x;
  c6_fc_x = muDoubleScalarCos(c6_fc_x);
  c6_gc_x = c6_r;
  c6_hc_x = c6_gc_x;
  c6_hc_x = muDoubleScalarCos(c6_hc_x);
  c6_RPYrot[0] = c6_b_x * c6_d_x;
  c6_RPYrot[3] = c6_f_x * c6_h_x * c6_j_x - c6_l_x * c6_n_x;
  c6_RPYrot[6] = c6_p_x * c6_r_x * c6_t_x + c6_v_x * c6_x_x;
  c6_RPYrot[1] = c6_ab_x * c6_cb_x;
  c6_RPYrot[4] = c6_eb_x * c6_gb_x * c6_ib_x + c6_kb_x * c6_mb_x;
  c6_RPYrot[7] = c6_ob_x * c6_qb_x * c6_sb_x - c6_ub_x * c6_wb_x;
  c6_RPYrot[2] = -c6_yb_x;
  c6_RPYrot[5] = c6_bc_x * c6_dc_x;
  c6_RPYrot[8] = c6_fc_x * c6_hc_x;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 12);
  for (c6_i4 = 0; c6_i4 < 9; c6_i4++) {
    c6_b_DCM[c6_i4] = c6_RPYrot[c6_i4];
  }

  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, -12);
  _SFD_SYMBOL_SCOPE_POP();
  for (c6_i5 = 0; c6_i5 < 9; c6_i5++) {
    (*chartInstance->c6_DCM)[c6_i5] = c6_b_DCM[c6_i5];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, chartInstance->c6_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY
    (_wabs_perceptionmodel_VPT_Limbic_v3_adjMachineNumber_,
     chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c6_i6 = 0; c6_i6 < 9; c6_i6++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c6_DCM)[c6_i6], 1U);
  }
}

static void mdl_start_c6_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SFc6_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void initSimStructsc6_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SFc6_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c6_machineNumber, uint32_T
  c6_chartNumber, uint32_T c6_instanceNumber)
{
  (void)c6_machineNumber;
  (void)c6_chartNumber;
  (void)c6_instanceNumber;
}

static const mxArray *c6_sf_marshallOut(void *chartInstanceVoid, void *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_i7;
  int32_T c6_i8;
  int32_T c6_i9;
  real_T c6_b_inData[9];
  int32_T c6_i10;
  int32_T c6_i11;
  int32_T c6_i12;
  real_T c6_u[9];
  const mxArray *c6_y = NULL;
  SFc6_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance;
  chartInstance = (SFc6_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *)
    chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_i7 = 0;
  for (c6_i8 = 0; c6_i8 < 3; c6_i8++) {
    for (c6_i9 = 0; c6_i9 < 3; c6_i9++) {
      c6_b_inData[c6_i9 + c6_i7] = (*(real_T (*)[9])c6_inData)[c6_i9 + c6_i7];
    }

    c6_i7 += 3;
  }

  c6_i10 = 0;
  for (c6_i11 = 0; c6_i11 < 3; c6_i11++) {
    for (c6_i12 = 0; c6_i12 < 3; c6_i12++) {
      c6_u[c6_i12 + c6_i10] = c6_b_inData[c6_i12 + c6_i10];
    }

    c6_i10 += 3;
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 0, 0U, 1U, 0U, 2, 3, 3), false);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, false);
  return c6_mxArrayOutData;
}

static void c6_emlrt_marshallIn
  (SFc6_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance,
   const mxArray *c6_b_DCM, const char_T *c6_identifier, real_T c6_y[9])
{
  emlrtMsgIdentifier c6_thisId;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_DCM), &c6_thisId, c6_y);
  sf_mex_destroy(&c6_b_DCM);
}

static void c6_b_emlrt_marshallIn
  (SFc6_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance,
   const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId, real_T c6_y[9])
{
  real_T c6_dv1[9];
  int32_T c6_i13;
  (void)chartInstance;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), c6_dv1, 1, 0, 0U, 1, 0U, 2, 3, 3);
  for (c6_i13 = 0; c6_i13 < 9; c6_i13++) {
    c6_y[c6_i13] = c6_dv1[c6_i13];
  }

  sf_mex_destroy(&c6_u);
}

static void c6_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_b_DCM;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  real_T c6_y[9];
  int32_T c6_i14;
  int32_T c6_i15;
  int32_T c6_i16;
  SFc6_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance;
  chartInstance = (SFc6_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *)
    chartInstanceVoid;
  c6_b_DCM = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_DCM), &c6_thisId, c6_y);
  sf_mex_destroy(&c6_b_DCM);
  c6_i14 = 0;
  for (c6_i15 = 0; c6_i15 < 3; c6_i15++) {
    for (c6_i16 = 0; c6_i16 < 3; c6_i16++) {
      (*(real_T (*)[9])c6_outData)[c6_i16 + c6_i14] = c6_y[c6_i16 + c6_i14];
    }

    c6_i14 += 3;
  }

  sf_mex_destroy(&c6_mxArrayInData);
}

static const mxArray *c6_b_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_i17;
  real_T c6_b_inData[3];
  int32_T c6_i18;
  real_T c6_u[3];
  const mxArray *c6_y = NULL;
  SFc6_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance;
  chartInstance = (SFc6_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *)
    chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  for (c6_i17 = 0; c6_i17 < 3; c6_i17++) {
    c6_b_inData[c6_i17] = (*(real_T (*)[3])c6_inData)[c6_i17];
  }

  for (c6_i18 = 0; c6_i18 < 3; c6_i18++) {
    c6_u[c6_i18] = c6_b_inData[c6_i18];
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 0, 0U, 1U, 0U, 1, 3), false);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, false);
  return c6_mxArrayOutData;
}

static const mxArray *c6_c_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  real_T c6_u;
  const mxArray *c6_y = NULL;
  SFc6_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance;
  chartInstance = (SFc6_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *)
    chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_u = *(real_T *)c6_inData;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", &c6_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, false);
  return c6_mxArrayOutData;
}

static real_T c6_c_emlrt_marshallIn
  (SFc6_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance,
   const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  real_T c6_y;
  real_T c6_d0;
  (void)chartInstance;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_d0, 1, 0, 0U, 0, 0U, 0);
  c6_y = c6_d0;
  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void c6_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_nargout;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  real_T c6_y;
  SFc6_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance;
  chartInstance = (SFc6_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *)
    chartInstanceVoid;
  c6_nargout = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_nargout), &c6_thisId);
  sf_mex_destroy(&c6_nargout);
  *(real_T *)c6_outData = c6_y;
  sf_mex_destroy(&c6_mxArrayInData);
}

const mxArray
  *sf_c6_wabs_perceptionmodel_VPT_Limbic_v3_adj_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c6_nameCaptureInfo = NULL;
  c6_nameCaptureInfo = NULL;
  sf_mex_assign(&c6_nameCaptureInfo, sf_mex_createstruct("structure", 2, 4, 1),
                false);
  c6_info_helper(&c6_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c6_nameCaptureInfo);
  return c6_nameCaptureInfo;
}

static void c6_info_helper(const mxArray **c6_info)
{
  const mxArray *c6_rhs0 = NULL;
  const mxArray *c6_lhs0 = NULL;
  const mxArray *c6_rhs1 = NULL;
  const mxArray *c6_lhs1 = NULL;
  const mxArray *c6_rhs2 = NULL;
  const mxArray *c6_lhs2 = NULL;
  const mxArray *c6_rhs3 = NULL;
  const mxArray *c6_lhs3 = NULL;
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("cos"), "name", "name", 0);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1395328496U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c6_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs0), "rhs", "rhs", 0);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs0), "lhs", "lhs", 0);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m"), "context",
                  "context", 1);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("eml_scalar_cos"), "name",
                  "name", 1);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1286818722U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c6_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs1), "rhs", "rhs", 1);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs1), "lhs", "lhs", 1);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(""), "context", "context", 2);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("sin"), "name", "name", 2);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1395328504U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c6_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs2), "rhs", "rhs", 2);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs2), "lhs", "lhs", 2);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("eml_scalar_sin"), "name",
                  "name", 3);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c6_info, c6_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(1286818736U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c6_info, c6_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c6_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c6_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_rhs3), "rhs", "rhs", 3);
  sf_mex_addfield(*c6_info, sf_mex_duplicatearraysafe(&c6_lhs3), "lhs", "lhs", 3);
  sf_mex_destroy(&c6_rhs0);
  sf_mex_destroy(&c6_lhs0);
  sf_mex_destroy(&c6_rhs1);
  sf_mex_destroy(&c6_lhs1);
  sf_mex_destroy(&c6_rhs2);
  sf_mex_destroy(&c6_lhs2);
  sf_mex_destroy(&c6_rhs3);
  sf_mex_destroy(&c6_lhs3);
}

static const mxArray *c6_emlrt_marshallOut(const char * c6_u)
{
  const mxArray *c6_y = NULL;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c6_u)), false);
  return c6_y;
}

static const mxArray *c6_b_emlrt_marshallOut(const uint32_T c6_u)
{
  const mxArray *c6_y = NULL;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", &c6_u, 7, 0U, 0U, 0U, 0), false);
  return c6_y;
}

static const mxArray *c6_d_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_u;
  const mxArray *c6_y = NULL;
  SFc6_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance;
  chartInstance = (SFc6_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *)
    chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_u = *(int32_T *)c6_inData;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", &c6_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, false);
  return c6_mxArrayOutData;
}

static int32_T c6_d_emlrt_marshallIn
  (SFc6_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance,
   const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  int32_T c6_y;
  int32_T c6_i19;
  (void)chartInstance;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_i19, 1, 6, 0U, 0, 0U, 0);
  c6_y = c6_i19;
  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void c6_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_b_sfEvent;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  int32_T c6_y;
  SFc6_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance;
  chartInstance = (SFc6_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *)
    chartInstanceVoid;
  c6_b_sfEvent = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_sfEvent),
    &c6_thisId);
  sf_mex_destroy(&c6_b_sfEvent);
  *(int32_T *)c6_outData = c6_y;
  sf_mex_destroy(&c6_mxArrayInData);
}

static uint8_T c6_e_emlrt_marshallIn
  (SFc6_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance,
   const mxArray *c6_b_is_active_c6_wabs_perceptionmodel_VPT_Limbic_v3_adj,
   const char_T *c6_identifier)
{
  uint8_T c6_y;
  emlrtMsgIdentifier c6_thisId;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c6_b_is_active_c6_wabs_perceptionmodel_VPT_Limbic_v3_adj), &c6_thisId);
  sf_mex_destroy(&c6_b_is_active_c6_wabs_perceptionmodel_VPT_Limbic_v3_adj);
  return c6_y;
}

static uint8_T c6_f_emlrt_marshallIn
  (SFc6_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance,
   const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  uint8_T c6_y;
  uint8_T c6_u0;
  (void)chartInstance;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_u0, 1, 3, 0U, 0, 0U, 0);
  c6_y = c6_u0;
  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void init_dsm_address_info
  (SFc6_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address
  (SFc6_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance)
{
  chartInstance->c6_RPY = (real_T (*)[3])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c6_DCM = (real_T (*)[9])ssGetOutputPortSignal_wrapper
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

void sf_c6_wabs_perceptionmodel_VPT_Limbic_v3_adj_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(883773522U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(853685170U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(31244891U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1931396024U);
}

mxArray* sf_c6_wabs_perceptionmodel_VPT_Limbic_v3_adj_get_post_codegen_info(void);
mxArray *sf_c6_wabs_perceptionmodel_VPT_Limbic_v3_adj_get_autoinheritance_info
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
      sf_c6_wabs_perceptionmodel_VPT_Limbic_v3_adj_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c6_wabs_perceptionmodel_VPT_Limbic_v3_adj_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c6_wabs_perceptionmodel_VPT_Limbic_v3_adj_jit_fallback_info(void)
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

mxArray *sf_c6_wabs_perceptionmodel_VPT_Limbic_v3_adj_updateBuildInfo_args_info
  (void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c6_wabs_perceptionmodel_VPT_Limbic_v3_adj_get_post_codegen_info(void)
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
  *sf_get_sim_state_info_c6_wabs_perceptionmodel_VPT_Limbic_v3_adj(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"DCM\",},{M[8],M[0],T\"is_active_c6_wabs_perceptionmodel_VPT_Limbic_v3_adj\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c6_wabs_perceptionmodel_VPT_Limbic_v3_adj_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc6_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc6_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _wabs_perceptionmodel_VPT_Limbic_v3_adjMachineNumber_,
           6,
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
            1.0,0,0,(MexFcnForType)c6_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c6_sf_marshallOut,(MexInFcnForType)
            c6_sf_marshallIn);
        }

        _SFD_SET_DATA_VALUE_PTR(0U, *chartInstance->c6_RPY);
        _SFD_SET_DATA_VALUE_PTR(1U, *chartInstance->c6_DCM);
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

static void sf_opaque_initialize_c6_wabs_perceptionmodel_VPT_Limbic_v3_adj(void *
  chartInstanceVar)
{
  chart_debug_initialization
    (((SFc6_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct*)
      chartInstanceVar)->S,0);
  initialize_params_c6_wabs_perceptionmodel_VPT_Limbic_v3_adj
    ((SFc6_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct*)
     chartInstanceVar);
  initialize_c6_wabs_perceptionmodel_VPT_Limbic_v3_adj
    ((SFc6_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct*)
     chartInstanceVar);
}

static void sf_opaque_enable_c6_wabs_perceptionmodel_VPT_Limbic_v3_adj(void
  *chartInstanceVar)
{
  enable_c6_wabs_perceptionmodel_VPT_Limbic_v3_adj
    ((SFc6_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct*)
     chartInstanceVar);
}

static void sf_opaque_disable_c6_wabs_perceptionmodel_VPT_Limbic_v3_adj(void
  *chartInstanceVar)
{
  disable_c6_wabs_perceptionmodel_VPT_Limbic_v3_adj
    ((SFc6_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct*)
     chartInstanceVar);
}

static void sf_opaque_gateway_c6_wabs_perceptionmodel_VPT_Limbic_v3_adj(void
  *chartInstanceVar)
{
  sf_gateway_c6_wabs_perceptionmodel_VPT_Limbic_v3_adj
    ((SFc6_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct*)
     chartInstanceVar);
}

static const mxArray*
  sf_opaque_get_sim_state_c6_wabs_perceptionmodel_VPT_Limbic_v3_adj(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c6_wabs_perceptionmodel_VPT_Limbic_v3_adj
    ((SFc6_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct*)
     chartInfo->chartInstance);        /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c6_wabs_perceptionmodel_VPT_Limbic_v3_adj
  (SimStruct* S, const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c6_wabs_perceptionmodel_VPT_Limbic_v3_adj
    ((SFc6_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct*)
     chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c6_wabs_perceptionmodel_VPT_Limbic_v3_adj(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc6_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct*)
                    chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_wabs_perceptionmodel_VPT_Limbic_v3_adj_optimization_info();
    }

    finalize_c6_wabs_perceptionmodel_VPT_Limbic_v3_adj
      ((SFc6_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct*)
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
  initSimStructsc6_wabs_perceptionmodel_VPT_Limbic_v3_adj
    ((SFc6_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct*)
     chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c6_wabs_perceptionmodel_VPT_Limbic_v3_adj
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
    initialize_params_c6_wabs_perceptionmodel_VPT_Limbic_v3_adj
      ((SFc6_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct*)
       (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c6_wabs_perceptionmodel_VPT_Limbic_v3_adj(SimStruct
  *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct =
      load_wabs_perceptionmodel_VPT_Limbic_v3_adj_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,6);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,6,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,6,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,6);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,6,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,6,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,6);
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

static void mdlRTW_c6_wabs_perceptionmodel_VPT_Limbic_v3_adj(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c6_wabs_perceptionmodel_VPT_Limbic_v3_adj(SimStruct *S)
{
  SFc6_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc6_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct *)
    utMalloc(sizeof(SFc6_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct));
  memset(chartInstance, 0, sizeof
         (SFc6_wabs_perceptionmodel_VPT_Limbic_v3_adjInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c6_wabs_perceptionmodel_VPT_Limbic_v3_adj;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c6_wabs_perceptionmodel_VPT_Limbic_v3_adj;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c6_wabs_perceptionmodel_VPT_Limbic_v3_adj;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c6_wabs_perceptionmodel_VPT_Limbic_v3_adj;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c6_wabs_perceptionmodel_VPT_Limbic_v3_adj;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c6_wabs_perceptionmodel_VPT_Limbic_v3_adj;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c6_wabs_perceptionmodel_VPT_Limbic_v3_adj;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c6_wabs_perceptionmodel_VPT_Limbic_v3_adj;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW =
    mdlRTW_c6_wabs_perceptionmodel_VPT_Limbic_v3_adj;
  chartInstance->chartInfo.mdlStart =
    mdlStart_c6_wabs_perceptionmodel_VPT_Limbic_v3_adj;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c6_wabs_perceptionmodel_VPT_Limbic_v3_adj;
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

void c6_wabs_perceptionmodel_VPT_Limbic_v3_adj_method_dispatcher(SimStruct *S,
  int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c6_wabs_perceptionmodel_VPT_Limbic_v3_adj(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c6_wabs_perceptionmodel_VPT_Limbic_v3_adj(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c6_wabs_perceptionmodel_VPT_Limbic_v3_adj(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c6_wabs_perceptionmodel_VPT_Limbic_v3_adj_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
