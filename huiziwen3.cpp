#include<cstdio>
#include<cstring>
//PAT:回字文
bool hzwjudge(char str[]){
	int n = strlen(str);
	for (int i = 0; i < n/2; i++){
		if (str[i]!=str[n-1-i]){
			return false;
		}
	}
}


const int maxn = 256;
char str[maxn];
void huiziwen(){
	while (gets(str))//多次输入str
	{
		bool flag=1;
		flag = hzwjudge(str);
		if (flag==true){
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}
	}
}

int main(){
	huiziwen();
	return 0;
}
