/*
 * In this lab, you will be using dynamic memory and gain more
 * practice using pointers, including constant pointers
 * 
 * This program utilizes dynamic memory to create an array of 
 * "Lines" which are used to store sentences of any length.
 *
 * The array is terminated when the user enters a "." as a line.
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <ctype.h>
#include <math.h>

#define INITSIZE 128

// Function Prototypes
char *getLine( void );
char **getList( void );

int main() {
/*
	// Test getLine()
	char *str1,*str2;
	
	str1 = getLine();
	printf("String1 is: %s\n",str1);
	
	str2 = getLine();
	printf("String2 is: %s\n",str2);
	
	free(str1);
	free(str2);
*/
	char **strList;
	
	strList = getList();
	
	// Print the List
	while(*strList != NULL){
		printf("%s\n",*strList);
		strList++;
	}
	
	//free(strList);	// Causes "double free" error
  return 0;
}

// Function Definitions
char **getList( void ){
/* Create a dynamic array of dynamic strings
 */
	int listSize = 4, i=0;
	char **arList;	//A dynamic list of arrays is a pointer to a pointer
	
	arList = malloc(listSize*sizeof(char*));
	if(arList != NULL){
		do{
			//resize the array when close to becoming "full"
			if(i==listSize-2){
				listSize *= 2;
				arList = realloc(arList,listSize*sizeof(char*));
				arList[i] = getLine();
			}
			else{
				arList[i] = getLine();	
			}
			i++;
		} while(*arList[i-1] != '.' && i<listSize);
		
		// Update the list size
		listSize = i;	
		arList = realloc(arList,listSize*sizeof(char*));
		arList[listSize-1] = NULL;	//Indicate where the end of the array is
		listSize--;
		
		/*Print the Array List
		printf("Here is the List:\n");
		for(i=0;i<listSize;i++){
			printf("%s\n",arList[i]);
		}*/
	}
	else{
		fprintf(stderr, "Error - unable to allocate required memory\n");
	}
	return arList;
};


char *getLine( void ){
/* This function must use a temporary dynamic array to store this full line as a single string, and must actually return the string in a perfectly-allocated dynamic string. */
	char *z;
  int i, count = 0;

  // allocate memory dynamically
  z = malloc(INITSIZE*sizeof(char));

  if(z != NULL){
  	// Write a sentence to a dynamic array
  	printf("Enter a string: ");
  	//scanf("%127[^\n]",z);	// Doesn't work when getLine() is called multiple times.
  	scanf("%[^\n]%*c",z);
  	
  	for(i=0; i < INITSIZE; i++){
  		if(z[i] != '\0')
  			count++;
  	}
  	count++;	//to ensure \0 is included in the string when resizing
  	
  	// Re-size z such that it is only the necessary size
  	z = realloc(z,count*sizeof(char));	
  }
  else{
  	fprintf(stderr, "Error - unable to allocate required memory\n");
  }
	
	return z;
};
