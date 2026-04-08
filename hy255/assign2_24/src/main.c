#include<stdio.h>
#include<stddef.h>
#include"mystring.h"

int main() {

    	int i = ms_length("antonia");

    	char str1[20] = "C programming";
	char str2[20];
	printf("ms_length %d\n",i);

	ms_copy(str2, str1);
	puts(str2); 

	/*str1[20] = "C programming";
	ms_ncopy(str2,str1,5);
	puts(str2);

	char dest[100] = "Hello, ";
	char src[] = "world!";

	ms_concat(dest, src);

	printf("Concatenated string: %s\n", dest);

	const char str3[] = "Hello";
	const char str4[] = "Hellono";

	int result = ms_compare(str3, str4);

	if (result == 0) {
        	printf("Strings are equal.\n");
	} else if (result < 0) {
        	printf("String 1 is less than String 2.\n");
	} else {
        	printf("String 1 is greater than String 2.\n");
	}

	result = ms_ncompare(str1, str2,5);

	if (result == 0) {
        	printf("Strings are equal.\n");
	} else if (result < 0) {
        	printf("String 1 is less than String 2.\n");
	} else {
        	printf("String 1 is greater than String 2.\n");
	}

	const char haystack[] = "Hello, world!";
	const char needle[] = "world";

	char *result1 = ms_search(haystack, needle);
	if (result1 != NULL) {
        	printf("Substring found at index: %ld\n", result1 - haystack);
	} else {
        	printf("Substring not found.\n");
	}*/

	return 0;
}
