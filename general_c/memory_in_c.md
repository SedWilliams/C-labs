
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

## How C represents Memory and stores values

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

Other types have different bits and bytes (and encodings) associcated with them.



