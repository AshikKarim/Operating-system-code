#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_USERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 20

bool login() {
    char username[MAX_USERNAME_LENGTH+1], password[MAX_PASSWORD_LENGTH+1];
    printf("Enter username: ");
    fgets(username, sizeof(username), stdin);
    printf("Enter password: ");
    int index = 0;
    char c;
    while ((c = getchar()) != '\n' && c != EOF) {
        if (index < MAX_PASSWORD_LENGTH) {
            password[index++] = c;
            printf("*");
        }
    }
    password[index] = '\0';

    // validate credentials
    // replace this block with your own validation mechanism
    bool valid = false;
    if (strcmp(username, "admin") == 0 && strcmp(password, "password") == 0) {
        valid = true;
    }
    else {
        printf("\nInvalid username or password.\n");
    }
    return valid;
}

int main() {
    bool loggedIn = false;
    //char choice;
     int option;
    while (true) {
        if (!loggedIn) {
            if (login()) {
                loggedIn = true;
            }
        
        
                while (1)
                {
                    printf("\n1. Option 1\n");
                    printf("2. Option 2\n");
                    printf("3. Option 3\n");
                    printf("4. Logout\n");
                    printf("Enter option: ");
                    scanf("%d", &option);

                    switch (option)
                    {
                        case 1:
                            printf("Option 1 selected.\n");
                            break;
                        case 2:
                            printf("Option 2 selected.\n");
                            break;
                        case 3:
                            printf("Option 3 selected.\n");
                            break;
                        case 4:
                            printf("Logout successful!\n");
                            break;
                        default:
                            printf("Invalid option.\n");
                            break;
                    }

                    if (option == 4)
                    {
                        break;
                    }
                }

                break;
            }
            else
            {
                printf("Invalid username or password.\n");
            }
        }
        // else if (option == 2)
        // {
        //     printf("Exiting program...\n");
        //     break;
        // }
        // else
        // {
        //     printf("Invalid option.\n");
        // }
         return 0;
    }

   

