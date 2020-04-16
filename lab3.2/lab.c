# include <stdio.h>
# include <stdbool.h>

extern bool isLower(char c){
	if (c>=97&&c<=122){
		printf("%c is lower\n",c);
		return true;
	}
	printf("%c is not lower\n",c);
	return false;
}
extern bool isUpper(char c){

	if (c>=65&&c<=90){
		printf("%c is upper\n",c);
		return true;
	}
	
	printf("%c is not upper\n",c);
	return false;
}
extern bool isDigit(char c){

	if (c>='0'&&c<='9'){
		printf("%c is digit\n",c);
		return true;
	}
	
	printf("%c is not digit\n",c);
	return false;
}



void main(){
	printf("Please enter a character: ");
	char entry;
	scanf("%c", &entry);
	isLower(entry);
	isUpper(entry);
	isDigit(entry);
}
