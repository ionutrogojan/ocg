#include <stdio.h>
#include "util/bitmap.h"
#include "util/vector.h"

String stringFrom(const char *data);

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

	UserDataOBMG userdata = {
		.title = stringFrom("testfile"),
		.author = stringFrom("authorname"),
		.description = stringFrom("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor."),
		.copyright = stringFrom("Creative-Commons(00)"),
		.create = {	2024, 3, 2, 5, 30, 0 },
		.edit = { 0, 0, 0, 0, 0, 0 },
		.software = stringFrom(""),
	};

	size_t bytesWritten = fwrite(&header, 1, sizeof(HeaderOBMG), file);
	if (bytesWritten != sizeof(header)) {
		printf("Error: Corrupted writing process. Aborting..\n");
		fclose(file);
		return 1;
	}

	printf("Bytes Written: %lu\n", bytesWritten);
	printf("Sizeof Header: %lu\n", sizeof(header));
	printf("Sizeof UserData: %lu\n", sizeof(userdata));

	printf("magic: %lu\nwidth: %lu\nheight: %lu\ndepth: %lu\ntype: %lu\n", sizeof(header.magic), sizeof(header.width), sizeof(header.height), sizeof(header.depth), sizeof(header.type));

	fclose(file);
	return 0;
}

String stringFrom(const char *data) {
	ubyte_1 length = 0;

	while (data[length] != '\0' && length < ((1ULL << (8 * sizeof(ubyte_1))) - 1))
		length++;

	return (String){ length, data };
}