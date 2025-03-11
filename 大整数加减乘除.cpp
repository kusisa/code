#include <bits/stdc++.h>
using namespace std;

struct bign {
    int data[2005]; // 乘积可能会达到 2000 位
    int len;
    bool isNegative;
    bign() {
        memset(data, 0, sizeof(data));
        len = 0;
        isNegative = false;
    }
};

bign change(string s) {
    bign c;
    if (s[0] == '-') {
        c.isNegative = true;
        s = s.substr(1);
    }
    c.len = s.size();
    for (int i = 0; i < c.len; i++) {
        c.data[i] = s[c.len - i - 1] - '0';
    }
    return c;
}

void print(bign a) {
    if (a.isNegative) {
        cout << "-";
    }
    for (int i = a.len - 1; i >= 0; i--) {
        cout << a.data[i];
    }
}
// 两个大整数相加
bign add(bign a, bign b) {
    bign c;
    int carry = 0;
    for (int i = 0; i < a.len || i < b.len; i++) {
        int temp = a.data[i] + b.data[i] + carry;
        c.data[c.len++] = temp % 10;
        carry = temp / 10;
    }
    if (carry != 0) {
        c.data[c.len++] = carry;
    }
    return c;
}
// 两个大整数相减
bign subtract(bign a, bign b) {
    bign c;
    int borrow = 0;
    for (int i = 0; i < a.len || i < b.len; i++) {
        int temp = a.data[i] - b.data[i] - borrow;
        if (temp < 0) {
            temp += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        c.data[c.len++] = temp;
    }
    while (c.len > 1 && c.data[c.len - 1] == 0) {
        c.len--;
    }
    return c;
}
// 判断 a 是否大于等于 b
bool isGreaterOrEqual(bign a, bign b) {
    if (a.len != b.len) {
        return a.len > b.len;
    }
    for (int i = a.len - 1; i >= 0; i--) {
        if (a.data[i] != b.data[i]) {
            return a.data[i] > b.data[i];
        }
    }
    return true;
}
// 两个大整数相乘
bign multiply(bign a, bign b) {
    bign c;
    c.len = a.len + b.len;
    for (int i = 0; i < a.len; i++) {
        for (int j = 0; j < b.len; j++) {
            c.data[i + j] += a.data[i] * b.data[j];
            if (c.data[i + j] >= 10) {
                c.data[i + j + 1] += c.data[i + j] / 10;
                c.data[i + j] %= 10;
            }
        }
    }
    while (c.len > 1 && c.data[c.len - 1] == 0) {
        c.len--;
    }
    c.isNegative = a.isNegative != b.isNegative;
    return c;
}
// 两个大整数相除
pair<bign, bign> divide(bign a, bign b) {
    bign quotient, remainder;
    remainder = a;
    quotient.len = a.len;
    for (int i = a.len - 1; i >= 0; i--) {
        int left = 0, right = 9;
        while (left <= right) {
            int mid = (left + right) / 2;
            bign temp = b;
            for (int j = 0; j < i; j++) {
                temp.data[j + b.len] = temp.data[j];
                temp.data[j] = 0;
            }
            temp.len += i;
            for (int j = 0; j < temp.len; j++) {
                temp.data[j] *= mid;
            }
            for (int j = 0; j < temp.len - 1; j++) {
                temp.data[j + 1] += temp.data[j] / 10;
                temp.data[j] %= 10;
            }
            while (temp.len > 1 && temp.data[temp.len - 1] == 0) {
                temp.len--;
            }
            if (isGreaterOrEqual(remainder, temp)) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        quotient.data[i] = right;
        bign temp = b;
        for (int j = 0; j < i; j++) {
            temp.data[j + b.len] = temp.data[j];
            temp.data[j] = 0;
        }
        temp.len += i;
        for (int j = 0; j < temp.len; j++) {
            temp.data[j] *= right;
        }
        for (int j = 0; j < temp.len - 1; j++) {
            temp.data[j + 1] += temp.data[j] / 10;
            temp.data[j] %= 10;
        }
        while (temp.len > 1 && temp.data[temp.len - 1] == 0) {
            temp.len--;
        }
        remainder = subtract(remainder, temp);
    }
    while (quotient.len > 1 && quotient.data[quotient.len - 1] == 0) {
        quotient.len--;
    }
    quotient.isNegative = a.isNegative != b.isNegative;
    remainder.isNegative = a.isNegative;
    return make_pair(quotient, remainder);
}

void test02() {
    string str1, str2;
    cin >> str1 >> str2;
    bign a = change(str1);
    bign b = change(str2);
    bign c;
    if (a.isNegative == b.isNegative) {
        c = add(a, b);
        c.isNegative = a.isNegative;
    } else {
        if (isGreaterOrEqual(a, b)) {
            c = subtract(a, b);
            c.isNegative = a.isNegative;
        } else {
            c = subtract(b, a);
            c.isNegative = b.isNegative;
        }
    }
    
    if (c.len > 1000) {
        cout << "错误：位数超限。";
    } else {
        print(c);
    }
}

void test03() {
    string str1, str2;
    cin >> str1 >> str2;
    bign a = change(str1);
    bign b = change(str2);
    bign c = multiply(a, b);
    if (c.len > 1000) {
        cout << "错误：位数超限。";
    } else {
        print(c);
    }
}

void test04() {
    string str1, str2;
    cin >> str1 >> str2;
    bign a = change(str1);
    bign b = change(str2);
    pair<bign, bign> result = divide(a, b);
    bign quotient = result.first;
    bign remainder = result.second;
    if (quotient.len > 1000) {
        cout << "错误：位数超限。";
    } else {
        print(quotient);
        cout << endl;
        print(remainder);
    }
}

int main() {
    char choice;
    cin >> choice;
    switch(choice) {
        case '+':
        case '-':
            test02();
            break;
        case '*':
            test03();
            break;
        case '/':
            test04();
            break;
    }
    return 0;
}