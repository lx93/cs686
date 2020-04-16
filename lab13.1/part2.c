#include <stdio.h>

int main ( void ) {
	int array [10];
	int *array1 = array;
	int i;
	for (i = 0; i < 10; i ++) {
		array [ i ] = 0xbeef ;
		printf ("Just added beef to %p\n " , array + i );
	}
	printf (" Writing the number 1...\n ");
	*(array1 +4) = 0x01;
	printf (" All done !\n");
	return 0;
}
