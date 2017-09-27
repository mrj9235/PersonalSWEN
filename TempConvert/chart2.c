#include <stdio.h>

int main() {
	float F = 0, C = 0;
	puts("Fahrenheit-Celcius");
	while(F <= 300)
	{
		C = (5*(F-32)/9);
		printf("%6.0f %10.1f \n", F , C);
		F = F +20;
	}
	return;
}
