#include <cstdio> 



int a7[10] = { 1, 9, 4, 3, 2, 7, 8, 0, 6, 5 };

//��������

//1ֻҪleft��right����ָ�벻��������ôָ��ֱ���temp�Ƚϣ�һ����ģ��ұߣ������ұߣ���ô������߻������Ҳ��ͬ
//����������ʱ�򣬾Ͱ�temp��������

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


