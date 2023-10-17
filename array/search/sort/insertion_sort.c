#include<stdio.h>

/*Selection we yust compare the adyacent value and compare to the prior
 * and then perform comparison/swap instructions etc if required
 * worst case number of steps for algorithm is n*n=n^2, thus
 * if used, must be performed on a small dataset n */

void insertion_sort(int arr[],int n)
{
	int key; int y;

	for(int i=1;i<n;i++)
	{
		key=arr[i];
		y=i-1;

		//if > key, then move to one position ahead
		//of their current position
		while(y>=0 && arr[y]>key)
		{
			arr[y+1]=arr[y];
			y-=1;
		}
		arr[y+1]=key;
	}
}

int main()
{
	int arr[]={12,11,13,5,6};
	int n=sizeof(arr)/sizeof(arr[0]);

	insertion_sort(arr,n);

	for(int i=0;i<n;i++)
		printf("%d\t",arr[i]);
	printf("\n");
	return 0;
}
