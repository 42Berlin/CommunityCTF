#include <stdio.h>

int main(int argc, char **argv) {
	char *tab5 = "0u}";
	char *tab4 = "0_y";
	char *tab3 = "3ll";
	char *tab2 = "g{h";
	char *tab1 = "fla";

	if (argc != 2) {
		printf("Please enter an argument.");
		return 2;
	}

	printf(argv[1]);
}
