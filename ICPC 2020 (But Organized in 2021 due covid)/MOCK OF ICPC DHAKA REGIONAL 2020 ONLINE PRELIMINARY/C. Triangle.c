#include<stdio.h>
int main(void)
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if (a==b && b==c && a==c)
        printf("Equilateral Triangle\n");
    else if (a==b || a==c || b==c)
        printf("Isosceles Triangle\n");
    else if (a!=b && a!=c && b!=c)
        printf("Bad Triangle\n");
    return 0;
}
