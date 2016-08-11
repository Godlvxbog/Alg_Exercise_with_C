#include <stdio.h>
#include <math.h>
#include <string>
#include <cstring>

//下面是PAT的练习题目1

void countCalazNum(){
	int n,count=0;
	scanf_s("%d", &n);
	while (n != 1){//n < 1000 && 不要自作多情限制n
		if (n%2==0)
		{
			n /= 2;
		}
		else{
			n =(n* 3 + 1)/2;
		}
		count++;
	}
	printf(" %d", count);//不要随便打印输出，一切按照输出格式来
}

//分类是s[i]求和，并且求出s中最大值
//输入，类别号，及分数
//1，分别求和，2求最大值

const int stuNum = 100000;
int school[stuNum] = { 0 };//这个应该放在外面，否则扣分，main中不能申请过大的内存，10^5要敏感
void fenleiAdd(){
	
	int n, schNum, score;
	scanf_s("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf_s("%d %d", &schNum, &score);
		school[schNum] += score;

	}
	int max = -1,k;
	for (int i = 0; i < n; i++)
	{
		if (max<school[i]){
			max = school[i];
			k = i;
		}

	}
	printf("%d %d", k, max);

}

void chazaotest(){
	int n,num[200];
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++){//存入数据到数组
		scanf_s("%d",&num[i]);
	}
	int m,k=0;
	scanf_s("%d", &m);
	for (k = 0; k < n; k++){//查找=1，if，2返回
		if (m==num[k])
		{
			printf("%d", k);
			break;//找到了就跳出循环
		}
	}
	//如果没有即为 n==i
	if (k == n){
		printf("-1\n");
	}
	
}

//PAT 3打印正方形：
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
void typesqaretest(){//调用函数必须放在前面，不然会提示找不到标识符
	char c;
	int n,m;
	scanf_s("%d %c", &n,&c );
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

//PAT 进制转换

void jzchange(){
	int a, b, d,sum=0;
	scanf_s("%d %d %d",&a,&b,&d);
	sum = a + b;
	int ans[31];
	int n = 0;
	do{		
		ans[n] = sum%d;//接收容器
		sum /= d;
		n++;//接收容器索引增加

	} while (sum!=0);

	for (int i = n-1; i>=0; i--)
	{
		printf("%d", ans[i]);
	}
}


//PAT练习:回字文
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
	while (gets_s(str))//多次输入str
	{
		bool flag = hzwjudge(str);
		if (flag){
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}
	}
}

//PAT说反话
char word[100][100];
void suofanhua(){
	int num=0;
	while (scanf_s("%s",word[num])!=EOF)//多次读入到数组word[],word[num]不用&
	{
		num++;
	}
	for (int i = num-1; i >= 0; i--)
	{
		printf("%s",word[i]);
	}
}

//PAT大数判断A+B>C吗？

void judgeABC(){
	int T,tcase=1;
	long long a, b, c;//考察点：大数操作可能越界
	scanf_s("%d", &T);
	int rz[20],j=0;
	while (T--){
		scanf_s("%lld%lld%lld",&a,&b,&c);
		if (a + b > c){
			rz[j++] = true;
		}
		else
		{
			rz[j++] =false;
			//printf("Case#%d:false", tcase);
		}
	}
	int i = 0;
	for (i = 0; i < j; i++)
	{
		if (rz[i]==true){
			printf("Case#%d:true\n", i);
		}
		else{
			printf("Case#%d:false\n", i);
		}
	}
}

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
	scanf_s("%lld %lld %lld %lld", &a, &da, &b, &db);
	long long pa = bitjudge(a, da);
	long long pb = bitjudge(b, db);
	printf("%lld", pa + pb);

}

//PAT  程序运行时间

void calctime(){
	int c1, c2,ans;
	scanf_s("%d %d", &c1, &c2); 
	ans = c2 - c1;
	if (ans % 100 >= 50){
		ans = ans / 100 + 1;
	}
	else{
		ans = ans / 100;//得到秒数
	}

	printf("%d:%d:%d", ans / 3600, (ans % 3600) / 60, ans % 60);


}


//PAT 喝酒划拳

