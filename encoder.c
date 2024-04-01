#include <stdio.h>
#include "util/bitmap.h"
#include "util/vector.h"

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

	FILE *file = fopen(fileName, "wb");
	if (file == NULL) {
		printf("Error: Writing unavailable file. Aborting..\n");
		return 1;
	}

	HeaderOBMG header = {
		.magic = "OBMG01",
		.width = 10,
		.height = 10,
		.depth = BD_1,
		.type = CT_SHADE
	};

	size_t bytesWritten = fwrite(&header, 1, sizeof(HeaderOBMG), file);
	printf("Bytes Written: %lu, Sizeof Header: %lu\n", bytesWritten, sizeof(header));
	if (bytesWritten != sizeof(header)) {
		printf("Error: Corrupted writing process. Aborting..\n");
		fclose(file);
		return 1;
	}

	printf("magic: %lu\nwidth: %lu\nheight: %lu\ndepth: %lu\ntype: %lu\n", sizeof(header.magic), sizeof(header.width), sizeof(header.height), sizeof(header.depth), sizeof(header.type));

	fclose(file);
	return 0;
}