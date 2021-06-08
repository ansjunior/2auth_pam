pdrive.o: pdrive.c
	gcc -fPIC -lcurl -fno-stack-protector -c pdrive.c

install: pdrive.o
	gcc -fPIC -lcurl -fno-stack-protector -c pdrive.c
	ld -lcurl -x --shared -o /lib64/security/pdrive.so pdrive.o
	sed -i "4s/^/	auth	  required  pdrive.so\n/" /etc/pam.d/system-auth
	gcc mkdir_pdrive.c -o mkdir_pdrive
	./mkdir_pdrive

uninstall:
	rm -f /lib64/security/pdrive.so
	rm -rf /etc/pam.d/pdrive
	sed -i '/pdrive/d' /etc/pam.d/system-auth
	
	@echo "-------> Two factors auth removed successfully"


