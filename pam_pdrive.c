#include <security/pam_modules.h>
#include <security/pam_ext.h>
#include <stdlib.h>
#include <stdio.h>

PAM_EXTERN int pam_sm_setcred( pam_handle_t *pamh, int flags, int argc, const char **argv ) 
{
	return PAM_SUCCESS;
}


PAM_EXTERN int pam_sm_authenticate( pam_handle_t *pamh, int flags,int argc, const char **argv ) 
{
	int r = system("cat /etc/pam.d/pam.pdrive/teste.txt");
	int a = system("lsblk --output SERIAL /dev/sdb");
	char ra[50] 
	char aa[50]
	itoa(r, ra, 10);
	itoa(a, aa, 10);

	if(strcmp(ra, aa))
	{
		printf("\nSeriais diferentes\n");
		sleep(2);
		return PAM_AUTH_ERR;		

	}
	else 
	{
		printf("\nseriais iguais\n");
		sleep(2);
		return PAM_SUCCESS;
	}

	
}
