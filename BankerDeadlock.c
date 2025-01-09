#include <stdio.h>
int main()
{


    
    int p = 5, r = 3, i, j, k, a[5][3] = {{0, 1, 0}, {2, 0, 0}, {3, 0, 2}, {2, 1, 1}, {0, 0, 2}},
        m[5][3] = {{7, 5, 3}, {3, 2, 2}, {9, 0, 2}, {2, 2, 2}, {4, 3, 3}}, v[3] = {3, 3, 2},
        n[5][3], f[5] = {0}, s[5], cnt = 0;
    for (i = 0; i < p; i++)
        for (j = 0; j < r; j++)
            n[i][j] = m[i][j] - a[i][j];
    while (cnt < p)
    {
        int found = 0;
        for (i = 0; i < p; i++)
        {
            if (!f[i])
            {
                for (j = 0; j < r; j++)
                    if (n[i][j] > v[j])
                        break;
                if (j == r)
                {
                    for (k = 0; k < r; k++)
                        v[k] += a[i][k];
                    s[cnt++] = i;
                    f[i] = 1;
                    found = 1;
                }
            }
        }
        if (!found)
        {
            printf("System is not in a safe state.\n");
            return -1;
        }
    }
    printf("System is in a safe state. Safe sequence: ");
    for (i = 0; i < p; i++)
        printf("%d ", s[i]);
    printf("\n");
    return 0;
}
