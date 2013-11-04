#include <stdlib.h>
#include "sort.h"
#include <time.h>

void randmass(int a[],long int n){
	srand(time(NULL));
	long int i;
	for (i=0;i<n;i++)
		a[i]=rand();
}

void invert(int a[],long int n){
	long int i;
	for (i=0;i<n;i++)
		a[i]=n-i-1;
}

void somerand(int a[],long int n){
	long int i;
	for(i=0;i<n;i++)
		a[i]=i;
	srand(time(NULL));
	for(i=0;i<n;i+=10)
		a[i]=rand();
}

void id(int a[],long int n){
	long int i;
	for(i=0;i<n;i++)
		a[i]=i;
}
