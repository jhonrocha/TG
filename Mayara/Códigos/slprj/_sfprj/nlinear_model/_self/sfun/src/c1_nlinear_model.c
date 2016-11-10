/* Include files */

#include "blascompat32.h"
#include "nlinear_model_sfun.h"
#include "c1_nlinear_model.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "nlinear_model_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char * c1_debug_family_names[14] = { "T1", "T2", "T3", "T4", "Ass",
  "Bss", "nargin", "nargout", "v1", "v2", "gama", "ctes", "x", "dx" };

/* Function Declarations */
static void initialize_c1_nlinear_model(SFc1_nlinear_modelInstanceStruct
  *chartInstance);
static void initialize_params_c1_nlinear_model(SFc1_nlinear_modelInstanceStruct *
  chartInstance);
static void enable_c1_nlinear_model(SFc1_nlinear_modelInstanceStruct
  *chartInstance);
static void disable_c1_nlinear_model(SFc1_nlinear_modelInstanceStruct
  *chartInstance);
static void c1_update_debugger_state_c1_nlinear_model
  (SFc1_nlinear_modelInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c1_nlinear_model
  (SFc1_nlinear_modelInstanceStruct *chartInstance);
static void set_sim_state_c1_nlinear_model(SFc1_nlinear_modelInstanceStruct
  *chartInstance, const mxArray *c1_st);
static void finalize_c1_nlinear_model(SFc1_nlinear_modelInstanceStruct
  *chartInstance);
static void sf_c1_nlinear_model(SFc1_nlinear_modelInstanceStruct *chartInstance);
static void c1_chartstep_c1_nlinear_model(SFc1_nlinear_modelInstanceStruct
  *chartInstance);
static void initSimStructsc1_nlinear_model(SFc1_nlinear_modelInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber);
static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData);
static void c1_emlrt_marshallIn(SFc1_nlinear_modelInstanceStruct *chartInstance,
  const mxArray *c1_dx, const char_T *c1_identifier, real_T c1_y[4]);
static void c1_b_emlrt_marshallIn(SFc1_nlinear_modelInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[4]);
static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static real_T c1_c_emlrt_marshallIn(SFc1_nlinear_modelInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_e_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_d_emlrt_marshallIn(SFc1_nlinear_modelInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[8]);
static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_f_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_e_emlrt_marshallIn(SFc1_nlinear_modelInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[16]);
static void c1_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static void c1_info_helper(c1_ResolvedFunctionInfo c1_info[18]);
static real_T c1_sqrt(SFc1_nlinear_modelInstanceStruct *chartInstance, real_T
                      c1_x);
static void c1_eml_error(SFc1_nlinear_modelInstanceStruct *chartInstance);
static void c1_eml_scalar_eg(SFc1_nlinear_modelInstanceStruct *chartInstance);
static void c1_b_eml_scalar_eg(SFc1_nlinear_modelInstanceStruct *chartInstance);
static const mxArray *c1_g_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static int32_T c1_f_emlrt_marshallIn(SFc1_nlinear_modelInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_ctes_bus_io(void *chartInstanceVoid, void *c1_pData);
static uint8_T c1_g_emlrt_marshallIn(SFc1_nlinear_modelInstanceStruct
  *chartInstance, const mxArray *c1_b_is_active_c1_nlinear_model, const char_T
  *c1_identifier);
static uint8_T c1_h_emlrt_marshallIn(SFc1_nlinear_modelInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_b_sqrt(SFc1_nlinear_modelInstanceStruct *chartInstance, real_T
                      *c1_x);
static void init_dsm_address_info(SFc1_nlinear_modelInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c1_nlinear_model(SFc1_nlinear_modelInstanceStruct
  *chartInstance)
{
  chartInstance->c1_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c1_is_active_c1_nlinear_model = 0U;
}

static void initialize_params_c1_nlinear_model(SFc1_nlinear_modelInstanceStruct *
  chartInstance)
{
}

static void enable_c1_nlinear_model(SFc1_nlinear_modelInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c1_nlinear_model(SFc1_nlinear_modelInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c1_update_debugger_state_c1_nlinear_model
  (SFc1_nlinear_modelInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c1_nlinear_model
  (SFc1_nlinear_modelInstanceStruct *chartInstance)
{
  const mxArray *c1_st;
  const mxArray *c1_y = NULL;
  int32_T c1_i0;
  real_T c1_u[4];
  const mxArray *c1_b_y = NULL;
  uint8_T c1_hoistedGlobal;
  uint8_T c1_b_u;
  const mxArray *c1_c_y = NULL;
  real_T (*c1_dx)[4];
  c1_dx = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  c1_st = NULL;
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellarray(2));
  for (c1_i0 = 0; c1_i0 < 4; c1_i0++) {
    c1_u[c1_i0] = (*c1_dx)[c1_i0];
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 4));
  sf_mex_setcell(c1_y, 0, c1_b_y);
  c1_hoistedGlobal = chartInstance->c1_is_active_c1_nlinear_model;
  c1_b_u = c1_hoistedGlobal;
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_b_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c1_y, 1, c1_c_y);
  sf_mex_assign(&c1_st, c1_y);
  return c1_st;
}

static void set_sim_state_c1_nlinear_model(SFc1_nlinear_modelInstanceStruct
  *chartInstance, const mxArray *c1_st)
{
  const mxArray *c1_u;
  real_T c1_dv0[4];
  int32_T c1_i1;
  real_T (*c1_dx)[4];
  c1_dx = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c1_doneDoubleBufferReInit = TRUE;
  c1_u = sf_mex_dup(c1_st);
  c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 0)), "dx",
                      c1_dv0);
  for (c1_i1 = 0; c1_i1 < 4; c1_i1++) {
    (*c1_dx)[c1_i1] = c1_dv0[c1_i1];
  }

  chartInstance->c1_is_active_c1_nlinear_model = c1_g_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 1)),
     "is_active_c1_nlinear_model");
  sf_mex_destroy(&c1_u);
  c1_update_debugger_state_c1_nlinear_model(chartInstance);
  sf_mex_destroy(&c1_st);
}

static void finalize_c1_nlinear_model(SFc1_nlinear_modelInstanceStruct
  *chartInstance)
{
}

