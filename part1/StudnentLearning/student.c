#include "student.h"

void menu1()
{
    printf("*************************************************\n");
    printf("*\t欢迎使用高校学生成绩管理系统V1.0\t*\n");
    printf("*\t\t请选择功能\t\t\t*\n");
    printf("*************************************************\n");
    printf("*\t\t1.学生登录\t\t\t*\n");
    printf("*\t\t2.管理员登录\t\t\t*\n");
    printf("*\t\t3.退出\t\t\t\t*\n");
}

void menu2()
{
    printf("*************************************************\n");
    printf("*\t欢迎使用高校学生成绩管理系统V1.0\t*\n");
    printf("*\t\t学生登录\t\t\t*\n");
    printf("*\t\t请选择功能\t\t\t*\n");
    printf("*************************************************\n");
    printf("*\t\t1.查看个人信息\t\t\t*\n");
    printf("*\t\t2.修改密码\t\t\t*\n");
    printf("*\t\t3.退出\t\t\t\t*\n");
}

void menu3()
{
    printf("*************************************************\n");
    printf("*\t欢迎使用高校学生成绩管理系统V1.0\t*\n");
    printf("*\t\t管理员登录\t\t\t*\n");
    printf("*\t\t请选择功能\t\t\t*\n");
    printf("*************************************************\n");
    printf("*\t\t1.增加学生信息\t\t\t*\n");
    printf("*\t\t2.删除学生信息\t\t\t*\n");
    printf("*\t\t3.排序学生信息\t\t*\n");
    printf("*\t\t4.查询并且修改学生信息\t\t*\n");
    printf("*\t\t5.打印学生信息\t\t*\n");
    printf("*\t\t6.退出\t\t\t\t*\n");
}

// Student *create_LinkedList(){
//       //创建头指针
//     Student *header =NULL;
//     //动态创建一个空间
//     header = (Student*)malloc(sizeof(Student));
//     //判断内存是否创建成功
//     if (header == NULL){
//         printf("内存创建失败\n");
//         return NULL;
//     }
//     //空节点，将next域置空
//     header->next = NULL;
//     return header;
// }

// 加载学生信息
void loadStudents(const char *filename, StuLinklist stulist)
{
    FILE *file = NULL;
    file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("文件打开失败\n");
        return;
    }

    char id[20], name[50], password[50], calssName[50];
    int age, grades[3];

    // 从文件中读取内容

    while (fscanf(file, "ID:%s\t\t姓名:%s\t\t密码:%s\t\t班级:%s\t\t年龄:%d\t\t语文:%d\t\t数学:%d\t\t英语:%d\n", id, name, password, calssName, &age, &grades[0], &grades[1], &grades[2]) != EOF)
    {
        Decrypt(password);
        InputStudent(stulist, id, name, password, calssName, age, grades);
    }

    fclose(file);
}

// 保存学生信息
void saveStudnets(const char *filename, StuLinklist stulist)
{
    FILE *file = fopen(filename, "w");
    if (file == NULL)
    {
        printf("文件保存失败\n");
        return;
    }
    Student *current = stulist->next; // 定义当前节点

    while (current != NULL) // 节点不为空
    {
        char password1[20];
        strcpy( password1 ,current->password);
        Encrypt(password1);
        fprintf(file, "ID:%s\t\t姓名:%s\t\t密码:%s\t\t班级:%s\t\t年龄:%d\t\t语文:%d\t\t数学:%d\t\t英语:%d\n", current->id, current->name, password1, current->clssName, current->age, current->grades[0], current->grades[1], current->grades[2]);
        current = current->next;
    }
    fclose(file);
}

// 加密字符串
void Encrypt(char *password)
{
    while (*password != '\0')
    {
        *password += 7;
        password++;
    }
    return;
}

// 解密字符串
void Decrypt(char *password)
{
    while (*password != '\0')
    {
        *password -= 7;
        password++;
    }
    return;
}

// 加载管理员信息
void loadUser(const char *filename, UserLink userlist)
{
    FILE *file = NULL;
    file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("文件打开失败\n");
        return;
    }
    char username[50];
    char password[50];

    // 从文件中读取内容

    while (fscanf(file, "管理员姓名:%s\t管理员密码:%s\t", username, password) != EOF)
    {
        InputUser(userlist, username, password);
    }
    fclose(file);
}

