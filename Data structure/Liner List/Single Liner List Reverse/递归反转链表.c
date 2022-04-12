#include <stdio.h>
#include <stdlib.h>

//声明节点结构
typedef struct Link {
    int elem; //存储整形元素
    struct Link *next;//指向直接后继元素的指针
}link;

//先声明所有使用的函数
link *initLink();
//初始化链表
link *recursive_reverse(link *p);
//反转
void display(link *p);
//遍历展示链表

int main(){
    link *p =NULL;
    printf("初始化链表为：\n");
    p = initLink();
    display(p);

    printf("迭代反转链表后：\n");
    p = recursive_reverse(p);
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

link *recursive_reverse(link *p){
    link *head = p;
    //递归的出口
    if (head == NULL || head->next == NULL) // 空链或只有一个结点， 直接返回头指针
    {
        return head;
    }else{
        //一直递归， 找到链表中最后一个节点
        link *new_head = recursive_reverse(head->next);
        //当逐层退出时， new_head 的指向都不变， 一直指向原链表中最后一个节点；
        //递归每退出一层， 函数中 head 指针的指向都会发生改变， 都指向上一个节点。
        //每退出一层， 都需要改变 head->next 节点指针域的指向， 同时令 head 所指节点的指针域为 NULL。
        head->next->next=head;
        head->next = NULL;
        //每一层递归结束， 都要将新的头指针返回给上一层。 由此， 即可保证整个递归过程中， 能够一直找得到新链表的表头。
        return new_head;
    }
}



void display(link *p){
    link *temp = p;
    while(temp){
        printf("%d ", temp->elem);
        temp = temp->next;
    }
    printf("\n");
}
