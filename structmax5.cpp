#include <cstdio> 
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
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%s%s%d",s_temp.name,s_temp.id,&s_temp.score);
		if (s_temp.score<s_min.score){
			s_min = s_temp;//这里是直接把当前学生作为最大的学生，而非最大分数，不然无法得到其他相关联的如id 
		}
		if (s_temp.score>s_max.score){
			s_max = s_temp;
		}

	}
	printf("%s %s\n", s_max.name, s_max.id);
	printf("%s %s\n", s_min.name, s_min.id);

}

int main(){
	structmax(); 
	return 0;
}
