#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define POCET_HODNOT 10

int teploty() {
	FILE *subor;
	double maximum = INT_MIN;
	double hodnota = 0;
	int i;

	subor = fopen("teploty.txt", "r");
	if (subor == NULL){
		perror("Subor neexistuje");
		return -1;
	}
	for( i = 0; i<POCET_HODNOT; i++){
		fscanf(subor, "%lf", &hodnota);
		if (hodnota > maximum){
			maximum = hodnota;
		}
	}

	printf("Maximalna teplota tento tyzden je %f\n", maximum);

	fclose(subor);
	return 0;
}

int main(void)
{
	return teploty();
}
