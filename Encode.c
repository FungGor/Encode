#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include<stdbool.h>
#include<string.h>
#include<crtdbg.h>

bool fuck = true;
bool transmit = false;
bool extend = false;
bool state = true;
int length = 4;
int n = 4;
int counter = 0;
int len = 0;

/*
This simulation program encodes binary message into ASCII characters 
*/

void send(char* datagram)
{
	printf("The datagram will be sent through UART:\n");
	for (int bit = 0; bit < 16; bit++)
	{
		printf("%c", datagram[bit]);
	}
}

int intToAscii(int number) 
{
	return '0' + number;
}

char decimal_to_hex(int value)
{
	char result[1];
	switch (value)
	{
	   case 0:
		   result[0] = '0';
		  break;
	   case 1:
		   result[0] = '1';
		   break;
	   case 2:
		   result[0] = '2';
		   break;
	   case 3:
		   result[0] = '3';
		   break;
	   case 4:
		   result[0] = '4';
		   break;
	   case 5:
		   result[0] = '5';
		   break;
	   case 6:
		   result[0] = '6';
		   break;
	   case 7:
		   result[0] = '7';
		   break;
	   case 8:
		   result[0] = '8';
		   break;
	   case 9:
		   result[0] = '9';
		   break;
	   case 10:
		   result[0] = 'A';
		   break;
	   case 11:
		   result[0] = 'B';
		   break;
	   case 12:
		   result[0] = 'C';
		   break;
	   case 13:
		   result[0] = 'D';
		   break;
	   case 14:
		   result[0] = 'E';
		   break;
	   case 15:
		   result[0] = 'F';
		   break;
	}
	return result[0];
}

int decimal_operation(int* block, int length)
{
	int result = 0;
	int exponent = length - 1;
	int power = 1;
	int translation = 0;

	for (int i = 0; i < length; i++)
	{
		for (int m = 0; m < exponent; m++)
		{
			power = power * 2;
		}
		translation = block[i] * power;
		result = result + translation;
		power = 1;
		exponent--;
	}
	return result;
}

char* binary_to_hex(int* message, int size)
{
	int index = 0;
	int* bit = calloc(4, sizeof(int));
	char* hex_data = calloc(4, sizeof(char));
	int decimal = 0;
	char hex[1];
	int position = 0;

	for (int i = 0; i < size; i++)
	{
		bit[index] = message[i];
		if (index == 3)
		{
			for (int y = 0; y < 4; y++)
			{
				printf("%d", bit[y]);
			}
			printf(" ");
			decimal = decimal_operation(bit, 4);
			printf("The decimal number is: %d ", decimal);
			hex[0] = decimal_to_hex(decimal);
			printf(" The hex number is: %c ", hex[0]);
			hex_data[position] = hex[0];
			printf("\n");
			free(bit);
			bit = calloc(4, sizeof(int));
			index = -1;
			position++;
		}
		index++;		
	}

	printf("\n");
	for (int z = 0; z < position; z++)
	{
		printf("%c", hex_data[z]);
	}
	return hex_data; //return the array element
}

void binary_conversion(int *message, int size, int e)
{
	int count = 0;
	int result = 0;
	int power = 1;
	int conversion = 0;
	for (int i = 0; i < size; i++)
	{
		printf("%d ", message[i]);
		//convert to the decimal
		for (int m = 0; m < e; m++)
		{
			power = power * 2;
		}
		conversion = message[i] * power;
		result = conversion + result;
		printf("The result is: %d\n", conversion);
		//reset the parameters
		if (i == 7)
		{
			printf(" The number: %d\n", result);
			printf("%d is ASCII value of %c", result, (char)result);
			e = 7;
			result = 0;
		}
		conversion = 0;
		power = 1;
		e--;		
	}
	printf("The result is: %d\n", result);
	printf("%d is ASCII value of %c", result, (char)result);
	
}

