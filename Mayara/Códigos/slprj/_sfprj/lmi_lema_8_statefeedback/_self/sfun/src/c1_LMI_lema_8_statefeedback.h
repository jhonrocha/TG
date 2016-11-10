#ifndef __c1_LMI_lema_8_statefeedback_h__
#define __c1_LMI_lema_8_statefeedback_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"

/* Type Definitions */
#ifndef struct_sbeJM90BjrqCzgdyR581lvE
#define struct_sbeJM90BjrqCzgdyR581lvE

typedef struct sbeJM90BjrqCzgdyR581lvE
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
} c1_sbeJM90BjrqCzgdyR581lvE;

#else

typedef struct sbeJM90BjrqCzgdyR581lvE c1_sbeJM90BjrqCzgdyR581lvE;

#endif

typedef struct {
  const char * context;
  const char * name;
  const char * dominantType;
  const char * resolved;
  uint32_T fileTimeLo;
  uint32_T fileTimeHi;
  uint32_T mFileTimeLo;
  uint32_T mFileTimeHi;
} c1_ResolvedFunctionInfo;

typedef struct {
  SimStruct *S;
  int32_T c1_sfEvent;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  boolean_T c1_doneDoubleBufferReInit;
  boolean_T c1_isStable;
  uint8_T c1_is_active_c1_LMI_lema_8_statefeedback;
  ChartInfoStruct chartInfo;
} SFc1_LMI_lema_8_statefeedbackInstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c1_LMI_lema_8_statefeedback_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c1_LMI_lema_8_statefeedback_get_check_sum(mxArray *plhs[]);
extern void c1_LMI_lema_8_statefeedback_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
