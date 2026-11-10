#include <locale.h>
#include <stdio.h>
#include <math.h>

#define ERR_NOT_DEFINE 0xAAAA
#define DIV_BY_ZERO 0xBBBB

double f(double x, double y, double z);

int main()
{
	setlocale(LC_CTYPE, ".UTF-8");

	double x, y, z, step, m, n;
	double res = f(x, y, z);

	printf("Введите значение y\n");
	scanf("%lf", &y);

	printf("Введите значение z\n");
	scanf("%lf", &z);

	printf("Введите значение step\n");
	scanf("%lf", &step);

	printf("Введите значение m\n");
	scanf("%lf", &m);

	printf("Введите значение n, меньшее чем m\n");
	scanf("%lf", &n);

	for (double x = n; x <= m; x += step)
	{
		double res = f(x, y, z);

		if (res == DIV_BY_ZERO)
		{
			printf("ERROR\n");
		}
		if (res == ERR_NOT_DEFINE)
		{
			printf("Function is not defined in this point (%f %f %f)\n", x, y, z);
		}
		else
		{
			printf(" %f | %f \n", x, res);
		}
	}
	return 0;
}

double f(double x, double y, double z)
{
	if (-1 <= z <= 1 && y >= 5 && x < 2)
	{
		double ch = log(abs(z - x)) + cos(y);
		double zn = 2 * z;
		if (z == x || z == 0)
		{
			return DIV_BY_ZERO;
		}
		return ch / zn;
	}
	else if (z > 1 && 0 <= y < 5 && 2 <= x <= 3)
	{
		double a = cos(z) + sin(x);
		return a;
	}
	else if (z <= -1 && y < 0 && x > 3)
	{
		double b = exp(2 * x + z) - 4;
		return b;
	}
	else
	{
		return ERR_NOT_DEFINE;
	}
}