/*
USER         PID        %CPU    %MEM      VSZ           RSS         TTY      STAT       START              TIME         COMMAND
用户         进程id      CPU     内存     虚拟内存      物理内存      终端      进程状态        启动时间         运行时间        指令

ps -e | grep ssh  查看含有ssh的内容，管道符，筛选


atoi(字符数组); 将字符串 转化为 int类型
sprintf(字符数组,数据类型,数据内容); 将int类型 转化为 字符串

文件描述符:作用和FILE*文件指针流的作用相似，文件描述符直接针对linux底层内核;
    open(); 打开文件, 成功返回值大于0
        open(打开的文件名,以何种方式打开(O_RDONLY|O_WRONLY|O_APPEND|O_CREAT|O_TRUNC|O_RDWR));
    read(); 读取文件, 成功返回值大于0
        read(读取文件的描述符,读取内容存放的位置,读取的字节数);    
    write(); 写入文件, 成功返回值大于0
        write(写入文件的描述符,需写入的内容(定义字符数组,通过数组写入),写入的字节数);
    lseek(); 定义光标的位置
        lseek(文件的描述符,偏移量,偏移的起始位置);
文件描述符的操作:
    freopen(); 重定向
        freopen(要打开的文件名,打开文件的方式,要重新定向的流(stdout|stdin|stderr));
    fcntl(); 文件描述符的修改(F_GETFL,F_SETFL)
        fcntl(文件描述符,修改方式,修改的样式);
    dup(); 复制文件描述符
        dup(文件描述符);
    dup2(); 重定向 dup2(fd,STDOUT_FILENO);
        dup2(文件描述符,重定向内容);
*/