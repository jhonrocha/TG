/* Include files */

#include "blascompat32.h"
#include "LMI_lema_8_statefeedback_sfun.h"
#include "c1_LMI_lema_8_statefeedback.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "LMI_lema_8_statefeedback_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char * c1_debug_family_names[8] = { "ctes", "nargin", "nargout",
  "v1", "v2", "gama", "h", "dh" };

/* Function Declarations */
static void initialize_c1_LMI_lema_8_statefeedback
  (SFc1_LMI_lema_8_statefeedbackInstanceStruct *chartInstance);
static void initialize_params_c1_LMI_lema_8_statefeedback
  (SFc1_LMI_lema_8_statefeedbackInstanceStruct *chartInstance);
static void enable_c1_LMI_lema_8_statefeedback
  (SFc1_LMI_lema_8_statefeedbackInstanceStruct *chartInstance);
static void disable_c1_LMI_lema_8_statefeedback
  (SFc1_LMI_lema_8_statefeedbackInstanceStruct *chartInstance);
static void c1_update_debugger_state_c1_LMI_lema_8_statefeedback
  (SFc1_LMI_lema_8_statefeedbackInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c1_LMI_lema_8_statefeedback
  (SFc1_LMI_lema_8_statefeedbackInstanceStruct *chartInstance);
static void set_sim_state_c1_LMI_lema_8_statefeedback
  (SFc1_LMI_lema_8_statefeedbackInstanceStruct *chartInstance, const mxArray
   *c1_st);
static void finalize_c1_LMI_lema_8_statefeedback
  (SFc1_LMI_lema_8_statefeedbackInstanceStruct *chartInstance);
static void sf_c1_LMI_lema_8_statefeedback
  (SFc1_LMI_lema_8_statefeedbackInstanceStruct *chartInstance);
static void c1_chartstep_c1_LMI_lema_8_statefeedback
  (SFc1_LMI_lema_8_statefeedbackInstanceStruct *chartInstance);
static void initSimStructsc1_LMI_lema_8_statefeedback
  (SFc1_LMI_lema_8_statefeedbackInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber);
static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData);
static void c1_emlrt_marshallIn(SFc1_LMI_lema_8_statefeedbackInstanceStruct
  *chartInstance, const mxArray *c1_dh, const char_T *c1_identifier, real_T
  c1_y[4]);
static void c1_b_emlrt_marshallIn(SFc1_LMI_lema_8_statefeedbackInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[4]);
static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static real_T c1_c_emlrt_marshallIn(SFc1_LMI_lema_8_statefeedbackInstanceStruct *
  chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_d_emlrt_marshallIn(SFc1_LMI_lema_8_statefeedbackInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  c1_sbeJM90BjrqCzgdyR581lvE *c1_y);
static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static void c1_eml_error(SFc1_LMI_lema_8_statefeedbackInstanceStruct
  *chartInstance);
static const mxArray *c1_e_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static int32_T c1_e_emlrt_marshallIn(SFc1_LMI_lema_8_statefeedbackInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static uint8_T c1_f_emlrt_marshallIn(SFc1_LMI_lema_8_statefeedbackInstanceStruct
  *chartInstance, const mxArray *c1_b_is_active_c1_LMI_lema_8_statefeedback,
  const char_T *c1_identifier);
static uint8_T c1_g_emlrt_marshallIn(SFc1_LMI_lema_8_statefeedbackInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void init_dsm_address_info(SFc1_LMI_lema_8_statefeedbackInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c1_LMI_lema_8_statefeedback
  (SFc1_LMI_lema_8_statefeedbackInstanceStruct *chartInstance)
{
  chartInstance->c1_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c1_is_active_c1_LMI_lema_8_statefeedback = 0U;
}

static void initialize_params_c1_LMI_lema_8_statefeedback
  (SFc1_LMI_lema_8_statefeedbackInstanceStruct *chartInstance)
{
}

static void enable_c1_LMI_lema_8_statefeedback
  (SFc1_LMI_lema_8_statefeedbackInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c1_LMI_lema_8_statefeedback
  (SFc1_LMI_lema_8_statefeedbackInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c1_update_debugger_state_c1_LMI_lema_8_statefeedback
  (SFc1_LMI_lema_8_statefeedbackInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c1_LMI_lema_8_statefeedback
  (SFc1_LMI_lema_8_statefeedbackInstanceStruct *chartInstance)
{
  const mxArray *c1_st;
  const mxArray *c1_y = NULL;
  int32_T c1_i0;
  real_T c1_u[4];
  const mxArray *c1_b_y = NULL;
  uint8_T c1_hoistedGlobal;
  uint8_T c1_b_u;
  const mxArray *c1_c_y = NULL;
  real_T (*c1_dh)[4];
  c1_dh = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  c1_st = NULL;
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellarray(2));
  for (c1_i0 = 0; c1_i0 < 4; c1_i0++) {
    c1_u[c1_i0] = (*c1_dh)[c1_i0];
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 4));
  sf_mex_setcell(c1_y, 0, c1_b_y);
  c1_hoistedGlobal = chartInstance->c1_is_active_c1_LMI_lema_8_statefeedback;
  c1_b_u = c1_hoistedGlobal;
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_b_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c1_y, 1, c1_c_y);
  sf_mex_assign(&c1_st, c1_y);
  return c1_st;
}

static void set_sim_state_c1_LMI_lema_8_statefeedback
  (SFc1_LMI_lema_8_statefeedbackInstanceStruct *chartInstance, const mxArray
   *c1_st)
{
  const mxArray *c1_u;
  real_T c1_dv0[4];
  int32_T c1_i1;
  real_T (*c1_dh)[4];
  c1_dh = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c1_doneDoubleBufferReInit = TRUE;
  c1_u = sf_mex_dup(c1_st);
  c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 0)), "dh",
                      c1_dv0);
  for (c1_i1 = 0; c1_i1 < 4; c1_i1++) {
    (*c1_dh)[c1_i1] = c1_dv0[c1_i1];
  }

  chartInstance->c1_is_active_c1_LMI_lema_8_statefeedback =
    c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 1)),
    "is_active_c1_LMI_lema_8_statefeedback");
  sf_mex_destroy(&c1_u);
  c1_update_debugger_state_c1_LMI_lema_8_statefeedback(chartInstance);
  sf_mex_destroy(&c1_st);
}

