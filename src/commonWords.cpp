/*
OVERVIEW: Given two strings, find the words that are common to both the strings.
E.g.: Input: "one two three", "two three five".  Output: "two", "three".

INPUTS: Two strings.

OUTPUT: common words in two given strings, return 2D array of strings.

ERROR CASES: Return NULL for invalid inputs.

NOTES: If there are no common words return NULL.
*/

#include <stdio.h>
#include <malloc.h>

#define SIZE 31
int compare(char* word, char*str2)
{
	int flag = 0, i=0, j=0;
	while (str2[i] != '\0')
	{

		for (; word[j] != str2[i]; i++);
		while (word[j] != '\0')
		{
			if (word[j] != str2[i])
			{
				flag = 1;
				break;
			}
			i++; j++;
		}
		i++;
		j = 0;
	}
	return flag;
}

char ** commonWords(char *str1, char *str2)
{
	int i,j,k=0;
	char word[31];
	char ** result;
	if (str1 == NULL || str2 == NULL)
		return NULL;
	for (i = 0; str1[i] == ' '&&str1[i] != '\0';i++);
	for (j = 0; str2[j] == ' '&&str2[j] != '\0';j++);
	if (str1[i] == '\0' || str2[i] == '\0') return NULL;

	result = (char**)malloc(sizeof(char*) * SIZE);
	for (i = 0; i < SIZE; i++)
		result[i] = (char *)malloc(sizeof(char)*SIZE);
	i = 0,j=0;
	while (str1[i]!='\0')
	{
		for (; str1[i] == ' '; i++);
		for (k=0; str1[i] != ' '&&str1[i]!='\0'; i++,k++)
			word[k] = str1[i];
		word[k] = '\0';
		if (compare(word, str2) == 0)
		{
			for (k = 0; word[k] != '\0'; k++)
			{
				result[j][k] = word[k];
			}
			result[j][k] = '\0';
			j++;
		}
	}
	if (j == 0)
		return NULL;
	else
	return result;
}
	
