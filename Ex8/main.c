#include <stdio.h>
#include <stdarg.h>
#include <math.h>


double sistema(int ss, int drob, ...)
{
	va_list args;
	va_start(args, drob);

	double x = 0.0;
	int  count = 0;
	double y = 0.0;



	for (int i = drob; i > 0; i--)
	{
		x = va_arg(args, double);
		y = x;

		while (x != 0.0 && count != 10)
		{
			x = x * ss;
			x = x - (int)x;
			count++;
			//printf("%f\n", x);


		};
		if (count != 10)
		{
			printf("%f konechnoe v s.s %d\t\n", y, ss);
			
		}
		else
		{
			printf("%f ne konechnoe v s.s %d\t\n", y, ss);
			
		};
		count = 0;

	}

	va_end(args);

}


int main()
{
	int base = 3;
	int drob = 3;
	double a1 = 0.2;
	double a2 = 0.5;
	double a3 = 0.12;

	printf("%f", sistema(base, drob, a1, a2, a3));


	return 0;
}
