/*
Módulo criado para aula de SO II - Professor: Rossano
Anisio Rodrigues da Silva Junior
Vitor Marcolin
Daniel Evaldo da Silva
Beatriz Camargo
Otavio Lisboa
*/

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


void mkdirusb(){

    // Variavel que grava o estado, 0 diretorio nao existe, -1 existe.
    struct stat st = {0};
	
    //se existe, retorna msg, se não, cria o diretório.
	if (stat("/etc/pam.d/pdrive", &st) == -1) {
	mkdir("/etc/pam.d/pdrive", 0700);
	}else{
            printf("    Diretório ja existente: /pdrive\n");
    }
}


// Mostra ao usuário o que está acontecendo
int main(int argc, char *argv[]){
	
	// Se o pen drive não estiver conectado, essa variável não retornará zero
	if(system("lsblk --output SERIAL /dev/sdb") == 0)
    {
	
	puts("\n\n-> Attention, pendrive must be plugged in");
    	system("read -p \"\nEnter to begin\" foo");

    	system("clear"); 
	
    	puts("\n-> Installing:");
    	puts("<><><><><><>");
    	sleep(1);

    	puts("\n-> Creating directory");
    	puts("   '/etc/pam.d/pdrive'");
	    
	// Abaixo entra no void (la em cima) que cria o diretório
	mkdirusb();
	    
	//system("lsblk --output SERIAL /dev/sdb > /etc/pam.d/pam.pdrive/teste.txt");
	// Esse comando acima pega o serial tambem, mas estávamos com erro pois ele tinha duas linhas

	// Esse comando abaixo pega o serial do pen drive e grava em um arquivo de texto
	system("/sbin/udevadm info -n /dev/sdb -a | grep serial > /etc/pam.d/pdrive/pen_drive.txt");
     	sleep(1);
    
    }
	
    else 
	{
		printf("\nUSB Flash drive not recognized\n");
		printf("\nUninstall make file, plug the pen drive, and try it again\n");
	}

    system("read -p \"Press enter to continue\" foo");


}
