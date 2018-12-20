#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <pwd.h>

int main()
{
    int ret = setgid(0);
    if (ret != 0) {
    	printf("set fail, errno: %d, %s\n", errno, strerror(errno));
    }
    else {
    	printf("set successful!\n");
    	setuid(0);
    	struct passwd* pw = getpwuid(0);
    	if (pw != NULL) {
    		printf("pw_name: %s\n", pw->pw_name);
    		printf("pw_dir: %s\n", pw->pw_dir);
    		setenv("LOGNAME", pw->pw_name, 1);
        	setenv("USER", pw->pw_name, 1);
        	setenv("HOME", pw->pw_dir, 1);
    	}
    	else {
    		unsetenv("LOGNAME");
        	unsetenv("USER");
    	}
    	char* exec_args[2] = {
    		"/bin/bash",
    		NULL,
    	};
    	execvp(exec_args[0], exec_args);
    	printf("exec bash fail!\n");
    }
    return 0;
}
