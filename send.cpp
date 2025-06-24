#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>

int main() {
    // Create a socket
    int clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket < 0) {
        std::cerr << "Error creating socket" << std::endl;
        return 1;
    }

    // Define the server address
    struct sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8888); // Port number
    serverAddress.sin_addr.s_addr = inet_addr("127.0.0.1"); // Server's IP address

    // Connect to the server
    if (connect(clientSocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) < 0) {
        std::cerr << "Error connecting to server" << std::endl;
        return 1;
    }

    // Send data
    const char *message = "Hello from C++ client!";
    send(clientSocket, message, strlen(message), 0);

    // Close the socket
    close(clientSocket);

    return 0;
}