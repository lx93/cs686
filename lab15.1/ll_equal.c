#include <stdio.h>
#include <string.h>

typedef struct user {
    char username[50];
    char password[50];
    int admin;
    struct user *next;
} userInfo;

/* FIXME: this function is buggy. */
int ll_equal(const userInfo* a, const userInfo* b) {
    while (a != NULL && b!=NULL) {
        if (a->admin != b->admin)
            return 0;
        if(strcmp(a->username, b->username) != 0) {
            return 0;
        }
        if(strcmp(a->password, b->password) != 0) {
            return 0;
        }
        a = a->next;
        b = b->next;
    }
    /* lists are equal if a and b are both null */
    return a == b;
}

int main(int argc, char** argv) {
    int i;
    userInfo users[10];

    for (i=0; i<10; i++) {
        strcpy(users[i].username, "user");
        strcpy(users[i].password, "password");
        users[i].admin = 0;
        users[i].next = NULL;
    }

    users[0].next = &users[1];
    users[1].next = &users[2];
    users[2].next = &users[3];

    printf("equal test 1 result = %d\n", ll_equal(&users[0], &users[0]));
    printf("equal test 2 result = %d\n", ll_equal(&users[0], &users[2]));

    return 0;
}
