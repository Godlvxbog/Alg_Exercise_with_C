
#include <cstdio> 
void arrayMoveR(){
	int n, m,a[110],count=0;
	
	scanf("%d %d",&n,&m);
	m=m%n;
	for (int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	for (int i = n - m; i < n; i++){
		printf("%d", a[i]);
		count++;
		if (count < n){
			printf(" ");
		}
		
	}
	for (int i = 0; i < n-m; i++)
	{
		printf("%d", a[i]);
		count++;
		if (count < n){
			printf(" ");
		}
		
	}
}
int main(){
	arrayMoveR();
	return 0;
}



