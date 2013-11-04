#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

void swap(int a[],int i,long int j){
	int temp = a[i];
	a[i]=a[j];
	a[j]=temp;
}

void printmass(int a[],long int n){
	long int i;
	for (i=0; i<n; i++)
		printf("%5d",a[i]);
	printf("\n");
}

int issort(int a[],long int n){
	long int i;
	for (i=1;i<n;i++)
		if (a[i]<a[i-1])
			return 0;
	return 1;
}

void insertionsort(int a[],long int n){
	long int i;
	long int j;
	int key;
	for (i=1;i<n;i++){
		key=a[i];
		j=i-1;
		while ((j>=0)&&(a[j]>key)){
			swap(a,j+1,j);
			j--;
		}
	}
}


void shellsort(int a[],long int n){
	int s[32];
	int nstep=0;
	long int k=2;
	s[0]=1;
	long int i;
	long int j;
	int step;
	int key;
	while ((k*2)<=n){
		nstep++;
		s[nstep]=k+1;
		k=k*2;
	}
	for (nstep; nstep >= 0; nstep--){
		step = s[nstep];
		for (i=0; i<step; i++){
			for (j=i+step;j<n;j+=step){
				key=a[j];
				k=j-step;
				while ((k>=0)&&(a[k]>key)){
					swap(a,k+step,k);
					k += -step;
				}
			}
		}
	}
}

void quicksort(int a[],long int n){
	if (n<=1)
		return;
	long int i, last;
	swap (a, 0, n/2);
	last=0;
	for (i=1;i<n;i++){
		if (a[i] < a[0])
			swap(a, ++last, i);
	}
	swap (a, 0, last);
	quicksort(a, last);
	quicksort(a+last+1, n-last-1);
}

void mergesort(int a[],long int n){  
	if (n<=1)
		return;
	long int l = n/2;
	long int r = n-l;
	mergesort(a, l);
	mergesort(a+l, r);
	long int left=0;
	long int right=l;
	long int i=0;
	int *buff = (int*) malloc(n*sizeof(int));    
	while (1){
		if (left<l)
			if (right<n)
				if (a[right] > a[left]){
					buff[i] = a[left];
					i++;
					left++;
					}
				else{
					buff[i] = a[right];
					i++;
					right++;		
				}
			else{
				for (left;left<l;left++){
					buff[i]=a[left];
					i++;
				}
				break;
			}
		else{
			for (right;right<n;right++){
				buff[i]=a[right];
				i++;
			}
			break;
		}
	}
	for(i=0;i<n;i++)
			a[i]=buff[i];
	free(buff);
}


void embedding(int a[],long int ind,long int n){
	long int t = n/2;
	if (ind <= t){
		long int ind_2 = ind*2;
		int key = a[ind-1];
		int lc = a[ind_2-1];
		if (ind_2 == n)
			if (key < lc)
				swap(a, ind-1, n-1);
			else{}
		else{
			int rc = a[ind_2];
			if (rc > lc)
				if (key < rc){
					swap(a, ind-1, ind_2);
					embedding(a, ind_2+1, n);
				}
				else{}
			else
				if (key < lc){
					swap(a, ind-1, ind_2-1);
					embedding(a, ind_2, n);
				}
		}
	}
}

void heapsort(int a[],long int n){
	long int i;
	for (i=n/2; i > 0; i--)
		embedding(a, i, n);
	long int k;
	for (k=n;k>1; k--){
		swap (a, 0, k-1);
		embedding(a, 1, k-1);
	}
}



















