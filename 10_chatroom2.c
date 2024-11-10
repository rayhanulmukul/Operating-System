#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(){
    int pidID = open("chat", 0666);
    char buffer[1000];
    int sz;
    char *user1 = "User1 : ";
    char *user2 = "User2 : ";
    while(1){
        sz = read(pidID, &buffer, sizeof(buffer));
        write(STDOUT_FILENO, user1, strlen(user1));
        write(STDOUT_FILENO, buffer, strlen(buffer));
        if(buffer[0] == 'b' && buffer[1] == 'y' && buffer[2] == 'e'){
            break;
        }

        write(STDOUT_FILENO, user2, strlen(user2));
        sz = read(STDIN_FILENO, &buffer, sizeof(buffer));
        buffer[sz] = '\n';
        write(pidID, buffer, strlen(buffer));
        if(buffer[0] == 'b' && buffer[1] == 'y' && buffer[2] == 'e'){
            break;
        }
        sleep(0.1);
    }
    exit(EXIT_SUCCESS);
}