#include <iostream>
using namespace std;

void print(int a[],int n,int i){
    cout<<"第"<<i+1<<"趟：";
    for(int j=0;j<8;j++){
        cout<<a[j]<<" ";
    }
    cout<<endl;
}

void swap(int a[],int i,int j){
    int temp;
    if(i == j){
        return;
    }
    temp = a[i];
    a[i]=a[j];
    a[j] =temp;
}

//类似双指针
void BinarySelectSort(int a[],int n)
{
    int i,j,max,min;
    for(i=1;i<n/2;++i){
            max = i;
            min = j;
        for(j = i+1;j<n-i;++i){
            if(a[j]>a[max]){
                max = j;
                continue;
            }
            if(a[j]<a[min]){
                min = j;
            }
        }
        swap(a,i-1,min);
        if(i==max){
            max = min;
        }
        swap(a,n-1,max);
    }
}



int main(){
    int a[8] = {3,1,5,7,2,4,9,6};
    cout<<"初始值：";
    for(int j=0;j<8;++j){
        cout<<a[j]<<" ";
    }
    cout<<endl<<endl;
    BinarySelectSort(a,8);
    print(a,8,8);
}
