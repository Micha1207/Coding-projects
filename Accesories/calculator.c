/*
* calculator.c
* C calculator 
* 
* 
* Written by Michael (micha1207) in Visual Studio Code.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float a = 0.00;
float b = 0.00;
char  t;
float out;

int main(void){

    printf("\nEnter a: ");
    scanf("%f", &a);

    printf("\nEnter b: ");
    scanf("%f", &b);

    printf("\nEnter operation (+, -, *, /): ");
    scanf(" %c", &t);

    switch (t){
    case '+':
        out = a + b;
        break;
    
    case '-':
        out = a - b;
        break;
    
    case '*':
        out = a * b;
        break;
    
    case '/':
        out = a / b;
        break;
    }

    printf("\nResult: %f\n", out);

    return 0;
    
}
