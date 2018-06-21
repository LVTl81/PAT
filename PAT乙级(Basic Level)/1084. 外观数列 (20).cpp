1084. 外观数列 (20)
外观数列是指具有以下特点的整数序列：
d, d1, d111, d113, d11231, d112213111, ...
它从不等于 1 的数字 d 开始，序列的第 n+1 项是对第 n 项的描述。比如第 2 项表示第 1 项有 1 个 d，所以就是 d1；第 2 项是 1 个 d（对应 d1）和 1 个 1（对应 11），所以第 3 项就是 d111。又比如第 4 项是 d113，其描述就是 1 个 d，2 个 1，1 个 3，所以下一项就是 d11231。当然这个定义对 d = 1 也成立。本题要求你推算任意给定数字 d 的外观数列的第 N 项。
输入格式：
输入第一行给出[0,9]范围内的一个整数 d、以及一个正整数 N（<=40），用空格分隔。
输出格式：
在一行中给出数字 d 的外观数列的第 N 项。
输入样例：
1 8
输出样例：
1123123111

分析：用string s接收所需变幻的数字，每次遍历s，从当前位置i开始，看后面有多少个与s[i]相同，设j处开始不相同，那么临时字符串t += to_string((s[i] - '0') * 10 + j - i);然后再将t赋值给s，cnt只要没达到n次就继续加油循环下一次，最后输出s的值～

#include <iostream>
using namespace std;
int main() {
    string s;
    int n, j;
    cin >> s >> n;
    for (int cnt = 1; cnt < n; cnt++) {
        string t;
        for (int i = 0; i < s.length(); i = j) {
            for (j = i; j < s.length() && s[j] == s[i]; j++);
            t += to_string((s[i] - '0') * 10 + j - i);
        }
        s = t;
    }
    cout << s;
    return 0;
}