static void sf_c1_nlinear_model(SFc1_nlinear_modelInstanceStruct *chartInstance)
{
  int32_T c1_i2;
  int32_T c1_i3;
  int32_T c1_i4;
  real_T *c1_v1;
  real_T *c1_v2;
  real_T (*c1_x)[4];
  real_T (*c1_gama)[2];
  real_T (*c1_dx)[4];
  c1_x = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 4);
  c1_gama = (real_T (*)[2])ssGetInputPortSignal(chartInstance->S, 2);
  c1_v2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c1_dx = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  c1_v1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c1_v1, 0U);
  for (c1_i2 = 0; c1_i2 < 4; c1_i2++) {
    _SFD_DATA_RANGE_CHECK((*c1_dx)[c1_i2], 1U);
  }

  _SFD_DATA_RANGE_CHECK(*c1_v2, 2U);
  for (c1_i3 = 0; c1_i3 < 2; c1_i3++) {
    _SFD_DATA_RANGE_CHECK((*c1_gama)[c1_i3], 3U);
  }

  for (c1_i4 = 0; c1_i4 < 4; c1_i4++) {
    _SFD_DATA_RANGE_CHECK((*c1_x)[c1_i4], 5U);
  }

  chartInstance->c1_sfEvent = CALL_EVENT;
  c1_chartstep_c1_nlinear_model(chartInstance);
  sf_debug_check_for_state_inconsistency(_nlinear_modelMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c1_chartstep_c1_nlinear_model(SFc1_nlinear_modelInstanceStruct
  *chartInstance)
{
  real_T c1_hoistedGlobal;
  real_T c1_b_hoistedGlobal;
  real_T c1_v1;
  real_T c1_v2;
  int32_T c1_i5;
  real_T c1_gama[2];
  c1_slBus1 c1_ctes;
  int32_T c1_i6;
  int32_T c1_i7;
  int32_T c1_i8;
  int32_T c1_i9;
  real_T c1_x[4];
  uint32_T c1_debug_family_var_map[14];
  real_T c1_T1;
  real_T c1_T2;
  real_T c1_T3;
  real_T c1_T4;
  real_T c1_Ass[16];
  real_T c1_Bss[8];
  real_T c1_nargin = 5.0;
  real_T c1_nargout = 1.0;
  real_T c1_dx[4];
  int32_T c1_i10;
  real_T c1_A;
  real_T c1_B;
  real_T c1_b_x;
  real_T c1_y;
  real_T c1_c_x;
  real_T c1_b_y;
  real_T c1_d_x;
  real_T c1_c_y;
  real_T c1_d_y;
  real_T c1_b;
  real_T c1_e_y;
  real_T c1_b_A;
  real_T c1_b_B;
  real_T c1_e_x;
  real_T c1_f_y;
  real_T c1_f_x;
  real_T c1_g_y;
  real_T c1_g_x;
  real_T c1_h_y;
  real_T c1_i_y;
  real_T c1_a;
  real_T c1_b_b;
  real_T c1_c_A;
  real_T c1_c_B;
  real_T c1_h_x;
  real_T c1_j_y;
  real_T c1_i_x;
  real_T c1_k_y;
  real_T c1_j_x;
  real_T c1_l_y;
  real_T c1_m_y;
  real_T c1_c_b;
  real_T c1_n_y;
  real_T c1_d_A;
  real_T c1_d_B;
  real_T c1_k_x;
  real_T c1_o_y;
  real_T c1_l_x;
  real_T c1_p_y;
  real_T c1_m_x;
  real_T c1_q_y;
  real_T c1_r_y;
  real_T c1_b_a;
  real_T c1_d_b;
  real_T c1_e_A;
  real_T c1_e_B;
  real_T c1_n_x;
  real_T c1_s_y;
  real_T c1_o_x;
  real_T c1_t_y;
  real_T c1_p_x;
  real_T c1_u_y;
  real_T c1_v_y;
  real_T c1_e_b;
  real_T c1_w_y;
  real_T c1_f_A;
  real_T c1_f_B;
  real_T c1_q_x;
  real_T c1_x_y;
  real_T c1_r_x;
  real_T c1_y_y;
  real_T c1_s_x;
  real_T c1_ab_y;
  real_T c1_bb_y;
  real_T c1_c_a;
  real_T c1_f_b;
  real_T c1_g_A;
  real_T c1_g_B;
  real_T c1_t_x;
  real_T c1_cb_y;
  real_T c1_u_x;
  real_T c1_db_y;
  real_T c1_v_x;
  real_T c1_eb_y;
  real_T c1_fb_y;
  real_T c1_g_b;
  real_T c1_gb_y;
  real_T c1_h_A;
  real_T c1_h_B;
  real_T c1_w_x;
  real_T c1_hb_y;
  real_T c1_x_x;
  real_T c1_ib_y;
  real_T c1_y_x;
  real_T c1_jb_y;
  real_T c1_kb_y;
  real_T c1_d_a;
  real_T c1_h_b;
  real_T c1_i_B;
  real_T c1_lb_y;
  real_T c1_mb_y;
  real_T c1_nb_y;
  real_T c1_ob_y;
  real_T c1_e_a;
  real_T c1_i_b;
  real_T c1_pb_y;
  real_T c1_i_A;
  real_T c1_j_B;
  real_T c1_ab_x;
  real_T c1_qb_y;
  real_T c1_bb_x;
  real_T c1_rb_y;
  real_T c1_cb_x;
  real_T c1_sb_y;
  real_T c1_tb_y;
  real_T c1_k_B;
  real_T c1_ub_y;
  real_T c1_vb_y;
  real_T c1_wb_y;
  real_T c1_xb_y;
  real_T c1_f_a;
  real_T c1_j_b;
  real_T c1_yb_y;
  real_T c1_j_A;
  real_T c1_l_B;
  real_T c1_db_x;
  real_T c1_ac_y;
  real_T c1_eb_x;
  real_T c1_bc_y;
  real_T c1_fb_x;
  real_T c1_cc_y;
  real_T c1_dc_y;
  real_T c1_m_B;
  real_T c1_ec_y;
  real_T c1_fc_y;
  real_T c1_gc_y;
  real_T c1_hc_y;
  real_T c1_n_B;
  real_T c1_ic_y;
  real_T c1_jc_y;
  real_T c1_kc_y;
  real_T c1_lc_y;
  real_T c1_g_a;
  real_T c1_k_b;
  real_T c1_mc_y;
  real_T c1_k_A;
  real_T c1_o_B;
  real_T c1_gb_x;
  real_T c1_nc_y;
  real_T c1_hb_x;
  real_T c1_oc_y;
  real_T c1_ib_x;
  real_T c1_pc_y;
  real_T c1_qc_y;
  real_T c1_h_a;
  real_T c1_l_b;
  real_T c1_rc_y;
  real_T c1_l_A;
  real_T c1_p_B;
  real_T c1_jb_x;
  real_T c1_sc_y;
  real_T c1_kb_x;
  real_T c1_tc_y;
  real_T c1_lb_x;
  real_T c1_uc_y;
  real_T c1_vc_y;
  real_T c1_i_a;
  real_T c1_m_b;
  real_T c1_wc_y;
  real_T c1_m_A;
  real_T c1_q_B;
  real_T c1_mb_x;
  real_T c1_xc_y;
  real_T c1_nb_x;
  real_T c1_yc_y;
  real_T c1_ob_x;
  real_T c1_ad_y;
  real_T c1_bd_y;
  real_T c1_j_a;
  real_T c1_n_b;
  real_T c1_cd_y;
  real_T c1_n_A;
  real_T c1_r_B;
  real_T c1_pb_x;
  real_T c1_dd_y;
  real_T c1_qb_x;
  real_T c1_ed_y;
  real_T c1_rb_x;
  real_T c1_fd_y;
  real_T c1_gd_y;
  int32_T c1_i11;
  real_T c1_k_a[16];
  int32_T c1_i12;
  real_T c1_o_b[4];
  int32_T c1_i13;
  real_T c1_hd_y[4];
  int32_T c1_i14;
  int32_T c1_i15;
  int32_T c1_i16;
  real_T c1_l_a[8];
  real_T c1_p_b[2];
  int32_T c1_i17;
  int32_T c1_i18;
  int32_T c1_i19;
  int32_T c1_i20;
  int32_T c1_i21;
  real_T *c1_b_v1;
  real_T *c1_b_v2;
  real_T (*c1_b_dx)[4];
  real_T (*c1_sb_x)[4];
  real_T (*c1_b_gama)[2];
  void **c1_b_ctes;
  c1_sb_x = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 4);
  c1_b_ctes = (void **)ssGetInputPortSignal(chartInstance->S, 3);
  c1_b_gama = (real_T (*)[2])ssGetInputPortSignal(chartInstance->S, 2);
  c1_b_v2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c1_b_dx = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  c1_b_v1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  c1_hoistedGlobal = *c1_b_v1;
  c1_b_hoistedGlobal = *c1_b_v2;
  c1_v1 = c1_hoistedGlobal;
  c1_v2 = c1_b_hoistedGlobal;
  for (c1_i5 = 0; c1_i5 < 2; c1_i5++) {
    c1_gama[c1_i5] = (*c1_b_gama)[c1_i5];
  }

  c1_ctes.A1 = *(real_T *)((char_T *)c1_b_ctes + 0);
  c1_ctes.A2 = *(real_T *)((char_T *)c1_b_ctes + 8);
  c1_ctes.A3 = *(real_T *)((char_T *)c1_b_ctes + 16);
  c1_ctes.A4 = *(real_T *)((char_T *)c1_b_ctes + 24);
  c1_ctes.a1 = *(real_T *)((char_T *)c1_b_ctes + 32);
  c1_ctes.a2 = *(real_T *)((char_T *)c1_b_ctes + 40);
  c1_ctes.a3 = *(real_T *)((char_T *)c1_b_ctes + 48);
  c1_ctes.a4 = *(real_T *)((char_T *)c1_b_ctes + 56);
  c1_ctes.kc = *(real_T *)((char_T *)c1_b_ctes + 64);
  c1_ctes.k1 = *(real_T *)((char_T *)c1_b_ctes + 72);
  c1_ctes.k2 = *(real_T *)((char_T *)c1_b_ctes + 80);
  c1_ctes.g = *(real_T *)((char_T *)c1_b_ctes + 88);
  for (c1_i6 = 0; c1_i6 < 4; c1_i6++) {
    c1_ctes.hlin[c1_i6] = ((real_T *)((char_T *)c1_b_ctes + 96))[c1_i6];
  }

  for (c1_i7 = 0; c1_i7 < 4; c1_i7++) {
    c1_ctes.h0[c1_i7] = ((real_T *)((char_T *)c1_b_ctes + 128))[c1_i7];
  }

  for (c1_i8 = 0; c1_i8 < 2; c1_i8++) {
    c1_ctes.vlin[c1_i8] = ((real_T *)((char_T *)c1_b_ctes + 160))[c1_i8];
  }

  for (c1_i9 = 0; c1_i9 < 4; c1_i9++) {
    c1_x[c1_i9] = (*c1_sb_x)[c1_i9];
  }

  sf_debug_symbol_scope_push_eml(0U, 14U, 14U, c1_debug_family_names,
    c1_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c1_T1, 0U, c1_d_sf_marshallOut,
    c1_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_T2, 1U, c1_d_sf_marshallOut,
    c1_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_T3, 2U, c1_d_sf_marshallOut,
    c1_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_T4, 3U, c1_d_sf_marshallOut,
    c1_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_Ass, 4U, c1_f_sf_marshallOut,
    c1_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_Bss, 5U, c1_e_sf_marshallOut,
    c1_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_nargin, 6U, c1_d_sf_marshallOut,
    c1_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_nargout, 7U, c1_d_sf_marshallOut,
    c1_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c1_v1, 8U, c1_d_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_v2, 9U, c1_d_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c1_gama, 10U, c1_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_ctes, 11U, c1_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c1_x, 12U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c1_dx, 13U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 2);
  for (c1_i10 = 0; c1_i10 < 4; c1_i10++) {
    c1_dx[c1_i10] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 5);
  c1_A = c1_ctes.A1;
  c1_B = c1_ctes.a1;
  c1_b_x = c1_A;
  c1_y = c1_B;
  c1_c_x = c1_b_x;
  c1_b_y = c1_y;
  c1_d_x = c1_c_x;
  c1_c_y = c1_b_y;
  c1_d_y = c1_d_x / c1_c_y;
  c1_b = c1_ctes.hlin[0];
  c1_e_y = 2.0 * c1_b;
  c1_b_A = c1_e_y;
  c1_b_B = c1_ctes.g;
  c1_e_x = c1_b_A;
  c1_f_y = c1_b_B;
  c1_f_x = c1_e_x;
  c1_g_y = c1_f_y;
  c1_g_x = c1_f_x;
  c1_h_y = c1_g_y;
  c1_i_y = c1_g_x / c1_h_y;
  c1_a = c1_d_y;
  c1_b_b = c1_i_y;
  c1_b_sqrt(chartInstance, &c1_b_b);
  c1_T1 = c1_a * c1_b_b;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 6);
  c1_c_A = c1_ctes.A2;
  c1_c_B = c1_ctes.a2;
  c1_h_x = c1_c_A;
  c1_j_y = c1_c_B;
  c1_i_x = c1_h_x;
  c1_k_y = c1_j_y;
  c1_j_x = c1_i_x;
  c1_l_y = c1_k_y;
  c1_m_y = c1_j_x / c1_l_y;
  c1_c_b = c1_ctes.hlin[1];
  c1_n_y = 2.0 * c1_c_b;
  c1_d_A = c1_n_y;
  c1_d_B = c1_ctes.g;
  c1_k_x = c1_d_A;
  c1_o_y = c1_d_B;
  c1_l_x = c1_k_x;
  c1_p_y = c1_o_y;
  c1_m_x = c1_l_x;
  c1_q_y = c1_p_y;
  c1_r_y = c1_m_x / c1_q_y;
  c1_b_a = c1_m_y;
  c1_d_b = c1_r_y;
  c1_b_sqrt(chartInstance, &c1_d_b);
  c1_T2 = c1_b_a * c1_d_b;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_e_A = c1_ctes.A3;
  c1_e_B = c1_ctes.a3;
  c1_n_x = c1_e_A;
  c1_s_y = c1_e_B;
  c1_o_x = c1_n_x;
  c1_t_y = c1_s_y;
  c1_p_x = c1_o_x;
  c1_u_y = c1_t_y;
  c1_v_y = c1_p_x / c1_u_y;
  c1_e_b = c1_ctes.hlin[2];
  c1_w_y = 2.0 * c1_e_b;
  c1_f_A = c1_w_y;
  c1_f_B = c1_ctes.g;
  c1_q_x = c1_f_A;
  c1_x_y = c1_f_B;
  c1_r_x = c1_q_x;
  c1_y_y = c1_x_y;
  c1_s_x = c1_r_x;
  c1_ab_y = c1_y_y;
  c1_bb_y = c1_s_x / c1_ab_y;
  c1_c_a = c1_v_y;
  c1_f_b = c1_bb_y;
  c1_b_sqrt(chartInstance, &c1_f_b);
  c1_T3 = c1_c_a * c1_f_b;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_g_A = c1_ctes.A4;
  c1_g_B = c1_ctes.a4;
  c1_t_x = c1_g_A;
  c1_cb_y = c1_g_B;
  c1_u_x = c1_t_x;
  c1_db_y = c1_cb_y;
  c1_v_x = c1_u_x;
  c1_eb_y = c1_db_y;
  c1_fb_y = c1_v_x / c1_eb_y;
  c1_g_b = c1_ctes.hlin[3];
  c1_gb_y = 2.0 * c1_g_b;
  c1_h_A = c1_gb_y;
  c1_h_B = c1_ctes.g;
  c1_w_x = c1_h_A;
  c1_hb_y = c1_h_B;
  c1_x_x = c1_w_x;
  c1_ib_y = c1_hb_y;
  c1_y_x = c1_x_x;
  c1_jb_y = c1_ib_y;
  c1_kb_y = c1_y_x / c1_jb_y;
  c1_d_a = c1_fb_y;
  c1_h_b = c1_kb_y;
  c1_b_sqrt(chartInstance, &c1_h_b);
  c1_T4 = c1_d_a * c1_h_b;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 10);
  c1_i_B = c1_T1;
  c1_lb_y = c1_i_B;
  c1_mb_y = c1_lb_y;
  c1_nb_y = c1_mb_y;
  c1_ob_y = -1.0 / c1_nb_y;
  c1_e_a = c1_ctes.A1;
  c1_i_b = c1_T3;
  c1_pb_y = c1_e_a * c1_i_b;
  c1_i_A = c1_ctes.A3;
  c1_j_B = c1_pb_y;
  c1_ab_x = c1_i_A;
  c1_qb_y = c1_j_B;
  c1_bb_x = c1_ab_x;
  c1_rb_y = c1_qb_y;
  c1_cb_x = c1_bb_x;
  c1_sb_y = c1_rb_y;
  c1_tb_y = c1_cb_x / c1_sb_y;
  c1_k_B = c1_T2;
  c1_ub_y = c1_k_B;
  c1_vb_y = c1_ub_y;
  c1_wb_y = c1_vb_y;
  c1_xb_y = -1.0 / c1_wb_y;
  c1_f_a = c1_ctes.A2;
  c1_j_b = c1_T4;
  c1_yb_y = c1_f_a * c1_j_b;
  c1_j_A = c1_ctes.A4;
  c1_l_B = c1_yb_y;
  c1_db_x = c1_j_A;
  c1_ac_y = c1_l_B;
  c1_eb_x = c1_db_x;
  c1_bc_y = c1_ac_y;
  c1_fb_x = c1_eb_x;
  c1_cc_y = c1_bc_y;
  c1_dc_y = c1_fb_x / c1_cc_y;
  c1_m_B = c1_T3;
  c1_ec_y = c1_m_B;
  c1_fc_y = c1_ec_y;
  c1_gc_y = c1_fc_y;
  c1_hc_y = -1.0 / c1_gc_y;
  c1_n_B = c1_T4;
  c1_ic_y = c1_n_B;
  c1_jc_y = c1_ic_y;
  c1_kc_y = c1_jc_y;
  c1_lc_y = -1.0 / c1_kc_y;
  c1_Ass[0] = c1_ob_y;
  c1_Ass[4] = 0.0;
  c1_Ass[8] = c1_tb_y;
  c1_Ass[12] = 0.0;
  c1_Ass[1] = 0.0;
  c1_Ass[5] = c1_xb_y;
  c1_Ass[9] = 0.0;
  c1_Ass[13] = c1_dc_y;
  c1_Ass[2] = 0.0;
  c1_Ass[6] = 0.0;
  c1_Ass[10] = c1_hc_y;
  c1_Ass[14] = 0.0;
  c1_Ass[3] = 0.0;
  c1_Ass[7] = 0.0;
  c1_Ass[11] = 0.0;
  c1_Ass[15] = c1_lc_y;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 14);
  c1_g_a = c1_gama[0];
  c1_k_b = c1_ctes.k1;
  c1_mc_y = c1_g_a * c1_k_b;
  c1_k_A = c1_mc_y;
  c1_o_B = c1_ctes.A1;
  c1_gb_x = c1_k_A;
  c1_nc_y = c1_o_B;
  c1_hb_x = c1_gb_x;
  c1_oc_y = c1_nc_y;
  c1_ib_x = c1_hb_x;
  c1_pc_y = c1_oc_y;
  c1_qc_y = c1_ib_x / c1_pc_y;
  c1_h_a = c1_gama[1];
  c1_l_b = c1_ctes.k2;
  c1_rc_y = c1_h_a * c1_l_b;
  c1_l_A = c1_rc_y;
  c1_p_B = c1_ctes.A2;
  c1_jb_x = c1_l_A;
  c1_sc_y = c1_p_B;
  c1_kb_x = c1_jb_x;
  c1_tc_y = c1_sc_y;
  c1_lb_x = c1_kb_x;
  c1_uc_y = c1_tc_y;
  c1_vc_y = c1_lb_x / c1_uc_y;
  c1_i_a = 1.0 - c1_gama[1];
  c1_m_b = c1_ctes.k2;
  c1_wc_y = c1_i_a * c1_m_b;
  c1_m_A = c1_wc_y;
  c1_q_B = c1_ctes.A3;
  c1_mb_x = c1_m_A;
  c1_xc_y = c1_q_B;
  c1_nb_x = c1_mb_x;
  c1_yc_y = c1_xc_y;
  c1_ob_x = c1_nb_x;
  c1_ad_y = c1_yc_y;
  c1_bd_y = c1_ob_x / c1_ad_y;
  c1_j_a = 1.0 - c1_gama[0];
  c1_n_b = c1_ctes.k1;
  c1_cd_y = c1_j_a * c1_n_b;
  c1_n_A = c1_cd_y;
  c1_r_B = c1_ctes.A4;
  c1_pb_x = c1_n_A;
  c1_dd_y = c1_r_B;
  c1_qb_x = c1_pb_x;
  c1_ed_y = c1_dd_y;
  c1_rb_x = c1_qb_x;
  c1_fd_y = c1_ed_y;
  c1_gd_y = c1_rb_x / c1_fd_y;
  c1_Bss[0] = c1_qc_y;
  c1_Bss[4] = 0.0;
  c1_Bss[1] = 0.0;
  c1_Bss[5] = c1_vc_y;
  c1_Bss[2] = 0.0;
  c1_Bss[6] = c1_bd_y;
  c1_Bss[3] = c1_gd_y;
  c1_Bss[7] = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 18);
  for (c1_i11 = 0; c1_i11 < 16; c1_i11++) {
    c1_k_a[c1_i11] = c1_Ass[c1_i11];
  }

  for (c1_i12 = 0; c1_i12 < 4; c1_i12++) {
    c1_o_b[c1_i12] = c1_x[c1_i12];
  }

  c1_eml_scalar_eg(chartInstance);
  c1_eml_scalar_eg(chartInstance);
  for (c1_i13 = 0; c1_i13 < 4; c1_i13++) {
    c1_hd_y[c1_i13] = 0.0;
    c1_i14 = 0;
    for (c1_i15 = 0; c1_i15 < 4; c1_i15++) {
      c1_hd_y[c1_i13] += c1_k_a[c1_i14 + c1_i13] * c1_o_b[c1_i15];
      c1_i14 += 4;
    }
  }

  for (c1_i16 = 0; c1_i16 < 8; c1_i16++) {
    c1_l_a[c1_i16] = c1_Bss[c1_i16];
  }

  c1_p_b[0] = c1_v1;
  c1_p_b[1] = c1_v2;
  c1_b_eml_scalar_eg(chartInstance);
  c1_b_eml_scalar_eg(chartInstance);
  for (c1_i17 = 0; c1_i17 < 4; c1_i17++) {
    c1_o_b[c1_i17] = 0.0;
    c1_i18 = 0;
    for (c1_i19 = 0; c1_i19 < 2; c1_i19++) {
      c1_o_b[c1_i17] += c1_l_a[c1_i18 + c1_i17] * c1_p_b[c1_i19];
      c1_i18 += 4;
    }
  }

  for (c1_i20 = 0; c1_i20 < 4; c1_i20++) {
    c1_dx[c1_i20] = c1_hd_y[c1_i20] + c1_o_b[c1_i20];
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, -18);
  sf_debug_symbol_scope_pop();
  for (c1_i21 = 0; c1_i21 < 4; c1_i21++) {
    (*c1_b_dx)[c1_i21] = c1_dx[c1_i21];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
}

