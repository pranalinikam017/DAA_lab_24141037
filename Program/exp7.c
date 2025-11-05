#include <stdio.h>
#include <limits.h>

#define MAX 10

int main() {
    int n, i, j, k;
    float p[MAX], q[MAX], w[MAX][MAX], c[MAX][MAX];
    int r[MAX][MAX];

    printf("Enter number of keys: ");
    scanf("%d", &n);

    printf("Enter probabilities for successful searches (p1 to p%d):\n", n);
    for (i = 1; i <= n; i++)
        scanf("%f", &p[i]);

    printf("Enter probabilities for unsuccessful searches (q0 to q%d):\n", n);
    for (i = 0; i <= n; i++)
        scanf("%f", &q[i]);

    for (i = 0; i <= n; i++) {
        w[i][i] = q[i];
        c[i][i] = 0;
        r[i][i] = 0;
    }

    for (i = 0; i < n; i++) {
        w[i][i + 1] = q[i] + q[i + 1] + p[i + 1];
        c[i][i + 1] = w[i][i + 1];
        r[i][i + 1] = i + 1;
    }

    for (int m = 2; m <= n; m++) {
        for (i = 0; i <= n - m; i++) {
            j = i + m;
            w[i][j] = w[i][j - 1] + p[j] + q[j];
            float min = INT_MAX;
            int kmin = 0;

            for (k = i + 1; k <= j; k++) {
                float cost = c[i][k - 1] + c[k][j];
                if (cost < min) {
                    min = cost;
                    kmin = k;
                }
            }
            c[i][j] = w[i][j] + min;
            r[i][j] = kmin;
        }
    }

    printf("\nMinimum cost of OBST = %.2f\n", c[0][n]);
    printf("\nRoot Table (r[i][j]):\n");
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= n; j++)
            printf("%d\t", r[i][j]);
        printf("\n");
    }

    return 0;
}
