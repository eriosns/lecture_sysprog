#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#ifndef BUFFSIZE
#define	BUFFSIZE	4096
#endif

int
main(void)
{
	int		n;
	char	buf[BUFFSIZE];

	while ((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0){
		if (write(STDOUT_FILENO, buf, n) != n){
			fprintf(stderr, "write error\n");
			exit(1);
		}
	}

	if (n < 0){
		fprintf(stderr, "read error\n");
		exit(1);
	}

	return(0);
}
