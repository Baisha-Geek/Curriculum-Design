#include <stdio.h>
int main()
{
    int i, a = 0x00ff, b = 0xff00, c, d;
    printf("输入一个整数i:\n");
    scanf("%d", &i);
    c = i & a;
    d = i & b;
    printf("i的高位是:%d,i的低位是:%d \n", d, c);
    return 0;
}