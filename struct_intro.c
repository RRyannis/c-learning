#include <stdio.h>
#include <string.h>

#define USERNAME_SIZE 32
#define EMAIL_SIZE 255

typedef struct {
    int id;
    char username[USERNAME_SIZE];
    char email[EMAIL_SIZE];
} User;

/* Print a User's fields, accessed through a pointer. */
void print_user(const User *u) {
    printf("id=%d, username=%s, email=%s\n", u->id, u->username, u->email);
}

int main(void) {
    User u1 = {0};
    u1.id = 1;
    strncpy(u1.username, "ioannis", USERNAME_SIZE - 1);
    strncpy(u1.email, "ioannis@example.com", EMAIL_SIZE - 1);

    User u2 = {0};
    u2.id = 2;
    strncpy(u2.username, "maria", USERNAME_SIZE - 1);
    strncpy(u2.email, "maria@example.com", EMAIL_SIZE - 1);

    print_user(&u1);
    print_user(&u2);

    return 0;
}