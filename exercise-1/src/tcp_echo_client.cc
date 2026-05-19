#include <arpa/inet.h>
#include <iostream>
#include <netinet/in.h>
#include <string>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

int create_client_socket() {
  int client_sock = socket(AF_INET, SOCK_STREAM, 0);
  if (client_sock < 0) {
    std::cerr << "Socket creation error\n";
    return -1;
  }
  return client_sock;
}

bool create_server_address(const std::string &server_address, int port,
                           sockaddr_in &address) {
  address.sin_family = AF_INET;
  address.sin_port = htons(port);
  // Convert IPv4 and IPv6 addresses from text to binary form
  if (inet_pton(AF_INET, server_address.c_str(), &address.sin_addr) <= 0) {
    std::cerr << "Invalid address/ Address not supported\n";
    return false;
  }
  return true;
}

int main(int argc, char *argv[]) {
  // #Question - are these the same type?
  //
  // #Answer - No they are not the same type. LHS is std::string object RHS is a
  // C-style string. std::string copies and owns the string.
  // std::string message = "Hello from client";

  if (argc < 2) {
    std::cerr << "Usage: " << argv[0] << " <message>\n";
    return 1;
  }

  std::string message = argv[1];
  std::cout << message << '\n';

  const int kPort = 8080;
  const std::string kServerAddress = "127.0.0.1";
  sockaddr_in address;
  const int kBufferSize = 1024;
  char buffer[kBufferSize] = {0};

  // Creating socket file descriptor
  int client_sock = create_client_socket();
  if (client_sock < 0) {
    return 1;
  }

  // Creating server address for client
  if (!create_server_address(kServerAddress, kPort, address)) {
    return 1;
  }

  // Connect to the server
  if (connect(client_sock, (sockaddr *)&address, sizeof(address)) < 0) {
    std::cerr << "Connection Failed\n";
    return -1;
  }
  // Send message
  send(client_sock, message.c_str(), message.size(), 0);
  std::cout << "Sent: " << message << "\n";
  // Wait for reply
  ssize_t read_size = read(client_sock, buffer, kBufferSize);
  std::cout << "Received: " << buffer << "\n";
  // Close the socket
  close(client_sock);
  return 0;
}
