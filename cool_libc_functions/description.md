My friend just started doing C, with the help of the libc he got an awesome
program to run. He hosted it on its server for me to try it and gave me the
source code too, unfortunetly some parts are missging...

Here is what I can read from it:

```c
#include <string.h>
#include <stdio.h>

typedef struct my_struct {
	char tab[4242];
	char key;
} my_struct;

int main() {
	my_struct	var;
	var.key = 0;

	puts("Hello! Please enter your name:");
	gets(var.tab);
	puts("Your name is:");
	puts(var.tab);

	if (var.key == 42) {
		show_secret_password();
	}
}
```

I have to find a way to call the function "show_secret_password" !

Anyway if you can help me the server is [IP],
he told me that you can connect with netcat to it.

Flag format: `flag{flag_value}`

Creator: nathan