#include <stdio.h>
#include <linux/kernel.h>
#include <sys/syscall.h>
#include <unistd.h>
int main(int argc, char** argv)
{	
	char first_name[25], last_name[25];
	printf("Enter your first name: \n");
	scanf("%s", first_name);
	printf("Enter your last name: \n");
	scanf("%s", last_name);
	long int amma = syscall(335, first_name, last_name);
	printf("System call sys_rapname returned %ld\n", amma);
	return 0;
}
