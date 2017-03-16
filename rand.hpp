/* 2017-03-09, fstqwq.

   This is a C++ header file in hope that it will help generating Pseudorandom
   numbers using Xorshift-like algorithm, but without any warranty of course.

   This head file is shared under CC0 1.0 Universal license (CC0 1.0), which
   means you can copy, modify, distribute and perform the work, even for
   commercial purposes, all without asking permission. See other information
   at <https://creativecommons.org/publicdomain/zero/1.0/>.  */

#ifndef _RAND_H

#define _RAND_H

#ifndef	_STDLIB_H
#include <stdlib.h>
#endif

#ifndef _LIMITS_H
#include <limits.h>
#endif

#ifndef _TIME_H
#include <time.h>
#endif

#ifndef _UNISTD_H
#include <unistd.h>
#endif

unsigned long long __rand_value = 0x2333333333333333, __hidden_seed = 0x79786365766f6c69;

unsigned long long raw_rand() {
	__rand_value ^= (__rand_value - 1) >> 12;
	__rand_value ^= (__rand_value + 1) << 25;
	__rand_value ^= (__rand_value - 1) >> 27;
	return __rand_value ^ __hidden_seed;
}

unsigned long R_mix(unsigned long a, unsigned long b, unsigned long c) {
    a=a-b;  a=a-c;  a=a^(c >> 13);
    b=b-c;  b=b-a;  b=b^(a << 8);
    c=c-a;  c=c-b;  c=c^(b >> 13);
    a=a-b;  a=a-c;  a=a^(c >> 12);
    b=b-c;  b=b-a;  b=b^(a << 16);
    c=c-a;  c=c-b;  c=c^(b >> 5);
    a=a-b;  a=a-c;  a=a^(c >> 3);
    b=b-c;  b=b-a;  b=b^(a << 10);
    c=c-a;  c=c-b;  c=c^(b >> 15);
    return c;
}

int R_mem() {
	int *tmp = (int*)malloc(sizeof(int));
	free(tmp);
	return (int)tmp;
}

unsigned int Get_seed() {
	//need unistd.h for getpid()
	return R_mix(time(NULL), getpid(), R_mem());
}

void Srand(unsigned long long seed = 0x319) {
	srand(Get_seed());
	__rand_value ^= time(NULL) * 0x2545f4914f6cdd1d;
	__hidden_seed ^=  (seed << 32) ^ seed ^ raw_rand();
	for (int i = 31; i; i--) __rand_value ^= ((unsigned long long)rand() * RAND_MAX + rand()) << i; 
}

int rand_int(int st = INT_MIN, int ed = INT_MAX) {
	return int(raw_rand() % ((long long)ed - st + 1) + st);
}

unsigned int rand_uint(int st = 0, int ed = UINT_MAX) {
	return (unsigned int)(raw_rand() % ((long long)ed - st + 1) + st);
}

long long rand_ll(long long st = LLONG_MIN, long long ed = LLONG_MAX) {
	if (st + ULLONG_MAX == (unsigned long long)ed)
		return raw_rand();
	else
		return raw_rand() % (ed - st + 1) + st;
}

unsigned long long rand_ull(unsigned long long st = 0, unsigned long long ed = ULLONG_MAX) {
	if (st + ULLONG_MAX == ed)
		return raw_rand();
	else 
		return raw_rand() % (ed - st + 1) + st;
}

float rand_float(float st = 0, float ed = 1) {
	return float(raw_rand() % ULLONG_MAX)  * (ed - st) / float(ULLONG_MAX - 1) + st;
}

double rand_double(double st = 0, double ed = 1) {
	return double(raw_rand() % ULLONG_MAX) * (ed - st) / double(ULLONG_MAX - 1) + st;
}

long double rand_ldouble(long double st = 0, long double ed = 1) {
	return ((long double)(raw_rand() % ULLONG_MAX)) * (ed - st) / ((long double)ULLONG_MAX - 1) + st;
}

#endif

