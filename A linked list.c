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
        printf("%s %d岁\n",dataNow.name,dataNow.age);
    }
    printf("共有%d名学生\n",lenList(stuList));
    freeList(stuList);
    return 0;
}

list newList(void) //新建一个初始化链表
{
    list linkedList = (list)malloc(sizeof(listStruct));
    if(linkedList == NULL) return NULL;
    linkedList->head = NULL;
    linkedList->end = NULL;
    linkedList->len = 0;
    return linkedList;
}

int newData(list linkedList,DATA data) //给链表加入新数据
{
    if(linkedList == NULL) return -1;
    node* newNode = (node*)malloc(sizeof(node)); //申请一片内存
    newNode->data = data;

    if(linkedList->head == NULL){ //假如新增入节点是第一个节点
        linkedList->head = (node*)malloc(sizeof(node));
        if(linkedList->head == NULL) return -1;
        linkedList->head->next = newNode;
        linkedList->end = newNode;
        linkedList->end->next = NULL; //将下一个节点的next指针设为NULL
    }else{
        linkedList->end->next = newNode;
        linkedList->end = newNode;
        linkedList->end->next = NULL;
    }
    linkedList->len += 1;
    return 0;
}

DATA getValue(list linkedList,int index) //取链表值
{
    node* h = linkedList->head;
    int i = -1;
    for(;h!=NULL;h=h->next,++i){
        if(h != linkedList->head && i == index)
            return h->data;
    }
    return linkedList->head->data;
}


int freeList(list linkedList) //释放整个链表
{
    node* traversePo = linkedList->head;
    node* nextPo;
    for(;traversePo!=NULL;traversePo=nextPo)
    {
        nextPo = traversePo->next;
        free(traversePo);
    }
    return 0;
}

int lenList(list linkedList) //链表节点个数计算
{
    int lene = linkedList->len;
    return lene;
}

