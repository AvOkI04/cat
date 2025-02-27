#include <stdio.h>
#include <stdlib.h>

// this func need for input and output symbols
void copy( FILE *in, FILE *out) {
	int c;
	while((c = getc(in))!=EOF) 
		putc(c,out);
}

int main(int argc, char *argv[]) {
	FILE *fp;

	if(argc == 1 )
		copy(stdin, stdout);
	else
		while(--argc>0) {
			if(( fp = fopen(*++argv, "r")) == NULL ) {
				printf("error!");
				exit(1);
			}
			else {
				copy(fp,stdout);
				fclose(fp);
			}
		}
	exit(0);
}
