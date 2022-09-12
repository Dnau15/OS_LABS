#include <stdio.h>
#include <float.h>
#include <limits.h>
int main(){
   int int_var;
   unsigned short uns_short_var;
   signed long int sign_long_var;
   float float_var;
   double double_var;
   
   int_var = INT_MAX;
   uns_short_var = USHRT_MAX;
   sign_long_var = LONG_MAX;
   float_var = FLT_MAX;
   double_var = DBL_MAX;
   
   printf("int size: %ld %d\n", sizeof(int), INT_MAX);
   printf("unsigned short size: %ld %d\n", sizeof(unsigned short), USHRT_MAX);
   printf("signed long int: %ld %lld\n", sizeof(signed long), LONG_MAX);
   printf("float: %ld %f\n", sizeof(float), FLT_MAX);
   printf("double: %ld %lf\n", sizeof(double), DBL_MAX);
}
