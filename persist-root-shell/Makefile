PWD := $(shell pwd)
obj-m += getshell.o

all:
	make ARCH=arm -C $(KERNEL)  M=$(PWD) modules
clean:
	make -C $(KERNEL)  M=$(PWD) clean
