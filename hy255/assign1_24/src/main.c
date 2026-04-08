#include <stdio.h>

int main(void){
	int c;
	
	char A[73][4] = { {'\'','A'},
			{' '},
			{'\'','E'},
			{'\'','H'},
			{'\'','I'},
			{' '},
			{'\'','O'},
			{' '},
			{'\'','Y'},
			{'\'','W'},
			{'i','"','\''},
			{'A'},
			{'V'},
			{'G'},
			{'D'},
			{'E'},
			{'Z'},
			{'H'},
			{'8'},
			{'I'},
			{'K'},
			{'L'},
			{'M'},
			{'N'},
			{'K','S'},
			{'O'},
			{'P'},
			{'R'},
			{' '},
			{'S'},
			{'T'},
			{'Y'},
			{'F'},
			{'X'},
			{'P','S'},
			{'W'},
			{'I','"'},
			{'Y','"'},
			{'a','\''},
			{'e','\''},
			{'h','\''},
			{'i','\''},
			{'y','"','\''},
			{'a'},
			{'v'},
			{'g'},
			{'d'},
			{'e'},
			{'z'},
			{'h'},
			{'8'},
			{'i'},
			{'k'},
			{'l'},
			{'m'},
			{'n'},
			{'k','s'},
			{'o'},
			{'p'},
			{'r'},
			{'s'},
	     		{'s'},
			{'t'},
			{'y'},
			{'f'},
			{'x'},
			{'p','s'},
			{'w'},
			{'i','"'},
			{'y','"'},
			{'o','\''},
			{'y','\''},
			{'w','\''}
			
	};
	
	int flag_n = 0;
	int flag_m = 0;
	while ((c = getchar()) != EOF){
		if(c < 182){
			if(flag_m){
				putchar('m');
			}else if(flag_n){
				putchar('n');
			}
			flag_m = flag_n = 0;
			printf("%c",c);
		} else if(c == 205 || c == 237){
			if(flag_n){
				printf("%s",A[flag_n-182]);
			} else {
				flag_n = c;
			}
		} else if(c == 204 || c == 236){
			if(flag_m){
				printf("%s",A[flag_m-182]);
			} else {
				flag_m = c;
			}
		} else{
			if(flag_n && (c == 212 || c == 244)){
				if(flag_n == 205){
					putchar('D');
				} else {
					putchar('d');
				}
			} else if(flag_m && (c == 208 || c == 240)){
				if(flag_m == 204){
					putchar('B');
				} else {
					putchar('b');
				}
			} else {
				if(flag_n){
					printf("%s",A[flag_n-182]);
				} else if(flag_m){
					printf("%s",A[flag_m-182]);
				}
				printf("%s",A[c-182]);
			}
			flag_n = flag_m = 0;
		}
	}
	if(flag_n){
		printf("%s",A[flag_n-182]);
	} else if(flag_m){
		printf("%s",A[flag_m-182]);
	}
	printf("\n");

	return 0;
}
