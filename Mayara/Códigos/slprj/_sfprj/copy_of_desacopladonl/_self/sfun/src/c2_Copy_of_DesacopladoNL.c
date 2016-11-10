/* Include files */

#include "blascompat32.h"
#include "Copy_of_DesacopladoNL_sfun.h"
#include "c2_Copy_of_DesacopladoNL.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Copy_of_DesacopladoNL_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char * c2_debug_family_names[8] = { "nargin", "nargout", "v1", "v2",
  "gama", "ctes", "h", "dh" };

/* Function Declarations */
static void initialize_c2_Copy_of_DesacopladoNL
  (SFc2_Copy_of_DesacopladoNLInstanceStruct *chartInstance);
static void initialize_params_c2_Copy_of_DesacopladoNL
  (SFc2_Copy_of_DesacopladoNLInstanceStruct *chartInstance);
static void enable_c2_Copy_of_DesacopladoNL
  (SFc2_Copy_of_DesacopladoNLInstanceStruct *chartInstance);
static void disable_c2_Copy_of_DesacopladoNL
  (SFc2_Copy_of_DesacopladoNLInstanceStruct *chartInstance);
static void c2_update_debugger_state_c2_Copy_of_DesacopladoNL
  (SFc2_Copy_of_DesacopladoNLInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c2_Copy_of_DesacopladoNL
  (SFc2_Copy_of_DesacopladoNLInstanceStruct *chartInstance);
static void set_sim_state_c2_Copy_of_DesacopladoNL
  (SFc2_Copy_of_DesacopladoNLInstanceStruct *chartInstance, const mxArray *c2_st);
static void finalize_c2_Copy_of_DesacopladoNL
  (SFc2_Copy_of_DesacopladoNLInstanceStruct *chartInstance);
static void sf_c2_Copy_of_DesacopladoNL(SFc2_Copy_of_DesacopladoNLInstanceStruct
  *chartInstance);
static void c2_chartstep_c2_Copy_of_DesacopladoNL
  (SFc2_Copy_of_DesacopladoNLInstanceStruct *chartInstance);
static void initSimStructsc2_Copy_of_DesacopladoNL
  (SFc2_Copy_of_DesacopladoNLInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber);
static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData);
static void c2_emlrt_marshallIn(SFc2_Copy_of_DesacopladoNLInstanceStruct
  *chartInstance, const mxArray *c2_dh, const char_T *c2_identifier, real_T
  c2_y[4]);
