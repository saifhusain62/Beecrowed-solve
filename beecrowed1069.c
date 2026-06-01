#include <stdio.h>
#include <string.h>

void solve() {
    char str[1001];
    scanf("%s", str);

    int open_brackets = 0;
    int diamonds = 0;
    int length = strlen(str);

    for (int i = 0; i < length; i++) {
        if (str[i] == '<') {
            open_brackets++;
        } else if (str[i] == '>' && open_brackets > 0) {
            diamonds++;
            open_brackets--;
        }
    }

    printf("%d\n", diamonds);
}

int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        while (n--) {
            solve();
        }
    }
    return 0;
}

