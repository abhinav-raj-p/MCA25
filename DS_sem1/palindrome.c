#include<stdio.h>
#include<string.h>
#define MAX 20
int queue[MAX];
int front=-1,rear=-1;
void enqueue(char s){
    if(rear==MAX-1){
        printf("Overflow");
    }
    else{
        if(front==-1){
        front++;
    }
    rear++;
    queue[rear]=s;
}
void dequeue(){
    if(front=-1){
        printf("Underflow");

    }
    else{
        front++;
        return queue[front];
    }
}

}
void main(){
    char s[20];
printf("Enter your string to check whether it is plaindrome or not\n");

scanf("%s",s);
printf("%d",strlen(s));
for(int i=0;i<length(s);i++){
    enqueue(s[i]);
}
for(int i=0;i<j;i++){
    for(int j=strlen(j)-1;i<j;j--){
        char r=dequeue();
        if()
    }
}
}