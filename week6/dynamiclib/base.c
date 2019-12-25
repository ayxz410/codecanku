#include<time.h>
#include<stdio.h>
#include<stdlib.h>
void initarray(int *a,int n)
{
  srand((int)time(0));
  for(int i=0;i<n;i++)
  {
    a[i] =i + (int)(1000.0 * rand()/(RAND_MAX +1.0));
  }

};
void showarray(int *p,int n)
{
  for(int i=0;i<n;i++)
  {
    printf("%4d  :  %4d\n",i,a[i]);
  }
}