static void c2_b_emlrt_marshallIn(SFc2_Copy_of_DesacopladoNLInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[4]);
static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static real_T c2_c_emlrt_marshallIn(SFc2_Copy_of_DesacopladoNLInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static void c2_eml_error(SFc2_Copy_of_DesacopladoNLInstanceStruct *chartInstance);
static const mxArray *c2_e_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static int32_T c2_d_emlrt_marshallIn(SFc2_Copy_of_DesacopladoNLInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_ctes_bus_io(void *chartInstanceVoid, void *c2_pData);
static uint8_T c2_e_emlrt_marshallIn(SFc2_Copy_of_DesacopladoNLInstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_Copy_of_DesacopladoNL, const
  char_T *c2_identifier);
static uint8_T c2_f_emlrt_marshallIn(SFc2_Copy_of_DesacopladoNLInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void init_dsm_address_info(SFc2_Copy_of_DesacopladoNLInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c2_Copy_of_DesacopladoNL
  (SFc2_Copy_of_DesacopladoNLInstanceStruct *chartInstance)
{
  chartInstance->c2_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c2_is_active_c2_Copy_of_DesacopladoNL = 0U;
}

static void initialize_params_c2_Copy_of_DesacopladoNL
  (SFc2_Copy_of_DesacopladoNLInstanceStruct *chartInstance)
{
}

static void enable_c2_Copy_of_DesacopladoNL
  (SFc2_Copy_of_DesacopladoNLInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c2_Copy_of_DesacopladoNL
  (SFc2_Copy_of_DesacopladoNLInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c2_update_debugger_state_c2_Copy_of_DesacopladoNL
  (SFc2_Copy_of_DesacopladoNLInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c2_Copy_of_DesacopladoNL
  (SFc2_Copy_of_DesacopladoNLInstanceStruct *chartInstance)
{
  const mxArray *c2_st;
  const mxArray *c2_y = NULL;
  int32_T c2_i0;
  real_T c2_u[4];
  const mxArray *c2_b_y = NULL;
  uint8_T c2_hoistedGlobal;
  uint8_T c2_b_u;
  const mxArray *c2_c_y = NULL;
  real_T (*c2_dh)[4];
  c2_dh = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  c2_st = NULL;
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellarray(2));
  for (c2_i0 = 0; c2_i0 < 4; c2_i0++) {
    c2_u[c2_i0] = (*c2_dh)[c2_i0];
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 1, 4));
  sf_mex_setcell(c2_y, 0, c2_b_y);
  c2_hoistedGlobal = chartInstance->c2_is_active_c2_Copy_of_DesacopladoNL;
  c2_b_u = c2_hoistedGlobal;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_b_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c2_y, 1, c2_c_y);
  sf_mex_assign(&c2_st, c2_y);
  return c2_st;
}

static void set_sim_state_c2_Copy_of_DesacopladoNL
  (SFc2_Copy_of_DesacopladoNLInstanceStruct *chartInstance, const mxArray *c2_st)
{
  const mxArray *c2_u;
  real_T c2_dv0[4];
  int32_T c2_i1;
  real_T (*c2_dh)[4];
  c2_dh = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c2_doneDoubleBufferReInit = TRUE;
  c2_u = sf_mex_dup(c2_st);
  c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 0)), "dh",
                      c2_dv0);
  for (c2_i1 = 0; c2_i1 < 4; c2_i1++) {
    (*c2_dh)[c2_i1] = c2_dv0[c2_i1];
  }

  chartInstance->c2_is_active_c2_Copy_of_DesacopladoNL = c2_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 1)),
     "is_active_c2_Copy_of_DesacopladoNL");
  sf_mex_destroy(&c2_u);
  c2_update_debugger_state_c2_Copy_of_DesacopladoNL(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void finalize_c2_Copy_of_DesacopladoNL
  (SFc2_Copy_of_DesacopladoNLInstanceStruct *chartInstance)
{
}

static void sf_c2_Copy_of_DesacopladoNL(SFc2_Copy_of_DesacopladoNLInstanceStruct
  *chartInstance)
{
  int32_T c2_i2;
  int32_T c2_i3;
  int32_T c2_i4;
  real_T *c2_v1;
  real_T *c2_v2;
  real_T (*c2_h)[4];
  real_T (*c2_gama)[2];
  real_T (*c2_dh)[4];
  c2_h = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 4);
  c2_gama = (real_T (*)[2])ssGetInputPortSignal(chartInstance->S, 2);
  c2_v2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c2_dh = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  c2_v1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c2_v1, 0U);
  for (c2_i2 = 0; c2_i2 < 4; c2_i2++) {
    _SFD_DATA_RANGE_CHECK((*c2_dh)[c2_i2], 1U);
  }

  _SFD_DATA_RANGE_CHECK(*c2_v2, 2U);
  for (c2_i3 = 0; c2_i3 < 2; c2_i3++) {
    _SFD_DATA_RANGE_CHECK((*c2_gama)[c2_i3], 3U);
  }

  for (c2_i4 = 0; c2_i4 < 4; c2_i4++) {
    _SFD_DATA_RANGE_CHECK((*c2_h)[c2_i4], 5U);
  }

  chartInstance->c2_sfEvent = CALL_EVENT;
  c2_chartstep_c2_Copy_of_DesacopladoNL(chartInstance);
  sf_debug_check_for_state_inconsistency(_Copy_of_DesacopladoNLMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c2_chartstep_c2_Copy_of_DesacopladoNL
  (SFc2_Copy_of_DesacopladoNLInstanceStruct *chartInstance)
{
  real_T c2_hoistedGlobal;
  real_T c2_b_hoistedGlobal;
  real_T c2_v1;
  real_T c2_v2;
  int32_T c2_i5;
  real_T c2_gama[2];
  c2_slBus1 c2_ctes;
  int32_T c2_i6;
  int32_T c2_i7;
  int32_T c2_i8;
  int32_T c2_i9;
  int32_T c2_i10;
  real_T c2_h[4];
  uint32_T c2_debug_family_var_map[8];
  real_T c2_nargin = 5.0;
  real_T c2_nargout = 1.0;
  real_T c2_dh[4];
  int32_T c2_i11;
  real_T c2_A;
  real_T c2_B;
  real_T c2_x;
  real_T c2_y;
  real_T c2_b_x;
  real_T c2_b_y;
  real_T c2_c_x;
  real_T c2_c_y;
  real_T c2_d_y;
  real_T c2_b;
  real_T c2_e_y;
  real_T c2_a;
  real_T c2_b_b;
  real_T c2_f_y;
  real_T c2_d_x;
  real_T c2_e_x;
  real_T c2_b_a;
  real_T c2_c_b;
  real_T c2_g_y;
  real_T c2_b_A;
  real_T c2_b_B;
  real_T c2_f_x;
  real_T c2_h_y;
  real_T c2_g_x;
  real_T c2_i_y;
  real_T c2_h_x;
  real_T c2_j_y;
  real_T c2_k_y;
  real_T c2_d_b;
  real_T c2_l_y;
  real_T c2_c_a;
  real_T c2_e_b;
  real_T c2_m_y;
  real_T c2_i_x;
  real_T c2_j_x;
  real_T c2_d_a;
  real_T c2_f_b;
  real_T c2_n_y;
  real_T c2_e_a;
  real_T c2_g_b;
  real_T c2_o_y;
  real_T c2_f_a;
  real_T c2_h_b;
  real_T c2_p_y;
  real_T c2_c_A;
  real_T c2_c_B;
  real_T c2_k_x;
  real_T c2_q_y;
  real_T c2_l_x;
  real_T c2_r_y;
  real_T c2_m_x;
  real_T c2_s_y;
  real_T c2_t_y;
  real_T c2_d_A;
  real_T c2_d_B;
  real_T c2_n_x;
  real_T c2_u_y;
  real_T c2_o_x;
  real_T c2_v_y;
  real_T c2_p_x;
  real_T c2_w_y;
  real_T c2_x_y;
  real_T c2_i_b;
  real_T c2_y_y;
  real_T c2_g_a;
  real_T c2_j_b;
  real_T c2_ab_y;
  real_T c2_q_x;
  real_T c2_r_x;
  real_T c2_h_a;
  real_T c2_k_b;
  real_T c2_bb_y;
  real_T c2_e_A;
  real_T c2_e_B;
  real_T c2_s_x;
  real_T c2_cb_y;
  real_T c2_t_x;
  real_T c2_db_y;
  real_T c2_u_x;
  real_T c2_eb_y;
  real_T c2_fb_y;
  real_T c2_l_b;
  real_T c2_gb_y;
  real_T c2_i_a;
  real_T c2_m_b;
  real_T c2_hb_y;
  real_T c2_v_x;
  real_T c2_w_x;
  real_T c2_j_a;
  real_T c2_n_b;
  real_T c2_ib_y;
  real_T c2_k_a;
  real_T c2_o_b;
  real_T c2_jb_y;
  real_T c2_l_a;
  real_T c2_p_b;
  real_T c2_kb_y;
  real_T c2_f_A;
  real_T c2_f_B;
  real_T c2_x_x;
  real_T c2_lb_y;
  real_T c2_y_x;
  real_T c2_mb_y;
  real_T c2_ab_x;
  real_T c2_nb_y;
  real_T c2_ob_y;
  real_T c2_g_A;
  real_T c2_g_B;
  real_T c2_bb_x;
  real_T c2_pb_y;
  real_T c2_cb_x;
  real_T c2_qb_y;
  real_T c2_db_x;
  real_T c2_rb_y;
  real_T c2_sb_y;
  real_T c2_q_b;
  real_T c2_tb_y;
  real_T c2_m_a;
  real_T c2_r_b;
  real_T c2_ub_y;
  real_T c2_eb_x;
  real_T c2_fb_x;
  real_T c2_n_a;
  real_T c2_s_b;
  real_T c2_vb_y;
  real_T c2_o_a;
  real_T c2_t_b;
  real_T c2_wb_y;
  real_T c2_p_a;
  real_T c2_u_b;
  real_T c2_xb_y;
  real_T c2_h_A;
  real_T c2_h_B;
  real_T c2_gb_x;
  real_T c2_yb_y;
  real_T c2_hb_x;
  real_T c2_ac_y;
  real_T c2_ib_x;
  real_T c2_bc_y;
  real_T c2_cc_y;
  real_T c2_i_A;
  real_T c2_i_B;
  real_T c2_jb_x;
  real_T c2_dc_y;
  real_T c2_kb_x;
  real_T c2_ec_y;
  real_T c2_lb_x;
  real_T c2_fc_y;
  real_T c2_gc_y;
  real_T c2_v_b;
  real_T c2_hc_y;
  real_T c2_q_a;
  real_T c2_w_b;
  real_T c2_ic_y;
  real_T c2_mb_x;
  real_T c2_nb_x;
  real_T c2_r_a;
  real_T c2_x_b;
  real_T c2_jc_y;
  real_T c2_s_a;
  real_T c2_y_b;
  real_T c2_kc_y;
  real_T c2_t_a;
  real_T c2_ab_b;
  real_T c2_lc_y;
  real_T c2_j_A;
  real_T c2_j_B;
  real_T c2_ob_x;
  real_T c2_mc_y;
  real_T c2_pb_x;
  real_T c2_nc_y;
  real_T c2_qb_x;
  real_T c2_oc_y;
  real_T c2_pc_y;
  int32_T c2_i12;
  real_T *c2_b_v1;
  real_T *c2_b_v2;
  real_T (*c2_b_dh)[4];
  real_T (*c2_b_h)[4];
  real_T (*c2_b_gama)[2];
  void **c2_b_ctes;
  c2_b_h = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 4);
  c2_b_ctes = (void **)ssGetInputPortSignal(chartInstance->S, 3);
  c2_b_gama = (real_T (*)[2])ssGetInputPortSignal(chartInstance->S, 2);
  c2_b_v2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c2_b_dh = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  c2_b_v1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  c2_hoistedGlobal = *c2_b_v1;
  c2_b_hoistedGlobal = *c2_b_v2;
  c2_v1 = c2_hoistedGlobal;
  c2_v2 = c2_b_hoistedGlobal;
  for (c2_i5 = 0; c2_i5 < 2; c2_i5++) {
    c2_gama[c2_i5] = (*c2_b_gama)[c2_i5];
  }

  c2_ctes.A1 = *(real_T *)((char_T *)c2_b_ctes + 0);
  c2_ctes.A2 = *(real_T *)((char_T *)c2_b_ctes + 8);
  c2_ctes.A3 = *(real_T *)((char_T *)c2_b_ctes + 16);
  c2_ctes.A4 = *(real_T *)((char_T *)c2_b_ctes + 24);
  c2_ctes.a1 = *(real_T *)((char_T *)c2_b_ctes + 32);
  c2_ctes.a2 = *(real_T *)((char_T *)c2_b_ctes + 40);
  c2_ctes.a3 = *(real_T *)((char_T *)c2_b_ctes + 48);
  c2_ctes.a4 = *(real_T *)((char_T *)c2_b_ctes + 56);
  c2_ctes.kc = *(real_T *)((char_T *)c2_b_ctes + 64);
  c2_ctes.k1 = *(real_T *)((char_T *)c2_b_ctes + 72);
  c2_ctes.k2 = *(real_T *)((char_T *)c2_b_ctes + 80);
  c2_ctes.g = *(real_T *)((char_T *)c2_b_ctes + 88);
  for (c2_i6 = 0; c2_i6 < 4; c2_i6++) {
    c2_ctes.hlin[c2_i6] = ((real_T *)((char_T *)c2_b_ctes + 96))[c2_i6];
  }

  for (c2_i7 = 0; c2_i7 < 4; c2_i7++) {
    c2_ctes.h0[c2_i7] = ((real_T *)((char_T *)c2_b_ctes + 128))[c2_i7];
  }

  for (c2_i8 = 0; c2_i8 < 2; c2_i8++) {
    c2_ctes.vlin[c2_i8] = ((real_T *)((char_T *)c2_b_ctes + 160))[c2_i8];
  }

  for (c2_i9 = 0; c2_i9 < 2; c2_i9++) {
    c2_ctes.v0[c2_i9] = ((real_T *)((char_T *)c2_b_ctes + 176))[c2_i9];
  }

  for (c2_i10 = 0; c2_i10 < 4; c2_i10++) {
    c2_h[c2_i10] = (*c2_b_h)[c2_i10];
  }

  sf_debug_symbol_scope_push_eml(0U, 8U, 8U, c2_debug_family_names,
    c2_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c2_nargin, 0U, c2_d_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_nargout, 1U, c2_d_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c2_v1, 2U, c2_d_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_v2, 3U, c2_d_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c2_gama, 4U, c2_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_ctes, 5U, c2_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c2_h, 6U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c2_dh, 7U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 2);
  for (c2_i11 = 0; c2_i11 < 4; c2_i11++) {
    c2_dh[c2_i11] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 4);
  if (CV_EML_IF(0, 0, c2_h[0] < 0.0)) {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 5);
    c2_h[0] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 7);
  if (CV_EML_IF(0, 1, c2_h[1] < 0.0)) {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 8);
    c2_h[1] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 10);
  if (CV_EML_IF(0, 2, c2_h[2] < 0.0)) {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 11);
    c2_h[2] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 13);
  if (CV_EML_IF(0, 3, c2_h[3] < 0.0)) {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 14);
    c2_h[3] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 18);
  c2_A = -c2_ctes.a1;
  c2_B = c2_ctes.A1;
  c2_x = c2_A;
  c2_y = c2_B;
  c2_b_x = c2_x;
  c2_b_y = c2_y;
  c2_c_x = c2_b_x;
  c2_c_y = c2_b_y;
  c2_d_y = c2_c_x / c2_c_y;
  c2_b = c2_ctes.g;
  c2_e_y = 2.0 * c2_b;
  c2_a = c2_e_y;
  c2_b_b = c2_h[0];
  c2_f_y = c2_a * c2_b_b;
  c2_d_x = c2_f_y;
  c2_e_x = c2_d_x;
  if (c2_e_x < 0.0) {
    c2_eml_error(chartInstance);
  }

  c2_e_x = muDoubleScalarSqrt(c2_e_x);
  c2_b_a = c2_d_y;
  c2_c_b = c2_e_x;
  c2_g_y = c2_b_a * c2_c_b;
  c2_b_A = c2_ctes.a3;
  c2_b_B = c2_ctes.A1;
  c2_f_x = c2_b_A;
  c2_h_y = c2_b_B;
  c2_g_x = c2_f_x;
  c2_i_y = c2_h_y;
  c2_h_x = c2_g_x;
  c2_j_y = c2_i_y;
  c2_k_y = c2_h_x / c2_j_y;
  c2_d_b = c2_ctes.g;
  c2_l_y = 2.0 * c2_d_b;
  c2_c_a = c2_l_y;
  c2_e_b = c2_h[2];
  c2_m_y = c2_c_a * c2_e_b;
  c2_i_x = c2_m_y;
  c2_j_x = c2_i_x;
  if (c2_j_x < 0.0) {
    c2_eml_error(chartInstance);
  }

  c2_j_x = muDoubleScalarSqrt(c2_j_x);
  c2_d_a = c2_k_y;
  c2_f_b = c2_j_x;
  c2_n_y = c2_d_a * c2_f_b;
  c2_e_a = c2_gama[0];
  c2_g_b = c2_ctes.k1;
  c2_o_y = c2_e_a * c2_g_b;
  c2_f_a = c2_o_y;
  c2_h_b = c2_v1;
  c2_p_y = c2_f_a * c2_h_b;
  c2_c_A = c2_p_y;
  c2_c_B = c2_ctes.A1;
  c2_k_x = c2_c_A;
  c2_q_y = c2_c_B;
  c2_l_x = c2_k_x;
  c2_r_y = c2_q_y;
  c2_m_x = c2_l_x;
  c2_s_y = c2_r_y;
  c2_t_y = c2_m_x / c2_s_y;
  c2_dh[0] = (c2_g_y + c2_n_y) + c2_t_y;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 19);
  c2_d_A = -c2_ctes.a2;
  c2_d_B = c2_ctes.A2;
  c2_n_x = c2_d_A;
  c2_u_y = c2_d_B;
  c2_o_x = c2_n_x;
  c2_v_y = c2_u_y;
  c2_p_x = c2_o_x;
  c2_w_y = c2_v_y;
  c2_x_y = c2_p_x / c2_w_y;
  c2_i_b = c2_ctes.g;
  c2_y_y = 2.0 * c2_i_b;
  c2_g_a = c2_y_y;
  c2_j_b = c2_h[1];
  c2_ab_y = c2_g_a * c2_j_b;
  c2_q_x = c2_ab_y;
  c2_r_x = c2_q_x;
  if (c2_r_x < 0.0) {
    c2_eml_error(chartInstance);
  }

  c2_r_x = muDoubleScalarSqrt(c2_r_x);
  c2_h_a = c2_x_y;
  c2_k_b = c2_r_x;
  c2_bb_y = c2_h_a * c2_k_b;
  c2_e_A = c2_ctes.a4;
  c2_e_B = c2_ctes.A2;
  c2_s_x = c2_e_A;
  c2_cb_y = c2_e_B;
  c2_t_x = c2_s_x;
  c2_db_y = c2_cb_y;
  c2_u_x = c2_t_x;
  c2_eb_y = c2_db_y;
  c2_fb_y = c2_u_x / c2_eb_y;
  c2_l_b = c2_ctes.g;
  c2_gb_y = 2.0 * c2_l_b;
  c2_i_a = c2_gb_y;
  c2_m_b = c2_h[3];
  c2_hb_y = c2_i_a * c2_m_b;
  c2_v_x = c2_hb_y;
  c2_w_x = c2_v_x;
  if (c2_w_x < 0.0) {
    c2_eml_error(chartInstance);
  }

  c2_w_x = muDoubleScalarSqrt(c2_w_x);
  c2_j_a = c2_fb_y;
  c2_n_b = c2_w_x;
  c2_ib_y = c2_j_a * c2_n_b;
  c2_k_a = c2_gama[1];
  c2_o_b = c2_ctes.k2;
  c2_jb_y = c2_k_a * c2_o_b;
  c2_l_a = c2_jb_y;
  c2_p_b = c2_v2;
  c2_kb_y = c2_l_a * c2_p_b;
  c2_f_A = c2_kb_y;
  c2_f_B = c2_ctes.A2;
  c2_x_x = c2_f_A;
  c2_lb_y = c2_f_B;
  c2_y_x = c2_x_x;
  c2_mb_y = c2_lb_y;
  c2_ab_x = c2_y_x;
  c2_nb_y = c2_mb_y;
  c2_ob_y = c2_ab_x / c2_nb_y;
  c2_dh[1] = (c2_bb_y + c2_ib_y) + c2_ob_y;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 20);
  c2_g_A = -c2_ctes.a3;
  c2_g_B = c2_ctes.A3;
  c2_bb_x = c2_g_A;
  c2_pb_y = c2_g_B;
  c2_cb_x = c2_bb_x;
  c2_qb_y = c2_pb_y;
  c2_db_x = c2_cb_x;
  c2_rb_y = c2_qb_y;
  c2_sb_y = c2_db_x / c2_rb_y;
  c2_q_b = c2_ctes.g;
  c2_tb_y = 2.0 * c2_q_b;
  c2_m_a = c2_tb_y;
  c2_r_b = c2_h[2];
  c2_ub_y = c2_m_a * c2_r_b;
  c2_eb_x = c2_ub_y;
  c2_fb_x = c2_eb_x;
  if (c2_fb_x < 0.0) {
    c2_eml_error(chartInstance);
  }

  c2_fb_x = muDoubleScalarSqrt(c2_fb_x);
  c2_n_a = c2_sb_y;
  c2_s_b = c2_fb_x;
  c2_vb_y = c2_n_a * c2_s_b;
  c2_o_a = 1.0 - c2_gama[1];
  c2_t_b = c2_ctes.k2;
  c2_wb_y = c2_o_a * c2_t_b;
  c2_p_a = c2_wb_y;
  c2_u_b = c2_v2;
  c2_xb_y = c2_p_a * c2_u_b;
  c2_h_A = c2_xb_y;
  c2_h_B = c2_ctes.A3;
  c2_gb_x = c2_h_A;
  c2_yb_y = c2_h_B;
  c2_hb_x = c2_gb_x;
  c2_ac_y = c2_yb_y;
  c2_ib_x = c2_hb_x;
  c2_bc_y = c2_ac_y;
  c2_cc_y = c2_ib_x / c2_bc_y;
  c2_dh[2] = c2_vb_y + c2_cc_y;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 21);
  c2_i_A = -c2_ctes.a4;
  c2_i_B = c2_ctes.A4;
  c2_jb_x = c2_i_A;
  c2_dc_y = c2_i_B;
  c2_kb_x = c2_jb_x;
  c2_ec_y = c2_dc_y;
  c2_lb_x = c2_kb_x;
  c2_fc_y = c2_ec_y;
  c2_gc_y = c2_lb_x / c2_fc_y;
  c2_v_b = c2_ctes.g;
  c2_hc_y = 2.0 * c2_v_b;
  c2_q_a = c2_hc_y;
  c2_w_b = c2_h[3];
  c2_ic_y = c2_q_a * c2_w_b;
  c2_mb_x = c2_ic_y;
  c2_nb_x = c2_mb_x;
  if (c2_nb_x < 0.0) {
    c2_eml_error(chartInstance);
  }

  c2_nb_x = muDoubleScalarSqrt(c2_nb_x);
  c2_r_a = c2_gc_y;
  c2_x_b = c2_nb_x;
  c2_jc_y = c2_r_a * c2_x_b;
  c2_s_a = 1.0 - c2_gama[0];
  c2_y_b = c2_ctes.k1;
  c2_kc_y = c2_s_a * c2_y_b;
  c2_t_a = c2_kc_y;
  c2_ab_b = c2_v1;
  c2_lc_y = c2_t_a * c2_ab_b;
  c2_j_A = c2_lc_y;
  c2_j_B = c2_ctes.A4;
  c2_ob_x = c2_j_A;
  c2_mc_y = c2_j_B;
  c2_pb_x = c2_ob_x;
  c2_nc_y = c2_mc_y;
  c2_qb_x = c2_pb_x;
  c2_oc_y = c2_nc_y;
  c2_pc_y = c2_qb_x / c2_oc_y;
  c2_dh[3] = c2_jc_y + c2_pc_y;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, -21);
  sf_debug_symbol_scope_pop();
  for (c2_i12 = 0; c2_i12 < 4; c2_i12++) {
    (*c2_b_dh)[c2_i12] = c2_dh[c2_i12];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
}

