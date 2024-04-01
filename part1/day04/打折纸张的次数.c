#include <stdio.h>

int main()
{
    float a= 0.1;
    int count=0;
    while (a<=8844430)
    {
        a*=2;/* code */
        count+=1;
    }
    printf("需要折叠%d次\n",count);

    return 0;
    
}