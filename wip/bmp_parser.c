#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

struct bmp
{
    // Contains general file information.
    struct header // 14 bytes.
    {
        unsigned char signature[2]; // 2 bytes
        uint32_t file_size;         // 4 bytes
        uint32_t reserved_bytes;    // 4 bytes
        uint32_t content_address;   // 4 bytes
    };

    // Contains specific file information.
    struct info_header  // 40 bytes
    {
        uint32_t size;          // 4 bytes
        int32_t width;          // 4 bytes
        int32_t height;         // 4 bytes
        uint16_t color_planes;  // 2 bytes
        uint32_t compression;   // 4 bytes
        
    };
};

FILE *img;

int main()
{   
    struct bmp image;

    img = fopen("images/2x2.bmp", "rb");
    if (!img)
    {
        perror("Error opening file.");
        return 1;
    }

    unsigned char buffer[500];
    size_t file_size = fread(buffer, 2, 2, img);

    printf("File was opened!\nFile size: %zu\n\n", file_size);


}