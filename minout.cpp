
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

//输出最小数

void minout(){
	int count[10];
	for (int i = 0; i < 10; i++){
		scanf("%d", &count[i]);
	}

	for (int i = 1; i < 10; i++){//因为本身其实是有序的  按照i来计算
		if (count[i]>0){
			printf("%d", i);
			count[i]--;//个数需要减少
			break;
		}
	}
	for (int i = 0; i < 10; i++){//打印出数字，10趟，每趟是第i个数，数字本身。
		for (int j = 0; j < count[i]; j++){//count[i]  一趟需要打印次数是count[i]
			printf("%d", i);
		}
	}
}

int main(){
	minout();
	return 0;
} 

