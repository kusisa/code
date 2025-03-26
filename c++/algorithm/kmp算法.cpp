#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 构建部分匹配表（next数组）
vector<int> buildNext(const string& pattern) {
    int n = pattern.length();
    vector<int> next(n, 0);
    next[0] = -1;          // 初始化第一个位置的next值为-1
    
    int j = -1;            // 前缀指针
    int i = 0;             // 后缀指针
    
    while (i < n - 1) {
        if (j == -1 || pattern[i] == pattern[j]) {
            // 字符匹配时，同时移动双指针
            ++i;
            ++j;
            // 优化：避免连续不匹配时的回退
            next[i] = (pattern[i] != pattern[j]) ? j : next[j];
        } else {
            // 失配时根据next数组回退
            j = next[j];
        }
    }
    return next;
}

// KMP主算法
vector<int> kmpSearch(const string& text, const string& pattern) {
    vector<int> matches;
    if (pattern.empty() || text.length() < pattern.length()) 
        return matches;

    vector<int> next = buildNext(pattern);
    int i = 0; // text指针
    int j = 0; // pattern指针
    const int n = text.length();
    const int m = pattern.length();

    while (i < n) {
        if (j == -1 || text[i] == pattern[j]) {
            // 字符匹配时同时前进
            ++i;
            ++j;
        } else {
            // 使用next数组跳过已匹配部分
            j = next[j];
        }

        // 找到完整匹配
        if (j == m) {
            matches.push_back(i - j);
            j = next[m-1]; // 继续寻找下一个匹配
            i--;           // 矫正text指针位置
        }
    }
    return matches;
}

int main() {
    // 测试用例
    string text = "abcasdasczczdasd";
    string pattern = "sczc";
    
    vector<int> result = kmpSearch(text, pattern);
    
    if (result.empty()) {
        cout << "Pattern not found" << endl;
    } else {
        cout << "Pattern found at positions: ";
        for (int pos : result) {
            cout << pos << " ";
        }
        cout << endl;
    }
    
    return 0;
}
