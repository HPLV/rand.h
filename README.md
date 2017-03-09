# rand.h

A simple and naive C++ header containing Pseudorandom number generator based on Xorshift algorithm.

Firstly you should call ```Srand()``` or ```Srand(seed)``` to initalize the random generator based on both time and your seed.

You can generate a random number by calling ```rand_<typename>(<typename> st, <typename> ed)```. Those types are supported:

1. ```int``` : int

2. ```uint``` : unsigned int

3. ```ll``` : long long / int64

4. ```ull``` : unsigned long long / uint64

5. ```float``` : float

6. ```double``` : double

7. ```ldouble``` : long double

The default parameters for integers are type_MIN and type_MAX, while for float numbers are 0 and 1.

You should notice that the so-called random numbers have DEFINITE SUCCESSOR when ```__hidden_seed``` is given. So please call ```Srand()``` at beginning of your program in order to change ```__hidden_seed```.

It is expected that the random number will have a maximal period of $2 ^ 64 − 1$, although no proof shows that this variation of Xorshift has an exact period of $2 ^ 64 − 1$.
