#include <iostream>
#include <WinSock2.h>
#include <WS2tcpip.h>

#pragma comment(lib, "Ws2_32.lib")

int main() {
    // Initialize Winsock
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        std::cerr << "WSAStartup failed" << std::endl;
        return 1;
    }

    // Create a UDP socket
    SOCKET clientSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (clientSocket == INVALID_SOCKET) {
        std::cerr << "Error creating socket" << std::endl;
        WSACleanup();
        return 1;
    }

    // Define the server address
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8888); // Port number
    inet_pton(AF_INET, "127.0.0.1", &serverAddress.sin_addr);

    // Send data
    const char *message = "Hello from C++ Windows UDP client!";
    sendto(clientSocket, message, strlen(message), 0, (sockaddr*)&serverAddress, sizeof(serverAddress));

    // Close the socket
    closesocket(clientSocket);
    WSACleanup();

    return 0;
}
