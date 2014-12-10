#include <stdio.h>
#include <string.h>

/*
    http://www.gidnetwork.com/b-56.html
    BEWARE - in that page the if-else clause at the last is wrong,
            the else behaves like gets

    Enter some characters: enter large amount of characters and see b1 changing
*/
// Also : http://www.tenouk.com/Bufferoverflowc/Bufferoverflow1.html (Good!)
void usingGets() {
    printf("Using gets \n");
    char  b1[] = "ABCD";
    char  b2[] = "LMNO";
    char  b3[] = "ZYXW";
    
    puts(b1);
    puts(b2);
    puts(b3);
    putchar('\n');
    
    puts("Enter some characters:");
    gets(b2);

    putchar('\n');
    puts(b1);
    puts(b2);
    puts(b3);
}

void usingFgets() {
    printf("Using fgets \n");
    char  b1[] = "ABCD";
    char  b2[] = "LMNO";
    char  b3[] = "ZYXW";
    
    puts(b1);
    puts(b2);
    puts(b3);
    putchar('\n');
    
    puts("Enter some characters:");
    fgets(b2, 5, stdin);  // 5 is the size of buffer b2
    
    // if the characters entered is less than 5 then \n is put inside the buffer
    // following -if- is to mitigate that
    if (b2[strlen(b2)-1] == '\n') 
    {   // full input line read
        b2[strlen(b2)-1] = '\0';  // remove the new-line
    }
    putchar('\n');
    puts(b1);
    puts(b2);
    puts(b3);
}

int main( void )
{
    usingGets();
    usingFgets(); 
    return(0);
}