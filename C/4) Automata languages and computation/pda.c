// To check if a string can be accepted by the given pda
#include <stdio.h>
struct state
{
    int a[3][3], st[3][3];
};
int main()
{
    int ns, a, f, l, j, k, i;
    char ch;
    printf("Enter no. of states: ");
    scanf("%d", &ns);
    struct state s[ns];
    int st[40];
    int top = 0;
    st[top] = 2;
    printf("Enter the respective transition state: \n");
    for (i = 0; i < ns; i++)
    {
        for (j = 0; j < 3; j++)
        {
            for (k = 0; k < 3; k++)
            {
                printf("(q%d,", i);
                if (j == 2)
                    printf("e,");
                else
                    printf("%d,", j);
                if (k == 2)
                    printf("e): ");
                else
                    printf("%d): ", k);
                scanf("%s", &ch);
                if (ch != '-')
                {
                    s[i].a[j][k] = ch - 48;
                    printf("stack_top: ");
                    scanf("%s", &ch);
                    if (ch != '-')
                        s[i].st[j][k] = ch - 48;
                    else
                        s[i].st[j][k] = 2;
                }
                else
                {
                    s[i].a[j][k] = -1;
                    s[i].st[j][k] = 2;
                }
            }
        }
    }
    printf("Enter the final state: ");
    scanf("%d", &f);
    printf("Enter the length of string: ");
    scanf("%d", &l);
    int p[l];
    printf("Enter the string: ");
    for (i = 0; i < l; i++)
    {
        scanf("%d", &p[i]);
    }
    int cn = 0, c0 = 0;
    for (i = 0; i < l; i++)
    {
        int t = st[top];
        cn = s[c0].a[p[i]][t];
        if (cn == -1)
            break;
        if (s[c0].st[p[i]][t] != 2)
            st[++top] = s[c0].st[p[i]][t];
        else
            top--;
        c0 = cn;
    }
    if (f == s[cn].a[2][st[top]] && cn != -1)
        printf("\nString Valid");
    else
        printf("\nString is Invalid");
}