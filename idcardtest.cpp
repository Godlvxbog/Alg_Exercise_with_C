#include <cstdio> 
#include <cmath> 
#include <cstring> 
#include <string>//��ʹ��string 
using namespace std;
void idcardtest(){
	int n,sum=0,j=0;
	char str[20];//����ʱ���ܽ��г�ʼ����
	//string s[110];
//	int m=0;
	
	 
	scanf("%d",&n);//ע�⴫�����c ������c-'0';

	int w[20] = { 7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2 };
	char jh[15] = { '1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2' };

	bool flag = true;

	for (int i = 0; i < n; i++){//��ѭ���������ݾ�ֻ�����һ����
		scanf("%s", str);
		for (j = 0; j < 17; j++){
			if (str[j]<='0'&&str[j]>='9'){//���䲹������Ϊ�����ж��֣����Ǵ���ʽ��һ��
				flag = false;
				printf("%s\n", str);
				break;//�����;�������룬������ֱ������ѭ������ʱ�����Ĳ�ͬ��  j<16;
			}
			sum += w[j] * (str[j] - '0');//��ȷ��ֻ��һ��  			
		}
		if (j < 16){
			flag = false;
			//s[m++]=str;
			printf("%s\n", str);
		}
		else if (jh[sum % 11]!=str[17]){
			flag = false;
			//s[m++]=str;
			printf("%s\n", str);
		}
	}
//	for(int k=0;k<m;k++){
//		printf("%s\n",s[k]);
//	}
	if (flag){
		printf("All passed\n");
	}
}

int main(){
	idcardtest(); 
	return 0;
}
