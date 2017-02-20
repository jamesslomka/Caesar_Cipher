nclude <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

	//char *fileName = argv[1];
	//Using tempFile to fgetc number of characters
	FILE *fileTemp;
	fileTemp = fopen(argv[1],"r");
	char *x;
	int shift = strtol(argv[2],&x,10);
	
	//Loop to count characters in textfile
	int characterCount=0;
	int c=0;
	while(1)
	{
		c = fgetc(fileTemp);
		if (c == EOF)
		{
			break;
			
		}
		characterCount++;
	}
	
	//Opening file again to fscan characters into array
	FILE *file;
	file = fopen(argv[1],"r");

	//Adding each character from text file into array
	int count=0;
	char letters[characterCount];
	
	for (count = 0; count < characterCount; count++)
	{	
		fscanf(file,"%1c",&letters[count]);
		//printf("%c",letters[count]);	
	}

	//Shifting characters
	int counter=0;
	char output[characterCount];
	while(letters[counter] != '\0')
	{
		if (letters[counter] >= 'A' && letters[counter] <='Z')
		{
                        output[counter] = (letters[counter] - 'A' + shift) %26 +'A';
                }
                else if (letters[counter] >= 'a' && letters[counter] <='z')
                {
                        output[counter] = (letters[counter] - 'a' + shift) %26 +'a';
                }
		counter++;
        }
        FILE *writeFile;
        writeFile = fopen(argv[1],"w");
        fwrite(output, sizeof(char),sizeof(output),writeFile);
}
