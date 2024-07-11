#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include "node.h"


//定义创建空链表的函数
Node *create_LinkedList(){
    //创建头指针
    Node *header =NULL;
    //动态创建一个空间
    header = (Node*)malloc(sizeof(Node));
    //判断内存是否创建成功
    if (header == NULL){
        printf("内存创建失败\n");
        return NULL;
    }
    //空节点，将next域置空
    header->next = NULL;
    
    return header;
    
}


//添加尾节点
void add_linkedlist(LinkedList linkedlist,int data){
    //linkedlist  增加元素
    //1.链表插入元素,尾部插入
    //第一步,定位到链表尾节点
    while (NULL != linkedlist->next)
    {
        //指针后移，指向下一个节点
        linkedlist = linkedlist->next;
    }
    Node *new_node = (Node*)calloc(1,sizeof(Node));//创建新节点
    if (new_node==NULL)
    {
        printf("内存申请失败\n");
        return;
    }
    new_node->data = data;//新节点赋值
    new_node->next = NULL;
    linkedlist->next = new_node;
}



//遍历链表
void printf_linklist(LinkedList linkedlist){
    //判断是否为空
    if(linkedlist->next ==NULL){
        printf("空表\n");
        return;
    }

    //定义一个当前节点
    LinkedList list = linkedlist->next;
    while (list!=NULL)
    {
        printf("%d ",list->data);
        //打印数据完成后，节点后移
        list = list->next;
    }
    printf("\n");
    
    return;

}


//linkedlist  删除元素,删除末尾元素
void delete_linkedlist(LinkedList linkedlist){
    //判断链表是否为空
    if(linkedlist->next==NULL){
        printf("此链表为空表，不能删除\n");
        return;
    }
    //循环列表,考略到只有一个节点的情况
    while (linkedlist->next!=NULL)
    {
        //list = list->next;
        //找到倒数第二位：list->next->next==NULL
        if(NULL==linkedlist->next->next){
            break;
        }
        linkedlist = linkedlist->next;
    }
    //删除最后一个节点
    Node *delete_node=linkedlist->next;
    //删除
    free(delete_node);
    delete_node=NULL;
    
    //倒数第二位，指针域置空
    linkedlist->next=NULL;
    
}

//修改节点
void update_linkedlist(LinkedList linkedlist,int olddata,int newdata){
    //定义当前节点
    LinkedList list =linkedlist->next;
    //循环
    while (list!=NULL)
    {
        if (list->data==olddata)
        {
            list->data=newdata;
            return;
        }
        list = list->next;
    }
    printf("没有找到该元素\n");
    //添加return：只修改第一次出现的数据‘
    //不添加return：所有出现的数据都进行修改
}

//链表查询元素
void find_linkedlist(LinkedList linkedlist,int value){
    //定义当前节点
    LinkedList list =linkedlist->next;
    //循环
    while (list!=NULL)
    {
        //找到条件
        if(value ==list->data){
            printf("找到了\n");
            return;
        }
        list=list->next;
    }
    printf("该元素不存在\n");
    return;

    //添加return：查找第一次出现
    //不写return：可以定义一个变量，进行统计出现的个数

}

//添加节点（链表的元素）：任意位置
//参数：你想要添加元素的链表，你想再什么地方插入，你需要添加的值

void add_linkedlistbydata(LinkedList linkedlist,int data,int newdata){
    //1、找到插入点之前的节点
    //为了让首元节点之前也能添加元素，故,头指针开始遍历
    while (linkedlist->next!=NULL)
    {
        //满足的节点位置
        if (linkedlist->next->data==data)
        {
            break;
        }
        //指向下一个节点
        linkedlist=linkedlist->next;
    }
    if (linkedlist==NULL)
    {
        printf("没有找到需要插入的位置\n");
        return;
    }
    //经过whlie循环后，linkedlist成为插入节点的前一个节点
    //插入功能
    //创建新节点
    Node *new_Node = (Node*)calloc(1,sizeof(Node));

    //判断
    if (new_Node==NULL)
    {
        printf("分配失败:\n");
        return;
    }
    
    //赋值

    new_Node->data = newdata;
    new_Node->next = NULL;

    //新节点的重新赋值以及指针域重新赋值
    new_Node->data=newdata;
    //新节点的指针域指向原来linkedlist指向的节点
    new_Node->next=linkedlist->next;
    //linkedlist的指针域指向新节点
    linkedlist->next = new_Node;
}


//任意删除
void delete_linkedlistbydata(LinkedList linkedlist,int delete_data){
    //判断链表是否为空
    if (linkedlist->next==NULL)
    {
        printf("链表为空，无法删除\n");
        return;
    }
    
    //如果删除的是首元节点，所以指针从头节点遍历
    while (linkedlist->next!=NULL)
    {   
        //当前节点数据满足删除条件
        if (linkedlist->next->data==delete_data)
        {
            printf("找到了删除节点\n");
            break;
        }
        linkedlist=linkedlist->next;
    }
    //删除功能
    //如果没有找到需要删除的元素
    if (linkedlist->next==NULL)//和老师的不一样
    {
        printf("没有找到这个节点\n");
        return;
    }
    //找到了，经过while循环后linklist成为需要删除节点的前一个指针
    Node *delete_node = linkedlist->next;

    //linklist的指向域指向该删除节点指向的区域
    linkedlist->next = delete_node->next;

    free(delete_node);
    delete_node = NULL;
    return;

}
