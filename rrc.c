#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char upperCaseLetters[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ_-";
char lowerCaseLetters[] = "0123456789abcdefghijklmnopqrstuvwxyz_-";

#define IS_UPPER_CASE(a) (a >= 'A' && a <= 'Z')
#define IS_LOWER_CASE(a) (a >= 'a' && a <= 'z')

#define TO_UPPER_CASE(a) (a- ('a'-'A'))
#define TO_LOWER_CASE(a) (a+ ('a'-'A'))

#define eq(a,b) (a == b || (IS_LOWER_CASE(a) && TO_UPPER_CASE(a) == b ) || (IS_UPPER_CASE(a) && TO_LOWER_CASE(a) == b ))

#define ALL_LOWER_CASE   0
#define FIRST_UPPER_CASE 1
#define FIRST_LOWER_CASE 0
#define ALL_UPPER_CASE   3


int main(int argc, char**argv) {

	if (argc < 4) {
		printf("Usage: %s FIND_PATTERN REPLACE_PATTERN_1 REPLACE_PATTERN_2 ... REPLACE_PATTERN_N\n",argv[0]); 
		return (1);
	}
	/* Read stdin stream into a memory buffer */
	long bufferSz = 1024;
	char *buffer = (char*)malloc(bufferSz);
	bufferSz = fread(buffer, 1,bufferSz,stdin);



	int i=0,j=0,k=0,l=strlen(argv[1]), m=0, _case=0;
	int matched = 0;

	/* ForEach replace pattern */
	for(k=0;k<(argc-2);k++) {
		/* Loop through the whole stdin */
		for(m=0;m<bufferSz;m++,j=0) {
			/* Loop through the whole FIND_PATTERN */
			for(i=0,_case=0;i<l&&m+i<bufferSz;i++) {
				if (IS_UPPER_CASE(buffer[m+i])) 
					if (i == 0) _case |= 1;
					else _case |= 2;
				if (eq(buffer[m+i],argv[1][j])) j++;
				if (j == l) {
					for(int z=0,zl=strlen(argv[k+2]);z<zl;z++) {
						     if (z>0 && _case != ALL_UPPER_CASE && IS_UPPER_CASE(argv[k+2][z])) 
							printf("%c", TO_LOWER_CASE(argv[k+2][z]));
						else if (z>0 && _case == ALL_UPPER_CASE && IS_LOWER_CASE(argv[k+2][z]))
							printf("%c", TO_UPPER_CASE(argv[k+2][z]));
						else if (z==0 && _case == FIRST_LOWER_CASE && IS_UPPER_CASE(argv[k+2][z]))
							printf("%c", TO_LOWER_CASE(argv[k+2][z]));
						else if (z==0 && _case == FIRST_UPPER_CASE && IS_LOWER_CASE(argv[k+2][z]))
							printf("%c", TO_UPPER_CASE(argv[k+2][z]));
						else
							printf("%c", argv[k+2][z]);
					}
					m += l;
				}
			}

			printf("%c",buffer[m]);

		}
	}
	
	return 0;
}
