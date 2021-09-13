#include<stdio.h>
#include<stdbool.h>
#include<string.h>
int main(){
  char *c[256];
  while(true) {
    fgets(c, 256, stdin);

    if(!strcmp("exit\n",c))
      break;
    
    fork();
    system(c);
  }
  return 0;
}