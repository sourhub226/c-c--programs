all:client.o server.o
	g++  client/client.o -o client/client
	g++  server/server.o -o server/server
client.o:
	g++ -c client/client.cpp -o client/client.o
server.o:
	g++ -c server/server.cpp -o server/server.o
clean:
	rm -r client/client.o
	rm -r server/server.o
	rm -r client/client
	rm -r server/server

