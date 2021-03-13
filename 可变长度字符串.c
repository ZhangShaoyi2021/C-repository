#include <stdio.h>
#include "list.h"

int main(void)
{
    LISTDATA strNode; //声明数据结构体strNode
    list str = newList(); //创建链表str
    char c_input;
    for(int i = 1;i<=10;i++){
        printf("请输入一个字符串:");
        while((c_input = getchar()) != '\n'){
            strNode.c = c_input; //把输入写进strNode的c成员
            newData(str,strNode); //把strNode加入str链表
        }
        
        int max=lenList(str)-1;//max = str链表的长度
        int index=0;
        char now_char;
        for(;index <= max;++index){ //遍历str
            now_char = getValue(str,index).c; //从str取出指定下标的数据结构体的c成员
            printf("%c",now_char); //打印c成员
        }
        printf("\n"); 
        
        emptyList(str); //清空str,迎接下一次循环
    }
    deleteList(str); //最后删除str
    return 0;
}
