KERNEL_HEADERS=/lib/modules/$(shell uname -r)/build
CC=gcc

TARGET=minco_module
obj-m=minco_module.o

all:
	@$(MAKE) -C $(KERNEL_HEADERS) M=$(PWD) modules

hi:
	@(CC) -o $@ $@.cz

clean:      
	@$(MAKE) -C $(KERNEL_HEADERS) M=$(PWD) clean
