/*
* launcher.c
* Helps to launch Michael's games.
* 
* Usage: This program asks you which game you want to play.
*
* Written by Michael (micha1207) in Visual Studio Code.
* Pushed: 21.11.2024 
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char exec;
char user;
void usr_name();

int main(){    
    // Declare a buffer to hold the username
    char user[100];
    
    // Open a pipe to the command "echo $USER"
    FILE *fp = popen("echo $USER", "r");
    if (fp) {
        fgets(user, sizeof(user), fp);  // Capture the output into the buffer
        fclose(fp);  // Close the pipe
    } else {
        printf("Failed to get user name.\n");
        return 1;
    }

    // Welcome User
    printf("Hello, %s", user);
    printf("\nWelcome to Michael's games v1.0 \n");
    printf("What game do you want to play? \n");

    // Select game
    printf("\nG# | ----Game title---- | lang | difficulty \n");
    printf("1.     Number Guess Game     C     very hard\n");

    scanf("%c", &exec);

    if (exec == '1') {
        sleep(0.2); // Sleep for 0.2 second
        printf("\n\n");
        system("num-game"); // Run the number guessing game
    }
}