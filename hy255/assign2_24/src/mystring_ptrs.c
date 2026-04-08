/*ΧΑΡΑΛΑΜΠΑΚΗ ΑΝΤΩΝΙΑ csd5104
	mystring_ptrs.c
 	Assignment 2	*/

#include<stddef.h>
#include<assert.h>
#include<stdio.h>
#include"mystring.h"


/*Calculates the length of a string by counting the number of characters 
  until the first null terminator ('\0') is encountered.
  Returns the length of the pcStr, excluding the null terminator
  It is a checked runtime error for `pcStr` to be NULL */
size_t ms_length(const char *pcStr) {
	const char *pcStrEnd = pcStr;
	assert(pcStr);
	while(*pcStrEnd)
		pcStrEnd++;
	return pcStrEnd-pcStr;
}

/*Copies the string pointed to by pcStr including the '\0' to 
  the array/pointer pointed to by strFinal
  Returns a pointer strFinal
  It is a checked runtime error for `pcStr` to be NULL*/
char* ms_copy(char *strFinal, const char *pcStr) {
	assert(pcStr);
       while(*pcStr){
       		*strFinal++ = *pcStr++;
       }
	*strFinal = '\0';
	return strFinal;
}


/*Copies  'num' characters from the string pcStr to the
 * character array/pointer strFinal. If the length of the pcStr is less than 
 * 'num', null characters are appended to the
 * strFinal until 'num' characters in total have been written
 * Returns a pointer to char strFinal
 * It is a checked runtime error for `pcStr` to be NULL*/
char * ms_ncopy(char *strFinal, const char *pcStr, size_t num){
	assert(pcStr);
	const char *pcStrTmp = pcStr;
	while (num > 1 && *pcStrTmp){
		*strFinal++ = *pcStr++;
		num--;
	}
	while (num-- > 0) 
		*strFinal++ = '\0';
	return strFinal;
}

/*Appends a copy of the null-terminated string 'pcStr' to the 
 * end of the null-terminated string 'con'. The '\0' in 'con' is overwritten
 * by the first character,
 * and a null character is included at the end of the new string formed by the
 * concatenation of both in the destination array
 * Returns a pointer to char con, which now contains the concatenated string
 * It is a checked runtime error for `pcStr` to be NULL*/
char * ms_concat(char *con, const char *pcStr) {
	assert(con);
	assert(pcStr);
	while (*con)
		con++;
	while (*pcStr)
		*con++ = *pcStr++;
	*con = '\0';
	return con;
}


/*Appends 'num' characters from the null-terminated string pcStr
 * to the end of the null-terminated string con
 * The terminating null character in destination is overwritten 
 * and a null character is included at the end of the new
 * string formed by the concatenation of both in the destination array. If 
 * 'num'characters are copied, no null character is automatically appended
 * to the destination array
 * Returns a pointer to char con, which now contains the concatenated string
 * It is a checked runtime error for `pcStr` to be NULL*/
char * ms_nconcat(char *con, const char *pcStr, size_t num){
	assert(con);
	assert(pcStr);
	while (*con)
		con++;
	while (*pcStr && num > 0){
		*con++ = *pcStr++;
		num--;
	}
	*con = '\0';
	return con;
}


/* Compares the two null-terminated strings pointed to by pcStr1 and pcStr2. 
 * The function returns an integer less than, equal to, or greater than zero
 * if pcStr1 is found to be less than, to match, or be greater 
 * than str2
 * It is a checked runtime error for `pcStr1` and 'pcStr2' to be NULL*/
int ms_compare(const char *pcStr1, const char *pcStr2){
	assert(pcStr1);
	assert(pcStr2);
	while (*pcStr1 && *pcStr2 && *pcStr1 == *pcStr2) {
        pcStr1++;
        pcStr2++;
    }
	return (*pcStr1 - *pcStr2);
}

/* Compares the first 'num' characters of two null-terminated strings 
 * pcStr1 and pcStr2. The function returns an integer less than,
 * equal to, or greater than zero if the first 'num' characters of str1 is found
 * to be less than, to match, or be greater than the first 'n'
 * characters of str2
 * It is a checked runtime error for `pcStr1` and 'pcStr2' to be NULL*/
int ms_ncompare(const char *pcStr1, const char *pcStr2, size_t num){
	assert(pcStr1);
	assert(pcStr2);
	while (num > 0 && *pcStr1 && *pcStr2 && *pcStr1 == *pcStr2) {
        pcStr1++;
        pcStr2++;
		num--;
    }
	if (num)
		return (*pcStr1 - *pcStr2);
	else
		return 0;
}


/* Finds the first occurrence of the substring subStr in the string pcStr 
 * The function returns a pointer to the first occurrence of the substring, or 
 * NULL if the substring is not found
 * It is a checked runtime error for `pcStr` and 'subStr' to be NULL*/
char * ms_search(const char *subStr, const char *pcStr){
	assert(subStr);
	assert(pcStr);
	const char *sub, *p;
    
    while (*subStr) {
        sub = subStr;
        p = pcStr;
        while (*p && *sub == *p) {
            sub++;
            p++;
        }
        if (*p == '\0')
            return (char *)subStr;
        subStr++;
    }
    
    return NULL;
}