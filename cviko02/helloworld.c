#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/* DOMACA ULOHA */
/* zistite ci tri usecky mozu byt stranami trojuholnika */


int faktorial(int cislo);
void vypisPole(int pole[], int dlzka);
int spocitajPole(int pole[], int dlzka);
double vypocitajPriemer(int pole[], int dlzka);
double dlzkaLomenejCiary(int xAxis[], int yAxis[], int dlzka);

int main(void)
{

	/* faktorial */
	/*int a;
	printf("Zadajte číslo: ");
	scanf("%d", &a);

	printf("\n%d! = %d\n", a, faktorial(a));*/

	/* vypis znamok a ich priemer */
	/*int znamky[] = {1,2,3,4,5,1,2,3,4,1};
	double priemer = vypocitajPriemer(znamky, 10);

	vypisPole(znamky, 10);
	printf("Priemer je %.2f\n", priemer);*/

	/* suradnice */
	int xAxis[] = {2, 4.5, 5, 5.7, 7};
	int yAxis[] = {3, 5.6, 6.5, 7, 7.7};

	double dlzkaCiary = dlzkaLomenejCiary(xAxis, yAxis, 5);

	printf("Dlzka lomenej ciary: %.2f pixlov\n", dlzkaCiary);

	return EXIT_SUCCESS;
}

int faktorial(int cislo)
{
	if(cislo == 0) {
		return 1;
	}
        if(cislo <= 2) {
                return cislo;
        }
        return cislo * faktorial(cislo-1);
}

void vypisPole(int pole[], int dlzka)
{
	int i;
	for(i = 0; i < dlzka; i++) {
		printf("%d\n", pole[i]);
	}
}

int spocitajPole(int pole[], int dlzka)
{
	int spolu = 0;
	int i;
	for(i = 0; i < dlzka; i++) {
                spolu += pole[i];
        }
	return spolu;
}

double vypocitajPriemer(int pole[], int dlzka)
{
	double sumar = (double) spocitajPole(pole, dlzka);
	return sumar / dlzka;
}

double dlzkaCiary(int x1, int y1, int x2, int y2)
{
	return sqrt(pow(x1-x2,2)+pow(y1-y2,2));
}

double dlzkaLomenejCiary(int xAxis[], int yAxis[], int dlzka)
{
	int i;
	double dlzkaCelejCiary = 0;
	for(i = 0; i < dlzka - 1; i++) {
		dlzkaCelejCiary += dlzkaCiary(xAxis[i], yAxis[i], xAxis[i + 1], yAxis[i + 1]);
	}
	return dlzkaCelejCiary;
}