// 保存管理员信息
void saveUser(const char *filename, UserLink userlist)
{
    FILE *file = fopen(filename, "w");
    if (file == NULL)
    {
        printf("文件保存失败\n");
        return;
    }
    User *current = userlist->next; // 定义当前节点

    while (current != NULL) // 节点不为空
    {
        fprintf(file, "管理员姓名:%s\t管理员密码:%s\t", current->username, current->password);
        current = current->next;
    }
    fclose(file);
}

// 添加学生(链表操作)
int InputStudent(StuLinklist stulist, const char *id, const char *name, const char *password, char *className, int age, int grades[3])
{
    if (findStudent(stulist, id) != NULL)
    {
        printf("学号已经存在\n");
        return 0; // 学号已经存在
    }

    // 创建新的学生节点
    Student *newstudet = (Student *)malloc(sizeof(Student));

    if (newstudet == NULL)
    {
        printf("创建新节点失败\n");
    }
    newstudet->next = NULL;

    // 给节点赋值
    strcpy(newstudet->id, id);
    strcpy(newstudet->name, name);
    strcpy(newstudet->password, password);
    strcpy(newstudet->clssName, className);
    newstudet->age = age;
    for (int i = 0; i < 3; i++)
    {
        newstudet->grades[i] = grades[i];
    }
    newstudet->totalScore = grades[0] + grades[1] + grades[2];

    // if (stulist->next==NULL)
    // {
    //     printf("是头指针\n");
    // }

    // 新节点指针指向原本节点指向的
    while (stulist->next != NULL)
    {
        stulist = stulist->next;
    }

    newstudet->next = stulist->next;

    // 原本节点指向学生这个节点
    stulist->next = newstudet;

    return 1;
}

// 单个添加学生（键盘录入操作）
void AddStudnet(StuLinklist stulist)
{

    char id[20], name[50], password[] = "123456", calssName[50];
    int age, grades[3];
    printf("请输入学生姓名\n");
    scanf("%s", name);
    getchar();
    printf("请输入学生班级(A~Z)\n");
    scanf("%s", calssName);
    if (calssName[1] == '\0')
    {
        if (calssName[0] < 'A' || calssName[0] > 'Z')
        {
            printf("你输入的班级有误,请重新输入\n");
            AddStudnet(stulist);
        }
    }else{
        printf("你输入的班级有误,请重新输入\n");
        AddStudnet(stulist);
    }
    printf("请输入学生年龄\n");
    scanf("%d", &age);
    printf("请输入学生第一门成绩\n");
    scanf("%d", &grades[0]);
    printf("请输入学生第二门成绩\n");
    scanf("%d", &grades[1]);
    printf("请输入学生第三门成绩\n");
    scanf("%d", &grades[2]);
    creatID(calssName, stulist, id);
    if (InputStudent(stulist, id, name, password, calssName, age, grades))
    {
        printf("学生信息录入成功\n");
    }
    else
    {
        printf("学生学号已经存在\n");
    }
}
// 生成id
void creatID(char *classname, StuLinklist stulist, char *id)
{
    int count = 1;

    while (stulist->next != NULL)
    {
        if (strcmp(stulist->next->clssName,classname)==0)
        {
            count++;
        }
        stulist = stulist->next;
    }
    // char newID[20];
    char str[12];
    sprintf(str, "%d", count);
    strcpy(id, classname);
    strcat(id, str);

    return;
}

// 查找学生
Student *findStudent(StuLinklist stulist, const char *id)
{

    Student *current = stulist->next;

    // 定位到当前节点，找到相同id
    while (current != NULL)
    {
        if (strcmp(current->id, id) == 0)
        {
            return current;
        }

        current = current->next;
    }
    return NULL;
}

