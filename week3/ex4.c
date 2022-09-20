#include <stdio.h>
#include <stdlib.h>


void* aggregate(void* base, size_t size, int n, void* initial_value, 
    void* (*opr)(const void*, const void*));

void* addInt(const void* a, const void* b){
    int _a = *(int*) a;
    int _b = *(int*) b;
    int *output = (int*) malloc(sizeof(int));

    *output = (_a + _b);
    return (void*)output;   
}

void* addDouble(const void* a, const void* b){
    double _a = *(double*) a;
    double _b = *(double*) b;
    
    double *output = (double*) malloc(sizeof(double));
    *output = _a + _b;
    return (void*)output;
}

void* mulInt(const void* a, const void* b){
    int _a = *(int*) a;
    int _b = *(int*) b;
    int *output = (int*) malloc(sizeof(int));
    *output = _a * _b;
    return (void*)output;
}

void* mulDouble(const void* a, const void* b){
    double _a = *(double*) a;
    double _b = *(double*) b;
    double *output = (double*) malloc(sizeof(double));
    *output = _a * _b;
    return (void*)output;
}

void* meanInt(const void* base, const void* n){
    int * output = (int*)malloc(sizeof(int));
    *output = 0;
    for(int i = 0; i < *(int*)n; i++) {
        *output += *(int*)base;
        base+=sizeof(int);
    }
    *output /= *(int*)n;
    return (void*)output;
}

void* meanDouble(const void* base, const void* n){
    double *output = (double *)malloc(sizeof(double));
    *output = 0;
    for(int i = 0; i < *(int*)n; i++) {
        *output += *(double*)base;
        base+=sizeof(double);
    }
    *output /= *(int*)n;
    return (void*)output;   
}

void* aggregate(void* base, size_t size, int n, void* initial_value, void* (*opr)(const void*, const void*)){
    if (opr == meanDouble || opr == meanInt) {
        return (*opr)(base, (const void *)&n);
    }
    
    void* output = (*opr)(initial_value, base);
    for(int i = 1; i < n; i++) {
        base += size;
        output = (*opr)(output, base);
    }
 return output;
}


int main(){
    int ints[] = {1,2,3,4,5};
    int *initial_value_int = (int*)malloc(sizeof(int));
    *initial_value_int = 0;
    int *int_one = (int*)malloc(sizeof(int));
    *int_one = 1;
    int* outputult1a = aggregate(&ints, sizeof(int), 5, initial_value_int, addInt);
    int* outputult2a = aggregate(&ints, sizeof(int), 5, int_one, mulInt);
    int* outputult3a = aggregate(&ints, sizeof(int), 5, initial_value_int, meanInt);
    
    double doubls[] = {1.0,2.0,3.0,4.0,5.0};
    double *initial_value_double = (double*)malloc(sizeof(double));
    *initial_value_double = 0;
    double *double_one = (double*)malloc(sizeof(double));
    *double_one = 1.0;

    double* outputult4a = aggregate(&doubls, sizeof(double), 5, initial_value_double, addDouble);
    double* outputult5a = aggregate(&doubls, sizeof(double), 5, double_one, mulDouble);
    double* outputult6a = aggregate(&doubls, sizeof(double), 5, initial_value_double, meanDouble);
    
    printf("%d\n", *outputult1a);
    printf("%d\n", *outputult2a);
    printf("%d\n", *outputult3a);
    printf("%f\n", *outputult4a);
    printf("%f\n", *outputult5a);
    printf("%f\n", *outputult6a);
}
