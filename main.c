/*
 * This is a simple password manager written in C.
 *
 * The basic features include the following:
 * 1. Generate a passphrase using given passwords
 * 2. Search for a passphrase using email/username
 *
 */

#include<stdio.h>
char * gen_random(int len) {
    static const char alphanum[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";

    char *s;
    for (int i = 0; i < len; i++) {
        s[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
    }

    return s;
}

void showMenu() {
    printf("\ng - generate a passphrase\ns - search for a passphrase\nq - quit\n");
}

int main(int argc, char*argv[]) {
    printf("Welcome to simple password manager!\n");
    char user_action;

    while (user_action != 'q') {
        showMenu();
        printf(">");
        user_action = getchar();

        if (user_action == 'g') {
            // generate a strong passphrase
            printf("Generating a passphrase of length 12...\n");
            char *passphrase = gen_random(12);

            printf("%s", passphrase);
        } else if (user_action == 's') {
            // search for a passphrase
            printf("search");
        } else if (user_action != 'q'){
            printf("Please enter a valid option!\n");
        }
    }

    return 0;
}
