#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

float getMin(float a1, float a2)
{
	if(a1<a2)
		return a1;
	return a2;
}

float getMax(float a1, float a2)
{
        if(a1>a2)
                return a1;
        return a2;
}


int main(void){
	float avg = 0;
	int count = 0;
	float min = INT_MAX;
	float max = INT_MIN;
	float temp = 0;
	char buffer[10];
	while(scanf("%s", buffer)!=0 && strcmp(buffer, "x") && (temp = atof(buffer))!=0) {
		avg = avg + temp;
		count++;
		min = getMin(min, temp);
		max = getMax(max, temp);
	}
	avg /= count;
	printf("Avg is: %f Max is %f Min is: %f\n", avg, max, min);
	return EXIT_SUCCESS;
}
