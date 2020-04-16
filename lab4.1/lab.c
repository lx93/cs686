#include <stdio.h>
#include <stdbool.h>

bool doesContainDigit(char str[]){
    for (int i=0;i< sizeof(str);i++){
        if (str[i]=='\0'){
            break;
        } else if (str[i]>='0'&&str[i]<='9') {
            printf("the string contains digits.\n");
            return true;
        }
    }
    printf("the string does not contain any digit.\n");
    return false;
}

bool doesContainOneDigit(char str[]){
    int digitCount = 0;
    for (int i=0;i< sizeof(str);i++){
        if (str[i]=='\0'){
            break;
        } else if (str[i]>='0'&&str[i]<='9') {
            digitCount ++;
        }
    }

    if (digitCount == 0 ){
        printf("the string does not contain any digit.\n");
        printf("The string does not contain only one digit.\n");
    } else if (digitCount == 1) {
        printf("The string contains digits.\nThe string contains only one digit.\n");
        return true;
    } else {
        printf("The string contains digits.\nThe string does not contain only one digit.\n");
    }
    return false;
}

void stringToInt(char str[]){
	int num = 0;
	for (itn i=sizeof(str);i>=0;i--){
		if (str[i]=='\0') break;
		int power = 1;
		for (int ii=0;ii<i;ii++){
			power = power * 10;
		}
		num+=str[i]*power;
	}
	printf(%d,num);
}


int main() {
    printf("Enter a string\n");
    char str[100];
    scanf("%s",str);
    doesContainOneDigit(str);
}

	if (c>=97&&c<=122){
		printf("is lower");
		return true;
	}
	return false;
