#include <security/pam_modules.h>
#include <security/pam_ext.h>
#include <stdlib.h>


PAM_EXTERN int pam_sm_setcred( pam_handle_t *pamh, int flags, int argc, const char **argv ) 
{
	return PAM_SUCCESS;
}

PAM_EXTERN int pam_sm_authenticate( pam_handle_t *pamh, int flags,int argc, const char **argv ) 
{
	
	int r;
	r=system("lsblk --output SERIAL /dev/sdb");
	return r; 
		if(r == "lsblk: /dev/sdb: not a block device")
	{
		printf("aqui mesmo");
		return PAM_SUCCESS;

	}	else{
	
		printf(r);
		return PAM_SUCCESS;
		}
}
