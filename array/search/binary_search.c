#include<stdio.h>
#include<stdlib.h>

/*binary search, recursive division essentially, divide the array, and compare to the key, depending
 * on > or < is the deciding factor of which divided section to narrow our search down to and repeat 2^-x times exponetial
 * inverse, this log(n) it gets faster each time ,beacuse of this recursive splitting of the array*/
/*Only works with sorted arrays, thus less numbers to operate over and perform comparison,thus less steps
 * in the algorithm which is what we want to achieve overall*/

int binary_search(int *array,int *l,int *r,int *x)
{
	//seems to break at start of comparison here
	
	while(*l<=*r)
	{
		int m = *l + (*r-*l) * 0.5; 	//instead of '/' just * against hardcoded value , thus less step for
						//the cpu to perform by having a hardcoded rational number
		//check if x is present at middle
		if(array[m]==*x)
			return m;
		else if(array[m]<*x)
			*l = m+1;			//if x is greater, than mid then ignore left side of division
		else
			*r = m-1; 		//ignore the right side	
	}

	//couldn't find it
	return -1;
}

int binary_search_recursive(int *array,int *l,int *r,int *x)
{
	if(*r>=*l)
	{
		int mid = *l + (*r-*l) * 0.5; int tmp;

		if(array[mid]==*x)
			return mid;
		else if(array[mid]<*x){
			tmp=mid-1;
			return binary_search_recursive(array,&tmp,r,x);
		}
		else{
			tmp=mid+1;	//extra operations here
			return binary_search_recursive(array,l,&tmp,x);
		}
	}

	return -1;
}

int main()
{
	int array[] = {1,3,5,7,9,11};
	int n = sizeof(array)/sizeof(array[0]);
	int x = 7;
	int l=0;
	int r=n-1;
	int result=binary_search(array,&l,&r,&x);

	//test case
	(result==-1) ? printf("Element does not exist in array.\n") : printf("Element exists at index %d.\n",result);

	//test case 2
	result = binary_search_recursive(array,&l,&r,&x);
	(result==-1) ? printf("Element does not exist in array.\n") : printf("Element exists in array index=%d\n",result);
		
	return 0;
}

