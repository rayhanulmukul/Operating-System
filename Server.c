#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include<stdlib.h>

int main()
{
    int description;
    int client;
    char storage[80];
    int length;
    int option=1;
    struct sockaddr_in server;
    struct sockaddr_in connection;
    char* message = "This is a message from the server";
    description = socket(AF_INET, SOCK_STREAM, 0);
    if(description<0)
   {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
   }     
    int status=setsockopt(description, SOL_SOCKET,SO_REUSEADDR , &option,sizeof(option));
    if(status<0){
        perror("Couldn't set options");
        exit(EXIT_FAILURE);
    }
    server.sin_family = AF_INET;
    server.sin_port = htons(8080);
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_zero[8]='\0';
    status=bind(description, (struct sockaddr*)&server, sizeof(struct sockaddr));
    if(status<0){
        perror("Couldn't bind socket");
        exit(EXIT_FAILURE);
    }
    status=listen(description,4);
    if(status<0){
        perror("Couldn't listen for connections");
        exit(EXIT_FAILURE);
    }
    length = sizeof(connection);
    client = accept(description, (struct sockaddr*)&connection, &length);
    if(client<0){
        perror("Couldn't establish connection with client");
        exit(EXIT_FAILURE);
    }
    read(client, storage, 80);
    storage[79] = '\0';
    printf("Message from client: %s \n",storage);
    send(client, message, strlen(message), 0);
    close(description);
    close(client);
    return 0;
}
