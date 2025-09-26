#include<stdio.h>
int main()
{
    int T,PA,PB,years;
    double G1, G2;
    scanf("%d",&T);

    while(T--){
        scanf("%d %d %lf %lf", &PA , &PB , &G1 , &G2);
        years = 0;

        while(PA<=PB){
            PA = PA + (int)(PA*(G1 /100.00));
            PB = PB + (int)(PB*(G2 /100.00));
            years++;

            if(years>100){
                printf("Mais de 1 seculo.\n");
                break;
            }
        }

        if(years <=100){
            printf("%d anos.\n", years);
        }
    }

    return 0;
}
