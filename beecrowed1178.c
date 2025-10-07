#include<stdio.h>
int main()
{
    double N[100];
    double X;
    int i;

    scanf("%lf",&X);

    for(i=0;i<100;i++){
        N[i] = X;
        printf("N[%d] = %.4lf\n",i,N[i]);
        X  = X /2.0;
    }

    return 0;
}
