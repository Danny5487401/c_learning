// 一、服务端的工作流程
// 1）创建服务端的socket。

// 2）把服务端用于通信的地址和端口绑定到socket上。

// 3）把socket设置为监听模式。

// 4）接受客户端的连接。

// 5）与客户端通信，接收客户端发过来的报文后，回复处理结果。

// 6）不断的重复第5）步，直到客户端断开连接。

// 7）关闭socket，释放资源。

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Using:./server port\nExample:./server 5005\n\n");
        return -1;
    }

    // 第1步：创建服务端的socket。
    int listenfd;
    if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        perror("socket"); // perror 在 <stdio.h> 中声明，用于在屏幕上最近一次系统错误码消息描述，
        return -1;
    }

    // 第2步：把服务端用于通信的地址和端口绑定到socket上。
    struct sockaddr_in servaddr; // 服务端地址信息的数据结构。
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;                // 协议族，在socket编程中只能是AF_INET。
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY); // 任意ip地址。
    //servaddr.sin_addr.s_addr = inet_addr("192.168.190.134"); // 指定ip地址。
    servaddr.sin_port = htons(atoi(argv[1])); // 指定通信端口。
    if (bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) != 0)
    {
        perror("bind");
        close(listenfd);
        return -1;
    }

    // 第3步：把socket设置为监听模式。
    if (listen(listenfd, 5) != 0) // listen函数把主动连接socket变为被动连接的socket
    {
        perror("listen");
        close(listenfd);
        return -1;
    }

    // 第4步：接受客户端的连接。
    int clientfd;                             // 客户端的socket。
    int socklen = sizeof(struct sockaddr_in); // struct sockaddr_in的大小
    struct sockaddr_in clientaddr;            // 客户端的地址信息。
    clientfd = accept(listenfd, (struct sockaddr *)&clientaddr, (socklen_t *)&socklen);
    printf("客户端（%s）已连接。\n", inet_ntoa(clientaddr.sin_addr));

    // 第5步：与客户端通信，接收客户端发过来的报文后，回复ok。
    char buffer[1024];
    while (1)
    {
        int iret;
        memset(buffer, 0, sizeof(buffer));
        if ((iret = recv(clientfd, buffer, sizeof(buffer), 0)) <= 0) // 接收客户端的请求报文。
        {
            printf("iret=%d\n", iret);
            break;
        }
        printf("接收：%s\n", buffer);

        strcpy(buffer, "ok");
        if ((iret = send(clientfd, buffer, strlen(buffer), 0)) <= 0) // 向客户端发送响应结果。
        {
            perror("send");
            break;
        }
        printf("发送：%s\n", buffer);
    }

    // 第6步：关闭socket，释放资源。
    close(listenfd);
    close(clientfd);
}

//运行 ./server 80