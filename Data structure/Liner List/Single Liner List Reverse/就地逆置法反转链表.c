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
link *local_reverse(link *p);
//反转
void display(link *p);
//遍历展示链表


int main(){
    link *p =NULL;
    printf("初始化链表为：\n");
    p = initLink();
    display(p);

    printf("迭代反转链表后：\n");
    p = local_reverse(p);
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

link *local_reverse(link *p){
    link *head = p;
    link *beg = NULL;
    link *end = NULL;

    if(head==NULL||head->next==NULL){
        return head;
    }
    beg = head;
    end = head->next;

    while(end!=NULL){
       //将 end 从链表中摘除
       beg->next = end->next;
       //将 end 移动至链表头
       end->next = head;
       head = end;

       //调整 end 的指向， 另其指向 beg 后的一个节点， 为反转下一个节点做准备
       end = beg->next;
    }
    return head;
}

void display(link *p){
    link *temp = p;
    while(temp){
        printf("%d ", temp->elem);
        temp = temp->next;
    }
    printf("\n");
}
