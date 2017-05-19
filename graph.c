#include <stdio.h>

int main() {
    int t, m, n;

    scanf(" %d", &t);

    while (t--) {
        scanf(" %d %d", &n, &m);

        printf("%d\n", 2*m*n-n-m);
    }

    return 0;
}
