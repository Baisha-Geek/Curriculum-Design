#include <stdio.h>
int main()
{
    unsigned int a, b, c;
    int n;
    printf("a = ");
    scanf("%x", &a);
    printf("n = ");
    scanf("%d", &n);
    b = a >> (16-n);
    c = a << n;
    c = b | c;
    printf("a = %x, c = %x", a, c);
    return 0;
}