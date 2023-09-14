#include <stdio.h>

int main() {
	int n, a, b, org, cnt = 0;
	scanf("%d", &n);
	org = n;

	while (1)
	{
		if (n < 10) {
			a = 0;
			b = n;
		}
		else {
			a = n / 10;
			b = n % 10;
		}
		if (a+b >= 10)
			n = a + b - 10 + b * 10;
		else
			n = a + b + b * 10;
		cnt++;
		if (n == org)
			break;
	}
	printf("%d", cnt);

	return 0;
}