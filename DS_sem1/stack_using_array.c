#include<stdio.h>
#define SIZE 5

int stack[SIZE];
int top=-1;

void push(int value) {
    if (top == SIZE - 1) {
        printf("\nStack is full \n");
    
    }
    else {
        top ++;
        stack[top]=value;
    }
}

void pop() {
    if (top == - 1) {
        printf("\nStack is empty \n");
    
    }
    else {
        
        printf("\n %d is deleted successfully.. \n ", stack[top]);
        top--;
    }
}

void display() {
    if (top == - 1) {
        printf("Stack is empty \n");
    
    }
    else {
        printf("Stack elements are: \n");
        for(int i=0;i<=top;i++){
            printf("%d \n ", stack[i]);

        }
       
    }
}

int main() {
int op;
int value;
while (1)
{
   
printf( " \n 1.Insert \n 2.Delete \n 3.Display\n 4.exit \n");
printf( "Choose Operation : \n");
scanf("%d" , &op);

switch (op)
{
case 1:
    printf("Enter Number to insert : \n");
    scanf("%d", &value);
    push(value);
    break;

case 2:
    pop();
    break;

case 3:
    display();
    break;

case 4:
    return 0;
    break;


default:
    printf("Invalid Operation \n");
    break;
}
}
}