static void finalize_c1_LMI_lema_8_statefeedback
  (SFc1_LMI_lema_8_statefeedbackInstanceStruct *chartInstance)
{
}

static void sf_c1_LMI_lema_8_statefeedback
  (SFc1_LMI_lema_8_statefeedbackInstanceStruct *chartInstance)
{
  int32_T c1_i2;
  int32_T c1_i3;
  int32_T c1_i4;
  real_T *c1_v1;
  real_T *c1_v2;
  real_T (*c1_h)[4];
  real_T (*c1_gama)[2];
  real_T (*c1_dh)[4];
  c1_h = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 3);
  c1_gama = (real_T (*)[2])ssGetInputPortSignal(chartInstance->S, 2);
  c1_v2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c1_dh = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  c1_v1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c1_v1, 0U);
  for (c1_i2 = 0; c1_i2 < 4; c1_i2++) {
    _SFD_DATA_RANGE_CHECK((*c1_dh)[c1_i2], 1U);
  }

  _SFD_DATA_RANGE_CHECK(*c1_v2, 2U);
  for (c1_i3 = 0; c1_i3 < 2; c1_i3++) {
    _SFD_DATA_RANGE_CHECK((*c1_gama)[c1_i3], 3U);
  }

  for (c1_i4 = 0; c1_i4 < 4; c1_i4++) {
    _SFD_DATA_RANGE_CHECK((*c1_h)[c1_i4], 4U);
  }

  chartInstance->c1_sfEvent = CALL_EVENT;
  c1_chartstep_c1_LMI_lema_8_statefeedback(chartInstance);
  sf_debug_check_for_state_inconsistency(_LMI_lema_8_statefeedbackMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c1_chartstep_c1_LMI_lema_8_statefeedback
  (SFc1_LMI_lema_8_statefeedbackInstanceStruct *chartInstance)
{
  real_T c1_hoistedGlobal;
  real_T c1_b_hoistedGlobal;
  real_T c1_v1;
  real_T c1_v2;
  int32_T c1_i5;
  real_T c1_gama[2];
  int32_T c1_i6;
  real_T c1_h[4];
  uint32_T c1_debug_family_var_map[8];
  c1_sbeJM90BjrqCzgdyR581lvE c1_ctes;
  real_T c1_nargin = 4.0;
  real_T c1_nargout = 1.0;
  real_T c1_dh[4];
  int32_T c1_i7;
  real_T c1_A;
  real_T c1_B;
  real_T c1_x;
  real_T c1_y;
  real_T c1_b_x;
  real_T c1_b_y;
  real_T c1_c_x;
  real_T c1_c_y;
  real_T c1_d_y;
  real_T c1_b;
  real_T c1_e_y;
  real_T c1_a;
  real_T c1_b_b;
  real_T c1_f_y;
  real_T c1_d_x;
  real_T c1_e_x;
  real_T c1_b_a;
  real_T c1_c_b;
  real_T c1_g_y;
  real_T c1_b_A;
  real_T c1_b_B;
  real_T c1_f_x;
  real_T c1_h_y;
  real_T c1_g_x;
  real_T c1_i_y;
  real_T c1_h_x;
  real_T c1_j_y;
  real_T c1_k_y;
  real_T c1_d_b;
  real_T c1_l_y;
  real_T c1_c_a;
  real_T c1_e_b;
  real_T c1_m_y;
  real_T c1_i_x;
  real_T c1_j_x;
  real_T c1_d_a;
  real_T c1_f_b;
  real_T c1_n_y;
  real_T c1_e_a;
  real_T c1_g_b;
  real_T c1_o_y;
  real_T c1_f_a;
  real_T c1_h_b;
  real_T c1_p_y;
  real_T c1_c_A;
  real_T c1_c_B;
  real_T c1_k_x;
  real_T c1_q_y;
  real_T c1_l_x;
  real_T c1_r_y;
  real_T c1_m_x;
  real_T c1_s_y;
  real_T c1_t_y;
  real_T c1_d_A;
  real_T c1_d_B;
  real_T c1_n_x;
  real_T c1_u_y;
  real_T c1_o_x;
  real_T c1_v_y;
  real_T c1_p_x;
  real_T c1_w_y;
  real_T c1_x_y;
  real_T c1_i_b;
  real_T c1_y_y;
  real_T c1_g_a;
  real_T c1_j_b;
  real_T c1_ab_y;
  real_T c1_q_x;
  real_T c1_r_x;
  real_T c1_h_a;
  real_T c1_k_b;
  real_T c1_bb_y;
  real_T c1_e_A;
  real_T c1_e_B;
  real_T c1_s_x;
  real_T c1_cb_y;
  real_T c1_t_x;
  real_T c1_db_y;
  real_T c1_u_x;
  real_T c1_eb_y;
  real_T c1_fb_y;
  real_T c1_l_b;
  real_T c1_gb_y;
  real_T c1_i_a;
  real_T c1_m_b;
  real_T c1_hb_y;
  real_T c1_v_x;
  real_T c1_w_x;
  real_T c1_j_a;
  real_T c1_n_b;
  real_T c1_ib_y;
  real_T c1_k_a;
  real_T c1_o_b;
  real_T c1_jb_y;
  real_T c1_l_a;
  real_T c1_p_b;
  real_T c1_kb_y;
  real_T c1_f_A;
  real_T c1_f_B;
  real_T c1_x_x;
  real_T c1_lb_y;
  real_T c1_y_x;
  real_T c1_mb_y;
  real_T c1_ab_x;
  real_T c1_nb_y;
  real_T c1_ob_y;
  real_T c1_g_A;
  real_T c1_g_B;
  real_T c1_bb_x;
  real_T c1_pb_y;
  real_T c1_cb_x;
  real_T c1_qb_y;
  real_T c1_db_x;
  real_T c1_rb_y;
  real_T c1_sb_y;
  real_T c1_q_b;
  real_T c1_tb_y;
  real_T c1_m_a;
  real_T c1_r_b;
  real_T c1_ub_y;
  real_T c1_eb_x;
  real_T c1_fb_x;
  real_T c1_n_a;
  real_T c1_s_b;
  real_T c1_vb_y;
  real_T c1_o_a;
  real_T c1_t_b;
  real_T c1_wb_y;
  real_T c1_p_a;
  real_T c1_u_b;
  real_T c1_xb_y;
  real_T c1_h_A;
  real_T c1_h_B;
  real_T c1_gb_x;
  real_T c1_yb_y;
  real_T c1_hb_x;
  real_T c1_ac_y;
  real_T c1_ib_x;
  real_T c1_bc_y;
  real_T c1_cc_y;
  real_T c1_i_A;
  real_T c1_i_B;
  real_T c1_jb_x;
  real_T c1_dc_y;
  real_T c1_kb_x;
  real_T c1_ec_y;
  real_T c1_lb_x;
  real_T c1_fc_y;
  real_T c1_gc_y;
  real_T c1_v_b;
  real_T c1_hc_y;
  real_T c1_q_a;
  real_T c1_w_b;
  real_T c1_ic_y;
  real_T c1_mb_x;
  real_T c1_nb_x;
  real_T c1_r_a;
  real_T c1_x_b;
  real_T c1_jc_y;
  real_T c1_s_a;
  real_T c1_y_b;
  real_T c1_kc_y;
  real_T c1_t_a;
  real_T c1_ab_b;
  real_T c1_lc_y;
  real_T c1_j_A;
  real_T c1_j_B;
  real_T c1_ob_x;
  real_T c1_mc_y;
  real_T c1_pb_x;
  real_T c1_nc_y;
  real_T c1_qb_x;
  real_T c1_oc_y;
  real_T c1_pc_y;
  int32_T c1_i8;
  real_T *c1_b_v1;
  real_T *c1_b_v2;
  real_T (*c1_b_dh)[4];
  real_T (*c1_b_h)[4];
  real_T (*c1_b_gama)[2];
  c1_b_h = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 3);
  c1_b_gama = (real_T (*)[2])ssGetInputPortSignal(chartInstance->S, 2);
  c1_b_v2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c1_b_dh = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  c1_b_v1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  c1_hoistedGlobal = *c1_b_v1;
  c1_b_hoistedGlobal = *c1_b_v2;
  c1_v1 = c1_hoistedGlobal;
  c1_v2 = c1_b_hoistedGlobal;
  for (c1_i5 = 0; c1_i5 < 2; c1_i5++) {
    c1_gama[c1_i5] = (*c1_b_gama)[c1_i5];
  }

  for (c1_i6 = 0; c1_i6 < 4; c1_i6++) {
    c1_h[c1_i6] = (*c1_b_h)[c1_i6];
  }

  sf_debug_symbol_scope_push_eml(0U, 8U, 8U, c1_debug_family_names,
    c1_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c1_ctes, 0U, c1_d_sf_marshallOut,
    c1_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_nargin, 1U, c1_c_sf_marshallOut,
    c1_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_nargout, 2U, c1_c_sf_marshallOut,
    c1_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c1_v1, 3U, c1_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_v2, 4U, c1_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c1_gama, 5U, c1_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c1_h, 6U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c1_dh, 7U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_ctes.A1 = 47.6;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 5);
  c1_ctes.A2 = 47.6;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 6);
  c1_ctes.A3 = 47.6;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_ctes.A4 = 47.6;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 9);
  c1_ctes.a1 = 0.204;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 10);
  c1_ctes.a2 = 0.186;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 11);
  c1_ctes.a3 = 0.135;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 12);
  c1_ctes.a4 = 0.051;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 14);
  c1_ctes.kc = 1.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 17);
  c1_ctes.k1 = 10.8;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 18);
  c1_ctes.k2 = 19.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 21);
  c1_ctes.g = 981.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 26);
  for (c1_i7 = 0; c1_i7 < 4; c1_i7++) {
    c1_dh[c1_i7] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 28);
  if (CV_EML_IF(0, 0, c1_h[0] < 0.0)) {
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 29);
    c1_h[0] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 31);
  if (CV_EML_IF(0, 1, c1_h[1] < 0.0)) {
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 32);
    c1_h[1] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 34);
  if (CV_EML_IF(0, 2, c1_h[2] < 0.0)) {
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 35);
    c1_h[2] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 37);
  if (CV_EML_IF(0, 3, c1_h[3] < 0.0)) {
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 38);
    c1_h[3] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 42);
  c1_A = -c1_ctes.a1;
  c1_B = c1_ctes.A1;
  c1_x = c1_A;
  c1_y = c1_B;
  c1_b_x = c1_x;
  c1_b_y = c1_y;
  c1_c_x = c1_b_x;
  c1_c_y = c1_b_y;
  c1_d_y = c1_c_x / c1_c_y;
  c1_b = c1_ctes.g;
  c1_e_y = 2.0 * c1_b;
  c1_a = c1_e_y;
  c1_b_b = c1_h[0];
  c1_f_y = c1_a * c1_b_b;
  c1_d_x = c1_f_y;
  c1_e_x = c1_d_x;
  if (c1_e_x < 0.0) {
    c1_eml_error(chartInstance);
  }

  c1_e_x = muDoubleScalarSqrt(c1_e_x);
  c1_b_a = c1_d_y;
  c1_c_b = c1_e_x;
  c1_g_y = c1_b_a * c1_c_b;
  c1_b_A = c1_ctes.a3;
  c1_b_B = c1_ctes.A1;
  c1_f_x = c1_b_A;
  c1_h_y = c1_b_B;
  c1_g_x = c1_f_x;
  c1_i_y = c1_h_y;
  c1_h_x = c1_g_x;
  c1_j_y = c1_i_y;
  c1_k_y = c1_h_x / c1_j_y;
  c1_d_b = c1_ctes.g;
  c1_l_y = 2.0 * c1_d_b;
  c1_c_a = c1_l_y;
  c1_e_b = c1_h[2];
  c1_m_y = c1_c_a * c1_e_b;
  c1_i_x = c1_m_y;
  c1_j_x = c1_i_x;
  if (c1_j_x < 0.0) {
    c1_eml_error(chartInstance);
  }

  c1_j_x = muDoubleScalarSqrt(c1_j_x);
  c1_d_a = c1_k_y;
  c1_f_b = c1_j_x;
  c1_n_y = c1_d_a * c1_f_b;
  c1_e_a = c1_gama[0];
  c1_g_b = c1_ctes.k1;
  c1_o_y = c1_e_a * c1_g_b;
  c1_f_a = c1_o_y;
  c1_h_b = c1_v1;
  c1_p_y = c1_f_a * c1_h_b;
  c1_c_A = c1_p_y;
  c1_c_B = c1_ctes.A1;
  c1_k_x = c1_c_A;
  c1_q_y = c1_c_B;
  c1_l_x = c1_k_x;
  c1_r_y = c1_q_y;
  c1_m_x = c1_l_x;
  c1_s_y = c1_r_y;
  c1_t_y = c1_m_x / c1_s_y;
  c1_dh[0] = (c1_g_y + c1_n_y) + c1_t_y;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 43);
  c1_d_A = -c1_ctes.a2;
  c1_d_B = c1_ctes.A2;
  c1_n_x = c1_d_A;
  c1_u_y = c1_d_B;
  c1_o_x = c1_n_x;
  c1_v_y = c1_u_y;
  c1_p_x = c1_o_x;
  c1_w_y = c1_v_y;
  c1_x_y = c1_p_x / c1_w_y;
  c1_i_b = c1_ctes.g;
  c1_y_y = 2.0 * c1_i_b;
  c1_g_a = c1_y_y;
  c1_j_b = c1_h[1];
  c1_ab_y = c1_g_a * c1_j_b;
  c1_q_x = c1_ab_y;
  c1_r_x = c1_q_x;
  if (c1_r_x < 0.0) {
    c1_eml_error(chartInstance);
  }

  c1_r_x = muDoubleScalarSqrt(c1_r_x);
  c1_h_a = c1_x_y;
  c1_k_b = c1_r_x;
  c1_bb_y = c1_h_a * c1_k_b;
  c1_e_A = c1_ctes.a4;
  c1_e_B = c1_ctes.A2;
  c1_s_x = c1_e_A;
  c1_cb_y = c1_e_B;
  c1_t_x = c1_s_x;
  c1_db_y = c1_cb_y;
  c1_u_x = c1_t_x;
  c1_eb_y = c1_db_y;
  c1_fb_y = c1_u_x / c1_eb_y;
  c1_l_b = c1_ctes.g;
  c1_gb_y = 2.0 * c1_l_b;
  c1_i_a = c1_gb_y;
  c1_m_b = c1_h[3];
  c1_hb_y = c1_i_a * c1_m_b;
  c1_v_x = c1_hb_y;
  c1_w_x = c1_v_x;
  if (c1_w_x < 0.0) {
    c1_eml_error(chartInstance);
  }

  c1_w_x = muDoubleScalarSqrt(c1_w_x);
  c1_j_a = c1_fb_y;
  c1_n_b = c1_w_x;
  c1_ib_y = c1_j_a * c1_n_b;
  c1_k_a = c1_gama[1];
  c1_o_b = c1_ctes.k2;
  c1_jb_y = c1_k_a * c1_o_b;
  c1_l_a = c1_jb_y;
  c1_p_b = c1_v2;
  c1_kb_y = c1_l_a * c1_p_b;
  c1_f_A = c1_kb_y;
  c1_f_B = c1_ctes.A2;
  c1_x_x = c1_f_A;
  c1_lb_y = c1_f_B;
  c1_y_x = c1_x_x;
  c1_mb_y = c1_lb_y;
  c1_ab_x = c1_y_x;
  c1_nb_y = c1_mb_y;
  c1_ob_y = c1_ab_x / c1_nb_y;
  c1_dh[1] = (c1_bb_y + c1_ib_y) + c1_ob_y;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 44);
  c1_g_A = -c1_ctes.a3;
  c1_g_B = c1_ctes.A3;
  c1_bb_x = c1_g_A;
  c1_pb_y = c1_g_B;
  c1_cb_x = c1_bb_x;
  c1_qb_y = c1_pb_y;
  c1_db_x = c1_cb_x;
  c1_rb_y = c1_qb_y;
  c1_sb_y = c1_db_x / c1_rb_y;
  c1_q_b = c1_ctes.g;
  c1_tb_y = 2.0 * c1_q_b;
  c1_m_a = c1_tb_y;
  c1_r_b = c1_h[2];
  c1_ub_y = c1_m_a * c1_r_b;
  c1_eb_x = c1_ub_y;
  c1_fb_x = c1_eb_x;
  if (c1_fb_x < 0.0) {
    c1_eml_error(chartInstance);
  }

  c1_fb_x = muDoubleScalarSqrt(c1_fb_x);
  c1_n_a = c1_sb_y;
  c1_s_b = c1_fb_x;
  c1_vb_y = c1_n_a * c1_s_b;
  c1_o_a = 1.0 - c1_gama[1];
  c1_t_b = c1_ctes.k2;
  c1_wb_y = c1_o_a * c1_t_b;
  c1_p_a = c1_wb_y;
  c1_u_b = c1_v2;
  c1_xb_y = c1_p_a * c1_u_b;
  c1_h_A = c1_xb_y;
  c1_h_B = c1_ctes.A3;
  c1_gb_x = c1_h_A;
  c1_yb_y = c1_h_B;
  c1_hb_x = c1_gb_x;
  c1_ac_y = c1_yb_y;
  c1_ib_x = c1_hb_x;
  c1_bc_y = c1_ac_y;
  c1_cc_y = c1_ib_x / c1_bc_y;
  c1_dh[2] = c1_vb_y + c1_cc_y;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 45);
  c1_i_A = -c1_ctes.a4;
  c1_i_B = c1_ctes.A4;
  c1_jb_x = c1_i_A;
  c1_dc_y = c1_i_B;
  c1_kb_x = c1_jb_x;
  c1_ec_y = c1_dc_y;
  c1_lb_x = c1_kb_x;
  c1_fc_y = c1_ec_y;
  c1_gc_y = c1_lb_x / c1_fc_y;
  c1_v_b = c1_ctes.g;
  c1_hc_y = 2.0 * c1_v_b;
  c1_q_a = c1_hc_y;
  c1_w_b = c1_h[3];
  c1_ic_y = c1_q_a * c1_w_b;
  c1_mb_x = c1_ic_y;
  c1_nb_x = c1_mb_x;
  if (c1_nb_x < 0.0) {
    c1_eml_error(chartInstance);
  }

  c1_nb_x = muDoubleScalarSqrt(c1_nb_x);
  c1_r_a = c1_gc_y;
  c1_x_b = c1_nb_x;
  c1_jc_y = c1_r_a * c1_x_b;
  c1_s_a = 1.0 - c1_gama[0];
  c1_y_b = c1_ctes.k1;
  c1_kc_y = c1_s_a * c1_y_b;
  c1_t_a = c1_kc_y;
  c1_ab_b = c1_v1;
  c1_lc_y = c1_t_a * c1_ab_b;
  c1_j_A = c1_lc_y;
  c1_j_B = c1_ctes.A4;
  c1_ob_x = c1_j_A;
  c1_mc_y = c1_j_B;
  c1_pb_x = c1_ob_x;
  c1_nc_y = c1_mc_y;
  c1_qb_x = c1_pb_x;
  c1_oc_y = c1_nc_y;
  c1_pc_y = c1_qb_x / c1_oc_y;
  c1_dh[3] = c1_jc_y + c1_pc_y;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, -45);
  sf_debug_symbol_scope_pop();
  for (c1_i8 = 0; c1_i8 < 4; c1_i8++) {
    (*c1_b_dh)[c1_i8] = c1_dh[c1_i8];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
}

