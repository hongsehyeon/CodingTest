#include <stdio.h>

long long Tlqkf[1000001];

int main()
{
	long long max, min;
	int cnt = 0;
	
	scanf("%lld %lld", &min, &max);
	for (long long i = 2; i * i <= max; i++)
	{
		long long x = min / (i * i);
		if (min % (i * i) != 0)
			x++;
		while (x * (i * i) <= max)
		{
			Tlqkf[x * (i * i) - min] = 1;
			x++;
		}
	}
	for (int i = 0; i <= max - min; i++)
	{
		if (Tlqkf[i] == 0)
			cnt++;
	}

	printf("%d", cnt);
	return 0;
}