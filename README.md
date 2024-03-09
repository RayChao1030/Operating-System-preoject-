Final Project:   
**Chatroom in C**  
![image](https://github.com/RayChao1030/Operating-System-preoject-/assets/76627328/5caa69d6-c397-4c25-a0f5-5418532615f5)
Workflow in client:     
![image](https://github.com/RayChao1030/Operating-System-preoject-/assets/76627328/2811dc7f-0624-4b43-a66c-20220fa7aeae)
Workflow in server:  
![image](https://github.com/RayChao1030/Operating-System-preoject-/assets/76627328/7b1eab07-31e3-4c57-9711-9dbc59666a29)
Mid Project:  
Added a new system call identity to the Linux kernel, which outputs the string "Hello F14075011". This process involves:  
1.Created an identity.c file containing the code to output the string.  
2.Updated the kernel's Makefile to include the identity/ directory, ensuring that identity.o is compiled into the kernel.  
3.Allocated a number for the new system call in syscall_64.tbl, making it available for use.  
4.Updated header files such as <linux/kernel.h>, unistd.h, and errno.h, which are used for implementing the system call, providing access to the POSIX API, and reporting error codes, respectively.
learnt added new system calls to the Linux kernel but also gained a deeper understanding of the file system structure of Unix-like operating systems. Additionally, solved some compilation issues, such as the need to add blank lines in certain places or to prepend # to include statements. Understood of operating systems and kernel programming more.     
Explanation of **"rbtree.c"** source code and Discussion on the Application of Red-Black Trees in the Linux System and the Impacts of Red-Black Tree Characteristics in HW.
