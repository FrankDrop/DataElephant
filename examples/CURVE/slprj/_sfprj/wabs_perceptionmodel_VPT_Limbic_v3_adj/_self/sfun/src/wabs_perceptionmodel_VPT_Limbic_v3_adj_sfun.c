/* Include files */

#include "wabs_perceptionmodel_VPT_Limbic_v3_adj_sfun.h"
#include "wabs_perceptionmodel_VPT_Limbic_v3_adj_sfun_debug_macros.h"
#include "c1_wabs_perceptionmodel_VPT_Limbic_v3_adj.h"
#include "c2_wabs_perceptionmodel_VPT_Limbic_v3_adj.h"
#include "c3_wabs_perceptionmodel_VPT_Limbic_v3_adj.h"
#include "c4_wabs_perceptionmodel_VPT_Limbic_v3_adj.h"
#include "c5_wabs_perceptionmodel_VPT_Limbic_v3_adj.h"
#include "c6_wabs_perceptionmodel_VPT_Limbic_v3_adj.h"
#include "c7_wabs_perceptionmodel_VPT_Limbic_v3_adj.h"
#include "c8_wabs_perceptionmodel_VPT_Limbic_v3_adj.h"
#include "c9_wabs_perceptionmodel_VPT_Limbic_v3_adj.h"
#include "c10_wabs_perceptionmodel_VPT_Limbic_v3_adj.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _wabs_perceptionmodel_VPT_Limbic_v3_adjMachineNumber_;

/* Function Declarations */

/* Function Definitions */
void wabs_perceptionmodel_VPT_Limbic_v3_adj_initializer(void)
{
}

void wabs_perceptionmodel_VPT_Limbic_v3_adj_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_wabs_perceptionmodel_VPT_Limbic_v3_adj_method_dispatcher
  (SimStruct *simstructPtr, unsigned int chartFileNumber, const char* specsCksum,
   int_T method, void *data)
{
  if (chartFileNumber==1) {
    c1_wabs_perceptionmodel_VPT_Limbic_v3_adj_method_dispatcher(simstructPtr,
      method, data);
    return 1;
  }

  if (chartFileNumber==2) {
    c2_wabs_perceptionmodel_VPT_Limbic_v3_adj_method_dispatcher(simstructPtr,
      method, data);
    return 1;
  }

  if (chartFileNumber==3) {
    c3_wabs_perceptionmodel_VPT_Limbic_v3_adj_method_dispatcher(simstructPtr,
      method, data);
    return 1;
  }

  if (chartFileNumber==4) {
    c4_wabs_perceptionmodel_VPT_Limbic_v3_adj_method_dispatcher(simstructPtr,
      method, data);
    return 1;
  }

  if (chartFileNumber==5) {
    c5_wabs_perceptionmodel_VPT_Limbic_v3_adj_method_dispatcher(simstructPtr,
      method, data);
    return 1;
  }

  if (chartFileNumber==6) {
    c6_wabs_perceptionmodel_VPT_Limbic_v3_adj_method_dispatcher(simstructPtr,
      method, data);
    return 1;
  }

  if (chartFileNumber==7) {
    c7_wabs_perceptionmodel_VPT_Limbic_v3_adj_method_dispatcher(simstructPtr,
      method, data);
    return 1;
  }

  if (chartFileNumber==8) {
    c8_wabs_perceptionmodel_VPT_Limbic_v3_adj_method_dispatcher(simstructPtr,
      method, data);
    return 1;
  }

  if (chartFileNumber==9) {
    c9_wabs_perceptionmodel_VPT_Limbic_v3_adj_method_dispatcher(simstructPtr,
      method, data);
    return 1;
  }

  if (chartFileNumber==10) {
    c10_wabs_perceptionmodel_VPT_Limbic_v3_adj_method_dispatcher(simstructPtr,
      method, data);
    return 1;
  }

  return 0;
}

extern void sf_wabs_perceptionmodel_VPT_Limbic_v3_adj_uses_exported_functions
  (int nlhs, mxArray * plhs[], int nrhs, const mxArray * prhs[])
{
  plhs[0] = mxCreateLogicalScalar(0);
}

