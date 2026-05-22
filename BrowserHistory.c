#include <stdio.h>
#include <string.h>

#define MAX 5

char history[MAX][50];
int top = -1;

// Visit new website
void visitWebsite(char site[])
{
    if(top == MAX - 1)
    {
        printf("History is full\n");
    }
    else
    {
        top++;

        strcpy(history[top], site);

        printf("%s visited\n", site);
    }
}

// Back operation
void goBack()
{
    if(top == -1)
    {
        printf("No browser history\n");
    }
    else
    {
        printf("Going back from %s\n", history[top]);

        top--;
    }
}

// Display History
void displayHistory()
{
    int i;

    if(top == -1)
    {
        printf("No history available\n");
    }
    else
    {
        printf("\n--- Browser History ---\n");

        for(i = top; i >= 0; i--)
        {
            printf("%s\n", history[i]);
        }
    }
}

// Main Function
int main()
{
    int choice;
    char site[50];

    while(1)
    {
        printf("\n--- BROWSER HISTORY MENU ---\n");
        printf("1. Visit Website\n");
        printf("2. Go Back\n");
        printf("3. Display History\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        getchar();

        switch(choice)
        {
            case 1:
                printf("Enter website name: ");
                fgets(site, sizeof(site), stdin);

                site[strcspn(site, "\n")] = '\0';

                visitWebsite(site);
                break;

            case 2:
                goBack();
                break;

            case 3:
                displayHistory();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}