
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

//�����С��

void minout(){
	int count[10];
	for (int i = 0; i < 10; i++){
		scanf("%d", &count[i]);
	}

	for (int i = 1; i < 10; i++){//��Ϊ������ʵ�������  ����i������
		if (count[i]>0){
			printf("%d", i);
			count[i]--;//������Ҫ����
			break;
		}
	}
	for (int i = 0; i < 10; i++){//��ӡ�����֣�10�ˣ�ÿ���ǵ�i���������ֱ���
		for (int j = 0; j < count[i]; j++){//count[i]  һ����Ҫ��ӡ������count[i]
			printf("%d", i);
		}
	}
}

int main(){
	minout();
	return 0;
} 

