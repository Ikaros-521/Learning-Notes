
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define swap(a,b) {typeof(a) t=a;a=b;b=t;}

// 冒泡排序
void bubble_sort(int* arr,int len)
{
	for(int i=len-1; i>0; i--)
	{
		bool flag = true;
		for(int j=0; j<i; j++)
		{
			if(arr[j] > arr[j+1])
			{
				swap(arr[j],arr[j+1]);
				flag = false;
			}
		}
		if(flag) break;
	}
}

// 插入排序
void insert_sort(int* arr,int len)
{
	for(int i=1; i<len; i++)
	{
		int index = -1;
		int t = arr[i];
		for(int j=i-1; j>=0; j--)
		{
			if(t < arr[j])
			{
				arr[j+1] = arr[j];
				index = j;
			}
		}
		if(index != -1)
			arr[index] = t;
	}
}

// 选择排序
void select_sort(int* arr,int len)
{
	for(int i=len-1; i>0; i--)
	{
		int max = i;// 存储最大数的坐标
		for(int j=0; j<i; j++)
		{
			if(arr[j] > arr[max])
				max = j;
		}
		swap(arr[i],arr[max]);
	}
}

void _quick_sort(int* arr,size_t left,size_t right)
{
	if(left >= right) return;
	int pi = (left+right)/2; //计算标杆的下标
	int pv = arr[pi];    // 备份标杆的值
	int l = left, r = right;    // 备份左右下标
	while(l < r)    // 左右下标相遇时结束
	{
		while(l < pi && arr[l] <= pv) l++;	// 在标杆的左边寻找比它大的数据
		if(l < pi)	// 如果没有超出范围，说明找到比标杆大的值
		{
			arr[pi] = arr[l];	// 与标杆交换位置，并记录新的标杆下标
			pi = l;
		}
		while(pi < r && arr[r] >= pv) r--;	// 
		if(pi < r)	// 如果没有超出范围，说明找到比标杆小的值
		{
			arr[pi] = arr[r];
			pi = r;
		}
		arr[pi] = pv;    // 还原标杆的值
		if(pi-left > 1) _quick_sort(arr,left,pi-1);
		if(right-pi > 1) _quick_sort(arr,pi+1,right);

	}
}

// 快速排序
void quick_sort(int* arr,size_t len)
{
	_quick_sort(arr,0,len-1);
}

void create_heap(int* arr,size_t root,size_t len)
{
	if(root >= len) return;
	int left = root*2+1;
	int right = root*2+2;

	create_heap(arr,left,len);
	create_heap(arr,right,len);

	int max = root;
	if(left < len)
	{
		if(arr[left] > arr[max])
			max = left;
	}
	if(right < len)
	{
		if(arr[right] > arr[max])
			max = right;
	}
	if(max != root)
		swap(arr[max],arr[root]);
}

// 堆排序
void heap_sort(int* arr,size_t len)
{
	for(int i=0; i<len; i++)
	{
		create_heap(arr,0,len-i);
		swap(arr[0],arr[len-i-1]);
	}
	//show_arr(arr,10);
}

// 归并排序
void merge(int* arr,size_t left,size_t pi,size_t right,int* temp)
{
	int i = left,j = pi+1,k = left;
	// 外部合并 （临时变量是外部提供的）
	while(i<=pi && j<=right)
	{
		if(arr[i] < arr[j])
			temp[k++] = arr[i++];
		else
			temp[k++] = arr[j++];
	}
	while(i<=pi) temp[k++] = arr[i++];
	while(j<=right) temp[k++] = arr[j++];
	for(int i=left; i<=right; i++)
	{
		arr[i] = temp[i];
	}
}

void _merge_sort(int* arr,size_t left,size_t right,int* temp)
{
	if(left >= right) return;
	int pi = (left+right)/2;
	_merge_sort(arr,left,pi,temp);
	_merge_sort(arr,pi+1,right,temp);
	merge(arr,left,pi,right,temp);
}

void merge_sort(int* arr,size_t len)
{	// 把元素差分成1个个，然后标杆左右两侧进行2块2块的比较
	int temp[len];
	_merge_sort(arr,0,len-1,temp);
}

void show_arr(int* arr,size_t len)
{
	for(int i=0; i<len; i++)
	{
		printf("%d ",arr[i]);
	}
}

int main()
{
	int arr[10],arr1[10],arr2[10];
	for(int i=0; i<10; i++)
	{
		arr[i] = rand() % 50;
		arr1[i] = rand() % 50;
		arr2[i] = rand() % 50;
	}
	printf("原序列arr:");
	show_arr(arr,10);
/*
	printf("\n原序列arr1:");
	show_arr(arr1,10);

	printf("\n原序列arr2:");
	show_arr(arr2,10);
	printf("\n");

	printf("\n冒泡排序：");
	bubble_sort(arr,10);
	show_arr(arr,10);
	printf("\n插入排序：");
	insert_sort(arr1,10);
	show_arr(arr1,10);
	printf("\n选择排序：");
	select_sort(arr2,10);
	show_arr(arr2,10);

	quick_sort(arr2,10);
	show_arr(arr2,10);
*/

//	heap_sort(arr,10);
	merge_sort(arr,10);
	printf("\n");
	show_arr(arr,10);
}

