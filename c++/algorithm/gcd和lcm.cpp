#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//ŷ������㷨 
//ŷ������㷨��ʱ�临�Ӷ�ԼΪ O(log(min(a, b)))��ʮ�ָ�Ч��
int gcd_Fur(int a,int b)
{
	return b==0?a:gcd_Fur(b,a%b);
} 

//���a��b����������
//��Լ���͹�����������޹أ�ʵ��ʹ����ȡ����ֵ���ɡ�
int gcd(int a, int b) {
    a = abs(a); // ת����
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
    if (a == 0 || b == 0) return 0; // ����������
    return abs(a * b) / gcd(a, b);
}

/*1 �������GCD
����Ӧ��GCD�㷨��
gcd(a, b, c) = gcd(gcd(a, b), c)
���磬gcd(24, 36, 48) = gcd(gcd(24, 36), 48) = gcd(12, 48) = 12
2. �������LCM
����Ӧ��LCM�㷨��
lcm(a, b, c) = lcm(lcm(a, b), c)
���磬lcm(4, 6, 8) = lcm(lcm(4, 6), 8) = lcm(12, 8) = 24
*/


int main(){
	cout<<gcd(12,18);
    return 0;
}
     
