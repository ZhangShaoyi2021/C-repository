#include <stdio.h>
#include <stdlib.h> //为malloc()与free()提供原型
#include <string.h> //为strcmp()提供原型

#define MAX 5 //名字最多字数
#define INDEX 5*3  //实际字符数（兼容中文）

typedef struct dataField{
    int age; //年龄
    char name[INDEX]; //名字
}DATA;

typedef struct NODE{
    DATA data;
    struct NODE* next; //指针域 next指针
}node;

typedef struct LISTSTR{
    node* head;
    node* end;
    int len;
}listStruct;

typedef listStruct* list;

list newList(void); //新建一个初始化链表
/*返回一个新链表，参数:没有*/

int newData(list,DATA); //给链表加入新数据
/*给链表加入数据，参数:一个链表、一个名称，一个年龄*/

DATA getValue(list,int); //取链表值
/*取出某个链表值，参数:一个链表，一个下标*/

int freeList(list); //释放整个链表
/*把列表内存全部释放，参数:一个链表*/

int lenList(list); //链表节点个数计算
/*返回链表的节点个数，参数:一个链表*/

int delementList(list,int); //删除列表元素
/*删除某个链表值，参数:同getValue()*/

int main(void)
{
    list stuList = newList();
    DATA studata;
    char in_name[INDEX];
    int in_age;
    for(;;){
        printf("输入学生姓名(0表示停止输入):");
        scanf("%s",in_name);
        if(!strcmp(in_name,"0"))
            break;
        printf("输入学生年龄:");
        scanf("%d",&in_age);
        strcpy(studata.name,in_name);
        studata.age = in_age;
        newData(stuList,studata);
        
    }
    for(int i=0;i<=lenList(stuList)-1;++i){
        DATA dataNow = getValue(stuList,i);
        printf("%5s %3d岁\n",dataNow.name,dataNow.age);
    }
    printf("共有%d名学生\n开除第二个学生\n还剩:\n",lenList(stuList));
    delementList(stuList,1);
    for(int i=0;i<=lenList(stuList)-1;++i){
        DATA dataNow = getValue(stuList,i);
        printf("%5s %3d岁\n",dataNow.name,dataNow.age);
    }
    freeList(stuList);
    return 0;
}

list newList(void) //新建一个初始化链表
{
    list linkedList = (list)malloc(sizeof(listStruct)); //给链表ADT申请一片内存
    if(linkedList == NULL) return NULL; //申请失败返回NULL
    linkedList->head = NULL;
    linkedList->end = NULL;  //初始化值
    linkedList->len = 0;
    return linkedList;
}

int newData(list linkedList,DATA data) //给链表加入新数据
{
    node* newNode = (node*)malloc(sizeof(node)); //为新节点申请一片内存
    if(newNode == NULL) return -1; //申请失败返回-1
    newNode->data = data; //写入数据

    if(linkedList->head == NULL){ //假如新增入节点是第一个节点
        linkedList->head = (node*)malloc(sizeof(node)); //先给head申请内存
        if(linkedList->head == NULL) return -1; //申请失败返回-1
        linkedList->head->next = newNode; //把新节点写到head的下一个节点
        
    }
    else
        linkedList->end->next = newNode;//把新节点附加在尾节点后
    linkedList->end = newNode; //最新增入节点设为尾节点
    linkedList->end->next = NULL; //将尾节点的next指针设为NULL
    linkedList->len += 1; //长度加1
    return 0;
}

DATA getValue(list linkedList,int index) //取链表值
{
    index++; //循环次数等于索引加1
    if(index > linkedList->len) return linkedList->head->data;
    //若索引超出长度，返回空结构体（head节点的结构体不放数据）
    node* h = linkedList->head;
    for(int i=0;i!=index;++i)
        h = h->next; //循环到目标节点
    return h->data;//返回数据结构体
        
}

int delementList(list linkedList,int index) //删除链表值
{
    if(index > linkedList->len) return -1;
    //若索引超出长度，返回-1表示错误
    node* h = linkedList->head; 
    /*与getValue()的不同之处:循环次数不加1*/
    for(int i=0;i!=index;++i)
        h = h->next; //循环到目标节点的上一个节点
    node* deleteNode = h->next; //待删除节点
    node* nextNode = deleteNode->next; //待删除节点的下一个节点
    h->next = nextNode; //跳过待删除节点，直接连到待删除节点的下一个节点
    /*如果nextNode是NULL，那么h->next也会被设成NULL*/
    free(deleteNode); //释放待删除节点
    linkedList->len -= 1; //减少长度
    return 0;
}

int freeList(list linkedList) //释放整个链表
{
    node* traversePo = linkedList->head;
    node* nextPo;
    for(;traversePo!=NULL;traversePo=nextPo){
        nextPo = traversePo->next;
        free(traversePo); //遍历链表，挨个释放
    }
    free(linkedList);//释放链表ADT
    return 0;
}

int lenList(list linkedList) //链表节点个数计算
{
    int lene = linkedList->len;//直接取到长度返回
    return lene;
}


