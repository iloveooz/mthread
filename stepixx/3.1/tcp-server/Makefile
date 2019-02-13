all: build_server build_client

build_server:
	# ggdb - добавляем отладочную информацию
	# O0 - выключаем любые оптимизации компилятором
	
	gcc -std=c99 -ggdb -O0 -o server server.c
	
build_client:
	
	gcc -std=c99 -ggdb -O0 -o client client.c
