#include <cstdio> 
#include <cmath>
//ö�ٷ����չ涨��ʽ���������1���õ�����λ���֣���������洢����a[i]=sum%10,sum/10��

//ö�ٷ����չ涨��ʽ���������1���õ�����λ���֣���������洢����a[i]=sum%10,sum/10��

void formatNum(){
	int n, a[10] , num = 0;
	//memset(a,0,sizeof(a));
	scanf("%d", &n);
	while (n!=0){
		a[num++] = n % 10;
		n /= 10;
	}
	for (int k= num-1; k >=0; k--){//�������飬�ϸ�������  kΪλ��
		if (k == 2){//��λ
			for (int i = a[k]; i > 0; i--){
				printf("B");
			}
		}
		else if (k==1){//ʮλ
			for (int i = a[k]; i>0; i--){
				printf("S");
			}
		}
		else if (k==0){
			for (int i = 1; i <= a[k]; i++)
			{
				printf("%d", i);
			}
		}
	}
}

int main(){
	formatNum(); 
	return 0;
}
