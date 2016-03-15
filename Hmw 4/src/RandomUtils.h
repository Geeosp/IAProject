#ifndef RANDOM_UTILS_H
#define RANDOM_UTILS_H

#include <assert.h>

#include <stdlib.h>

//returns a random integer between x and y
inline int   RandInt(int x, int y)
{
	assert(y >= x && "<RandInt>: y is less than x");
	return rand() % (y - x + 1) + x;
}

//returns a random double between zero and 1
inline float RandFloat()      { return (float)((rand()) / (RAND_MAX + 1.0)); }

inline float RandInRange(float x, float y)
{
	return x + RandFloat()*(y - x);
}

//returns a random bool
inline bool   RandBool()
{
	if (RandFloat() > 0.5) return true;

	else return false;
}

//returns a random double in the range -1 < n < 1
inline float RandomClamped()    { return RandFloat() - RandFloat(); }

#endif