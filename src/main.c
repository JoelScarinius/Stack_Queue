#include <stdio.h>
#include <string.h>

// Option is a integer variable thatis used to represent what menu choice the user have chosen. 
static unsigned int option = 0;

static void printWelcomeMessage(); // This function prints a short welcome message.
static void displayMainMenu(); // This function displays the main menu.

void main() {
    printWelcomeMessage();
    do {
        displayMainMenu();
        printf("\nYour choice?: ");
        fflush(stdin);
        scanf("%d", &option);
        switch(option) { // Control structure for all the different options the user have.
        case 1: break;
        case 2: break;
        case 3: break;
        case 4: break;
        case 0: break;
        default: break;
        }
    } while (option != 0);
}

static void printWelcomeMessage() { // Prints a short welcome message.
    puts("******************************************************************************************\n"
        "Welcome!\nThis is a program that uses a linkedlist to create a directory of phone numbers and names.\n"
        "Down below the main menu is diplayed where you can see which options you have.\nPlease enjoy!\n"
        "******************************************************************************************");
}

static void displayMainMenu() { // Displays the main menu.
    puts("\n\n***** MAIN MENU *****"
        "\n1: Display record"
        "\n2: Display directory"
        "\n3: Add a new record at the beginning of the directory"
        "\n4: Delete a record"
        "\n0: Exit");
}

