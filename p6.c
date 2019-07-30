#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <math.h>

void printhex(char * label, int input)
{
    char reverse[8];
	int temp;
	char holder;
	int remain = input;
	int i;
	//calculate each digit of the hex address
	for (i = 0; i < 8; i++)
	{
		if (remain > 0)
		{
			temp = remain % 16;

			if (temp <= 9)
			{
				reverse[i] = temp + '0';
			}
			else if (temp == 10)
			{
				reverse[i] = 'A';
			}
			else if (temp == 11)
			{
				reverse[i] = 'B';
			}
			else if (temp == 12)
			{
				reverse[i] = 'c';
			}
			else if (temp == 13)
			{
				reverse[i] = 'D';
			}
			else if (temp == 14)
			{
				reverse[i] = 'E';
			}
			else if (temp == 15)
			{
				reverse[i] = 'F';
			}
		remain = (remain / 16) - (temp / 16);
		}
		else if (remain == 0)
		{
			reverse[i] = '0';
		}
	}

	//reverse order of hex address string
	for (i = 0; i < 4; i++)
	{
		holder = reverse[7 - i];
		reverse[7 - i] = reverse[i];
		reverse[i] = holder;
	}

	//print values
	printf("%s: 0x", label);
	for (i = 0; i < 8; i++)
	{
		printf("%c", reverse[i]);
	}
	printf("\n");
}

int calcindex(int total, long input)
{
    int index = input / total;
    return index;
}

int calcoffset(int total, long input)
{
    int offset = input % total;
    return offset;
}

int main(int argc, char * argv[])
{
    char address[8];
    char tempaddress[8];
    strcpy(tempaddress, argv[1]);
    int size = strlen(argv[1]);
    int i;
    int count = 0;
    for(i = 0; i < 8; i++)
    {
        if(i <= 7-size)
        {
            address[i] = '0';
        }
        else if(i > 7-size)
        {
            address[i] = tempaddress[count];
            count++;
        }
    }
    int total = 4096;
    long input = strtol(argv[1], NULL, 16);
    int index = calcindex(total, input);
    int offset = calcoffset(total, input);
    printf("Address: 0x");
    for(i = 0; i < 8; i++)
    {
        printf("%c",address[i]);
    }
    printf("\n");
    printhex("Index", index);
    printhex("Offset", offset);
    return 0;
}