unsigned int sf_wabs_perceptionmodel_VPT_Limbic_v3_adj_process_check_sum_call
  ( int nlhs, mxArray * plhs[], int nrhs, const mxArray * prhs[] )
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
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1720694083U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2469085625U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3909685772U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(121233264U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3573953872U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(183357578U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2716720537U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1925293918U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void sf_c1_wabs_perceptionmodel_VPT_Limbic_v3_adj_get_check_sum
            (mxArray *plhs[]);
          sf_c1_wabs_perceptionmodel_VPT_Limbic_v3_adj_get_check_sum(plhs);
          break;
        }

       case 2:
        {
          extern void sf_c2_wabs_perceptionmodel_VPT_Limbic_v3_adj_get_check_sum
            (mxArray *plhs[]);
          sf_c2_wabs_perceptionmodel_VPT_Limbic_v3_adj_get_check_sum(plhs);
          break;
        }

       case 3:
        {
          extern void sf_c3_wabs_perceptionmodel_VPT_Limbic_v3_adj_get_check_sum
            (mxArray *plhs[]);
          sf_c3_wabs_perceptionmodel_VPT_Limbic_v3_adj_get_check_sum(plhs);
          break;
        }

       case 4:
        {
          extern void sf_c4_wabs_perceptionmodel_VPT_Limbic_v3_adj_get_check_sum
            (mxArray *plhs[]);
          sf_c4_wabs_perceptionmodel_VPT_Limbic_v3_adj_get_check_sum(plhs);
          break;
        }

       case 5:
        {
          extern void sf_c5_wabs_perceptionmodel_VPT_Limbic_v3_adj_get_check_sum
            (mxArray *plhs[]);
          sf_c5_wabs_perceptionmodel_VPT_Limbic_v3_adj_get_check_sum(plhs);
          break;
        }

       case 6:
        {
          extern void sf_c6_wabs_perceptionmodel_VPT_Limbic_v3_adj_get_check_sum
            (mxArray *plhs[]);
          sf_c6_wabs_perceptionmodel_VPT_Limbic_v3_adj_get_check_sum(plhs);
          break;
        }

       case 7:
        {
          extern void sf_c7_wabs_perceptionmodel_VPT_Limbic_v3_adj_get_check_sum
            (mxArray *plhs[]);
          sf_c7_wabs_perceptionmodel_VPT_Limbic_v3_adj_get_check_sum(plhs);
          break;
        }

       case 8:
        {
          extern void sf_c8_wabs_perceptionmodel_VPT_Limbic_v3_adj_get_check_sum
            (mxArray *plhs[]);
          sf_c8_wabs_perceptionmodel_VPT_Limbic_v3_adj_get_check_sum(plhs);
          break;
        }

       case 9:
        {
          extern void sf_c9_wabs_perceptionmodel_VPT_Limbic_v3_adj_get_check_sum
            (mxArray *plhs[]);
          sf_c9_wabs_perceptionmodel_VPT_Limbic_v3_adj_get_check_sum(plhs);
          break;
        }

       case 10:
        {
          extern void
            sf_c10_wabs_perceptionmodel_VPT_Limbic_v3_adj_get_check_sum(mxArray *
            plhs[]);
          sf_c10_wabs_perceptionmodel_VPT_Limbic_v3_adj_get_check_sum(plhs);
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
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3362309131U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3414483127U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2963174628U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3579721232U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_wabs_perceptionmodel_VPT_Limbic_v3_adj_autoinheritance_info( int
  nlhs, mxArray * plhs[], int nrhs, const mxArray * prhs[] )
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
     case 1:
      {
        if (strcmp(aiChksum, "V7xL8pgVjhN45GTt4t9OPE") == 0) {
          extern mxArray
            *sf_c1_wabs_perceptionmodel_VPT_Limbic_v3_adj_get_autoinheritance_info
            (void);
          plhs[0] =
            sf_c1_wabs_perceptionmodel_VPT_Limbic_v3_adj_get_autoinheritance_info
            ();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 2:
      {
        if (strcmp(aiChksum, "coeRrFdQXYgrQHoQRY0DXG") == 0) {
          extern mxArray
            *sf_c2_wabs_perceptionmodel_VPT_Limbic_v3_adj_get_autoinheritance_info
            (void);
          plhs[0] =
            sf_c2_wabs_perceptionmodel_VPT_Limbic_v3_adj_get_autoinheritance_info
            ();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 3:
      {
        if (strcmp(aiChksum, "5DrcLLpXyaKz5FzWUoLuIC") == 0) {
          extern mxArray
            *sf_c3_wabs_perceptionmodel_VPT_Limbic_v3_adj_get_autoinheritance_info
            (void);
          plhs[0] =
            sf_c3_wabs_perceptionmodel_VPT_Limbic_v3_adj_get_autoinheritance_info
            ();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 4:
      {
        if (strcmp(aiChksum, "NLRmqbrti0AXoMtSp9h7UC") == 0) {
          extern mxArray
            *sf_c4_wabs_perceptionmodel_VPT_Limbic_v3_adj_get_autoinheritance_info
            (void);
          plhs[0] =
            sf_c4_wabs_perceptionmodel_VPT_Limbic_v3_adj_get_autoinheritance_info
            ();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 5:
      {
        if (strcmp(aiChksum, "bzFSGeuC13IHN5AjR0tELC") == 0) {
          extern mxArray
            *sf_c5_wabs_perceptionmodel_VPT_Limbic_v3_adj_get_autoinheritance_info
            (void);
          plhs[0] =
            sf_c5_wabs_perceptionmodel_VPT_Limbic_v3_adj_get_autoinheritance_info
            ();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 6:
      {
        if (strcmp(aiChksum, "bzFSGeuC13IHN5AjR0tELC") == 0) {
          extern mxArray
            *sf_c6_wabs_perceptionmodel_VPT_Limbic_v3_adj_get_autoinheritance_info
            (void);
          plhs[0] =
            sf_c6_wabs_perceptionmodel_VPT_Limbic_v3_adj_get_autoinheritance_info
            ();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 7:
      {
        if (strcmp(aiChksum, "leyVQmadPOFqJtNlmZWDjB") == 0) {
          extern mxArray
            *sf_c7_wabs_perceptionmodel_VPT_Limbic_v3_adj_get_autoinheritance_info
            (void);
          plhs[0] =
            sf_c7_wabs_perceptionmodel_VPT_Limbic_v3_adj_get_autoinheritance_info
            ();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 8:
      {
        if (strcmp(aiChksum, "jy8PU8EPF4m5dxmtn9lgHD") == 0) {
          extern mxArray
            *sf_c8_wabs_perceptionmodel_VPT_Limbic_v3_adj_get_autoinheritance_info
            (void);
          plhs[0] =
            sf_c8_wabs_perceptionmodel_VPT_Limbic_v3_adj_get_autoinheritance_info
            ();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 9:
      {
        if (strcmp(aiChksum, "bzFSGeuC13IHN5AjR0tELC") == 0) {
          extern mxArray
            *sf_c9_wabs_perceptionmodel_VPT_Limbic_v3_adj_get_autoinheritance_info
            (void);
          plhs[0] =
            sf_c9_wabs_perceptionmodel_VPT_Limbic_v3_adj_get_autoinheritance_info
            ();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 10:
      {
        if (strcmp(aiChksum, "NLRmqbrti0AXoMtSp9h7UC") == 0) {
          extern mxArray
            *sf_c10_wabs_perceptionmodel_VPT_Limbic_v3_adj_get_autoinheritance_info
            (void);
          plhs[0] =
            sf_c10_wabs_perceptionmodel_VPT_Limbic_v3_adj_get_autoinheritance_info
            ();
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

unsigned int
  sf_wabs_perceptionmodel_VPT_Limbic_v3_adj_get_eml_resolved_functions_info( int
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
          *sf_c1_wabs_perceptionmodel_VPT_Limbic_v3_adj_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c1_wabs_perceptionmodel_VPT_Limbic_v3_adj_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 2:
      {
        extern const mxArray
          *sf_c2_wabs_perceptionmodel_VPT_Limbic_v3_adj_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c2_wabs_perceptionmodel_VPT_Limbic_v3_adj_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 3:
      {
        extern const mxArray
          *sf_c3_wabs_perceptionmodel_VPT_Limbic_v3_adj_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c3_wabs_perceptionmodel_VPT_Limbic_v3_adj_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 4:
      {
        extern const mxArray
          *sf_c4_wabs_perceptionmodel_VPT_Limbic_v3_adj_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c4_wabs_perceptionmodel_VPT_Limbic_v3_adj_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 5:
      {
        extern const mxArray
          *sf_c5_wabs_perceptionmodel_VPT_Limbic_v3_adj_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c5_wabs_perceptionmodel_VPT_Limbic_v3_adj_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 6:
      {
        extern const mxArray
          *sf_c6_wabs_perceptionmodel_VPT_Limbic_v3_adj_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c6_wabs_perceptionmodel_VPT_Limbic_v3_adj_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 7:
      {
        extern const mxArray
          *sf_c7_wabs_perceptionmodel_VPT_Limbic_v3_adj_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c7_wabs_perceptionmodel_VPT_Limbic_v3_adj_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 8:
      {
        extern const mxArray
          *sf_c8_wabs_perceptionmodel_VPT_Limbic_v3_adj_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c8_wabs_perceptionmodel_VPT_Limbic_v3_adj_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 9:
      {
        extern const mxArray
          *sf_c9_wabs_perceptionmodel_VPT_Limbic_v3_adj_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c9_wabs_perceptionmodel_VPT_Limbic_v3_adj_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 10:
      {
        extern const mxArray
          *sf_c10_wabs_perceptionmodel_VPT_Limbic_v3_adj_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c10_wabs_perceptionmodel_VPT_Limbic_v3_adj_get_eml_resolved_functions_info
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

unsigned int sf_wabs_perceptionmodel_VPT_Limbic_v3_adj_third_party_uses_info
  ( int nlhs, mxArray * plhs[], int nrhs, const mxArray * prhs[] )
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
     case 1:
      {
        if (strcmp(tpChksum, "TJJnUPtDgao8xsPgtGTkNF") == 0) {
          extern mxArray
            *sf_c1_wabs_perceptionmodel_VPT_Limbic_v3_adj_third_party_uses_info
            (void);
          plhs[0] =
            sf_c1_wabs_perceptionmodel_VPT_Limbic_v3_adj_third_party_uses_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "jRJBwO7xT0wSpVQigURh1F") == 0) {
          extern mxArray
            *sf_c2_wabs_perceptionmodel_VPT_Limbic_v3_adj_third_party_uses_info
            (void);
          plhs[0] =
            sf_c2_wabs_perceptionmodel_VPT_Limbic_v3_adj_third_party_uses_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "qSFjDj3D5NgXiED53E6oXC") == 0) {
          extern mxArray
            *sf_c3_wabs_perceptionmodel_VPT_Limbic_v3_adj_third_party_uses_info
            (void);
          plhs[0] =
            sf_c3_wabs_perceptionmodel_VPT_Limbic_v3_adj_third_party_uses_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "ZXTfsdHcXkwGFg0RK1euE") == 0) {
          extern mxArray
            *sf_c4_wabs_perceptionmodel_VPT_Limbic_v3_adj_third_party_uses_info
            (void);
          plhs[0] =
            sf_c4_wabs_perceptionmodel_VPT_Limbic_v3_adj_third_party_uses_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "e60ukkYwFOidnU2m7OqJVC") == 0) {
          extern mxArray
            *sf_c5_wabs_perceptionmodel_VPT_Limbic_v3_adj_third_party_uses_info
            (void);
          plhs[0] =
            sf_c5_wabs_perceptionmodel_VPT_Limbic_v3_adj_third_party_uses_info();
          break;
        }
      }

     case 6:
      {
        if (strcmp(tpChksum, "e60ukkYwFOidnU2m7OqJVC") == 0) {
          extern mxArray
            *sf_c6_wabs_perceptionmodel_VPT_Limbic_v3_adj_third_party_uses_info
            (void);
          plhs[0] =
            sf_c6_wabs_perceptionmodel_VPT_Limbic_v3_adj_third_party_uses_info();
          break;
        }
      }

     case 7:
      {
        if (strcmp(tpChksum, "MDvDYPHel0JR5LB3X1tAKF") == 0) {
          extern mxArray
            *sf_c7_wabs_perceptionmodel_VPT_Limbic_v3_adj_third_party_uses_info
            (void);
          plhs[0] =
            sf_c7_wabs_perceptionmodel_VPT_Limbic_v3_adj_third_party_uses_info();
          break;
        }
      }

     case 8:
      {
        if (strcmp(tpChksum, "68cQBFNF0jQtZ4Xnm2fx4") == 0) {
          extern mxArray
            *sf_c8_wabs_perceptionmodel_VPT_Limbic_v3_adj_third_party_uses_info
            (void);
          plhs[0] =
            sf_c8_wabs_perceptionmodel_VPT_Limbic_v3_adj_third_party_uses_info();
          break;
        }
      }

     case 9:
      {
        if (strcmp(tpChksum, "e60ukkYwFOidnU2m7OqJVC") == 0) {
          extern mxArray
            *sf_c9_wabs_perceptionmodel_VPT_Limbic_v3_adj_third_party_uses_info
            (void);
          plhs[0] =
            sf_c9_wabs_perceptionmodel_VPT_Limbic_v3_adj_third_party_uses_info();
          break;
        }
      }

     case 10:
      {
        if (strcmp(tpChksum, "ZXTfsdHcXkwGFg0RK1euE") == 0) {
          extern mxArray
            *sf_c10_wabs_perceptionmodel_VPT_Limbic_v3_adj_third_party_uses_info
            (void);
          plhs[0] =
            sf_c10_wabs_perceptionmodel_VPT_Limbic_v3_adj_third_party_uses_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_wabs_perceptionmodel_VPT_Limbic_v3_adj_jit_fallback_info( int
  nlhs, mxArray * plhs[], int nrhs, const mxArray * prhs[] )
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
     case 1:
      {
        if (strcmp(tpChksum, "TJJnUPtDgao8xsPgtGTkNF") == 0) {
          extern mxArray
            *sf_c1_wabs_perceptionmodel_VPT_Limbic_v3_adj_jit_fallback_info(void);
          plhs[0] =
            sf_c1_wabs_perceptionmodel_VPT_Limbic_v3_adj_jit_fallback_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "jRJBwO7xT0wSpVQigURh1F") == 0) {
          extern mxArray
            *sf_c2_wabs_perceptionmodel_VPT_Limbic_v3_adj_jit_fallback_info(void);
          plhs[0] =
            sf_c2_wabs_perceptionmodel_VPT_Limbic_v3_adj_jit_fallback_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "qSFjDj3D5NgXiED53E6oXC") == 0) {
          extern mxArray
            *sf_c3_wabs_perceptionmodel_VPT_Limbic_v3_adj_jit_fallback_info(void);
          plhs[0] =
            sf_c3_wabs_perceptionmodel_VPT_Limbic_v3_adj_jit_fallback_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "ZXTfsdHcXkwGFg0RK1euE") == 0) {
          extern mxArray
            *sf_c4_wabs_perceptionmodel_VPT_Limbic_v3_adj_jit_fallback_info(void);
          plhs[0] =
            sf_c4_wabs_perceptionmodel_VPT_Limbic_v3_adj_jit_fallback_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "e60ukkYwFOidnU2m7OqJVC") == 0) {
          extern mxArray
            *sf_c5_wabs_perceptionmodel_VPT_Limbic_v3_adj_jit_fallback_info(void);
          plhs[0] =
            sf_c5_wabs_perceptionmodel_VPT_Limbic_v3_adj_jit_fallback_info();
          break;
        }
      }

     case 6:
      {
        if (strcmp(tpChksum, "e60ukkYwFOidnU2m7OqJVC") == 0) {
          extern mxArray
            *sf_c6_wabs_perceptionmodel_VPT_Limbic_v3_adj_jit_fallback_info(void);
          plhs[0] =
            sf_c6_wabs_perceptionmodel_VPT_Limbic_v3_adj_jit_fallback_info();
          break;
        }
      }

     case 7:
      {
        if (strcmp(tpChksum, "MDvDYPHel0JR5LB3X1tAKF") == 0) {
          extern mxArray
            *sf_c7_wabs_perceptionmodel_VPT_Limbic_v3_adj_jit_fallback_info(void);
          plhs[0] =
            sf_c7_wabs_perceptionmodel_VPT_Limbic_v3_adj_jit_fallback_info();
          break;
        }
      }

     case 8:
      {
        if (strcmp(tpChksum, "68cQBFNF0jQtZ4Xnm2fx4") == 0) {
          extern mxArray
            *sf_c8_wabs_perceptionmodel_VPT_Limbic_v3_adj_jit_fallback_info(void);
          plhs[0] =
            sf_c8_wabs_perceptionmodel_VPT_Limbic_v3_adj_jit_fallback_info();
          break;
        }
      }

     case 9:
      {
        if (strcmp(tpChksum, "e60ukkYwFOidnU2m7OqJVC") == 0) {
          extern mxArray
            *sf_c9_wabs_perceptionmodel_VPT_Limbic_v3_adj_jit_fallback_info(void);
          plhs[0] =
            sf_c9_wabs_perceptionmodel_VPT_Limbic_v3_adj_jit_fallback_info();
          break;
        }
      }

     case 10:
      {
        if (strcmp(tpChksum, "ZXTfsdHcXkwGFg0RK1euE") == 0) {
          extern mxArray
            *sf_c10_wabs_perceptionmodel_VPT_Limbic_v3_adj_jit_fallback_info
            (void);
          plhs[0] =
            sf_c10_wabs_perceptionmodel_VPT_Limbic_v3_adj_jit_fallback_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_wabs_perceptionmodel_VPT_Limbic_v3_adj_updateBuildInfo_args_info
  ( int nlhs, mxArray * plhs[], int nrhs, const mxArray * prhs[] )
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
     case 1:
      {
        if (strcmp(tpChksum, "TJJnUPtDgao8xsPgtGTkNF") == 0) {
          extern mxArray
            *sf_c1_wabs_perceptionmodel_VPT_Limbic_v3_adj_updateBuildInfo_args_info
            (void);
          plhs[0] =
            sf_c1_wabs_perceptionmodel_VPT_Limbic_v3_adj_updateBuildInfo_args_info
            ();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "jRJBwO7xT0wSpVQigURh1F") == 0) {
          extern mxArray
            *sf_c2_wabs_perceptionmodel_VPT_Limbic_v3_adj_updateBuildInfo_args_info
            (void);
          plhs[0] =
            sf_c2_wabs_perceptionmodel_VPT_Limbic_v3_adj_updateBuildInfo_args_info
            ();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "qSFjDj3D5NgXiED53E6oXC") == 0) {
          extern mxArray
            *sf_c3_wabs_perceptionmodel_VPT_Limbic_v3_adj_updateBuildInfo_args_info
            (void);
          plhs[0] =
            sf_c3_wabs_perceptionmodel_VPT_Limbic_v3_adj_updateBuildInfo_args_info
            ();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "ZXTfsdHcXkwGFg0RK1euE") == 0) {
          extern mxArray
            *sf_c4_wabs_perceptionmodel_VPT_Limbic_v3_adj_updateBuildInfo_args_info
            (void);
          plhs[0] =
            sf_c4_wabs_perceptionmodel_VPT_Limbic_v3_adj_updateBuildInfo_args_info
            ();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "e60ukkYwFOidnU2m7OqJVC") == 0) {
          extern mxArray
            *sf_c5_wabs_perceptionmodel_VPT_Limbic_v3_adj_updateBuildInfo_args_info
            (void);
          plhs[0] =
            sf_c5_wabs_perceptionmodel_VPT_Limbic_v3_adj_updateBuildInfo_args_info
            ();
          break;
        }
      }

     case 6:
      {
        if (strcmp(tpChksum, "e60ukkYwFOidnU2m7OqJVC") == 0) {
          extern mxArray
            *sf_c6_wabs_perceptionmodel_VPT_Limbic_v3_adj_updateBuildInfo_args_info
            (void);
          plhs[0] =
            sf_c6_wabs_perceptionmodel_VPT_Limbic_v3_adj_updateBuildInfo_args_info
            ();
          break;
        }
      }

     case 7:
      {
        if (strcmp(tpChksum, "MDvDYPHel0JR5LB3X1tAKF") == 0) {
          extern mxArray
            *sf_c7_wabs_perceptionmodel_VPT_Limbic_v3_adj_updateBuildInfo_args_info
            (void);
          plhs[0] =
            sf_c7_wabs_perceptionmodel_VPT_Limbic_v3_adj_updateBuildInfo_args_info
            ();
          break;
        }
      }

     case 8:
      {
        if (strcmp(tpChksum, "68cQBFNF0jQtZ4Xnm2fx4") == 0) {
          extern mxArray
            *sf_c8_wabs_perceptionmodel_VPT_Limbic_v3_adj_updateBuildInfo_args_info
            (void);
          plhs[0] =
            sf_c8_wabs_perceptionmodel_VPT_Limbic_v3_adj_updateBuildInfo_args_info
            ();
          break;
        }
      }

     case 9:
      {
        if (strcmp(tpChksum, "e60ukkYwFOidnU2m7OqJVC") == 0) {
          extern mxArray
            *sf_c9_wabs_perceptionmodel_VPT_Limbic_v3_adj_updateBuildInfo_args_info
            (void);
          plhs[0] =
            sf_c9_wabs_perceptionmodel_VPT_Limbic_v3_adj_updateBuildInfo_args_info
            ();
          break;
        }
      }

     case 10:
      {
        if (strcmp(tpChksum, "ZXTfsdHcXkwGFg0RK1euE") == 0) {
          extern mxArray
            *sf_c10_wabs_perceptionmodel_VPT_Limbic_v3_adj_updateBuildInfo_args_info
            (void);
          plhs[0] =
            sf_c10_wabs_perceptionmodel_VPT_Limbic_v3_adj_updateBuildInfo_args_info
            ();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

void sf_wabs_perceptionmodel_VPT_Limbic_v3_adj_get_post_codegen_info( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{
  unsigned int chartFileNumber = (unsigned int) mxGetScalar(prhs[0]);
  char tpChksum[64];
  mxGetString(prhs[1], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  switch (chartFileNumber) {
   case 1:
    {
      if (strcmp(tpChksum, "TJJnUPtDgao8xsPgtGTkNF") == 0) {
        extern mxArray
          *sf_c1_wabs_perceptionmodel_VPT_Limbic_v3_adj_get_post_codegen_info
          (void);
        plhs[0] =
          sf_c1_wabs_perceptionmodel_VPT_Limbic_v3_adj_get_post_codegen_info();
        return;
      }
    }
    break;

   case 2:
    {
      if (strcmp(tpChksum, "jRJBwO7xT0wSpVQigURh1F") == 0) {
        extern mxArray
          *sf_c2_wabs_perceptionmodel_VPT_Limbic_v3_adj_get_post_codegen_info
          (void);
        plhs[0] =
          sf_c2_wabs_perceptionmodel_VPT_Limbic_v3_adj_get_post_codegen_info();
        return;
      }
    }
    break;

   case 3:
    {
      if (strcmp(tpChksum, "qSFjDj3D5NgXiED53E6oXC") == 0) {
        extern mxArray
          *sf_c3_wabs_perceptionmodel_VPT_Limbic_v3_adj_get_post_codegen_info
          (void);
        plhs[0] =
          sf_c3_wabs_perceptionmodel_VPT_Limbic_v3_adj_get_post_codegen_info();
        return;
      }
    }
    break;

   case 4:
    {
      if (strcmp(tpChksum, "ZXTfsdHcXkwGFg0RK1euE") == 0) {
        extern mxArray
          *sf_c4_wabs_perceptionmodel_VPT_Limbic_v3_adj_get_post_codegen_info
          (void);
        plhs[0] =
          sf_c4_wabs_perceptionmodel_VPT_Limbic_v3_adj_get_post_codegen_info();
        return;
      }
    }
    break;

   case 5:
    {
      if (strcmp(tpChksum, "e60ukkYwFOidnU2m7OqJVC") == 0) {
        extern mxArray
          *sf_c5_wabs_perceptionmodel_VPT_Limbic_v3_adj_get_post_codegen_info
          (void);
        plhs[0] =
          sf_c5_wabs_perceptionmodel_VPT_Limbic_v3_adj_get_post_codegen_info();
        return;
      }
    }
    break;

   case 6:
    {
      if (strcmp(tpChksum, "e60ukkYwFOidnU2m7OqJVC") == 0) {
        extern mxArray
          *sf_c6_wabs_perceptionmodel_VPT_Limbic_v3_adj_get_post_codegen_info
          (void);
        plhs[0] =
          sf_c6_wabs_perceptionmodel_VPT_Limbic_v3_adj_get_post_codegen_info();
        return;
      }
    }
    break;

   case 7:
    {
      if (strcmp(tpChksum, "MDvDYPHel0JR5LB3X1tAKF") == 0) {
        extern mxArray
          *sf_c7_wabs_perceptionmodel_VPT_Limbic_v3_adj_get_post_codegen_info
          (void);
        plhs[0] =
          sf_c7_wabs_perceptionmodel_VPT_Limbic_v3_adj_get_post_codegen_info();
        return;
      }
    }
    break;

   case 8:
    {
      if (strcmp(tpChksum, "68cQBFNF0jQtZ4Xnm2fx4") == 0) {
        extern mxArray
          *sf_c8_wabs_perceptionmodel_VPT_Limbic_v3_adj_get_post_codegen_info
          (void);
        plhs[0] =
          sf_c8_wabs_perceptionmodel_VPT_Limbic_v3_adj_get_post_codegen_info();
        return;
      }
    }
    break;

   case 9:
    {
      if (strcmp(tpChksum, "e60ukkYwFOidnU2m7OqJVC") == 0) {
        extern mxArray
          *sf_c9_wabs_perceptionmodel_VPT_Limbic_v3_adj_get_post_codegen_info
          (void);
        plhs[0] =
          sf_c9_wabs_perceptionmodel_VPT_Limbic_v3_adj_get_post_codegen_info();
        return;
      }
    }
    break;

   case 10:
    {
      if (strcmp(tpChksum, "ZXTfsdHcXkwGFg0RK1euE") == 0) {
        extern mxArray
          *sf_c10_wabs_perceptionmodel_VPT_Limbic_v3_adj_get_post_codegen_info
          (void);
        plhs[0] =
          sf_c10_wabs_perceptionmodel_VPT_Limbic_v3_adj_get_post_codegen_info();
        return;
      }
    }
    break;

   default:
    break;
  }

  plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
}

void wabs_perceptionmodel_VPT_Limbic_v3_adj_debug_initialize(struct
  SfDebugInstanceStruct* debugInstance)
{
  _wabs_perceptionmodel_VPT_Limbic_v3_adjMachineNumber_ =
    sf_debug_initialize_machine(debugInstance,
    "wabs_perceptionmodel_VPT_Limbic_v3_adj","sfun",0,10,0,0,0);
  sf_debug_set_machine_event_thresholds(debugInstance,
    _wabs_perceptionmodel_VPT_Limbic_v3_adjMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(debugInstance,
    _wabs_perceptionmodel_VPT_Limbic_v3_adjMachineNumber_,0);
}

void wabs_perceptionmodel_VPT_Limbic_v3_adj_register_exported_symbols(SimStruct*
  S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_wabs_perceptionmodel_VPT_Limbic_v3_adj_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info(
      "wabs_perceptionmodel_VPT_Limbic_v3_adj",
      "wabs_perceptionmodel_VPT_Limbic_v3_adj");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_wabs_perceptionmodel_VPT_Limbic_v3_adj_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
