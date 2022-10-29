#include <winsock2.h>
#include <iostream>
using namespace std;

int main(){
    WSADATA data;
    WSAStartup(MAKEWORD(2,2), &data);
    
    //소켓 형식 만들기
    SOCKET skt; 
    skt = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    /*
    프로토콜 쳬계를 불러오고, meterpreter 형식으로 지정
    */

    //개체 정보 담는 공간 생성, 프로토콜쳬계정보 및 포트 정보 담기
    SOCKADDR_IN addr = {};
    addr.sin_family - AF_INET;
    addr.sin_port = htons(4444);
    addr.sin_addr.s_addr = htonl(INADDR_ANY);

    //클라이언트 측 접속 응답 받아오기
    bind(skt, (SOCKADDR*)&addr, sizeof(addr));
    listen(skt, SOMAXCONN);

    //클라이언트 정보 담는 공간
    SOCKADDR_IN client = {};
    int client_size = sizeof(client);
    SOCKET client_sock = accept(skt, (SOCKADDR*)&client, &client_size);
    
    closesocket(client_sock);
    closesocket(skt);
    WSACleanup();
}