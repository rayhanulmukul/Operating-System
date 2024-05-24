#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include<fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>

int main(){
    int pipId = open("chat", 0666);
    char buffer[1000];
    int sz;
    char* user1 = "User1 : ";
    char* user2 = "User2 : ";
    while(1){
        sz = read(pipId, &buffer, sizeof(buffer));
        write(STDOUT_FILENO, user1, strlen(user1));
        write(STDOUT_FILENO, buffer, strlen(buffer));
        if(buffer[0] == 'b' && buffer[1] == 'y' && buffer[2] == 'e'){
            break;
        }
        write(STDOUT_FILENO, user2, strlen(user2));
        sz = read(STDIN_FILENO, &buffer, sizeof(buffer));
        buffer[sz]='\n';
        write(pipId, buffer, strlen(buffer));
        if(buffer[0] == 'b' && buffer[1] == 'y' && buffer[2] == 'e'){
            break;
        }
        sleep(0.1);
    }
    exit(EXIT_SUCCESS);
}
