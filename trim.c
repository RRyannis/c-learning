//to compile gcc -Wall -Wextra -std=c11 -g -O0 -fsanitize=address trim.c -o trim
#include <stdio.h>
#include <ctype.h>

char *trim_in_place(char *s);

int main(void) {
    char buf1[] = "hello   ";
    char buf2[] = "world";
    char buf3[] = "   ";
    char buf4[] = "";

    printf("[%s]\n", trim_in_place(buf1));
    printf("[%s]\n", trim_in_place(buf2));
    printf("[%s]\n", trim_in_place(buf3));
    printf("[%s]\n", trim_in_place(buf4));
    return 0;
}

char *trim_in_place(char *s) {
   char *p = s;
   while (*p) {
    p++;
   }
   /*p now hopefully points at '\0'.*/
   while (p > s && isspace(*(p - 1))) {
    p--;
    *p = '\0';
   }
    return s;
}