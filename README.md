# rand.h

A simple and naive C++ header containing Pseudorandom number generator based on Xorshift algorithm.

Firstly you should call ```Srand()``` or ```Srand(seed)``` to initalize the random generator based on both time and your seed.

You can generate a random number by calling ```rand_<typename>(<typename> st, <typename> ed)```. Those types are supported:

1. ```rand_int()``` : int

2. ```rand_uint()``` : unsigned int

3. ```rand_ll()``` : long long / int64

4. ```rand_ull()``` : unsigned long long / uint64

5. ```rand_float()``` : float

6. ```rand_double()``` : double

7. ```rand_ldouble()``` : long double

The default parameters for integers are type_MIN and type_MAX, while for float numbers are 0 and 1.

You should notice that the so-called random numbers have DEFINITE SUCCESSOR when ```__hidden_seed``` is given. So please call ```Srand()``` whenever you want to do something which is unrelated to what you just have done in order to change ```__hidden_seed```(like making next case of data for OI/ACM contest).
