#include <stdio.h>
int main()
{
    int a, b = 0xf, c;
    printf("输入一个十六进制数 a: \n");
    scanf("%x", &a);
    c = a ^ b;
    printf("a翻转后的数为: %x \n",c);
    return 0;
}
