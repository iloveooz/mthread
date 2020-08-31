
	#include <stdio.h> // для вывода на экран
	
	#include <sys/types.h> // для сокетов
	#include <sys/socket.h>
	#include <netinet/in.h>
	
	#include <unistd.h> // для функции close()
	
	int main(int argc, char **argv) {
		
		// создаём сокет
		int MasterSocket = socket(
			AF_INET, // IPv4
			SOCK_STREAM,  // TCP
			IPPROTO_TCP); // TCP
		
		// биндим сокет на адрес
		struct sockaddr_in SockAddr;
		
		SockAddr.sin_family = AF_INET; // протокол
		SockAddr.sin_port = htons(42222); // port
		SockAddr.sin_addr.s_addr = htonl(INADDR_ANY); // 0.0.0.0 all ip's
		
		bind(MasterSocket, (struct sockaddr *)(&SockAddr), sizeof(SockAddr));
		
		// начинаем слушать сокет
		listen(MasterSocket, SOMAXCONN);
		
		while(1) {
			// принимаем соединение и перекидываем его на другой сокет
			int SlaveSocket = accept(MasterSocket, 0, 0); 
			
			int Buffer[5] = { 0, 0, 0, 0, 0 };
			unsigned int counter = 0;
			
			// чтение из сокета, читаем все 4 байта
			while (counter < 4) {
				int res = recv(SlaveSocket, Buffer + 4 - counter, counter, MSG_NOSIGNAL);
				if (res > 0) {
					counter += res;
				}
			}
			
			send(SlaveSocket, Buffer, 4, MSG_NOSIGNAL);
			
			shutdown(SlaveSocket, SHUT_RDWR); // разрыв соединения
			close(SlaveSocket); // закрываем сокет
			
			printf("%s\n", Buffer); // вывод содержимого буфера
			
		}
		
		return 0;
	}
	
