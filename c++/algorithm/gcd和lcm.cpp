#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//欧几里得算法 
//欧几里得算法的时间复杂度约为 O(log(min(a, b)))，十分高效。
int gcd_Fur(int a,int b)
{
	return b==0?a:gcd_Fur(b,a%b);
} 

//如果a和b不是正整数
//公约数和公倍数与符号无关，实际使用中取绝对值即可。
int gcd(int a, int b) {
    a = abs(a); // 转正数
    b = abs(b); 
    return b == 0 ? a : gcd(b, a % b);
}

int gcd_For(int a,int b){
	while(b!=0){
		int temp=a%b;
		a=b;
		b=temp;
	}
	return a;
}
//lcm(a,b)=a*b/gcd(a,b)
int lcm(int a, int b) {
    if (a == 0 || b == 0) return 0; // 避免除零错误
    return abs(a * b) / gcd(a, b);
}

/*1 多个数的GCD
连续应用GCD算法：
gcd(a, b, c) = gcd(gcd(a, b), c)
例如，gcd(24, 36, 48) = gcd(gcd(24, 36), 48) = gcd(12, 48) = 12
2. 多个数的LCM
连续应用LCM算法：
lcm(a, b, c) = lcm(lcm(a, b), c)
例如，lcm(4, 6, 8) = lcm(lcm(4, 6), 8) = lcm(12, 8) = 24
*/


int main(){
	cout<<gcd(12,18);
    return 0;
}
     
