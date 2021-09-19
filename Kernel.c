//
// Created by kevin on 19/09/21.
//

#include <malloc.h>
#include "Kernel.h"

Kernel *Kernel_new(int size, float weight, float *coefficients) {
    Kernel *krn = (Kernel *) malloc(sizeof(Kernel));

    Kernel_setSize(krn, size);
    Kernel_setWeight(krn, weight);
    Kernel_setCoefficients(krn, coefficients);

    return krn;
}

Kernel *Kernel_newEmpty(int size, float weight) {
    float *coefficients = (float *) malloc(sizeof(float) * size * size);
    return Kernel_new(size, weight, coefficients);
}

float Kernel_getCoefficient(Kernel *krn, int x, int y) {
    float *coefficients = Kernel_getCoefficients(krn);
    int size = Kernel_getSize(krn);
    return coefficients[y * size + x];
}

void Kernel_setCoefficient(Kernel *krn, int x, int y, float coefficient) {
    float *coefficients = Kernel_getCoefficients(krn);
    int size = Kernel_getSize(krn);

    coefficients[y * size + x] = coefficient;
}

void Kernel_delete(Kernel *krn) {
    if (krn != NULL) {
        if (Kernel_getCoefficients(krn) != NULL) {
            free(Kernel_getCoefficients(krn));
        }
        free(krn);
    }
}

Kernel *Kernel_boxBlur(int size) {
    Kernel *krn = Kernel_newEmpty(size, (float) 1 / (float) (size * size));

    for (int i = 0; i < size * size; i++) {
        Kernel_getCoefficients(krn)[i] = 1;
    }

    return krn;
}

Kernel *Kernel_identity(int size) {
    Kernel *krn = Kernel_newEmpty(size, unnormalized);

    Kernel_getCoefficients(krn)[(size * size - 1) / 2] = 1;

    return krn;
}

Kernel *Kernel_gaussianBlur(int size) {
    int coef, sum = 0;
    int *coefficients = (int *) malloc(sizeof(int) * size);
    for (int j = 0; j < size; j++) {
        if (j == 0)
            coef = 1;
        else
            coef = coef * (size - j) / j;
        coefficients[j] = coef;
        sum += coef;
    }

    Kernel *krn = Kernel_newEmpty(size, (float) 1 / (float) (sum * sum));

    for (int i = 0; i < size * size; i++) {
        int col = i % size;
        int row = i / size;
        Kernel_getCoefficients(krn)[i] = (float) (coefficients[row] * coefficients[col]);
    }

    return krn;
}