# Creating a basic Kernel Module

Creating a Kernel Module needs 4 things:
1. Some basic understanding of Kernel space and user space.
2. Another tab open of linus-torvalds github repo of a header which you want to use and test macros.
3. Linux headers installed from your package manager.
4. And lastly some love :)

## Steps to follow:
### 1. Installing Linux Kernel Headers:

To compile the kernel code you are about to write, you will need the linux kernel headers which can be installed using the following command:
<br>
<b>sudo apt-get install linux-headers-$(uname -r)</b> (If you are using apt)
<br>
<b>sudo dnf install kernel-headers-$(uname -r)</b> (If you are using dnf)

### 2. Creating a Makefile:

Compiling Kernel Code is not as simple as just running: <br><b>gcc my_kernel_module.c</b><br>
We need to use the build present in the kernel header that you installed!
So to compile kernel code you need to run the command: <br><b>make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules</b>

And to remove all the kernel module and accessory stuff built you need to run the command: <br><b>make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean</b>

This can be a bit of a headache so we write a Makefile that goes like this:

<b>
obj-m += <name of your C file without .c extension>.o

all:<br>
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:<br>
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
</b>

Now we can compile kernel code using the command: <b>make</b>

### 3. Time to write some Code:

Write some code related to macros and structures already present in some linux headers.
Refer to my_module.c in list_processes directory for example.

### 4. Compile the code!

Compile the C Code that you have typed by running the command: <b>make</b>

### 5. Wow so many new files!

New files will be created after compiling like this:

![image](https://user-images.githubusercontent.com/97780641/228914283-0cb63ea8-abdd-4f2b-8346-a94daae72dcd.png)

The one you are looking for is <your C file name without .c extension>.ko

### 6. Loading the Kernel Module:

To load the Kernel Module, run the command: <b>sudo insmod <your prize>.ko </b>

### 7. dmesg is key!

Nothing happened?
Well run the command: <b>dmesg</b><br>
There it is! 

![image](https://user-images.githubusercontent.com/97780641/228914725-9a9ebc9f-7d2a-4d8c-8f34-692ddb0a7345.png)
