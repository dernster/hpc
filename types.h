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

typedef float color_t;
typedef unsigned int uint;
typedef double coord_t;

#define pow2(x)				((x)*(x))
#define ABS(x) 				((x) > 0 ? (x) : (-(x)))
#define MIN(x,y) 			(((x) < (y)) ? (x) : (y))
#define for3ig(array,value) 	for(int i = 0; i < 3; i++)\
								array[i] = value;

#define for3masig(array,value) 	for(int i = 0; i < 3; i++)\
								array[i] += value;

#define BYTE(var,i)	*(((unsigned char*)&var)+i)

#endif /* TYPES_H_ */
