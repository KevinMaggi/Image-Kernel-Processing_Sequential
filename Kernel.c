//
// Created by kevin on 19/09/21.
//

#include <malloc.h>
#include "Kernel.h"

Kernel* Kernel_new(int size, int weight, float *coefficients) {
    Kernel* krn = (Kernel*) malloc(sizeof(Kernel));

    Kernel_setSize(krn, size);
    Kernel_setWeight(krn, weight);
    Kernel_setCoefficients(krn, coefficients);

    return krn;
}

Kernel* Kernel_newEmpty(int size, int weight) {
    float* coefficients = (float*) malloc(sizeof(float)*size*size);
    return Kernel_new(size, weight, coefficients);
}

float Kernel_getCoefficient(Kernel *krn, int x, int y) {
    float* coefficients = Kernel_getCoefficients(krn);
    int size = Kernel_getSize(krn);
    return coefficients[y*size+x];
}

void Kernel_setCoefficient(Kernel *krn, int x, int y, float coefficient) {
    float* coefficients = Kernel_getCoefficients(krn);
    int size = Kernel_getSize(krn);

    coefficients[y*size+x] = coefficient;
}

void Kernel_delete(Kernel *krn) {
    if (krn != NULL) {
        if (Kernel_getCoefficients(krn) != NULL) {
            free(Kernel_getCoefficients(krn));
        }
        free(krn);
    }
}