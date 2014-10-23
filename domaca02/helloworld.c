#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/* DOMACA ULOHA */
/* zistite ci tri usecky mozu byt stranami trojuholnika */

int overNerovnost(int a, int b, int c);

int main(void)
{
	int a;
	int b;
	int c;
	int vysledok;
	printf("Zadajte strany trojuholnika oddelene medzerou (A B C): ");
	scanf("%d %d %d", &a, &b, &c);

	vysledok = overNerovnost(a, b, c);

	if(overNerovnost(a, b, c)) {
		printf("Tento trojholnik vies urobit -_-");
	} else {
		printf("Tento trojuholnik sa ti nepodarí :D");
	}
	printf("\n");


	return EXIT_SUCCESS;
}

int overNerovnost(int a, int b, int c)
{
	return (a + b > c) && (b + c > a) && (c + a > b);
}
