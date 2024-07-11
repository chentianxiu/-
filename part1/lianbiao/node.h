#ifndef _NODE_H
#define _NODE_H


//声明链表节点结构体节点
typedef struct Linked_Node
{
    int data;//数据域
    struct Linked_Node * next;   //指针域
}Node,*LinkedList;//起别名

//定义创建空链表的函数
Node *create_LinkedList();

//添加节点
void add_linkedlist(LinkedList Linkedlist,int data);

//遍历链表
void printf_linklist(LinkedList linklist);

//linkedlist  删除元素,删除末尾元素
void delete_linkedlist(LinkedList linkedlist);

//修改节点
void update_linkedlist(LinkedList linkedlist,int olddata,int newdata);

//查询
void find_linkedlist(LinkedList linkedlist,int value);


//任意插入
//添加节点（链表的元素）：任意位置
//参数：你想要添加元素的链表，你想再什么地方插入，你需要添加的值
void add_linkedlistbydata(LinkedList linkedlist,int data,int newdata);

//任意删除
void delete_linkedlistbydata(LinkedList linkedlist,int delete_data);
#endif