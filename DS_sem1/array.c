#include<stdio.h>

int arr[100],  size,  pos,  num;

void insert(){
    printf("Enter how many elements to enter?\n");
    scanf("%d",&size);
    printf("ENter the elements:\n");
    for(int i=0;i<size;i++){
        scanf("%d", &arr[i]);

    }

}


int search(int num){
    for(int i=0;i<size;i++){
        if (arr[i] == num){
            return i;
        }
    }
    return -1; 
}


void delete(){
    printf("Enter the number you want to delete:\n");
    scanf("%d", &num);
    pos = search(num);

    if (pos == -1) {
        printf("Element not found\n");
        return;
    }

    for (int i = pos; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
    printf("Element deleted successfully\n");
}


void display(){

    printf("The elements are:\n");
    for(int i=0;i<size;i++){
        printf("[%d]",arr[i]);
    }
}

void sort() {
    for (int j = 0; j < size - 1; j++) {
        for (int i = 0; i < size - j - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
    }
    printf("Final sorted array is:\n");
    display();
}



int main() {
int op;
int value;
while (1)
{
   
printf( " \n 1.Insert \n 2.Delete \n 3.Display\n 4.search \n 5. sort \n 6.exit \n");
printf( "Choose Operation : \n");
scanf("%d" , &op);

switch (op)
{
case 1:
    insert();
    break;

case 2:
    delete();
    break;

case 3:
    display();
    break;

case 4:
    printf("Enter the number you want to search?\n");
    scanf("%d",&num);
    pos=search(num);
    if (pos != -1)
        printf("Number found at index %d\n", pos);
    else
        printf("Number not found\n");
    break;

case 5:
    sort();
    break;

case 6:
    return 0;
    break;

default:
    printf("Invalid Operation \n");
    break;
}
}
}