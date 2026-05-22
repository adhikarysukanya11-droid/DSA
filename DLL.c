#include <stdio.h>
#include <stdlib.h>

// Structure of Doubly Linked List Node
struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;

// Insert at Beginning
void insertBeginning(int value)
{
    struct Node *newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;

    if(head != NULL)
    {
        head->prev = newNode;
    }

    head = newNode;

    printf("Node inserted at beginning\n");
}

// Insert at End
void insertEnd(int value)
{
    struct Node *newNode, *temp;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = NULL;

    if(head == NULL)
    {
        newNode->prev = NULL;
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
        newNode->prev = temp;
    }

    printf("Node inserted at end\n");
}

// Delete from Beginning
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

        if(head != NULL)
        {
            head->prev = NULL;
        }

        free(temp);

        printf("Node deleted from beginning\n");
    }
}

// Delete from End
void deleteEnd()
{
    struct Node *temp;

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
            temp = temp->next;
        }

        temp->prev->next = NULL;

        free(temp);

        printf("Node deleted from end\n");
    }
}

// Display Forward
void displayForward()
{
    struct Node *temp;

    if(head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        temp = head;

        printf("Forward List: ");

        while(temp != NULL)
        {
            printf("%d <-> ", temp->data);

            temp = temp->next;
        }

        printf("NULL\n");
    }
}

// Display Backward
void displayBackward()
{
    struct Node *temp;

    if(head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        temp = head;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        printf("Backward List: ");

        while(temp != NULL)
        {
            printf("%d <-> ", temp->data);

            temp = temp->prev;
        }

        printf("NULL\n");
    }
}

// Main Function
int main()
{
    int choice, value;

    while(1)
    {
        printf("\n--- DOUBLY LINKED LIST MENU ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete from Beginning\n");
        printf("4. Delete from End\n");
        printf("5. Display Forward\n");
        printf("6. Display Backward\n");
        printf("7. Exit\n");

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
                deleteBeginning();
                break;

            case 4:
                deleteEnd();
                break;

            case 5:
                displayForward();
                break;

            case 6:
                displayBackward();
                break;

            case 7:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}