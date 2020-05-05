#include <stdio.h>
#include <string.h>

typedef struct user {
    char username[50];
    char password[50];
    int admin;
    struct user *next;
} userInfo;

int ll_has_cycle(userInfo *head) {
    userInfo* trav1 = head;
    userInfo* trav2 = head;

    while (trav2!=NULL){
        trav2 = trav2->next->next;
        trav1 = trav1->next;
        if (trav1==trav2) return 1;
    }
    return 0;

}

void test_ll_has_cycle(void) {
    int i;
    userInfo users[25]; //enough to run our tests
    for(i=0; i < sizeof(users)/sizeof(userInfo); i++) {
        users[i].next = 0;
        strcpy(users[i].username, "user");
        strcpy(users[i].password, "password");
        users[i].admin = 0;
    }

    users[0].next = &users[1];
    users[1].next = &users[2];
    users[2].next = &users[3];
    printf("Checking first list for cycles. There should be none, ll_has_cycle says it has %s cycle\n", ll_has_cycle(&users[0])?"a":"no");

    users[4].next = &users[5];
    users[5].next = &users[6];
    users[6].next = &users[7];
    users[7].next = &users[8];
    users[8].next = &users[9];
    users[9].next = &users[10];
    users[10].next = &users[4];
    printf("Checking second list for cycles. There should be a cycle, ll_has_cycle says it has %s cycle\n", ll_has_cycle(&users[4])?"a":"no");

    users[11].next = &users[12];
    users[12].next = &users[13];
    users[13].next = &users[14];
    users[14].next = &users[15];
    users[15].next = &users[16];
    users[16].next = &users[17];
    users[17].next = &users[14];
    printf("Checking third list for cycles. There should be a cycle, ll_has_cycle says it has %s cycle\n", ll_has_cycle(&users[11])?"a":"no");

    users[18].next = &users[18];
    printf("Checking fourth list for cycles. There should be a cycle, ll_has_cycle says it has %s cycle\n", ll_has_cycle(&users[18])?"a":"no");

    users[19].next = &users[20];
    users[20].next = &users[21];
    users[21].next = &users[22];
    users[22].next = &users[23];
    printf("Checking fifth list for cycles. There should be none, ll_has_cycle says it has %s cycle\n", ll_has_cycle(&users[19])?"a":"no");

    printf("Checking length-zero list for cycles. There should be none, ll_has_cycle says it has %s cycle\n", ll_has_cycle(NULL)?"a":"no");
}

int main(void) {
    test_ll_has_cycle();
    return 0;
}
