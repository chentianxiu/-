#include <stdio.h>
#include<stdlib.h>

//声明链表节点结构体节点
typedef struct Linked_Node
{
    int data;//数据域
    struct Linked_Node * next;   //指针域
}Node,*LinkedList;//起别名

//定义创建空链表的函数
Node * create_LinkedList(){
    //创建头指针
    Node *header =NULL;
    //动态创建一个空间
    header = (Node *)malloc(sizeof(Node));
    //判断内存是否创建成功
    if (header == NULL){
        printf("内存创建失败\n");
        return NULL;
    }
    //空节点，将next域置空
    header->next = NULL;
    
    return header;
    
}


int main()
{   
    //创建链表 也就是创建一个头指针（头节点）
    //Node * node = create_LinkedList();
    LinkedList linkedlist = create_LinkedList();

    //linkedlist  增加元素

    //linkedlist  修改元素

    //linkedlist  删除元素

    //linkedlist  查询元素


    return 0;
    
}