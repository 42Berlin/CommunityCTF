#include <string.h>
#include <stdio.h>
#include <unistd.h>

void my_gets(char *a) {
	int ret = 0;

	ret = read(0, a, 42000);
}

typedef struct test {
	char tab[4242];
	char key;
} test;

void show_secret_password() {
	printf("flag{H0w_did_U_do?}");
}

int main() {
	test	var;
	
	var.key = 0;
	bzero(var.tab, 4242);

	puts("Hello! Please enter your name:");
	fflush(stdout);
	gets(var.tab);
	puts("Your name is:");
	puts(var.tab);

	if (var.key == 42) {
		show_secret_password();
	}
}
