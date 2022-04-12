#include <stdio.h>
#include <stdlib.h>

//声明节点结构
typedef struct Link {
    int elem; //存储整形元素
    struct Link *next;//指向直接后继元素的指针
}link;

//先声明所有使用的函数
link *initLink();
//链表插入的函数，p是链表，elem是插入的结点的数据域，add是插入的位置
link *insertElem(link * p, int elem, int add);
//删除结点的函数，p代表操作链表，add代表删除节点的位置
link *delElem(link * p, int add);
//查找结点的函数，elem为目标结点的数据域的值
int selectElem(link * p, int elem);
//更新结点的函数，newElem为新的数据域的值
link *replaceElem(link * p, int add, int newElem);
void display(link *p);

int main(){
    link *p =NULL;
    int address;
    //初始化链表（1，2，3，4）
    printf("初始化链表为：\n");
    p = initLink();
    display(p);

    //在第4的位置插入元素5：（1，2，3，5, 4）
    printf("在第4的位置插入元素5：\n");
    p = insertElem(p, 5, 4);
    display(p);

    //删除元素3:（1，2，5, 4）
    printf("删除元素3:\n");
    p = delElem(p, 3);
    display(p);

    //元素2的位置为：2
    printf("查找元素2的位置为：\n");
    address = selectElem(p, 2);
    if (address == -1) {
        printf("没有该元素");
    }
    else {
        printf("元素2的位置为：%d\n", address);
    }

    //更改第3的位置上的数据为7:（1，2，7, 4）
    printf("更改第3的位置上的数据为7:\n");
    p = replaceElem(p, 3, 7);
    display(p);

    return 0;
}


//创建链表的函数
link *initLink(){
    link *p = (link*)malloc(sizeof(link));//创建一个头结点
    link *temp = p;//声明一个指针指向头结点，用于遍历链表(这个即为头结点)
    int i  = 0;
    //生成链表
    for(i =1 ;i<5;i++){
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

//p为原链表，elem表示新数据元素，add表示新元素要插入的位置
link *insertElem(link *p, int elem, int add) {
    link *temp = p;//创建临时结点temp
    link *c = NULL;
    int i = 0;
    //首先找到要插入位置的上一个结点
    for (i = 1;i< add ;i++){
        if(temp==NULL){
            printf("插入位置无效\n");
            return p;
        }
        temp = temp->next;
    }
    //创建插入结点c
    c = (link*)malloc(sizeof(link));
    c->elem = elem;
    c->next = temp->next;
    temp->next = c;

    return p;
}

//p为原链表，add为要删除元素的值
link *delElem(link *p,int add){
    link *temp = p;
    link *del = NULL;
    int i = 0;
    for(i=1;i<add;i++){
        temp = temp->next;
    }
    del = temp->next;//单独设置一个指针指向被删除结点，以防丢失
    temp->next = temp->next->next;//删除某个结点的方法就是更改前一个结点的指针域
    free(del);//手动释放该结点，防止内存泄漏
    return p;
}

//p为原链表，elem表示被查找元素、
int selectElem(link *p,int elem){
    //新建一个指针t，初始化为头指针 p
    link *t = p;
    int i = 1;
    //新建一个指针t，初始化为头指针 p
    while (t->next){
        t = t->next;
        if(t->elem == elem){
            return i;
        }
        i++;
    }
    //程序执行至此处，表示查找失败
    return -1;
}

//更新函数，其中，add 表示更改结点在链表中的位置，newElem 为新的数据域的值
link *replaceElem(link *p,int add,int newElem){
    int i = 0;
    link *temp = p;
    temp = temp->next;//在遍历之前，temp指向首元结点
    //遍历到被删除结点
    for(i = 1;i<add;i++){
        temp = temp->next;
    }
    temp->elem = newElem;
    return p;
}

void display(link *p){
    link *temp = p;//将temp指针重新指向头结点
    //只要temp指针指向的结点的next不是Null，就执行输出语句。
    while(temp->next){
        temp = temp->next;//跳过头结点
        //遍历到每个结点，打印数据域对应的值
        printf("%d ", temp->elem);
    }
    printf("\n");
}