static void initSimStructsc1_LMI_lema_8_statefeedback
  (SFc1_LMI_lema_8_statefeedbackInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber)
{
}

static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i9;
  real_T c1_b_inData[4];
  int32_T c1_i10;
  real_T c1_u[4];
  const mxArray *c1_y = NULL;
  SFc1_LMI_lema_8_statefeedbackInstanceStruct *chartInstance;
  chartInstance = (SFc1_LMI_lema_8_statefeedbackInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i9 = 0; c1_i9 < 4; c1_i9++) {
    c1_b_inData[c1_i9] = (*(real_T (*)[4])c1_inData)[c1_i9];
  }

  for (c1_i10 = 0; c1_i10 < 4; c1_i10++) {
    c1_u[c1_i10] = c1_b_inData[c1_i10];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 4));
  sf_mex_assign(&c1_mxArrayOutData, c1_y);
  return c1_mxArrayOutData;
}

static void c1_emlrt_marshallIn(SFc1_LMI_lema_8_statefeedbackInstanceStruct
  *chartInstance, const mxArray *c1_dh, const char_T *c1_identifier, real_T
  c1_y[4])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_dh), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_dh);
}

static void c1_b_emlrt_marshallIn(SFc1_LMI_lema_8_statefeedbackInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[4])
{
  real_T c1_dv1[4];
  int32_T c1_i11;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv1, 1, 0, 0U, 1, 0U, 1, 4);
  for (c1_i11 = 0; c1_i11 < 4; c1_i11++) {
    c1_y[c1_i11] = c1_dv1[c1_i11];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_dh;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y[4];
  int32_T c1_i12;
  SFc1_LMI_lema_8_statefeedbackInstanceStruct *chartInstance;
  chartInstance = (SFc1_LMI_lema_8_statefeedbackInstanceStruct *)
    chartInstanceVoid;
  c1_dh = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_dh), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_dh);
  for (c1_i12 = 0; c1_i12 < 4; c1_i12++) {
    (*(real_T (*)[4])c1_outData)[c1_i12] = c1_y[c1_i12];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i13;
  real_T c1_b_inData[2];
  int32_T c1_i14;
  real_T c1_u[2];
  const mxArray *c1_y = NULL;
  SFc1_LMI_lema_8_statefeedbackInstanceStruct *chartInstance;
  chartInstance = (SFc1_LMI_lema_8_statefeedbackInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i13 = 0; c1_i13 < 2; c1_i13++) {
    c1_b_inData[c1_i13] = (*(real_T (*)[2])c1_inData)[c1_i13];
  }

  for (c1_i14 = 0; c1_i14 < 2; c1_i14++) {
    c1_u[c1_i14] = c1_b_inData[c1_i14];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 2));
  sf_mex_assign(&c1_mxArrayOutData, c1_y);
  return c1_mxArrayOutData;
}

