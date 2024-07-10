#include "data_type.h"
#include "deal.h"
#include "server.h"

// 用户文件的加载
void load_user()
{
    if (NULL == userhead)
    {
        printf("头节点为空\n");
        return ;
    }
    FILE *fp_user = fopen("user.txt", "r"); // 打开文件
    if (fp_user == NULL)
    {
        system("touch user.txt"); // 不存在就创建
        return ;
    }

    User user;
    while (fscanf(fp_user, "用户名:%s\t\t密码:%s\n", user.username, user.passwd) != EOF)
    {
        insert_user(user); // 插入链表
    }
    //(fp_user,"用户名:%s\t\t密码:%s\n",user.username,user.passwd);
    fclose(fp_user);
    fp_user = NULL;

    return ;
}

//插入链表
void insert_user(User data)
{
    Userlink* cur = userhead;
    while (cur->next!=NULL)
    {
        cur = cur->next;//循环遍历到最后的节点
    }
    Userlink* newnode = calloc(1,sizeof(Userlink));
    newnode->data = data;
    newnode->next = NULL;
    cur->next = newnode;
}

//保存链表
void save_user()
{
    if (NULL == userhead)
    {
        printf("头节点为空\n");
        return;
    }
    FILE* fp_user = fopen("user.txt","w");
    if (NULL == fp_user)
    {
        printf("文件打开失败\n");
        return ;
    }
    Userlink* cur = userhead;
    cur = cur->next;
    while (cur != NULL)
    {
        fprintf(fp_user,"用户名:%s\t\t密码:%s\n",cur->data.username,cur->data.passwd);
        cur = cur->next;
    }
    fclose(fp_user);
    fp_user = NULL;
    
    return;
}