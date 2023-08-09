#include<stdio.h>

/*O(n) worst case running time, same as normal linear search, However this algorithm places the key at the end of the array
 * and swaps out the last element of the array to do so, thus we iterate through and compare to this bastion key at the end and
 * this apparently results in one less checking step for making sure we're in bounds of the array and making sure we're not attempting
 * to access out of bounds memory.*/

void sentinelSearch(int *array,int *size,int *key)
{
	//1.store last element of array
	int last = array[*size-1];
	
	//2. replace the last element with our key to subject for comparison
	int i=0;
	array[*size-1]= *key;

	//3.iterate through adjacent elements and perform comparison against sentinel,notice the lack of checking to see we're in bounds
	//However this doesn't really change much at all compared to normal linear search, as the out of bounds check just becomes the key
	//so I don't see much point in really using this algorithm...
	while(array[i]!=*key)
	{
		i++;
	}

	//4. place the last element back
	array[*size-1]=last;

	//5. optional check here
	if((i<*size-1) || (array[*size-1]==*key))
	{
		printf("key found at index:%d\n",i);
	}
	else
	{
		printf("key not found.\n");
	}	
	

}


int main()
{
	int array[] = {2,4,6,8,10};
	int size=5;
	int key=6;
	sentinelSearch(array,&size,&key);
	return 0;
}
