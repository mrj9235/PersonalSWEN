#include <stdio.h>

int main()
{
	int F = 0, C = 0;
	puts("Fahrenheit-Celcius");
	while(F <= 300)
	{
		C = (5*(F-32)/9);
		printf("%i %i \n", F , C);
		F = F +20;
	}
	return;
}
