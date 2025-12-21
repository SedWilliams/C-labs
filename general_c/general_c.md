
# General C Notes

## History

C was developed in the early 1970's by Dennis Ritchie and Ken Thompson.

It was intended to be a systems language to develop the Unix (at the time Unics) operating system.

Since then it has become the best-in-slot language for computing problems where speed is of the most importance.

## Features and design

### How is C so fast?
C gets its speed from the fact that it is one abstraction above machine binary. When compiled, it is made directly into machine code.
This is the lowest abstraction from any programming language and therefore makes C the fastest. Since C is just an abstraction
above machine code, it's only bottlenecks are typically programmer error and speed of the machine. It is quite literally
impossible for other systems languages to be as fast as C for those exact reasons, and therefore the tradeoff you are taking
by using a language like Rust, Zig, or Jai instead of C is ergonomics for slightly slower code.

### Features of the language itself?
* Leaves unspecified behavior up to the programmer.
* minimal guardrails even if it means lack of safety.

