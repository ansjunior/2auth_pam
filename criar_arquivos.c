#include <dirent.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <errno.h>
#include <pwd.h>


void makeDirPdrive(){

    //variavel que grava o estado, 0 diretorio nao existe, -1 existe.
    struct stat st = {0};
	
    //se existe, retorna msg, se não cria o diretório
	if (stat("/etc/pam.d/pam.pdrive", &st) == -1) {
		if(mkdir("/etc/pam.d/pam.pdrive", 0700) == 0){
            printf("    Diretório criado com Sucesso: /pam.pdrive\n");
		}else{
            printf("    Erro ao criar diretório: /pam.pdrive\n");
        }
	}else{
            printf("    Diretório ja existente: /pam.pdrive\n");
    }
}



void makeFileSerial(){
    FILE *pdrive_serial;
    
    pdrive_serial = fopen("/etc/pam.d/pam.pdrive/pdrive.serial", "a");

    if (pdrive_serial == NULL){
        printf("    Erro ao criar arquivo de seriais.\n");
    }
    else{
        printf("    Arquivo de seriais criado com sucesso.\n");
    }
}

int verPendrive(){
    ssize_t len;
     
    char buf[256], *p;
    char buf2[256];
    int i;
   
    len = readlink("/sys/block/sdb", buf, 256);
   
    buf[len] = 0;
   
    // printf("%s\n", buf);
    sprintf(buf2, "%s/%s", "/sys/block/", buf);
    for (i=0; i<6; i++) {
        p = strrchr(buf2, '/');
        *p = 0;
    }
   
    // printf("%s\n", buf2);
    strcat(buf2, "/serial");
    // printf("opening %s\n", buf2);

    int f = open(buf2, 0);
    len = read(f, buf, 256);
    if (len <= 0) {
        printf("Erro");
    }
 
    buf[len - 1] = 0;

    int qtd = strlen(buf);

    return qtd;
    
}

char verSerial(){
    ssize_t len;
     
    char buf[256], *p;
    char buf2[256];
    int i;
   
    len = readlink("/sys/block/sdb", buf, 256);
   
    buf[len] = 0;
   
    // printf("%s\n", buf);
    sprintf(buf2, "%s/%s", "/sys/block/", buf);
    for (i=0; i<6; i++) {
        p = strrchr(buf2, '/');
        *p = 0;
    }
   
    // printf("%s\n", buf2);
    strcat(buf2, "/serial");
    // printf("opening %s\n", buf2);

    int f = open(buf2, 0);
    len = read(f, buf, 256);
    if (len <= 0) {
        
    }
 
    buf[len - 1] = 0;
    

    return buf;

}


void addUser( char nome[256] ){
    ssize_t len;
     
    char buf[256], *p;
    char buf2[256];
    int i;
   
    len = readlink("/sys/block/sdb", buf, 256);
   
    buf[len] = 0;
   
    sprintf(buf2, "%s/%s", "/sys/block/", buf);
    for (i=0; i<6; i++) {
        p = strrchr(buf2, '/');
        *p = 0;
    }
   
    strcat(buf2, "/serial");

    int f = open(buf2, 0);
    len = read(f, buf, 256);
    if (len <= 0) {
        
    }
 
    buf[len - 1] = 0;

    FILE *pont_arq; // cria variável ponteiro para o arquivo
        
        //abrindo o arquivo com tipo de abertura w
        pont_arq = fopen("/etc/pam.d/pam.pdrive/pdrive.serial", "w");
        
        //testando se o arquivo foi realmente criado
        if(pont_arq == NULL)
        {
        printf("    Error!");
        }
        
        //usando fprintf para armazenar a string no arquivo
        fprintf(pont_arq, "%s", buf);

        //usando fclose para fechar o arquivo
        fclose(pont_arq);

        puts("    Work done successfully\n");

}

int main(int argc, char *argv[]){
    system("clear");

    puts("\n\n-> Attention, pendrive must be plugged in");
    system("read -p \"\nEnter to begin\" foo");

    system("clear"); 

     puts("\n-> Installing:");
    puts("<><><><><><");
    sleep(2);

    puts("\n-> Creating directories:");
    puts("   '/etc/pam.d/pam.pdrive'");
    puts("   '/etc/pam.d/pam.pdrive/log'");
    makeDirPdrive();
     sleep(2);

    puts("\n-> Creating files to save serials:");
    puts("   '/etc/pam.d/pam.pdrive'");
    puts("   '/etc/pam.d/pam.pdrive/log'");
    makeFileSerial();
    

    char nome[100]; 

    puts("\n-> Allowing pendrive:");

    addUser(nome);

    system("read -p \"Press enter to continue\" foo");




}
