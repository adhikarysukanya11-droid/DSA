#include <stdio.h>
#include <stdlib.h>

// Structure of Node
struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

// Insert at Beginning
void insertBeginning(int value)
{
    struct Node *newNode, *temp;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;

    if(head == NULL)
    {
        head = newNode;
        newNode->next = head;
    }
    else
    {
        temp = head;

        while(temp->next != head)
        {
            temp = temp->next;
        }

        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }

    printf("Node inserted at beginning\n");
}

// Insert at End
void insertEnd(int value)
{
    struct Node *newNode, *temp;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;

    if(head == NULL)
    {
        head = newNode;
        newNode->next = head;
    }
    else
    {
        temp = head;

        while(temp->next != head)
        {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->next = head;
    }

    printf("Node inserted at end\n");
}

// Delete from Beginning
void deleteBeginning()
{
    struct Node *temp, *last;

    if(head == NULL)
    {
        printf("List is empty\n");
    }
    else if(head->next == head)
    {
        free(head);
        head = NULL;

        printf("Last node deleted\n");
    }
    else
    {
        temp = head;
        last = head;

        while(last->next != head)
        {
            last = last->next;
        }

        head = head->next;
        last->next = head;

        free(temp);

        printf("Node deleted from beginning\n");
    }
}

// Delete from End
void deleteEnd()
{
    struct Node *temp, *prev;

    if(head == NULL)
    {
        printf("List is empty\n");
    }
    else if(head->next == head)
    {
        free(head);
        head = NULL;

        printf("Last node deleted\n");
    }
    else
    {
        temp = head;

        while(temp->next != head)
        {
            prev = temp;
            temp = temp->next;
        }

        prev->next = head;

        free(temp);

        printf("Node deleted from end\n");
    }
}

// Display Circular Linked List
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

        printf("Circular Linked List: ");

        do
        {
            printf("%d -> ", temp->data);

            temp = temp->next;

        } while(temp != head);

        printf("(HEAD)\n");
    }
}

// Main Function
int main()
{
    int choice, value;

    while(1)
    {
        printf("\n--- CIRCULAR LINKED LIST MENU ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete from Beginning\n");
        printf("4. Delete from End\n");
        printf("5. Display\n");
        printf("6. Exit\n");

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
                display();
                break;

            case 6:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}