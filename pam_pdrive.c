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
	int serial1, serial2, result;
	
	
	serial1 = system("lsblk --output SERIAL /dev/sdb");
	serial2 = system("cat /etc/pam.d/pam.pdrive/teste.txt");

	char a[60];
	char b[60];
	sprintf(a, "lsblk --output SERIAL /dev/sdb");
    	sprintf(b, "cat /etc/pam.d/pam.pdrive/teste.txt");
	
	result = strcmp(a, b);
	if(result == 0)
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
