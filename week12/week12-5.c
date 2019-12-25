#include "my.h"
#define BUF_4K 4*1024
#define BUF_8K 8*1024
#define BUF_12K 12*1024
int main()
{
  char a[BUF_4K];
  char b[BUF_8K];
  char c[BUF_12K];

  memset(a,'A',sizeof(a));
  memset(b,'A',sizeof(a));
  memset(c,'