static void initSimStructsc1_nlinear_model(SFc1_nlinear_modelInstanceStruct
  *chartInstance)
{
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber)
{
}

static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i22;
  real_T c1_b_inData[4];
  int32_T c1_i23;
  real_T c1_u[4];
  const mxArray *c1_y = NULL;
  SFc1_nlinear_modelInstanceStruct *chartInstance;
  chartInstance = (SFc1_nlinear_modelInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i22 = 0; c1_i22 < 4; c1_i22++) {
    c1_b_inData[c1_i22] = (*(real_T (*)[4])c1_inData)[c1_i22];
  }

  for (c1_i23 = 0; c1_i23 < 4; c1_i23++) {
    c1_u[c1_i23] = c1_b_inData[c1_i23];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 4));
  sf_mex_assign(&c1_mxArrayOutData, c1_y);
  return c1_mxArrayOutData;
}

static void c1_emlrt_marshallIn(SFc1_nlinear_modelInstanceStruct *chartInstance,
  const mxArray *c1_dx, const char_T *c1_identifier, real_T c1_y[4])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_dx), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_dx);
}

static void c1_b_emlrt_marshallIn(SFc1_nlinear_modelInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[4])
{
  real_T c1_dv1[4];
  int32_T c1_i24;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv1, 1, 0, 0U, 1, 0U, 1, 4);
  for (c1_i24 = 0; c1_i24 < 4; c1_i24++) {
    c1_y[c1_i24] = c1_dv1[c1_i24];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_dx;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y[4];
  int32_T c1_i25;
  SFc1_nlinear_modelInstanceStruct *chartInstance;
  chartInstance = (SFc1_nlinear_modelInstanceStruct *)chartInstanceVoid;
  c1_dx = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_dx), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_dx);
  for (c1_i25 = 0; c1_i25 < 4; c1_i25++) {
    (*(real_T (*)[4])c1_outData)[c1_i25] = c1_y[c1_i25];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  c1_slBus1 c1_u;
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
  int32_T c1_i26;
  real_T c1_n_u[4];
  const mxArray *c1_n_y = NULL;
  int32_T c1_i27;
  real_T c1_o_u[4];
  const mxArray *c1_o_y = NULL;
  int32_T c1_i28;
  real_T c1_p_u[2];
  const mxArray *c1_p_y = NULL;
  SFc1_nlinear_modelInstanceStruct *chartInstance;
  chartInstance = (SFc1_nlinear_modelInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(c1_slBus1 *)c1_inData;
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
  for (c1_i26 = 0; c1_i26 < 4; c1_i26++) {
    c1_n_u[c1_i26] = c1_u.hlin[c1_i26];
  }

  c1_n_y = NULL;
  sf_mex_assign(&c1_n_y, sf_mex_create("y", c1_n_u, 0, 0U, 1U, 0U, 2, 4, 1));
  sf_mex_addfield(c1_y, c1_n_y, "hlin", "hlin", 0);
  for (c1_i27 = 0; c1_i27 < 4; c1_i27++) {
    c1_o_u[c1_i27] = c1_u.h0[c1_i27];
  }

  c1_o_y = NULL;
  sf_mex_assign(&c1_o_y, sf_mex_create("y", c1_o_u, 0, 0U, 1U, 0U, 2, 4, 1));
  sf_mex_addfield(c1_y, c1_o_y, "h0", "h0", 0);
  for (c1_i28 = 0; c1_i28 < 2; c1_i28++) {
    c1_p_u[c1_i28] = c1_u.vlin[c1_i28];
  }

  c1_p_y = NULL;
  sf_mex_assign(&c1_p_y, sf_mex_create("y", c1_p_u, 0, 0U, 1U, 0U, 2, 2, 1));
  sf_mex_addfield(c1_y, c1_p_y, "vlin", "vlin", 0);
  sf_mex_assign(&c1_mxArrayOutData, c1_y);
  return c1_mxArrayOutData;
}

static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i29;
  real_T c1_b_inData[2];
  int32_T c1_i30;
  real_T c1_u[2];
  const mxArray *c1_y = NULL;
  SFc1_nlinear_modelInstanceStruct *chartInstance;
  chartInstance = (SFc1_nlinear_modelInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i29 = 0; c1_i29 < 2; c1_i29++) {
    c1_b_inData[c1_i29] = (*(real_T (*)[2])c1_inData)[c1_i29];
  }

  for (c1_i30 = 0; c1_i30 < 2; c1_i30++) {
    c1_u[c1_i30] = c1_b_inData[c1_i30];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 2));
  sf_mex_assign(&c1_mxArrayOutData, c1_y);
  return c1_mxArrayOutData;
}