// 打印学生信息
void rankPrintMassge(StuLinklist stulist)
{

    // 定义一个指针，指向当前指针
    Student *current = stulist->next;
    printf("学号\t密码\t姓名\t班级\t年龄\t语文\t数学\t英语\t总分\t排名\n");
    int count = 0;

    // 遍历计算学生数量

    while (current != NULL)
    {
        current = current->next;
        count++;
    }

    // 循环查找对应排名的学生输出
    for (int i = 0; i < count; i++)
    {
        current = stulist->next;
        while (current != NULL)
        {
            if (current->rank == i + 1)
            {
                printf("%s\t", current->id);
                printf("%s\t", current->password);
                printf("%s\t", current->name);
                printf("%s\t", current->clssName);
                printf("%d\t", current->age);
                printf("%d\t", current->grades[0]);
                printf("%d\t", current->grades[1]);
                printf("%d\t", current->grades[2]);
                printf("%d\t", current->totalScore);
                printf("%d\t", current->rank);
                printf("\n");
            }
            current = current->next;
        }
    }
    return;
}

// 打印学生信息
void PrintMassge(StuLinklist stulist)
{
    // 定义一个指针，指向当前指针
    Student *current = stulist->next;
    printf("学号\t密码\t姓名\t班级\t年龄\t语文\t数学\t英语\t总分\t排名\n");
    current = stulist->next;
    while (current != NULL)
    {

        printf("%s\t", current->id);
        printf("%s\t", current->password);
        printf("%s\t", current->name);
        printf("%s\t", current->clssName);
        printf("%d\t", current->age);
        printf("%d\t", current->grades[0]);
        printf("%d\t", current->grades[1]);
        printf("%d\t", current->grades[2]);
        printf("%d\t", current->totalScore);
        printf("%d\t", current->rank);
        printf("\n");

        current = current->next;
    }
    return;
}

// 学生排序
void calculateRanks(StuLinklist stulist)
{
    int count = 0, number = 0;
    Student *temp = stulist;
    while (temp->next != NULL) // 学生数量获取
    {
        temp = temp->next;
        count++;
    }
    int sort[count]; // 数组,用于排名

    temp = stulist;
    while (temp->next != NULL) // 数组赋值
    {
        temp = temp->next;
        sort[number] = temp->totalScore;
        number++;
    }
    for (int i = 0; i < count - 1; i++) // 冒泡排序
    {
        for (int j = 0; j < count - 1 - i; j++)
        {
            if (sort[j] < sort[j + 1])
            {
                int temp_data = sort[j];
                sort[j] = sort[j + 1];
                sort[j + 1] = temp_data;
            }
        }
    }
    temp = stulist;
    while (temp->next != NULL) // 学生名次赋值
    {
        temp = temp->next;
        for (int i = 0; i < count; i++)
        {
            if (sort[i] == (temp->totalScore))
            {
                temp->rank = i + 1;
                break;
            }
        }
    }
    return;
}

// 学生单科排序(选择排序)
void calculatebyalone(StuLinklist stulist, int num)
{
    StuLinklist sortedlist = NULL; // 排序后的链表

    sortedlist = (Student *)malloc(sizeof(Student));

    if (sortedlist == NULL)
    {
        printf("链表创建失败\n");
    }
    Student *current1 = sortedlist;
    sortedlist->next = NULL;

    while (stulist->next != NULL)
    {

        Student *maxprecurrent = NULL;       // 最大节点置为空
        Student *maxcurrent = stulist->next; // 将指向最大节点的指针赋值为头指针
        Student *precurrent = NULL;          // 将指向当前节点的指针赋值为头指针
        Student *current = stulist->next;    // 从首元节点开始

        while (current != NULL)
        {
            // 找到当前排序的最大节点
            if (current->grades[num] > maxcurrent->grades[num])
            {
                maxprecurrent = precurrent;
                maxcurrent = current;
            }
            // 没有就继续向前移动直到结束链表
            precurrent = current;
            current = current->next;
        }

        // 找到当前的最大值节点后，将当前节点剪切下来
        if (maxprecurrent != NULL)
        {
            maxprecurrent->next = maxcurrent->next;
        }
        else
        {
            stulist->next = maxcurrent->next; // 最大节点是首元节点
        }

        // 将最大节点接到新的链表上
        maxcurrent->next = NULL;

        current1->next = maxcurrent;

        current1 = current1->next;
    }
    stulist->next = sortedlist->next;
    sortedlist->next = NULL;
    free(sortedlist);

    return;
}

