#include <stdio.h>
// peguei o código para printar binários do Stack Overflow -> https://stackoverflow.com/questions/111928/is-there-a-printf-converter-to-print-in-binary-format
void printBits(void const *const ptr)
{
    unsigned char *b = (unsigned char *)ptr;
    unsigned char byte;
    int i, j;

    for (i = 1 - 1; i >= 0; i--)
    {
        for (j = 7; j >= 0; j--)
        {
            byte = (b[i] >> j) & 1;
            printf("%u", byte);
        }
    }
    puts("");
}

unsigned int extract_bits(unsigned int number, int position, int width)
{
    unsigned int mask = (1 << width) - 1;
    return (number >> position) & mask;
}

int main()
{
    unsigned int number = 0b0100;
    int position = 2;
    int width = 2;

    unsigned int extracted_bits = extract_bits(number, position, width);

    printf("Numero original:");
    printBits(&number);
    printf("Bits extraidos (posicao %d, largura %d): ", position, width);
    printBits(&extracted_bits);

    unsigned int number2 = 0b01101001;
    int position2 = 3;
    int width2 = 3;

    unsigned int extracted_bits2 = extract_bits(number2, position2, width2);

    printf("Numero original:");
    printBits(&number2);
    printf("Bits extraidos (posicao %d, largura %d): ", position2, width2);
    printBits(&extracted_bits2);

    return 0;
}