static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  real_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_nlinear_modelInstanceStruct *chartInstance;
  chartInstance = (SFc1_nlinear_modelInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(real_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c1_mxArrayOutData, c1_y);
  return c1_mxArrayOutData;
}

static real_T c1_c_emlrt_marshallIn(SFc1_nlinear_modelInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
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
  SFc1_nlinear_modelInstanceStruct *chartInstance;
  chartInstance = (SFc1_nlinear_modelInstanceStruct *)chartInstanceVoid;
  c1_nargout = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_nargout), &c1_thisId);
  sf_mex_destroy(&c1_nargout);
  *(real_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_e_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i31;
  int32_T c1_i32;
  int32_T c1_i33;
  real_T c1_b_inData[8];
  int32_T c1_i34;
  int32_T c1_i35;
  int32_T c1_i36;
  real_T c1_u[8];
  const mxArray *c1_y = NULL;
  SFc1_nlinear_modelInstanceStruct *chartInstance;
  chartInstance = (SFc1_nlinear_modelInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_i31 = 0;
  for (c1_i32 = 0; c1_i32 < 2; c1_i32++) {
    for (c1_i33 = 0; c1_i33 < 4; c1_i33++) {
      c1_b_inData[c1_i33 + c1_i31] = (*(real_T (*)[8])c1_inData)[c1_i33 + c1_i31];
    }

    c1_i31 += 4;
  }

  c1_i34 = 0;
  for (c1_i35 = 0; c1_i35 < 2; c1_i35++) {
    for (c1_i36 = 0; c1_i36 < 4; c1_i36++) {
      c1_u[c1_i36 + c1_i34] = c1_b_inData[c1_i36 + c1_i34];
    }

    c1_i34 += 4;
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 2, 4, 2));
  sf_mex_assign(&c1_mxArrayOutData, c1_y);
  return c1_mxArrayOutData;
}