static void initSimStructsc2_Copy_of_DesacopladoNL
  (SFc2_Copy_of_DesacopladoNLInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber)
{
}

static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i13;
  real_T c2_b_inData[4];
  int32_T c2_i14;
  real_T c2_u[4];
  const mxArray *c2_y = NULL;
  SFc2_Copy_of_DesacopladoNLInstanceStruct *chartInstance;
  chartInstance = (SFc2_Copy_of_DesacopladoNLInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i13 = 0; c2_i13 < 4; c2_i13++) {
    c2_b_inData[c2_i13] = (*(real_T (*)[4])c2_inData)[c2_i13];
  }

  for (c2_i14 = 0; c2_i14 < 4; c2_i14++) {
    c2_u[c2_i14] = c2_b_inData[c2_i14];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 1, 4));
  sf_mex_assign(&c2_mxArrayOutData, c2_y);
  return c2_mxArrayOutData;
}

static void c2_emlrt_marshallIn(SFc2_Copy_of_DesacopladoNLInstanceStruct
  *chartInstance, const mxArray *c2_dh, const char_T *c2_identifier, real_T
  c2_y[4])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_dh), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_dh);
}

static void c2_b_emlrt_marshallIn(SFc2_Copy_of_DesacopladoNLInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[4])
{
  real_T c2_dv1[4];
  int32_T c2_i15;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv1, 1, 0, 0U, 1, 0U, 1, 4);
  for (c2_i15 = 0; c2_i15 < 4; c2_i15++) {
    c2_y[c2_i15] = c2_dv1[c2_i15];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_dh;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[4];
  int32_T c2_i16;
  SFc2_Copy_of_DesacopladoNLInstanceStruct *chartInstance;
  chartInstance = (SFc2_Copy_of_DesacopladoNLInstanceStruct *)chartInstanceVoid;
  c2_dh = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_dh), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_dh);
  for (c2_i16 = 0; c2_i16 < 4; c2_i16++) {
    (*(real_T (*)[4])c2_outData)[c2_i16] = c2_y[c2_i16];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  c2_slBus1 c2_u;
  const mxArray *c2_y = NULL;
  real_T c2_b_u;
  const mxArray *c2_b_y = NULL;
  real_T c2_c_u;
  const mxArray *c2_c_y = NULL;
  real_T c2_d_u;
  const mxArray *c2_d_y = NULL;
  real_T c2_e_u;
  const mxArray *c2_e_y = NULL;
  real_T c2_f_u;
  const mxArray *c2_f_y = NULL;
  real_T c2_g_u;
  const mxArray *c2_g_y = NULL;
  real_T c2_h_u;
  const mxArray *c2_h_y = NULL;
  real_T c2_i_u;
  const mxArray *c2_i_y = NULL;
  real_T c2_j_u;
  const mxArray *c2_j_y = NULL;
  real_T c2_k_u;
  const mxArray *c2_k_y = NULL;
  real_T c2_l_u;
  const mxArray *c2_l_y = NULL;
  real_T c2_m_u;
  const mxArray *c2_m_y = NULL;
  int32_T c2_i17;
  real_T c2_n_u[4];
  const mxArray *c2_n_y = NULL;
  int32_T c2_i18;
  real_T c2_o_u[4];
  const mxArray *c2_o_y = NULL;
  int32_T c2_i19;
  real_T c2_p_u[2];
  const mxArray *c2_p_y = NULL;
  int32_T c2_i20;
  real_T c2_q_u[2];
  const mxArray *c2_q_y = NULL;
  SFc2_Copy_of_DesacopladoNLInstanceStruct *chartInstance;
  chartInstance = (SFc2_Copy_of_DesacopladoNLInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(c2_slBus1 *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createstruct("structure", 2, 1, 1));
  c2_b_u = c2_u.A1;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_addfield(c2_y, c2_b_y, "A1", "A1", 0);
  c2_c_u = c2_u.A2;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_c_u, 0, 0U, 0U, 0U, 0));
  sf_mex_addfield(c2_y, c2_c_y, "A2", "A2", 0);
  c2_d_u = c2_u.A3;
  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", &c2_d_u, 0, 0U, 0U, 0U, 0));
  sf_mex_addfield(c2_y, c2_d_y, "A3", "A3", 0);
  c2_e_u = c2_u.A4;
  c2_e_y = NULL;
  sf_mex_assign(&c2_e_y, sf_mex_create("y", &c2_e_u, 0, 0U, 0U, 0U, 0));
  sf_mex_addfield(c2_y, c2_e_y, "A4", "A4", 0);
  c2_f_u = c2_u.a1;
  c2_f_y = NULL;
  sf_mex_assign(&c2_f_y, sf_mex_create("y", &c2_f_u, 0, 0U, 0U, 0U, 0));
  sf_mex_addfield(c2_y, c2_f_y, "a1", "a1", 0);
  c2_g_u = c2_u.a2;
  c2_g_y = NULL;
  sf_mex_assign(&c2_g_y, sf_mex_create("y", &c2_g_u, 0, 0U, 0U, 0U, 0));
  sf_mex_addfield(c2_y, c2_g_y, "a2", "a2", 0);
  c2_h_u = c2_u.a3;
  c2_h_y = NULL;
  sf_mex_assign(&c2_h_y, sf_mex_create("y", &c2_h_u, 0, 0U, 0U, 0U, 0));
  sf_mex_addfield(c2_y, c2_h_y, "a3", "a3", 0);
  c2_i_u = c2_u.a4;
  c2_i_y = NULL;
  sf_mex_assign(&c2_i_y, sf_mex_create("y", &c2_i_u, 0, 0U, 0U, 0U, 0));
  sf_mex_addfield(c2_y, c2_i_y, "a4", "a4", 0);
  c2_j_u = c2_u.kc;
  c2_j_y = NULL;
  sf_mex_assign(&c2_j_y, sf_mex_create("y", &c2_j_u, 0, 0U, 0U, 0U, 0));
  sf_mex_addfield(c2_y, c2_j_y, "kc", "kc", 0);
  c2_k_u = c2_u.k1;
  c2_k_y = NULL;
  sf_mex_assign(&c2_k_y, sf_mex_create("y", &c2_k_u, 0, 0U, 0U, 0U, 0));
  sf_mex_addfield(c2_y, c2_k_y, "k1", "k1", 0);
  c2_l_u = c2_u.k2;
  c2_l_y = NULL;
  sf_mex_assign(&c2_l_y, sf_mex_create("y", &c2_l_u, 0, 0U, 0U, 0U, 0));
  sf_mex_addfield(c2_y, c2_l_y, "k2", "k2", 0);
  c2_m_u = c2_u.g;
  c2_m_y = NULL;
  sf_mex_assign(&c2_m_y, sf_mex_create("y", &c2_m_u, 0, 0U, 0U, 0U, 0));
  sf_mex_addfield(c2_y, c2_m_y, "g", "g", 0);
  for (c2_i17 = 0; c2_i17 < 4; c2_i17++) {
    c2_n_u[c2_i17] = c2_u.hlin[c2_i17];
  }

  c2_n_y = NULL;
  sf_mex_assign(&c2_n_y, sf_mex_create("y", c2_n_u, 0, 0U, 1U, 0U, 2, 4, 1));
  sf_mex_addfield(c2_y, c2_n_y, "hlin", "hlin", 0);
  for (c2_i18 = 0; c2_i18 < 4; c2_i18++) {
    c2_o_u[c2_i18] = c2_u.h0[c2_i18];
  }

  c2_o_y = NULL;
  sf_mex_assign(&c2_o_y, sf_mex_create("y", c2_o_u, 0, 0U, 1U, 0U, 2, 4, 1));
  sf_mex_addfield(c2_y, c2_o_y, "h0", "h0", 0);
  for (c2_i19 = 0; c2_i19 < 2; c2_i19++) {
    c2_p_u[c2_i19] = c2_u.vlin[c2_i19];
  }

  c2_p_y = NULL;
  sf_mex_assign(&c2_p_y, sf_mex_create("y", c2_p_u, 0, 0U, 1U, 0U, 2, 2, 1));
  sf_mex_addfield(c2_y, c2_p_y, "vlin", "vlin", 0);
  for (c2_i20 = 0; c2_i20 < 2; c2_i20++) {
    c2_q_u[c2_i20] = c2_u.v0[c2_i20];
  }

  c2_q_y = NULL;
  sf_mex_assign(&c2_q_y, sf_mex_create("y", c2_q_u, 0, 0U, 1U, 0U, 2, 2, 1));
  sf_mex_addfield(c2_y, c2_q_y, "v0", "v0", 0);
  sf_mex_assign(&c2_mxArrayOutData, c2_y);
  return c2_mxArrayOutData;
}

