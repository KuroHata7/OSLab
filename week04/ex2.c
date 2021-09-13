#include<stdio.h>
int main(){
  for(int i=0;i<5;i++){
    fork();
    sleep(5);
  }
  return 0;
}
/*
 konsole─┬─bash─┬─ex2─┬─ex2─┬─ex2───ex2
        │          │         │      │     │     └─ex2
        │          │         │      │     ├─ex2───ex2
        │          │         │      │     └─ex2
        │          │         │      └─pstree
        │          │         └─6*[{konsole}]
*/