static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  real_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_LMI_lema_8_statefeedbackInstanceStruct *chartInstance;
  chartInstance = (SFc1_LMI_lema_8_statefeedbackInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(real_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c1_mxArrayOutData, c1_y);
  return c1_mxArrayOutData;
}

static real_T c1_c_emlrt_marshallIn(SFc1_LMI_lema_8_statefeedbackInstanceStruct *
  chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  real_T c1_y;
  real_T c1_d0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_d0, 1, 0, 0U, 0, 0U, 0);
  c1_y = c1_d0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_nargout;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y;
  SFc1_LMI_lema_8_statefeedbackInstanceStruct *chartInstance;
  chartInstance = (SFc1_LMI_lema_8_statefeedbackInstanceStruct *)
    chartInstanceVoid;
  c1_nargout = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_nargout), &c1_thisId);
  sf_mex_destroy(&c1_nargout);
  *(real_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  c1_sbeJM90BjrqCzgdyR581lvE c1_u;
  const mxArray *c1_y = NULL;
  real_T c1_b_u;
  const mxArray *c1_b_y = NULL;
  real_T c1_c_u;
  const mxArray *c1_c_y = NULL;
  real_T c1_d_u;
  const mxArray *c1_d_y = NULL;
  real_T c1_e_u;
  const mxArray *c1_e_y = NULL;
  real_T c1_f_u;
  const mxArray *c1_f_y = NULL;
  real_T c1_g_u;
  const mxArray *c1_g_y = NULL;
  real_T c1_h_u;
  const mxArray *c1_h_y = NULL;
  real_T c1_i_u;
  const mxArray *c1_i_y = NULL;
  real_T c1_j_u;
  const mxArray *c1_j_y = NULL;
  real_T c1_k_u;
  const mxArray *c1_k_y = NULL;
  real_T c1_l_u;
  const mxArray *c1_l_y = NULL;
  real_T c1_m_u;
  const mxArray *c1_m_y = NULL;
  SFc1_LMI_lema_8_statefeedbackInstanceStruct *chartInstance;
  chartInstance = (SFc1_LMI_lema_8_statefeedbackInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(c1_sbeJM90BjrqCzgdyR581lvE *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createstruct("structure", 2, 1, 1));
  c1_b_u = c1_u.A1;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_addfield(c1_y, c1_b_y, "A1", "A1", 0);
  c1_c_u = c1_u.A2;
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_c_u, 0, 0U, 0U, 0U, 0));
  sf_mex_addfield(c1_y, c1_c_y, "A2", "A2", 0);
  c1_d_u = c1_u.A3;
  c1_d_y = NULL;
  sf_mex_assign(&c1_d_y, sf_mex_create("y", &c1_d_u, 0, 0U, 0U, 0U, 0));
  sf_mex_addfield(c1_y, c1_d_y, "A3", "A3", 0);
  c1_e_u = c1_u.A4;
  c1_e_y = NULL;
  sf_mex_assign(&c1_e_y, sf_mex_create("y", &c1_e_u, 0, 0U, 0U, 0U, 0));
  sf_mex_addfield(c1_y, c1_e_y, "A4", "A4", 0);
  c1_f_u = c1_u.a1;
  c1_f_y = NULL;
  sf_mex_assign(&c1_f_y, sf_mex_create("y", &c1_f_u, 0, 0U, 0U, 0U, 0));
  sf_mex_addfield(c1_y, c1_f_y, "a1", "a1", 0);
  c1_g_u = c1_u.a2;
  c1_g_y = NULL;
  sf_mex_assign(&c1_g_y, sf_mex_create("y", &c1_g_u, 0, 0U, 0U, 0U, 0));
  sf_mex_addfield(c1_y, c1_g_y, "a2", "a2", 0);
  c1_h_u = c1_u.a3;
  c1_h_y = NULL;
  sf_mex_assign(&c1_h_y, sf_mex_create("y", &c1_h_u, 0, 0U, 0U, 0U, 0));
  sf_mex_addfield(c1_y, c1_h_y, "a3", "a3", 0);
  c1_i_u = c1_u.a4;
  c1_i_y = NULL;
  sf_mex_assign(&c1_i_y, sf_mex_create("y", &c1_i_u, 0, 0U, 0U, 0U, 0));
  sf_mex_addfield(c1_y, c1_i_y, "a4", "a4", 0);
  c1_j_u = c1_u.kc;
  c1_j_y = NULL;
  sf_mex_assign(&c1_j_y, sf_mex_create("y", &c1_j_u, 0, 0U, 0U, 0U, 0));
  sf_mex_addfield(c1_y, c1_j_y, "kc", "kc", 0);
  c1_k_u = c1_u.k1;
  c1_k_y = NULL;
  sf_mex_assign(&c1_k_y, sf_mex_create("y", &c1_k_u, 0, 0U, 0U, 0U, 0));
  sf_mex_addfield(c1_y, c1_k_y, "k1", "k1", 0);
  c1_l_u = c1_u.k2;
  c1_l_y = NULL;
  sf_mex_assign(&c1_l_y, sf_mex_create("y", &c1_l_u, 0, 0U, 0U, 0U, 0));
  sf_mex_addfield(c1_y, c1_l_y, "k2", "k2", 0);
  c1_m_u = c1_u.g;
  c1_m_y = NULL;
  sf_mex_assign(&c1_m_y, sf_mex_create("y", &c1_m_u, 0, 0U, 0U, 0U, 0));
  sf_mex_addfield(c1_y, c1_m_y, "g", "g", 0);
  sf_mex_assign(&c1_mxArrayOutData, c1_y);
  return c1_mxArrayOutData;
}

