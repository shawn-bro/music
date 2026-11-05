#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int songID;
    char songName[50];
    char singerName[50];
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;
struct node *tail = NULL;

void addAtStart(int id, char name[], char singer[]) {
    struct node *newnode;

    newnode = malloc(sizeof(struct node));

    if (newnode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    newnode->songID = id;
    strcpy(newnode->songName, name);
    strcpy(newnode->singerName, singer);

    newnode->prev = NULL;
    newnode->next = head;

    if (head == NULL) {
        tail = newnode;
    } else {
        head->prev = newnode;
    }

    head = newnode;

    printf("Song added successfully!\n");
}

void addAtEnd(int id, char name[], char singer[]) {
    struct node *newnode;

    newnode = malloc(sizeof(struct node));

    if (newnode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    newnode->songID = id;
    strcpy(newnode->songName, name);
    strcpy(newnode->singerName, singer);

    newnode->next = NULL;
    newnode->prev = tail;

    if (tail == NULL) {
        head = newnode;
    } else {
        tail->next = newnode;
    }

    tail = newnode;

    printf("Song added successfully!\n");
}

void removeFromStart() {
    struct node *temp;

    if (head == NULL) {
        printf("Playlist is empty!\n");
        return;
    }

    temp = head;
    if(head == tail)
{
    head = tail = NULL;
}
else
{
    head = head->next;
    head->prev = NULL;
}

    printf("Removed song: %s\n", temp->songName);
    free(temp);
}

void removeFromEnd() {
    struct node *temp;

    if (tail == NULL) {
        printf("Playlist is empty!\n");
        return;
    }

    temp = tail;

    if (tail == head) {
        head = tail =  NULL;
    } else {
        tail = tail->prev;
        tail->next = NULL;
    }

    printf("Removed song: %s\n", temp->songName);
    free(temp);
}

void modifySong(int oldID, int newID) {
    struct node *temp = head;

    while (temp != NULL && temp->songID != oldID) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Song ID not found!\n");
        return;
    }

    temp->songID = newID;

    printf("Song ID modified successfully!\n");
}

void displayForward() {
    struct node *temp = head;

    if (head == NULL) {
        printf("Playlist is empty!\n");
        return;
    }

    printf("\n--- Playlist Forward ---\n");

    while (temp != NULL) {
        printf("Song ID: %d\n", temp->songID);
        printf("Song Name: %s\n", temp->songName);
        printf("Singer Name: %s\n\n", temp->singerName);

        temp = temp->next;
    }
}

void displayBackward() {
    struct node *temp = tail;

    if (tail == NULL) {
        printf("Playlist is empty!\n");
        return;
    }

    printf("\n--- Playlist Backward ---\n");

    while (temp != NULL) {
        printf("Song ID: %d\n", temp->songID);
        printf("Song Name: %s\n", temp->songName);
        printf("Singer Name: %s\n\n", temp->singerName);

        temp = temp->prev;
    }
}

int main() {
    int choice, id, oldID, newID;
    char name[50], singer[50];

    while (1) {
        printf("\n===== MUSIC PLAYLIST MANAGEMENT =====\n");
        printf("1. Add Song at Start\n");
        printf("2. Add Song at End\n");
        printf("3. Remove Song from Start\n");
        printf("4. Remove Song from End\n");
        printf("5. Display Playlist Forward\n");
        printf("6. Display Playlist Backward\n");
        printf("7. Modify Song ID\n");
        printf("8. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Song ID: ");
                scanf("%d", &id);

                printf("Enter Song Name: ");
                scanf(" %49[^\n]", name);

                printf("Enter Singer Name: ");
                scanf(" %49[^\n]", singer);

                addAtStart(id, name, singer);
                break;

            case 2:
                printf("Enter Song ID: ");
                scanf("%d", &id);

                printf("Enter Song Name: ");
                scanf(" %49[^\n]", name);

                printf("Enter Singer Name: ");
                scanf(" %49[^\n]", singer);

                addAtEnd(id, name, singer);
                break;

            case 3:
                removeFromStart();
                break;

            case 4:
                removeFromEnd();
                break;

            case 5:
                displayForward();
                break;

            case 6:
                displayBackward();
                break;

            case 7:
                printf("Enter old Song ID: ");
                scanf("%d", &oldID);

                printf("Enter new Song ID: ");
                scanf("%d", &newID);

                modifySong(oldID, newID);
                break;

            case 8:
                printf("Exiting Playlist...\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}
