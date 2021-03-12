#include <stdio.h>
#include "list.h"
 /*已在list.h中改变LISTDATA结构体*/
int main(void)
{
    LISTDATA strNode; //创建数据结构体strNode
    list str = newList(); //创建链表str
    char c_input;
    printf("请输入一个字符串:");
    while((c_input = getchar()) != '\n'){
        strNode.c = c_input; //把输入写入数据结构体的c成员
        newData(str,strNode); //新增节点strNode
    }
    int max = lenList(str)-1; //最大遍历量
    int index = 0;//索引
    for(;index <= max;++index){
        char now_char = getValue(str,index).c; //遍历取值
        printf("%c",now_char);//打印
    }
    printf("\n");
    freeList(str); //释放链表
    return 0
}

