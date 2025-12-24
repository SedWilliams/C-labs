
# Memory Representation in C

## Intro

Memory in C is closely related to the general format and technique of how computers store and manage data
at the lowest level.

Obviously, the computer stores things in binary at the lowest level (1s and 0s).

But humans do not store 1s and 0s. So it makes sense that like programming languages in general <ins>we create abstractions
or constructs for the purpose of representing binary/memory</ins> in a way that is easier for humans to understand whether in
programming languages or human language.

Thus we arrive at...

## Bits and Bytes

* One bit is one possibility for a 0 or 1.
* One Byte is 8 bits.

The computer itself does not give meaning to any particular orientation of 1s or 0s. It simply recognizes the sequence.
It is the work of humans that gives specific meanings to the 1s and 0s. And that is where the concepts of bits and bytes come in.

<ins>We use bits and bytes to represent different values, and then we use encodings (ASCII, UTF-8, etc.) to represent characters, emojis, etc...</ins>

The way that we group bits into bytes and bytes into larger structures is what gives meaning to the data.

## What is "Memory".

If bits and bytes are values stored in memory, what is memory itself?

<ins>Memory is simply a large, global, array of bytes.</ins> The global aspect gives it the Random Access property
meaning that it is accessible from anywhere in the program at any time.

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
* That process is not automated in C which causes memory unsafety. For example,
when you use the write(int64, int64, n) function, when you pass a value n (which
corresponds to the amount of bytes to increment to) greater than the actual
width of your value then you start pulling memory values from elsewhere in your program.
C's no guardrails approach lets you do this.

OUTDATED:
That single integer the object is referenced with, is
the address at which you can find the first part out of
the whole associated object. Since the rest of the object
is stored sequentially right after the initial pointer
then getting the rest of any associated value is as
simple as iterating through the rest of that value.

The computer stops iterating typically when it reaches
a null terminator value (a byte of all zeroes). Which
stops it from pulling more memory than it should (C will
definitely let you do so, no guardrails). 
