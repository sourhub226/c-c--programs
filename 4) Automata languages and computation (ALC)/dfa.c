// To implement deterministic finite automata
#include <stdio.h>
#include <stdlib.h>
struct state
{
    int a0, a1;
};
int main()
{
    int ns, i, f, c = 0, len;
    printf("Enter Number of States: ");
    scanf("%d", &ns);
    struct state s[ns];
    for (i = 0; i < ns; i++)
    {
        printf("\n State %d :\n", i);
        printf("\tT(q%d,0): ", i);
        scanf("%d", &s[i].a0);
        printf("\tT(q%d,1): ", i);
        scanf("%d", &s[i].a1);
    }
    printf("\nEnter Final State: ");
    scanf("%d", &f);
    printf("\nEnter Length of String: ");
    scanf("%d", &len);
    printf("\nEnter String: ");
    int *p = malloc(len * sizeof(int));
    for (i = 0; i < len; i++)
        scanf("%d", &p[i]);
    for (i = 0; i < len; i++)
    {
        if (p[i] == 0)
            c = s[c].a0;
        else
            c = s[c].a1;
    }
    if (c == f)
        printf("\nThe String is valid ");
    else
        printf("\nThe String is not valid ");
}