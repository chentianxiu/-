#include <stdio.h>
#include <stdlib.h>

#define MAX_NUMBERS 1024

// 比较函数，用于排序
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    FILE *file;
    int numbers[MAX_NUMBERS];
    int count = 0;

    // 打开 a.txt 文件读取
    file = fopen("a.txt", "r");
    if (file == NULL) {
        perror("打开文件 a.txt 失败");
        return 1;
    }

    // 读取文件内容并解析为数字
    while (fscanf(file, "%d", &numbers[count]) != EOF) {
        count++;
        if (count >= MAX_NUMBERS) {
            fprintf(stderr, "超出最大支持数字数量 %d\n", MAX_NUMBERS);
            break;
        }
    }

    fclose(file);

    // 对数字排序
    qsort(numbers, count, sizeof(int), compare);
    
    

    // 打开 b.txt 文件写入
    file = fopen("b.txt", "w");
    if (file == NULL) {
        perror("打开文件 b.txt 失败");
        return 1;
    }

    // 将排序结果写入 b.txt
    for (int i = 0; i < count; i++) {
        fprintf(file, "%d\n", numbers[i]);
    }

    fclose(file);

    return 0;
}