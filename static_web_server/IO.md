
# Input/Output in C

## How to read from a file

This is a basic file read in C using the stdlib
``` C

//file.c/main()

/*
First get the 'file descriptor' which is
of type int.
    
When you request a file to be accessible via
open() you pull it into memory (from storage)
and then you give it a descriptor in memory to 
be accessible from.

This descriptor is kind of like a pointer, but is moreso
an index at which the file you request and other memory
is stored.
*/

int fd = open(path, O_RDONLY);
//file is now accesible via memory address
//    stored in 'fd'

/*
To perform actions you can use the C standard library.

Say you want to perform a read...
you would first allocate the space in your program
to be able to store the results of a read (make a buffer).

And then you would use the read() function.
*/

//Holds random memory until written to
char buffer[100];

/*
read(fd, buff, n) where...

ssize_t -> "signed size type"

args:
    fd (int) -> file descriptor (found previously)
    buff (void *) -> where we want the results of our read
    n (int) -> how many bytes we want to read

Again, file descriptors are not pointers to files
but rather integers in memory that serve as indices
you can query so the OS knows which file to get.

void * means a non-typed pointer, and it allows any
memory address to be passed that references a writeable
buffer.
*/
ssize_t length = read(fd, buffer, 100);

//close to stop a memory leak
close(fd);

/*
The read function will return a special signed int (ssize_t).
And this represents the amount of bytes that were successfully
read from the file.

This value may be less than the number of bytes you requested (100)
for example if the file is less than 100 bytes long.

It can also return -1 representing an error which needs to
be manually handled.

Otherwise it will return 100 representing that it read the
full 100 bytes you requested.
*/
```

## What is meant by buffer?
This buffer strategy is necessary because reading from
a file results in data that is highly mutable, and
non-deterministic.

So you cannot use a simple contiguous character array
(string literal) to read it (it would segfault).

You must allocate writeable memory first, and then
write to it.

This further shows that the ideas of mutable/immutable
are highly important.

The stack is for immutable/deterministic data, and allows
for increased speed.

And the heap is for data that is highly dynamic.

These concepts also connect to OOP concepts, and statically
vs. dynamically typed languages.

When creating variables in these languages you have more
flexibility when those languages are dynamic, but at the
cost of speed. And you have less flexibility with statically
typed languages but you gain speed.

> Also see -> memory_in_c.md
