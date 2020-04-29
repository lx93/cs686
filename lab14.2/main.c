#include <string.h>
#include <stdio.h>

typedef unsigned char bitmap8;

struct user {
    char username [50];
    char password [50];
    bitmap8 permissions ;
};

void grantPermission ( int bitIndex , struct user * user ) {
    bitmap8 mask = 0;
    if (bitIndex == 0) mask = 1;
    else if (bitIndex == 1) mask = 1<<1;
    else if (bitIndex == 2) mask = 0b100;
    user->permissions |= mask;
}
void revokePermission ( int bitIndex , struct user * user ) {
    bitmap8 mask = 0;
    if (bitIndex == 0) mask = 1;
    else if (bitIndex == 1) mask = 1<<1;
    else if (bitIndex == 2) mask = 1<<2;
    user->permissions &= ~mask;
}

int checkPermission ( int bitIndex , struct user * user ) {
    bitmap8 mask = 0;
    if (bitIndex==0) mask = 1;
    else if (bitIndex==1) mask = 1<<1;
    else if (bitIndex==2) mask = 1<<2;

    if (user->permissions & mask ){
        return 1;
    }
    else return 0;
}
void printPermissions ( struct user * user ) {
    if ( checkPermission (0 , user )) {
        printf ("%s has write permission .\n" , user -> username );
    }else {
        printf ("%s doesn't have write permission.\n" , user -> username );
    }
    if ( checkPermission (1 , user )) {
        printf ("%s has read permission .\n" , user -> username );
    }
    else {
        printf ("%s doesn 't have read permission .\n" , user -> username );
    }
    if ( checkPermission (2 , user )) {
        printf ("%s has execute permission.\n" , user -> username );
    }
    else {
        printf ("%s doesn 't have execute permission .\n " , user -> username );
    }
}


void setPermissions ( int new_permissions , struct user * user ) {
    user->permissions = new_permissions;
}




int main ( void ) {
    struct user user ;
    strcpy ( user . username , "vahab");
    strcpy ( user . password , "fgH!12");
    user . permissions = 0; // Sets the permissions to 0
    grantPermission (0 , & user );
    grantPermission (1 , & user );
    printPermissions (& user );
    revokePermission (1 , & user );
    grantPermission (2 , & user );
    printPermissions (& user );
    setPermissions(4,&user);
    printPermissions (& user );


    return 0;
}


