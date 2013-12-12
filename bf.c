#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
	if (argc < 2) {
		printf("usage: ./bf filename\n");
		return 0;
	}

	// read file
	char *program = (char *) calloc(10, sizeof(char));
	int fi = 0;
	int size = 10;

	FILE *fp;
	fp = fopen(argv[1],"r");

	if (fp == NULL) {
		printf("Cannot open file\n");
		exit(-1);
	}

	char ch;

	while ((ch = fgetc(fp)) != EOF) {
		if (ch == '>' || ch == '<' || ch == '+' || ch == '-' || ch == '.' || ch == ',' || ch == '[' || ch == ']') {
			program[fi++] = ch;
			if (fi > size) {
				size *= 2;
				program = (char *) realloc(program, size * sizeof(char));
			}
		}
	}

	fclose(fp);

	program = (char *) realloc(program, fi * sizeof(char));
	size = fi;

	char *data = (char *) calloc(30000, sizeof(char));
	char *p = data;
	int ip = 0;

	while (ip < size) {
		// printf("%3d: %c\n", ip, program[ip]);
		switch (program[ip]) {
			case '>':
				++p;
				break;
			case '<':
				--p;
				break;
			case '+':
				++*p;
				break;
			case '-':
				--*p;
				break;
			case '.':
				putchar(*p);
				break;
			case ',':
				*p = getchar();
				break;
			case '[':
				if (*p == 0) {
					int layer = 1;
					while (layer) {
						char c = program[++ip];
						if (c == '[')
							layer++;
						else if (c == ']')
							layer--;
					}
				}
				break;
			case ']':
				if (*p) {
					int layer = 1;
					while (layer) {
						char c = program[--ip];
						if (c == ']')
							layer++;
						else if (c == '[')
							layer--;
					}
				}
				break;
			default:
				break;
		}
		ip++;
	}

	free(program);
	free(data);

	return 0;
}