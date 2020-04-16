#include <time.h>
#include <stdio.h>

const unsigned short int correct_short = -1;
const unsigned int correct = -1;
const unsigned long correct_long = -1;
	
void testShort() {
	clock_t start , end;
	start = clock ();

	unsigned short int upperbound = -1;
	unsigned int guess = 0;
	while (guess<upperbound){
		guess++;
		if (guess==correct_short){
			printf("the correct password is %d\n",guess);
			break;
		}
	}

	end = clock ();
	float seconds = ( float )( end - start ) / CLOCKS_PER_SEC ;
	printf (" It took % f to guess an unsigned short int password.\n" , seconds );


}



void test() {
	clock_t start , end;
	start = clock ();

	unsigned int upperbound = -1;
	unsigned int guess = 0;
	while (guess<upperbound){
		guess++;
		if (guess==correct){
			printf("the correct password is %u\n",guess);
			break;
		}
	}

	end = clock ();
	float seconds = ( float )( end - start ) / CLOCKS_PER_SEC ;

	printf (" It took % f to guess an unsigned int password.\n" , seconds );
}


void testLong() {
	clock_t start , end;
	start = clock ();

	unsigned int upperbound = -1;
	int guess = 0;
	while (guess<upperbound){
		guess++;
		if (guess==correct){
			printf("the correct password is %d\n",guess);
			break;
		}
	}

	end = clock ();
	float seconds = ( float )( end - start ) / CLOCKS_PER_SEC ;

	printf (" It took % f to guess an unsigned int password.\n" , seconds );
}


void main(){
	testShort();
	test();
}