static void c1_d_emlrt_marshallIn(SFc1_LMI_lema_8_statefeedbackInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  c1_sbeJM90BjrqCzgdyR581lvE *c1_y)
{
  emlrtMsgIdentifier c1_thisId;
  static const char * c1_fieldNames[12] = { "A1", "A2", "A3", "A4", "a1", "a2",
    "a3", "a4", "kc", "k1", "k2", "g" };

  c1_thisId.fParent = c1_parentId;
  sf_mex_check_struct(c1_parentId, c1_u, 12, c1_fieldNames, 0U, 0);
  c1_thisId.fIdentifier = "A1";
  c1_y->A1 = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c1_u, "A1", "A1", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "A2";
  c1_y->A2 = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c1_u, "A2", "A2", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "A3";
  c1_y->A3 = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c1_u, "A3", "A3", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "A4";
  c1_y->A4 = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c1_u, "A4", "A4", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "a1";
  c1_y->a1 = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c1_u, "a1", "a1", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "a2";
  c1_y->a2 = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c1_u, "a2", "a2", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "a3";
  c1_y->a3 = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c1_u, "a3", "a3", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "a4";
  c1_y->a4 = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c1_u, "a4", "a4", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "kc";
  c1_y->kc = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c1_u, "kc", "kc", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "k1";
  c1_y->k1 = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c1_u, "k1", "k1", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "k2";
  c1_y->k2 = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c1_u, "k2", "k2", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "g";
  c1_y->g = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c1_u,
    "g", "g", 0)), &c1_thisId);
  sf_mex_destroy(&c1_u);
}

