#include <stdio.h>
#include <math.h>

// Returns gcd of a and b
int gcd(int a, int b)
{
	if (b == 0)
	{
		return a;
	}

	return gcd(b, a % b);
}

int main()
{
	// Choose two distinct prime numbers
	double p = 3;
	double q = 5;

	double n = p * q; // Used as the modulus for both the public and private keys

	double phi = (p - 1) * (q - 1); // Calculate totient to set a limit for e
	
	// Choose an integer that is coprime to n.
	int e = 0;
	for (int i = 2; i < phi; i++)
	{
		if (gcd(n, i) == 1)
		{
			e = i;
			break;
		}
	}

	int k = 2; // Some integer

	// Generate private key
	double d = (k * phi + 1) / e;

	return 0;
}