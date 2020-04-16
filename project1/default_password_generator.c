#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool containsUsername(char* username,char* password, int i){
  if (password[i] != username[0]) return false;
  else
  { // if c is the same as first letter of username
      i++;
      bool contains = true;
      int j=1;
      while (j<strlen(username)){
        char charusername=username[j];
        char charpassword=password[i];
        if (charusername == charpassword){j++;i++;}
        else return false;
      }
      return true;
  }
}

bool isValidChar(char c){
  if (c<'0'||(c>'9'&&c<'A')||(c>'Z'&&c<'a')||c>'z'){
    printf("detected non-alphanumeric character");
    return false;
  }
  else return true;
}

bool isUpper(char c){
  if (c>='A'&&c<='Z') return true;
  else return false;
}

bool isLower(char c){
  if (c>='a'&&c<='z') return true;
  else return false;
}

bool isDigit(char c){
  if (c>='0'&&c<='9') return true;
  else return false;
}


bool isStrongPassword (char username[] , char* password){
  // check if password is at least 8 characters long
  if (strlen(password)<8){
    printf("Password is too short.\n");
    return false;
  }

  int consecutive = 0;
  bool hasUpper,hasLower,hasDigit = false;
  bool atLeastFourConsec = false;

  // iterate through every single char in password
  for (int i=0;i<strlen(password);i++){
    char c = password[i];

    if (containsUsername(username, password,i)){
      printf("password contains username. try again.\n");
      return false;
    }

    // check for invalid char
    if (!isValidChar(c)) return false;
    else if (isUpper(c)) {hasUpper = true; consecutive++;}
    else if (isLower(c)) {hasLower = true; consecutive++;}
    else if (isDigit(c)) {hasDigit=true; consecutive = 0;}

    if(consecutive>=4) atLeastFourConsec = true;
   }


  if (!hasUpper||!hasLower||!hasDigit) {
    printf("you need to have one upper one lower and one digit.\n");
    return false;
  }
  else if (!atLeastFourConsec) {
    printf("You need at least four consecutive letters.");
    return false;
  }

  else return true;
  
}
bool isStrongDefaultPassword (char username[] , char* password){
  // check if password is at least 8 characters long
  if (strlen(password)<8){
    return false;
  }

  bool hasUpper,hasLower,hasDigit = false;

  // iterate through every single char in password
  for (int i=0;i<strlen(password);i++){
    char c = password[i];

    if (containsUsername(username, password,i)){
      return false;
    }

    // check for invalid char
    if (!isValidChar(c)) return false;
    else if (isUpper(c)) hasUpper = true;
    else if (isLower(c)) hasLower = true;
    else if (isDigit(c)) hasDigit=true; 
   }

  if (!hasUpper||!hasLower||!hasDigit) {
    return false;
  }

  else return true;
  
}


void generateDefaultPassword(char default_password[], char username[]){
  printf("Generating a default password...\n");
  srand(time());
  int length = rand()%7+8; //random passworld length between 8 and 15
  for (int i=0;i<length;i++){
      char randChar = rand()%74+48;
      while (!isUpper(randChar)&!isLower(randChar)&!isDigit(randChar)){
        randChar = rand()%74+48;
      }
      default_password[i] = randChar;
  }
  if (isStrongDefaultPassword(username,default_password)){
      printf("Generated default password: %s\n",default_password);
  }
  else {
    while (!isStrongDefaultPassword(username,default_password)) {
      printf("The FAILED randomly generated default password is: %s\n",default_password);
      sleep(1); // sleep for a second so srand(time()) has a different seed
      generateDefaultPassword(default_password,username);
    }
  }
}


int main(void) {
  // Part 1
  char username[99];
  char password[99];
  bool secured = false;
  while (!secured){

    printf("Enter username: \n");
    scanf("%s",username);
    printf("Enter new password: \n");
    scanf("%s",password);
    if (!isStrongPassword(username,password)){
      printf("Your password is weak! Try again.\n"); 
    }
    else {
      printf("Strong password. %s\n",password);
      secured = true;
    }
  }

  printf("---------------------------------\n");

  // Part2
  char default_password[16] = "";
  generateDefaultPassword(default_password, username);

  return 0;
}
