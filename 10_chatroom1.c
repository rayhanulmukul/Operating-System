#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>

int main(){
    int pipID = open("chat", 0666);
    char buffer[1000];
    int sz;
    char *user1 = "User1 : ";
    char *user2 = "User2 : ";

    while(1){
        write(STDOUT_FILENO, user1, strlen(user1));
        sz = read(STDIN_FILENO, &buffer, sizeof(buffer));
        write(pipID, buffer, strlen(buffer));
        if(buffer[0] == 'b' && buffer[1] == 'y' && buffer[2] == 'e'){
            break;
        }
        sleep(0.1);

        sz = read(pipID, &buffer, sizeof(buffer));
        buffer[sz] = '\n';
        write(STDOUT_FILENO, user2, strlen(user2));
        write(STDOUT_FILENO, buffer, strlen(buffer));
        if(buffer[0] == 'b' && buffer[1] == 'y' && buffer[2] == 'e'){
            break;
        }
    }

    exit(EXIT_SUCCESS);
}