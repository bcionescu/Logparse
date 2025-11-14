#include <stdio.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {

    // Take path to log file as argument, as well as something to look for.
	
   if (argc < 2) {
	fprintf(stderr, "Usage: %s <path-to-log>\n", argv[0]);
	return 1;
    }

    const char *path = argv[1];
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

    printf("Path provided: %s\n", path);

    // Check that the file exists, and that it is not empty.
	
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
