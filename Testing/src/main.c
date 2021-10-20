#include <portable-simd/portable-simd.h>

#include <stdio.h>

int main()
{
	simd4f x = Create4f(1.2f, 4.9f, 9.112f, 7.5f);
	simd4f y = Round4f(x);

	printf("Hello, world!\n");

	float a;
	float b;
	float c;
	float d;

	Unpack4f(y, &a, &b, &c, &d);

	printf("%f, %f, %f, %f", a, b, c, d);

	return 0;
}