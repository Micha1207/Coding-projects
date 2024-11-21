/*
* num-game.c 
* "Guess the Number" Game 
* 
* Rules: You have to guess randomly taken number. Scale will be displayed. 
* If you guess correctly: You get 1 Point (int pts).
* If you guess incorrectly: Game quits.
*
* Use with "launcher.c" compiled as "mgms". If not - comment ("//") "oute();" 
* and uncomment (remove "//") "exit(0);" in "lvlX" functions.
*
* Written by Michael (micha1207) in Visual Studio Code.
* Pushed: 21.11.2024
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define ranseed time(NULL)

void lvl1();
void lvl2();
void lvl3();
void lvl4();
void lvl5();
void oute();

int pts = 0;
int num = 0;
int ran;
int in = 2;
int lvl = 1;

int main(void){
    srand(ranseed);
    
    printf("This is 'Number Guess Game' \n");

    // Level functions:
    lvl1();
    lvl2();
    lvl3();
    lvl4();
    lvl5();

    printf("So, you won! Congrats! It is hardly possible to get it done. \n");

    return 0;
}

void lvl1(){
    int ran = rand() % 2;

    printf("Select a number. 0 or 1? ");
    scanf("%i", &num); // Get user input

    if (num == ran){
        pts = pts + 1;
        printf("\nGood! You have %i points. \n", pts);
        
    } 
    if (num != ran) {
        printf("\nBad! The correct number was %i \n", ran);
        //exit(1);
        oute();
    }
}

void lvl2(){
    int ran = rand() % 5;

    printf("Select a number. 0 to 4? ");
    scanf("%d", &num); // Get user input

    if (num == ran){
        pts = pts + 1;
        printf("\nGood! You have %i points. \n", pts);
        
    } 
    if (num != ran) {
        printf("\nBad! The correct number was %i \n", ran);
        //exit(1);
        oute();
    }
}

void lvl3(){
    int ran = rand() % 7;

    printf("Select a number. 0 to 6? ");
    scanf("%d", &num); // Get user input

    if (num == ran){
        pts = pts + 1;
        printf("\nGood! You have %i points. \n", pts);
        
    } 
    if (num != ran) {
        printf("\nBad! The correct number was %i \n", ran);
        //exit(1);
        oute();
    }
}

void lvl4(){
    int ran = rand() % 9;

    printf("Select a number. 0 to 8? ");
    scanf("%d", &num); // Get user input

    if (num == ran){
        pts = pts + 1;
        printf("\nGood! You have %i points. \n", pts);
        
    } 
    if (num != ran) {
        printf("\nBad! The correct number was %i \n", ran);
        //exit(1);
        oute();
    }
}

void lvl5(){
    int ran = rand() % 11;

    printf("Select a number. 0 to 10? ");
    scanf("%d", &num); // Get user input

    if (num == ran){
        pts = pts + 1;
        printf("\nGood! You have %i points. \n", pts);
        
    } 
    if (num != ran) {
        printf("\nBad! The correct number was %i \n", ran);
        //exit(1);
        oute();
    }
}

void oute(){
    system("mgms");
}
