#include "student.h"

void rootmenu();
int rootlogin(char *username,char *password);

void studentmenu(StuLinklist stulist, char *id);
int studentlogin(char *username,char *password);

StuLinklist stulist1 = NULL;
UserLink userlist1 = NULL;

int main()
{

    // 给链表创建头节点
    stulist1 = (Student *)malloc(sizeof(Student));
    userlist1 = (User *)malloc(sizeof(User));
    stulist1->next = NULL;
    userlist1->next = NULL;
    // if (stulist1->next==NULL)
    // {
    //     printf("空表\n");
    // }

    loadStudents("stu.txt", stulist1);

    loadUser("user.txt", userlist1);

    calculateRanks(stulist1);

    // int choose = 0;
    int num = 3;
    while (num>0)
    {
        char username[20],password[20];
        
        printf("请输入账号(输入[0]退出):\n");
        scanf("%s", username);
        if ((username[0]=='0')&&(username[1]=='\0'))
        {
            calculateRanks(stulist1);
            saveStudnets("stu.txt", stulist1);
            saveUser("user.txt", userlist1);
            printf("退出系统\n");
            return 0;
        }
        printf("请输入密码:\n");
        get_password(password);

        if (username[0]=='+')
        {
            
            int temp=rootlogin(username,password);
            if (temp==0)
            {
                num--;
                printf("还剩下%d次机会\n", num);
            }else{
                num=3;
            }
            


        }else 
        {
            int temp1 =studentlogin(username,password);
            if (temp1 == 0)
            {
                num--;
                printf("还剩下%d次机会\n", num);
            }else{
                num = 3;
            }
            
            
        }
     }

    return 0;
}

// 学生登录
int studentlogin(char *id,char *password)
{
    // int num = 3;
    // while (num > 0)
    // {

        Student *current = stulist1;

        while (current != NULL)
        {
            if (strcmp(current->id, id) == 0 && strcmp(current->password, password) == 0)
            {
                printf("登录成功\n");
                studentmenu(stulist1, id);
                return 1;
            }
            current = current->next;
        }
        //num--;
        printf("输入错误\n");
        //printf("还剩下%d次机会\n", num);
        return 0;
}
    // printf("登录失败\n");
    // return;
//}

// 学生菜单
void studentmenu(StuLinklist stulist, char *id)
{
    while (1)
    {
        menu2();
        char ch = getch();
        switch (ch)
        {
        case '1':
            StuPrintMassge(stulist1, id);
            break;
        case '2':
            ChangeStuPassWorld(stulist1, id);
            saveStudnets("stu.txt", stulist1);
            break;
        case '3':
            return;
            break;
        default:
            printf("输入有误，没有该功能\n");
            break;
        }
    }
    return;
}

// 管理员登录
int rootlogin(char *username,char *password)
{
    // int num = 3;
    // while (num > 0)
    // {
    //     // char username[20], password[20];
        // printf("请输入账号:\n");
        // scanf("%s", username);
        // printf("请输入密码:\n");
        // // scanf("%s",password);
        // get_password(password);
        User *current = userlist1;
        while (current != NULL)
        {
            if (strcmp(current->username, username) == 0 && strcmp(current->password, password) == 0)
            {
                printf("登录成功\n");
                rootmenu(stulist1);
                return 1;
            }
            current = current->next;
        }
        //num--;
         printf("输入错误\n");
        // printf("还剩下%d次机会\n", num);
        return 0;
    }
    //printf("登录失败\n");
    //return;
 
// 管理员菜单
void rootmenu()
{
    while (1)
    {
        menu3();
        char ch = getch();
        switch (ch)
        {
        case '1':
            AddStudnet(stulist1);
            calculateRanks(stulist1);
            break;
        case '2':
            delete_studnet(stulist1);
            calculateRanks(stulist1);
            break;
        case '3':
            printf("排序方式[1].按姓名  [2].按语文  [3].按数学  [4].按英语  [5].按总成绩\n");
            int num = 100;
            scanf("%d", &num);
            if (num == 1)
            {
                calculatebyname(stulist1);
                printf("排序完成,请打印学生信息查看\n");
            }
            else if (num == 2)
            {
                calculatebyalone(stulist1, num - 2);
                printf("排序完成,请打印学生信息查看\n");
            }
            else if (num == 3)
            {
                calculatebyalone(stulist1, num - 2);
                printf("排序完成,请打印学生信息查看\n");
            }
            else if (num == 4)
            {
                calculatebyalone(stulist1, num - 2);
                printf("排序完成,请打印学生信息查看\n");
            }
            else if (num == 5)
            {
                rankPrintMassge(stulist1);
            }
            else
            {
                printf("您的输入有误\n");
            }
            break;
        case '4':
            Selectstudent(stulist1);
            break;
        case '5':
            PrintMassge(stulist1);
            break;
        case '6':
            return;
            break;
        default:
            printf("输入有误，没有该功能\n");
            break;
        }
    }
    return;
}