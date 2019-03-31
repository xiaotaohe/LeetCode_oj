#include<stdio.h>
#include<math.h>
int fuc(int x){
    if(x<9) return 1;
    int y=x;
    int num,sum=0;
    while(y){
        num=y%10;
        sum=sum*10+num;
        y=y/10;
    }
    if(sum==x) return 1;
    return 0;
}
int main(){
    for(int i=1;i<256;i++){
        if(fuc(i*i)){
            printf("%d\n",i);
        }
    }
}