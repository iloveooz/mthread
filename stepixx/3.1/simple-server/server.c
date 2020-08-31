
	#include <sys/types.h>
	#include <sys/socket.h>
	#include <netinet/in.h>
	#include <arpa/inet.h>
	#include <unistd.h>
	
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	
	#define PORT 11000
	
	int main(void) {
		
		struct sockaddr_in stSockAddr;
		
		int i32SocketFD = socket(
						AF_INET,
						SOCK_STREAM,
						IPPROTO_TCP);
		
		if (i32SocketFD == -1) {
			perror("ошибка при создании сокета");
			exit(EXIT_FAILURE);
		}
		
		// очищаем структуру sockaddr
		memset(&stSockAddr, 0, sizeof(stSockAddr));
		
		stSockAddr.sin_family = AF_INET;
		stSockAddr.sin_port = htons(PORT);
		stSockAddr.sin_addr.s_addr = htonl(INADDR_ANY);
		
		if (bind(i32SocketFD, (struct sockaddr *) (&stSockAddr), sizeof(stSockAddr)) == -1) {
			perror("ошибка связывания");
			close(i32SocketFD);
			exit(EXIT_FAILURE);
		}
		
		if (listen(i32SocketFD, SOMAXCONN) == -1) {
			perror("ошибка прослушивания");
			close(i32SocketFD);
			exit(EXIT_FAILURE);
		}
		
		for (;;) {
			int i32ConnectFD = accept(i32SocketFD, 0, 0);
		
			if (i32ConnectFD < 0) {
				perror("ошибка принятия");
				close(i32SocketFD);
				exit(EXIT_FAILURE);
			}
			
			// операции чтения и записи
			int Buffer[5] = { 0, 0, 0, 0, 0 };
			
			// чтение из сокета, читаем все 4 байта
			recv(i32ConnectFD, Buffer, 4, MSG_NOSIGNAL);
			send(i32ConnectFD, Buffer, 4, MSG_NOSIGNAL);

			shutdown(i32ConnectFD, SHUT_RDWR);
			close(i32ConnectFD);
			
			printf("%s\n", Buffer); // вывод содержимого буфера
		}
		
		return 0;
	}
	
