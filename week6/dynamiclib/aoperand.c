int main(int *a, int n)
{
  int max = a[0];
  int i;

  for(i=1;i<n;i++)
  {
    if(a[i]>max)
    {
      max=a[i];
    }
  }

  return max;
} 

int sum(int *a, int n)
{
  int sum=0;
  int i;
  for(i=1;i<n;i++)
  {
    sum+=a[i];
  }

  return max;
} 
