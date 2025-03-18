#include<bits/stdc++.h>
using namespace std;


int main(){
    int n;cin>>n;
    int len=0;
    int a[10000],s[10000];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0,j=0;i<n;i++){
        s[a[i]]++;
        while(j<=i&&s[a[i]]>1){
            s[a[j]]--;
            j++;
        }
        len=max(len,i-j+1);
    }
    cout<<len<<endl;
    return 0;
}