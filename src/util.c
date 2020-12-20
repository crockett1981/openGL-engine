#include "util.h"

char* concat(const char* string1, const char* string2) {
	const size_t length1 = strlen(string1);
	const size_t length2 = strlen(string2);
	
	/* + 1 for null terminator "\0" */
	char* string = (char*)malloc(length1 + length2 + 1);
	if (string == NULL)
		return NULL;

	memcpy(string, string1, length1);
	memcpy(string + length1, string2, length2 + 1);

	return string;
}

char* load_file(const char* file_name) {

	FILE* file = NULL;
	long length = 0;
	char* content = NULL;
	size_t read_chars = 0;

	char* error = concat("File not found ", file_name);

	file = fopen(file_name, "rb");
	if (file == NULL) {
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "File", error, window);
		return NULL;
	}

	if (fseek(file, 0, SEEK_END) != 0) {
		printf("Unexpected end of file\n");
		return NULL;
	}

	length = ftell(file);
	if (length < 0) {
		printf("File doesn't have any information\n");
		return NULL;
	}

	if (fseek(file, 0, SEEK_SET) != 0) {
		printf("Unexpected end of file\n");
		return NULL;
	}

	content = (char*)malloc((size_t)length + sizeof(""));
	if (content == NULL) {
		return NULL;
	}

	read_chars = fread(content, sizeof(char), (size_t)length, file);
	if ((long)read_chars != length) {
		free(content);
		content = NULL;
		fclose(file);
		return NULL;
	}

	content[read_chars] = '\0';

	fclose(file);

	return content;
}
