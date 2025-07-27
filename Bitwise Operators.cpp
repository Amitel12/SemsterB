#include <stdio.h>

int main()
{
	//9 = 0000 1001
	unsigned int x = 9;
	//24 = 0001 1000
	unsigned int y = 24;
	unsigned int r;
	r = x << 2; //shift 2 to the left 9 = (0000 1001) -> 36 = (0010 0100) 32 + 4  = 36 
	printf(" x<<2: %d\n", r);
	r = x>> 2;//shift 2 to the right 9 = (0000 1001) -> 2= 0000 0010
	printf("x>>2 : %d \n", r);
	r = ~x;//flips the digits 9 = 0000 1001 -> -10 = 1111 0110
	printf("~x :%d\n", r);
	r = x & y; // AND (checks if the Bit is the same on both if yes do 1 on the same spot if not do 0 
	//9 = 0000 1001
	//24 =0001 1000
	//r = 0000 1000 
	printf("x&y: %d\n",r);
	r =x | y; // OR (if at least one of them is 1 do 1 on the same spot
	//9 = 0000 1001
	//24 =0001 1000
	//r = 0001 1001 = 1+8+16 = 25
	printf("x|y: %d\n", r);
	r = x ^ y; //XOR if both are diffrent put 1 matching-> 0
	//9 = 0000 1001
	//24 =0001 1000
	//r = 0001 0001 = 1 + 16 = 17
	printf("x^y: %d\n", r);

}