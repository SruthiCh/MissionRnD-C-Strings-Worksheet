/*
OVERVIEW: Given a string, remove all spaces in it.
E.g.: Input: "abd scd". Output: "abdscd"

INPUTS: A string.

OUTPUT: Return string after removing spaces.

ERROR CASES: Return '\0' for invalid inputs.

NOTES: Don't create new string.
*/

char* removeSpaces(char *str) {
	int i = 0, j = 0;
	if (str == '\0' || str == "") return '\0';
	else
	{
		while (str[i] != '\0')
		{
			if (str[i] != ' ')
			{
				str[j] = str[i];
				i++; j++;
			}
			else
			{
				for (; str[i] == ' '; i++);
				str[j] = str[i];
				i++; j++;
			}
		}
		str[j] = '\0';
		return str;
	}
}