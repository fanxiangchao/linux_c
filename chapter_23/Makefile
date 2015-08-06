all:server client

server:server.c
	gcc -g -o server server.c
client:client.c
	gcc -g -o client client.c
clean:
	rm *.o server client server1 client1

all_1:server_1 client_1

server_1:server1.c iolib.c
	gcc -g -o server1 server1.c iolib.c
client_1:client1.c iolib.c
	gcc -g -o client1 client1.c iolib.c

all_2:server_2 client_2

server_2:server2.c
	gcc -g -o server2 server2.c
client_2:client2.c
	gcc -g -o client2 client2.c

all_3:server_3 client_3

server_3:server3.c
	gcc -g -o server3 server3.c
client_3:client3.c
	gcc -g -o client3 client3.c

all_4:server_4 client_4

server_4:server4.c
	gcc -g -o server4 server4.c
client_4:client4.c
	gcc -g -o client4 client4.c


.PHONY:all_4
.PHONY:all_3
.PHONY:all_2
.PHONY:all_1
.PHONY:all
.PHONY:clean