static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i21;
  real_T c2_b_inData[2];
  int32_T c2_i22;
  real_T c2_u[2];
  const mxArray *c2_y = NULL;
  SFc2_Copy_of_DesacopladoNLInstanceStruct *chartInstance;
  chartInstance = (SFc2_Copy_of_DesacopladoNLInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i21 = 0; c2_i21 < 2; c2_i21++) {
    c2_b_inData[c2_i21] = (*(real_T (*)[2])c2_inData)[c2_i21];
  }

  for (c2_i22 = 0; c2_i22 < 2; c2_i22++) {
    c2_u[c2_i22] = c2_b_inData[c2_i22];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 1, 2));
  sf_mex_assign(&c2_mxArrayOutData, c2_y);
  return c2_mxArrayOutData;
}

static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_Copy_of_DesacopladoNLInstanceStruct *chartInstance;
  chartInstance = (SFc2_Copy_of_DesacopladoNLInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c2_mxArrayOutData, c2_y);
  return c2_mxArrayOutData;
}

static real_T c2_c_emlrt_marshallIn(SFc2_Copy_of_DesacopladoNLInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d0, 1, 0, 0U, 0, 0U, 0);
  c2_y = c2_d0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_nargout;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_Copy_of_DesacopladoNLInstanceStruct *chartInstance;
  chartInstance = (SFc2_Copy_of_DesacopladoNLInstanceStruct *)chartInstanceVoid;
  c2_nargout = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_nargout), &c2_thisId);
  sf_mex_destroy(&c2_nargout);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

