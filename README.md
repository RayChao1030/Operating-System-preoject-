Project_mid:  
added a new system call identity to the Linux kernel, which outputs the string "Hello F14075011". This process involves:  
1.Created an identity.c file containing the code to output the string.  
2.Updated the kernel's Makefile to include the identity/ directory, ensuring that identity.o is compiled into the kernel.  
3.Allocated a number for the new system call in syscall_64.tbl, making it available for use.  
4.Updated header files such as <linux/kernel.h>, unistd.h, and errno.h, which are used for implementing the system call, providing access to the POSIX API, and reporting error codes, respectively.
leart added new system calls to the Linux kernel but also gained a deeper understanding of the file system structure of Unix-like operating systems. Additionally, solved some compilation issues, such as the need to add blank lines in certain places or to prepend # to include statements. This experience has enhanced your understanding of operating systems and kernel programming, as well as your problem-solving abilities.
Worked in VMware Workstation.    
Explanation of **"rbtree.c"** source code and Discussion on the Application of Red-Black Trees in the Linux System and the Impacts of Red-Black Tree Characteristics in HW.
