obj-m+=encdev.o
obj-m+=decdev.o
all:
	make -C /lib/modules/$(shell uname -r)/build/ M=$(PWD) modules
	$(CC) etest.c -o etest
	$(CC) dtest.c -o dtest
clean:
	make -C /lib/modules/$(shell uname -r)/build/ M=$(PWD) clean
	$(RM) Module.markers modules.order
	rm etest
	rm dtest
