
#include <cstdio> 
#include <cmath>

void triangleType(){
	int n,bottom;
	char c;
	scanf("%d %c",&n,&c);
	bottom = (int)sqrt(2.0*(n + 1)) - 1;
	if(bottom%2==0){
		bottom--;
	}
	int used = (bottom + 1)*(bottom + 1) / 2 - 1;
	//��ӡ�����ǣ�ǰ�ո����c����\n����iΪc�ĸ���  i[bottom:1:-2]
	for (int i = bottom; i>=1; i-=2){
		for (int j = 0; j < (bottom - i) / 2; j++){
			printf(" ");
		}
		for (int k = 0; k < i; k++){
			printf("%c", c);
		}
		printf("\n");
	}
	//��ӡ�����ǣ�i[3:bottom:2]
	for (int i = 3; i <=bottom; i+=2){
		for (int j = 0; j < (bottom - i) / 2; j++){
			printf(" ");
		}
		for (int k = 0; k < i; k++){
			printf("%c", c);
		}
		printf("\n");
	}
	//���ʣ�����
	printf("%d", n - used);
}


int main(){
	triangleType(); 
	return 0;
}
