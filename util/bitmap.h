#ifndef BITMAP_H
#define BITMAP_H

#ifndef STDINT_H
#define STDINT_H
	#include <stdint.h>
#endif // STDINT_HA

#define ubyte_1 uint8_t
#define ubyte_2 uint16_t
#define ubyte_4 uint32_t
#define ubyte_8 uint64_t

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

typedef struct __attribute__((packed)) {
	char magic[8];
	ubyte_4 width;
	ubyte_4 height;
	ubyte_1 depth;
	ubyte_1 type;
} HeaderOBMG;

typedef struct __attribute__((packed)) {
	ubyte_2 year;      // complete year 1999, not 99
	ubyte_1 month;     // 1..12
	ubyte_1 day;       // 1..31
	ubyte_1 hour;      // 0..23
	ubyte_1 minute;    // 0..59
	ubyte_1 second;    // 0..60
} TimeOBMG;

typedef struct __attribute__((packed)) {
	ubyte_1 length;
	const char *data;
} String;

typedef struct __attribute__((packed)) {
	String title;          // short title or caption
	String author;         // name of the image creator
	String description;    // image content description
	String copyright;      // copyright notice
	// Universal Time (UTC) should be used instead of local
	TimeOBMG create;         // original time creation
	TimeOBMG edit;           // last time modified
	String software;       // software used to create
	// String device;      // device used to create
	// String comment;     // misc comments
} UserDataOBMG;

#endif // BITMAP_H