#include<stdio.h>
#define SIZE 5
int front=-1,rear=-1;
int queue[SIZE];

void enqueue(int value){
    if(rear==SIZE-1){
        printf("Queue is full\n");
    }
    else{
        if(front==-1) front=0;
       
        rear++;
        queue[rear]=value;
        
    }

}

void dequeue(){
      if(front==-1 || front>rear){
        printf("Queue is empty\n");
    }
    else{
        printf("%d is deleted",queue[front]);
        front++;

        
    }

}

void display(){

    if(front==-1 || front>rear){
        printf("Queue is empty\n");
    }
    else{
        printf("Elements are:\n");
        for (int i = front; i <=rear; i++)
        {
            printf("%d\n",queue[i]);
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
    enqueue(value);
    break;

case 2:
    dequeue();
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