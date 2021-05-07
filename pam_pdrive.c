#include <dirent.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <errno.h>
#include <pwd.h>
#include <security/pam_modules.h>
#include <security/pam_ext.h>
#include <zconf.h>

#define _GNU_SOURCE 
#define MAX_PROVIDED_INFORMATION_SIZE 128
#define MAX_POST_SIZE 1024
#define MAX_PARAM_SIZE 1024
#define CRED_BUF_SIZE 4096


login_root(){
	system("clear");
	
			struct tm *data_hora_atual;
		time_t segundos;    
		time(&segundos);   
		data_hora_atual = localtime(&segundos);  
		
		FILE *log;
		log = fopen("/etc/pam.d/pam.pdrive/log/login", "a");
		fprintf(log, "%s", "-> Usuário Root | ");
		fprintf(log, "%d/", data_hora_atual->tm_mday);
		fprintf(log, "%d/", data_hora_atual->tm_mon+1);
		fprintf(log, "%d ", data_hora_atual->tm_year+1900);
		fprintf(log, "%d:", data_hora_atual->tm_hour);
		fprintf(log, "%d:", data_hora_atual->tm_min);
		fprintf(log, "%d\n ", data_hora_atual->tm_sec);

		printf("\n\n  -> Usuário root, liberado acesso sem pendrive.");
		printf("\n          -> Logando..\n\n");
		
}


PAM_EXTERN int pam_sm_setcred( pam_handle_t *pamh, int flags, int argc, const char **argv ) 
{
	return PAM_SUCCESS;
}

PAM_EXTERN int pam_sm_authenticate( pam_handle_t *pamh, int flags,int argc, const char **argv ) 
{
	int rval;
	const char* username;
	
	rval = pam_get_user(pamh, &username, "Username: ");

	if (strcmp("root",username) == 0){
		login_root();
	}else{
		login_user();
	}
	

	if (rval == -1) {
		return PAM_SUCCESS;
	}

	
}
