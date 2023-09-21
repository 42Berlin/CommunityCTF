#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <stdlib.h>
#include <utime.h>
#include <fcntl.h>
#include <ctype.h>
#include <errno.h>

void create();
void resolve();

#define FILE "not_so_important_file"

int main(int argc, char **argv) {
	if (argc != 2) {
		write(2, "argument needed\n", 17);
		exit(1);
	}
	if (strcmp("reset", argv[1]) == 0) {
		create();
	} else if (strcmp("check", argv[1]) == 0) {
		resolve();
	} else if (strcmp("both", argv[1]) == 0) { // a rm
		create();
		resolve();
	} else {
		printf("argv != reset or check");
	}
}

void chars_into_int(int *ptr, char *tab, int offset) {
	char *i = ptr;

	i[0] = tab[0] + offset;
	i[1] = tab[1] + offset;
	i[2] = tab[2] + offset;
	i[3] = tab[3] + offset;
}

void int_into_str(int number, char *tab, int offset) {
	char *i = &number;

	tab[0] = i[0] - offset;
	tab[1] = i[1] - offset;
	tab[2] = i[2] - offset;
	tab[3] = i[3] - offset;
}

void data(int key) {
	char *tab = malloc(key + 1);
	bzero(tab, key + 1);

	for (int i = 0; i < key; i++) {
		char c = rand() % 16;
		if (c < 10) {
			tab[i] = c + '0';
		} else {
			tab[i] = c + 'a' - 10;
		}
	}
	int fd = open(FILE, O_CREAT | O_RDWR, 0644);
	int w = write(fd, tab, key);
	close(fd);
}

void create() {
	unlink(FILE);
	srand(time(0));
	int key = 1 + (rand() % 16);
	data(key);

	struct timespec new[2];
	bzero(new, sizeof(struct timespec) * 2);
	char t1[4] = "flag";
	char t2[4] = "{Cr*";
	char t3[4] = "Vit3";
	char t4[4] = "}\0\0\0";
	chars_into_int(&new[0].tv_sec, t1, key);
	chars_into_int(&new[0].tv_nsec, t2, key);
	chars_into_int(&new[1].tv_sec, t3, key);
	chars_into_int(&new[1].tv_nsec, t4, key);

	int ret = utimensat(AT_FDCWD, FILE, new, AT_SYMLINK_NOFOLLOW);
}

void resolve() {
	struct stat file_stat;
	char flag[] = "flag{Cr*Vit3}";

	stat(FILE, &file_stat);

	int key = file_stat.st_size;

	char t1[5], t2[5], t3[5], t4[5];
	bzero(t1, 5);
	bzero(t2, 5);
	bzero(t3, 5);
	bzero(t4, 5);

	void *ptr = &file_stat.st_atime;

	int_into_str(file_stat.st_atime, t1, key);
	int_into_str(*(int *)(ptr + 8), t2, key);
	int_into_str(file_stat.st_mtime, t3, key);
	int_into_str(*(int *)(ptr + 24), t4, key);


	char truc[17];
	bzero(truc, 17);

	strcpy(truc, t1);
	strcat(truc, t2);
	strcat(truc, t3);
	strcat(truc, t4);

	if (strncmp(truc, flag, 13) == 0) {
		printf("The flag is still available\n");
	} else {
		printf("The flag is not available anymore. Reset.\n");
	}
}
