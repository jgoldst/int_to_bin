/* 
Positive Integer to Binary Value.
Joseph Goldstein
September 8, 2014
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void menu();
void printAnswer(char printBinary[]);
void intToBinary(int n);

int main() {
	menu();
	return 0;
}

void menu() {
    int n = 0;
    printf("Please enter positive integer you wish to convert to binary (-1 to quit): ");
    scanf("%i", &n);

    char message[128] = "";
    
    if (n == -1) {
        strncat(message, "q", 128);
        printAnswer(message);
    }
    /* reject all other negative inputs */
	else if (n < 0) {
		strncat(message, "Cannot accept negative input.", 128);
		printAnswer(message);
	}
    /* 0 answer, here for clean formatting output */
	else if (n == 0) {
		strncat(message, "00", 128);
		printAnswer(message);
	}
    /* 1 answer, here for clean formatting output */
	else if (n == 1) {
		strncat(message, "01", 128);
		printAnswer(message);
	}
    /* all other positive input answers */
    else {
        intToBinary(n);
    }
}

void printAnswer(char printBinary[]) {
    if (strcmp("q", printBinary) == 0) {
       //let program end
    }
    else {
        printf("%s\n", printBinary);
        menu();
    }
}

void intToBinary(int n) {
    int continueOn = 1;
	int binaryCounter = 0, numberOfBits = 0;
	int twoToTheBinaryCounter = pow(2, binaryCounter);
	char binaryString[1024] = "";

	while (twoToTheBinaryCounter <= n) {
		if (twoToTheBinaryCounter == n) {
			strncat(binaryString, "1", 2);
			for (int i = 0; i < numberOfBits; i++) {
				strncat(binaryString, "0", 2);
			}
            continueOn = 0;
			printAnswer(binaryString);
		}

		binaryCounter++;
		twoToTheBinaryCounter = pow(2, binaryCounter);
		numberOfBits++;
	}
    
    if (continueOn == 1) {
        int gettingToZero = n;
        numberOfBits = numberOfBits - 1;
        
        while (numberOfBits >= 0) {
            if (gettingToZero == 0) {
                strncat(binaryString, "0", 2);
            }
            else if (gettingToZero >= pow(2, numberOfBits)) {
                gettingToZero = (gettingToZero - (pow(2, numberOfBits)));
                strncat(binaryString, "1", 2);
            }
            else {
                strncat(binaryString, "0", 2);
            }
            
            numberOfBits = numberOfBits - 1;
        }
        
        printAnswer(binaryString);
    }
}

