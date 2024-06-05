#include "currentID.h"

// 初始化当前ID的值
void initializeId() {
    FILE *file = fopen(ID_FILE, "r");
    if (file != NULL) {
        // 从文件读取当前ID值
        if (fscanf(file, "%d", &currentId) != 1) {
            fprintf(stderr, "Failed to read ID from file. Initializing to current time.\n");
            currentId = (int)time(NULL);
        }
        fclose(file);
    } else {
        // 如果文件不存在，使用当前时间的秒数作为初始值
        currentId = (int)time(NULL);
    }
}

// 保存当前ID值到文件
void saveCurrentId() {
    FILE *file = fopen(ID_FILE, "w");
    if (file != NULL) {
        fprintf(file, "%d\n", currentId);
        fclose(file);
    } else {
        fprintf(stderr, "Failed to open file for writing current ID.\n");
    }
}

// 生成新的唯一ID
int generateUniqueId() {
    return currentId++;
}