static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_ctes;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  c1_sbeJM90BjrqCzgdyR581lvE c1_y;
  SFc1_LMI_lema_8_statefeedbackInstanceStruct *chartInstance;
  chartInstance = (SFc1_LMI_lema_8_statefeedbackInstanceStruct *)
    chartInstanceVoid;
  c1_ctes = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_ctes), &c1_thisId, &c1_y);
  sf_mex_destroy(&c1_ctes);
  *(c1_sbeJM90BjrqCzgdyR581lvE *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

const mxArray *sf_c1_LMI_lema_8_statefeedback_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c1_nameCaptureInfo;
  c1_ResolvedFunctionInfo c1_info[7];
  c1_ResolvedFunctionInfo (*c1_b_info)[7];
  const mxArray *c1_m0 = NULL;
  int32_T c1_i15;
  c1_ResolvedFunctionInfo *c1_r0;
  c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  c1_b_info = (c1_ResolvedFunctionInfo (*)[7])c1_info;
  (*c1_b_info)[0].context = "";
  (*c1_b_info)[0].name = "mrdivide";
  (*c1_b_info)[0].dominantType = "double";
  (*c1_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c1_b_info)[0].fileTimeLo = 3368733440U;
  (*c1_b_info)[0].fileTimeHi = 30130985U;
  (*c1_b_info)[0].mFileTimeLo = 529702400U;
  (*c1_b_info)[0].mFileTimeHi = 30114350U;
  (*c1_b_info)[1].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c1_b_info)[1].name = "rdivide";
  (*c1_b_info)[1].dominantType = "double";
  (*c1_b_info)[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c1_b_info)[1].fileTimeLo = 3099026944U;
  (*c1_b_info)[1].fileTimeHi = 30108061U;
  (*c1_b_info)[1].mFileTimeLo = 0U;
  (*c1_b_info)[1].mFileTimeHi = 0U;
  (*c1_b_info)[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c1_b_info)[2].name = "eml_div";
  (*c1_b_info)[2].dominantType = "double";
  (*c1_b_info)[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  (*c1_b_info)[2].fileTimeLo = 1639026944U;
  (*c1_b_info)[2].fileTimeHi = 30108061U;
  (*c1_b_info)[2].mFileTimeLo = 0U;
  (*c1_b_info)[2].mFileTimeHi = 0U;
  (*c1_b_info)[3].context = "";
  (*c1_b_info)[3].name = "mtimes";
  (*c1_b_info)[3].dominantType = "double";
  (*c1_b_info)[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c1_b_info)[3].fileTimeLo = 529702400U;
  (*c1_b_info)[3].fileTimeHi = 30114350U;
  (*c1_b_info)[3].mFileTimeLo = 0U;
  (*c1_b_info)[3].mFileTimeHi = 0U;
  (*c1_b_info)[4].context = "";
  (*c1_b_info)[4].name = "sqrt";
  (*c1_b_info)[4].dominantType = "double";
  (*c1_b_info)[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  (*c1_b_info)[4].fileTimeLo = 2179026944U;
  (*c1_b_info)[4].fileTimeHi = 30108061U;
  (*c1_b_info)[4].mFileTimeLo = 0U;
  (*c1_b_info)[4].mFileTimeHi = 0U;
  (*c1_b_info)[5].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  (*c1_b_info)[5].name = "eml_error";
  (*c1_b_info)[5].dominantType = "char";
  (*c1_b_info)[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  (*c1_b_info)[5].fileTimeLo = 1659026944U;
  (*c1_b_info)[5].fileTimeHi = 30108061U;
  (*c1_b_info)[5].mFileTimeLo = 0U;
  (*c1_b_info)[5].mFileTimeHi = 0U;
  (*c1_b_info)[6].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  (*c1_b_info)[6].name = "eml_scalar_sqrt";
  (*c1_b_info)[6].dominantType = "double";
  (*c1_b_info)[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m";
  (*c1_b_info)[6].fileTimeLo = 2039026944U;
  (*c1_b_info)[6].fileTimeHi = 30108061U;
  (*c1_b_info)[6].mFileTimeLo = 0U;
  (*c1_b_info)[6].mFileTimeHi = 0U;
  sf_mex_assign(&c1_m0, sf_mex_createstruct("nameCaptureInfo", 1, 7));
  for (c1_i15 = 0; c1_i15 < 7; c1_i15++) {
    c1_r0 = &c1_info[c1_i15];
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->context)), "context", "nameCaptureInfo",
                    c1_i15);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c1_r0->name)), "name", "nameCaptureInfo", c1_i15);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c1_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c1_i15);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->resolved)), "resolved", "nameCaptureInfo",
                    c1_i15);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c1_i15);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c1_i15);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c1_i15);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c1_i15);
  }

  sf_mex_assign(&c1_nameCaptureInfo, c1_m0);
  return c1_nameCaptureInfo;
}

