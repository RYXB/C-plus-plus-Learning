#include <stdio.h>
#include <stdlib.h>

//链表的结点，创建结构体表示，分为指针域和数据域
typedef struct Link{
    char elem; //代表数据域
    struct Link *next; //代表指针域，指向直接后继元素
}link;//link为节点名，每个节点都是一个 link 结构体

//(1)链表的初始化
//创建一个存储 {1,2,3,4} 且无头节点的链表
link *initLink1(){
    int i;
    link *p = NULL;//创建头指针
    link *temp = (link*)malloc(sizeof(link));//创建首元节点
    //首元结点初始化
    temp->elem = 1;
    temp->next = NULL;
    p = temp;//头指针指向首元节点
    //从第二个节点开始创建
     for (i = 2; i < 5; i++){
        //创建一个新节点并初始化
        link *a = (link*)malloc(sizeof(link));
        a->elem = i;
        a->next = NULL;
        //将temp节点与新建立的a节点建立逻辑关系
        temp->next = a;
        //指针temp每次都指向新链表的最后一个节点，其实就是 a节点，这里写temp=a也对
        temp = temp->next;
     }
      //返回建立的节点，只返回头指针 p即可，通过头指针即可找到整个链表
      return p;
}
void display1(link *p) {
    link *temp = p;//将temp指针重新指向头结点
    //只要temp指针指向的结点的next不是Null，就执行输出语句。
    while (temp) {
        printf("%d ", temp->elem);
        temp = temp->next;
    }
    printf("\n");
}


//(2)链表的初始化
//创建一个存储 {1,2,3,4} 且含头节点的链表
link *initLink2(){
    int i;
    link *p = (link*)malloc(sizeof(link));//创建一个头结点
    link *temp = p;//声明一个指针指向头结点，
    //生成链表
     for (i = 1; i < 5; i++){
        //创建一个新节点并初始化
        link *a = (link*)malloc(sizeof(link));
        a->elem = i;
        a->next = NULL;
        //将temp节点与新建立的a节点建立逻辑关系
        temp->next = a;
        //指针temp每次都指向新链表的最后一个节点，其实就是 a节点，这里写temp=a也对
        temp = temp->next;
     }
      //返回建立的节点，只返回头指针 p即可，通过头指针即可找到整个链表
      return p;
}
void display2(link *p){
    link* temp=p;//将temp指针重新指向头结点
    //只要temp指针指向的结点的next不是Null，就执行输出语句。
    while (temp->next) {
        temp=temp->next;
        printf("%d ",temp->elem);
    }
    printf("\n");
}

int main() {
    link*p = NULL;
    //初始化链表（1，2，3，4）
    printf("初始化链表为：\n");
    //p = initLink1();
    //display1(p);
    p = initLink2();
    display2(p);

    return 0;
}
