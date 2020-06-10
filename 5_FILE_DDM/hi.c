
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>


int main(){
	int fd = open("/dev/kdh", O_RDWR);
	if(fd < 0) {
		printf("ERROR /dev/kdh \n");
	}
	else {
		printf("gooood!\n");
	}

	close(fd);

	return 0;
}
