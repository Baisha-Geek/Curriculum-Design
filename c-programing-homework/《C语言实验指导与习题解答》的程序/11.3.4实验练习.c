#include <stdio.h>
int main()
{
    int num, mask;
    printf("Input a integer number: ");
    scanf("%d", &num);
    num >>= 7;
    mask = ~(~0 << 4);
    printf("result = 0x%x\n", num & mask);
    return 0;
}