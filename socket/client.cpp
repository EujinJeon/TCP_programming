#include <winsock2.h>
#include <iostream>
using namespace std;

int main(){
    WSADATA wsa;
    WSAStartup(MAKEWORD(2,2), &wsa);

    SOCKET skt;
    skt = socket(PF_INET,SOCK_STREAM,IPPROTO_TCP);

    SOCKADDR_IN addr = {};
    addr.sin_family = AF_INET;
    addr.sin_port = htons(4444);
    addr.sin_addr.s_addr = inet_addr("서버아이피");

    connect(skt, (SOCKADDR*)&addr,sizeof(addr));
    closesocket(skt);
    WSACleanup();
}