const mxArray *sf_c2_Copy_of_DesacopladoNL_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo;
  c2_ResolvedFunctionInfo c2_info[7];
  c2_ResolvedFunctionInfo (*c2_b_info)[7];
  const mxArray *c2_m0 = NULL;
  int32_T c2_i23;
  c2_ResolvedFunctionInfo *c2_r0;
  c2_nameCaptureInfo = NULL;
  c2_nameCaptureInfo = NULL;
  c2_b_info = (c2_ResolvedFunctionInfo (*)[7])c2_info;
  (*c2_b_info)[0].context = "";
  (*c2_b_info)[0].name = "mrdivide";
  (*c2_b_info)[0].dominantType = "double";
  (*c2_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c2_b_info)[0].fileTimeLo = 3368733440U;
  (*c2_b_info)[0].fileTimeHi = 30130985U;
  (*c2_b_info)[0].mFileTimeLo = 529702400U;
  (*c2_b_info)[0].mFileTimeHi = 30114350U;
  (*c2_b_info)[1].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c2_b_info)[1].name = "rdivide";
  (*c2_b_info)[1].dominantType = "double";
  (*c2_b_info)[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c2_b_info)[1].fileTimeLo = 3099026944U;
  (*c2_b_info)[1].fileTimeHi = 30108061U;
  (*c2_b_info)[1].mFileTimeLo = 0U;
  (*c2_b_info)[1].mFileTimeHi = 0U;
  (*c2_b_info)[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c2_b_info)[2].name = "eml_div";
  (*c2_b_info)[2].dominantType = "double";
  (*c2_b_info)[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  (*c2_b_info)[2].fileTimeLo = 1639026944U;
  (*c2_b_info)[2].fileTimeHi = 30108061U;
  (*c2_b_info)[2].mFileTimeLo = 0U;
  (*c2_b_info)[2].mFileTimeHi = 0U;
  (*c2_b_info)[3].context = "";
  (*c2_b_info)[3].name = "mtimes";
  (*c2_b_info)[3].dominantType = "double";
  (*c2_b_info)[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c2_b_info)[3].fileTimeLo = 529702400U;
  (*c2_b_info)[3].fileTimeHi = 30114350U;
  (*c2_b_info)[3].mFileTimeLo = 0U;
  (*c2_b_info)[3].mFileTimeHi = 0U;
  (*c2_b_info)[4].context = "";
  (*c2_b_info)[4].name = "sqrt";
  (*c2_b_info)[4].dominantType = "double";
  (*c2_b_info)[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  (*c2_b_info)[4].fileTimeLo = 2179026944U;
  (*c2_b_info)[4].fileTimeHi = 30108061U;
  (*c2_b_info)[4].mFileTimeLo = 0U;
  (*c2_b_info)[4].mFileTimeHi = 0U;
  (*c2_b_info)[5].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  (*c2_b_info)[5].name = "eml_error";
  (*c2_b_info)[5].dominantType = "char";
  (*c2_b_info)[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  (*c2_b_info)[5].fileTimeLo = 1659026944U;
  (*c2_b_info)[5].fileTimeHi = 30108061U;
  (*c2_b_info)[5].mFileTimeLo = 0U;
  (*c2_b_info)[5].mFileTimeHi = 0U;
  (*c2_b_info)[6].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  (*c2_b_info)[6].name = "eml_scalar_sqrt";
  (*c2_b_info)[6].dominantType = "double";
  (*c2_b_info)[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m";
  (*c2_b_info)[6].fileTimeLo = 2039026944U;
  (*c2_b_info)[6].fileTimeHi = 30108061U;
  (*c2_b_info)[6].mFileTimeLo = 0U;
  (*c2_b_info)[6].mFileTimeHi = 0U;
  sf_mex_assign(&c2_m0, sf_mex_createstruct("nameCaptureInfo", 1, 7));
  for (c2_i23 = 0; c2_i23 < 7; c2_i23++) {
    c2_r0 = &c2_info[c2_i23];
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->context)), "context", "nameCaptureInfo",
                    c2_i23);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c2_r0->name)), "name", "nameCaptureInfo", c2_i23);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c2_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c2_i23);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->resolved)), "resolved", "nameCaptureInfo",
                    c2_i23);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c2_i23);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c2_i23);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c2_i23);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c2_i23);
  }

  sf_mex_assign(&c2_nameCaptureInfo, c2_m0);
  return c2_nameCaptureInfo;
}