void hejiu(){
	int n,a1,a2,b1,b2,failA=0,failB=0;
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++){
		scanf_s("%d %d %d %d",&a1,&a2,&b1,&b2);
		if (a1 + b1 == a2&&a1 + b1!=b2){
			failB++;
		}
		if (a1 + b1 == b2&&a1 + b1 !=a2){
			failA++;
		}
	}
	printf("%d %d\n",failA,failB);
}

void arrayMoveR(){
	int n, m,a[50],count=0;
	scanf_s("%d %d",&n,&m);
	for (int i = 0; i < n; i++){
		scanf_s("%d", &a[i]);
	}
	for (int i = n - m; i < n; i++){
		printf("%d", a[i]);
		if (count < n){
			printf(" ");
		}
		count++;
	}
	for (int i = 0; i < n-m; i++)
	{
		printf("%d", a[i]);
		if (count < n){
			printf(" ");
		}
		count++;
	}
	

}

//求倒数
void qiudao(){
	int a[1000],k,e,count=0;
	while (scanf_s("%d %d",&k,&e)){
		a[e] = k;
	}
	for (int i = 0; i < 1000; i++)
	{
		a[i - 1] = a[i] * i;
		a[i] = 0;
		if (a[i]!=0){
			count++;
		}
	}

	for (int i = 1000; i >= 0; i--)
	{
		if (a[i] != 0){
			printf("%d &d", a[i], i);
			count--;
			if (count>0){
				printf(" ");
			}
		}		
	}
}

//试座号作为键，去找，考试号和准考证，为值，
struct  STU{
	long long id;
	int ksnum;
};
const int maxn2 = 1010;
STU stu[maxn2];

void jian2zhichazao(){
	int n;
	scanf_s("%d", &n);
	long long id;
	int csnum, ksnum;
	for (int i = 0; i < n; i++){
		scanf_s("%lld %d %d", &id, &csnum, &ksnum);
		stu[csnum].id = id;
		stu[csnum].ksnum = ksnum;
	}
	int m;
	scanf_s("%d",&m);
	for (int i = 0; i < m; i++){
		scanf_s("%d", &csnum);
		printf("%lld %d\n", stu[csnum].id, stu[csnum].ksnum);
	}
}

//求结构体，s数组中某个属性的最值
const int length = 20;
struct STUD{
	char name[length];
	char id[length];
	int score;
};
STUD s_temp,s_min,s_max;//声明三个学生,其中s_temp（可变的）用来scanf传输数据

//重要，求最大值只需要，1max初始化，2for获取临时可变的对象

void structmax(){
	s_min.score = 101;//一定不是最小的数
	s_max.score = -1;//一定不是最z最大的数，所以一定一开始就会进入判断语句
	int n;
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++){
		scanf_s("%s %s %d",s_temp.name,s_temp.id,&s_temp.score);
		if (s_temp.score<s_min.score){
			s_min.score = s_temp.score;
		}
		if (s_temp.score>s_max.score){
			s_max.score = s_temp.score;
		}

	}
	printf("%s %s", s_max.name, s_max.id);
	printf("%s %s", s_min.name, s_min.id);

}

void triangleType(){
	int n,bottom;
	char c;
	scanf_s("%d %c",&n,&c);
	bottom = (int)sqrt(2.0*(n + 1)) - 1;
	int used = (bottom + 1)*(bottom + 1) / 2 - 1;
	//打印倒三角：前空格加上c，再\n，设i为c的个数  i[bottom:1:-2]
	for (int i = bottom; i>=1; i-=2){
		for (int j = 0; j < (bottom - i) / 2; j++){
			printf(" ");
		}
		for (int k = 0; k < i; k++){
			printf("%c", c);
		}
		printf("\n");
	}
	//打印正三角：i[3:bottom:2]
	for (int i = 3; i <=bottom; i+=2){
		for (int j = 0; j < (bottom - i) / 2; j++){
			printf(" ");
		}
		for (int k = 0; k < i; k++){
			printf("%c", c);
		}
		printf("\n");
	}
	//输出剩余个数
	printf("%d", n - used);
}


//PAT进制换算 哈利波特换钱  G=29*17 S=29  price=a1*G+b1*S+c1 计算一定是换成统一的最小单位计算
//  sum/G*s : (sum%(G*S))/S : sum%S

