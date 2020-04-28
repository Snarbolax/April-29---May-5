#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

// exercise 7-1
void exercise1(const char* argv[]) {
	char c = fgetc(stdout);
	int i = 0;
	do {
		if (isupper(c)) { fputc(tolower(c), stdout); }
		else if (islower(c)) { fputc(toupper(c), stdout); }
		else { fputc(c, stdout); }
		++i;
	} while (c != EOF || i < strlen(argv[0]));
}

// exercise 7-6
void exercise6(const char* argv[]) {
	FILE* in1 = fopen(argv[1], "r");
	FILE* in2 = fopen(argv[2], "r");
	char c = fgetc(in1);
	char v = fgetc(in2);
	char arr1[BUFSIZ];
	char arr2[BUFSIZ];
	int count = 0;

	do {
		arr1[count] = c;
		arr2[count] = v;
		if (c == '\n' || v == '\n') {
			if (strcmp(arr1, arr2) != 0) { printf("Differ found at Line %d at:\n\t%s: %s\n\t%s: %s\n", count, argv[1], arr1, argv[2], arr2); }
			else { memset(arr1, NULL, sizeof(arr1)); memset(arr2, NULL, sizeof(arr2)); }
		}
		++count;
		c = fgetc(in1);
		v = fgetc(in2);
	} while (c != EOF || v != EOF);
}

// exercise 7-8
void exercise8(int argc, const char* argv[]) {
	if (argc == 1) { fprintf(stderr, "argc must be >1\n"); }
	char title[BUFSIZ];
	int pc = 0;
	FILE* in;
	char c;
	for (size_t i = 1; i < argc; ++i) {
		in = fopen(argv[i], "r");
		c = fgetc(in);
		printf("%s\n------------------------------\n", argv[i]);
		while (c != EOF) { printf("%c", c); c = fgetc(in); }
		printf("\t\t\t\t\t\tPAGE %d", pc);
		++pc;
		fclose(in);
	}
}

int main(int argc, const char* argv[]) {
	exercise1(argv);
	//exercise6(argv);
	//exercise8(argc, argv);

	return 0;
}