
#include <cstdio> 
#include <cmath>

//PAT���ƻ��� �������ػ�Ǯ  G=29*17 S=29  price=a1*G+b1*S+c1 ����һ���ǻ���ͳһ����С��λ����
//  sum/G*s : (sum%(G*S))/S : sum%S

const int G = 29 * 17;
const int S = 29;
void jingzhichange(){

	int a1, b1, c1, a2, b2, c2;
	scanf("%d.%d.%d %d.%d.%d", &a1, &b1, &c1, &a2, &b2, &c2);
	int price = a1*G + b1*S + c1;
	int money = a2*G + b2*S + c2;
	int change = money - price;//����С�ĵ�λ����ͳһ���ڼ���

	if (change < 0){//Ϊ���ŵĴ���   1���-��2ȡ�෴��Ϊ�����ֵ��Ϊ�����Ϳ��԰�����ǰ����������������
		printf("-");
		//change =(int)fabs((double)change);
		change = -change;
	}
	printf("%d.%d.%d\n", change / G, (change % G) / S, change%S);
}


int main(){
	jingzhichange(); 
	return 0;
}
