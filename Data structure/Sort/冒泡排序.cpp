#include<iostream>
using namespace std;

void print(int a[],int n,int i){
    cout<<"第"<<i+1<<"趟：";
    for(int j=0;j<n;j++){
        cout<<a[j]<<" ";
    }
    cout<<endl;
}


void BubbleSort(int a[],int n){
    for(int i=0;i< n-1;++i){
        for(int j =0;j<n-i-1;++j){
            if(a[j]>a[j+1]){
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
        print(a,n,i);
    }
}

int main(){
    int a[8] = {49,38,65,97,76,13,27,49};
    cout<<"初始值：";
    for(int j=0;j<8;++j){
        cout<<a[j]<<" ";
    }
    cout<<endl<<endl;
    BubbleSort(a,8);
}
