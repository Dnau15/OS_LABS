#include <stdio.h>
#include <float.h>
#include <limits.h>
int main(){
   int int_var;
   unsigned short uns_short_var;
   signed long sign_long_var;
   float float_var;
   double double_var;
   int_var = INT_MAX;
   uns_short_var = USHRT_MAX;
   sign_long_var = LONG_MAX;
   float_var = FLT_MAX;
   double_var = DBL_MAX;
   printf("%d %d\n", sizeof(int), INT_MAX);
   printf("%d %d\n", sizeof(unsigned short), USHRT_MAX);
   printf("%d %g\n", sizeof(signed long), LONG_MAX);
   printf("%d %g\n", sizeof(float), FLT_MAX);
   printf("%d %g\n", sizeof(double), DBL_MAX);
}
