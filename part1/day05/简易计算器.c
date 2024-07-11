#include <stdio.h>

//定义四种运算函数
double add(double a,double b){return a+b;}
double sub(double a,double b){return a-b;}
double mul(double a,double b){return a*b;}
double div(double a,double b){return a/b;}


int main()
{
    //double num1 ,num2,result = 0;
    //char operator,quit;
    int flag = 1;
    while (flag)
    {
        double num1 =0;
        double num2 = 0;
        double result = 0;
        char operator = 0;
        char quit = 0;
        printf("请输入您的操作比如1+2\n");
        scanf("%lf",&num1);
        scanf("%c",&operator);
        scanf("%lf",&num2);
        switch (operator)
        {
        case '+':
            result = add(num1,num2);
            break;
        case '-':
            result = sub(num1,num2);
            break;
        case '*':
            result = mul(num1,num2);
            break;
        case '/':
            if (num2!=0)
            {
                result = div(num1,num2);
            }else{
                printf("除数不能为0\n");
                continue;
            }
            break;   
        default:
            printf("您输入的格式有问题\n");
            while(getchar()!='\n');
            continue;
        }
        
        printf("结果是:%.2lf\n",result);

        while(flag){

        printf("是否退出继续?(y/n):\n");

        while(getchar()!='\n');//清除缓冲区多余字符
        /*while(getchar()!='\n') 这个语句在C语言中用于读取并丢弃从标准输入（通常是键盘）直到遇到换行符（'\n'）为止的所有字符。
        这里的 getchar() 函数从标准输入读取一个字符，并返回这个字符的ASCII值。然后，这个值（字符）与换行符（'\n'）进行比较。
        如果读取的字符不是换行符，getchar()!='\n' 的结果为 true，while 循环将继续执行。这意味着，getchar() 函数会再次被调用，
        读取下一个字符，并与换行符进行比较，如此循环，直到读取到换行符为止。
        当读取到换行符时，getchar()!='\n' 的结果为 false，while 循环将停止执行。
        这种结构通常用于清除输入缓冲区中的多余字符，尤其是在用户输入了一个值之后，
        但输入缓冲区中可能还残留有其他字符（例如，如果用户按下了多余的键或进行了错误的输入操作）。
        但是需要注意的是，这种结构不会将读取的字符存储在任何地方，它们只是被读取并丢弃。
        如果你需要保存这些字符，你需要将它们存储在一个数组或其他数据结构中。
        此外，由于 getchar() 在循环中被连续调用，所以如果用户没有输入任何字符就直接按下了回车键（即输入缓冲区中没有任何字符），
        那么循环可能会立即退出。但如果输入缓冲区中有其他字符（例如之前的输入操作遗留的），这些字符也会被读取并丢弃。*/
        scanf("%c",&quit);
        if(quit=='y'||quit=='Y'){
            flag = 0;
            break;
        }else if (quit=='n'||quit=='N')
        {
            printf("程序继续\n");
            break;
        }else{
            printf("请输入有效的字符y或者n\n");
            continue;
        }
        //while为无限循环，break才能打断进程
        }

        while(getchar()!='\n');

    }
    

    return 0;
    
}