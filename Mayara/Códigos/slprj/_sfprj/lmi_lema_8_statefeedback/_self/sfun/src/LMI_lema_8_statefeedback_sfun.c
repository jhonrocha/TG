/* Include files */

#include "LMI_lema_8_statefeedback_sfun.h"
#include "c1_LMI_lema_8_statefeedback.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _LMI_lema_8_statefeedbackMachineNumber_;
real_T _sfTime_;

/* Function Declarations */

/* Function Definitions */
void LMI_lema_8_statefeedback_initializer(void)
{
}

void LMI_lema_8_statefeedback_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_LMI_lema_8_statefeedback_method_dispatcher(SimStruct
  *simstructPtr, unsigned int chartFileNumber, const char* specsCksum, int_T
  method, void *data)
{
  if (chartFileNumber==1) {
    c1_LMI_lema_8_statefeedback_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_LMI_lema_8_statefeedback_process_check_sum_call( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[20];
  if (nrhs<1 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the checksum */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"sf_get_check_sum"))
    return 0;
  plhs[0] = mxCreateDoubleMatrix( 1,4,mxREAL);
  if (nrhs>1 && mxIsChar(prhs[1])) {
    mxGetString(prhs[1], commandName,sizeof(commandName)/sizeof(char));
    commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
    if (!strcmp(commandName,"machine")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2509524218U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3396692467U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1839114318U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(456911511U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3899604931U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3130212374U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3319126071U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3857392569U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void sf_c1_LMI_lema_8_statefeedback_get_check_sum(mxArray *
            plhs[]);
          sf_c1_LMI_lema_8_statefeedback_get_check_sum(plhs);
          break;
        }

       default:
        ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0.0);
      }
    } else if (!strcmp(commandName,"target")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3176360410U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1862911626U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(659157607U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1884031890U);
    } else {
      return 0;
    }
  } else {
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3088636885U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1161305559U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3973696362U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(745798021U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_LMI_lema_8_statefeedback_autoinheritance_info( int nlhs, mxArray
  * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[32];
  if (nrhs<2 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the autoinheritance_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_autoinheritance_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        extern mxArray *sf_c1_LMI_lema_8_statefeedback_get_autoinheritance_info
          (void);
        plhs[0] = sf_c1_LMI_lema_8_statefeedback_get_autoinheritance_info();
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_LMI_lema_8_statefeedback_get_eml_resolved_functions_info( int
  nlhs, mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[64];
  if (nrhs<2 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the get_eml_resolved_functions_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_eml_resolved_functions_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        extern const mxArray
          *sf_c1_LMI_lema_8_statefeedback_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c1_LMI_lema_8_statefeedback_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

void LMI_lema_8_statefeedback_debug_initialize(void)
{
  _LMI_lema_8_statefeedbackMachineNumber_ = sf_debug_initialize_machine(
    "LMI_lema_8_statefeedback","sfun",0,1,0,0,0);
  sf_debug_set_machine_event_thresholds(_LMI_lema_8_statefeedbackMachineNumber_,
    0,0);
  sf_debug_set_machine_data_thresholds(_LMI_lema_8_statefeedbackMachineNumber_,0);
}

void LMI_lema_8_statefeedback_register_exported_symbols(SimStruct* S)
{
}
