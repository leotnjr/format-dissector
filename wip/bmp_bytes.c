#include<stdio.h>
#include<stdlib.h> 

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
    size_t file_size = fread(buffer, 1, 500, img);

    printf("\nread bytes: %zu\n\n", file_size);

    //Shows which byte index have the contents of the image matrix  
    int address = buffer[10];
    printf("Image starts at byte %d\n\n",address);

    
    // Trying to see were each byte is and their contents
    // using byte offset found in the bmp format specifications.
    for(i = 0; i < file_size; i++)
    {
        
        switch (i)
        {
            case 0:
                printf("\nHEADER"
                    "\nFile format:"
                    "\nByte %02d: 0x%02X\n", i, buffer[i]);
                break;
            case 2:
                printf("\nFile size:"
                    "\nByte:%02d: 0x%02X\n", i, buffer[i]);
                break;
            case 6:
                printf("\nReserved_A:"
                    "\nByte:%02d: 0x%02X\n", i, buffer[i]);
                break;
            case 8:
                printf("\nReserved_B:"
                    "\nByte:%02d: 0x%02X\n", i, buffer[i]);
                break;
            case 10:
                printf("\nStarting Address:"
                    "\nByte:%02d: 0x%02X\n", i, buffer[i]);
                break;
            case 14:
                printf("\nBITMAPINFOREADER"
                    "\nSize:"
                    "\nByte:%02d: 0x%02X\n", i, buffer[i]);
                break;
            case 18:
                printf("\nWidth in pixels:"
                    "\nByte:%02d: 0x%02X\n", i, buffer[i]);
                break;
            case 22:
                printf("\nHeight in pixels:"
                    "\nByte:%02d: 0x%02X\n", i, buffer[i]);
                break;
            case 26:
                printf("\nNumber of color planes:"
                    "\nByte:%02d: 0x%02X\n", i, buffer[i]);
                break;
            case 28:
                printf("\nBits per pixel:"
                    "\nByte:%02d: 0x%02X\n", i, buffer[i]);
                break;
            case 30:
                printf("\nCompression method:"
                    "\nByte:%02d: 0x%02X\n", i, buffer[i]);
                break;
            case 34:
                printf("\nImage size:"
                    "\nByte:%02d: 0x%02X\n",
                    i, buffer[i]);
                break;
            case 38:
                printf("\nHorizontal resolution. Pixel per metre, signed integer:"
                    "\nByte:%02d: 0x%02X\n", i, buffer[i]);
                break;
            case 42:
                printf("\nVertical resolution of the image. Pixel per metre, signed integer:"
                    "\nByte:%02d: 0x%02X\n", i, buffer[i]);
                break;
            case 46:
                printf("\nNumber of colors in the color palette:"
                    "\nByte:%02d: 0x%02X\n", i, buffer[i]);
                break;
            case 50:
                printf("\nNumber of important colors used, or 0 when every color is important:"
                    "\nByte:%02d: 0x%02X\n", i, buffer[i]);
                break;
            case 54:
                printf("\nStart of Image:"
                    "\nByte:%02d: 0x%02X\n", i, buffer[i]);
                break;
            default:
                printf("Byte:%02d: 0x%02X\n", i, buffer[i]);
                break;
        }
    }
    getchar();
    
    fclose(img);
}