// 学生姓名排序
void calculatebyname(StuLinklist stulist)
{
    StuLinklist sortedlist = NULL; // 排序后的链表

    sortedlist = (Student *)malloc(sizeof(Student));

    if (sortedlist == NULL)
    {
        printf("链表创建失败\n");
    }
    Student *current1 = sortedlist;
    sortedlist->next = NULL;

    while (stulist->next != NULL)
    {

        Student *maxprecurrent = NULL;       // 最大节点置为空
        Student *maxcurrent = stulist->next; // 将指向最大节点的指针赋值为头指针
        Student *precurrent = NULL;          // 将指向当前节点的指针赋值为头指针
        Student *current = stulist->next;    // 从首元节点开始

        while (current != NULL)
        {
            // 找到当前排序的最大节点
            if (strcmp(current->name, maxcurrent->name) < 0)
            {
                maxprecurrent = precurrent;
                maxcurrent = current;
            }
            // 没有就继续向前移动直到结束链表
            precurrent = current;
            current = current->next;
        }

        // 找到当前的最大值节点后，将当前节点剪切下来
        if (maxprecurrent != NULL)
        {
            maxprecurrent->next = maxcurrent->next;
        }
        else
        {
            stulist->next = maxcurrent->next; // 最大节点是首元节点
        }

        // 将最大节点接到新的链表上
        maxcurrent->next = NULL;

        current1->next = maxcurrent;

        current1 = current1->next;
    }
    stulist->next = sortedlist->next;
    sortedlist->next = NULL;
    free(sortedlist);

    return;
}

// 学生查看自己的信息
void StuPrintMassge(StuLinklist stulist, char *id)
{

    while (stulist->next != NULL)
    {
        stulist = stulist->next;
        if (strcmp(stulist->id, id) == 0)
        {
            printf("学号\t姓名\t密码\t班级\t年龄\t语文\t数学\t英语\t总成绩\t总分排名\n");
            printf("%s\t%s\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\n",
                   stulist->id, stulist->name, stulist->password, stulist->clssName, stulist->age, stulist->grades[0], stulist->grades[1], stulist->grades[2], stulist->totalScore, stulist->rank);
        }
    }
}

