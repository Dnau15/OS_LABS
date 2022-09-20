#include <stdio.h>
#include <stdlib.h>


void* aggregate(void* base, size_t size, int n, void* initial_value, 
    void* (*opr)(const void*, const void*));

void* addInt(const void* a, const void* b){
    int fst = *(int*) a;
    int sec = *(int*) b;
    int *output = (int*) malloc(sizeof(int));

    *output = (fst + sec);
    return (void*)output;   
}

void* addDouble(const void* a, const void* b){
    double fst = *(double*) a;
    double sec = *(double*) b;
    
    double *output = (double*) malloc(sizeof(double));
    *output = fst + sec;
    return (void*)output;
}

void* mulInt(const void* a, const void* b){
    int fst = *(int*) a;
    int sec = *(int*) b;
    int *output = (int*) malloc(sizeof(int));
    *output = fst * sec;
    return (void*)output;
}

void* mulDouble(const void* a, const void* b){
    double fst = *(double*) a;
    double sec = *(double*) b;
    double *output = (double*) malloc(sizeof(double));
    *output = fst * sec;
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
    // outputs for int
    int* output1a = aggregate(&ints, sizeof(int), 5, initial_value_int, addInt);
    int* output2a = aggregate(&ints, sizeof(int), 5, int_one, mulInt);
    int* output3a = aggregate(&ints, sizeof(int), 5, initial_value_int, meanInt);
    
    double doubls[] = {1.0,2.0,3.0,4.0,5.0};
    double *initial_value_double = (double*)malloc(sizeof(double));
    *initial_value_double = 0;
    double *double_one = (double*)malloc(sizeof(double));
    *double_one = 1.0;

    //outputs for double
    double* output4a = aggregate(&doubls, sizeof(double), 5, initial_value_double, addDouble);
    double* output5a = aggregate(&doubls, sizeof(double), 5, double_one, mulDouble);
    double* output6a = aggregate(&doubls, sizeof(double), 5, initial_value_double, meanDouble);
    
    printf("%d\n", *output1a);
    printf("%d\n", *output2a);
    printf("%d\n", *output3a);
    printf("%f\n", *output4a);
    printf("%f\n", *output5a);
    printf("%f\n", *output6a);
}
