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

#### Answers
- Yes there are a few bugs that I can notice in this code. 
- Code does not check the return value of send(), we do not know if the full message was actually sent because of that. 
- The client and server print the data received as C-style strings, but there is no null termination guarantee, can lead to Information leaks through buffer overflow attack. 
- Edge case testing, running binary compiled with -Wall -WExtra, using gdb can be done to identify bugs in the code. 

## Refactoring: Extract Function

- What is different in this code compared to exercise-1?
- Is this code better or worse than exercise-1?
- What are the tradeoffs compared to exercise-1?
- Are you able to spot any mistakes or inconsistencies in the changes?

#### Answers 
- The code in exercise 2 is more readable than exercise 1
- There are more functions, and each function has its own reason to exist 
- exercise 2's code is better for readability
- The tradeoff is the lack of continuity in code since now we have to goto different functions to understand the program flow.
- As mentioned in the previous section, I think the server and client printing th recieved data as a C-style string, even though read() doesn't terminate to nullbytes. It the is common case of buffer overflow. 


## Thinking About Performance

- Does writing code this way have any impact on performance?
- What do we mean when we say performance?
- How do we measure performance in a program?

#### Answers
- Since there are more functions now, their calls will add a small overhead.
- A program's performance is how efficiently it can compute its task in the given environment. 
- Performance is measured by timing, measurnig memory usage, cpu usage, latency, using profiling tools, throughput, scalability. 
- To compare performance of exercise 1 and 2 important factors would be, latency (how long a request takes), memory usage, throughput (how many requests the server can handle in a second)
- Did a simple benchmark for comparing latency and the results are:
```
exercise-1: 10000 requests, 17257.29 ms total, 1.726 ms/request
exercise-2: 10000 requests, 17451.49 ms total, 1.745 ms/request
```
- This shows us that performance in terms of latency for both programs is almost the same, since the logic behind them is no different. I ran this test a few times, similar results. Proves my first point that exercise-2 code will have a small overhead from the function calls :)

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

#### Answers
- git tag is a name attached to a marked commit (generally important for some specific reason)
- git branch is different since it is the name of the current state of the codebase, and it keeps changing as more additions come to it.
- tags stick to the commit that was marked, and can be used as points to revert to incase some additions or changes to the codebase go south 
- We can use tags and branches to keep track of specific versions of the codebase that we want to come back to, both for reference, and in-case of issues that might want us to revert back to the older version
- This gives us more freedom to play with the codebase, experiment complex changes, huge refactors and so on, without losing any previous progress.

## Learn Basics of Debugging in Your IDE

- How do you enable debug mode in your IDE?
- In debug mode, how do you add a watch?
- In debug mode, how do you add a breakpoint?
- In debug mode, how do you step through code?

#### Answers
- Debug configuration in the IDE with debug symbols enabled and either -O0 or -Og optimization level. 
- vs code, In the debug session, right click variable -> then add to watch. 
- watch \<expression\> on gdb for the same
- b* addr on gdb, clicking next to line number on vs code and f9 or right click line and add breakpoint 
- in gdb (with tui), ni for next instruction, c for continue (stops at breakpoint)
- in vs code, we can click the buttons in the toolbar (step into F11, step over F10, step out Shift+F11)


### Memory Management and Debug Mode in Your IDE

- How do you see the memory layout of a `std::string` from your IDE debug mode?
- How do you see the memory layout of a struct from your IDE debug mode?

#### Answers 
- After compiling in debug mode, set breakpoint after string is created, look at the variables to inspect `std::string` and use the memory view option to examine the address of the string object. I right click the variable and click go to memory to get the address. In gdb, I do x/s &varstr or x/16xb &varstr for string output and hex output.
- Same for struct, compile in debug mode, right click the struct, click go to memory to find struct's address. View the struct members by right clicking struct variable and watching it. For direct memory layout- x/32xb struct

```
#include <iostream>
#include <string>

struct Student {
  int age;
  char grade;
};

int main() {
  std::string str = "hello";

  Student s{20, 'A'};

  std::cout << str << "\n";
  std::cout << s.age << " " << s.grade << " " << "\n";

  return 0;
}
```
`set breakpoint at return 0 (disas main to find address)`
```
(gdb) x/32xb &s
0x7fffffffda28:	0x14	0x00	0x00	0x00	0x41	0x7f	0x00	0x00
0x7fffffffda30:	0x40	0xda	0xff	0xff	0xff	0x7f	0x00	0x00
0x7fffffffda38:	0x05	0x00	0x00	0x00	0x00	0x00	0x00	0x00
0x7fffffffda40:	0x68	0x65	0x6c	0x6c	0x6f	0x00	0x00	0x00
(gdb) x/32xb &str
0x7fffffffda30:	0x40	0xda	0xff	0xff	0xff	0x7f	0x00	0x00
0x7fffffffda38:	0x05	0x00	0x00	0x00	0x00	0x00	0x00	0x00
0x7fffffffda40:	0x68	0x65	0x6c	0x6c	0x6f	0x00	0x00	0x00
0x7fffffffda48:	0x2f	0x7c	0x8a	0xf7	0xff	0x7f	0x00	0x00
(gdb) x/s str.c_str()
0x7fffffffda40:	"hello"
(gdb) x/1xb &s.grade
0x7fffffffda2c:	0x41
(gdb) p s.grade
$1 = 65 'A'

```
