HOW TO RUN APPLICATION:

==>to compile our application run Makefile using below command
	
	->make

==>run the program to see output
	
	->./main

katthi@katthi-Inspiron-15-3567:~/Downloads/video_training/dl_libraries$ ./main
enter any two numbers for calculation
8
4
add:12
sub:4
mul:32
div:2

==>to clean our executables and object files and shared library execute below command
	
	->make clean
-----------------------------------------------------------------------------------------

Dynamically loaded (DL) libraries are libraries that are loaded at times other than during the startup of a program.


==>dlopen()

The dlopen(3) function opens a library and prepares it for use. In C its prototype is:

  void * dlopen(const char *filename, int flag);

If filename begins with ``/'' (i.e., it's an absolute path), dlopen() will just try to use it (it won't search for a library). Otherwise, dlopen() will search for the library in the following order:

    A colon-separated list of directories in the user's LD_LIBRARY_PATH environment variable.

    The list of libraries specified in /etc/ld.so.cache (which is generated from /etc/ld.so.conf).

    /lib, followed by /usr/lib. Note the order here; this is the reverse of the order used by the old a.out loader. The old a.out loader, when loading a program, first searched /usr/lib, then /lib (see the man page ld.so(8)). This shouldn't normally matter, since a library should only be in one or the other directory (never both), and different libraries with the same name are a disaster waiting to happen.

In dlopen(), the value of flag must be either RTLD_LAZY, meaning ``resolve undefined symbols as code from the dynamic library is executed'', or RTLD_NOW, meaning ``resolve all undefined symbols before dlopen() returns and fail if this cannot be done''. RTLD_GLOBAL may be optionally or'ed with either value in flag, meaning that the external symbols defined in the library will be made available to subsequently loaded libraries. While you're debugging, you'll probably want to use RTLD_NOW; using RTLD_LAZY can create inscrutable errors if there are unresolved references. Using RTLD_NOW makes opening the library take slightly longer (but it speeds up lookups later); if this causes a user interface problem you can switch to RTLD_LAZY later.

If the libraries depend on each other (e.g., X depends on Y), then you need to load the dependees first (in this example, load Y first, and then X).

The return value of dlopen() is a ``handle'' that should be considered an opaque value to be used by the other DL library routines. dlopen() will return NULL if the attempt to load does not succeed, and you need to check for this. If the same library is loaded more than once with dlopen(), the same file handle is returned.




===>dlerror()

Errors can be reported by calling dlerror(), which returns a string describing the error from the last call to dlopen(), dlsym(), or dlclose(). One oddity is that after calling dlerror(), future calls to dlerror() will return NULL until another error has been encountered.



==>dlsym()

There's no point in loading a DL library if you can't use it. The main routine for using a DL library is dlsym(3), which looks up the value of a symbol in a given (opened) library. This function is defined as:

 	void * dlsym(void *handle, char *symbol);

the handle is the value returned from dlopen, and symbol is a NIL-terminated string. If you can avoid it, don't store the result of dlsym() into a void* pointer, because then you'll have to cast it each time you use it (and you'll give less information to other people trying to maintain the program).

dlsym() will return a NULL result if the symbol wasn't found. If you know that the symbol could never have the value of NULL or zero, that may be fine, but there's a potential ambiguity otherwise: if you got a NULL, does that mean there is no such symbol, or that NULL is the value of the symbol? The standard solution is to call dlerror() first (to clear any error condition that may have existed), then call dlsym() to request a symbol, then call dlerror() again to see if an error occurred. A code snippet would look like this:


 	dlerror(); /* clear error code */
	 s = (actual_type) dlsym(handle, symbol_being_searched_for);
 	if ((err = dlerror()) != NULL) {
  	/* handle error, the symbol wasn't found */
 	} else {
 	 /* symbol found, its value is in s */
 	}



==>dlclose()

The converse of dlopen() is dlclose(), which closes a DL library. The dl library maintains link counts for dynamic file handles, so a dynamic library is not actually deallocated until dlclose has been called on it as many times as dlopen has succeeded on it. Thus, it's not a problem for the same program to load the same library multiple times. If a library is deallocated, its function _fini is called (if it exists) 
Note: dlclose() returns 0 on success, and non-zero on error.


If the program were in a file named "main.c", you would build the program with the following command:

    gcc -o foo foo.c -ldl

-----------------------------*end*--------------------------------------------