static void c1_d_emlrt_marshallIn(SFc1_nlinear_modelInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[8])
{
  real_T c1_dv2[8];
  int32_T c1_i37;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv2, 1, 0, 0U, 1, 0U, 2, 4, 2);
  for (c1_i37 = 0; c1_i37 < 8; c1_i37++) {
    c1_y[c1_i37] = c1_dv2[c1_i37];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_Bss;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y[8];
  int32_T c1_i38;
  int32_T c1_i39;
  int32_T c1_i40;
  SFc1_nlinear_modelInstanceStruct *chartInstance;
  chartInstance = (SFc1_nlinear_modelInstanceStruct *)chartInstanceVoid;
  c1_Bss = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_Bss), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_Bss);
  c1_i38 = 0;
  for (c1_i39 = 0; c1_i39 < 2; c1_i39++) {
    for (c1_i40 = 0; c1_i40 < 4; c1_i40++) {
      (*(real_T (*)[8])c1_outData)[c1_i40 + c1_i38] = c1_y[c1_i40 + c1_i38];
    }

    c1_i38 += 4;
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_f_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i41;
  int32_T c1_i42;
  int32_T c1_i43;
  real_T c1_b_inData[16];
  int32_T c1_i44;
  int32_T c1_i45;
  int32_T c1_i46;
  real_T c1_u[16];
  const mxArray *c1_y = NULL;
  SFc1_nlinear_modelInstanceStruct *chartInstance;
  chartInstance = (SFc1_nlinear_modelInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_i41 = 0;
  for (c1_i42 = 0; c1_i42 < 4; c1_i42++) {
    for (c1_i43 = 0; c1_i43 < 4; c1_i43++) {
      c1_b_inData[c1_i43 + c1_i41] = (*(real_T (*)[16])c1_inData)[c1_i43 +
        c1_i41];
    }

    c1_i41 += 4;
  }

  c1_i44 = 0;
  for (c1_i45 = 0; c1_i45 < 4; c1_i45++) {
    for (c1_i46 = 0; c1_i46 < 4; c1_i46++) {
      c1_u[c1_i46 + c1_i44] = c1_b_inData[c1_i46 + c1_i44];
    }

    c1_i44 += 4;
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 2, 4, 4));
  sf_mex_assign(&c1_mxArrayOutData, c1_y);
  return c1_mxArrayOutData;
}

