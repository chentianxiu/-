#include "userLink.h"

// 创建用户链表(节点)
UserLink *createUserLink()
{
    // 创建头指针
    UserLinklsit header = NULL;
    // 动态创建一个空间
    header = (UserLink *)malloc(sizeof(UserLink));
    // 判断内存是否创建成功
    if (header == NULL)
    {
        printf("内存创建失败\n");
        return NULL;
    }
    // 空节点，将next域置空
    header->next = NULL;
    return header;
}

// 添加用户(链表操作)
void InserUserNode(UserLinklsit head, UserLinklsit newNode)
{
    // 找到尾部节点
    while (head->next != NULL)
    {
        head = head->next;
    }
    // 尾插操作
    newNode->next = head->next;
    head->next = newNode;
    return;
}

// 打印节点信息
void printUserLink(UserLinklsit head)
{
    UserLink *current = head->next; // 定义一个中间变量
    while (current != NULL)
    {
        printf("用户名:%s\t用户密码%s\t用户金额%.2lf\n", current->data.username, current->data.password, current->data.money);
        current = current->next;
    }
    return;
}

// 打印当前节点信息
void printUserLinkone(UserLinklsit head, char *username)
{
    // 遍历函数到当前用户节点，打印用户账户信息
    while (head->next != NULL)
    {
        if (strcmp(head->next->data.username, username) == 0)
        {
            printf("用户名:%s\t\t密码:%s\t\t账户余额:%.2lf\n", head->next->data.username, head->next->data.password, head->next->data.money);
        }
        head = head->next;
    }
}



//充值
void Addmoney(UserLinklsit head, char *username){
    int money = 0;
    printf("请输入充值的金额\n");
    scanf("%d",&money);
    UserLink *current = head->next;
    while (current != NULL)
    {
        if (strcmp(current->data.username, username) == 0)
        {
            current->data.money +=money;
            printf("充值成功\n");
            return ;
        }
        current = current->next;
    }
}



// 用户修改密码
int ChangPwd(UserLinklsit head, char *username)
{

    while (head->next != NULL)
    {
        head = head->next;
        if (strcmp(head->data.username, username) == 0)
        {
            break;
        }
    }
    // 验证原密码
    char old_password[50];
    char flag;
    printf("请输入原密码:\n");
    scanf("%s", old_password);
    // 清空输入缓冲区
    while (getchar() != '\n')
    {
        ;
    }
    if ((strcmp(head->data.password, old_password)) != 0)
    {
        printf("您输入的原密码有误,请重新输入\n");
        printf("是否重新输入原密码?如果想退出请输入'n'\n");
        scanf("%c", &flag);
        if (flag == 'n')
        {
            return 0;
        }
        else
        {
            return ChangPwd(head, username);
        }
    }

    // 新密码录入
    char new_password[20];
    char two_password[20];
    int flag2 = 1;
    while (flag2)
    {
        printf("请输入新密码(20位以内)\n");
        scanf("%s", new_password);
        // 清空输入缓冲区
        while (getchar() != '\n')
        {
            ;
        }
        printf("请确认新密码\n");
        scanf("%s", two_password);
        // 清空输入缓冲区
        while (getchar() != '\n')
        {
            ;
        }
        // 判断长度
        if (strlen(new_password) > 20 || strlen(new_password) < 0 || strlen(two_password) > 20 || strlen(two_password) < 0)
        {
            printf("密码长度不符合规定\n");
            continue;
        }
        // 判断两次密码是否一致
        if (strcmp(new_password, two_password) == 0)
        {
            strcpy(head->data.password, new_password);
            printf("密码修改成功\n");
            return 1;
        }
        else
        {
            printf("两次密码不一致,请重新输入\n");
            printf("是否退出密码修改?如果想退出请输入'n'\n");
            scanf("%c", &flag);
            // 退出整个函数
            if (flag == 'n')
            {
                return 0;
            }
        }
    }
}

// 释放所有节点(退出系统用)
void freeUserLink(UserLinklsit head)
{
    UserLink *current = head; // 定义一个中间变量
    while (current != NULL)
    {
        UserLink *temp = current;
        current = current->next;
        free(temp);
    }
    return;
}

// 删除节点(用户注销用)
int removeUserNode(UserLinklsit head,char *username)
{
    UserLink *current = head->next;
    UserLink *precurrent = head;
    while (current != NULL)
    {
        if (strcmp(current->data.username, username) == 0)
        {
            precurrent->next = current->next;

            return 1;
        }
        
        precurrent = current;
        current = current->next;
        
    }
    return 0;
}

// 将信息保存入链表之中
void saveUsers(UserLinklsit head)
{
    FILE *file = fopen("user.txt", "w");
    if (file == NULL)
    {
        printf("文件保存失败\n");
        return;
    }
    UserLink *current = head->next; // 定位到首元节点

    while (current != NULL)
    {
        int result = fprintf(file, "用户名:%s\t\t密码:%s\t\t账户余额:%.2lf\n", current->data.username, current->data.password, current->data.money);
        current = current->next;
    }

    fclose(file);
    return;
}

// 从文件中加载用户信息
void loadUsers(UserLinklsit head)
{
    FILE *file = NULL;
    file = fopen("user.txt", "r");
    if (file == NULL)
    {
        printf("用户文件打开失败\n");
        return;
    }
    char username[20], password[20];
    double money;
    while (fscanf(file, "用户名:%s\t\t密码:%s\t\t账户余额:%lf\n", username, password, &money) != EOF)
    {
        UserLink *newNode = createUserLink();
        newNode->data.money = money;
        strcpy(newNode->data.username, username);
        strcpy(newNode->data.password, password);
        InserUserNode(head, newNode);
    }
    fclose(file);
}

// 注册用户
void registerUser(UserLinklsit userHead)
{
    char username[20], password[20], password2[20];
    printf("请输入账号名\n");
    scanf("%s", username);
    UserLink *current = userHead->next;
    while (current != NULL)
    {
        if (strcmp(current->data.username, username) == 0)
        {
            printf("账号已经存在,请重新输入\n");
            return registerUser(userHead);
        }
        current = current->next;
    }
    printf("请输入密码\n");
    scanf("%s", password);

    printf("请第二次输入密码\n");
    scanf("%s", password2);
    if (strcmp(password, password2) != 0)
    {
        printf("两次密码不一致,请重新注册\n");
        return registerUser(userHead);
    }
    // 创建新节点用来储存用户信息
    UserLink *newNode = createUserLink();
    newNode->data.money = 0;
    strcpy(newNode->data.username, username);
    strcpy(newNode->data.password, password);
    InserUserNode(userHead, newNode);
    printf("用户注册成功\n");
}

