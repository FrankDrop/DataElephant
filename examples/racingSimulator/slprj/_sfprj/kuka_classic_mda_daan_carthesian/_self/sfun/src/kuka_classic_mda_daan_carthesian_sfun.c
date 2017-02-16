/* Include files */

#include "kuka_classic_mda_daan_carthesian_sfun.h"
#include "kuka_classic_mda_daan_carthesian_sfun_debug_macros.h"
#include "c4_kuka_classic_mda_daan_carthesian.h"
#include "c6_kuka_classic_mda_daan_carthesian.h"
#include "c32_kuka_classic_mda_daan_carthesian.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _kuka_classic_mda_daan_carthesianMachineNumber_;

/* Function Declarations */

/* Function Definitions */
void kuka_classic_mda_daan_carthesian_initializer(void)
{
}

void kuka_classic_mda_daan_carthesian_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_kuka_classic_mda_daan_carthesian_method_dispatcher(SimStruct
  *simstructPtr, unsigned int chartFileNumber, const char* specsCksum, int_T
  method, void *data)
{
  if (chartFileNumber==4) {
    c4_kuka_classic_mda_daan_carthesian_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  if (chartFileNumber==6) {
    c6_kuka_classic_mda_daan_carthesian_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  if (chartFileNumber==32) {
    c32_kuka_classic_mda_daan_carthesian_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  return 0;
}

extern void sf_kuka_classic_mda_daan_carthesian_uses_exported_functions(int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[])
{
  plhs[0] = mxCreateLogicalScalar(0);
}

unsigned int sf_kuka_classic_mda_daan_carthesian_process_check_sum_call( int
  nlhs, mxArray * plhs[], int nrhs, const mxArray * prhs[] )
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
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(192835292U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3540925071U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2895708839U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1665087055U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(668437553U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3775012274U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3231879071U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2880479371U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 4:
        {
          extern void sf_c4_kuka_classic_mda_daan_carthesian_get_check_sum
            (mxArray *plhs[]);
          sf_c4_kuka_classic_mda_daan_carthesian_get_check_sum(plhs);
          break;
        }

       case 6:
        {
          extern void sf_c6_kuka_classic_mda_daan_carthesian_get_check_sum
            (mxArray *plhs[]);
          sf_c6_kuka_classic_mda_daan_carthesian_get_check_sum(plhs);
          break;
        }

       case 32:
        {
          extern void sf_c32_kuka_classic_mda_daan_carthesian_get_check_sum
            (mxArray *plhs[]);
          sf_c32_kuka_classic_mda_daan_carthesian_get_check_sum(plhs);
          break;
        }

       default:
        ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0.0);
      }
    } else if (!strcmp(commandName,"target")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2515920432U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3908508645U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2530489944U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2924353608U);
    } else {
      return 0;
    }
  } else {
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(232395398U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1971238432U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3080632120U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2888495960U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_kuka_classic_mda_daan_carthesian_autoinheritance_info( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[32];
  char aiChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the autoinheritance_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_autoinheritance_info"))
    return 0;
  mxGetString(prhs[2], aiChksum,sizeof(aiChksum)/sizeof(char));
  aiChksum[(sizeof(aiChksum)/sizeof(char)-1)] = '\0';

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 4:
      {
        if (strcmp(aiChksum, "bzFSGeuC13IHN5AjR0tELC") == 0) {
          extern mxArray
            *sf_c4_kuka_classic_mda_daan_carthesian_get_autoinheritance_info
            (void);
          plhs[0] =
            sf_c4_kuka_classic_mda_daan_carthesian_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 6:
      {
        if (strcmp(aiChksum, "hD7WC5y37IhGoNQBx0PwdE") == 0) {
          extern mxArray
            *sf_c6_kuka_classic_mda_daan_carthesian_get_autoinheritance_info
            (void);
          plhs[0] =
            sf_c6_kuka_classic_mda_daan_carthesian_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 32:
      {
        if (strcmp(aiChksum, "bzFSGeuC13IHN5AjR0tELC") == 0) {
          extern mxArray
            *sf_c32_kuka_classic_mda_daan_carthesian_get_autoinheritance_info
            (void);
          plhs[0] =
            sf_c32_kuka_classic_mda_daan_carthesian_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
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

unsigned int sf_kuka_classic_mda_daan_carthesian_get_eml_resolved_functions_info
  ( int nlhs, mxArray * plhs[], int nrhs, const mxArray * prhs[] )
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
     case 4:
      {
        extern const mxArray
          *sf_c4_kuka_classic_mda_daan_carthesian_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c4_kuka_classic_mda_daan_carthesian_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 6:
      {
        extern const mxArray
          *sf_c6_kuka_classic_mda_daan_carthesian_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c6_kuka_classic_mda_daan_carthesian_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 32:
      {
        extern const mxArray
          *sf_c32_kuka_classic_mda_daan_carthesian_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c32_kuka_classic_mda_daan_carthesian_get_eml_resolved_functions_info
          ();
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

unsigned int sf_kuka_classic_mda_daan_carthesian_third_party_uses_info( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the third_party_uses_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_third_party_uses_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 4:
      {
        if (strcmp(tpChksum, "e60ukkYwFOidnU2m7OqJVC") == 0) {
          extern mxArray
            *sf_c4_kuka_classic_mda_daan_carthesian_third_party_uses_info(void);
          plhs[0] = sf_c4_kuka_classic_mda_daan_carthesian_third_party_uses_info
            ();
          break;
        }
      }

     case 6:
      {
        if (strcmp(tpChksum, "QXTx1FnaIsumV3SC1SkLD") == 0) {
          extern mxArray
            *sf_c6_kuka_classic_mda_daan_carthesian_third_party_uses_info(void);
          plhs[0] = sf_c6_kuka_classic_mda_daan_carthesian_third_party_uses_info
            ();
          break;
        }
      }

     case 32:
      {
        if (strcmp(tpChksum, "e60ukkYwFOidnU2m7OqJVC") == 0) {
          extern mxArray
            *sf_c32_kuka_classic_mda_daan_carthesian_third_party_uses_info(void);
          plhs[0] =
            sf_c32_kuka_classic_mda_daan_carthesian_third_party_uses_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_kuka_classic_mda_daan_carthesian_jit_fallback_info( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the jit_fallback_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_jit_fallback_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 4:
      {
        if (strcmp(tpChksum, "e60ukkYwFOidnU2m7OqJVC") == 0) {
          extern mxArray
            *sf_c4_kuka_classic_mda_daan_carthesian_jit_fallback_info(void);
          plhs[0] = sf_c4_kuka_classic_mda_daan_carthesian_jit_fallback_info();
          break;
        }
      }

     case 6:
      {
        if (strcmp(tpChksum, "QXTx1FnaIsumV3SC1SkLD") == 0) {
          extern mxArray
            *sf_c6_kuka_classic_mda_daan_carthesian_jit_fallback_info(void);
          plhs[0] = sf_c6_kuka_classic_mda_daan_carthesian_jit_fallback_info();
          break;
        }
      }

     case 32:
      {
        if (strcmp(tpChksum, "e60ukkYwFOidnU2m7OqJVC") == 0) {
          extern mxArray
            *sf_c32_kuka_classic_mda_daan_carthesian_jit_fallback_info(void);
          plhs[0] = sf_c32_kuka_classic_mda_daan_carthesian_jit_fallback_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_kuka_classic_mda_daan_carthesian_updateBuildInfo_args_info( int
  nlhs, mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the updateBuildInfo_args_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_updateBuildInfo_args_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 4:
      {
        if (strcmp(tpChksum, "e60ukkYwFOidnU2m7OqJVC") == 0) {
          extern mxArray
            *sf_c4_kuka_classic_mda_daan_carthesian_updateBuildInfo_args_info
            (void);
          plhs[0] =
            sf_c4_kuka_classic_mda_daan_carthesian_updateBuildInfo_args_info();
          break;
        }
      }

     case 6:
      {
        if (strcmp(tpChksum, "QXTx1FnaIsumV3SC1SkLD") == 0) {
          extern mxArray
            *sf_c6_kuka_classic_mda_daan_carthesian_updateBuildInfo_args_info
            (void);
          plhs[0] =
            sf_c6_kuka_classic_mda_daan_carthesian_updateBuildInfo_args_info();
          break;
        }
      }

     case 32:
      {
        if (strcmp(tpChksum, "e60ukkYwFOidnU2m7OqJVC") == 0) {
          extern mxArray
            *sf_c32_kuka_classic_mda_daan_carthesian_updateBuildInfo_args_info
            (void);
          plhs[0] =
            sf_c32_kuka_classic_mda_daan_carthesian_updateBuildInfo_args_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

void sf_kuka_classic_mda_daan_carthesian_get_post_codegen_info( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{
  unsigned int chartFileNumber = (unsigned int) mxGetScalar(prhs[0]);
  char tpChksum[64];
  mxGetString(prhs[1], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  switch (chartFileNumber) {
   case 4:
    {
      if (strcmp(tpChksum, "e60ukkYwFOidnU2m7OqJVC") == 0) {
        extern mxArray
          *sf_c4_kuka_classic_mda_daan_carthesian_get_post_codegen_info(void);
        plhs[0] = sf_c4_kuka_classic_mda_daan_carthesian_get_post_codegen_info();
        return;
      }
    }
    break;

   case 6:
    {
      if (strcmp(tpChksum, "QXTx1FnaIsumV3SC1SkLD") == 0) {
        extern mxArray
          *sf_c6_kuka_classic_mda_daan_carthesian_get_post_codegen_info(void);
        plhs[0] = sf_c6_kuka_classic_mda_daan_carthesian_get_post_codegen_info();
        return;
      }
    }
    break;

   case 32:
    {
      if (strcmp(tpChksum, "e60ukkYwFOidnU2m7OqJVC") == 0) {
        extern mxArray
          *sf_c32_kuka_classic_mda_daan_carthesian_get_post_codegen_info(void);
        plhs[0] = sf_c32_kuka_classic_mda_daan_carthesian_get_post_codegen_info();
        return;
      }
    }
    break;

   default:
    break;
  }

  plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
}

void kuka_classic_mda_daan_carthesian_debug_initialize(struct
  SfDebugInstanceStruct* debugInstance)
{
  _kuka_classic_mda_daan_carthesianMachineNumber_ = sf_debug_initialize_machine
    (debugInstance,"kuka_classic_mda_daan_carthesian","sfun",0,3,0,0,0);
  sf_debug_set_machine_event_thresholds(debugInstance,
    _kuka_classic_mda_daan_carthesianMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(debugInstance,
    _kuka_classic_mda_daan_carthesianMachineNumber_,0);
}

void kuka_classic_mda_daan_carthesian_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_kuka_classic_mda_daan_carthesian_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info(
      "kuka_classic_mda_daan_carthesian", "kuka_classic_mda_daan_carthesian");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_kuka_classic_mda_daan_carthesian_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
