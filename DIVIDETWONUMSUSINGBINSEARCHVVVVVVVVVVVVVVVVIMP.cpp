#include <stdio.h>
#include <limits.h>

// define infinity as ULONG_MAX
#define INF ULONG_MAX

double abs(double i) {
   return i >= 0 ? i : -i;
}

// Function to perform division of two numbers using binary search algorithm
double divide(double x, double y)
{
	// handle divisibility by 0
	if (y == 0) {
		return INF;		// return infinity
	}

	// set range for result [low, high]. high is set to infinity
	// to handle the case when y < 1, x < result < INF
	double low = 0, high = INF;

	// set accuracy of the result
	double precision = 0.001;

	// store sign of the result
	int sign = 1;
	if (x * y < 0) {
		sign = -1;
	}

	// make both input numbers positive
	x = abs(x);
	y = abs(y);

	while (1)
	{
		// calculate mid
		double mid = low + ((high - low)/2);

		// if y*mid is almost equal to x, return mid
		if (abs(y * mid - x) <= precision)
			return mid * sign;

		// if y*mid is less than x, update low to mid
		if (y * mid < x)
			low = mid;
		else
			// if y*mid is more than x, update high to mid
			high = mid;
	}
}

// Division of two numbers using binary search algorithm
int main(void)
{
	printf("%f", divide(22, 7));

	return 0;
}s