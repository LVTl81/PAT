1070. 结绳(25)
给定一段一段的绳子，你需要把它们串成一条绳。每次串连的时候，是把两段绳子对折，再如下图所示套接在一起。这样得到的绳子又被当成是另一段绳子，可以再次对折去跟另一段绳子串连。每次串连后，原来两段绳子的长度就会减半。
给定N段绳子的长度，你需要找出它们能串成的绳子的最大长度。
输入格式：
每个输入包含1个测试用例。每个测试用例第1行给出正整数N (2 <= N <= 104)；第2行给出N个正整数，即原始绳段的长度，数字间以空格分隔。所有整数都不超过104。
输出格式：
在一行中输出能够串成的绳子的最大长度。结果向下取整，即取为不超过最大长度的最近整数。
输入样例：
8
10 15 12 3 4 13 1 15
输出样例：
14

分析：因为所有长度都要串在一起，每次都等于(旧的绳子长度+新的绳子长度)/2，所以越是早加入绳子长度中的段，越要对折的次数多，所以既然希望绳子长度是最长的，就必须让长的段对折次数尽可能的短。所以将所有段从小到大排序，然后从头到尾从小到大分别将每一段依次加入结绳的绳子中，最后得到的结果才会是最长的结果～

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &v[i]);
    sort(v.begin(), v.end());
    int result = v[0];
    for (int i = 1; i < n; i++)
        result = (result + v[i]) / 2;
    printf("%d", result);
    return 0;
}