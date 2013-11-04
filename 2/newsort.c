#include "mex.h"
#include <stdio.h>
#include <time.h>
#include "sort.h"
#include "gen.h"

void interface(double sorttime[],long int num[]){
	typedef void (*pfun)(int [],long int);
	double *time, out;
	mxArray *str, *new_number;
	
	pfun s1=insertionsort;
	pfun s2=quicksort;
	pfun s3=mergesort;
	pfun s4=shellsort;
	pfun s5=heapsort;
	pfun masssort [] = {s1, s2, s3, s4, s5};
	pfun g1=randmass;
	pfun g2=invert;
	pfun g3=somerand;
	pfun g4=invert;
	pfun massgen [] = {g1 ,g2, g3, g4};
	int nfun;
	int gfun;
	long int n = num[0];
	int *a;
	str = mxCreateString("Enter type of sort\n	insertionsort - 0\n	quicksort - 1\n	mergesort - 2\n	shellsort - 3\n	heapsort - 4\n");
	mexCallMATLAB(1,&new_number,1,&str, "input");
	nfun = mxGetScalar(new_number);

	str= mxCreateString("input massive generate number\n	full random - 0\n	invert - 1\n	random 10%% - 2\n	id - 3\n");
	mexCallMATLAB(1,&new_number,1,&str, "input");
	gfun = mxGetScalar(new_number);

	a = (int*) malloc(n*sizeof(int));
	(*(massgen[gfun]))(a, n);
	clock_t functime;
	functime = clock();
	(*(masssort[nfun]))(a, n);
	sorttime[0] = ((double)(clock() - functime))/(double)CLOCKS_PER_SEC;
	if (issort(a, n))
				mexPrintf("\nsorted for %.3f second\n\n", sorttime[0]);
	free(a);
}
/*void timestwo(double y[], double x[])
{
  y[0] = 2.0*x[0];
}
*/


void mexFunction( int nlhs, mxArray *plhs[],
                  int nrhs, const mxArray *prhs[] ){
	double *time, out;
	long int *num;
	
  size_t mrows,ncols;
    /* Check for proper number of arguments. */
  if(nrhs!=1) {
    mexErrMsgIdAndTxt( "MATLAB:timestwo:invalidNumInputs",
             "One input is required: array number");
    } else if(nlhs>1) {
      mexErrMsgIdAndTxt( "MATLAB:timestwo:maxlhs",
             "Too many output arguments.");
    }

  /* The input must be a scalar integer .*/
  mrows = mxGetM(prhs[0]);
  ncols = mxGetN(prhs[0]);
	//Bred!{
	mexPrintf("Test message: %i\n",mxIsInt64(prhs[0]));
	//}Bred!
  if( !mxIsDouble(prhs[0]) || mxIsComplex(prhs[0]) ||
      !(mrows==1 && ncols==1) ) {
    mexErrMsgIdAndTxt( "MATLAB:timestwo:inputNotInteger",
            "Input must be an integer");
  }

	/* Create matrix for the return argument. */
  plhs[0] = mxCreateDoubleMatrix((mwSize)mrows, (mwSize)ncols, mxREAL);
  
	/* Assign pointers to each input and output. */
  num = (long int *)mxGetPr(prhs[0]);
  time = mxGetPr(plhs[0]);
  
	interface(time,num);
}
