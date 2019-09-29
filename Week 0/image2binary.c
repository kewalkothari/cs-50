#include <stdio.h>

#define IMAGE_FILE_LOCATION         "hello-world.png"
#define BINARY_TEXT_FILE_LOCATION   "hello-world-binary.txt"

int main() {
    int byteValue, byteIndex;
    FILE *imageFile;
    FILE *textFile;

    imageFile = fopen(IMAGE_FILE_LOCATION, "r");
    
    if (imageFile != NULL)
    {
        textFile = fopen(BINARY_TEXT_FILE_LOCATION, "w");

        do 
        {
            byteValue = fgetc(imageFile);

            for (byteIndex = 0; byteIndex < 8; byteIndex++) 
            {
                if (byteValue&(1<<(7-byteIndex))) 
                {
                    fputc('1', textFile);
                }
                else 
                {
                    fputc('0', textFile);
                }
            }
        } while (byteValue != EOF);

        fclose(imageFile);
        fclose(textFile);
        printf("Binary added to hello-worl-binary.txt");
    }
    else 
    {
        printf("File failed to load\n");
        fclose(imageFile);
    }
    return 0;
}