#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct ticket {
    char name[50];
    int age;
    int movie_id;
    int theater_id;
    int seat_number;
};

void showMovies(void) {
    printf("\nAvailable Movies:\n");
    printf("1. URI: The Surgical Strike\n");
    printf("2. The Kashmir Files\n");
    printf("3. Article 370\n");
    printf("4. Shershaah\n");
}

void showTheaters(void) {
    printf("\nTheaters:\n");
    printf("1. Wave Cinemas\n");
    printf("2. PVR: KC Jammu\n");
    printf("3. Platinum Movietime: Palm Island Mall\n");
    printf("4. Apsara Multiplex\n");
}

void bookTicket(struct ticket *t) {
    showMovies();
    printf("Enter Movie ID (1-4): ");
    scanf("%d", &t->movie_id);

    showTheaters();
    printf("Enter Theater ID (1-4): ");
    scanf("%d", &t->theater_id);

    // clear leftover newline before reading string
    while (getchar() != '\n');

    printf("Enter your name: ");
    fgets(t->name, sizeof(t->name), stdin);
    t->name[strcspn(t->name, "\n")] = '\0';  // remove trailing newline

    printf("Enter your age: ");
    scanf("%d", &t->age);

    t->seat_number = (rand() % 100) + 1;
    printf("\nTicket booked successfully!\n\n");
}

void displayTicket(const struct ticket *t) {
    printf("\n--- Ticket Details ---\n");
    printf("Name      : %s\n",   t->name);
    printf("Age       : %d\n",   t->age);

    printf("Movie     : ");
    switch (t->movie_id) {
        case 1: printf("URI: The Surgical Strike\n");   break;
        case 2: printf("The Kashmir Files\n");           break;
        case 3: printf("Article 370\n");                break;
        case 4: printf("Shershaah\n");                  break;
        default: printf("Unknown\n");                   break;
    }

    printf("Theater   : ");
    switch (t->theater_id) {
        case 1: printf("Wave Cinemas\n");                                    break;
        case 2: printf("PVR: KC Jammu\n");                                  break;
        case 3: printf("Platinum Movietime: Palm Island Mall\n");           break;
        case 4: printf("Apsara Multiplex\n");                              break;
        default: printf("Unknown\n");                                     break;
    }

    printf("Seat No.  : %d\n\n", t->seat_number);
}

int main(void) {
    struct ticket myTicket = { "", 0, 0, 0, 0 };
    int choice;
    srand((unsigned)time(NULL));

    do {
        printf("=== Movie Ticket Booking System ===\n");
        printf("1. View Movies\n");
        printf("2. Book Ticket\n");
        printf("3. Display Ticket\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                showMovies();
                break;
            case 2:
                bookTicket(&myTicket);
                break;
            case 3:
                displayTicket(&myTicket);
                break;
            case 4:
                printf("Thank you for using the system.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }

        printf("\n");

    } while (choice != 4);

    return 0;
}