static void c1_eml_error(SFc1_LMI_lema_8_statefeedbackInstanceStruct
  *chartInstance)
{
  int32_T c1_i16;
  static char_T c1_varargin_1[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o',
    'o', 'l', 'b', 'o', 'x', ':', 's', 'q', 'r', 't', '_', 'd', 'o', 'm', 'a',
    'i', 'n', 'E', 'r', 'r', 'o', 'r' };

  char_T c1_u[30];
  const mxArray *c1_y = NULL;
  for (c1_i16 = 0; c1_i16 < 30; c1_i16++) {
    c1_u[c1_i16] = c1_varargin_1[c1_i16];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 30));
  sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 1U, 14,
    c1_y));
}

static const mxArray *c1_e_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_LMI_lema_8_statefeedbackInstanceStruct *chartInstance;
  chartInstance = (SFc1_LMI_lema_8_statefeedbackInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(int32_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 6, 0U, 0U, 0U, 0));
  sf_mex_assign(&c1_mxArrayOutData, c1_y);
  return c1_mxArrayOutData;
}

static int32_T c1_e_emlrt_marshallIn(SFc1_LMI_lema_8_statefeedbackInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  int32_T c1_y;
  int32_T c1_i17;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_i17, 1, 6, 0U, 0, 0U, 0);
  c1_y = c1_i17;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_sfEvent;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  int32_T c1_y;
  SFc1_LMI_lema_8_statefeedbackInstanceStruct *chartInstance;
  chartInstance = (SFc1_LMI_lema_8_statefeedbackInstanceStruct *)
    chartInstanceVoid;
  c1_b_sfEvent = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_sfEvent),
    &c1_thisId);
  sf_mex_destroy(&c1_b_sfEvent);
  *(int32_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static uint8_T c1_f_emlrt_marshallIn(SFc1_LMI_lema_8_statefeedbackInstanceStruct
  *chartInstance, const mxArray *c1_b_is_active_c1_LMI_lema_8_statefeedback,
  const char_T *c1_identifier)
{
  uint8_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_b_is_active_c1_LMI_lema_8_statefeedback), &c1_thisId);
  sf_mex_destroy(&c1_b_is_active_c1_LMI_lema_8_statefeedback);
  return c1_y;
}

static uint8_T c1_g_emlrt_marshallIn(SFc1_LMI_lema_8_statefeedbackInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint8_T c1_y;
  uint8_T c1_u0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_u0, 1, 3, 0U, 0, 0U, 0);
  c1_y = c1_u0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void init_dsm_address_info(SFc1_LMI_lema_8_statefeedbackInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c1_LMI_lema_8_statefeedback_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(952228865U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1837005070U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1588195733U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1906525225U);
}

mxArray *sf_c1_LMI_lema_8_statefeedback_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(3238957470U);
    pr[1] = (double)(1410062021U);
    pr[2] = (double)(4008162948U);
    pr[3] = (double)(881926655U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,4,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
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
      pr[0] = (double)(1);
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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(2);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(4);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));
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
      pr[0] = (double)(4);
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

  return(mxAutoinheritanceInfo);
}

