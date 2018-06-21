L1-037. A除以B
真的是简单题哈 —— 给定两个绝对值不超过100的整数A和B，要求你按照“A/B=商”的格式输出结果。

输入格式：
输入在第一行给出两个整数A和B（-100 <= A, B, <= 100），数字间以空格分隔。

输出格式：
在一行中输出结果：如果分母是正数，则输出“A/B=商”；如果分母是负数，则要用括号把分母括起来输出；如果分母为零，则输出的商应为“Error”。输出的商应保留小数点后2位。

输入样例1：
-1 2
输出样例1：
-1/2=-0.50
输入样例2：
1 -3
输出样例2：
1/(-3)=-0.33
输入样例3：
5 0
输出样例3：
5/0=Error

分析：如果b小于0就左右加上括号，如果b=0就要输出计算结果为Error，其余情况就输出a/b的保留两位小数的结果～

#include <cstdio>
using namespace std;
int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%d/", a);
    if (b >= 0)
        printf("%d=", b);
    else
        printf("(%d)=", b);
    if (b == 0)
        printf("Error");
    else
        printf("%.2f", a * 1.0 / b);
    return 0;
}