#include <security/pam_modules.h>
#include <security/pam_ext.h>
#include <stdlib.h>


PAM_EXTERN int pam_sm_setcred( pam_handle_t *pamh, int flags, int argc, const char **argv ) 
{
	return PAM_SUCCESS;
}

PAM_EXTERN int pam_sm_authenticate( pam_handle_t *pamh, int flags,int argc, const char **argv ) 
{
	int main (){
		int r;
		r=system("lsblk --output SERIAL /dev/sdb");
		return r; }
	
	
	printf("Teste/n/n");
	return PAM_SUCCESS;
	
}