static void c1_e_emlrt_marshallIn(SFc1_nlinear_modelInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[16])
{
  real_T c1_dv3[16];
  int32_T c1_i47;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv3, 1, 0, 0U, 1, 0U, 2, 4, 4);
  for (c1_i47 = 0; c1_i47 < 16; c1_i47++) {
    c1_y[c1_i47] = c1_dv3[c1_i47];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_Ass;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y[16];
  int32_T c1_i48;
  int32_T c1_i49;
  int32_T c1_i50;
  SFc1_nlinear_modelInstanceStruct *chartInstance;
  chartInstance = (SFc1_nlinear_modelInstanceStruct *)chartInstanceVoid;
  c1_Ass = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_Ass), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_Ass);
  c1_i48 = 0;
  for (c1_i49 = 0; c1_i49 < 4; c1_i49++) {
    for (c1_i50 = 0; c1_i50 < 4; c1_i50++) {
      (*(real_T (*)[16])c1_outData)[c1_i50 + c1_i48] = c1_y[c1_i50 + c1_i48];
    }

    c1_i48 += 4;
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

const mxArray *sf_c1_nlinear_model_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo;
  c1_ResolvedFunctionInfo c1_info[18];
  const mxArray *c1_m0 = NULL;
  int32_T c1_i51;
  c1_ResolvedFunctionInfo *c1_r0;
  c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  c1_info_helper(c1_info);
  sf_mex_assign(&c1_m0, sf_mex_createstruct("nameCaptureInfo", 1, 18));
  for (c1_i51 = 0; c1_i51 < 18; c1_i51++) {
    c1_r0 = &c1_info[c1_i51];
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->context)), "context", "nameCaptureInfo",
                    c1_i51);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c1_r0->name)), "name", "nameCaptureInfo", c1_i51);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c1_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c1_i51);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->resolved)), "resolved", "nameCaptureInfo",
                    c1_i51);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c1_i51);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c1_i51);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c1_i51);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c1_i51);
  }

  sf_mex_assign(&c1_nameCaptureInfo, c1_m0);
  return c1_nameCaptureInfo;
}

