#include<stdio.h>
#define SIZE 5

int cq[SIZE];
int f = -1, r = -1;

void push(int value) {
    if ((r == SIZE - 1 && f == 0) || (r == f - 1)) {
        printf("Overflow\n");
        return;
    }

    if (f == -1) f = 0;

    if (r == SIZE - 1) {
        r = 0;
    }
    else {
        r++;
    }
    cq[r] = value;
}

void pop() {
    if (f == -1) {
        printf("Underflow\n");
        return;
    }

    if (f == r) {
        f = -1;
        r = -1;
    }
    else if (f == SIZE - 1) {
        f = 0;
    }
    else {
        f++;
    }
}

void traversal() {
    if (f == -1) {
        printf("Queue is empty\n");
        return;
    }

    int i = f;
    printf("Elements are:\n");
    while (1) {
        printf("%d\n", cq[i]);
        if (i == r)
            break;
        i = (i + 1) % SIZE;
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
    traversal();
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