#include<stdio.h>

int main()
{
    int X , sum;

    while(scanf("%d",&X)== 1 && X != 0){
        sum = 0;
        if(X % 2 !=0){
            X++;
        }
        for(int i = 0; i<5 ; i++){
            sum = sum + X;
            X = X + 2;
        }
        printf("%d\n", sum);
    }
    return 0;
}
