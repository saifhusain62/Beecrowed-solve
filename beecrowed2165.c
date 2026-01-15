#include <stdio.h>
#include <string.h>

int main()
{
    char twt[600];
    gets(twt);
    printf((strlen(twt)>140)?"MUTE\n":"TWEET\n");
    return 0;
}

