#include <security/pam_modules.h>
#include <security/pam_ext.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

PAM_EXTERN int pam_sm_setcred( pam_handle_t *pamh, int flags, int argc, const char **argv ) 
{
	return PAM_SUCCESS;
}


PAM_EXTERN int pam_sm_authenticate( pam_handle_t *pamh, int flags,int argc, const char **argv ) 
{
	int serial1, serial2;
	
	
	serial1 = system("lsblk --output SERIAL /dev/sdb");
	serial2 = system("cat /etc/pam.d/pam.pdrive/teste.txt");

	char buffer[10];
	char buffer2[10];
	sprintf(serial1,buffer);
	sprintf(serial2, buffer2);
	

	if(strcmp(buffer, buffer2) == 0)
	{
		printf("\nseriais iguais\n");
		sleep(2);
		return PAM_SUCCESS;
	}
	else 
	{
		printf("\nSeriais diferentes\n");
		sleep(2);
		return PAM_SUCCESS;		

	}

	
}
