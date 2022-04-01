#include <iostream>
using namespace std;

void print(int a[],int n,int i){
    cout<<"第"<<i+1<<"趟：";
    for(int j=0;j<8;j++){
        cout<<a[j]<<" ";
    }
    cout<<endl;
}

/**
 * 数组的最小index
 *
 * @return i 数组的index
 */
int SelectMinKey(int a[],int n,int i){
    int k = i;
    for(int j=i+1;j<n;++j){
        if(a[j]<a[k]){
            k = j;
        }
    }
    return k;
}

/**
 * 简单选择排序
 *
 */
void SimpleSelectSort(int a[],int n){
    int key,temp;
    for(int i=0;i<n;++i){
        key = SelectMinKey(a,n,i); //选取最小元素的index
        if(key != i){//常见的swap算法
            temp = a[i];
            a[i] = a[key];
            a[key] = temp;
        }
        print(a,n,i);
    }
}

int main(){
    int a[8] = {3,1,5,7,2,4,9,6};
    cout<<"初始值：";
    for(int j=0;j<8;++j){
        cout<<a[j]<<" ";
    }
    cout<<endl<<endl;
    SimpleSelectSort(a,8);
    print(a,8,8);
}
