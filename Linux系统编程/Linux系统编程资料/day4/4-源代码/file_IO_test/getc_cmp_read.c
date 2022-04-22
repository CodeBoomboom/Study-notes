#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE *fp, *fp_out;
	int n;

	fp = fopen("dict.txt", "r");
	if(fp == NULL){
		perror("fopen error");
		exit(1);
	}

	fp_out = fopen("dict.cp", "w");
	if(fp_out == NULL){
		perror("fopen error");
		exit(1);
	}

	while((n = fgetc(fp)) != EOF){
		fputc(n, fp_out);
	}

	fclose(fp);
	fclose(fp_out);

	return 0;
}
