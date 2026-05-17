# Exercise 2

**Update this README with your answers to the questions below.**

## Sources of Information for Questions from Before

### Socket 
- https://man7.org/linux/man-pages/man2/socket.2.html - System call reference
  for creating communication endpoints
- Or type `man socket` in terminal
- https://man7.org/linux/man-pages/man7/socket.7.html - Socket interface 
  overview and protocol families
- Or type `man 7 socket` in terminal
- When would you want to use a `SOCK_RAW` stream?

#### Answers 
- SOCK_RAM stream is useful when we want low-level control over network packets. Useful when we want to build our own protocols. It is used by tools for network debugging, packet inspection among other use cases.

### TCP and IP Protocols
- [IPv4](https://www.rfc-editor.org/info/rfc791) - Internet Protocol 
  specification defining packet structure and routing
- [IPv6](https://www.rfc-editor.org/info/rfc8200) - Next-generation Internet 
  Protocol with expanded address space
- [TCP](https://datatracker.ietf.org/doc/html/rfc9293) - Transmission Control 
  Protocol providing reliable, ordered data delivery
    
### C++
- [C++23 ISO standard draft](https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2023/n4950.pdf) - 
  Working draft of the C++ language specification
- Is the above the official C++23 spec? 
- Where is the official C++23 spec?
- Why was this link chosen instead?
- Is this a helpful reference for learning C++?
- Can the various implementations of C++ compilers be different from the
  C++ standard?
- What are the most widely used and most significant C++ compilers?
- Where is the equivalent spec for C++26?

- Where do you find the spec for the HTTP protocol?
- What about HTTPS? Is there a spec for that protocol?

#### Answers 
- No this is not the official final spec. It is a public working draft as clearly mentioned in the pdf itself. 
- The official C++23 spec is the ISO C++23 standard.
- The draft link is free, and close enough to be used for references. 
- It is not beginner friendly, since it is written in formal language, but for learning new features of C++23 it is a very good source.
- Yes compiler implementation differ from the C++ standard, due to various reasons like disagreements on the standard itself, and bugs. 
- g++, clang, msvc are some of the most widely used C++ compilers.
- C++26 specs' working draft can be found online in the ISO C++ website itself. 

- From the RFC documents released by IETF. 
- HTTPS is HTTP used with TLS (security layer). There is no separate spec for HTTPS. HTTP RFC and TLS RFC are the specs for HTTPS.



## Introduction to C++ and Sockets Programming

- Read the code in `src/`
- Are there any bugs in this code? 
- What can you do to identify if there are bugs in the code?

## Refactoring: Extract Function

- What is different in this code compared to exercise-1?
- Is this code better or worse than exercise-1?
- What are the tradeoffs compared to exercise-1?
- Are you able to spot any mistakes or inconsistencies in the changes?
  
## Thinking About Performance

- Does writing code this way have any impact on performance?
- What do we mean when we say performance?
- How do we measure performance in a program?

## Play with Git

- There isn't necessarily a single correct answer for how to abstract the 
  code from exercise-1 into functions
- Try different ways to refactor the code from exercise-1 to make it more
  readable.
- Make sure to commit each change as small and self-contained commit
- This will make it easier to revert your code if you need to
- What is `git tag`? How is `git tag` different from `git branch`?
- How can you use `git tag` and `git branch` to make programming easier and
  more fun?

## Learn Basics of Debugging in Your IDE

- How do you enable debug mode in your IDE?
- In debug mode, how do you add a watch?
- In debug mode, how do you add a breakpoint?
- In debug mode, how do you step through code?

### Memory Management and Debug Mode in Your IDE

- How do you see the memory layout of a `std::string` from your IDE debug mode?
- How do you see the memory layout of a struct from your IDE debug mode?


