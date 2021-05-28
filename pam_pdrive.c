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
	int* serial1, serial2, result;
	
	FILE *pendrive1;
	FILE *pendrive2;
	pendrive1 = popen("lsblk --output SERIAL /dev/sdb", "r");
	pendrive2 = popen("lsblk --output SERIAL /dev/sdb", "r");
	
	
	serial1 = pclose(pendrive1);
	serial2 = pclose(pendrive2);

	char a[60];
	char b[60];
	sprintf(a, "%d", serial1);
    	sprintf(b, "%d", serial2);
	
	
	if(strcmp(a,b) == 0)
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
