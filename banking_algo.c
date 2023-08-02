#include <stdio.h>

int main()
{
    int n, m, i, j, k;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter number of resources: ");
    scanf("%d", &m);

    int allocated[n][m];
    int maximum[n][m];
    int available[m];

    printf("Enter Allocation Matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &allocated[i][j]);
        }
    }

    printf("Enter Maximum Matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &maximum[i][j]);
        }
    }

    printf("Enter Available Resources:\n");
    for (i = 0; i < m; i++) {
        scanf("%d", &available[i]);
    }

    int f[n];
    int ans[n];
    int ind = 0;
    int need[n][m];
    for (i = 0; i < n; i++) {
        f[i]=0;
        for (j = 0; j < m; j++)
            need[i][j] = maximum[i][j] - allocated[i][j];
    }
    int y = 0;
    for (k = 0; k < 5; k++) {
        for (i = 0; i < n; i++) {
            if (f[i] == 0) {
                int flag_f = 0;
                for (j = 0; j < m; j++) {
                    if (need[i][j] > available[j]) {
                        flag_f = 1;
                        break;
                    }
                }

                if (flag_f == 0) {
                    ans[ind++] = i;
                    for (y = 0; y < m; y++)
                        available[y] += allocated[i][y];
                    f[i] = 1;
                }
            }
        }
    }

    int flag_f = 1;

    for (i = 0; i < n; i++) {
        if (f[i] == 0) {
            flag_f = 0;
            printf("Sequence not Safe\n");
            break;
        }
    }

    if (flag_f == 1) {
        printf("Safe Sequence is:\n");
        for (i = 0; i < n - 1; i++)
            printf(" P%d ->", ans[i]);
        printf(" P%d\n", ans[n - 1]);
    }

    return 0;
}
