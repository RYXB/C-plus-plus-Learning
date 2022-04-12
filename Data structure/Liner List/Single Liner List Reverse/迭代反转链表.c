#include <stdio.h>
#include <stdlib.h>
//参考：https://blog.csdn.net/m0_62436868/article/details/123174059

//声明节点结构
typedef struct Link {
    int elem; //存储整形元素
    struct Link *next;//指向直接后继元素的指针
}link;

//先声明所有使用的函数
link *initLink();
//初始化链表
link *iteration_reverse(link *p);
//反转
void display(link *p);
//遍历展示链表

int main(){
    link *p =NULL;
    printf("初始化链表为：\n");
    p = initLink();
    display(p);

    printf("迭代反转链表后：\n");
    p = iteration_reverse(p);
    display(p);
}
//创建链表的函数（无头结点）
link *initLink(){
    int i;
    link *p = NULL;//创建头指针
    link *temp = (link*)malloc(sizeof(link));//创建首元节点
    //首元结点初始化
    temp->elem = 1;
    temp->next = NULL;
    p = temp;//头指针指向首元节点
    //生成链表
    for(i =2 ;i<5;i++){
        //创建节点并初始化
        link *a = (link*)malloc(sizeof(link));
        a->elem = i;
        a->next = NULL;
        //建立新节点与直接前驱节点的逻辑关系
        temp->next = a;
        temp = temp->next;
    }
    return p;
}

//迭代反转法， head 为无头节点链表的头指针
link *iteration_reverse(link *p){
    link *head = p;
    if(head == NULL){
        return NULL;
    }
    if(head->next == NULL){
        return head;
    }
    link *beg = head;
    link *mid = head->next;
    link *end = mid->next;

    beg->next = NULL;//头插法
    //一直遍历
    while(mid!=NULL)
    {
        mid ->next= beg;
        beg = mid;
        mid = end;
        if(end !=NULL){
            end = end->next;
        }
    }
     return beg;
}

void display(link *p){
    link *temp = p;
    while(temp){
        printf("%d ", temp->elem);
        temp = temp->next;
    }
    printf("\n");
}
