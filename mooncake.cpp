
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
//月饼销售问题，所谓的贪心问题。。。对月饼以单价从高到低排序，ans+月饼总价,需求D减少月饼销售量

struct Moock{
	double num;
	double sale;	
	double price;
}cake[1010];
//比较前准备
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
		scanf("%lf", &cake[i].sale);//输入的格式一定是%lf long float
		cake[i].price = cake[i].sale / cake[i].num;
	}
	sort(cake, cake + n, cmp);

	double ans=0.0;
	for (int i = 0; i < n; i++){
		if (cake[i].num <= D){
			ans += cake[i].sale;
			D -= cake[i].num;//月饼每卖出一次，需求量也就减少了一次
		}
		else{
			ans += cake[i].price*D;
			break;//此时已经完成了循环
		}
	}

	printf("%.2lf", ans);

}

int main(){
	mooncake();
	return 0;
} 
