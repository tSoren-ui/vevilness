#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define WRITE "w"
#define READ "r"
#define APPEND "a+"
#define NT '\0'

void writetofile(char *filename);
void readcontents(char *fname);
void appendtofile(char *fname);

int main(int argc, char *argv[]) {

	  printf("      ><(((º>   \n\n");
	    printf("  ______  _                   _         _ _       \n");
	    printf(" | __ ) || | ___   _ __   ___| | __ _  | (_) __ _ \n");
	    printf(" |  _ \\ || |/ _ \\ | '_ \\ / __| |/ _` | | | |/ _` |\n");
	    printf(" | |_) || | (_) || | | \\__ \\ | (_| | | | | (_| |\n");
	    printf(" |____(_)_|\\___/ |_| |_|___/_|\\__,_| |_|_|\\__,_|\n\n");
	    printf("               >>> BLUEGIGEDITOR <<< \n");


	    if (argc < 3) { //checks for 3 args (the name of the program, the file, and the mode)
	        printf("Usage: %s <filename> <r/w>\n", argv[0]);
	        return 1;
	    }

	    if (strcmp(argv[2], "a") == 0){
	    	appendtofile(argv[1]);
	    }
	    if (strcmp(argv[2], "w") == 0){
	    	writetofile(argv[1]);
	    }

	    if (strcmp(argv[2], "r") == 0){
	    readcontents(argv[1]);
	    }

	    printf("Operation completed successfully.\n");

}

void writetofile(char *fname) {
	char *arr, *dummy;
	int m, i;
	int c;
	FILE *fptr;

	m = 200;
	i = 0;
	fptr = fopen(fname, WRITE);
	arr = malloc(sizeof(char) * m);

	if (arr == NULL) {
		perror("error with memory allocation");
		exit(EXIT_FAILURE);
	}

	printf("%s\n", "type ^ to exit");
	while ((c = fgetc(stdin)) != '^') {
		arr[i] = c;
		i++;

		if (i == m) { // i is the number of bytes used, m is how many bytes to malloc
			m *= 2;
			dummy = realloc(arr, sizeof(char) * m); //uses dummy to make sure realloc works, so all of the data in arr isnt erased
			if (dummy == NULL) {
				perror("error with reallocation");
				exit(EXIT_FAILURE);
			}
			arr = dummy; //set arr to dummy after reallocation goes correctly
		}

	}
	arr[i] = NT;
	fprintf(fptr, "%s", arr);
	fclose(fptr);
	free(arr);

}
void readcontents(char *fname){
	FILE *fptr;
	char *buffer;
	buffer = malloc(200);
	fptr = fopen(fname, READ);
	 while (fgets(buffer, 200, fptr)) {
	        printf("%s", buffer);

	 	 }

	free(buffer);
	fclose(fptr);

}

void appendtofile(char *fname){
	char *buffer;
	char *arr, *dummy;
	int m, i;
	int c;
	FILE *fptr;
	m = 200;

	fptr = fopen(fname, APPEND);

	if(fptr == NULL){
		perror("error opening file");
		exit(EXIT_FAILURE);
	}

	buffer = malloc(200);
		 while (fgets(buffer, 200, fptr)) {
		        printf("%s", buffer);
		 	 }

	fseek(fptr, 0, SEEK_END);
	i = 0;
	arr = malloc(sizeof(char) *m);

	if (arr == NULL){
		perror("malloc error");
		exit(EXIT_FAILURE);
	}

	printf("%s\n", "type ^ to exit");
	while ((c = fgetc(stdin)) != '^'){
	arr[i] = c;
	i++;
	if (i == m){
		m *=2;
		dummy = realloc(arr, sizeof(char) * m);
		if (dummy == NULL) {
			perror("reallocation error");
			exit(EXIT_FAILURE);
		}
		arr = dummy;
	}


}
	arr[i] = NT;
		fprintf(fptr, "%s", arr);
		fclose(fptr);
		free(arr);
		free(buffer);
}
