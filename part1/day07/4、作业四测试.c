#include <stdio.h>

int main() {
    int scores[6][5]; // 6个学生，每个学生5门课程
    int i, j;
    
    // 从键盘输入每个学生的成绩
    printf("请输入6个学生的5门课程成绩：\n");
    for (i = 0; i < 6; i++) {
        printf("请输入第 %d 个学生的成绩：\n", i + 1);
        for (j = 0; j < 5; j++) {
            printf("请输入第 %d 门课程的成绩：", j + 1);
            scanf("%d", &scores[i][j]);
        }
    }
    
    // 打印二维数组
    printf("学生的成绩二维数组：\n");
    for (i = 0; i < 6; i++) {
        for (j = 0; j < 5; j++) {
            printf("%d ", scores[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}

