#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 10

int top = -1, option = 1;
int stack[MAX];

bool validInput(char *expression, bool validInput);
int validExpression(char *expression, int *flag);
void push(char);
char pop();

void main() {
    do {
        int flag = 1;
        char expression[MAX*2];
        bool validInputStr = false;
        top = -1;

        do {
            validInputStr = validInput(expression, validInputStr);
            if(!validInputStr) puts("Your input doesn't only contain '(', ')', '[', ']' '{' and '}', please try again!");
        } while (!validInputStr); 
        validExpression(expression, &flag); 
        if (flag == 0) {
            if (top == (MAX-1)) printf("Stack Overflow!\n");
            else if (top == -1) printf("Stack Underflow!\n");
            else printf("Ouch! The expression is not balanced!\n");
        }
        else printf("Great the expression is balanced!\n");
        printf("\nDo you want to try another expression?\nPress \"0\" for \"yes\" and \"1\" for \"no\": ");
        fflush(stdin);
        scanf("%d", &option);
    } while (option == 0);
}

bool validInput(char *expression, bool validInputStr) {
    fflush(stdin);
    printf("Enter an expression only containing '(', ')', '[', ']' '{' and '}': ");
    fgets(expression, MAX*2, stdin);
    expression[(strlen(expression)-1)] = '\0';
    
    for (size_t i = 0; expression[i] != '\0' ; i++) {
        if (expression[i] == '(' || expression[i] == ')' || expression[i] == '[' || 
            expression[i] == ']' || expression[i] == '{' || expression[i] == '}') {
            validInputStr = true;
        }
        else return validInputStr = false;
    }
    return validInputStr;
}

int validExpression(char *expression, int *flag) {
    for(size_t i = 0; expression[i] != '\0'; i++) {
        if (top == (MAX-1)) return *flag = 0;    
        else if (expression[i] == '(') {
            if(expression[i+1] == '{' || expression[i+1] == '[' || expression[i+1] == '\0') return *flag = 0;
            else push(expression[i]);
        }
        else if (expression[i] == '[') {
            if (expression[i+1] == '{' || expression[i+1] == '\0') return *flag = 0;
            else push(expression[i]);
        }
        else if (expression[i] == '{') {
            if(expression[i+1] == '\0') return *flag = 0;
            else push(expression[i]);
        }
        if (expression[i] == ')' || expression[i] == '}' || expression[i] == ']')
            if (top == -1) return *flag = 0;
        else {
            if (top == -1) return *flag = 0;
            char temp = pop();
            if (expression[i] == ')' && (temp == '{' || temp == '[')) return *flag = 0;
            if (expression[i] == '}' && (temp == '(' || temp == '[')) return *flag = 0;
            if (expression[i] == ']' && (temp == '(' || temp == '{')) return *flag = 0;
            if (expression[i+1] == '\0' && top != -1) return *flag = 0;
        }
    } 
}

void push(char character) {
    top = top+1;
    stack[top] = character;
}

char pop() {
    return stack[top--];
}