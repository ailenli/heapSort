
#include <stdlib.h>
#include <stdio.h>
/*
自顶向下 构建子树
heapify，自顶向下，往下沉
*/
void swap(int *array,int a,int b)
{
	int temp = *(array+a);
	*(array+a) = *(array+b);
	*(array+b) = temp; 
}

void Heapify(int *array,int index,int heap_size)
{
	while(1)
	{
		int left = index*2 + 1;
		int right = index*2 + 2;
		int max = *(array+index);
		int max_position = index;
		if(left<heap_size && *(array+left)>max)
		{
			max = *(array+left);
			max_position = left;
		}
		if(right<heap_size && *(array + right)>max)
		{
			max = *(array + right);
			max_position = right;
		}

		if(max_position != index)//need swap
		{
			swap(array,index,max_position);
			index = max_position;
		}
		else//don`t need swap
		{
			break;
		}
	}
}
void buildHeap(int *array,int heap_size)
{
	int p = (heap_size)/2 - 1;
	for(int i=p;i>=0;i--)
	{
		Heapify(array,i,heap_size);
	}
}

int heapSort(int * array,int size)
{
	buildHeap(array,size);
	for(int i=size-1;i>0;i--)
	{
		swap(array,0,i);
		Heapify(array,0,i);
	}
	return 0;
}
int main(int argc, char const *argv[])
{
	int a[]={2,1,32,4,56,100,2};
	int size = sizeof(a)/sizeof(int);
	//printf("%d\n", size);
	heapSort(a,size);
	printf("size:%d\n", size);
	for(int i=0;i<size;i++)
	{
		printf("%d \n",a[i]);
	}
	printf("\n");
	return 0;
}

