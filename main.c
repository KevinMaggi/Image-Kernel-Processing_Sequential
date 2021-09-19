#include <stdio.h>
#include "Image.h"
#include "Utils.h"
#include "Kernel.h"

int main() {
    Image *img;

    printf("Loading image\n");
    img = loadJPEG("/home/kevin/CLionProjects/Image_Kernel_Processing/Image/Input/example.jpg");
    printf("Saving image\n");
    if (img != NULL) {
        savePNG("/home/kevin/CLionProjects/Image_Kernel_Processing/Image/Output/example.png", img);
    }
    printf("Finish\n");

    return 0;
}
