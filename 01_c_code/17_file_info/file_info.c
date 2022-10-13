#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>


int main(int argc, char *argv[]) {
    struct stat sb;
    DIR *dirp;
    struct dirent *direntp;
    char filename[128];
    // opendir 函数打开一个目录名所对应的 DIR 目录流
    if ((dirp = opendir("/usr")) == NULL) {
        printf("Open Directory Error\n");
        exit(1);
    }
    // readdir 函数从 DIR 目录流中读取一个项目，返回的是一个指针，指向 dirent 结构体，且流的自动指向下一个目录条目。如果已经到流的最后一个条目，则返回 NULL
    while ((direntp = readdir(dirp)) != NULL) {
        sprintf(filename, "/usr/%s", direntp->d_name);
        if (lstat(filename, &sb) == -1) {
            printf("lstat Error\n");
            exit(1);
        }


        printf("name : %s, mode : %d, size : %lld, user id : %d\n", direntp->d_name, sb.st_mode, sb.st_size, sb.st_uid);


    }
    // closedir() 关闭参数 dir 所指的目录流
    closedir(dirp);


    return 0;
}