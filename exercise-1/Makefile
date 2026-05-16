.PHONY: all clean

all: build/client build/server

build/client: src/tcp_echo_client.cc
	mkdir -p build
	g++ src/tcp_echo_client.cc -o build/client

build/server: src/tcp_echo_server.cc
	mkdir -p build
	g++ src/tcp_echo_server.cc -o build/server

clean:
	rm -rf build
