#include "lodepng.h"
#include <iostream>
#include <vector>

struct Pixel {
    unsigned char r;
    unsigned char g;
    unsigned char b;
    unsigned char a;
};

class Image {
private:
    std::vector<unsigned char> data;
    std::size_t width;
    std::size_t height;
public:


};




void saveImage(const char* filename, const std::vector<unsigned char>& image, unsigned width, unsigned height) {
    // Encode the image and save it to a file
    unsigned error = lodepng::encode(filename, image, width, height);

    if (error) {
        // Handle the error (display, log, etc.)
        printf("PNG encoding error %u: %s\n", error, lodepng_error_text(error));
    } else {
        printf("Image saved as %s\n", filename);
    }
}

int main(int argc, char *argv[]) {
    char* img_path;
    if(argc > 1){
        img_path = argv[1];
    }
    std::string str(img_path);
    std::cout << "IMAGE PATH:" <<  str << std::endl;
      // Example pixel data in RGBA format
    std::vector<unsigned char> image;
    // Fill 'image' with your pixel data in RGBA format
    unsigned width = 800;
    unsigned height = 600;

    unsigned char blackRed = 0;
    unsigned char blackGreen = 0;
    unsigned char blackBlue = 0;
    unsigned char blackAlpha = 255;

    for (size_t i = 0; i < width * height; ++i) {
        image.push_back(blackRed);
        image.push_back(blackGreen);
        image.push_back(blackBlue);
        image.push_back(blackAlpha);
    }

    // Save the image to a file
    saveImage(img_path, image, width, height);

    return 0;
}