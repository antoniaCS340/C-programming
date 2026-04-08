/*ΧΑΡΑΛΑΜΠΑΚΗ ΑΝΤΩΝΙΑ csd5104
	mystring_ars.c
 	Assignment 2	*/


#include<stddef.h>
#include<assert.h>
#include"mystring.h"


/*Calculates the length of a string by counting the number of characters until
  the first null terminator ('\0') is encountered.
  Returns the length of the pcStr, excluding the null terminator
  It is a checked runtime error for `pcStr` to be NULL */
size_t ms_length(const char pcStr[]){
	size_t uiLength;
	uiLength = 0U;
	assert(pcStr);
	while (pcStr[uiLength])
		uiLength++;
	return uiLength;
}


/*Copies the string pointed to by pcStr including the '\0' to 
  the array/pointer pointed to by strFinal
  Returns a pointer strFinal
  It is a checked runtime error for `pcStr` to be NULL*/
char * ms_copy(char str[], const char pcStr[]){
	size_t i;
	assert(pcStr);
	for(i = 0; pcStr[i]; i++)
		str[i] = pcStr[i];
	str[i] = '\0';
	return str;
}

/*Copies  'num' characters from the string pcStr to the
 * character array/pointer strFinal. If the length of the pcStr is less than 'num', null characters are appended to the
 * strFinal until 'num' characters in total have been written
 * Returns a pointer to char strFinal
 * It is a checked runtime error for `pcStr` to be NULL*/
char * ms_ncopy(char str[], const char pcStr[], size_t num){
	assert(pcStr);
	size_t i;
	i = 0U;
	while (num > 1 && pcStr[i]){
		str[i] = pcStr[i];
		num--;
		i++;
	}
	str[i] = '\0';
	return str;
}

/*Appends a copy of the null-terminated string 'pcStr' to the 
 * end of the null-terminated string 'con'. The '\0' in 'con' is overwritten by the first character,
 * and a null character is included at the end of the new string formed by the
 * concatenation of both in the destination array
 *  Returns a pointer to char con, which now contains the concatenated string
 * It is a checked runtime error for `pcStr` to be NULL*/
char * ms_concat(char con[], const char pcStr[]){
	assert(pcStr);
	size_t con_len = ms_length(con);
	size_t i = 0U;
    while (pcStr[i]) {
        con[con_len + i] = pcStr[i];
        i++;
    }
	con[con_len + i] = '\0';
	return con;
}


/*Appends 'num' characters from the null-terminated string pcStr
 * to the end of the null-terminated string con
 * The terminating null character in destination is overwritten 
 * and a null character is included at the end of the new
 * string formed by the concatenation of both in the destination array. If 'num'
 * characters are copied, no null character is automatically appended
 * to the destination array
 * Returns a pointer to char con, which now contains the concatenated string
 * It is a checked runtime error for `pcStr` to be NULL*/
char * ms_nconcat(char con[], const char pcStr[], size_t num){
	assert(pcStr);
	size_t con_len = ms_length(con);
	size_t i = 0U;
    while (pcStr[i] && i < num) {
        con[con_len + i] = pcStr[i];
        i++;
    }
	con[con_len + i] = '\0';
	return con;
}


/* Compares the two null-terminated strings pointed to by pcStr1 and pcStr2. 
 * The function returns an integer less than, equal to, or greater than zero
 * if pcStr1 is found to be less than, to match, or be greater 
 * than str2
 * It is a checked runtime error for `pcStr1` and 'pcStr2' to be NULL*/
int ms_compare(const char pcStr1[], const char pcStr2[]){
	assert(pcStr1);
	assert(pcStr2);
	size_t i = 0U;
	while (pcStr1[i] && pcStr2[i] && pcStr1[i] == pcStr2[i]) 
        i++;
	return (int)pcStr1[i] - (int)pcStr2[i];
}



/* Compares the first 'num' characters of two null-terminated strings 
 * pcStr1 and pcStr2. The function returns an integer less than,
 * equal to, or greater than zero if the first 'num' characters of str1 is found
 * to be less than, to match, or be greater than the first 'n'
 * characters of str2
 * It is a checked runtime error for `pcStr1` and 'pcStr2' to be NULL*/
int ms_ncompare(const char pcStr1[], const char pcStr2[], size_t num){
	assert(pcStr1);
	assert(pcStr2);
	size_t i = 0U;
	while (i < num && pcStr1[i] && pcStr2[i] && pcStr1[i] == pcStr2[i]) 
        i++;
	if (i == num)
		return 0;
	else
		return (int)pcStr1[i] - (int)pcStr2[i];
}


/* Finds the first occurrence of the substring subStr in the string pcStr 
 * The function returns a pointer to the first occurrence of the substring, or 
 * NULL if the substring is not found
 * It is a checked runtime error for `pcStr` and 'subStr' to be NULL*/
char * ms_search(const char subStr[], const char pcStr[]){
	assert(subStr);
	assert(pcStr);
	size_t i, j;

    for (i = 0; subStr[i]; i++) {
        j = 0;
        while (pcStr[j] && subStr[i + j] == pcStr[j]) {
            j++;
        }
        if (pcStr[j] == '\0') {
            return (char *)&subStr[i];
        }
    }
    
    return NULL;

}