static void c2_eml_error(SFc2_Copy_of_DesacopladoNLInstanceStruct *chartInstance)
{
  int32_T c2_i24;
  static char_T c2_varargin_1[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o',
    'o', 'l', 'b', 'o', 'x', ':', 's', 'q', 'r', 't', '_', 'd', 'o', 'm', 'a',
    'i', 'n', 'E', 'r', 'r', 'o', 'r' };

  char_T c2_u[30];
  const mxArray *c2_y = NULL;
  for (c2_i24 = 0; c2_i24 < 30; c2_i24++) {
    c2_u[c2_i24] = c2_varargin_1[c2_i24];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 10, 0U, 1U, 0U, 2, 1, 30));
  sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 1U, 14,
    c2_y));
}

static const mxArray *c2_e_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_Copy_of_DesacopladoNLInstanceStruct *chartInstance;
  chartInstance = (SFc2_Copy_of_DesacopladoNLInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(int32_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 6, 0U, 0U, 0U, 0));
  sf_mex_assign(&c2_mxArrayOutData, c2_y);
  return c2_mxArrayOutData;
}

static int32_T c2_d_emlrt_marshallIn(SFc2_Copy_of_DesacopladoNLInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  int32_T c2_y;
  int32_T c2_i25;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_i25, 1, 6, 0U, 0, 0U, 0);
  c2_y = c2_i25;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_sfEvent;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_y;
  SFc2_Copy_of_DesacopladoNLInstanceStruct *chartInstance;
  chartInstance = (SFc2_Copy_of_DesacopladoNLInstanceStruct *)chartInstanceVoid;
  c2_b_sfEvent = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_sfEvent),
    &c2_thisId);
  sf_mex_destroy(&c2_b_sfEvent);
  *(int32_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_ctes_bus_io(void *chartInstanceVoid, void *c2_pData)
{
  const mxArray *c2_mxVal = NULL;
  c2_slBus1 c2_tmp;
  int32_T c2_i26;
  int32_T c2_i27;
  int32_T c2_i28;
  int32_T c2_i29;
  SFc2_Copy_of_DesacopladoNLInstanceStruct *chartInstance;
  chartInstance = (SFc2_Copy_of_DesacopladoNLInstanceStruct *)chartInstanceVoid;
  c2_mxVal = NULL;
  c2_tmp.A1 = *(real_T *)((char_T *)c2_pData + 0);
  c2_tmp.A2 = *(real_T *)((char_T *)c2_pData + 8);
  c2_tmp.A3 = *(real_T *)((char_T *)c2_pData + 16);
  c2_tmp.A4 = *(real_T *)((char_T *)c2_pData + 24);
  c2_tmp.a1 = *(real_T *)((char_T *)c2_pData + 32);
  c2_tmp.a2 = *(real_T *)((char_T *)c2_pData + 40);
  c2_tmp.a3 = *(real_T *)((char_T *)c2_pData + 48);
  c2_tmp.a4 = *(real_T *)((char_T *)c2_pData + 56);
  c2_tmp.kc = *(real_T *)((char_T *)c2_pData + 64);
  c2_tmp.k1 = *(real_T *)((char_T *)c2_pData + 72);
  c2_tmp.k2 = *(real_T *)((char_T *)c2_pData + 80);
  c2_tmp.g = *(real_T *)((char_T *)c2_pData + 88);
  for (c2_i26 = 0; c2_i26 < 4; c2_i26++) {
    c2_tmp.hlin[c2_i26] = ((real_T *)((char_T *)c2_pData + 96))[c2_i26];
  }

  for (c2_i27 = 0; c2_i27 < 4; c2_i27++) {
    c2_tmp.h0[c2_i27] = ((real_T *)((char_T *)c2_pData + 128))[c2_i27];
  }

  for (c2_i28 = 0; c2_i28 < 2; c2_i28++) {
    c2_tmp.vlin[c2_i28] = ((real_T *)((char_T *)c2_pData + 160))[c2_i28];
  }

  for (c2_i29 = 0; c2_i29 < 2; c2_i29++) {
    c2_tmp.v0[c2_i29] = ((real_T *)((char_T *)c2_pData + 176))[c2_i29];
  }

  sf_mex_assign(&c2_mxVal, c2_b_sf_marshallOut(chartInstance, &c2_tmp));
  return c2_mxVal;
}

static uint8_T c2_e_emlrt_marshallIn(SFc2_Copy_of_DesacopladoNLInstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_Copy_of_DesacopladoNL, const
  char_T *c2_identifier)
{
  uint8_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_b_is_active_c2_Copy_of_DesacopladoNL), &c2_thisId);
  sf_mex_destroy(&c2_b_is_active_c2_Copy_of_DesacopladoNL);
  return c2_y;
}

