# Exercise 1

**Update this README with your answers to the questions below.**

## How to Approach This Exercise

Before you scroll down to the questions, try this:

1. **Don't peek at the questions yet.** Pretend you've just been handed a brief
   that says: *"Learn these topics as deeply as you can — g++ CLI, Make, Git,
   sockets, and memory management in C++."* That's the whole assignment.
   How would you go about it? What would you read, what would you try, in what
   order, and how would you know when you've understood something well enough?
   Write that plan down in this README, then actually follow it.

2. **Now go through the questions below and answer them like you're an LLM.**
   No live Googling, no Stack Overflow, no asking ChatGPT mid-question. You may
   refer to notes *you* took during step 1 — that's your context window. Answer
   from what you've internalised.

3. **Reflect on how it went.** Honestly:
   - Did your self-directed learning actually prepare you for the questions, or
     did you over-study things that never came up?
   - Which questions blindsided you? Why — was the topic missing from your
     plan, or did you skim past it?
   - Map your experience onto the *known knowns / known unknowns / unknown
     unknowns* idea. The interesting category is usually the last one: things
     you didn't even realise you should have learned. What were yours, and how
     could a better learning plan have surfaced them earlier?

The point of this exercise isn't to get the questions "right" — it's to notice
the gap between how you *think* you learn and how you actually do, so you can
close it.

