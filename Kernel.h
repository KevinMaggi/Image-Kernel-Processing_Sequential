//
// Created by kevin on 19/09/21.
//

#ifndef IMAGE_KERNEL_PROCESSING_KERNEL_H
#define IMAGE_KERNEL_PROCESSING_KERNEL_H

typedef struct {
    int size;
    int weight;
    float *coefficients;
} Kernel;

#define Kernel_getSize(krn) ((krn)->size)
#define Kernel_getWeight(krn) ((krn)->weight)
#define Kernel_getCoefficients(krn) ((krn)->coefficients)

#define Kernel_setSize(krn, val) (Kernel_getSize(krn) = (val))
#define Kernel_setWeight(krn, val) (Kernel_getWeight(krn) = (val))
#define Kernel_setCoefficients(krn, val) (Kernel_getCoefficients(krn) = (val))

Kernel* Kernel_new(int size, int weight, float *coefficients);
Kernel* Kernel_newEmpty(int size, int weight);
float Kernel_getCoefficient(Kernel *krn, int x, int y);
void Kernel_setCoefficient(Kernel *krn, int x, int y, float coefficient);
void Kernel_delete(Kernel *krn);

#endif //IMAGE_KERNEL_PROCESSING_KERNEL_H
