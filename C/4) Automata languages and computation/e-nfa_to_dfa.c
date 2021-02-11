// To convert e-nfa to dfa
#include <stdio.h>
#include <string.h>
#include <conio.h>

char nfa[50][50], stack[20], st[10][20], eclosure[20], input[20];
int x, e, top = 0, topd = 0, n = 0, ns, nos, in;
int checkE(char a)
{
    int i;
    for (i = 0; i < e; i++)
    {
        if (eclosure[i] == a)
            return i;
    }
    return -1;
}
int check(char a)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (input[i] == a)
            return i;
    }
    return -1;
}
void push(char a)
{
    stack[top] = a;
    top++;
}
char pop()
{
    top--;
    return stack[top];
}
void pushd(char *a)
{
    strcpy(st[topd], a);
    topd++;
}
char *popd()
{
    topd--;
    return st[topd];
}
int ctoi(char a)
{
    int i = a - 48;
    return i;
}
char itoc(int a)
{
    char i = a + 48;
    return i;
}
char *findeclosure(char *a)
{
    int i, j;
    char c;
    for (i = 0; i < strlen(a); i++)
        push(a[i]);
    e = strlen(a);
    strcpy(eclosure, a);
    while (top != 0)
    {
        c = pop();
        for (j = 0; j < ns; j++)
        {
            if (nfa[ctoi(c)][j] == 'e')
            {
                if (check(itoc(j)) == -1)
                {
                    eclosure[e] = itoc(j);
                    push(eclosure[e]);
                    e++;
                }
            }
        }
    }
    eclosure[e] = '\0';
    return eclosure;
}
int main()
{
    int i, j, k, count;
    char ec[20], a[20], b[20], c[20], dstates[10][10];
    //clrscr();
    printf("Enter the number of states: ");
    scanf("%d", &ns);
    for (i = 0; i < ns; i++)
    {
        for (j = 0; j < ns; j++)
        {
            printf("Move [%d][%d]: ", i, j);
            scanf("%s", &nfa[i][j]);
            if (nfa[i][j] != '-' && nfa[i][j] != 'e')
            {
                if ((check(nfa[i][j])) == -1)
                    input[in++] = nfa[i][j];
            }
        }
    }
    printf("\nTransition Table:\n");
    topd = 0;
    nos = 0;
    c[0] = itoc(0);
    c[1] = '\0';
    pushd(findeclosure(c));
    strcpy(dstates[nos], findeclosure(c));
    for (x = 0; x < in; x++)
        printf("\t\t%c", input[x]);
    printf("\n");
    while (topd > 0)
    {
        strcpy(a, popd());
        printf("%s\t\t", a);
        for (i = 0; i < in; i++)
        {
            int len = 0;
            for (j = 0; j < strlen(a); j++)
            {
                int x = ctoi(a[j]);
                for (k = 0; k < ns; k++)
                {
                    if (nfa[x][k] == input[i])
                        ec[len++] = itoc(k);
                }
            }
            ec[len] = '\0';
            strcpy(b, findeclosure(ec));
            count = 0;
            for (j = 0; j <= nos; j++)
            {
                if (strcmp(dstates[j], b) == 0)
                    count++;
            }
            if (count == 0)
            {
                if (b[0] != '\0')
                {
                    nos++;
                    pushd(b);
                    strcpy(dstates[nos], b);
                }
            }
            printf("%s\t\t", b);
        }
        printf("\n");
    }
    getch();
}