# How C Views/Uses Memory

## Syntax for storing and creating objects in C

Basic binary to value process: Binary (bits/bytes) --(encoding)--> Value (int, char, float, etc...)

C leverages several organizations of these bits and bytes throughout the language. These organizations are called data types.

For example with strings...they are made with the following syntax:

```c
char *str = "This is a string";
```

The char \* is the data type.
It represents one byte. And the star (\*) returns the address-of
the first byte of the sequence of bytes in memory which the whole string resides.  

The variable name `str` is simply a label for that address in memory.

Since the type is one single byte (char), whenever this variable is used, it expects the 
string to end in a null terminator. A null terminator is simply a byte with all bits set to 0.

Other types have different bits and bytes (and encodings) associcated with them.

> "Everything in C is either an object type or a function type." - Robert C. Seacord, _Effective C_


## How are values in a C program referenced?

Most arguments (refs to predefined values) are referenced in C as pointers in the form of
integers (See above section) that reperesent the "address" of the values.

This works because all the objects in the program
will eventually boil down into (global) memory addresses
which themselves are just integers of a particular
bit/byte size. This is true of all types (Strings, floats, ints, etc..)

References create pointers that boil down to integer addresses
which hold integers converted from human value to binary via encodings.

And initialized values are stored in memory as their binary conversions
as well, but expose different addresses which can be 
referenced via pointers.

initialized value -> binary conversion -> stored in memory at address X
pointer -> memory address of an initialized value -> IF dereferenced -> gets the value at address X

both the initialized value and the pointer to that value
ultimately boil down to integer.

pointer 

### But if C values are referenced as single integers, then how does the entirety of the value get used?

UPDATED:  
If a value is referenced using only a pointer to one part of it's value, how
does the computer get the rest of the bytes associated with any given object/value?

All bytes of a single human-value are referenceable from just a pointer to the first byte
because of the way that memory is stored. Processors store memory sequentially so
when you know the first byte, and also how many bytes are associated with that value
then you can just increment from the initial address to find the rest of the bytes.
That or the value itself has a terminator value that indicates the end of the value.
Example...null terminator for strings.
* That process is not always automated in C which causes memory unsafety. For example,
when you use the write(int64, int64, n) function, when you pass a value n (which
corresponds to the amount of bytes to increment to) greater than the actual
width of your value then you start pulling memory values from elsewhere in your program.
C's no guardrails approach lets you do this.

## Memory of functions

In C, when a function is called, a new "stack frame" is created in memory.

When that function returns or exits its objects in that stack frame are
automatically "dropped" \(removed from memory\).
* The most automatic memory management in C.
* Stops memory leaks on function calls.

This behavior with functions is why it's dangerous to return pointers to
values that were defined and instantiated inside a function.

Once the function exits, the values the pointer may point to are gone. And thus, result
in undefined behavior if you try to \(de\)reference that pointer.

This is why it's often safer to mutate passed in values as opposed to returning new values
from functions in C.

This problem however introduces manual memory management techniques in C.

## Manual memory management in C
C provides functions in its standard library to manually allocate and free memory.
These functions include `malloc()`, `calloc()`, `realloc()`, and `free()`.

When you use `malloc()` or `calloc()`, you are requesting a block of memory from the heap.
This memory remains allocated until you explicitly free it using the `free()` function.
Failing to free allocated memory can lead to memory leaks, where memory that is no longer needed is not returned to the system.

This is the same ideology used when we open files for example. We don't want the file descriptor,
to be close prematurely so it likely uses malloc under the hood. And then when we are done with the
file we must call close(fd) to free that memory back up. Just as we would use free() for a malloc() call.

It is important to note that manual memory allocation can be avoided. You don't always need to use it
and it's often safer to not use it just because of the potential for bugs that doing
manual memory management can introduce.

It's important to be aware of the types of errors that stem from manual malloc/dealloc...
* "Use After Free" errors
    * Double-free
    * Standard Use-after (referencing freed memory)
* Buffer overflow errors
    * Referencing too much memory than is intended
        - Leads to undefined behavior (accessing random memory)

## Further questions
Memory and storage is referenced above as if it's the same thing.

My questions:
* When running a C program and thinking about memory, am I thinking about RAM,
or storage (SSD/HDD), or the CPU memory?
* Which storage/memory is used in the C programs I write?
* What are the different forms of memory/storage in a computer system (stack, heap, registers, cache, etc..)?
