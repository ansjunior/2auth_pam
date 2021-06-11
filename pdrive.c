/*
Módulo criado para aula de SO II - Professor: Rossano
Anisio Rodrigues da Silva Junior
Vitor Marcolin
Daniel Evaldo da Silva
Beatriz Camargo
Otavio Lisboa
*/

#include <security/pam_modules.h>
#include <security/pam_ext.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <math.h>


PAM_EXTERN int pam_sm_setcred( pam_handle_t *pamh, int flags, int argc, const char **argv ) 
{
	return PAM_SUCCESS;
}


PAM_EXTERN int pam_sm_authenticate( pam_handle_t *pamh, int flags,int argc, const char **argv ) 
{
	// Cria um diretório com o serial do pen drive atual plugado
	system("/sbin/udevadm info -n /dev/sdc -a | grep serial > /etc/pam.d/pdrive/pen_drive2.txt");
	char pdrive[512];
	char pdrive2[512];

	FILE *pendrive;
	FILE *pendrive2;
		
	// O "pendrive" pega do arquivo criado lá no mkdir_pdrive para depois comparar com o serial do pen drive atual
	pendrive = fopen("/etc/pam.d/pdrive/pen_drive.txt", "r");
	pendrive2 = fopen("/etc/pam.d/pdrive/pen_drive2.txt", "r");

	fgets(pdrive, 512, pendrive);
	fgets(pdrive2, 512, pendrive2);
	
	sleep(1);
		
	if(strcmp(pdrive, pdrive2) == 0)
	{
		printf("\nThe serials are the same\n");
		sleep(1);
		return PAM_SUCCESS;
	}
	else 
	{
		printf("\nThe serials are not the same\n");
		sleep(1);
		return PAM_AUTH_ERR;		

	}

	
}
