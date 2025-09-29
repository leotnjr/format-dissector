#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<string.h>

/*
This is my first attempt to understand bitmap format byte structure.
The switch was helping me visualize the bytes in cmd.
*/
FILE *img;

int main()
{
	int i;
    img = fopen("images/2x2.bmp", "rb");
    if (!img)
    {
        perror("Error opening file.");
        return 1;
    }
    
    // General info
    unsigned char buffer[500]; //max file size for now.
    // size_t file_size = fread(buffer, 1, 500, img);


    // printf("\nread bytes: %zu\n\n", file_size);

    //Shows which byte index have the contents of the image matrix  
    //int address = buffer[10];
    //printf("Image starts at byte %d\n\n",address);

    
    // Trying to see were each byte is and their contents
    // using byte offset found in the bmp format specifications.
    unsigned char signature[3];
    fread(signature, 1, 2, img);
    signature[2] = '\0';
    
    if (strcmp(signature, "BM\0") == 0)
    {
        printf("The file has bitmap signature!\n");
    }
    else
    {
        printf("Signature doesnt match BMP.\n\nExiting\n");
        exit(0);
    }
    
    getchar();
    
    fclose(img);
}
