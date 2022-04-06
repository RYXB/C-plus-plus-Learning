#include<iostream>
using namespace std;

/*基本思想：

1）选择一个基准元素,通常选择第一个元素或者最后一个元素,

2）通过一趟排序讲待排序的记录分割成独立的两部分，其中一部分记录的元素值均比基准元素值小。另一部分记录的 元素值比基准值大。

3）此时基准元素在其排好序后的正确位置

4）然后分别对这两部分记录用同样的方法继续进行排序，直到整个序列有序。*/

void print(int a[],int n){
    for(int j=0;j<n;j++){
        cout<<a[j]<<" ";
    }
    cout<<endl;
}

int partition(int a[],int low, int high){
    int pivotKey = a[low];//基准元素

    while (low < high){//从表的两端交替地向中间扫描
        while(low < high && a[high] >= pivotKey){
            --high;//从high 所指位置向前搜索，至多到low+1 位置。将比基准元素小的交换到低端
        }
        a[low] = a[high];
        while(low < high && a[low] <=pivotKey){
            ++low;
        }
        a[high] =a[low];
    }
    a[low] = pivotKey;
    print(a,10);
    return low;
}


void QuickSort(int a[],int low,int high){
    if(low < high){
        int privotLoc = partition(a,low,high);//将表一分为二
        QuickSort(a,low,privotLoc - 1);//递归对低子表递归排序
        QuickSort(a,privotLoc+1,high);//递归对低子表递归排序
    }
}

int main(){
    int a[10] = {3,1,5,7,2,4,9,6,10,8};
    cout<<"初始值：";
    print(a,10);
    QuickSort(a,0,9);
    cout<<"结果：";
    print(a,10);
}
