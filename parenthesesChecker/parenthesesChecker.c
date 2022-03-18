#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 10 // This define is the maximum number of elements the stack can hold.
// The Integer top is the top position of the stack and the integer option will be 1 or 0 deepending on the users decision.
int top = -1, option = 1;
int stack[MAX]; // This is the stack that we will push characters to and pop characters from.
// This function prints a welcome message to the screen.
void printWelcomeMessage();
// This function controls that the user inputs an expression only containing the characters '(', ')', '[', ']' '{' and '}'.
bool validInput(char *expression, bool validInput); 
// This function then controls if the inputted expression is a valid expression.
int validExpression(char *expression, int *flag);
// This function inserts a character to the top of the stack.
void push(char);
// This function deletes a character from the top of the stack.
char pop();
// This function prints (based on the value of flag) one of these messages "Not Balanced", "Stack Overflow", "Stack Underflow" or "Balanced".
void printResult(int *flag);
// This function asks the user if they want to try a new expression and sets option to "0" for "yes" or "1" for "no".
void endMessage(int *option);

void main() {
    printWelcomeMessage();
    do {
        int flag = 1; // This integer flag is used to print the correct message to the screen.
        char expression[MAX*2]; // This is a string representation of the inputted expression.
        // This is variable is set to true if the user inputs an expression only containing the characters '(', ')', '[', ']' '{' and '}'.
        bool validInputStr = false; 
        top = -1; // Because I decieded to loop my program I had to reset top in some situations.

        do { // Loops until user inputs an expression containing only the characters '(', ')', '[', ']' '{' and '}'.
            validInputStr = validInput(expression, validInputStr);
            if(!validInputStr) puts("Your input doesn't contain only the characters '(', ')', '[', ']' '{' and '}', please try again!");
        } while (!validInputStr); 
        validExpression(expression, &flag); // Will change the value of flag if invalid expression, stack overflow or stack underflow.
        printResult(&flag); // Prints proper message to the screen based on flag's value.
        endMessage(&option); // Prints an end message to the screen asking the user to input "0" for "yes" and "1" for "no".
    } while (option == 0);
}

void printWelcomeMessage() { // Prints a welcome message to the screen.
    puts("************************************************************************************\n"
        "Welcome!\n"
        "This is a program that uses a stack to check if an expression is a valid expression.\n"
        "The Constraints are:\n"
        "• The expression can contain only the characters '(', ')', '[', ']' '{' and '}'.\n"
        "• Open brackets must be closed by the same type of brackets.\n"
        "• Open brackets must be closed in the correct order.\n"
        "• Curved ( ) brackets can contain only ( ) brackets.\n"
        "• Square brackets [ ] can contain only [ ] and ( ) brackets.\n"
        "• Curly { } brackets can contain { }, [ ] and ( ) brackets.\n"
        "************************************************************************************\n");
}

bool validInput(char *expression, bool validInputStr) { // Controls that the expression only contain the valid characters.
    fflush(stdin);
    printf("Enter an expression containing only the characters '(', ')', '[', ']' '{' and '}': ");
    fgets(expression, MAX*2, stdin);
    expression[(strlen(expression)-1)] = '\0'; // Sets the newline character added by fgets to '\0'.
    
    for (size_t i = 0; expression[i] != '\0' ; i++) { // Loops until every character in expression have been controlled.
        if (expression[i] == '(' || expression[i] == ')' || expression[i] == '[' || 
            expression[i] == ']' || expression[i] == '{' || expression[i] == '}') {
            validInputStr = true;
        }
        else return validInputStr = false; // If any character isn't one of these characters '(', ')', '[', ']' '{' and '}' return false.
    }
    return validInputStr; // Expression is only containing the characters '(', ')', '[', ']' '{' and '}' so the function returns true.
}

int validExpression(char *expression, int *flag) {
    for(size_t i = 0; expression[i] != '\0'; i++) {
        if (top == (MAX-1)) return *flag = 0; // If top == Max-1 we will have stock overflow condition.
        // Push to stack if next element in expression isn't '{','[' or '\0'. If next element is '{','[' or '\0' expression is invalid.
        if (expression[i] == '(') { 
            if(expression[i+1] == '{' || expression[i+1] == '[' || expression[i+1] == '\0') return *flag = 0; // Flag = 0 prints Not Balanced. 
            else push(expression[i]); // Push character at position i in expression to stack.
        }
        // Push to stack if next element in expression isn't '{' or '\0'. If next element is '{' or '\0' expression is invalid.
        if (expression[i] == '[') {
            if (expression[i+1] == '{' || expression[i+1] == '\0') return *flag = 0; // Flag = 0 prints Not Balanced.
            else push(expression[i]); // Push character at position i in expression to stack.
        }
        // Push to stack if next element in expression isn't '\0'. If next element is '\0' expression is invalid.
        if (expression[i] == '{') {
            if (expression[i+1] == '\0') return *flag = 0; // Flag = 0 prints Not Balanced.
            else push(expression[i]); // Push character at position i in expression to stack.
        }
        if (expression[i] == ')' || expression[i] == '}' || expression[i] == ']') {
            if (top == -1) return *flag = -1; // If top == -1 we will return flag -1 which means stack underflow.
            else { // These if statements checks if expression is valid else flag = 0 is returned and Not Balanced is printed.
                char temp = pop();
                if (expression[i] == ')' && (temp == '{' || temp == '[')) return *flag = 0;
                if (expression[i] == '}' && (temp == '(' || temp == '[')) return *flag = 0;
                if (expression[i] == ']' && (temp == '(' || temp == '{')) return *flag = 0;
                if (expression[i+1] == '\0' && top != -1) return *flag = 0;
            }
        }
    } 
}

void push(char character) { // Inserts a character to the top of the stack.
    if (top == MAX-1) return;
    top = top+1; // Increments top to be the new top position.
    stack[top] = character; // Inserts the character to the new top position of the stack.
}

char pop() { // Deletes a character from the top of the stack.
    if (top == -1) return 'e';
    return stack[top--]; // Decrement the value of top and returns the character at the new top position.
}

void printResult(int *flag) { // Prints proper message to the screen based on flag's value.
    if (*flag == 0) (top == (MAX-1)) ? printf("Stack Overflow!\n") : printf("Ouch! The expression is Not Balanced!\n");
    else if (*flag == -1 && top == -1) printf("Stack Underflow!\n");
    else printf("Great the expression is Balanced!\n");
}

void endMessage(int *option) { // Prints an end message to the screen asking the user to input "0" for "yes" and "1" for "no".
    printf("\nDo you want to try another expression?\nPress \"0\" for \"yes\" and \"1\" for \"no\": ");
    fflush(stdin);
    scanf("%d", &*option);
    if (*option == 1) puts("\nHave a good one!");
}