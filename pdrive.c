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
	
	system("/sbin/udevadm info -n /dev/sdb -a | grep serial > /etc/pam.d/pam.pdrive/pen_drive2.txt");
	char pdrive[512];
	char pdrive2[512];

	FILE *pendrive1;
	FILE *pendrive2;
		
	pendrive1 = fopen("/etc/pam.d/pam.pdrive/pen_drive2.txt", "r");
	pendrive2 = fopen("/etc/pam.d/pam.pdrive/pen_drive.txt", "r");

	fgets(pdrive, 512, pendrive1);
	fgets(pdrive2, 512, pendrive2);
	
	sleep(1);
		
	if(strcmp(pdrive, pdrive2) == 0)
	{
		printf("\nOs seriais são iguais\n");
		sleep(1);
		return PAM_SUCCESS;
	}
	else 
	{
		printf("\nOs seriais são diferentes\n");
		sleep(1);
		return PAM_AUTH_ERR;		

	}

	
}
