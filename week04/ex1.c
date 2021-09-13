#include<stdio.h>
#include<sys/types.h>
int main(){
  int n = 4;
  int ret = fork();
  if(ret == 0)
    printf("Hello from child [%d - %d]\n", ret, n);
  else 
    printf("Hello from parent [%d - %d]\n", ret, n);
  return 0;
}
