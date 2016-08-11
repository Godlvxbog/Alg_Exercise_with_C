#include <stdio.h>


const int stuNum = 100010;
int school[stuNum] = {0};
void fenleiAdd(){
  
  int n, schNum, score;
  scanf("%d", &n);
  for (int i = 0; i <n; i++)
  {
    scanf("%d %d", &schNum, &score);
    school[schNum] += score;

  }
  int max = -1,k;
  for (int i = 1; i <= n; i++)
  {
    if (max<school[i]){
      max = school[i];
      k = i;
    }

  }
  printf("%d %d", k, max);

}

int main(){
  fenleiAdd();
  return 0;
  
}
