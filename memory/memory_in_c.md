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

## Further questions

Memory and storage is referenced above as if it's the same thing.

My questions:
* When running a C program and thinking about memory, am I thinking about RAM,
or storage (SSD/HDD), or the CPU memory?
* Which storage/memory is used in the C programs I write?
* What are the different forms of memory/storage in a computer system (stack, heap, registers, cache, etc..)?
