#include "userLottery.h"
#include<stdio.h>
/*
	功能：创建个人彩票链表
	参数：无
	返回值：头节点的地址 NULL 失败
*/
UserLottery* createUserLottery(){
    //创建头指针
     UserLottery * header =NULL;
     //动态创建一个空间
     header = (UserLottery*)calloc(1,sizeof(UserLottery));
     //判断内存是否创建成功
     if (header == NULL){
         printf("内存创建失败\n");
         return NULL;
     }
     //空节点，将next域置空
     header->next = NULL;
     return header;
}


/*
	功能：添加节点
	参数：head: 头节点 newNode:要添加的节点
	返回值：	1 成功 0 失败
*/
void insertLotteryNode(UserLotteryLink head, UserLotteryLink newNode){
    //找到尾部节点
    while (head->next!=NULL)
    {
        head = head->next;
    }
    //尾插操作
    newNode->next =head->next;
    head->next = newNode;
    return;
}



//输入选中号码只取9位数
void processInput(char *input, char *output) {
    int length = strlen(input);

    // 如果长度超过九位，截取前九位
    if (length > 9) {
        strncpy(output, input, 9);
        output[9] = '\0';  // 确保字符串结束
    } else {
        // 如果长度不足九位，前面补零
        int padding = 9 - length;
        for (int i = 0; i < padding; ++i) {
            output[i] = '0';
        }
        strcpy(output + padding, input);
    }
}


/*
	功能：打印所有信息
	参数：head: 头节点
	返回值：无
*/
void printUserLottery(UserLotteryLink head){
    UserLottery *current = head->next;//定义一个中间变量
    while (current!=NULL)
    {
        printf("发布期号:%d\t\t彩票id:%d\t\t投注号码%s\t\t购买者账号%s\t\t注数%d\t\t中奖状态%d\t\t中奖金额%.2lf\n",
        current->lottery.issue,current->lottery.id,current->lottery.selcetedNumber,current->lottery.username,current->lottery.numBets,current->lottery.winningStatus,current->lottery.winprice);
        current = current->next;
    }
    return;
}

/*
	功能：释放所有节点
	参数：head: 头节点
	返回值：无
*/
void freeUserLottery(UserLotteryLink head){
    UserLottery *current = head;//定义一个中间变量
    while (current!=NULL)
    {
        UserLottery *temp = current;
        current = current->next;
        free(temp);
    }
    return;
}

/*
	功能：通过名字删除节点
	参数：head:头节点 name： 名字
	返回值：0 失败 1 成功
*/
int removeLotteryNode(UserLotteryLink head, const int id){

}

/*
	功能：保存所有信息到文件中
	参数：head 头节点
	返回值：无
*/
void saveUserLottery(UserLotteryLink head){
    FILE *file = fopen("userLottery.txt", "w");
    if (file == NULL)
    {
        printf("文件保存失败\n");
        return;
    }
    UserLottery * current = head->next;//定位到首元节点

    while (current!=NULL)
    {
        fprintf(file,"发布期号:%d\t\t彩票id:%d\t\t投注号码%s\t\t购买者账号%s\t\t注数%d\t\t中奖状态%d\t\t中奖金额%.2lf\n",
        current->lottery.issue,current->lottery.id,current->lottery.selcetedNumber,current->lottery.username,current->lottery.numBets,current->lottery.winningStatus,current->lottery.winprice);
        current = current->next;
    }
    fclose(file);
}


/*
	功能：从文件中加载所有的信息到内存中
	参数：head: 头节点
	返回值：无
*/
void loadUserLottery(UserLotteryLink head){
    FILE *file = NULL;
    file = fopen("userlottery.txt", "r");
    if (file == NULL)
    {
        printf("个人彩票文件打开失败\n");
        return;
    }
    int issue;              //发布期号
    int id;                 //单张彩票唯一表示id
    char selcetedNumber[10];  //彩票上选中的号码
    char username[20];     //购买者账号
    int numBets;            //已购买某一彩票号的注数(最多5注)
    int winningStatus;      //中奖状态
    double winprice;

    while (fscanf(file,"发布期号:%d\t\t彩票id:%d\t\t投注号码%s\t\t购买者账号%s\t\t注数%d\t\t中奖状态%d\t\t中奖金额%lf\n",&issue,&id,selcetedNumber,
    username,&numBets,&winningStatus,&winprice) != EOF)
    {
        UserLottery * newNode = createUserLottery();
        newNode->lottery.issue = issue;
        newNode->lottery.id = id;
        newNode->lottery.numBets = numBets;
        newNode->lottery.winningStatus = winningStatus;
        newNode->lottery.winprice = winprice;
        strcpy(newNode->lottery.selcetedNumber,selcetedNumber);
        strcpy(newNode->lottery.username,username);
        insertLotteryNode(head,newNode);
    }
    fclose(file);
}

//查询购买彩票记录
void CheckRecords(UserLottery *lotteryHead,char *username){
    int a = 0;
    //定义到首节点
    UserLottery *current = lotteryHead->next;
    while (current != NULL)
    {
        if (strcmp(current->lottery.username, username) == 0)
        {
            a = 1;
            printf("发布期号:%d\t\t彩票id:%d\t\t投注号码%s\t\t购买者账号%s\t\t注数%d\t\t中奖状态%d\t\t中奖金额%.2lf\n",
                   current->lottery.issue, current->lottery.id, current->lottery.selcetedNumber, current->lottery.username, current->lottery.numBets, current->lottery.winningStatus, current->lottery.winprice);
        }
        current = current->next;
    }
    if (a == 0)
    {
        printf("没有购买记录\n");
    }
    
    return ;
}

//查询中奖记录
void CheckWinRrecords(UserLottery * lotteryHead,char *username){
    int a = 0;
    //定义到首节点
    UserLottery *current = lotteryHead->next;
    while (current != NULL)
    {
        if (strcmp(current->lottery.username, username) == 0&&current->lottery.winningStatus!=0)
        {
            a=1;
            printf("发布期号:%d\t\t彩票id:%d\t\t投注号码%s\t\t购买者账号%s\t\t注数%d\t\t中奖状态%d\t\t中奖金额%.2lf\n",
                   current->lottery.issue, current->lottery.id, current->lottery.selcetedNumber, current->lottery.username, current->lottery.numBets, current->lottery.winningStatus, current->lottery.winprice);
        }
        current = current->next;
    }
    if (a == 0)
    {
        printf("没有中奖记录\n");
    }
    
    return ;
}

// 彩票号码购买信息查询
void CheckSelectNum(UserLottery *lotteryHead){
    char num[10];
    printf("请输入您需要查询的彩票号码\n");
    scanf("%s",num);
    UserLottery * current = lotteryHead->next;
    while (current!=NULL)
    {
        if (strcmp(current->lottery.selcetedNumber,num)==0)
        {
            printf("发布期号:%d\t\t彩票id:%d\t\t投注号码%s\t\t购买者账号%s\t\t注数%d\t\t中奖状态%d\t\t中奖金额%.2lf\n",
                   current->lottery.issue, current->lottery.id, current->lottery.selcetedNumber, current->lottery.username, current->lottery.numBets, current->lottery.winningStatus, current->lottery.winprice);
        }
        current = current->next;
    }
    return ;
}