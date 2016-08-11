#include <cstdio> 
void hejiu(){
	int n,a1,a2,b1,b2,failA=0,failB=0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d %d %d %d",&a1,&a2,&b1,&b2);
		if (a1 + b1 == a2&&a1 + b1!=b2){
			failB++;
		}
		if (a1 + b1 == b2&&a1 + b1 !=a2){
			failA++;
		}
	}
	printf("%d %d\n",failA,failB);
}

int main(){
	hejiu();
	return 0;
}
