#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Song
{
    char name[50];
    struct Song *next;
};

struct Song *head = NULL;

// Add song
void addSong(char songName[])
{
    struct Song *newSong, *temp;

    newSong = (struct Song*)malloc(sizeof(struct Song));

    strcpy(newSong->name, songName);
    newSong->next = NULL;

    if(head == NULL)
    {
        head = newSong;
    }
    else
    {
        temp = head;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newSong;
    }

    printf("Song added successfully\n");
}

// Display playlist
void displayPlaylist()
{
    struct Song *temp;

    if(head == NULL)
    {
        printf("Playlist is empty\n");
    }
    else
    {
        temp = head;

        printf("\n--- MUSIC PLAYLIST ---\n");

        while(temp != NULL)
        {
            printf("%s\n", temp->name);

            temp = temp->next;
        }
    }
}

int main()
{
    int choice;
    char songName[50];

    while(1)
    {
        printf("\n--- PLAYLIST MENU ---\n");
        printf("1. Add Song\n");
        printf("2. Display Playlist\n");
        printf("3. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        getchar();

        switch(choice)
        {
            case 1:
                printf("Enter song name: ");
                fgets(songName, sizeof(songName), stdin);

                songName[strcspn(songName, "\n")] = '\0';

                addSong(songName);
                break;

            case 2:
                displayPlaylist();
                break;

            case 3:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}