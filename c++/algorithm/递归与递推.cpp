#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int factorial_Fur(int n){
if(n==0||n==1)
return 1;
else return n*factorial_Fur(n-1);
} 
//stack��ջ�׵�ջ��������5 4 3 2 1
//ջ����ִ����ֱ��pop 
int factorial_For(int n){
	int fact=1;
	for(int i=1;i<=n;i++){
		fact*=i;
	}
	return fact;
}



int main(){
	int a=factorial_Fur(5);
	int b=factorial_For(5);
 	cout<<a<<endl<<b;
    return 0;
}
     
