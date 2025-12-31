#include <stdio.h>
int main()
{
    int num, i, a, cnt2=0, cnt3=0, cnt4=0, cnt5=0;
    scanf("%d", &num);
    for(i=0; i<num; i++)
    {
        scanf("%d", &a);
        if(a % 2 == 0) cnt2++;
        if(a % 3 == 0) cnt3++;
        if(a % 4 == 0) cnt4++;
        if(a % 5 == 0) cnt5++;
    }
    printf("%d Multiplo(s) de 2\n", cnt2);
    printf("%d Multiplo(s) de 3\n", cnt3);
    printf("%d Multiplo(s) de 4\n", cnt4);
    printf("%d Multiplo(s) de 5\n", cnt5);
    return 0;
}