static const mxArray *sf_get_sim_state_info_c1_LMI_lema_8_statefeedback(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"dh\",},{M[8],M[0],T\"is_active_c1_LMI_lema_8_statefeedback\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_LMI_lema_8_statefeedback_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_LMI_lema_8_statefeedbackInstanceStruct *chartInstance;
    chartInstance = (SFc1_LMI_lema_8_statefeedbackInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_LMI_lema_8_statefeedbackMachineNumber_,
           1,
           1,
           1,
           5,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           ssGetPath(S),
           (void *)S);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          init_script_number_translation(_LMI_lema_8_statefeedbackMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_LMI_lema_8_statefeedbackMachineNumber_,chartInstance->chartNumber,
             1);
          sf_debug_set_chart_event_thresholds
            (_LMI_lema_8_statefeedbackMachineNumber_,
             chartInstance->chartNumber,
             0,
             0,
             0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"v1");
          _SFD_SET_DATA_PROPS(1,2,0,1,"dh");
          _SFD_SET_DATA_PROPS(2,1,1,0,"v2");
          _SFD_SET_DATA_PROPS(3,1,1,0,"gama");
          _SFD_SET_DATA_PROPS(4,1,1,0,"h");
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
        _SFD_CV_INIT_EML(0,1,4,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,1020);
        _SFD_CV_INIT_EML_IF(0,0,490,500,-1,524);
        _SFD_CV_INIT_EML_IF(0,1,529,539,-1,563);
        _SFD_CV_INIT_EML_IF(0,2,568,578,-1,602);
        _SFD_CV_INIT_EML_IF(0,3,607,617,-1,641);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_c_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)
            c1_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_c_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          real_T *c1_v1;
          real_T *c1_v2;
          real_T (*c1_dh)[4];
          real_T (*c1_gama)[2];
          real_T (*c1_h)[4];
          c1_h = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 3);
          c1_gama = (real_T (*)[2])ssGetInputPortSignal(chartInstance->S, 2);
          c1_v2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c1_dh = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
          c1_v1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c1_v1);
          _SFD_SET_DATA_VALUE_PTR(1U, *c1_dh);
          _SFD_SET_DATA_VALUE_PTR(2U, c1_v2);
          _SFD_SET_DATA_VALUE_PTR(3U, *c1_gama);
          _SFD_SET_DATA_VALUE_PTR(4U, *c1_h);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_LMI_lema_8_statefeedbackMachineNumber_,chartInstance->chartNumber,
         chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c1_LMI_lema_8_statefeedback(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc1_LMI_lema_8_statefeedbackInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c1_LMI_lema_8_statefeedback
    ((SFc1_LMI_lema_8_statefeedbackInstanceStruct*) chartInstanceVar);
  initialize_c1_LMI_lema_8_statefeedback
    ((SFc1_LMI_lema_8_statefeedbackInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c1_LMI_lema_8_statefeedback(void *chartInstanceVar)
{
  enable_c1_LMI_lema_8_statefeedback
    ((SFc1_LMI_lema_8_statefeedbackInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c1_LMI_lema_8_statefeedback(void *chartInstanceVar)
{
  disable_c1_LMI_lema_8_statefeedback
    ((SFc1_LMI_lema_8_statefeedbackInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c1_LMI_lema_8_statefeedback(void *chartInstanceVar)
{
  sf_c1_LMI_lema_8_statefeedback((SFc1_LMI_lema_8_statefeedbackInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c1_LMI_lema_8_statefeedback
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c1_LMI_lema_8_statefeedback
    ((SFc1_LMI_lema_8_statefeedbackInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_LMI_lema_8_statefeedback();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_raw2high'.\n");
  }

  return plhs[0];
}

extern void sf_internal_set_sim_state_c1_LMI_lema_8_statefeedback(SimStruct* S,
  const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_LMI_lema_8_statefeedback();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c1_LMI_lema_8_statefeedback
    ((SFc1_LMI_lema_8_statefeedbackInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c1_LMI_lema_8_statefeedback
  (SimStruct* S)
{
  return sf_internal_get_sim_state_c1_LMI_lema_8_statefeedback(S);
}

static void sf_opaque_set_sim_state_c1_LMI_lema_8_statefeedback(SimStruct* S,
  const mxArray *st)
{
  sf_internal_set_sim_state_c1_LMI_lema_8_statefeedback(S, st);
}

static void sf_opaque_terminate_c1_LMI_lema_8_statefeedback(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_LMI_lema_8_statefeedbackInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c1_LMI_lema_8_statefeedback
      ((SFc1_LMI_lema_8_statefeedbackInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc1_LMI_lema_8_statefeedback
    ((SFc1_LMI_lema_8_statefeedbackInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_LMI_lema_8_statefeedback(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c1_LMI_lema_8_statefeedback
      ((SFc1_LMI_lema_8_statefeedbackInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c1_LMI_lema_8_statefeedback(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,"LMI_lema_8_statefeedback",
      "LMI_lema_8_statefeedback",1);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,"LMI_lema_8_statefeedback",
                "LMI_lema_8_statefeedback",1,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      "LMI_lema_8_statefeedback","LMI_lema_8_statefeedback",1,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"LMI_lema_8_statefeedback",
        "LMI_lema_8_statefeedback",1,4);
      sf_mark_chart_reusable_outputs(S,"LMI_lema_8_statefeedback",
        "LMI_lema_8_statefeedback",1,1);
    }

    sf_set_rtw_dwork_info(S,"LMI_lema_8_statefeedback",
                          "LMI_lema_8_statefeedback",1);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1629225121U));
  ssSetChecksum1(S,(1840428068U));
  ssSetChecksum2(S,(1051696031U));
  ssSetChecksum3(S,(3885928880U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c1_LMI_lema_8_statefeedback(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "LMI_lema_8_statefeedback",
      "LMI_lema_8_statefeedback",1);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c1_LMI_lema_8_statefeedback(SimStruct *S)
{
  SFc1_LMI_lema_8_statefeedbackInstanceStruct *chartInstance;
  chartInstance = (SFc1_LMI_lema_8_statefeedbackInstanceStruct *)malloc(sizeof
    (SFc1_LMI_lema_8_statefeedbackInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc1_LMI_lema_8_statefeedbackInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c1_LMI_lema_8_statefeedback;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c1_LMI_lema_8_statefeedback;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c1_LMI_lema_8_statefeedback;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c1_LMI_lema_8_statefeedback;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c1_LMI_lema_8_statefeedback;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c1_LMI_lema_8_statefeedback;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c1_LMI_lema_8_statefeedback;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c1_LMI_lema_8_statefeedback;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_LMI_lema_8_statefeedback;
  chartInstance->chartInfo.mdlStart = mdlStart_c1_LMI_lema_8_statefeedback;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c1_LMI_lema_8_statefeedback;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->S = S;
  ssSetUserData(S,(void *)(&(chartInstance->chartInfo)));/* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c1_LMI_lema_8_statefeedback_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_LMI_lema_8_statefeedback(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_LMI_lema_8_statefeedback(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_LMI_lema_8_statefeedback(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_LMI_lema_8_statefeedback_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
