/*ΧΑΡΑΛΑΜΠΑΚΗ ΑΝΤΩΝΙΑ csd5104
	mystring.h
 	Assignment 2	*/

/*Calculates the length of a string by counting the number of characters until
  the first null terminator ('\0') is encountered.
  Returns the length of the pcStr, excluding the null terminator
  It is a checked runtime error for `pcStr` to be NULL */
size_t ms_length(const char *pcStr);


/*Copies the string pointed to by pcStr including the '\0' to 
  the array/pointer pointed to by strFinal
  Returns a pointer strFinal
  It is a checked runtime error for `pcStr` to be NULL*/
char * ms_copy(char *strFinal, const char *pcStr);


/*Copies  'num' characters from the string pcStr to the
 * character array/pointer strFinal. If the length of the pcStr is less than 'num', null characters are appended to the
 * strFinal until 'num' characters in total have been written
 * Returns a pointer to char strFinal
 * It is a checked runtime error for `pcStr` to be NULL*/
char * ms_ncopy(char *strFinal, const char *pcStr, size_t num);


/*Appends a copy of the null-terminated string 'pcStr' to the 
 * end of the null-terminated string 'con'. The '\0' in 'con' is overwritten by the first character,
 * and a null character is included at the end of the new string formed by the
 * concatenation of both in the destination array
 *  Returns a pointer to char con, which now contains the concatenated string
 * It is a checked runtime error for `pcStr` to be NULL*/
char * ms_concat(char *strFinal, const char *pcStr);


/*Appends 'num' characters from the null-terminated string pcStr
 * to the end of the null-terminated string con
 * The terminating null character in destination is overwritten 
 * and a null character is included at the end of the new
 * string formed by the concatenation of both in the destination array. If 'num'
 * characters are copied, no null character is automatically appended
 * to the destination array
 * Returns a pointer to char con, which now contains the concatenated string
 * It is a checked runtime error for `pcStr` to be NULL*/
char *  ms_nconcat(char *strFinal, const char *pcStr, size_t num);

/* Compares the two null-terminated strings pointed to by pcStr1 and pcStr2. 
 * The function returns an integer less than, equal to, or greater than zero
 * if pcStr1 is found to be less than, to match, or be greater 
 * than str2
 * It is a checked runtime error for `pcStr1` and 'pcStr2' to be NULL*/
int ms_compare(const char *pcStr1, const char *pcStr2);



/* Compares the first 'num' characters of two null-terminated strings 
 * pcStr1 and pcStr2. The function returns an integer less than,
 * equal to, or greater than zero if the first 'num' characters of str1 is found
 * to be less than, to match, or be greater than the first 'n'
 * characters of str2
 * It is a checked runtime error for `pcStr1` and 'pcStr2' to be NULL*/
int ms_ncompare(const char *pcStr1, const char *pcStr2, size_t num);


/* Finds the first occurrence of the substring subStr in the string pcStr 
 * The function returns a pointer to the first occurrence of the substring, or 
 * NULL if the substring is not found
 * It is a checked runtime error for `pcStr` and 'subStr' to be NULL*/
char * ms_search(const char *subStr, const char *pcStr);

