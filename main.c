#include <stdio.h>
#include "Image.h"
#include "Utils.h"
#include "Kernel.h"
#include "Processing.h"

int main() {
    Image *img;
    Image *res;
    Kernel *krn = Kernel_boxBlur(15);

    printf("Loading image\n");
    img = loadJPEG("/home/kevin/CLionProjects/Image_Kernel_Processing/Image/Input/example.jpg");
/*    img = Image_new_empty(8, 8, 3);
    for (int c = 0; c < 3; c++) {
        for (int x = 0; x < 8; x++) {
            for (int y = 0; y < 8; y++) {
                img->data[x * 8 * 3 + y * 3 + c] = 10 * (c + 1) * x;
            }
        }
    }
    savePNG("/home/kevin/CLionProjects/Image_Kernel_Processing/Image/Input/example.png", img);
    for (int c = 0; c < 3; c++) {
        for (int x = 0; x < 8; x++) {
            for (int y = 0; y < 8; y++) {
                printf("%d\t", img->data[x * 8 * 3 + y * 3 + c]);
            }
            printf("\n");
        }
        printf("\n\n");
    }*/

    printf("Processing image\n");
    res = process(img, krn);
    printf("Saving image\n");
    if (res != NULL) {
        savePNG("/home/kevin/CLionProjects/Image_Kernel_Processing/Image/Output/example.png", res);
    }

    /*for (int c = 0; c < 3; c++) {
        for (int x = 0; x < 8; x++) {
            for (int y = 0; y < 8; y++) {
                printf("%d\t", res->data[x * 8 * 3 + y * 3 + c]);
            }
            printf("\n");
        }
        printf("\n\n");
    }*/

    printf("Finish\n");

    return 0;
}
