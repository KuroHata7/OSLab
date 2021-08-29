#include<stdio.h>
#include<limits.h>
#include<float.h>
int main()
{
  int _int = INT_MAX;
  float _float = FLT_MAX;
  double _double = DBL_MAX;
  printf("Integer = %d\n", _int);
  printf("Float = %f\n", _float);
  printf("Double = %lf\n", _double);

  printf("Sizeof integer = %d\n", sizeof _int);
  printf("Sizeof float = %d\n", sizeof _float);
  printf("Sizeof double = %d\n", sizeof _double);
  return 0;
}
