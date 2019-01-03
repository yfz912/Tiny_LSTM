#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <iostream>
#include <unistd.h>
//#include <stdio.h>
//  客户端会自动分配端口号
int main()
{
    int sock = -1;
    sock = socket( AF_INET, SOCK_STREAM, 0 );
    std::cout << "sock:" << sock << std::endl;

    struct sockaddr_in serv_addr;
    //  memset( &serv_addr, 0 , sizeof( serv_addr ) );
    //  author suggest that use bzero;
    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    //  serv_addr.sin_addr.s_addr = inet_addr( "111.231.190.103" );
    //  author suggest that use inet_pton
    inet_pton(AF_INET, "111.231.190.103", &serv_addr.sin_addr);
    serv_addr.sin_port = htons(7000);

    int conn = connect( sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr) );
    std::cout << "conn:" << conn << std::endl;
    
    char buffer[40];
    
    for(;;)
    {
    	read(sock, buffer,sizeof(buffer)-1);
    	printf("Message from server: %s\n", buffer);
    }  

    sleep(100);
    printf("Message from server: %s\n", buffer);
    close (sock);
    return 0;
}