#include<stdio.h>

/*Bubble sort algorithm, has a worst case, total number of steps of n^2
 * as we iterate through each element of n, and then take that element
 * and iterate through the data set each time with this algorithm
 * thus ending up with a total number of n*n steps.
 *
 *Thus slow with larger data sets, so if this is used, will need to make sure that n is small, thus n^2 doesn't result
 in a significant number of steps for the alogrithm.
 *
 * */

void swap(int *x, int *y)
{
	int temp=*x;
	*x=*y;
	*y=temp;
}

void bubble_sort(int arr[],int n)
{
	int swapped;
	for(int i=0;i<n;i++)
	{
		swapped=0;
		/*start at the offset of arr[i],thus can
		 * reduce the loop as we're using i as offset,looping through n times, and making sure,each
		 * iteration, we reduce the number of iterations in the inner loop each time, as in each loop
		 * we assumedly placed the swapped element to the end, thus then need to re-iterate again,making
		 * sure to not swap the prior element out, and work on the rest of the unordered items.*/
		for(int y=0;y<n-i;y++)
		{
			if(arr[y]>arr[y+1])
			{
				swap(&arr[y],&arr[y+1]);
				swapped=1;
			}
		}

		//if no elements swapped , we break out
		if(swapped==0)
			break;
	}
}

int main()
{
	int arr[] = {64,34,25,12,22,11,90};
	int n = sizeof(arr) / sizeof(arr[0]);
	bubble_sort(arr,n);

	for(int i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	
	return 0;
}
