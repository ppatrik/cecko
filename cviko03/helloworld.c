#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

void vypisPohlavie(char rodneCislo[])
{
	if(rodneCislo[2] == '5' || rodneCislo[2] == '6') {
		printf("RodneCislo %10s patri zene.\n", rodneCislo);
	} else {
		printf("RodneCislo %10s patri muzovi.\n", rodneCislo);
	}
}

void nacitajRodneCisla()
{
	FILE *subor;
	char rodneCislo[11];

	subor = fopen("rc", "r");
	if(subor==NULL) {
		perror("Subor nebol najdeny");
		return;
	}

	while(fscanf(subor, "%s", rodneCislo) != EOF) {
		vypisPohlavie(rodneCislo);
	}
	fclose(subor);
}

void pracaSoSuborom()
{
	FILE *subor;
	char naZapis[25];
	int i;
	char c;

	subor = fopen("jozko", "w");
	strcpy(naZapis, "riadok");
	for(i = 0; i < 10; i++) {
		fprintf(subor, "%s cislo %d.\n", naZapis, i);
	}
	fclose(subor);

	subor = fopen("jozko", "rt");
	/*while(fscanf(subor, "%s", buffer)!=EOF) {
		printf("%s\n", buffer);
	}*/
	while((c = getc(subor)) != EOF) {
		printf("%c", c);
	}
	fclose(subor);

}

int main(void)
{
	nacitajRodneCisla();
/*	pracaSoSuborom();*/
	return EXIT_SUCCESS;
}
