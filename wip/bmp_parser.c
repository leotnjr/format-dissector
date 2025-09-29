#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>


// Contains general file information.
struct header // 14 bytes.
{
    unsigned char signature[2]; // 2 bytes
    uint32_t fileSize;          // 4 bytes
    uint32_t reservedBytes;     // 4 bytes
    uint32_t arrayAddress;      // 4 bytes
};

// Contains specific file information.
struct infoHeader  // 40 bytes
{
    uint32_t headerSize;         // 4 bytes
    int32_t imgWidth;           // 4 bytes
    int32_t imgHeight;          // 4 bytes
    uint16_t colorPlanes;       // 2 bytes
    uint16_t bitPerPixel;       // 2 bytes
    uint32_t compression;       // 4 bytes
    uint32_t imgSize;           // 4 bytes
    int32_t horizontalRes;      // 4 bytes
    int32_t verticalRes;        // 4 bytes
    uint32_t colorsInTable;     // 4 bytes
    uint32_t importantColors;   // 4 bytes
};



FILE *img;

int main()
{   
    struct bmp *image;

    img = fopen("images/2x2.bmp", "rb");
    if (!img)
    {
        perror("Error opening file.");
        return 1;
    }

    unsigned char buffer[500];
    size_t fileSize = fread(buffer, 2, 2, img);

    printf("File was opened!\nFile size: %zu\n\n", fileSize);
}