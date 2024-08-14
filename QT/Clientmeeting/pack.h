#ifndef PACK_H
#define PACK_H

typedef struct
{
    int width; //宽度
    int height; //高度
    int bytesPerline; //每行字节数
    bool isLastPack;
    int packTaken;
    char data[2048];
}ImagePackage;


#endif // PACK_H
