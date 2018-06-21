1074. 宇宙无敌加法器(20)
地球人习惯使用十进制数，并且默认一个数字的每一位都是十进制的。而在PAT星人开挂的世界里，每个数字的每一位都是不同进制的，这种神奇的数字称为“PAT数”。每个PAT星人都必须熟记各位数字的进制表，例如“……0527”就表示最低位是7进制数、第2位是2进制数、第3位是5进制数、第4位是10进制数，等等。每一位的进制d或者是0（表示十进制）、或者是[2，9]区间内的整数。理论上这个进制表应该包含无穷多位数字，但从实际应用出发，PAT星人通常只需要记住前20位就够用了，以后各位默认为10进制。
在这样的数字系统中，即使是简单的加法运算也变得不简单。例如对应进制表“0527”，该如何计算“6203+415”呢？我们得首先计算最低位：3+5=8；因为最低位是7进制的，所以我们得到1和1个进位。第2位是：0+1+1（进位）=2；因为此位是2进制的，所以我们得到0和1个进位。第3位是：2+4+1（进位）=7；因为此位是5进制的，所以我们得到2和1个进位。第4位是：6+1（进位）=7；因为此位是10进制的，所以我们就得到7。最后我们得到：6203+415=7201。
输入格式：
输入首先在第一行给出一个N位的进制表（0 < N <=20），以回车结束。 随后两行，每行给出一个不超过N位的正的PAT数。
输出格式：
在一行中输出两个PAT数之和。
输入样例：
30527
06203
415
输出样例：
7201

分析：先将要相加的两个字符串S1和S2都扩展到和S等长，然后从后往前按照进制相加到ans中，注意进位carry，最后输出字符串ans，记得不要输出字符串ans前面的0。如果一次都没有输出，最后要输出一个0

#include <iostream>
using namespace std;
int main() {
    string s, s1, s2, ans;
    int carry = 0, flag = 0;
    cin >> s >> s1 >> s2;
    ans = s;
    string ss1(s.length() - s1.length(), '0');
    s1 = ss1 + s1;
    string ss2(s.length() - s2.length(), '0');
    s2 = ss2 + s2;
    for(int i = s.length() - 1; i >= 0; i--) {
        int mod = s[i] == '0' ? 10 : (s[i] - '0');
        ans[i] = (s1[i] - '0' + s2[i] - '0' + carry) % mod + '0';
        carry = (s1[i] - '0' + s2[i] - '0' + carry) / mod;
    }
    if (carry != 0) ans = '1' + ans;
    for(int i = 0; i < ans.size(); i++) {
        if (ans[i] != '0' || flag == 1) {
            flag = 1;
            cout << ans[i];
        }
    }
    if (flag == 0) cout << 0;
    return 0;
}