int main(void)
{
	char* datagram = calloc(n, sizeof(char)); //initialize
	char* r = calloc(4, sizeof(char)); //expressed in form of 4 bit
	while(fuck)
	{
		float temperature;
		float voltage;
		int temp;
		float point;
		int data[10];
		int remainder;
		int size = 0;
		int k;
		int precision;
		int result[10];
		int Block[16]; //mesage
		int count = 0;
		int index = 0;
		int byte = 0;
		int i = 0;
		int d = 0;
		int y = 0;
		
		if (state == true)
		{
			printf("**********Data Processing**********\n");
			printf("Please enter the temperature: ");
			scanf("%f", &temperature);
			printf("The temperature is: %.2f\n", temperature);
			temp = temperature;
			point = temperature - temp;
			printf("Integer is: %d\n", temp);
			printf("Point is: %.2f\n", point);
			//convert to binary number
			for (int i = 0; temp > 0; i++)
			{
				remainder = temp % 2;
				temp = temp / 2;
				data[i] = remainder;
				size++;
			}
			printf("\nEnter the conversion precision: ");
			scanf("%d", &k);
			//convert the fractional part to binary
			for (int bit = k - 1; bit >= 0; bit--)
			{
				point = point * 2;
				precision = point;
				result[count] = precision;
				point = point - precision;
				count++;
			}
		}
		

		if (size < 7)
		{
			int number = 0;
			y = size - 1;
			int q = 7 - size; //number of 0's that have to be added! 
			printf("Only %d bits! ", size);
			while (d < q)
			{
				y = y + 1;
				data[y] = 0;
				d++;
			}
			//append the bits
			printf("After appending redundunt bits...\n");
			for (int length = y; length >= 0; length--)
			{
				printf("%d", data[length]);
				Block[byte] = data[length];
				byte++;
			}
			printf(".");
			Block[7] = 0;
			byte = byte + 1;
			for (int l = 0; l < count; l++)
			{
				printf("%d", result[l]);
				Block[byte] = result[l];
				byte = byte + 1;
			}
			printf("\n");
			int exponent = byte - 1; //exponent = 15

			//u = 16;
			for (int u = 0; u < byte; u++)
			{
				printf("%d", Block[u]);
			}

			printf("\n");
			int power = 1;
			int decimal = 0;
			int num;
			int solution = 0;
			int conversion = 0;
			for (num = 0; num < byte; num++)
			{
				for (int m = 0; m < exponent; m++)
				{
					power = power * 2;
				}
				solution = Block[num] * power;
				conversion = conversion + solution;
				printf("The result is: %d\n", solution);
				solution = 0;
				power = 1;
				exponent--;
			}
			int p = 7;

			printf("\n");
			printf("The final result is: %d", conversion);
			printf("\n");
			binary_conversion(Block, byte, p);
			printf("\n");
			strncpy(r,binary_to_hex(Block,byte),4); //output a block (4-bit long)
			printf("\n");
			printf("The hex is:\n");

			for (int y = 0; y < 4; y++)
			{
				printf("%c", r[y]); 
			}

			printf("\n");

			if (extend == false)
			{
				n = 4;
				datagram = calloc(size, sizeof(char)); //initialize
				for (int counter = 0; counter < length; counter++)
				{
					printf("%c", *(r + counter));
					*(datagram + counter) = *(r + counter); //save it !
				}
			}

			else if (extend == true)
			{
				n = n + 4;
				int position = n - 4; //the new initial array position
				datagram = (char*)realloc(datagram, n); // assign the new length
				for (int counter = 0; counter < length; counter++)
				{
					datagram[position] = r[counter];
					position++;
				}
				printf("\n");
				for (int num = 0; num < position; num++)
				{
					printf("%c", datagram[num]);
				}
				if (n > 16)
				{
					transmit = true;
					n = 4; //The array size of the datagram is reset
					send(datagram);
				}
			}
		}

		else
		{
			for (int length = size - 1; length >= 0; length--)
			{
				printf("%d", data[length]);
				Block[byte] = data[length];
				byte++;
			}
			printf(".");
			Block[7] = 0;
			byte = byte + 1;
			for (int l = 0; l < count; l++)
			{
				printf("%d", result[l]);
				Block[byte] = result[l];
				byte = byte + 1;
			}
			printf("\n");
			for (int u = 0; u < byte; u++)
			{
				printf("%d", Block[u]);
			}
		}

		printf("\n");
		char command;
		printf("Continue? Y/n ");
		scanf(" %c", &command);
		if (command == 'n' || command == 'N')
		{
			fuck = false;
			extend = false;
			state = false;
			free(r); //prevent memory leak
			free(datagram); //prevent memory leak
		}
		else if(command == 'y' || command == 'Y') {
			fuck = true;
			state = true;
			if (transmit == true)
			{
				extend = false;
				transmit = false;
				free(datagram);
			}
			else if (transmit == false)
			{
				extend = true;
			}
			_CrtDumpMemoryLeaks();
			free(r); //prevent memory leak
		}
	}
	printf("\nGood Bye!");	
}