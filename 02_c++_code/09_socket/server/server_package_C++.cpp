#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

class CTcpServer
{
public:
  int m_listenfd; // 服务端用于监听的socket
  int m_clientfd; // 客户端连上来的socket

  CTcpServer();

  bool InitServer(int port); // 初始化服务端

  bool Accept(); // 等待客户端的连接

  // 向对端发送报文
  int Send(const void *buf, const int buflen);
  // 接收对端的报文
  int Recv(void *buf, const int buflen);

  ~CTcpServer();
};

int main()
{
  CTcpServer TcpServer;

  if (TcpServer.InitServer(5051) == false)
  {
    printf("TcpServer.InitServer(5051) failed,exit...\n");
    return -1;
  }

  if (TcpServer.Accept() == false)
  {
    printf("TcpServer.Accept() failed,exit...\n");
    return -1;
  }

  printf("客户端已连接。\n");

  char strbuffer[1024];

  while (1)
  {
    memset(strbuffer, 0, sizeof(strbuffer));
    if (TcpServer.Recv(strbuffer, sizeof(strbuffer)) <= 0)
      break;
    printf("接收：%s\n", strbuffer);

    strcpy(strbuffer, "ok");
    if (TcpServer.Send(strbuffer, strlen(strbuffer)) <= 0)
      break;
    printf("发送：%s\n", strbuffer);
  }

  printf("客户端已断开连接。\n");
}

CTcpServer::CTcpServer()
{
  // 构造函数初始化socket
  m_listenfd = m_clientfd = 0;
}

CTcpServer::~CTcpServer()
{
  if (m_listenfd != 0)
    close(m_listenfd); // 析构函数关闭socket
  if (m_clientfd != 0)
    close(m_clientfd); // 析构函数关闭socket
}

// 初始化服务端的socket，port为通信端口
bool CTcpServer::InitServer(int port)
{
  m_listenfd = socket(AF_INET, SOCK_STREAM, 0); // 创建服务端的socket

  // 把服务端用于通信的地址和端口绑定到socket上
  struct sockaddr_in servaddr; // 服务端地址信息的数据结构
  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;                // 协议族，在socket编程中只能是AF_INET
  servaddr.sin_addr.s_addr = htonl(INADDR_ANY); // 本主机的任意ip地址
  servaddr.sin_port = htons(port);              // 绑定通信端口
  if (bind(m_listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) != 0)
  {
    close(m_listenfd);
    m_listenfd = 0;
    return false;
  }

  // 把socket设置为监听模式
  if (listen(m_listenfd, 5) != 0)
  {
    close(m_listenfd);
    m_listenfd = 0;
    return false;
  }

  return true;
}

bool CTcpServer::Accept()
{
  if ((m_clientfd = accept(m_listenfd, 0, 0)) <= 0)
    return false;

  return true;
}

int CTcpServer::Send(const void *buf, const int buflen)
{
  return send(m_clientfd, buf, buflen, 0);
}

int CTcpServer::Recv(void *buf, const int buflen)
{
  return recv(m_clientfd, buf, buflen, 0);
}