/*
program:
https://www.geeksforgeeks.org/largest-rectangle-under-histogram/
*/

#include<stdio.h>
#include<string.h>
#include<stdarg.h>

int top=-1;
struct stack {
	int height;
	int index;
};

struct stack s[100]={0};

int main()
{
	//int bars[7]={6, 2, 5, 4, 5, 1, 6};
	//int bars[7]={1, 2, 3, 4, 5, 6, 7};
	int bars[7]={7,6,5,4,3,2,1};
	int n=7,i=0;
	int left,current_area=0,max_area=0;

	top=-1;
	for(i=0;i<=n;i++) {

		while(top>=0 && (i==n || s[top].height > bars[i])) {
			if(top>0) 
				left=s[top-1].index;
			else
				left=-1;
			current_area=(i-left-1)*s[top].height;
			top--;
			if(current_area >= max_area)
				max_area=current_area;

		}
		if(i<n)
		{
			top++;
			s[top].height=bars[i];
			s[top].index=i;
		}


	}
	printf("max area=%d\n",max_area);
	return 0;
}
