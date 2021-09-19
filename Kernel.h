//
// Created by kevin on 19/09/21.
//

#ifndef IMAGE_KERNEL_PROCESSING_KERNEL_H
#define IMAGE_KERNEL_PROCESSING_KERNEL_H

typedef struct {
    int size;
    float weight;
    float *coefficients;
} Kernel;

#define unnormalized 1

#define Kernel_getSize(krn) ((krn)->size)
#define Kernel_getWeight(krn) ((krn)->weight)
#define Kernel_getCoefficients(krn) ((krn)->coefficients)

#define Kernel_setSize(krn, val) (Kernel_getSize(krn) = (val))
#define Kernel_setWeight(krn, val) (Kernel_getWeight(krn) = (val))
#define Kernel_setCoefficients(krn, val) (Kernel_getCoefficients(krn) = (val))

Kernel *Kernel_new(int size, float weight, float *coefficients);

Kernel *Kernel_newEmpty(int size, float weight);

float Kernel_getCoefficient(Kernel *krn, int x, int y);

void Kernel_setCoefficient(Kernel *krn, int x, int y, float coefficient);

void Kernel_delete(Kernel *krn);

Kernel *Kernel_boxBlur(int size);

Kernel *Kernel_identity(int size);

Kernel *Kernel_gaussianBlur(int size);

#endif //IMAGE_KERNEL_PROCESSING_KERNEL_H
