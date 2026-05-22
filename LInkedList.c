#include <stdio.h>
#include <stdlib.h>

// Structure of Node
struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

// Insert at beginning
void insertBeginning(int value)
{
    struct Node *newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = head;

    head = newNode;

    printf("Node inserted at beginning.\n");
}

// Insert at end
void insertEnd(int value)
{
    struct Node *newNode, *temp;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = NULL;

    if(head == NULL)
    {
        head = newNode;
    }
    else
    {
        temp = head;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    printf("Node inserted at end.\n");
}

// Insert at position
void insertPosition(int value, int pos)
{
    struct Node *newNode, *temp;
    int i;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;

    temp = head;

    for(i = 1; i < pos - 1; i++)
    {
        temp = temp->next;

        if(temp == NULL)
        {
            printf("Invalid Position\n");
            return;
        }
    }

    newNode->next = temp->next;
    temp->next = newNode;

    printf("Node inserted at position %d\n", pos);
}

// Delete from beginning
void deleteBeginning()
{
    struct Node *temp;

    if(head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        temp = head;
        head = head->next;

        free(temp);

        printf("Node deleted from beginning\n");
    }
}

// Delete from end
void deleteEnd()
{
    struct Node *temp, *prev;

    if(head == NULL)
    {
        printf("List is empty\n");
    }
    else if(head->next == NULL)
    {
        free(head);
        head = NULL;

        printf("Last node deleted\n");
    }
    else
    {
        temp = head;

        while(temp->next != NULL)
        {
            prev = temp;
            temp = temp->next;
        }

        prev->next = NULL;

        free(temp);

        printf("Node deleted from end\n");
    }
}

// Search element
void search(int key)
{
    struct Node *temp;
    int pos = 1, found = 0;

    temp = head;

    while(temp != NULL)
    {
        if(temp->data == key)
        {
            printf("Element found at position %d\n", pos);
            found = 1;
            break;
        }

        temp = temp->next;
        pos++;
    }

    if(found == 0)
    {
        printf("Element not found\n");
    }
}

// Display list
void display()
{
    struct Node *temp;

    if(head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        temp = head;

        printf("Linked List: ");

        while(temp != NULL)
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }

        printf("NULL\n");
    }
}

// Main Function
int main()
{
    int choice, value, pos;

    while(1)
    {
        printf("\n----- LINKED LIST MENU -----\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Search Element\n");
        printf("7. Display List\n");
        printf("8. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);

                insertBeginning(value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);

                insertEnd(value);
                break;

            case 3:
                printf("Enter value: ");
                scanf("%d", &value);

                printf("Enter position: ");
                scanf("%d", &pos);

                insertPosition(value, pos);
                break;

            case 4:
                deleteBeginning();
                break;

            case 5:
                deleteEnd();
                break;

            case 6:
                printf("Enter element to search: ");
                scanf("%d", &value);

                search(value);
                break;

            case 7:
                display();
                break;

            case 8:
                exit(0);

            default:
                printf("Invalid Choice\n");
        }
    }

    return 0;
}