/*
 * In this lab, you will be using dynamic memory and gain more
 * practice using pointers, including constant pointers
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <ctype.h>
#include <math.h>

#define INITSIZE 128

// Function Prototypes
char *getLine( void );
void getList( void );

int main() {
	char *str1,*str2;
	str1 = getLine();
	str2 = getLine();	// getLine() does not work after multiple uses :(
	
	printf("String1 is: %s\n",str1);
	printf("String2 is: %s\n",str2);
	
	/*int listSize = 4, i;
	
	char **arList;
	arList = malloc(listSize*sizeof(char*));
	
	
	for(i=1;i<listSize-1;i++){
		if(i==listSize){
			arList[i] = NULL;
		}
		else{
		arList[i] = getLine();
		printf("%s\n",arList[i]);
		}
	}
	
	
	for(i=0;i<listSize;i++){
		printf("%p\n",arList[i]);
	}*/
	
	
  return 0;
}

// Function Definitions
char *getLine( void ){
	char *z;
  int i, count = 0;

  // allocate memory dynamically
  z = malloc(INITSIZE*sizeof(char));

  if(z != NULL){
  	// Write a sentence to a dynamic array
  	printf("Enter a string: ");
  	scanf("%127[^\n]",z);
  	
  	
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
	//printf("%s\n",z);
	
	return z;
}
