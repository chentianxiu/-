#ifndef CURRENTID_H_
#define CURRENTID_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ID_FILE "id_store.txt" // 存储当前ID值的文件名

extern int currentId; // 声明变量


// 初始化当前ID的值
void initializeId();

// 保存当前ID值到文件
void saveCurrentId();

// 生成新的唯一ID
int generateUniqueId();


#endif