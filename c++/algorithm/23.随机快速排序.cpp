#include<bits/stdc++.h>
using namespace std;
std::vector<int> arr = {8,7,9};
int partition1(int l,int r,int x){
	int a=l;
	int xi=0;
for(int i=l;i<=r;i++){
	if(arr[i]<=x){
		swap(arr[a],arr[i]);
		if(arr[a]==x){
			xi=a;
		}
		a++;
	}
}
	swap(arr[xi],arr[a-1]);
	return a-1; 
}
int first,last;
void partition2(int l,int r,int x){
	first=l;
	last=r;
	int i=l;
  while(i<=last){
  	if(arr[i]==x){
  		i++;
	  }else if(arr[i]<x)
	  {
	  	swap(arr[i++],arr[first++]);
	  }else {
	  	swap(arr[i],arr[last--]);
	  }
  }
	}
	//传统随机快速排序  
void quicksort1(int l,int r){
	if(l>=r)
	return ;
	int x=arr[l+rand()%(r-l+1)];
	int mid=partition1(l,r,x);
	quicksort1(l,mid-1);
	quicksort1(mid+1,r);
}
//荷兰国旗问题优化
//可以解决数组里有多个x相同值，更高效  
void quicksort2(int l,int r){
	if(l>=r)
	return ;
	int x=arr[l+rand()%(r-l+1)];
	partition2(l,r,x);
	int left=first;
	int rig=last;
	quicksort2(l,first-1);
	quicksort2(last+1,r);
}
int main(){
	srand(time(0));
	//quicksort1(0,arr.size()-1);
	quicksort2(0,arr.size()-1);
    for (auto& a : arr) {
        cout << a << " ";
    }
    cout << endl;
	return 0;
} 
