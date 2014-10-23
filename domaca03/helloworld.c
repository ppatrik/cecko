#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/* DOMACA ULOHA */
/* mate subor rodne cisla, zistite ci zadane rodne cislo patri muzovi alebo zene (aby bola co najmensia pamatova narocnost) */

int main(void)
{
	FILE *subor;
	char c;
	int result = 0; /* 0 -> unknown, 1 -> muž, 2 -> žen*/
	int pozicia = 0;

	subor = fopen("rodnecisla", "r");

	while( ( c = getc(subor) ) != EOF )
	{
		if(c=='\n') {
			if(result == 1) {
				printf(" patri muzovi\n");
			} else {
				printf(" patri zene\n");
			}
			result = 0;
			pozicia = 0;
			continue;
		}
		pozicia++;
		if(pozicia==3) {
			if(c=='5' || c=='6') {
				result = 2;
			} else {
				result = 1;
			}
		}
		printf("%c", c);
	}
	fclose(subor);
	return EXIT_SUCCESS;
}
