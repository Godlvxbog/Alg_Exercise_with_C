#include <stdio.h> 
#include <string.h>

void getstest(){
	char a[20][20];
	for(int i=0;i<3;i++){
		gets(a[i]);
		
	}
	for(int i=0;i<3;i++){
		puts(a[i]);
		int n = strlen(a[i]);
		printf("%d", n);
		
	}
	
}

void strlentest(){
	char a[20];
	gets(a);		
	int len=strlen(a);
	printf("%d",len);
}

void strcmptest(){
	char str1[20],str2[20];
	gets(str1);
	gets(str2);
	int result=strcmp(str1,str2);
	printf("%d",result);
}

void strcpytest(){
	char str1[20],str2[20];
	gets(str2);
	strcpy(str1,str2);
	puts(str1);
}

void sscanftest(){
	char str1[20],str2[20]="123";
	int num;
	sscanf(str2,"%d",&num);//输入到n，n是目标 
	printf("%d",num);
}

int main(){
	//getstest();
	//strlentest();
	
	//strcmptest();
	
	
	//strcpytest();
	
	sscanftest();
	getchar(); 
	return 0;
	
}
