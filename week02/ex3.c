#include<stdio.h>
int main(int argc, char* argv[])
{
  int n;
  sscanf(argv[1], "%d", &n);
  for(int i=0;i<n;i++)
  {
    int s = 2*(i+1)-1;
    int sp = 2*n-1-s;
    for(int j=0;j<sp/2;j++)
    {
      printf(" ");
    }
    for(int j=0;j<s;j++)
    {
      printf("*");
    }
    for(int j=0;j<sp/2;j++)
    {
      printf(" ");
    }
    printf("\n");
  }
  return 0;
}
