#include <stdio.h>

typedef struct node{
    int data;//数据域

    struct node * next ;//指针域
}Node;

int main()
{
    //创建结构体节点
    Node node1,node2,node3;

    //初始化数据，数据域赋值
    node1.data = 1;
    node2.data = 2;
    node3.data = 3;

    //构建节点之间的关系
    node1.next=&node2;
    node2.next=&node3;
    node3.next=NULL;

    //初始化 定义一个指针，指向第一个元素
    Node * currentNode = &node1;
    while (currentNode !=NULL)
    {
        printf("%d ",currentNode->data);
        //当前 node 指向下一个
        currentNode = currentNode->next;
    }
    

    

    return 0;
    
}