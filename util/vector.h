#ifndef VECTOR_H
#define VECTOR_H

#ifndef STDINT_H
#define STDINT_H
	#include <stdint.h>
#endif // STDINT_H

typedef struct __attribute__ ((packed)) {
	char magic[8];
	uint32_t width;
	uint32_t height;
} HeaderOVG;

#endif // VECTOR_H