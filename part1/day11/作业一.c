//定义一个结构体图书（书名、作者、价格），使用输入和输出语句。
#include <stdio.h>
#include <string.h>

typedef struct book
{
    char name[30];
    char author[30];
    float price;
    
}Book;


int main()
{
    Book book1 ;
    char name[30];
    char author[30];
    float price = 0;

    printf("请输入书名\n");
    scanf("%s",name);
    strcpy(book1.name,name);

    printf("请输入作者\n");
    scanf("%s",author);
    strcpy(book1.author,author);

    printf("请输入价格：\n");
    scanf("%f",&price);
    book1.price = price;
    printf("录入完毕，接下来是输出\n");

    printf("作者是%s,书名字是%s,价格是%.2f",book1.author,book1.name,book1.price);




    return 0;
    
}