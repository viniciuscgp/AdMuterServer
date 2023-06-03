#include <stdio.h>
#include <winsock2.h>

#define PORT 8888
#define MAX_BUF 1024

#define UP 1
#define DOWN 2
#define MUTE 3
#define UNMUTE 4

void change_volume(int cmd)
{
    char command_line[255];
    switch (cmd)
    {
    case UP:
        sprintf(command_line, ".\\tools\\nircmd.exe changesysvolume 2000"); // Aumenta o volume;
        break;
    case DOWN:
        sprintf(command_line, ".\\tools\\nircmd.exe changesysvolume -2000"); // Diminui o volume
        break;
    case MUTE:
        sprintf(command_line, ".\\tools\\nircmd.exe mutesysvolume 1");; // mute
        break;
    case UNMUTE:
        sprintf(command_line, ".\\tools\\nircmd.exe mutesysvolume 0");; // Diminui o volume
        break;
    default:
        printf("Unknown command: %d\n", cmd);
        return;
    }

    system(command_line);
}

int main()
{
    WSADATA wsa;
    SOCKET sockfd;
    struct sockaddr_in servaddr, cliaddr;
    char buffer[MAX_BUF];
    int cmd;

    // Inicializa a winsock
    printf("Starting Winsock...\n");
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
    {
        printf("Failure. Error: %d", WSAGetLastError());
        return 1;
    }
    printf("Started.\n");

    // Cria um soquete
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) == INVALID_SOCKET)
    {
        printf("Cannot create a socket : %d", WSAGetLastError());
    }
    printf("Socket created.\n");

    // Configura o servidor
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(PORT);

    // Liga o servidor ao endereço do soquete
    if (bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == SOCKET_ERROR)
    {
        printf("Bind failure. Error: %d", WSAGetLastError());
        return 1;
    }
    printf("Binded.\n");

    int len, n;
    len = sizeof(cliaddr);

    printf("Wating for commands...\n");

    // Infine loop to maintain the server running.
    while (1)
    {
        n = recvfrom(sockfd, buffer, MAX_BUF, 0, (struct sockaddr *)&cliaddr, &len);
        if (n == SOCKET_ERROR)
        {
            printf("recvfrom failure with error: %d\n", WSAGetLastError());
            return 1;
        }
        buffer[n] = '\0';
        printf("Peer : %s\n", buffer);

        cmd = atoi(buffer);

        change_volume(cmd);
    }

    closesocket(sockfd);
    WSACleanup();

    return 0;
}
