
# Memory Representation in C

## Intro

Memory in C is closely related to the general format and technique of how computers store and manage data
at the lowest level.

Obviously, the computer stores things in binary at the lowest level (1s and 0s).

But humans do not store 1s and 0s. So it makes sense that like programming languages in general <u>we create abstractions
or constructs for the purpose of representing binary/memory</u> in a way that is easier for humans to understand whether in
programming languages or human language.

Thus we arrive at...

## Bits and Bytes

* One bit is one possibility for a 0 or 1.
* One Byte is 8 bits.

The computer itself does not give meaning to any particular orientation of 1s or 0s. It simply recognizes the sequence.
It is the work of humans that gives specific meanings to the 1s and 0s. And that is where the concepts of bits and bytes come in.

<u>We use bits and bytes to represent different values, and then we use encodings (ASCII, UTF-8, etc.) to represent characters, emojis, etc...</u>

The way that we group bits into bytes and bytes into larger structures is what gives meaning to the data.

