#include<cstdio>
#include<cstring>

//PAT a+b的部分和
long long bitjudge(long long a, long long da){
	long long pa = 0;
	while (a!=0){
		if (a%10==da){
			pa = pa * 10 + da;
		}
		a /= 10;//调整
	}
	return pa;
}


void bitNumAdd(){
	long long a, da, b, db;
	scanf("%lld %lld %lld %lld", &a, &da, &b, &db);
	long long pa = bitjudge(a, da);
	long long pb = bitjudge(b, db);
	printf("%lld", pa + pb);

}

int main(){
	
	bitNumAdd();
	return 0;
}
