#include<stdio.h>
int main(void)
{
    int n;
    scanf("%d", &n);
    if (n<6)
        printf("1\n");
    else
    {
        int people = (n/6) + 1;
        printf("%d\n", people);
    }
    return 0;
}
