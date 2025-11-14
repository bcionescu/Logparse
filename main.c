#include <stdio.h>
#include <sys/stat.h>
#include <string.h>

int main(int argc, char *argv[]) {

    // Take path to log file as argument, as well as something to look for.
    int flag_i = 0, flag_n = 0, flag_a = 0;
    const char *regex = NULL;
    const char *path = NULL;

    int i = 1;
    for (; i < argc; i++) {
	if (argv[i][0] == '-') {
	    if (argv[i][1] == '\0') {
		break;
	    }

	    for (int j = 1; argv[i][j] != '\0'; j++) {
		switch (argv[i][j]) {
		    case 'i': flag_i = 1; break;
		    case 'n': flag_n = 1; break;
		    case 'a': flag_a = 1; break;
		    default:
			fprintf(stderr, "Unknown option: %c\n", argv[i][j]);
			return 1;
		}
	    }
	} else {
	    break;
	}
    }

    if (i < argc - 1) {
	regex = argv[i++];
    }

    if (i < argc) {
	path = argv[i];
    }

    if (!path) {
	fprintf(stderr, "Usage: %s [-i] [-n] [-a] [regex] <path-to-log>\n", argv[0]);
	return 1;
    }

    // Check that the file exists.

    struct stat st;
    
    if (stat(path, &st) != 0) {
	perror("stat");
	fprintf(stderr, "Error: cannot access file: %s\n", path);
	return 1;
    }

    if (!S_ISREG(st.st_mode)) {
	fprintf(stderr, "Error: path is not a regular file: %s\n", path);
	return 1;
    }

    printf("Flags: -i=%d -n=%d -a=%d\n", flag_i, flag_n, flag_a);
    printf("Regex: %s\n", regex ? regex : "(none)");
    printf("Path: %s\n", path);

    // Read the file

    // Ensure the file is not empty.

    // Check that the regex compiles properly, and in a reasonable amount of time.

    // Check that the file is readable, and does not contain any null bytes, causing
    // portions of the file be silently skipped.

    // Logs are usually in UTF-8, but not always. This might need to be addressed?

    // Read the contents of the file.

    // Go through it line by line, and use regex to look for requested data.

    // Show the relevant lines, using ANSII to color the matches, if the flag was provided.

    // Display extra information, such as the number of occurences.

    // Take extra arguments:
    // -i for case insensitivity
    // -n to display the line number for each matching line
    // -a to enable ANSII, as some users may prefer to not have it by default

    return 0;

}
