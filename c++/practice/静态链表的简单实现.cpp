#include<iostream>
#define maxsize 100
using namespace std;

struct student{
    int data;
    int cur;
};

//初始化静态链表
void InitList(student space[]){
    for(int i=0;i<maxsize-1;i++){
        space[i].cur=i+1;
    }
    space[maxsize-2].cur=0;
    space[maxsize-1].cur=0;
}
//模拟分配内存
int malloc_List(student space[]){
int i=space[0].cur;
if(space[0].cur){
    space[0].cur=space[i].cur;
     return i;
}
}
//静态链表的长度
int LengthList(student space[]){
    int count=0;
  for(int i=space[maxsize-1].cur;i!=0;i=space[i].cur){
        count++;
  }
    return count;
}
//插入元素
bool InsertList(student space[],int node,int data){
    if(node<1||node>LengthList(space)+1){
        return false;
    }
    //创建新节点
    int new_cur=malloc_List(space);

    if(new_cur){
        space[new_cur].data=data;
        int cur=maxsize-1;//cur=99
        for(int i=1;i<node;i++){
           // cout<<space[cur].cur<<"   ";
            cur=space[cur].cur;
        }
        //cout<<cur<<endl;
        space[new_cur].cur=space[cur].cur;
        space[cur].cur=new_cur;
        return true;
    }
return false;
}
//释放一个节点
void FreeList(student space[],int k){
    space[k].cur=space[0].cur;
    space[0].cur=k;
}
//删除元素
bool DeleteList(student space[],int node){
    if(node<1||node>LengthList(space)){
        return false;
    }
    int cur=maxsize-1;
    for(int i=1;i<node;i++){
        cur=space[cur].cur;
    }
    int temp=space[cur].cur;
    space[cur].cur=space[temp].cur;
    FreeList(space,temp);
    return true;
}
//打印节点数据域
void PrintList(student space[]){
    int i=space[maxsize-1].cur;
    while(i){
        cout<<space[i].data<<" ";
        i=space[i].cur;
    }
}
int main(){
    student StaticList[maxsize];
    InitList(StaticList);
    InsertList(StaticList,1,10);
    InsertList(StaticList,2,20);
    InsertList(StaticList,3,30);
    cout<<" "<<StaticList[maxsize-1].cur<<endl;
    //InsertList(StaticList,2,40);
    //PrintList(StaticList);
    //DeleteList(StaticList,2);
    //cout<<endl;
    //cout<<LengthList(StaticList)<<endl;
    
   // PrintList(StaticList);
    return 0;
}
//maxsize为什么能指向头节点