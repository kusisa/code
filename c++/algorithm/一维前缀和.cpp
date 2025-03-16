#include<bits/stdc++.h>//这个头文件包含了所有的头文件
using namespace std;

int main(){
    //流同步，效率更高，但是c++和c不能混用
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    const int N = 10000;
    int a[N]={0};
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        a[i]+=a[i-1];
    }
    while(m--){
        int l,r;
        cin>>l>>r;
        cout<<a[r]-a[l-1]<<endl;
    }
}