#include <string.h>
#include <stdio.h>
#include <stdlib.h>
char * copyStr ( const char * s ) {
	char * dst = ( char *) malloc ( sizeof ( char ) * strlen ( s ) + 1);
	if ( dst != NULL ) {
		for ( int i = 0; i < strlen (s) + 1; ++i ) {
			*(dst + i ) = *( s + i);
		}
	}
	return dst ;
}

int main ( void ) {
	char str [] = " test ";
	printf ("1. %s \n " , str );
	char * str1 = copyStr (str);
	printf ("2. %s \n " , str1);
	free ( str1 );
	return 0;
}
