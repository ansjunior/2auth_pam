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
	mkdir("/etc/pam.d/pam.pdrive", 0700);
	}else{
            printf("    Diretório ja existente: /pam.pdrive\n");
    }
}



int main(int argc, char *argv[]){
    system("clear");

    puts("\n\n-> Attention, pendrive must be plugged in");
    system("read -p \"\nEnter to begin\" foo");

    system("clear"); 

     puts("\n-> Installing:");
    puts("<><><><><><>");
    sleep(2);

    puts("\n-> Creating directories:");
    puts("   '/etc/pam.d/pam.pdrive'");
     makeDirPdrive();
     sleep(2);


    system("read -p \"Press enter to continue\" foo");


}
