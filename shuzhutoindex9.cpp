#include <cstdio> 
#include <cmath> 
#include <cstring> 
//count[str[i]]++,����Ҳ�Ǳ���,ͳ��1��λ��

void tongjisuzhu(){
	char str[1010];
	gets(str);
	int len = strlen(str);//str[i]���Եõ���������
	int count[20] = {0};
	for (int i = 0; i < len;i++){
		int bit = str[i]-'0';//������λ  ��Ҫת��Ϊ���֣���ǰstr[i]��char������
		count[bit]++;//����
	}
	for (int j = 0; j < 10;j++){//ö��10��
		if (count[j]!=0){
			printf("%d:%d\n", j, count[j]);
		}
	}
}

int main(){
	tongjisuzhu(); 
	return 0;
}
