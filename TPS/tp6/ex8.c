/* dirfiles.c
 * list a directory's regular files
 * jmcruz@fe.up.pt, 01.apr.2021
 */

#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

int main(int argc, char * argv[]) {
	char *dirname;
	char filename[1024] = {'\0'};
	DIR * od;
	struct dirent * ds;
	struct stat st;
	if (argc < 2) {
		fprintf(stderr, "\n\tUsage: %s <dirname>\n", argv[0]);
		return (-1);
	}
	dirname = argv[1];
	if ((od = opendir(dirname)) == NULL) {
		perror("opendir");
		exit(1);
	}

	int filecount = 0;
	int totalSize = 0;
	int sizeBlocks = 0;
	int smallest = __INT_MAX__;
	int biggest = 0;
	while((ds = readdir(od)) != NULL) {
		if (!strcmp(ds->d_name, ".") || !strcmp(ds->d_name, ".."))
			continue;
		sprintf(filename, "%s/%s", dirname, ds->d_name);
		if (stat(filename, &st) < 0) {
			perror("stat");
			continue;
		}

		if (st.st_size >biggest){
			biggest = st.st_size;
		}
		if (st.st_size < smallest){
			smallest = st.st_size;
		}

		if ((st.st_mode & S_IFMT) == S_IFREG)
			printf("%s\n",  ds->d_name);
		filecount++;
		totalSize += st.st_size;
		sizeBlocks += st.st_blksize;
	}
	printf("Nr of files: %d\n",filecount);
	printf("Smallest file size: %d\n",smallest);
	printf("Biggest file size: %d\n",biggest);
	printf("Average file's size: %d\n",totalSize/filecount);

	exit(0);
} 
