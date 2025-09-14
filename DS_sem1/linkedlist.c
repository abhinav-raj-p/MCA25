#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head1 = NULL;
struct node *head2 = NULL;


void insertEnd(struct node **head_ref, int value) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = newnode;
    } else {
        struct node *temp = *head_ref;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void insertBeginning(struct node **head_ref, int value) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = *head_ref;
    *head_ref = newnode;
}


void insertPosition(struct node **head_ref, int position, int value) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;

    if (*head_ref == NULL || position <= 1) {
        newnode->next = *head_ref;
        *head_ref = newnode;
    } else {
        struct node *temp = *head_ref;
        int i = 1;
        while (i < position - 1 && temp->next != NULL) {
            temp = temp->next;
            i++;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
}


void deleteData(struct node **head_ref, int value) {
    struct node *temp = *head_ref, *prev = NULL;

    if (*head_ref == NULL) {
        printf("Empty\n");
        return;
    }

    if (temp->data == value) {
        *head_ref = temp->next;
        printf("%d deleted\n", value);
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Data not found\n");
        return;
    }

    prev->next = temp->next;
    printf("%d deleted\n", value);
    free(temp);
}


void deleteBeginning(struct node **head_ref) {
    struct node *temp = *head_ref;

    if (*head_ref == NULL) {
        printf("Empty\n");
        return;
    }

    *head_ref = temp->next;
    printf("%d deleted\n", temp->data);
    free(temp);
}


void deleteEnd(struct node **head_ref) {
    if (*head_ref == NULL) {
        printf("Empty\n");
        return;
    }

    struct node *temp = *head_ref;
    if (temp->next == NULL) {
        printf("%d deleted\n", temp->data);
        free(temp);
        *head_ref = NULL;
        return;
    }

    struct node *prev = NULL;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    printf("%d deleted\n", temp->data);
    prev->next = NULL;
    free(temp);
}

void search(struct node *head, int value) {
    struct node *temp = head;
    int i = 1;

    while (temp != NULL) {
        if (temp->data == value) {
            printf("%d is found at node %d\n", value, i);
            return;
        }
        temp = temp->next;
        i++;
    }

    printf("%d not found\n", value);
}

void printList(struct node *head) {
    if (head == NULL) {
        printf("List is empty\n");
    } else {
        struct node *temp = head;
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}


void mergeLists() {
    if (head1 == NULL) {
        head1 = head2;
    } else {
        struct node *temp = head1;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = head2;
    }
    head2 = NULL;
    printf("Lists merged successfully.\n");
}


int main() {
    int op, value, position, list_choice;
    struct node **current_list;

    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. Insert at end\n");
        printf("2. Insert at beginning\n");
        printf("3. Insert at position\n");
        printf("4. Delete by value\n");
        printf("5. Delete beginning\n");
        printf("6. Delete end\n");
        printf("7. Display list\n");
        printf("8. Search\n");
        printf("9. Merge list 2 into list 1\n");
        printf("10. Exit\n");
        printf("Choose operation: ");
        scanf("%d", &op);

        if (op >= 1 && op <= 8) {
            printf("Choose list (1 or 2): ");
            scanf("%d", &list_choice);
            if (list_choice == 1)
                current_list = &head1;
            else if (list_choice == 2)
                current_list = &head2;
            else {
                printf("Invalid list\n");
                continue;
            }
        }

        switch (op) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertEnd(current_list, value);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertBeginning(current_list, value);
                break;
            case 3:
                printf("Enter value: ");
                scanf("%d", &value);
                printf("Enter position: ");
                scanf("%d", &position);
                insertPosition(current_list, position, value);
                break;
            case 4:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteData(current_list, value);
                break;
            case 5:
                deleteBeginning(current_list);
                break;
            case 6:
                deleteEnd(current_list);
                break;
            case 7:
                printList(*current_list);
                break;
            case 8:
                printf("Enter value to search: ");
                scanf("%d", &value);
                search(*current_list, value);
                break;
            case 9:
                mergeLists();
                break;
            case 10:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid option\n");
        }
    }
}