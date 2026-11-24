#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define USERNAME_MAX 32
#define EMAIL_MAX 64

typedef struct {
    int id;
    char username[USERNAME_MAX];
    char email[EMAIL_MAX];
} User;

void print_user(const User *u) {
    printf("User { id: %d, username: %s, email: %s }\n",
    u->id, u->username, u->email);
}

User *create_user(int id, const char *username, const char *email) {
    
    if (username == NULL || email == NULL) return NULL;

    User *u = malloc(sizeof *u);
    if (u == NULL) return NULL;

    memset(u, 0, sizeof *u);

    u->id = id;

    strncpy(u->username, username, sizeof u->username -1);
    strncpy(u->email, email, sizeof u->email -1);

    return u;
}

int main(void) {
    User *alice = create_user(1, "alice", "alice@example.com");
    User *bob = create_user(1, "bob", "bob@example.com");

    if (alice == NULL || bob == NULL) {
        fprintf(stderr, "Failed to create user\n");
        free(alice);
        free(bob);
        return 1;
    }

    print_user(alice);
    print_user(bob);

    free(alice);
    free(bob);

    return 0;
    
}