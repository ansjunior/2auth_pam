#include <security/pam_modules.h>
#include <security/pam_ext.h>
#include <stdlib.h>
#include <stdio.h>




PAM_EXTERN int pam_sm_authenticate( pam_handle_t *pamh, int flags,int argc, const char **argv ) 
{
	

	if(system("lsblk --output SERIAL /dev/sdb") == system("cat /etc/pam.d/pam.pdrive/teste.txt"))
	{
		printf("\nseriais iguais\n");
		sleep(2);
		return PAM_SUCCESS;
	}
	else 
	{
		printf("\nSeriais diferentes\n");
		sleep(2);
		return PAM_AUTH_ERR;
	}

	
}
