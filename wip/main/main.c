#include<stdio.h>
#include<stdlib.h>
#include<string.h>


FILE *img;
unsigned char general_header[8];
unsigned char *buffer;


FILE* loadFile(char path[])
{
    FILE *file;
    file = fopen(path,"rb");
    if (!file) return NULL;
    return file;
}
void checkSignature(char header[]);

int main()
{
    img = loadFile("../images/2x2.bmp");

    fseek(img, 0, SEEK_END);
    long img_size = ftell(img);
    rewind(img);

    buffer = malloc(img_size);
    if (!buffer)
    {
        perror("Malloc failed");
        return 1;
    }

    printf("\n\nAllocated memory for buffer: %zu.", img_size * sizeof(unsigned char));
    fread(general_header, 1, 8, img);

    printf("\n\nThe signature is: ");

    int i;
    for(i = 0; i<8; i++)
    {
        printf("%X", general_header[i]);
    }
    printf("\nHeader signature preview: ");
    for(i = 0; i<2; i++)
    {
        printf("%c", general_header[i]);
    }

    printf("\n\n");
    free(buffer);
    buffer = NULL;
    fclose(img);
    getchar();
}