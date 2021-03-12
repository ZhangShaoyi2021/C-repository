//list.h:链表ADT头文件

#ifndef __LIST_H
#define __LIST_H

//宏、类型定义：

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
//使用时自行修改LISTDATA结构
typedef struct dataField{
    char c;
}LISTDATA;
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

typedef struct NODE{
    LISTDATA data;
    struct NODE* next; //指针域 next指针
}node;
typedef struct LISTSTR{
    node* head;
    node* end;
    int len;
}listStruct;
typedef listStruct* list;

//函数定义：

list newList(void); //新建一个初始化链表
/*返回一个新链表，参数:没有*/

int newData(list,LISTDATA); //给链表加入新数据
/*给链表加入数据，参数:一个链表、一个数据结构体*/

LISTDATA getValue(list,int); //取链表值
/*取出某个链表值，参数:一个链表，一个下标*/

int freeList(list); //释放整个链表
/*把列表内存全部释放，参数:一个链表*/

int lenList(list); //链表节点个数计算
/*返回链表的节点个数，参数:一个链表*/

int delementList(list,int); //删除列表元素
/*删除某个链表值，参数:同getValue()*/

#endif