static void c1_info_helper(c1_ResolvedFunctionInfo c1_info[18])
{
  c1_info[0].context = "";
  c1_info[0].name = "mrdivide";
  c1_info[0].dominantType = "double";
  c1_info[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c1_info[0].fileTimeLo = 3368733440U;
  c1_info[0].fileTimeHi = 30130985U;
  c1_info[0].mFileTimeLo = 529702400U;
  c1_info[0].mFileTimeHi = 30114350U;
  c1_info[1].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c1_info[1].name = "rdivide";
  c1_info[1].dominantType = "double";
  c1_info[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c1_info[1].fileTimeLo = 3099026944U;
  c1_info[1].fileTimeHi = 30108061U;
  c1_info[1].mFileTimeLo = 0U;
  c1_info[1].mFileTimeHi = 0U;
  c1_info[2].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c1_info[2].name = "eml_div";
  c1_info[2].dominantType = "double";
  c1_info[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c1_info[2].fileTimeLo = 1639026944U;
  c1_info[2].fileTimeHi = 30108061U;
  c1_info[2].mFileTimeLo = 0U;
  c1_info[2].mFileTimeHi = 0U;
  c1_info[3].context = "";
  c1_info[3].name = "mtimes";
  c1_info[3].dominantType = "double";
  c1_info[3].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[3].fileTimeLo = 529702400U;
  c1_info[3].fileTimeHi = 30114350U;
  c1_info[3].mFileTimeLo = 0U;
  c1_info[3].mFileTimeHi = 0U;
  c1_info[4].context = "";
  c1_info[4].name = "sqrt";
  c1_info[4].dominantType = "double";
  c1_info[4].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c1_info[4].fileTimeLo = 2179026944U;
  c1_info[4].fileTimeHi = 30108061U;
  c1_info[4].mFileTimeLo = 0U;
  c1_info[4].mFileTimeHi = 0U;
  c1_info[5].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c1_info[5].name = "eml_error";
  c1_info[5].dominantType = "char";
  c1_info[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c1_info[5].fileTimeLo = 1659026944U;
  c1_info[5].fileTimeHi = 30108061U;
  c1_info[5].mFileTimeLo = 0U;
  c1_info[5].mFileTimeHi = 0U;
  c1_info[6].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c1_info[6].name = "eml_scalar_sqrt";
  c1_info[6].dominantType = "double";
  c1_info[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m";
  c1_info[6].fileTimeLo = 2039026944U;
  c1_info[6].fileTimeHi = 30108061U;
  c1_info[6].mFileTimeLo = 0U;
  c1_info[6].mFileTimeHi = 0U;
  c1_info[7].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[7].name = "eml_index_class";
  c1_info[7].dominantType = "";
  c1_info[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[7].fileTimeLo = 2439026944U;
  c1_info[7].fileTimeHi = 30108061U;
  c1_info[7].mFileTimeLo = 0U;
  c1_info[7].mFileTimeHi = 0U;
  c1_info[8].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[8].name = "eml_scalar_eg";
  c1_info[8].dominantType = "double";
  c1_info[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[8].fileTimeLo = 2619026944U;
  c1_info[8].fileTimeHi = 30108061U;
  c1_info[8].mFileTimeLo = 0U;
  c1_info[8].mFileTimeHi = 0U;
  c1_info[9].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[9].name = "eml_xgemm";
  c1_info[9].dominantType = "int32";
  c1_info[9].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c1_info[9].fileTimeLo = 1759026944U;
  c1_info[9].fileTimeHi = 30108061U;
  c1_info[9].mFileTimeLo = 0U;
  c1_info[9].mFileTimeHi = 0U;
  c1_info[10].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!itcount";
  c1_info[10].name = "length";
  c1_info[10].dominantType = "double";
  c1_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c1_info[10].fileTimeLo = 2259026944U;
  c1_info[10].fileTimeHi = 30108061U;
  c1_info[10].mFileTimeLo = 0U;
  c1_info[10].mFileTimeHi = 0U;
  c1_info[11].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!itcount";
  c1_info[11].name = "min";
  c1_info[11].dominantType = "double";
  c1_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c1_info[11].fileTimeLo = 1619026944U;
  c1_info[11].fileTimeHi = 30108061U;
  c1_info[11].mFileTimeLo = 0U;
  c1_info[11].mFileTimeHi = 0U;
  c1_info[12].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c1_info[12].name = "eml_min_or_max";
  c1_info[12].dominantType = "char";
  c1_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c1_info[12].fileTimeLo = 2539026944U;
  c1_info[12].fileTimeHi = 30108061U;
  c1_info[12].mFileTimeLo = 0U;
  c1_info[12].mFileTimeHi = 0U;
  c1_info[13].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c1_info[13].name = "eml_scalexp_alloc";
  c1_info[13].dominantType = "double";
  c1_info[13].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c1_info[13].fileTimeLo = 2619026944U;
  c1_info[13].fileTimeHi = 30108061U;
  c1_info[13].mFileTimeLo = 0U;
  c1_info[13].mFileTimeHi = 0U;
  c1_info[14].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c1_info[14].name = "eml_refblas_xgemm";
  c1_info[14].dominantType = "int32";
  c1_info[14].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c1_info[14].fileTimeLo = 2479026944U;
  c1_info[14].fileTimeHi = 30108061U;
  c1_info[14].mFileTimeLo = 0U;
  c1_info[14].mFileTimeHi = 0U;
  c1_info[15].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c1_info[15].name = "eml_index_minus";
  c1_info[15].dominantType = "int32";
  c1_info[15].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c1_info[15].fileTimeLo = 2439026944U;
  c1_info[15].fileTimeHi = 30108061U;
  c1_info[15].mFileTimeLo = 0U;
  c1_info[15].mFileTimeHi = 0U;
  c1_info[16].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c1_info[16].name = "eml_index_times";
  c1_info[16].dominantType = "int32";
  c1_info[16].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c1_info[16].fileTimeLo = 2459026944U;
  c1_info[16].fileTimeHi = 30108061U;
  c1_info[16].mFileTimeLo = 0U;
  c1_info[16].mFileTimeHi = 0U;
  c1_info[17].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c1_info[17].name = "eml_index_plus";
  c1_info[17].dominantType = "int32";
  c1_info[17].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c1_info[17].fileTimeLo = 2439026944U;
  c1_info[17].fileTimeHi = 30108061U;
  c1_info[17].mFileTimeLo = 0U;
  c1_info[17].mFileTimeHi = 0U;
}

static real_T c1_sqrt(SFc1_nlinear_modelInstanceStruct *chartInstance, real_T
                      c1_x)
{
  real_T c1_b_x;
  c1_b_x = c1_x;
  c1_b_sqrt(chartInstance, &c1_b_x);
  return c1_b_x;
}

static void c1_eml_error(SFc1_nlinear_modelInstanceStruct *chartInstance)
{
  int32_T c1_i52;
  static char_T c1_varargin_1[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o',
    'o', 'l', 'b', 'o', 'x', ':', 's', 'q', 'r', 't', '_', 'd', 'o', 'm', 'a',
    'i', 'n', 'E', 'r', 'r', 'o', 'r' };

  char_T c1_u[30];
  const mxArray *c1_y = NULL;
  for (c1_i52 = 0; c1_i52 < 30; c1_i52++) {
    c1_u[c1_i52] = c1_varargin_1[c1_i52];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 30));
  sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 1U, 14,
    c1_y));
}

static void c1_eml_scalar_eg(SFc1_nlinear_modelInstanceStruct *chartInstance)
{
}

static void c1_b_eml_scalar_eg(SFc1_nlinear_modelInstanceStruct *chartInstance)
{
}

static const mxArray *c1_g_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_nlinear_modelInstanceStruct *chartInstance;
  chartInstance = (SFc1_nlinear_modelInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(int32_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 6, 0U, 0U, 0U, 0));
  sf_mex_assign(&c1_mxArrayOutData, c1_y);
  return c1_mxArrayOutData;
}

static int32_T c1_f_emlrt_marshallIn(SFc1_nlinear_modelInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  int32_T c1_y;
  int32_T c1_i53;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_i53, 1, 6, 0U, 0, 0U, 0);
  c1_y = c1_i53;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_sfEvent;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  int32_T c1_y;
  SFc1_nlinear_modelInstanceStruct *chartInstance;
  chartInstance = (SFc1_nlinear_modelInstanceStruct *)chartInstanceVoid;
  c1_b_sfEvent = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_sfEvent),
    &c1_thisId);
  sf_mex_destroy(&c1_b_sfEvent);
  *(int32_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_ctes_bus_io(void *chartInstanceVoid, void *c1_pData)
{
  const mxArray *c1_mxVal = NULL;
  c1_slBus1 c1_tmp;
  int32_T c1_i54;
  int32_T c1_i55;
  int32_T c1_i56;
  SFc1_nlinear_modelInstanceStruct *chartInstance;
  chartInstance = (SFc1_nlinear_modelInstanceStruct *)chartInstanceVoid;
  c1_mxVal = NULL;
  c1_tmp.A1 = *(real_T *)((char_T *)c1_pData + 0);
  c1_tmp.A2 = *(real_T *)((char_T *)c1_pData + 8);
  c1_tmp.A3 = *(real_T *)((char_T *)c1_pData + 16);
  c1_tmp.A4 = *(real_T *)((char_T *)c1_pData + 24);
  c1_tmp.a1 = *(real_T *)((char_T *)c1_pData + 32);
  c1_tmp.a2 = *(real_T *)((char_T *)c1_pData + 40);
  c1_tmp.a3 = *(real_T *)((char_T *)c1_pData + 48);
  c1_tmp.a4 = *(real_T *)((char_T *)c1_pData + 56);
  c1_tmp.kc = *(real_T *)((char_T *)c1_pData + 64);
  c1_tmp.k1 = *(real_T *)((char_T *)c1_pData + 72);
  c1_tmp.k2 = *(real_T *)((char_T *)c1_pData + 80);
  c1_tmp.g = *(real_T *)((char_T *)c1_pData + 88);
  for (c1_i54 = 0; c1_i54 < 4; c1_i54++) {
    c1_tmp.hlin[c1_i54] = ((real_T *)((char_T *)c1_pData + 96))[c1_i54];
  }

  for (c1_i55 = 0; c1_i55 < 4; c1_i55++) {
    c1_tmp.h0[c1_i55] = ((real_T *)((char_T *)c1_pData + 128))[c1_i55];
  }

  for (c1_i56 = 0; c1_i56 < 2; c1_i56++) {
    c1_tmp.vlin[c1_i56] = ((real_T *)((char_T *)c1_pData + 160))[c1_i56];
  }

  sf_mex_assign(&c1_mxVal, c1_b_sf_marshallOut(chartInstance, &c1_tmp));
  return c1_mxVal;
}

static uint8_T c1_g_emlrt_marshallIn(SFc1_nlinear_modelInstanceStruct
  *chartInstance, const mxArray *c1_b_is_active_c1_nlinear_model, const char_T
  *c1_identifier)
{
  uint8_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_b_is_active_c1_nlinear_model), &c1_thisId);
  sf_mex_destroy(&c1_b_is_active_c1_nlinear_model);
  return c1_y;
}

