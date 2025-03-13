#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

void move(char pos1,char pos2){
    cout<<pos1<<"->"<<pos2<<endl;
}

void hanoi(int n,char pos1,char pos2,char pos3){
    if(n==1) move(pos1,pos3);
    else{
        hanoi(n-1,pos1,pos3,pos2);//将n-1个盘子从A经过C移动到B
        move(pos1,pos3);
        hanoi(n-1,pos2,pos1,pos3);
    }
}

int main(){
ios::sync_with_stdio(0);cin.tie(0);

int n;cin>>n;
hanoi(n,'A','B','C');
return 0;
}