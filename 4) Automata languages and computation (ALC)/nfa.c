// To implement non-deterministic finite automata
#include <stdio.h>
#include <stdlib.h>
struct state
{
    int a0[10], a1[10];
    int n0, n1;
};
int nfa(int p[], int len) { int i; }
int main()
{
    int ns, i, j, k, f, c = 0, len, t;
    int prev[100], current[100];
    printf("Enter Number of States: ");
    scanf("%d", &ns);
    struct state s[ns];
    for (i = 0; i < ns; i++)
    {
        printf("\n Enter No of Transition of (q%d,0): ", i);
        scanf("%d", &s[i].n0);
        printf("\tT(q%d,0): ", i);
        for (j = 0; j < s[i].n0; j++)
            scanf("%d", &s[i].a0[j]);
        printf("\n Enter No of Transition of (q%d,1): ", i);
        scanf("%d", &s[i].n1);
        printf("\tT(q%d,1): ", i);
        for (j = 0; j < s[i].n1; j++)
            scanf("%d", &s[i].a1[j]);
    }
    printf("\nEnter Final State: ");
    scanf("%d", &f);
    printf("\nEnter Length of String: ");
    scanf("%d", &len);
    printf("\nEnter String: ");
    int *p = malloc(len * sizeof(int));
    for (i = 0; i < len; i++)
        scanf("%d", &p[i]);
    prev[0] = 0;
    prev[1] = -1;
    for (i = 0; i < len; i++)
    {
        t = -1;
        if (p[i] == 0)
        {
            for (j = 0; prev[j] != -1; j++)
            {
                c = prev[j];
                for (k = 0; k < s[c].n0; k++)
                    current[++t] = s[c].a0[k];
            }
        }
        else
        {
            for (j = 0; prev[j] != -1; j++)
            {
                c = prev[j];
                for (k = 0; k < s[c].n1; k++)
                    current[++t] = s[c].a1[k];
            }
        }
        for (j = 0; j <= t; j++)
        {
            prev[j] = current[j];
        }
        prev[j] = -1;
    }
    int flag = 0;
    for (j = 0; prev[j] != -1; j++)
    {
        if (f == prev[j])
        {
            flag = 1;
            break;
        }
        if (flag == 1)
            break;
    }
    if (flag == 1)
        printf("\nThe String is valid ");
    else
        printf("\nThe String is not valid ");
}