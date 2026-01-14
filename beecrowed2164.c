#include <stdio.h>

int main()
{
    double n, x, y, ans;
    scanf("%lf", &n);
    x = (1 + sqrt(5))/2.0;
    y = (1 - sqrt(5))/2.0;
    ans = (pow(x,n) - pow(y,n))/sqrt(5);
    printf("%.1lf\n", ans);
    return 0;
}
