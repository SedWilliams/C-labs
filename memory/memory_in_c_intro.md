
# How the OS views memory

Understanding how data is represented by the OS is useful for understanding how C views memory.

## Intro

> "Computers are all 1s and 0s." -Many people

The computer stores things at the lowest level in binary. And what is meant by this is that all data input eventually boils down to 1s and 0s because that is the format that is manipulatable by the OS.

But humans do not store nor think about information in binary. So it makes sense that <ins>we create abstractions or constructs for the purpose of representing binary/memory</ins> in a way that is easier for humans to understand (programming languages, apps, networks).

Thus we arrive at...

## Bits and Bytes

* One bit is one possibility for a 0 or 1.
* One Byte is 8 bits.

The computer itself does not give meaning to any particular orientation of 1s or 0s. It simply recognizes them and gives the resources and computation that can be performed on them. It is the work of humans that gives specific meanings to the binary and that tells the computer to perform computations on it. And that is where the concepts of bits and bytes come in.

Bits and bytes are the first form of abstraction that humans use to communicate from binary to human language.

<ins>We use bits and bytes to represent different values, and then we use encodings (ASCII, UTF-8, etc.) to represent characters, emojis, etc...</ins>

The way that we group bits into bytes and bytes into larger structures is what gives meaning to the data.

Basic binary to value process: Binary (bits/bytes) --(encoding)--> Value (int, char, float, etc...)

## What is "Memory".

If bits and bytes are values stored in memory, what is memory itself?

<ins>Memory is simply a large, global, array of bytes.</ins> The global aspect gives it the Random Access property meaning that it is accessible from anywhere in the program at any time.

The different types of memory
* CPU Memory (cache)
* RAM
* Storage memory