static uint8_T c1_h_emlrt_marshallIn(SFc1_nlinear_modelInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint8_T c1_y;
  uint8_T c1_u0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_u0, 1, 3, 0U, 0, 0U, 0);
  c1_y = c1_u0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_b_sqrt(SFc1_nlinear_modelInstanceStruct *chartInstance, real_T
                      *c1_x)
{
  if (*c1_x < 0.0) {
    c1_eml_error(chartInstance);
  }

  *c1_x = muDoubleScalarSqrt(*c1_x);
}

static void init_dsm_address_info(SFc1_nlinear_modelInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c1_nlinear_model_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2072520697U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3663000187U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2002145078U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2547458126U);
}

mxArray *sf_c1_nlinear_model_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(3054510230U);
    pr[1] = (double)(276442309U);
    pr[2] = (double)(4122512270U);
    pr[3] = (double)(3430152366U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,5,3,dataFields);

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
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(13));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(4);
      pr[1] = (double)(1);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));
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

static const mxArray *sf_get_sim_state_info_c1_nlinear_model(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"dx\",},{M[8],M[0],T\"is_active_c1_nlinear_model\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_nlinear_model_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_nlinear_modelInstanceStruct *chartInstance;
    chartInstance = (SFc1_nlinear_modelInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_nlinear_modelMachineNumber_,
           1,
           1,
           1,
           6,
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
          init_script_number_translation(_nlinear_modelMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_nlinear_modelMachineNumber_,chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_nlinear_modelMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"v1");
          _SFD_SET_DATA_PROPS(1,2,0,1,"dx");
          _SFD_SET_DATA_PROPS(2,1,1,0,"v2");
          _SFD_SET_DATA_PROPS(3,1,1,0,"gama");
          _SFD_SET_DATA_PROPS(4,1,1,0,"ctes");
          _SFD_SET_DATA_PROPS(5,1,1,0,"x");
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
        _SFD_CV_INIT_EML(0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,569);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_d_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)
            c1_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_d_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(4,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_ctes_bus_io,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          real_T *c1_v1;
          real_T *c1_v2;
          void **c1_ctes;
          real_T (*c1_dx)[4];
          real_T (*c1_gama)[2];
          real_T (*c1_x)[4];
          c1_x = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 4);
          c1_ctes = (void **)ssGetInputPortSignal(chartInstance->S, 3);
          c1_gama = (real_T (*)[2])ssGetInputPortSignal(chartInstance->S, 2);
          c1_v2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c1_dx = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
          c1_v1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c1_v1);
          _SFD_SET_DATA_VALUE_PTR(1U, *c1_dx);
          _SFD_SET_DATA_VALUE_PTR(2U, c1_v2);
          _SFD_SET_DATA_VALUE_PTR(3U, *c1_gama);
          _SFD_SET_DATA_VALUE_PTR(4U, c1_ctes);
          _SFD_SET_DATA_VALUE_PTR(5U, *c1_x);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_nlinear_modelMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c1_nlinear_model(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc1_nlinear_modelInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c1_nlinear_model((SFc1_nlinear_modelInstanceStruct*)
    chartInstanceVar);
  initialize_c1_nlinear_model((SFc1_nlinear_modelInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c1_nlinear_model(void *chartInstanceVar)
{
  enable_c1_nlinear_model((SFc1_nlinear_modelInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c1_nlinear_model(void *chartInstanceVar)
{
  disable_c1_nlinear_model((SFc1_nlinear_modelInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c1_nlinear_model(void *chartInstanceVar)
{
  sf_c1_nlinear_model((SFc1_nlinear_modelInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c1_nlinear_model(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c1_nlinear_model
    ((SFc1_nlinear_modelInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_nlinear_model();/* state var info */
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

extern void sf_internal_set_sim_state_c1_nlinear_model(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_nlinear_model();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c1_nlinear_model((SFc1_nlinear_modelInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c1_nlinear_model(SimStruct* S)
{
  return sf_internal_get_sim_state_c1_nlinear_model(S);
}

static void sf_opaque_set_sim_state_c1_nlinear_model(SimStruct* S, const mxArray
  *st)
{
  sf_internal_set_sim_state_c1_nlinear_model(S, st);
}

static void sf_opaque_terminate_c1_nlinear_model(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_nlinear_modelInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c1_nlinear_model((SFc1_nlinear_modelInstanceStruct*)
      chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc1_nlinear_model((SFc1_nlinear_modelInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_nlinear_model(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c1_nlinear_model((SFc1_nlinear_modelInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c1_nlinear_model(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,"nlinear_model","nlinear_model",1);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,"nlinear_model","nlinear_model",1,
                "RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,"nlinear_model",
      "nlinear_model",1,"gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"nlinear_model","nlinear_model",1,5);
      sf_mark_chart_reusable_outputs(S,"nlinear_model","nlinear_model",1,1);
    }

    sf_set_rtw_dwork_info(S,"nlinear_model","nlinear_model",1);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1627283622U));
  ssSetChecksum1(S,(1844117400U));
  ssSetChecksum2(S,(2458779029U));
  ssSetChecksum3(S,(1587704183U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c1_nlinear_model(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "nlinear_model", "nlinear_model",1);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c1_nlinear_model(SimStruct *S)
{
  SFc1_nlinear_modelInstanceStruct *chartInstance;
  chartInstance = (SFc1_nlinear_modelInstanceStruct *)malloc(sizeof
    (SFc1_nlinear_modelInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc1_nlinear_modelInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c1_nlinear_model;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c1_nlinear_model;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c1_nlinear_model;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c1_nlinear_model;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c1_nlinear_model;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c1_nlinear_model;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c1_nlinear_model;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c1_nlinear_model;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_nlinear_model;
  chartInstance->chartInfo.mdlStart = mdlStart_c1_nlinear_model;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c1_nlinear_model;
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

void c1_nlinear_model_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_nlinear_model(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_nlinear_model(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_nlinear_model(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_nlinear_model_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
