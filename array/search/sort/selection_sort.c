//Selection sort has a worst number of steps being n^2, due to the inner
//loop of the algorithm, thus same with bubble sort, that this is best
//used on smaller data sets, thus when n^2 resulting in not to high
//of a number of steps in the algorithm required.



#include<stdio.h>

void swap(int *x,int *y)
{
	int temp = *x;*x=*y; *y=temp;
}

//then output sorted array
void selection_sort(int arr[],int n)
{
	int min;

	//compare each element to each in the list, to
	//perform comparison and switch instruction, thus
	//n^2
	for(int i=0;i<n;i++)
	{
		min=i;
		for(int y=i+1;y<n;y++)
			if(arr[y]<arr[min])
				min=y;

		if(!min==i)
			swap(&arr[min],&arr[i]);
	}
}

int main()
{
	int arr[] = {64,25,12,22,11};
	int n = sizeof(arr)/sizeof(arr[0]);
	selection_sort(arr,n);

	for(int i=0;i<n;i++)
		printf("%d\t",arr[i]);
	printf("\n");

	return 0;
}