// 学生修改密码
void ChangeStuPassWorld(StuLinklist stulist, char *id)
{
    // 移动指针指向登录学生节点
    while (stulist->next != NULL)
    {
        stulist = stulist->next;
        if (strcmp(stulist->id, id) == 0)
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
    if ((strcmp(stulist->password, old_password)) != 0)
    {
        printf("您输入的原密码有误,请重新输入\n");
        printf("是否重新输入原密码?如果想退出请输入'n'\n");
        scanf("%c", &flag);
        if (flag == 'n')
        {
            return;
        }
        else
        {
            return ChangeStuPassWorld(stulist, id);
        }
    }

    // 新密码录入
    char new_password[50];
    char two_password[50];
    int flag2 = 1;
    while (flag2)
    {
        printf("请输入新密码,密码长度在6-45个字符\n");
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
        if (strlen(new_password) > 45 || strlen(new_password) < 6 || strlen(two_password) > 45 || strlen(two_password) < 6)
        {
            printf("密码长度不符合规定\n");
            continue;
        }
        // 判断两次密码是否一致
        if (strcmp(new_password, two_password) == 0)
        {
            strcpy(stulist->password, new_password);
            printf("密码修改成功\n");
            return;
        }
        else
        {
            printf("两次密码不一致,请重新输入\n");
            printf("是否退出密码修改?如果想退出请输入'n'\n");
            scanf("%c", &flag);
            // 退出整个函数
            if (flag == 'n')
            {
                return;
            }
        }
    }
}

// 删除学生
void delete_studnet(StuLinklist stulist)
{

    char id[20];
    printf("请输入需要删除的学生学号：\n");
    scanf("%s", id);

    printf("确定删除Y或者y\n");
    char choose;
    scanf(" %c", &choose);
    if (choose == 'Y' || choose == 'y')
    {
        Student *current = NULL; // 首元节点
        // 调用函数找到对应节点
        current = findStudent(stulist, id);

        if (current == NULL)
        {
            printf("没有这个id\n");
            return;
        }

        // 链表直接和current的后面一个节点直接相连
        while (stulist->next != NULL)
        {
            if (stulist->next == current)
            {
                stulist->next = stulist->next->next;

                free(current);

                current = NULL;

                printf("删除成功\n");

                return;
            }

            stulist = stulist->next;
        }
    }
    return;
}

// 修改学生信息
void ChangStudentMssage(StuLinklist current,StuLinklist stulist)
{
    printf("是否修改学生信息,确定修改Y或者y\n");
    char choose;
    scanf(" %c", &choose);
    if (choose == 'Y' || choose == 'y')
    {
        printf("请输入需要修改的信息([1]密码;[2]姓名;[3]班级;[4]年龄;[5]成绩;[6]1~5):\n");
        int flag = 0;
        char name[50], password[50], calssName[50];
        int age, grades[3];
        scanf("%d", &flag);
        switch (flag)
        {
        case 1:
            printf("请输入新密码\n");
            scanf("%s", password);
            strcpy(current->password, password);
            printf("修改成功\n");
            Printonestudent(current);
            break;
        case 2:
            printf("请输入新名字\n");
            scanf("%s", name);
            strcpy(current->name, name);
            printf("修改成功\n");
            Printonestudent(current);
            break;
        case 3:
            printf("请输入新班级\n");
            scanf("%s", calssName);
            strcpy(current->clssName, calssName);
            printf("修改成功\n");
            Printonestudent(current);
            break;
        case 4:
            printf("请输入新年龄\n");
            scanf("%d", &age);
            current->age = age;
            printf("修改成功\n");
            Printonestudent(current);
            break;
        case 5:
            printf("请输入您要修改的学科([0]语文;[1]数学;[2]英语):\n");
            int num = 100;
            scanf("%d", &num);
            printf("请输入新成绩\n");
            scanf("%d", &grades[num]);
            current->grades[num] = grades[num];
            current->totalScore=current->grades[0]+current->grades[1]+current->grades[2];
            calculateRanks(stulist);
            printf("修改成功\n");
            Printonestudent(current);
            break;
        case 6:
            printf("请输入新密码、名字、班级、年龄、语文成绩、数学成绩、英语成绩\n");
            scanf("%s", password);
            strcpy(current->password, password);
            scanf(" %s", name);
            strcpy(current->name, name);
            scanf(" %s", calssName);
            strcpy(current->clssName, calssName);
            scanf(" %d", &age);
            current->age = age;
            scanf(" %d", &grades[0]);
            current->grades[0] = grades[0];
            scanf(" %d", &grades[1]);
            current->grades[1] = grades[1];
            scanf(" %d", &grades[2]);
            current->grades[2] = grades[2];
            current->totalScore=current->grades[0]+current->grades[1]+current->grades[2];
            calculateRanks(stulist);
            printf("修改成功\n");
            Printonestudent(current);
            break;
        default:
            printf("输入错误\n");
            break;
        }
    }

    return;
}

// 查询学生
void Selectstudent(StuLinklist stulist)
{
    Student old = {};
    StuLinklist current = NULL;
    fflush(stdin);
    int  flag = 1, score_one = 0;
    char choose[10];
    while (flag) // 更改学生查找
    {
        current = stulist;
        fflush(stdin);
        printf("请输入您的查找方式([1]学号;[2]姓名;[3]班级;[4]成绩;[5]年龄;[6]排名;[0]退出):\n");
        scanf("%s", choose);
        switch (choose[0])
        {
        case '0':
            flag = 0;
            break;
        case '1':
            fflush(stdin);
            printf("请输入您要查找的学号:\n");
            scanf("%s", old.id);
            while (current->next != NULL)
            {
                current = current->next;
                if (strcmp(current->id, old.id) == 0)
                {
                    Printonestudent(current);
                    ChangStudentMssage(current,stulist);
                    flag = 0;
                    break;
                }
            }
            if (flag != 0)
            {
                printf("没有找到该学号!\n");
            }
            break;
        case '2':
            fflush(stdin);
            printf("请输入您要查找的姓名:\n");
            scanf("%s", old.name);
            while (current->next != NULL)
            {
                current = current->next;
                if (strcmp(current->name, old.name) == 0)
                {
                    Printonestudent(current);
                    ChangStudentMssage(current,stulist);
                    flag = 0;
                    break;
                }
            }
            if (flag != 0)
            {
                printf("没有找到该学生!\n");
            }
            break;
        case '3':
            fflush(stdin);
            printf("请输入您要查找的班级:\n");
            scanf("%s", old.clssName);
            while (current->next != NULL)
            {
                current = current->next;
                if (strcmp(current->clssName, old.clssName) == 0)
                {
                    Printonestudent(current);
                    ChangStudentMssage(current,stulist);
                    flag = 0;
                    break;
                }
            }
            if (flag != 0)
            {
                printf("没有找到该班级!\n");
            }
            break;
        case '4':
            fflush(stdin);
            printf("请输入您要查找的学科([0]语文;[1]数学;[2]英语):\n");
            scanf("%d", &score_one);
            while (current->next != NULL)
            {
                current = current->next;
                if (current->grades[score_one] == old.grades[score_one])
                {
                    Printonestudent(current);
                    ChangStudentMssage(current,stulist);
                    break;
                }
            }
            if (flag != 0)
            {
                printf("没有找到该成绩!\n");
            }
            break;
        case '5':
            fflush(stdin);
            printf("请输入您要查找的年龄:\n");
            scanf("%d", &old.age);
            while (current->next != NULL)
            {
                current = current->next;
                if (current->age == old.age)
                {
                    Printonestudent(current);
                    ChangStudentMssage(current,stulist);
                    flag = 0;
                    break;
                }
            }
            if (flag != 0)
            {
                printf("没有找到该年龄!\n");
            }
            break;
        case '6':
            fflush(stdin);
            printf("请输入您要查找的排名:\n");
            scanf("%d", &old.rank);
            while (current->next != NULL)
            {
                current = current->next;
                if (current->rank == old.rank)
                {
                    Printonestudent(current);
                    ChangStudentMssage(current,stulist);
                    flag = 0;
                    break;
                }
            }
            if (flag != 0)
            {
                printf("没有找到该排名!\n");
            }
            break;
        default:
            printf("您的输入有误!!\n");
            break;
        }
    }
    return;
}

// 添加管理员(链表操作)
void InputUser(UserLink userlist, const char *username, const char *password)
{
    // 创建新节点

    User *newuser = (User *)malloc(sizeof(User));

    if (newuser == NULL)
    {
        printf("创建新节点失败\n");
    }

    newuser->next = NULL;

    strcpy(newuser->username, username);
    strcpy(newuser->password, password);
    // 新节点指针指向原本节点指向的
    newuser->next = userlist->next;
    // 原本节点指向学生这个节点
    userlist->next = newuser;
}

// 打印单个学生信息
void Printonestudent(StuLinklist current)
{
    printf("学号\t密码\t姓名\t班级\t年龄\t语文\t数学\t英语\t总分\t排名\n");
    printf("%s\t", current->id);
    printf("%s\t", current->password);
    printf("%s\t", current->name);
    printf("%s\t", current->clssName);
    printf("%d\t", current->age);
    printf("%d\t", current->grades[0]);
    printf("%d\t", current->grades[1]);
    printf("%d\t", current->grades[2]);
    printf("%d\t", current->totalScore);
    printf("%d\t", current->rank);
    printf("\n");
}

// 隐藏密码
void get_password(char *password)
{
    char ch;
    int i = 0;
    // 获取输入，直到按下回车键
    while ((ch = _getch()) != '\r')
    {
        // 如果按下退格键，并且已经输入了字符，则删除最后一个字符
        if (ch == '\b' && i > 0)
        {
            i--;
            printf("\b \b");
        }
        // 如果输入的不是退格键，则检查是否已达到最大输入长度，并处理输入
        else if (ch != '\b')
        {
            // 如果输入长度未超过最大限制，显示*号
            if (i < 20)
            {
                password[i++] = ch;
                printf("*");
            }
        }
    }
    // 在密码字符串末尾添加终止符，表示字符串的结束
    password[i] = '\0';
    printf("\n"); // 换行
    return;
}