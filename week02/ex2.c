#include<stdio.h>
int main()
{
  char _string[256];
  fgets(_string, 256, stdin);
  
  char reversed_string[256];

  int n = strlen(_string)-1;

  for(int i=0;i<n;i++)
  {
    reversed_string[i] = _string[n-i-1];  
  }

  printf("Your sentence in reverse:\n");

  for(int i=0;i<n;i++)
  {
    printf("%c", reversed_string[i]);
  }
  printf("\n");
  return 0;
}
