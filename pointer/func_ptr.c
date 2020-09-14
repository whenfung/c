# include <stdio.h>

int max(int, int);       // 函数声明

int main(void)
{
    int(*p)(int, int);  // 定义一个函数指针
    int a, b, c;
    p = max;            // p 指向 max 函数入口
    printf("please enter a and b:");
    scanf("%d%d", &a, &b);
    c = (*p)(a, b);     // 通过函数指针调用 max 函数
    printf("a = %d\nb = %d\nmax = %d\n", a, b, c);
    return 0;
}

int max(int x, int y)   // 定义 max 函数
{
    return x > y ? x : y;
}
