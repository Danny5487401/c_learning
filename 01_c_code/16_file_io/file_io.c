#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>


int main(int argc, char *argv[]) {


    int fd = -1;
    int ret = 1;
    int buffer = 1024;
    int num = 0;


    if ((fd = open("./test", O_RDWR | O_CREAT | O_TRUNC)) == -1) {
        printf("Open Error\n");
        exit(1);
    }

    // write 要用于写入数据。
    // 第一个参数就是文件描述符，第二个参数表示要写入的数据存放位置，第三个参数表示希望写入的字节数，返回值表示成功写入到文件的字节数。
    ret = write(fd, &buffer, sizeof(int));
    if (ret < 0) {
        printf("write Error\n");
        exit(1);
    }
    printf("write %d byte(s)\n", ret);

    // lseek 用于重新定位读写的位置，第一个参数是文件描述符，第二个参数是重新定位的位置，第三个参数是 SEEK_SET，表示起始位置为文件头
    lseek(fd, 0L, SEEK_SET);
    
    // read 用于读取数据，
    // 第一个参数是文件描述符，第二个参数是读取来的数据存到指向的空间，第三个参数是希望读取的字节数，返回值表示成功读取的字节数
    ret = read(fd, &num, sizeof(int));
    if (ret == -1) {
        printf("read Error\n");
        exit(1);
    }
    printf("read %d byte(s)，the number is %d\n", ret, num);


    close(fd);


    return 0;
}