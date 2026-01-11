#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;
struct node *head2 = NULL;

/* Insert at beginning */
void insertFirst(int value, int ll) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    new_node->data = value;
    new_node->prev = NULL;

    if (ll == 1) {
        new_node->next = head;
        if (head != NULL)
            head->prev = new_node;
        head = new_node;
    } 
    else if (ll == 2) {
        new_node->next = head2;
        if (head2 != NULL)
            head2->prev = new_node;
        head2 = new_node;
    } 
    else {
        printf("Invalid linked list\n");
        free(new_node);
    }
}

/* Insert at end */
void insertEnd(int value, int ll) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    new_node->data = value;
    new_node->next = NULL;

    if (ll == 1) {
        if (head == NULL) {
            new_node->prev = NULL;
            head = new_node;
            return;
        }

        struct node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = new_node;
        new_node->prev = temp;
    } 
    else if (ll == 2) {
        if (head2 == NULL) {
            new_node->prev = NULL;
            head2 = new_node;
            return;
        }

        struct node *temp = head2;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = new_node;
        new_node->prev = temp;
    } 
    else {
        printf("Invalid linked list\n");
        free(new_node);
    }
}

/* Insert at position */
void insertAtpos(int value, int pos, int ll) {
    if (pos <= 0) {
        printf("Invalid position\n");
        return;
    }

    if (pos == 1) {
        insertFirst(value, ll);
        return;
    }

    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    new_node->data = value;

    struct node *temp = (ll == 1) ? head : head2;
    if (temp == NULL) {
        printf("Position out of range\n");
        free(new_node);
        return;
    }

    for (int i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Position out of range\n");
        free(new_node);
        return;
    }

    new_node->next = temp->next;
    new_node->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = new_node;

    temp->next = new_node;
}

/* Delete first node */
void deleteFirst(int ll) {
    if (ll == 1) {
        if (head == NULL) return;
        struct node *temp = head;
        head = head->next;
        if (head != NULL)
            head->prev = NULL;
        free(temp);
    } 
    else if (ll == 2) {
        if (head2 == NULL) return;
        struct node *temp = head2;
        head2 = head2->next;
        if (head2 != NULL)
            head2->prev = NULL;
        free(temp);
    }
}


/* Delete last node */
void deleteEnd(int ll) {
    struct node *temp = (ll == 1) ? head : head2;

    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }

    if (temp->next == NULL) {
        if (ll == 1)
            head = NULL;
        else
            head2 = NULL;

        free(temp);
        return;
    }

    while (temp->next != NULL)
        temp = temp->next;

    temp->prev->next = NULL;
    free(temp);
}

/* Delete at position */
void deleteAtpos(int pos, int ll) {
    if (pos <= 0) {
        printf("Invalid position\n");
        return;
    }

    if (pos == 1) {
        deleteFirst(ll);
        return;
    }

    struct node *temp = (ll == 1) ? head : head2;

    for (int i = 1; i < pos && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Position out of range\n");
        return;
    }

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    if (temp->prev != NULL)
        temp->prev->next = temp->next;

    free(temp);
}

/* Search */
void search(int value, int ll) {
    struct node *temp = (ll == 1) ? head : head2;

    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }

    int pos = 1, found = 0;
    while (temp != NULL) {
        if (temp->data == value) {
            printf("Element %d found at position %d\n", value, pos);
            found = 1;
        }
        temp = temp->next;
        pos++;
    }

    if (!found)
        printf("Element not found\n");
}

/* Display */
void display(int ll) {
    struct node *temp = (ll == 1) ? head : head2;

    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("Linked List %d: ", ll);
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

/* Merge list 2 into list 1 */
void merge() {
    if (head == NULL) {
        head = head2;
        head2 = NULL;
        return;
    }

    if (head2 == NULL)
        return;

    struct node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = head2;
    head2->prev = temp;
    head2 = NULL;
}

/* Main */
int main() {
    int op, value, pos, ll;

    while (1) {
        printf("\n1.Insert at beginning\n2.Insert at end\n3.Insert at position");
        printf("\n4.Delete first\n5.Delete last\n6.Delete at position");
        printf("\n7.Search\n8.Display\n9.Merge\n10.Exit\n");
        printf("Choose operation: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                scanf("%d %d", &ll, &value);
                insertFirst(value, ll);
                break;
            case 2:
                scanf("%d %d", &ll, &value);
                insertEnd(value, ll);
                break;
            case 3:
                scanf("%d %d %d", &ll, &value, &pos);
                insertAtpos(value, pos, ll);
                break;
            case 4:
                scanf("%d", &ll);
                deleteFirst(ll);
                break;
            case 5:
                scanf("%d", &ll);
                deleteEnd(ll);
                break;
            case 6:
                scanf("%d %d", &ll, &pos);
                deleteAtpos(pos, ll);
                break;
            case 7:
                scanf("%d %d", &ll, &value);
                search(value, ll);
                break;
            case 8:
                scanf("%d", &ll);
                display(ll);
                break;
            case 9:
                merge();
                break;
            case 10:
                return 0;
            default:
                printf("Invalid option\n");
        }
    }
}