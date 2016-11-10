#ifndef __c2_Copy_of_DescentralizadoNL_h__
#define __c2_Copy_of_DescentralizadoNL_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"

/* Type Definitions */
typedef struct {
  const char * context;
  const char * name;
  const char * dominantType;
  const char * resolved;
  uint32_T fileTimeLo;
  uint32_T fileTimeHi;
  uint32_T mFileTimeLo;
  uint32_T mFileTimeHi;
} c2_ResolvedFunctionInfo;

#ifndef struct_slBus1_tag
#define struct_slBus1_tag

typedef struct slBus1_tag
{
  real_T A1;
  real_T A2;
  real_T A3;
  real_T A4;
  real_T a1;
  real_T a2;
  real_T a3;
  real_T a4;
  real_T kc;
  real_T k1;
  real_T k2;
  real_T g;
  real_T hlin[4];
  real_T h0[4];
  real_T vlin[2];
  real_T v0[2];
} c2_slBus1;

#else

typedef struct slBus1_tag c2_slBus1;

#endif

typedef struct {
  SimStruct *S;
  int32_T c2_sfEvent;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  boolean_T c2_doneDoubleBufferReInit;
  boolean_T c2_isStable;
  uint8_T c2_is_active_c2_Copy_of_DescentralizadoNL;
  ChartInfoStruct chartInfo;
} SFc2_Copy_of_DescentralizadoNLInstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c2_Copy_of_DescentralizadoNL_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c2_Copy_of_DescentralizadoNL_get_check_sum(mxArray *plhs[]);
extern void c2_Copy_of_DescentralizadoNL_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
