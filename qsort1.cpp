#include <cstdio> 



int a7[10] = { 1, 9, 4, 3, 2, 7, 8, 0, 6, 5 };

//快速排序

//1只要left和right两个指针不相遇，那么指针分别于temp比较，一旦大的（右边）不在右边，那么就与左边换；左边也相同
//当两个相遇时候，就把temp插入其中

int partion(int a[], int left, int right){
	int temp = a[left];
	while (left<right){
		while (left<right&&a[right]>temp)
		{
			right--;
		}
		a[left] = a[right];
		while (left<right&& a[left]<temp)
		{
			left++;
		}
		a[right]=a[left];
	}
	a[left] = temp;
	return left;
}

void qsort1(int a[], int left, int right){
	int pos = partion(a, left,right);
	qsort1(a,left,pos-1);
	qsort1(a, pos + 1,right);
}

int main(){
	qsort1(a7,0,9);
	return 0;	
}


