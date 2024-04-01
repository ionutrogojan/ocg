#include <stdio.h>
#include "util/bitmap.h"
#include "util/vector.h"

const int depths[] = { 1, 2, 4, 8 };
const char *types[] = {
	"SHADE",
	"INDEX",
	"COLOUR",
	"SHADE_ALPHA",
	"COLOUR_ALPHA"
};

int main(int argc, char *argv[]) {
	if (argc < 2) {
		printf("Error: Not enough arguments. Aborting..\n");
		return 1;
	}

	if (argc > 2) {
		printf("Error: Too many arguments. Aborting..\n");
		return 1;
	}

	const char *fileName = argv[1];

	FILE *file = fopen(fileName, "rb");
	if (file == NULL) {
		printf("Error: Reading unavailable file. Aborting..\n");
		return 1;
	}

	HeaderOBMG header;

	size_t bytesRead = fread(&header, 1, sizeof(HeaderOBMG), file);
	if (bytesRead != sizeof(HeaderOBMG)) {
		printf("Error: Corrupted reading process. Aborting..\n");
		fclose(file);
		return 1;
	}

	printf("Magic: %.8s\n", header.magic);
	printf("Width: %upx\n", header.width);
	printf("Height: %upx\n", header.height);
	printf("Bit-Depth: %d\n", depths[header.depth]);
	printf("Colour-Type: %s\n", types[header.type]);

	fclose(file);
	return 0;
}