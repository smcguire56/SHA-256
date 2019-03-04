// Sean McGuire
// The secure Hash Algorithm 256 

// input/ output header files.
#include <stdio.h>
// for using fixed bit length integers.
#include <stdint.h>

// see sections 4.1.2 and 4.2.2 for definitions. 
uint32_t sig0(uint32_t x);
uint32_t sig1(uint32_t x);

// Section 3.2
uint32_t rotr(uint32_t n, uint32_t x);
uint32_t shr(uint32_t n, uint32_t x);

void sha256();


int main(int argc, char *argv[]) 
{
	sha256();
	return 0;
}

// Initial sketch of SHA 256 algorithm
void sha256() 
{
	// Message schedule (Section 6.2)
	uint32_t W[64];
	// Working variables (Section 6.2)
	uint32_t a, b, c, d, e, f, g, h;
	// Two temporary variables (SECTION 6.2).
	uint32_t T1, T2;

	// The Hash value. (Section 6.2)
	uint32_t H[8] = 
	{
		0x6a09e667,
		0xbb67ae85,
		0x3c6ef372,
		0xa54ff53a,
		0x510e527f,
		0x9b05688c,
		0x1f83d9ab,
		0x5be0cd19
	};

	// Current message block
	uint32_t M[16];

	// for loop, from page 22, W[t] = M[t] 
	// for 0 <= t <= 15
	for (int t = 0; t < 16; t++)
	{
		W[t] = M[t];
	}

	// loops through the rest, page 22
	for (int t = 0; t < 64; t++)
	{
		sig1(W[t - 2]) + W[t - 7] + sig0(W[t - 15]) + W[t - 16];
	}

	// Initialize a, b, c, d and e as per stpe 2.(Page 19)
	a = H[0]; b = H[1]; c = H[2]; d = H[3]; 
	e = H[4]; f = H[5]; g = H[6]; h = H[7];

	// step 3.
	for (int t = 0; t < 64; t++)
	{
		T1 = h + SIG_1(e) + Ch(e, f, g) + K[t] + W[t];
		T2 = SIG_0(a) + Maj(a, b, c);
		h = g;
		f = e;
		e = d + T1;
		d = c;
		c = b;
		b = a;
		a = T1 + T2;

	}

	// step 4.
	H[0] = a + H[0];
	H[1] = b + H[1];
	H[2] = c + H[2];
	H[3] = d + H[3];
	H[4] = e + H[4];
	H[5] = f + H[5];
	H[6] = g + H[6];
	H[7] = h + H[7];
}

uint32_t sig0(uint32_t x)
{
	// Section 3.2 & 4.1.2 for reference 
	return (rotr(7, x) ^ rotr(18, x) ^ rotr(3, x));
}

uint32_t sig1(uint32_t x)
{
	// Section 3.2 & 4.1.2 for reference 
	return (rotr(17, x) ^ rotr(19, x) ^ shr(10, x));

}

uint32_t rotr(uint32_t n, uint32_t x)
{
	return (x >> n) | (x << (32 - n));
}

uint32_t shr(uint32_t n, uint32_t x)
{
	return (x >> n);
}