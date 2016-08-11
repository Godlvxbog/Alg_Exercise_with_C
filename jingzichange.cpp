
#include <cstdio> 
#include <cmath>

//PAT进制换算 哈利波特换钱  G=29*17 S=29  price=a1*G+b1*S+c1 计算一定是换成统一的最小单位计算
//  sum/G*s : (sum%(G*S))/S : sum%S

const int G = 29 * 17;
const int S = 29;
void jingzhichange(){

	int a1, b1, c1, a2, b2, c2;
	scanf("%d.%d.%d %d.%d.%d", &a1, &b1, &c1, &a2, &b2, &c2);
	int price = a1*G + b1*S + c1;
	int money = a2*G + b2*S + c2;
	int change = money - price;//以最小的单位进行统一，在计算

	if (change < 0){//为符号的处理   1输出-，2取相反数为或绝对值，为正，就可以按照以前的正的做法计算了
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
