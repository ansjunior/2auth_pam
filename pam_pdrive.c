#include <security/pam_modules.h>
#include <security/pam_ext.h>


PAM_EXTERN int pam_sm_setcred( pam_handle_t *pamh, int flags, int argc, const char **argv ) 
{
	return PAM_SUCCESS;
}

PAM_EXTERN int pam_sm_authenticate( pam_handle_t *pamh, int flags,int argc, const char **argv ) 
{
	
	
	int system(const char *lsblk --output SERIAL /dev/sdb);
	printf(system);
	return PAM_SUCCESS;
	
}
