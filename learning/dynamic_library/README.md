HOW TO RUN APPLICATION:

==>Let us fix that by prepending our working directory to the existing LD_LIBRARY_PATH:
==>If you do not export the changes to an environment variable, they will not be inherited by the child processes. The loader and our test program did not inherit the changes we made.

	->export LD_LIBRARY_PATH=$PWD:$LD_LIBRARY_PATH

==>To compile our application run Makefile using below command
	
	->make

==>Run the executable to see output
	
	->./main
	
katthi@katthi-Inspiron-15-3567:~/Downloads/video_training/TSHtraining/learning$ ./main
enter any two numbers for calculation
10
2
10 + 2 = 12
10 - 2 = 8
10 * 2 = 20
10 / 2 = 5

==>To clean our executables and object files and shared library execute below command
	
	->make clean
------------------------------------------------------------------------------------------

Below are the detailed information about compilation commands in makefile:



==>We need to compile our library source code into position-independent code (PIC):

	gcc -c -fpic calc.c


==>Now we need to actually turn this object file into a shared library. We will call it libcalc.so:

	gcc -shared -o libcalc.so calc.o 


==>We have a shared library. Let us compile our main.c and link it with libcalc

	gcc -o main main.c -lcalc



-----------------------------*end*--------------------------------------------
