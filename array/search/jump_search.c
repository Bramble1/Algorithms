#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<sys/param.h>
/*Jump search algorithm for sorted arrays. Similiar to linear search with exception that we alter the number of steps we're 
 * counting across the number line, so rationalising by 3, thus we're counting in sets of 3 as opposed to sets of 1.
 * We use this as a jump counter to essentially skip elements in the array in order to help find the key in a smaller 
 * number of steps by doing this.
 *
 *This algorithm is better than linear, but not as efficient as binary search.
 
	The steps to skip is determined by the square root of the length of the array, step size being m,
	then n/m as to rationalise and count in sets of m essentially.

	So perform the jumps until the value at that step is greater than the target value, if that's the case
       jump back to the previous position and perform a linear search from there, as we've exceeded the key value,
	so the logic is that the key would have to be inbetween the last jump for the range to exceed the key we're
 	searching for.	


	Jump search works well for arrays where the elements are in order and uniformly distributed, as it can jump to a closer position in the array with each iteration
 *
 *Worst case running time O(sqrt of N), because we're counting up in sets of sqrt of n
 *
 * */
int jump_search(int *array,int *x,int *n)
{
	//determine the number to rationalise the set by and thus count with
	int step=sqrt(*n);

	//perform jump search algoritmh
	int prev=0;
	while(array[(int)fmin(step,*n)-1] < *x)
	{
		prev=step;
		step+=sqrt(*n);
		if(prev>=*n)
			return -1;		
	}
	//perform a linear search between the last position and the one which exceeds the key, to then search for the key in
	//between
	while(array[prev]<*x)
	{
		prev++;

		if(prev==(int)fmin(step,*n))
			return -1;	
	}
	//element found otherwise
	if(array[prev]==*x)
		return prev;

	return -1;	
}



int main()
{	//only works with ordered sets remember, just like how binary only works with ordered sets
	int array[]={1,2,3,4,5,6,7};
	int x=6;
	int n = sizeof(array)/sizeof(array[0]);
	
	int index=jump_search(array,&x,&n);
		
	(index>=0) ? printf("Number is at %d index\n",index) : printf("Number does not exist in array\n");
	return 0;	
}



