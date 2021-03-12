# C-repository
一个自己搞的链表ADT，以一个类型为LISTDATA的结构体作为每个节点的数据域
在仓库里附有一个使用实例

ADT类型:
    链表类型 : list
    数据结构类型 :LISTDATA

可用的函数:
list newList(void);
返回一个新链表，参数:没有
成功返回一个链表，不成功返回NULL

int newData(list,LISTDATA)
给链表加入数据，参数:一个链表、一个数据结构体
成功返回0，不成功返回-1

LISTDATA getValue(list,int)
取出某个链表值，参数:一个链表，一个下标
成功返回指定链表数据域，不成功返回空LISTDATA结构体

int freeList(list)
把列表内存全部释放，参数:一个链表
返回0

int lenList(list)
返回链表的节点个数，参数:一个链表
返回节点个数

int delementList(list,int)
把指定列表元素删除，参数:同getValue()
返回0

提示:
如果希望获得一个链表，只能通过newList()函数.
如果希望使用这个ADT，请自行修改list.h文件中定义的LISTDATA结构的成员