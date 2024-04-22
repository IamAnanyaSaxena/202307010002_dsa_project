#include<stdio.h>
#include<string.h>
#include<conio.h> /* For Turbo C, for console input/output */
#define max 20

char stack[max][100];
int top = -1;

void adding_website() {
    char value[100]; /* Temporarily store the website here before adding to the stack */
    if (top == max - 1) {
        printf("Stack overflow!\n");
    } else {
        printf("Enter the page you want to visit:\n");
        fflush(stdin); /* Clear the input buffer */
        gets(value); /* Use gets instead of scanf for Turbo C compatibility */
        top++;
        strcpy(stack[top], value);
    }
}

void backward_button() {
    if (top == -1) {
        printf("Stack underflow!\n");
    } else {
        printf("Previous website: ");
        top--;
        printf("%s\n", stack[top]);
    }
}

void forward_button() {
    if (top >= max-1 || top == -1) { /* Modified to prevent accessing beyond the stack */
        printf("No forward page available!\n");
    } else {
        printf("The following website: ");
        top++;
        printf("%s\n", stack[top]);
    }
}

void history() {
    int i;
    printf("Your history is:\n");
    for (i = 0; i <= top; i++) {
        printf("%s\n", stack[i]);
    }
}

int main() {
    int choice;
    do {
        printf("Menu:\n1. Add website\n2. Go backward\n3. Go forward\n4. History\n5. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                adding_website();
                break;
            case 2:
                backward_button();
                break;
            case 3:
                forward_button();
                break;
            case 4:
                history();
                break;
            case 5:
                printf("Thank you. Exitted.\n");
                break;
            default:
                printf("Wrong choice entered.\n");
        }
    } while (choice != 5);

    return 0;
}
