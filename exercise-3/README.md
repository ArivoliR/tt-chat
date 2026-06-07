# Exercise 3

**Update this README with your answers to the questions below.**

## Re-using Code

- Read the code in `src/tcp_echo_client.cc`
- A new function `check_error()` has been created and `create_socket()` from 
  exercise-2 has been refactored to make use of it
- What are the benefits of writing code in this way?
- Are there any costs to writing code like this?
- Apply `check_error` to all the code in `src/`

### Answers
- Benefits: Code has improved readability and is easier to debug. Also makes the code less likely to have human inconsistencies while coding (since the amount of code is less)
- Function overloads let me add an overload such that I can use check_error that closes a socket (helps in server code)
- Costs: Function call overheads

## Introduction to Compiler Explorer

- Try out the old `create_socket()` and the new `check_error()` and 
  `create_socket()` in [Compiler Explorer](https://godbolt.org) - Interactive 
  tool for exploring how C++ code compiles to assembly
- What is happening here?
- Can you think of any different approaches to this problem?
- How can you modify your Makefile to generate assembly code instead of
  compiled code?
- **Note**: You can save the generated assembly from Compiler Explorer
- **Bonus**: Can you view assembly code using your IDE?
- **Bonus**: How do you see the assembly when you step through each line in
  debugging mode from your IDE?
- [x86 assembly reference](http://ref.x86asm.net/) - Comprehensive reference 
  for x86 assembly language instructions and syntax

### Answers
- In Compiler Explorer, the old `create_socket()` keeps the error handling
  directly inside the function. The new version moves the repeated error check
  into `check_error()`. At `-O0`, the generated assembly can show the extra
  function call because the compiler preserves more structure for debugging.
  At `-O3`, a small helper like `check_error()` will mostly be inlined, so the
  generated code can become very similar.
- Different approaches include using a macro, a lambda, a templated helper,
  exceptions, returning an error value like `std::optional`, or wrapping the
  socket in a small RAII class that closes automatically. For this exercise,
  the simple helper function is the clearest approach.
- To generate assembly from a Makefile, use `-S` so the compiler stops after
  assembly generation. 
- In VS Code you can view assembly through the debugger's disassembly view.
  In GDB, commands like `disassemble` and `layout split` show
  assembly.
- in GDB, `si` steps one instruction 


## More About Memory Management

- Make sure you have `-fsanitize=address` in both your `CXX_FLAGS` and 
  `LD_FLAGS` in your Makefile
- What do `-fsanitize=address`, `CXX_FLAGS` and `LD_FLAGS` mean?
- With the new tool of the Compiler Explorer, and keeping in mind what you 
  have learned about how to use debug mode
- What happens when you look at a `std::string` using the above methods?
- Where is the text in your `std::string`?
- What is `std::optional`?
- How do you find out the memory layout of a `std::optional`?
- Read https://en.cppreference.com/w/cpp/memory#Smart_pointers - Guide to 
  modern C++ memory management using smart pointers
- Which pointer types are the most important to know about?
- Which smart pointer should you use by default if you can?
- Does changing your optimization level in `CXXFLAGS` from `-O0` to `-O3` have
  any impact on the answers to any of the above questions?

### Answers 
- the flag fsanitize=address is for the AddressSanitizer. It catches memory bugs, like double free, use after free etc. 
- CXX flags are used for compiling c++ code. LD flags are used by the linker to link the executable to shared libraries. 
- std::string stores size, capacity and a pointer to a memory region that has characters stored there. 
- std::string sometimes contains the text in the object itself (due to SSO for small strings), but generall it is stored on the heap and the object points to it.
- std::optional<T> is a wrapper that has either no value or T. 
- In gdb, x/32xb &optional_var can be used to inspect bytes or sizeof(std::optional<T?)
- std::unique_ptr -> exclusive ownership
- std::shared_ptr -> shared ownership 
- std::weak_ptr -> non-owning reference to a shared ownership 
- raw pointer -> non-owning access 

- std::unique_ptr should be preferred (unless you need shared ownership)
- Switching from O0 to O3 can make debugging harder since the optimized assembly inlines functions and variables that are present in code, do not necessarily exist outside. 


## More Thinking About Performance

- After your experiments with Compiler Explorer, do you have any updates for
  your answers in exercise-2?

### Answers 
- Maybe inlining a few functions, not really something I realized because of godbolt though!

### Bonus: Do Not Watch Now 

- [More about Compiler Explorer](https://www.youtube.com/watch?v=bSkpMdDe4g4) - 
  Deep dive into compiler optimization and assembly analysis
  - Create a struct which contain many different data types
  - Look at the memory layout in the debugger
  - Create a `char` or `uint8_t` pointer to the beginning of the struct, 
    iterate to the end of the struct, printing out the value of each byte in 
    hexadecimal
  - Try accessing different parts of the struct and see in compiler explorer
    what the assembly looks like
  - What happens if you iterate the pointer to outside the bounds of your
    array?
  - Let's say your struct is called `Foo`
  - What is the difference between `std::vector<Foo>` and `std::vector<Foo*>`?
  - What are the tradeoffs between using `std::vector<Foo>` vs 
    `std::vector<Foo*>`? 
  - Give an example where `std::vector<Foo>` is a better choice than 
    `std::vector<Foo*>`
  - Give another example where the opposite is true
  - Can you create `std::vector<Foo&>`? 
  - Can you create `std::vector<std::optional<Foo>>`?
  - What happens if your struct contains another struct?
  - What is the difference between a struct and a class?
