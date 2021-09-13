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
/*
Hello from parent [3578 - 4]
Hello from child [0 - 4]
Hello from parent [3580 - 4]
Hello from child [0 - 4]
Hello from parent [3582 - 4]
Hello from child [0 - 4]
Hello from parent [3584 - 4]
Hello from child [0 - 4]
Hello from parent [3586 - 4]
Hello from child [0 - 4]
Hello from parent [3588 - 4]
Hello from child [0 - 4]
Hello from parent [3590 - 4]
Hello from child [0 - 4]
Hello from parent [3592 - 4]
Hello from child [0 - 4]
Hello from parent [3594 - 4]
Hello from child [0 - 4]
Hello from parent [3596 - 4]
Hello from child [0 - 4]
childs show 0 and parents show their process id
*/
