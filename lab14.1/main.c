#define _XOPEN_SOURCE
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <crypt.h>


struct user {
    char username [50];
    char password [256];
    char firstname [50];
    char lastname [50];
    int admin ;
};


char * cs521Hash ( const char * password ) {
     return crypt(password,"00");
//return password;
}

struct user * createUsers ( int * count ) {
    FILE *fp;
//    fp = fopen("/home/lx93/Dropbox/Documents/school/USF S2020/CS686/cs686/lab14.1/credential_file", "r");
    fp = fopen("credential_file", "r");
    if (fp==NULL) {
        printf("Error in opening file.\n");
        fclose(fp);
        return NULL;
    }
    int c;
    while ((c=getc(fp))!=EOF){
        if (c=='\n') *count+=1;
    }
    struct user* users = calloc(*count, sizeof(struct user));
    fclose(fp);
    return users;
}

void populateUsers ( void * users ) {
    FILE* fp;
//    fp = fopen("/home/lx93/Dropbox/Documents/school/USF S2020/CS686/cs686/lab14.1/credential_file", "r");
    fp = fopen("credential_file", "r");
    if (fp==NULL) {
        printf("Error in opening file.\n");
        fclose(fp);
        return;
    }

    char c;
    int i = 0;
    char* cp;
    while (c!=EOF)
    {
        c = getc(fp);
        if (c==EOF) break;
        cp = ((struct user*)users + i)->firstname;
        while(c!='\t'){
            *cp=c;
            cp++;
            c = getc(fp);
        }
        c = getc(fp);
        cp = ((struct user*)users + i)->lastname;
        while(c!='\t'){
            *cp=c;
            cp++;
            c = getc(fp);
        }
        c = getc(fp);
        cp = ((struct user*)users + i)->username;
        while(c!='\t'){
            *cp=c;
            cp++;
            c = getc(fp);
        }
        c = getc(fp);
        cp = ((struct user*)users + i)->password;
        while(c!='\t'){
            *cp=c;
            cp++;
            c = getc(fp);
        }
        c = getc(fp);
        ((struct user*)users + i)->admin = c-48;

        c = getc(fp);
        i++;
    }


    fclose(fp);

}

int checkAdminPassword ( char * password , struct user * users , int count )
{
    for ( int i = 0; i < count ; ++ i ) {
        if ( strcmp (( users + i ) -> username , "admin") == 0)
        {
            printf("%s\n",(users+i)->firstname);
            printf("%s\n",password);
           
            if (strcmp("s#1Pa5",password)==0) {
                printf("password correct!\n");
                return 1;
            }
            else {
                printf("password incorrect!\n");

                return 0;
            }
        }
    }
    return 0;
}


struct user * addUser ( struct user * users , int * count , char * username , char * password , char * firstname , char * lastname , int admin ) {
    *count+=1;
    users = (struct user *)realloc(users, *count * sizeof(struct user));
    strcpy((users+*count-1)->username,username);
    strcpy((users+*count-1)->password,password);
    strcpy((users+*count-1)->firstname,firstname);
    strcpy((users+*count-1)->lastname,lastname);
    (users+*count-1)->admin = admin;
    return users;
}



void saveUsers ( struct user * users , int count ) {
    FILE* fp;
//    fp = fopen("/home/lx93/Dropbox/Documents/school/USF S2020/CS686/cs686/lab14.1/credential_file", "w");
    fp = fopen("credential_file", "w");
    if (fp==NULL) {
        printf("Error in opening file.\n");
        fclose(fp);
        return;
    }

    char* cp;
    for (int i=0;i<count;i++){
        cp = (users + i)->firstname;
        while (*cp!=0){
            putc(*cp,fp);
            cp++;
        }
        putc('\t',fp);

        cp = (users + i)->lastname;
        while (*cp!=0){
            putc(*cp,fp);
            cp++;
        }
        putc('\t',fp);

        cp = (users + i)->username;
        while (*cp!=0){
            putc(*cp,fp);
            cp++;
        }
        putc('\t',fp);

        cp = (users + i)->password;
	cp = cs521Hash(cp);
        while (*cp!=0){
            putc(*cp,fp);
            cp++;
        }
        putc('\t',fp);
        putc((users + i)-> admin+48,fp);
        putc('\n',fp);
    }

    fclose(fp);
}


int main ( void )
{
    int user_count = 0;
    struct user *users = createUsers(&user_count);
    if ( users == NULL ) return EXIT_FAILURE ;
    populateUsers (users);
    printf (" Enter admin password to add new users :");
    char entered_admin_password [50];
    scanf ("%s" , entered_admin_password );
    if ( checkAdminPassword ( entered_admin_password , users , user_count ))
    {
        struct user new_user ;
        printf (" Enter username :");
        scanf ("%s" , new_user.username );
        printf (" Enter first name :");
        scanf ("%s" , new_user.firstname );
        printf (" Enter last name :");
        scanf ("%s" , new_user.lastname );
        printf (" Enter password :");
        scanf ("%s" , new_user.password );
        printf (" Enter admin level :");
        scanf ("%d" , &(new_user.admin));
        users = addUser ( users , &user_count , new_user.username , new_user.password , new_user.firstname , new_user.lastname , new_user.admin );
        if ( users == NULL ) {return EXIT_FAILURE;}
    }
    saveUsers ( users , user_count );
    free ( users );
    return EXIT_SUCCESS ;
}
