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
	char r;
	char a;
	r = system("cat /etc/pam.d/pam.pdrive/teste.txt");
	a = system("cat /etc/pam.d/pam.pdrive/teste.txt");

	if(system("cat /etc/pam.d/pam.pdrive/teste.txt") == system("cat /etc/pam.d/pam.pdrive/teste.txt")))
	{
		printf("seriais iguais");
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
