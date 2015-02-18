/*
 * types.h
 *
 *  Created on: Feb 13, 2015
 *      Author: dernster
 */

#ifndef TYPES_H_
#define TYPES_H_

#include <limits.h>
#include <iostream>

typedef unsigned int color_t;
typedef double coord_t;

#define pow2(x)	((x)*(x))
#define ABS(x) 	((x) > 0 ? (x) : (-(x)))

//#define MAX(type)	std::numeric_limits<type>::max()
//#define MIN(type)	std::numeric_limits<type>::min()

#endif /* TYPES_H_ */
