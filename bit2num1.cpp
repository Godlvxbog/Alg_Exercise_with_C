#include <cstdio> 
#include <cstring> 

//λ--������--��λ��str[i]-'0',����ȡ�࣬bit[num++]���棬Ȼ�������i=[num-1,0:1],if(i>0) ��ӡ�� �� else��ӡ��\n��
char strNum[110];
int sumNum[10];
//ע�������Ӧ���á������ַ����� ���ǡ������ַ���
char change1[10][5] = { "ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu" };
void bit2num(){
	int sum=0,j=0;
	gets(strNum);//���������ڸ�ֵ
	int len = strlen(strNum);
	for ( int i = 0; i < len; i++){
		sum += strNum[i] - '0';
	}
	while (sum!=0){
		sumNum[j++] = sum % 10;
		sum /= 10;
	}
	for (int k = j-1; k >=0 ;k--){
		int index = sumNum[k];
		printf("%s", change1[index]);
		if (k>0){
			printf(" ");
		}
		else{
			printf("\n");
		}
	}
}

int main(){
	bit2num();
	return 0;
	
}
