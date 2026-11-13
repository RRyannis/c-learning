#include <stdio.h>
#include <string.h>

#define USERNAME_SIZE 32
#define EMAIL_SIZE 255

typedef struct {
    int id;
    char username[USERNAME_SIZE];
    char email[EMAIL_SIZE];
} User;

int main(void) {
    User u1 = {0};  // zero-initialize
    
    u1.id = 1;
    strncpy(u1.username, "ioannis", USERNAME_SIZE - 1);
    strncpy(u1.email, "ioannis@example.com", EMAIL_SIZE - 1);

    User u2 = {0};
    u2.id = 2;
    strncpy(u2.username, "maria", USERNAME_SIZE - 1);
    strncpy(u2.email, "maria@example.com", EMAIL_SIZE - 1);

    printf("User 1: id=%d, username=%s, email=%s\n", u1.id, u1.username, u1.email);
    printf("User 2: id=%d, username=%s, email=%s\n", u2.id, u2.username, u2.email);

    printf("\nsizeof(User) = %zu\n", sizeof(User));
    printf("offsetof id      = %zu\n", (size_t)((char*)&u1.id - (char*)&u1));
    printf("offsetof username = %zu\n", (size_t)((char*)&u1.username - (char*)&u1));
    printf("offsetof email   = %zu\n", (size_t)((char*)&u1.email - (char*)&u1));

    return 0;
}