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

    // Variavel que grava o estado, 0 diretorio nao existe, -1 existe.
    struct stat st = {0};
	
    //se existe, retorna msg, se não, cria o diretório.
	if (stat("/etc/pam.d/pam.pdrive", &st) == -1) {
	mkdir("/etc/pam.d/pam.pdrive", 0700);
	}else{
            printf("    Diretório ja existente: /pam.pdrive\n");
    }
}



int main(int argc, char *argv[]){
    if(system("lsblk --output SERIAL /dev/sdb") == 0)
    {
	    
	puts("\n\n-> Attention, pendrive must be plugged in");
    system("read -p \"\nEnter to begin\" foo");

    system("clear"); 
	
     puts("\n-> Installing:");
    puts("<><><><><><>");
    sleep(1);

    puts("\n-> Creating directory");
    puts("   '/etc/pam.d/pam.pdrive'");
     makeDirPdrive();
	//system("lsblk --output SERIAL /dev/sdb > /etc/pam.d/pam.pdrive/teste.txt");
	system("/sbin/udevadm info -n /dev/sdb -a | grep serial > /etc/pam.d/pam.pdrive/teste.txt");
     sleep(1);
    
    }
	
    else 
	{
		printf("\nPen drive não plugado\n");
		printf("\nUninstall make file, plug the pen drive and try it again\n");
	}

    system("read -p \"Press enter to continue\" foo");


}