## Plan to Learn:
Starting off with g++, revising the compiler flags that I already know from my notes. Plan on doing the same for Make, and I'll read the man pages for both as well. I'm pretty confident with my grasp on git so I would normally just look through the commands once (man page mostly). But the brief here says, `as deeply as you can`, so I'll spend some time revising/learning from the first few chapters of the pro git book. For sockets I'll find some reference (Beej Networking guide was mentioned someone so I'll look into that), and look through the material that was provided in notion from Tinkercademy. I'll also read documentation for the socket functions. For memory management there were resources in notion that I already read, I'll skim through them again.

The order would be: g++, make, sockets, memory management, git. I would comfortably assume I've understood something well enough when I'm able to explain it without double guessing myself, and use the concept/command without doubt. Rewriting code or trying commands out from tutorials, helps me. I did that with learncpp to learn c++ as well.

## Learning How to Learn

- Answer the following questions in this file and commit and push your changes.
- Bonus sections are more difficult and optional.
- How can you find the information required to complete these tasks?
- How can you tell if the source of your information is good?
- How would you define "good" in this situation?

#### Answers
- I used to google for references, but recently I've started using perplexity or chatgpt for the same, and it works pretty well. Sometimes when it doesn't or I'm not satisfied, I pivot the searching through google again. Asking an LLM helps because I can ask for suggestions on how to cover which material, and I check if whether it makes sense to do that, and often times its very helpful.
- I usually trust reputed pages, like, say geeksforgeeks, or cppreference, or blogs/videos from reputed authors (like say Herb Sutter for C++). Official documentation sources are always trustworthy.
- One way of looking at it would be, correctness perspective. In which case, official documentation is unbeaten, but it is often not very readable or beginner friendly. Unofficial documentations like cppreference that have a good reputation would be a better alternative for learning.

## Learn Basics of g++ CLI

- Compile the TCP client and server using `g++` from command line.
- What are the most important command line arguments to learn for `g++`?
- What is the difference between debug vs release versions?
- What are the tradeoffs between debug and release versions?
- What arguments would you use in a debug build?
- What about for release?
- What other kinds of build types are useful?

#### Answers
- Compilation done 
- Most important g++ command line arguments are -O, -o, -g, -I.
- -O is used for optimization, -O0, -O1, -O2, -O3, -Og to control the optimization level with -O3 being highest
- -o for setting name of output binary 
- -g for enabling debug symbols, and -I for include path of header files 
- theres also -std= that lets you pick which c++ version to use. 

- Debug version is for development. Generally compiled with debug symbols and zero optimization. Release build is compiled with optimizations and debug symbols are removed. 
- Debug build is a bit slower than the Release build, but in return in debug build, since we have debug symbols, it is easier to to debug any bugs. Code to assembly comparison looks much simpler in debug mode, and it is easy to spot any issues. In release build, the execution is much faster because of compiler optimizations and the file size is also smaller.
- I would use -g to enable debug symbols for debug build. If needed, -Wall and -Wextra to check if there is any unintentional mistake in code. 
- Wall shows common warning messages, and Wextra shows additional warnings on top of -Wall. 
- I would use -O3 to optimize for release build. 
- I've used -ASan (Address sanitizer) in some builds in HPX(an open source org that I contribute to). This build is used to find memory bugs. There's also -Og which optimizes but keeps debug symbols on. 

## Learn Basics of Make

- Create a Makefile that will speed up the process.
- [Quickstart tutorial to make](https://makefiletutorial.com/) - Learn make 
  fundamentals with practical examples and common patterns.
- How else can you learn about make?
- How can you tell if the resource you are using is correct?
- Create a makefile such that when you run `make` with no arguments, it will:
  - Create `build/` directory if it does not exist
  - Create executables **client** and **server** in `build/`, if needed
  - How does make know when it needs to rebuild the executables?
  - Change your Makefile such that `make clean` will remove `build/` and all
    its contents
- What are the most important command line arguments to learn for make?
- What are the most important directives to learn about in Makefile?
- What are the most important commands to implement in your Makefile?
- Which ones are essential, which ones are nice to haves?

#### Answers 
- Makefile done 
- Making our own Makefiles, or reading simple existing ones. The Makefile in the xv6 OS was not too simple and not too hard at the same time. Understanding what that Makefile was doing, helped me learn Make deeply. 
- Like I mentioned earlier, I generally write the examples down on my own and test it. If these work as intended, the resource I'm using is probably right. The website's reputation and author reputation play a role too of course. 

- -n for dry run(shows what would run without executing), -B for force rebuild, -f to choose the Makefile, and -j for speed. (-j4 runs the build with 4 threads). 
- .PHONY, variables, pattern rules, targets are important to learn 
- default target and clean target are the most important commands to implement in Makefile 
- Essentials parts are the default target, clean target, and dependencies. Its nice to have separate debug and release targets, pattern rules etc. 

## Learn Basics of Git

- Read through the code in `src/`
- Answer any `#Questions` as a comment
- Commit and push your changes to git
- Each commit should be responding to a single task or question
- Why is it important to keep your commit to a single task or question?
- Is it better to have a lot of very small commits, or one big commit when 
  everything is working?
- What are the most important commands to know in git?

#### Answers
- It is important to keep each commit to a single task or question because it makes the history easier to understand. This directly helps with debugging bugs and code review. 
- It is better to have small commits instead of one big commit. But there needs to be a balance; a commit for every small change would mean too many commits which again makes the repository history very cluttered and hard to work with. Every commit should have meaning to it. 
- Important commands: git commit, push, pull, diff, status, add, checkout, log

## Introduction to Sockets

- Read the code in `src/tcp-echo-client.cc` and add a way to change the 
  message sent using command line arguments
- **Example**: `./client "hello message from the command prompt"` should send
  `"hello message from the command prompt"` to the server
- Commit your changes into git
- What do all these headers do?
- How do you find out which part of the below code comes from which header?
- How do you change the code so that you are sending messages to servers
  other than localhost?
- How do you change the code to send to a IPv6 address instead of IPv4?
- **Bonus**: How do you change the client code to connect by hostname instead
  of IP address?

#### Answers
- Current issue in server code:
```
➜  build git:(main) ✗ ./server 
Server listening on port 8080
Received: aaaaaaaa
Echo message sent
Received: bbaaaaaa
Echo message sent
^C
➜  build git:(main) ✗ ./client aaaaaaaa
aaaaaaaa
Sent: aaaaaaaa
Received: aaaaaaaa
➜  build git:(main) ✗ ./client bb      
bb
Sent: bb
Received: bb
```
- The server reused the same buffer between reads, a shorter message sent could be attached with leftover characters from the previous message because of that. 
- Fixed in commit "Fix stale buffer handling in TCP server"
- They're used to share code across files through declarations of functions and variables.
- ``<iostream>`` is for input output functions like std::cin and cout. `sys/socket.h` defines socket functions (lie socket(), connect(), send(), etc). `netinet/in.h` contains internet address structures like sockaddr_in and AF_INET. `arpa/inet.h` provides IP address conversion functions.
- One way to do that, is to use `go to definition` shortcuts. In my neovim, that is mapped to the keybind `gd`. In vs-code you can right-click the variable or function name and the option to go to definition will pop up. For a external library, you can look up the man page of the function, and the Synopsis tab will include which header file it is defined in. Example:
`man listen`
```
SYNOPSIS
     #include <sys/socket.h>

     int listen(int socket, int backlog);
```
- This can be done by changning server address to the target servers's IP address. localhost is `127.0.0.1`. 
- To send a IPv6 address instead of IPv4 we should use AF_INET6 and sockaddr_in6 functions. 
- getaddrinfo() can be used to connect by hostname instead of ip address. 


## Introduction to Memory Management

- What is happening in line 26 of `tcp-echo-client.cc`? 
  `if (inet_pton(AF_INET, kServerAddress.c_str(), &address.sin_addr) <= 0) {`
- What is happening in line 31 of `tcp-echo-client.cc`?
  `if (connect(my_sock, (sockaddr *)&address, sizeof(address)) < 0) {`
- What is the difference between a pointer and a reference?
- When is it better to use a pointer?
- When is it better to use a reference?
- What is the difference between `std::string` and a C-style string?
- What type is a C-style string?
- What happens when you iterate a pointer?
- What are the most important safety tips to know when using pointers?

#### Answers
- The function call argument kServerAddress.c_str() is converting the IP address from `std::string` to a C-style string. Not sure exactly what the inet_pton call is doing, but an educated guess would be that it converts the server IP address into network form and stores it in address.sin_addr.
- connect() commands the OS to connect my_sock socket to the server (pointed to by the variable `address`).
- Pointer is a variable that stores a memory address. a reference is another name for an existing variable. 
- It is better to use a pointer when the object can be null, and its useful when working with arrays and buffers etc, since it supports pointer arithmetic. 
- It is better to use a reference when the object must exist and cannot/should not be null. 
- C-style string is a null-terminated character array. std::string is a C++ class that manages string memory. 
- C-style string is char* (generally)
- Iterating a pointer moves it throught memory by the size of the type it points to. For, example, a pointer pointing to an int, when incremented, moves by 4 bytes.
- Initialize pointers before using them; do not use pointers after the object it is pointing to is destroyed.

## Learn Basics of Creating a C++ Project in Your IDE

- How do you compile and run your project in your IDE?

#### Answers 
- I use g++ on the command line to compile, and then use the CLI again to run the binary. 
- Since I'm used to neovim, I do the same with the integrated terminal in vs-code as well.


## Improving Interactions with LLMs

- What is the most authoritative source of information about `socket()`
  from `<sys/socket.h>`?
- What is the most authoritative source of information about the TCP and IP
  protocols?
- What is the most authoritative source of information about the C++
  programming language?
- What information can you find about using Markdown when structuring prompts 
  to LLMs?
- What is the difference between LLM and AI?
- Is it grammatically correct in English to say "a LLM" or "an LLM"? Why?

#### Answers

- the man page the is the most authoritative source of information for socket(). 
- The RFC documents are the most authoritative information about TCP and IP protocols. You can find them by googling. 
- The ISO C++ standard is the most authoritative source of information for C++. cppreference is a useful resource but not an official source. 
- Markdown helps structure the prompt, by giving it headings, sections, code blocks etc, making it easier for LLMs to parse.
- LLM is a specific type of AI, that is focused on generating language. 
- An LLM is grammatically correct. I think it is because of the way it is pronounced, not sure.  
