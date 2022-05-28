#include <stdio.h>
#include <string>
#include <math.h>

using namespace std;

struct PRIVATE_KEY // !!!KEPT SECRET!!!
{
	int p;
	int q;
	double d; // Private key exponent
};

struct PUBLIC_KEY
{
	double n; // Used as the modulus
	static const int e = 2 ^ 16 + 1; // Used as the exponent
};

struct RSA_KEYS
{
	PUBLIC_KEY		public_key;
	PRIVATE_KEY		private_key;
};

int bin_exp( int a, int b ) // Returns a^b using binary exponentiation
{
	if ( b == 1 )
		return a;

	if ( b % 2 == 0 )
		return bin_exp( a * a, b / 2 );
	else
		return a * bin_exp( a * a, (b - 1) / 2 );
}

// Returns gcd of a and b
int gcd(int a, int b)
{
	if (b == 0)
	{
		return a;
	}

	return gcd(b, a % b);
}

// 
RSA_KEYS generate_keys()
{
	// Choose two distinct prime numbers
	double p = 3;
	double q = 5;

	double n = p * q; // Used as the modulus for both the public and private keys. n's length (in bits) is the key length.

	double phi = ((p - 1) * (q - 1)) / gcd( p - 1, q - 1 ); // Calculate totient to set a limit for e. Faster calculation due to n = pq.

	// Choose an integer that is coprime to n. Released as part of the public key.
	int e = 2^16 + 1; // Short bit length and small Hamming weight
	
	int k = 2; // Some integer

	// Generate private key exponent
	double d = (k * phi + 1) / PUBLIC_KEY::e;

	// Create the keys struct
	RSA_KEYS keys;
	keys.private_key.d = d;
	keys.private_key.p = p;
	keys.private_key.q = q;

	keys.public_key.n = n;

	return keys;
}

double encrypt()
{
	return 0;
}

double decrypt()
{
	return 0;
}

// Driver code
int main()
{
	// Generate keys
	RSA_KEYS keys = generate_keys();
	PUBLIC_KEY pub = keys.public_key;
	PRIVATE_KEY priv = keys.private_key;

	// Bob wants to send message M to Alice, after receiving Alice's public key.
	string M = "Hello World"; // The original message

	int m = 0; // m is the padded message with an agreed upon size

	int c = bin_exp( m, pub.e ) % (int)(pub.n);

	return 0;
}