#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void helloWorld()
{
	printf("Hello world\n");
	/* .... že vraj dve lomky nefunguju - POZN - používame starodavnu normu, preto nič logicke nejde */
}

void domaca()
{
	int i;
	for(i = 0; i<10; i++) {
                printf("IDE za mna urobi domace ulohy!\n");
        }
}


void setColor(int textColor)
{
        printf("\x1b[1;%d;40m", textColor);
}

void resetColor()
{
        printf("\x1b[0m");
}


void printToFile()
{
	/*int i;
	for(i = 0; i<8; i++) {
		setColor(30+i);
		printf("%d", i);
	}
	resetColor();
	printf("\n");*/
}

void malaNasobilka(int nasobit)
{
	int i;
	for(i=0;i<=10;i++) {
		if(i<5) {
			setColor(31);
		} else {
			setColor(32);
		}
		printf("%02d x %02d = %03d\n", i, nasobit, i*nasobit);
	}
	resetColor();
}

void matrix()
{
	int i;
	for(i=0;i<100000000;i++) {
		char randomletter = 'A' + (random() % 26);
		if(random()%10>5) {
			setColor(32);
		} else {
			setColor(30);
		}
		printf("%c", randomletter);
	}
	resetColor();
/*	printf("\r");*/
}

double vzdialenostMedziBodmi(int x1, int y1, int x2, int y2) 
{
	int a = abs(x1-x2);
	int b = abs(y1-y2);
	return sqrt( pow(a, 2) + pow(b, 2) );
}

int i;
int main(void)
{
	resetColor();
	/*helloWorld();
	domace();
	setColor();*/
	printToFile();

	for(i=0; i <= 10; i++) {
		malaNasobilka(i);
	}

	printf("%.2f\n", vzdialenostMedziBodmi(0,0,10,10));

	for(i=0; i<=1000; i++) {
		matrix();
	}

	printf("\n");
	return EXIT_SUCCESS;
}