static uint8_T c2_f_emlrt_marshallIn(SFc2_Copy_of_DesacopladoNLInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint8_T c2_y;
  uint8_T c2_u0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_u0, 1, 3, 0U, 0, 0U, 0);
  c2_y = c2_u0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void init_dsm_address_info(SFc2_Copy_of_DesacopladoNLInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c2_Copy_of_DesacopladoNL_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2272133413U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2563693438U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4219805463U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(499094272U);
}

mxArray *sf_c2_Copy_of_DesacopladoNL_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(2315601221U);
    pr[1] = (double)(3278232494U);
    pr[2] = (double)(1087406583U);
    pr[3] = (double)(438301U);
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

static const mxArray *sf_get_sim_state_info_c2_Copy_of_DesacopladoNL(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"dh\",},{M[8],M[0],T\"is_active_c2_Copy_of_DesacopladoNL\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_Copy_of_DesacopladoNL_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_Copy_of_DesacopladoNLInstanceStruct *chartInstance;
    chartInstance = (SFc2_Copy_of_DesacopladoNLInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_Copy_of_DesacopladoNLMachineNumber_,
           2,
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
          init_script_number_translation(_Copy_of_DesacopladoNLMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_Copy_of_DesacopladoNLMachineNumber_,chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds
            (_Copy_of_DesacopladoNLMachineNumber_,
             chartInstance->chartNumber,
             0,
             0,
             0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"v1");
          _SFD_SET_DATA_PROPS(1,2,0,1,"dh");
          _SFD_SET_DATA_PROPS(2,1,1,0,"v2");
          _SFD_SET_DATA_PROPS(3,1,1,0,"gama");
          _SFD_SET_DATA_PROPS(4,1,1,0,"ctes");
          _SFD_SET_DATA_PROPS(5,1,1,0,"h");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,611);
        _SFD_CV_INIT_EML_IF(0,0,80,90,-1,114);
        _SFD_CV_INIT_EML_IF(0,1,119,129,-1,153);
        _SFD_CV_INIT_EML_IF(0,2,158,168,-1,192);
        _SFD_CV_INIT_EML_IF(0,3,197,207,-1,231);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_d_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)
            c2_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_d_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(4,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_ctes_bus_io,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          real_T *c2_v1;
          real_T *c2_v2;
          void **c2_ctes;
          real_T (*c2_dh)[4];
          real_T (*c2_gama)[2];
          real_T (*c2_h)[4];
          c2_h = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 4);
          c2_ctes = (void **)ssGetInputPortSignal(chartInstance->S, 3);
          c2_gama = (real_T (*)[2])ssGetInputPortSignal(chartInstance->S, 2);
          c2_v2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c2_dh = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
          c2_v1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c2_v1);
          _SFD_SET_DATA_VALUE_PTR(1U, *c2_dh);
          _SFD_SET_DATA_VALUE_PTR(2U, c2_v2);
          _SFD_SET_DATA_VALUE_PTR(3U, *c2_gama);
          _SFD_SET_DATA_VALUE_PTR(4U, c2_ctes);
          _SFD_SET_DATA_VALUE_PTR(5U, *c2_h);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_Copy_of_DesacopladoNLMachineNumber_,chartInstance->chartNumber,
         chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c2_Copy_of_DesacopladoNL(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc2_Copy_of_DesacopladoNLInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c2_Copy_of_DesacopladoNL
    ((SFc2_Copy_of_DesacopladoNLInstanceStruct*) chartInstanceVar);
  initialize_c2_Copy_of_DesacopladoNL((SFc2_Copy_of_DesacopladoNLInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c2_Copy_of_DesacopladoNL(void *chartInstanceVar)
{
  enable_c2_Copy_of_DesacopladoNL((SFc2_Copy_of_DesacopladoNLInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c2_Copy_of_DesacopladoNL(void *chartInstanceVar)
{
  disable_c2_Copy_of_DesacopladoNL((SFc2_Copy_of_DesacopladoNLInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c2_Copy_of_DesacopladoNL(void *chartInstanceVar)
{
  sf_c2_Copy_of_DesacopladoNL((SFc2_Copy_of_DesacopladoNLInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c2_Copy_of_DesacopladoNL
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c2_Copy_of_DesacopladoNL
    ((SFc2_Copy_of_DesacopladoNLInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_Copy_of_DesacopladoNL();/* state var info */
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

extern void sf_internal_set_sim_state_c2_Copy_of_DesacopladoNL(SimStruct* S,
  const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_Copy_of_DesacopladoNL();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c2_Copy_of_DesacopladoNL
    ((SFc2_Copy_of_DesacopladoNLInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c2_Copy_of_DesacopladoNL(SimStruct*
  S)
{
  return sf_internal_get_sim_state_c2_Copy_of_DesacopladoNL(S);
}

static void sf_opaque_set_sim_state_c2_Copy_of_DesacopladoNL(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c2_Copy_of_DesacopladoNL(S, st);
}

static void sf_opaque_terminate_c2_Copy_of_DesacopladoNL(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_Copy_of_DesacopladoNLInstanceStruct*) chartInstanceVar)
      ->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c2_Copy_of_DesacopladoNL((SFc2_Copy_of_DesacopladoNLInstanceStruct*)
      chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc2_Copy_of_DesacopladoNL
    ((SFc2_Copy_of_DesacopladoNLInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_Copy_of_DesacopladoNL(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_Copy_of_DesacopladoNL
      ((SFc2_Copy_of_DesacopladoNLInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c2_Copy_of_DesacopladoNL(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,"Copy_of_DesacopladoNL",
      "Copy_of_DesacopladoNL",2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,"Copy_of_DesacopladoNL",
                "Copy_of_DesacopladoNL",2,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,"Copy_of_DesacopladoNL",
      "Copy_of_DesacopladoNL",2,"gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"Copy_of_DesacopladoNL",
        "Copy_of_DesacopladoNL",2,5);
      sf_mark_chart_reusable_outputs(S,"Copy_of_DesacopladoNL",
        "Copy_of_DesacopladoNL",2,1);
    }

    sf_set_rtw_dwork_info(S,"Copy_of_DesacopladoNL","Copy_of_DesacopladoNL",2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(788477820U));
  ssSetChecksum1(S,(2266229223U));
  ssSetChecksum2(S,(2209548473U));
  ssSetChecksum3(S,(2183734677U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c2_Copy_of_DesacopladoNL(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "Copy_of_DesacopladoNL", "Copy_of_DesacopladoNL",
      2);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_Copy_of_DesacopladoNL(SimStruct *S)
{
  SFc2_Copy_of_DesacopladoNLInstanceStruct *chartInstance;
  chartInstance = (SFc2_Copy_of_DesacopladoNLInstanceStruct *)malloc(sizeof
    (SFc2_Copy_of_DesacopladoNLInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc2_Copy_of_DesacopladoNLInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c2_Copy_of_DesacopladoNL;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c2_Copy_of_DesacopladoNL;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c2_Copy_of_DesacopladoNL;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c2_Copy_of_DesacopladoNL;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c2_Copy_of_DesacopladoNL;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c2_Copy_of_DesacopladoNL;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c2_Copy_of_DesacopladoNL;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c2_Copy_of_DesacopladoNL;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_Copy_of_DesacopladoNL;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_Copy_of_DesacopladoNL;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c2_Copy_of_DesacopladoNL;
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

void c2_Copy_of_DesacopladoNL_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_Copy_of_DesacopladoNL(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_Copy_of_DesacopladoNL(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_Copy_of_DesacopladoNL(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_Copy_of_DesacopladoNL_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
