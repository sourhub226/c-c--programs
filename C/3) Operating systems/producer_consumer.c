// To implement producer consumer problem using mutex
#include <stdio.h>
#include <stdlib.h>

int mutex = 1, full = 0, empty = 3, x = 0;
int main()
{
    int n;
    void producer();
    void consumer();
    int wait(int);
    int signal(int);
    while (1)
    {
        printf("1.Producer\n2.Consumer\n3.Exit");
        printf("\nEnter your choice:");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            if ((mutex == 1) && (empty != 0))
                producer();
            else
                printf("\nBuffer is full!\n\n");
            break;
        case 2:
            if ((mutex == 1) && (full != 0))
                consumer();
            else
                printf("\nBuffer is empty!\n\n");
            break;
        case 3:
            exit(0);
            break;
        }
    }
    return 0;
}
int wait(int s)
{
    return (--s);
}

int signal(int s)
{
    return (++s);
}
void producer()
{
    mutex = wait(mutex);
    full = signal(full);
    empty = wait(empty);
    x++;
    printf("\nProducer produces the item %d\n\n", x);
    mutex = signal(mutex);
}

void consumer()
{
    mutex = wait(mutex);
    full = wait(full);
    empty = signal(empty);
    printf("\nConsumer consumes item %d\n\n", x);
    x--;
    mutex = signal(mutex);
}