const int G = 29 * 17;
const int S = 29;
void jingzhichange(){

	int a1, b1, c1, a2, b2, c2;
	scanf_s("%d.%d.%d %d.%d.%d", &a1, &b1, &c1, &a2, &b2, &c2);
	int price = a1*G + b1*S + c1;
	int money = a2*G + b2*S + c2;
	int change = money - price;//以最小的单位进行统一，在计算

	if (change <= 0){//为符号的处理   1输出-，2取相反数为或绝对值，为正，就可以按照以前的正的做法计算了
		printf("-");
		//change =(int)fabs((double)change);
		change = -change;
	}
	printf("%d.%d.%d\n", change / G, (change % G) / S, change%S);
}
//枚举法按照规定格式进行输出，1，得到各个位数字，并用数组存储，（a[i]=sum%10,sum/10）

void formatNum(){
	int n, a[10] , num = 0;
	memset(a,0,sizeof(a));
	scanf_s("%d", &n);
	while (n!=0){
		a[num++] = n % 10;
		n /= 10;
	}
	for (int k= num-1; k >=0; k--){//遍历数组，上各个数字  k为位号

	
		if (k == 2){//百位
			for (int i = a[k]; i > 0; i--){
				printf("B");
			}
		}
		else if (k==1){//十位
			for (int i = a[k]; i>0; i--){
				printf("S");
			}
		}
		else if (k==0){
			for (int i = 1; i <= a[k]; i++)
			{
				printf("%d", i);
			}
		}
	}
}

//count[str[i]]++,索引也是变量,统计1个位数

void tongjisuzhu(){
	char str[1010];
	gets_s(str);
	int len = strlen(str);//str[i]可以得到各个数字
	int count[20] = {0};
	for (int i = 0; i < len;i++){
		int bit = str[i]-'0';//索引：位  需要转化为数字，当前str[i]是char的数字
		count[bit]++;//次数
	}
	for (int j = 0; j < 10;j++){//枚举10次
		if (count[j]!=0){
			printf("%d:%d\n", j, count[j]);
		}
	}
}

using namespace std;
void idcardtest(){
	int n, sum = 0, j = 0;
	char str[20];//输入时不能进行初始化的
	string s[110];
	int m = 0;


	scanf_s("%d", &n);//注意传入的是c 数字是c-'0';

	int w[20] = { 7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2 };
	char jh[15] = { '1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2' };

	bool flag = true;

	for (int i = 0; i < n; i++){//此循环所有内容就只是面对一行了
		scanf_s("%s", str);
		for (j = 0; j < 17; j++){
			if (str[j] <= '0'&&str[j] >= '9'){//求其补集，因为补集有多种，但是处理方式都一样
				flag = false;

				break;//如果中途其他闯入，则这行直接跳出循环，此时与满的不同是  j<16;
			}
			sum += w[j] * (str[j] - '0');//正确的只有一种  			
		}
		if (j < 16){
			flag = false;
			s[m++] = str;
			//printf("%s\n", str);
		}
		else if (jh[sum % 11] != str[17]){
			flag = false;
			s[m++] = str;
			//printf("%s\n", str);
		}
	}
	for (int k = 0; k<m; k++){
		printf("%s\n", s[k]);
	}
	if (flag){
		printf("All passed\n");
	}
}

//位--》数字--》位：str[i]-'0',除基取余，bit[num++]保存，然后输出，i=[num-1,0:1],if(i>0) 打印“ ” else打印“\n”
char strNum[110];
int sumNum[10];
//注意这里的应该用“”（字符串） 而非‘’（字符）
char change1[10][5] = { "ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu" };
void bit2num(){
	int sum=0,j=0;
	gets_s(strNum);//输入类似于赋值
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
	//countCalazNum();
	
	//fenleiAdd();

	//chazaotest();

	//typesqaretest();

	//jzchange();

	//huiziwen();

	//suofanhua();

	//judgeABC();

	//bitNumAdd();

	//calctime();

	//hejiu();

	//arrayMoveR();

	//qiudao();

	//jian2zhichazao();

	//structmax();

	//triangleType();

	//jingzhichange();

	//formatNum();

	//tongjisuzhu();

	//idcardtest();

	bit2num();
	getchar();
	return 0;

}