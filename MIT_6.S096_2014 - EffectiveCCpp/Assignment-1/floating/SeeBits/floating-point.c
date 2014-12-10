#include <stdio.h>

union float_bits {
    float f;
    unsigned int bits;
};

int decimal_binary(int n)  /* Function to convert decimal to binary.*/
{
    int rem, i=1, binary=0;
    while (n!=0)
    {
        rem=n%2;
        n/=2;
        binary+=rem*i;
        i*=10;
    }
    return binary;
}

char* print_bits(unsigned int num, char* bitArr, size_t size) {
    // Write to the arr backwards so that the binary representation
    // is in the correct order i.e.  the LSB is on the far right
    for (int idx = (size-2); idx >= 0; idx--) {
        bitArr[idx] = (num & 1) ? '1' : '0'; 
        num = num>>1; // right shift by 1 will divide by 2
    }
    /* start to print */
    if(bitArr[0] == '1') printf("-1.");
    else printf("1.");
    for (unsigned int i = 9; i<=(size-1); i++) {
        printf("%c", bitArr[i] );
    }
    // http://www.wikihow.com/Convert-from-Binary-to-Decimal // using doubling
    int exponent = 0; 
    for (int i = 1; i<=8; i++) {
        if (bitArr[i] == '1') (exponent = (exponent << 1) + 1);
        else exponent <<= 1;
    }
    printf("* 2^%d\n", exponent-127);
    return bitArr;
}


void print_float_bits(float f) {
    union float_bits t;
    t.f = f;
    size_t size =  sizeof(int)*8 + 1;
    char bitArr[size];
    bitArr[size-1] = '\0';
    print_bits(t.bits, bitArr, size);
}



int main(void) {
    print_float_bits(1.5f); // "The float looks like Ox4OaOOOOO in hex."
    // e is arr[1:9]
    // sign is arr[0]
    //print_bits(3);
    return 0;
}