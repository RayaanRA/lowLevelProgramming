#include <stdio.h>
#include <math.h>
#include <string.h>



void decimalToBinary(int num);
void binaryToDecimal(int num);
void decimalToHex(int num);
void hexToDecimal(char num[]);

int main() {

	hexToDecimal("AA3");
	printf("\n");
	return 0;
}

void decimalToBinary(int num) {
	if (num != 0) {
		decimalToBinary(num / 2);
		printf("%d", num % 2);
	}
}

void binaryToDecimal(int num) {
	int decimal = 0;
	int power = 1;
	while (num != 0) {
		decimal += (num % 10) * power;
		power *= 2;
		num /= 10;
	}
	printf("%d", decimal);
}

void decimalToHex(int num) {
	char hexString[17];
	int i = 0;
	char digits[] = "0123456789ABCDEF";
	while (num != 0) {
		hexString[i] = digits[num % 16];
		num /= 16;
		i++;
	}
	for (int j = i - 1; j > -1; j--) {
		printf("%c", hexString[j]);
	}
}

void hexToDecimal(char num[]) {
	int length = strlen(num);
	int decimal = 0;
	for (int i = 0; i < length; i++) {
		int number;
		if (num[i] >= '0' && num[i] <= '9') {
			number = num[i] - '0';
		} else {
			number = num[i] - 'A' + 10;
		}

		decimal *= 16;
		decimal += number;
	}
	printf("%d", decimal);

}
