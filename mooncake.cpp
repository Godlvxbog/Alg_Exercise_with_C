
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
//�±��������⣬��ν��̰�����⡣�������±��Ե��۴Ӹߵ�������ans+�±��ܼ�,����D�����±�������

struct Moock{
	double num;
	double sale;	
	double price;
}cake[1010];
//�Ƚ�ǰ׼��
bool cmp(Moock a, Moock b){
	return a.price > b.price;
}

void mooncake(){
	int n ;
	double D;
	scanf("%d %lf", &n,&D);
	for ( int i = 0; i < n; i++){
		scanf("%lf",&cake[i].num);
	}

	for (int i = 0; i < n; i++){
		scanf("%lf", &cake[i].sale);//����ĸ�ʽһ����%lf long float
		cake[i].price = cake[i].sale / cake[i].num;
	}
	sort(cake, cake + n, cmp);

	double ans=0.0;
	for (int i = 0; i < n; i++){
		if (cake[i].num <= D){
			ans += cake[i].sale;
			D -= cake[i].num;//�±�ÿ����һ�Σ�������Ҳ�ͼ�����һ��
		}
		else{
			ans += cake[i].price*D;
			break;//��ʱ�Ѿ������ѭ��
		}
	}

	printf("%.2lf", ans);

}

int main(){
	mooncake();
	return 0;
} 
