#include<iostream>
using namespace std;

/*传统冒泡排序中每一趟排序操作只能找到一个最大值或最小值
我们考虑利用在每趟排序中进行正向和反向两遍冒泡的方法一次可以得到两个最终值(最大者和最小者)
从而使排序趟数几乎减少了一半。*/

void print(int a[],int n,int i){
    cout<<"第"<<i+1<<"趟：";
    for(int j=0;j<n;j++){
        cout<<a[j]<<" ";
    }
    cout<<endl;
}

void BubbleSortTwoNeedle(int a[],int n){
    int low = 0;
    int high = n-1;
    int temp,j;
    while(low < high){
        for (j=low;j<high;++j){//正向冒泡,找到最大者
            if(a[j]>a[j+1]){
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
         --high;//修改high值, 前移一位
        for(j=high;j>low;--j){//反向冒泡,找到最小者
            if(a[j]<a[j-1]){
                temp = a[j];
                a[j] = a[j-1];
                a[j-1] = temp;
            }
        }
        ++low;//修改low值,后移一位
        print(a,n,j);
    }
}

int main(){
    int a[8] = {49,38,65,97,76,13,27,49};
    cout<<"初始值：";
    for(int j=0;j<8;++j){
        cout<<a[j]<<" ";
    }
    cout<<endl<<endl;
    BubbleSortTwoNeedle(a,8);
}
