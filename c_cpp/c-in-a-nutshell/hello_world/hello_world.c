#include<stdio.h>

int main() {
    char str1[20];

    printf("Your name: ");    
    scanf("%19s", str1);

    printf("Hello %s\n", str1);

    return 0;
}

// #include <stdio.h>

// int main () {
//    char str1[20], str2[30];

//    printf("Enter name: ");
//    scanf("%19s", str1);

//    printf("Enter your website name: ");
//    scanf("%29s", str2);

//    printf("Entered Name: %s\n", str1);
//    printf("Entered Website:%s\n", str2);
   
//    return(0);
// }