#include <stdio.h>

//PAT 3��ӡ�����Σ�
void lchartype(char c, int n){
	for (int i = 0; i < n; i++)
	{
		printf("%c", c);
	}
	printf("\n");
}

void schartype(char c, int n){
	printf("%c", c);
	for (int i = 1; i < n - 1; i++)
	{
		printf(" ");
	}
	printf("%c\n", c);
	
}
void typesqaretest(){//���ú����������ǰ�棬��Ȼ����ʾ�Ҳ�����ʶ��
	char c;
	int n,m;
	scanf("%d %c", &n,&c );
	if (n % 2 == 0){
		m = n / 2;
	}
	else{
		m = n / 2 + 1;
	}
	
	lchartype(c, n);
	for (int i =1; i < m-1; i++)
	{
		schartype(c, n);
	}

	lchartype(c, n);

}

int main(){
	typesqaretest();
	return 0;
} 
