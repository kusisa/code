#include<bits/stdc++.h>
using namespace std;

int main(){

    int a[1000],b[1000];
    int n,m,x;cin>>n>>m>>x;
int i,j;//双指针
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    for(j=0;j<m;j++){
        cin>>b[j];
    }
//两个数组必须升序升序输入，排序后原来的a[i]与原来的a[i]值不一样，该方法失效

    for(i=0,j=m-1;i<n;i++){
        while(j>=0&&a[i]+b[j]>x){
            j--;
        }
        if(j>=0&&a[i]+b[j]==x){
            cout<<i<<" "<<j<<endl;
            break;
        }
    }
}