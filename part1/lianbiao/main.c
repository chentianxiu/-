#include <stdio.h>
#include<stdlib.h>
#include "node.h" 


int main()
{   

    int data1 = 10;
    //创建链表 也就是创建一个头指针（头节点）
    //Node * node = create_LinkedList();
    LinkedList linkedlist = create_LinkedList();
    add_linkedlist(linkedlist,3);
    add_linkedlist(linkedlist,6);
    add_linkedlist(linkedlist,9);
    add_linkedlist(linkedlist,12);
    printf_linklist(linkedlist);
    //删除之后，遍历
    //delete_linkedlist(linkedlist);
    //printf_linklist(linkedlist);
    //update_linkedlist(linkedlist,6,7);
    //printf_linklist(linkedlist);
   // find_linkedlist(linkedlist,10);

    //linkedlist  修改元素

    

    //linkedlist  查询元素

    //删除指定元素
    //delete_linkedlistbydata(linkedlist,7);

    //printf_linklist(linkedlist);

    //delete_linkedlistbydata(linkedlist,10);


    return 0;
    
}








