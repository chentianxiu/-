#include "issueLink.h"
#include <stdio.h>

/*
    功能：创建每期彩票链表
    参数：无
    返回值：头节点的地址 NULL 失败
*/
IssueLink *createIssueLink()
{
    // 创建头指针
    IssueLinklist header = NULL;
    // 动态创建一个空间
    header = (IssueLink *)malloc(sizeof(IssueLink));
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

/*
    功能：添加节点
    参数：head: 头节点 newNode:要添加的节点
    返回值：	1 成功 0 失败
*/
void insertIssueNode(IssueLinklist head, IssueLinklist newNode)
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

/*
    功能：打印所有信息
    参数：head: 头节点
    返回值：无
*/
void printIssueLink(IssueLinklist head)
{
    IssueLink *current = head->next; // 定义一个中间变量
    while (current != NULL)
    {
        printf("发布期号:%d\t\t彩票单价:%.2lf\t\t开奖状态:%d\t\t中奖号码:%s\t\t售出总数:%d\t\t奖池总额:%.2lf\n",
               current->data.issue, current->data.saleprice, current->data.winningStatus, current->data.winNumber, current->data.salenum, current->data.pool);
        current = current->next;
    }
    return;
}

/*
    功能：释放所有节点
    参数：head: 头节点
    返回值：无
*/
void freeIssueLink(IssueLink *head)
{
    IssueLink *current = head; // 定义一个中间变量
    while (current != NULL)
    {
        IssueLink *temp = current;
        current = current->next;
        free(temp);
    }
    return;
}

/*
    功能：保存所有信息到文件中
    参数：head 头节点
    返回值：无
*/
void saveIssueLink(IssueLink *head)
{
    FILE *file = fopen("issueLink.txt", "w");
    if (file == NULL)
    {
        printf("文件保存失败\n");
        return;
    }
    IssueLink *current = head->next; // 定位到首元节点

    while (current != NULL)
    {
        fprintf(file, "发布期号:%08d\t\t彩票单价:%lf\t\t开奖状态:%d\t\t中奖号码:%s\t\t售出总数:%d\t\t奖池总额:%lf\n",
                current->data.issue, current->data.saleprice, current->data.winningStatus, current->data.winNumber, current->data.salenum, current->data.pool);
        current = current->next;
    }
    fclose(file);
}

/*
    功能：从文件中加载所有的信息到内存中
    参数：head: 头节点
    返回值：无
*/
void loadIssueLink(IssueLink *head)
{
    FILE *file = NULL;

    file = fopen("issueLink.txt", "r");

    if (file == NULL)
    {
        printf("每期彩票文件打开失败\n");
        return;
    }
    int issue;          // 发布期号
    double saleprice;   // 彩票单价
    int winningStatus;  // 开奖状态
    char winNumber[10]; // 中奖号码
    int salenum;        // 售出总数
    double pool;        // 奖池总额

    while (fscanf(file, "发布期号:%08d\t\t彩票单价:%lf\t\t开奖状态:%d\t\t中奖号码:%s\t\t售出总数:%d\t\t奖池总额:%lf\n",
                  &issue, &saleprice, &winningStatus, winNumber, &salenum, &pool) != EOF)
    {

        IssueLink *newNode = createIssueLink();
        newNode->data.issue = issue;
        newNode->data.saleprice = saleprice;
        newNode->data.pool = pool;
        newNode->data.winningStatus = winningStatus;
        newNode->data.salenum = salenum;
        strcpy(newNode->data.winNumber, winNumber);
        insertIssueNode(head, newNode);
    }
    fclose(file);
}

// 随机生成一串期号(根据当前时间生成)
int generateTimeBasedNumber()
{
    // 获取当前时间
    time_t rawtime;
    struct tm *timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    // 获取月份、日期、小时和分钟
    int month = timeinfo->tm_mon + 1; // 月份从0开始，需要加1
    int day = timeinfo->tm_mday;
    int hour = timeinfo->tm_hour;
    int minute = timeinfo->tm_min;

    // 组合成一个数字：MMDDHHMM
    int timeBasedNumber = month * 1000000 + day * 10000 + hour * 100 + minute;

    return timeBasedNumber;
}

// 查找是否有未开奖的彩票
int FindissueStatus(IssueLink *head)
{
    while (head->next != NULL)
    {
        if (head->next->data.winningStatus == 1)
        {
            return 1;
        }

        head = head->next;
    }

    return 0;
}

// 发行彩票函数
void Issuelotterytickets(UserLink *userHead, UserLottery *lotteryHead, IssueLink *issueHead)
{
    int status = FindissueStatus(issueHead);
    if (status == 1)
    {
        printf("已经有彩票在发行中,现在无法发行,请等待彩票开奖后再发行\n");
        return;
    }
    int issue = generateTimeBasedNumber(); // 发布期号

    double saleprice; // 彩票单价
    printf("请输入彩票单价\n");
    scanf("%lf", &saleprice);

    char winNumber[10] = {'0', '0', '0', '0', '0', '0', '0', '0', '0', '\0'}; // 中奖号码
    int salenum = 0;                                                          // 售出总数
    double pool = 200000;                                                     // 奖池总额
    IssueLink *newNode = createIssueLink();                                   // 创建新节点
    // 给新节点赋值
    newNode->data.issue = issue;
    newNode->data.saleprice = saleprice;
    newNode->data.winningStatus = 1;
    strcpy(newNode->data.winNumber, winNumber);
    newNode->data.salenum = salenum;
    double oldpool =0;
    oldpool = Getoldpool(issueHead);//找到上一期的奖池
    newNode->data.pool = pool+oldpool;
    insertIssueNode(issueHead, newNode);
    printf("彩票发行成功\n");
}


//找到上一期奖池
double Getoldpool(IssueLink *issueHead){
    IssueLink * current = issueHead->next;
    int temp = 0;
    double pool2 = 0;
    if (current == NULL)
    {
        pool2 = 0;
        return pool2;
    }
    
    while (current!=NULL)
    {
        if (current->data.issue>temp)
        {
            temp = current->data.issue;
            pool2 = current->data.pool;
        }
        current = current->next;
    }
    return pool2;
    
}

// 按用户账户查询
void userNamesort(UserLink *userHead, UserLottery *lotteryHead, IssueLink *issueHead)
{
    printf("请输入您需要查询的账户\n");
    char username[20];
    scanf("%s", username);
    Printonemassge(username, userHead, lotteryHead);
}

// 按照用户名字打印用户信息
void Printonemassge(const char *username, UserLink *userHead, UserLottery *lotteryHead)
{
    int a = 0;
    int b = 0;
    // 遍历函数到当前用户节点，打印用户账户信息
    while (userHead->next != NULL)
    {
        if (strcmp(userHead->next->data.username, username) == 0)
        {
            printf("用户名:%s\t\t密码:%s\t\t账户余额:%.2lf\n", userHead->next->data.username, userHead->next->data.password, userHead->next->data.money);
            a = 1;
        }
        userHead = userHead->next;
    }
    // 遍历个人彩票信息节点，打印用户购买彩票信息
    UserLottery *current = lotteryHead->next;
    while (current != NULL)
    {
        if (strcmp(current->lottery.username, username) == 0)
        {
            printf("发布期号:%d\t\t彩票id:%d\t\t投注号码%s\t\t购买者账号%s\t\t注数%d\t\t中奖状态%d\t\t中奖金额%.2lf\n",
                   current->lottery.issue, current->lottery.id, current->lottery.selcetedNumber, current->lottery.username, current->lottery.numBets, current->lottery.winningStatus, current->lottery.winprice);
            b = 1;
        }
        current = current->next;
    }

    if (a == 0)
    {
        printf("该用户不存在\n");
    }
    if (a!= 0 &&b == 0)
    {
        printf("该用户没有购买过彩票\n");
    }

    return;
}

// 按照用户余额排序用户信息
void userMoneysort(UserLink *userHead)
{
    if (NULL == userHead || NULL == userHead->next || NULL == userHead->next->next)
    {
        return;
    }

    UserLink *p = userHead->next;
    UserLink *q = NULL;
    /*
        用链表的每一个节点的数据与后边所有节点的的值比较，如果后边节点的值
        小于后边的节点，将值交换，每次外循环结束，却定待拍序列的最小值
        到第一个节点
    */
    for (p = userHead->next; p->next != NULL; p = p->next)
    {
        for (q = p->next; q != NULL; q = q->next)
        {
            if (p->data.money > q->data.money)
            {
                Userdata tmp = p->data;
                p->data = q->data;
                q->data = tmp;
            }
        }
    }
    printUserLink(userHead);
}

// 用户购买彩票
void Buytickets(UserLink *userHead, UserLottery *lotteryHead, IssueLink *issueHead, char *username)
{
    // 判断当前有无在售彩票
    IssueLink *current = issueHead->next;
    while (current != NULL)
    {
        if (current->data.winningStatus == 1)
        {
            break;
        }
        current = current->next;
    }
    if (current == NULL)
    {
        printf("当前彩票没有在售中\n");
        return;
    }

    UserLottery *newnode = createUserLottery();
    newnode->lottery.issue = current->data.issue; // 当前期号
    char input[20];
    char output[10];
    int numbet = 5;

    printf("请输入购买的彩票号码(输入九位数,不足九位数前面自动补零,超过九位数只取前九位)\n");
    scanf("%s", input);
    processInput(input, output);
    strcpy(newnode->lottery.selcetedNumber, output); // 选中的号码

    // 计算注数
    UserLottery *current2 = lotteryHead->next;
    while (current2 != NULL)
    {
        if (strcmp(newnode->lottery.selcetedNumber, current2->lottery.selcetedNumber) == 0 && (newnode->lottery.issue == current2->lottery.issue))
        {
            numbet -= current2->lottery.numBets;
        }
        current2 = current2->next;
    }
    if (numbet <= 0)
    {
        printf("您购买的号码已经卖完了\n");
        free(newnode);
        return;
    }
    else
    {
        int temp = 0;
        temp = checkmoney(userHead, newnode, current, username, numbet); // 判断余额是否足够
        if (temp == 0)
        {
            free(newnode);
            return;
        }
    }
    strcpy(newnode->lottery.username, username); // 购买者账号
    newnode->lottery.winningStatus = 0;          // 中奖状态初始化为0,不中奖
    newnode->lottery.winprice = 0;               // 中奖金额初始化为0,开奖时计算
    newnode->lottery.id = generateUniqueId();    // 使用函数生成唯一id
    // 将新节点连接上链表
    insertLotteryNode(lotteryHead, newnode);
    printf("购买彩票成功\n");
    return;
}

// 判断余额是否足够
int checkmoney(UserLink *userHead, UserLottery *newnode, IssueLink *current, char *username, int numbet)
{
    double newmoney = 0;
    printf("请输入您购买彩票的注数,该号码已经购买了%d注,您最多买%d注\n", 5 - numbet, numbet);
    scanf("%d", &newnode->lottery.numBets); // 购买的注数

    if (newnode->lottery.numBets > numbet || newnode->lottery.numBets <= 0)
    {
        printf("您输入的注数超过范围\n");
        return 0;
    }

    // 判断余额是否充足
    UserLink *current3 = userHead->next;
    while (current3 != NULL)
    {
        if (strcmp(current3->data.username, username) == 0)
        {
            break;
        }
        current3 = current3->next;
    }
    newmoney = current3->data.money - newnode->lottery.numBets * current->data.saleprice;
    if (newmoney < 0)
    {
        printf("您的余额不足,请充值\n");
        return 0;
    }
    else
    {
        current3->data.money = newmoney;
    }
    current->data.pool += (newnode->lottery.numBets * current->data.saleprice);
    current->data.salenum +=newnode->lottery.numBets;
    return 1;
}

// 开奖
void LotteryDraw(UserLink *userHead, UserLottery *lotteryHead, IssueLink *issueHead)
{
    char winnum[10];
    // 找到当前未开奖的期号
    IssueLink *current = issueHead->next;

    while (current != NULL)
    {
        if (current->data.winningStatus == 1)
        {
            break;
        }
        current = current->next;
    }
    if (current == NULL)
    {
        printf("当前彩票没有未开奖的\n");
        return;
    }
    // 测试，手动输入中奖号码
    printf("请输入中奖号码\n");
    scanf("%s", winnum);
    winnum[9] = '\0';
    //generateRandom9DigitString(winnum);
    // 遍历用户彩票信息,找到当前期号的彩票,对比,如果中奖,则对用户彩票中奖状态进行操作
    strcpy(current->data.winNumber,winnum);
    UserLottery *current2 = lotteryHead->next;
    while (current2 != NULL)
    {
        if (current2->lottery.issue == current->data.issue) // 找到当前期号的彩票,对比彩票号码
        {
            current2->lottery.winningStatus = CompareWinNum(current2->lottery.selcetedNumber, winnum);
        }
        current2 = current2->next;
    }
    UpdateUserLotMsg(lotteryHead, current);//更新中奖用户的奖金

    // 计算奖池剩余金额
    UserLottery *current10 = lotteryHead->next; // 定义到个人彩票首元节点
    while (current10 != NULL)
    {
        if (current10->lottery.issue == current->data.issue)
        {
            current->data.pool -= current10->lottery.winprice;
        }
        current10 = current10->next;
    }
    // 计算用户结算后的余额
    AddwinPrice(userHead, lotteryHead, current);
    //打印现在中奖的彩票信息
    printf("中奖号码是:%s\n",winnum);
    PrintNow(lotteryHead,current);

    current->data.winningStatus = 0;

    printf("开奖完毕\n");
    return;
}

// 找到当前期号的彩票,对比彩票号码,判断中奖等级
int CompareWinNum(char *selcetedNumber, char *winnum)
{
    int count = 0;
    for (int i = 0; i < 9; i++)
    {
        if (selcetedNumber[i] == winnum[i])
        {
            count++;
        }
    }
    if (count > 5)
    {
        return 1;
    }
    else if (count == 5)
    {
        return 2;
    }
    else if (count == 4)
    {
        return 3;
    }
    else if (count == 3)
    {

        return 4;
    }
    else
    {
        return 0;
    }
}

// 更新中奖用户的奖金,奖金池暂时不更新,最后统一更新
void UpdateUserLotMsg(UserLottery *lotteryHead, IssueLink *current)
{
    // 计算所有中奖注数，一等奖注数，二等奖注数，三等奖注数,四等奖注数
    int num1 = 0;
    int num2 = 0;
    int num3 = 0;
    UserLottery *current22 = lotteryHead->next;
    while (current22 != NULL) // 计算每一等奖的所有注数
    {
        if (current22->lottery.winningStatus == 1 && current22->lottery.issue == current->data.issue)
        {
            num1 += current22->lottery.numBets;
        }
        if (current22->lottery.winningStatus == 2 && current22->lottery.issue == current->data.issue)
        {
            num2 += current22->lottery.numBets;
        }
        if (current22->lottery.winningStatus == 3 && current22->lottery.issue == current->data.issue)
        {
            num3 += current22->lottery.numBets;
        }
        current22 = current22->next;
    }
    // 接下来更新用户奖金信息
    UserLottery *current9 = lotteryHead->next;
    while (current9 != NULL)
    {
        if (current9->lottery.issue == current->data.issue && current9->lottery.winningStatus == 1 && num1 != 0)
        { // 一等奖中奖金额
            current9->lottery.winprice = ((current->data.pool) * 0.5 / num1) * current9->lottery.numBets;
        }
        if (current9->lottery.issue == current->data.issue && current9->lottery.winningStatus == 2 && num2 != 0)
        { // 二等奖中奖金额
            current9->lottery.winprice = ((current->data.pool) * 0.25 / num2) * current9->lottery.numBets;
        }
        if (current9->lottery.issue == current->data.issue && current9->lottery.winningStatus == 3 && num3 != 0)
        { // 三等奖中奖金额
            current9->lottery.winprice = ((current->data.pool) * 0.1 / num3) * current9->lottery.numBets;
        }
        if (current9->lottery.issue == current->data.issue && current9->lottery.winningStatus == 4)
        {                                    // 四等奖中奖金额
            current9->lottery.winprice = 20; // 四等奖固定金额
        } 
        current9 = current9->next;
    }

    return;
}

// 计算用户结算后的余额
void AddwinPrice(UserLink *userHead, UserLottery *lotteryHead, IssueLink *current)
{
    UserLink *p1 = userHead->next;//定位到用户的首元节点
    UserLottery *p2 = lotteryHead->next;//定位到用户购买彩票信息的首元节点
    while (p1 != NULL)
    {
        p2 = lotteryHead->next;
        while (p2 != NULL)
        {
            if (strcmp(p1->data.username , p2->lottery.username)==0&&p2->lottery.issue==current->data.issue)
            {
                    p1->data.money += p2->lottery.winprice;//修改余额
            }
            p2 = p2->next;
        }

        p1 = p1->next;
    }
    return;
}

//打印现在中奖的彩票信息
void PrintNow(UserLottery *lotteryHead,IssueLink *current){
    int a = 0;
    UserLottery * current2 = lotteryHead->next;
    while (current2!=NULL)
    {
        if (current2->lottery.winningStatus!=0&&current2->lottery.issue==current->data.issue)
        {
            a=1;
            printf("发布期号:%d\t\t彩票id:%d\t\t投注号码%s\t\t购买者账号%s\t\t注数%d\t\t中奖状态%d\t\t中奖金额%.2lf\n",
                   current2->lottery.issue, current2->lottery.id, current2->lottery.selcetedNumber, current2->lottery.username, current2->lottery.numBets, current2->lottery.winningStatus, current2->lottery.winprice);
        }
        current2 = current2->next;
    }
    if (a == 0)
    {
        printf("无人中奖\n");
    }
    
    
}

// 修改用户名
void Changname(UserLinklsit userhead,UserLottery *lotteryHead, char *username)
{
    char newname[20];
    printf("请输入新账号名\n");
    scanf("%s", newname);
    UserLink *current = userhead->next;
    while (current != NULL)
    {
        if (strcmp(current->data.username, newname) == 0)
        {
            printf("该账号已经存在,请重新输入\n");
            return Changname(userhead,lotteryHead, username);
        }
        current = current->next;
    }

    //更改用户彩票信息中的姓名
    UserLottery * p3 = lotteryHead->next;
    while (p3!=NULL)
    {
         if (strcmp(p3->lottery.username, username) == 0)
        {   
            strcpy(p3->lottery.username,newname);
        }
        p3 = p3->next;
    }
    //更改个人账户信息中的姓名
    UserLink *current2 = userhead->next;

    while (current2 != NULL)
    {
        if (strcmp(current2->data.username, username) == 0)
        {   
            strcpy(current2->data.username,newname);
            printf("修改成功\n");
            return;
        }
        current2 = current2->next;
    }
    
    return;
}
// 用户修改自己信息
int Changemassge(UserLinklsit userhead,UserLottery *lotteryHead,char *username)
{
    int choice = 0;
    int a = 0;

    while (1)
    {
        printf("选择想要修改的信息\n");
        printf("1.修改姓名\n");
        printf("2.修改密码\n");
        printf("0.返回上一级\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1: // 修改姓名
            Changname(userhead, lotteryHead,username);
            return 1;
            break;
        case 2: // 修改密码
            a = ChangPwd(userhead, username);
            if (a==1)
            {
                return 1;
            }
            return 0;
            break;
        case 0: // 退出
            return 0;
        default:
            printf("无效选项\n");
            break;
        }
    }
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

// 生成四位数验证码
void generateCaptcha(char *captcha, int length)
{
    const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    int charsetSize = sizeof(charset) - 1;

    for (int i = 0; i < length; ++i)
    {
        int key = rand() % charsetSize;
        captcha[i] = charset[key];
    }
    captcha[length] = '\0'; // 终止字符串
}

//随机生成9位数
void generateRandom9DigitString(char *str) {
    srand(time(NULL)); // 用当前时间作为随机数生成的种子
    for (int i = 0; i < 9; i++) {
        str[i] = '0' + rand() % 10; // 生成0到9的随机数字
    }
    str[9] = '\0'; // 确保字符串以空字符结尾
}
//猜数小游戏
void guessNumberGame() {
    int number, guess, numberOfTries = 0;
    
    // 初始化随机数生成器
    srand(time(0));
    
    // 随机生成1到100之间的数字
    number = rand() % 100 + 1;
    
    printf("欢迎来到猜数字游戏！\n");
    printf("我已经想好了一个1到100之间的数字，你能猜到它是什么吗？\n");
    
    // 猜测循环
    do {
        printf("请输入你的猜测: ");
        scanf("%d", &guess);
        numberOfTries++;
        
        if (guess > number) {
            printf("太大了！再试一次。\n");
        } else if (guess < number) {
            printf("太小了！再试一次。\n");
        } else {
            printf("恭喜你！你猜对了！\n");
            printf("你一共猜了 %d 次。\n", numberOfTries);
        }
    } while (guess != number);
}