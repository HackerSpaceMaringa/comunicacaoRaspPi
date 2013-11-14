#include "hdr/repa.h"
#include "hdr/linkedlist.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "Management.h"

repa_sock_t sock;

int port = 9000;

int last = 35;
double i = 0;
void getTemperature(char* data){
    Management client;
    strcpy(data,(char*)client.initSocket(port).c_str());
    printf("%s\n",data);
}

void sendMessage(char* data){
    char* interest = (char*)malloc(255*sizeof(char));
    strcpy(interest,"server");
    printf("%s\n",data);
    size_t data_len = strlen(data);
    if (data_len > 0) {
        repa_send(sock, interest, data, data_len, 0);
        printf("Message sent I: \"%s\" D: \"%s\"\n", interest, data);
    }
    free(interest);
}

int main(){
    char *interest,*data;

    sock = repa_open();

    //Aloca espaço para registrar endereço e dados para transmissão
    interest = (char*)malloc(255*sizeof(char));
    data = (char*)malloc(1500*sizeof(char));

    strcpy(interest,"client");
    repa_register_interest(sock,interest); // Registra o interesse

    while (true){
        getTemperature(data);
        sendMessage(data);
        sleep(1);
    }
    free(interest);
    free(data);
    repa_close(sock);
    return 0;
}
