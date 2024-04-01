#ifndef BITMAP_H
#define BITMAP_H

#ifndef STDINT_H
#define STDINT_H
	#include <stdint.h>
#endif // STDINT_H

typedef enum {
	CT_SHADE,
	CT_INDEX,
	CT_COLOUR,
	CT_SHADE_ALPHA,
	CT_COLOUR_ALPHA
} ColorTypeOBMG;

typedef enum {
	BD_1,
	BD_2,
	BD_4,
	BD_8,
	// BD_16,
	// BD_32
} BitDepthOBMG;

typedef struct __attribute__((packed)){
	char magic[8];
	uint32_t width;
	uint32_t height;
	uint8_t depth;
	uint8_t type;
} HeaderOBMG;

#endif // BITMAP_H