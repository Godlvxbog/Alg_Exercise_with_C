#include <cstdio> 

//试座号作为键，去找，考试号和准考证，为值，
struct  STU{
	long long id;
	int ksnum;
};
const int maxn2 = 1010;
STU stu[maxn2];

void jian2zhichazao(){
	int n;
	scanf("%d", &n);
	long long id;
	int csnum, ksnum;
	for (int i = 0; i < n; i++){
		scanf("%lld %d %d", &id, &csnum, &ksnum);
		stu[csnum].id = id;
		stu[csnum].ksnum = ksnum;
	}
	int m;
	scanf("%d",&m);
	for (int i = 0; i < m; i++){
		scanf("%d", &csnum);
		printf("%lld %d\n", stu[csnum].id, stu[csnum].ksnum);
	}
}


int main(){
	jian2zhichazao(); 
	return 0;
}
