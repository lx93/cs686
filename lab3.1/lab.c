#include <stdio.h>

int sumOfArray(int arr[],int arrSize){
	printf("%lu\n",sizeof(arr));
	if (arrSize<12) return 0;
	int ans = arr[0]+arr[2];
	return ans;
}

int sumOfSubarray(int arr[],int startIndex, int endIndex){
	int sum=0;
	while (startIndex<=endIndex){
		sum+=arr[startIndex];
		startIndex++;
	}
	return sum;
}

void main(){
	int arr[6] = {1,-3,2,9,-2,10};
	int arrSize = sizeof(arr);
	printf("%d\n",arrSize);
	sumOfArray(arr,arrSize);
	sumOfSubarray(arr,1,3);
}
