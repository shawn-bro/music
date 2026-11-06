
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

void addAtPosition(int id, char name[], char singer[], int position) {
    struct node *newnode, *temp;
    int i;

    if (position < 1) {
        printf("Invalid position!\n");
        return;
    }

    if (position == 1) {
        addAtStart(id, name, singer);
        return;
    }

    temp = head;

    for (i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position!\n");
        return;
    }

    newnode = malloc(sizeof(struct node));

    if (newnode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    newnode->songID = id;
    strcpy(newnode->songName, name);
    strcpy(newnode->singerName, singer);

    newnode->prev = temp;
    newnode->next = temp->next;

    if (temp->next == NULL) {
        tail = newnode;
    } else {
        temp->next->prev = newnode;
    }

    temp->next = newnode;

    printf("Song added successfully!\n");
}

void removeFromStart() {
    struct node *temp;

    if (head == NULL) {
        printf("Playlist is empty!\n");
        return;
    }

    temp = head;

    if (head == tail) {
        head = tail = NULL;
    } else {
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
        head = tail = NULL;
    } else {
        tail = tail->prev;
        tail->next = NULL;
    }

    printf("Removed song: %s\n", temp->songName);
    free(temp);
}


void removeAtPosition(int position) {
    struct node *temp;
    int i;

    if (head == NULL) {
        printf("Playlist is empty!\n");
        return;
    }

    if (position < 1) {
        printf("Invalid position!\n");
        return;
    }

    if (position == 1) {
        removeFromStart();
        return;
    }

    temp = head;

    for (i = 1; i < position && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position!\n");
        return;
    }

    if (temp == tail) {
        removeFromEnd();
        return;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    printf("Removed song: %s\n", temp->songName);

    free(temp);
}


void modifySong(int oldID, int newID, char name[], char singer[]) {
    struct node *temp = head;

    while (temp != NULL && temp->songID != oldID) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Song ID not found!\n");
        return;
    }

    temp->songID = newID;
    strcpy(temp->songName, name);
    strcpy(temp->singerName, singer);

    printf("Song details modified successfully!\n");
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
    int choice, id, oldID, newID, position;
    char name[50], singer[50];

    
while (1) {
    printf("\n===== MUSIC PLAYLIST MANAGEMENT =====\n");
    printf("1. Add Song at Start\n");
    printf("2. Add Song at End\n");
    printf("3. Add Song at Specific Position\n");
    printf("4. Remove Song from Start\n");
    printf("5. Remove Song from End\n");
    printf("6. Remove Song at Specific Position\n");
    printf("7. Display Playlist Forward\n");
    printf("8. Display Playlist Backward\n");
    printf("9. Modify Song Details\n");
    printf("10. Exit\n");

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
            printf("Enter Song ID: ");
            scanf("%d", &id);

            printf("Enter Song Name: ");
            scanf(" %49[^\n]", name);

            printf("Enter Singer Name: ");
            scanf(" %49[^\n]", singer);

            printf("Enter Position: ");
            scanf("%d", &position);

            addAtPosition(id, name, singer, position);
            break;

        case 4:
            removeFromStart();
            break;

        case 5:
            removeFromEnd();
            break;

        case 6:
            printf("Enter Position: ");
            scanf("%d", &position);

            removeAtPosition(position);
            break;

        case 7:
            displayForward();
            break;

        case 8:
            displayBackward();
            break;

        case 9:
            printf("Enter old Song ID: ");
            scanf("%d", &oldID);

            printf("Enter new Song ID: ");
            scanf("%d", &newID);

            printf("Enter Song Name: ");
            scanf(" %49[^\n]", name);

            printf("Enter Singer Name: ");
            scanf(" %49[^\n]", singer);

            modifySong(oldID, newID, name, singer);
            break;

        case 10:
            printf("Exiting Playlist...\n");
            return 0;

        default:
            printf("Invalid choice!\n");
    }
}

}
