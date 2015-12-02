/*
OVERVIEW: Given a float number ,Convert it into a string 

INPUTS: A Float,Final string ,How many digits after decimal has to be displayed .
Its zero for integers.


OUTPUT: No need to output anything ,Modify the str in function parameter such that it
now holds the string format of the float number specified

Example : number_to_str(345,str,0);
Should copy "345\0" in the str;
number_to_str(345.342,str,2);
Should copy "345.34" in the str;

NOTES: Don't create new string.

*/

#include <stdio.h>


void reverse(char*str, int i, int j)
{
	char temp;
	for (; i < j; i++, j--)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
	}
}

int toString(int integer, char* str, int afterdecimal)
{
	int index = 0, flag = 0;
	if (integer < 0)
	{
		str[index++] = '-';
		integer *= -1;
		flag = 1;
	}
	while (integer != 0)
	{
		str[index++] = (integer % 10) + '0';
		integer /= 10;
	}
	reverse(str, flag, index - 1);
	str[index] = '\0';
	return index;
}
int power(int num1, int num2)
{
	int i;
	for (i = 0; i < num2 - 1; i++)
		num1 = num1*num1;
	return num1;
}
void number_to_str(float number, char *str, int afterdecimal){
	int integer, index;
	float decimal;
	integer = (int)number;
	decimal = number - integer;
	if (decimal < 0) decimal *= -1;
	index = toString(integer, str, 0);
	if (afterdecimal > 0) str[index] = '.';
	integer = decimal*power(10, afterdecimal);
	toString(integer, str + index + 1, afterdecimal);
}