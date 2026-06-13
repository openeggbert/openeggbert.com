---
title: C++
breadcrumb:
- label: Technologies
  href: Technologies/index.html
- label: Programming languages
  href: Technologies/Programming_languages/index.html
subpages:
- label: Go Up
  href: Technologies/Programming_languages/index.html
- label: History
  href: Technologies/Programming_languages/C++/History/index.html
- label: Versions
  href: Technologies/Programming_languages/C++/Versions/index.html
- label: Key words
  href: Technologies/Programming_languages/C++/Key_words/index.html
---

This article is devoted to collect content about the C++ programming language.

- The goal is to describe all aspects of C++ in a simple form.

C++ is [programming language](Article_does_not_yet_exist_or_link_is_broken/index.html) created in [1985](Article_does_not_yet_exist_or_link_is_broken/index.html)
            by [Bjarne Stroustrup](Article_does_not_yet_exist_or_link_is_broken/index.html).

C++ is based on the C programming language. OOP in C++ was inspired by the Simula67 programming language.
            Almost all C programs are valid C++ programs.

The name of the C++ programming language is related to the incremental operator "++" and was created by Rick
            Mascitti in Summer 1983 and was first used in December 1983.

The C++ predecessor is "[C with Classes](Article_does_not_yet_exist_or_link_is_broken/index.html)", which is an
            extension of the [C](Article_does_not_yet_exist_or_link_is_broken/index.html) programming language created by Bjarne
            Stroustup in [1979](Article_does_not_yet_exist_or_link_is_broken/index.html).

- "C with Classes" introduced [object-oriented programming](Article_does_not_yet_exist_or_link_is_broken/index.html)
                (OOP).
- "C with Classes" maintained the efficiency of C.

**Reason for creation of C++:**

To make the programming easier without the usage or assembler or C or other programming languages.

<br>

<br>

**Advantages:**

- powerful
- high-performance
- it combines the efficiency of low-level programming with the flexibility of high-level abstractions.

**Programming paradigms supported by C++:**

- Procedural - emphasizes algorithms, for big projects
- Object-oriented - emphasizes data, for big projects
- Generic - emphasizes algorithms, for small tasks like sorting or linked lists
- Functional

C++ remains one of the most powerful and versatile programming languages.

- Whether you're developing high-performance applications, working on system-level programming, or
                building scalable software, C++ provides the tools and flexibility needed for success.

**Key Features of C++:**

- **Object-Oriented Programming (OOP):** Supports classes, inheritance, polymorphism, and
                encapsulation.
- **Templates & Generic Programming:** Enables code reusability through function and class templates.
- **Memory Management:** Provides both automatic and manual memory control via **new**,
                **delete**, and smart pointers.
- **Standard Template Library (STL):** Includes data structures, algorithms, and iterators for
                efficient programming.
- **Multithreading Support:** Offers thread management features for concurrent programming.
- **Low-Level Manipulation:** Allows direct interaction with hardware, making it suitable for
                system-level programming.
- **High Performance:** Optimized for speed and resource management, making it ideal for
                performance-critical applications.

**Common Applications of C++:**

- **Game Development:** Used in game engines like Unreal Engine.
- **Operating Systems:** Many operating systems, including parts of Windows and Linux, are built with
                C++.
- **Embedded Systems:** Used in automotive software, IoT devices, and real-time systems.
- **Finance & Trading Systems:** High-frequency trading platforms rely on C++ for low-latency
                execution.
- **Scientific Computing:** Used in applications like MATLAB, CERN software, and physics simulations.

**Modern C++ and Future Trends:**

Modern C++ focuses on improving developer productivity while maintaining backward compatibility. Recent updates
        have introduced

**concepts, coroutines, modules, and ranges**

to simplify development. The future of C++ is
        expected to bring

**better safety, concurrency, and performance enhancements**

, keeping it relevant for
        decades to come.

## Comparison of C++ and C

The following are examples of additional features in C++ compared to C:

- Classes
- Objects
- Inheritance
- Polymorphism
- Virtual functions
- Runtime type identification (RTTI)
- Function overloading
- Reference variables
- Generic programming via the Standard Template Library (STL
- Exceptions
- Namespaces

## How to create a C++ program

creating the C++ source code (text files), compiling to object files, linking object files to an executable
        version of the program.

## File name extensions of C++ source code file

| Implementation of C++ | File name extensions |
| --- | --- |
| UNIX | C, cc, cxx, c |
| GNU C++ | C, cc, cxx, cpp, c++ |
| Microsoft Visual C++ | cpp, cxx, cc |

## Other

How to manage memory automatically: Boehm-Demers-Weiser Garbage Collector

## Functions

C++ program consists of functions. Function consists of statements. Each statement must end with the semicolon
        character.

        Prototype vs implementation.

### Function main()

Function main() is the entrypoint of an C++ application.

**Variants:**

- int main() {return 0;}
- void main() {return 0;}
- void main(void) {return 0;}
- int main(void) {return 0;}

## Console

How to delay program and wait for the press of the key Enter: cin.get();

<br>

Printing text to console: cout << "some text"; //operator overloading: <<

<br>

Reading text from console: cin >> carrots;

<br>

How to print end line: "\n" or std::endl

## Comments

One line: // comment

<br>

Multi line: /* comment */

## Preprocessor directives

### #include <iostream>

Includes file iostream

### #define INT_MAX 32767

Replaces all INT_MAX occurences by 32767

## Importing namespaces

using namespace std;

<br>

using std::count;

## C++ statement

Each C++ statement must be ended with the semicolon character ;

### Declaration (statement type)

This allocates memory.

<br>

Example: int carrots;

### Assignment (statement type)

Example: carrots

15;

### Initialization (statement type)

int carrots

15;

<br>

//or

<br>

int carrots (15);

## Key words

return, void, int, const

        And others

### Constexpr

The constexpr keyword in C++ is used to define constants that are evaluated at compile time, ensuring optimized
        and predictable behavior.

<br>

It can gives performance boost.

## Variable

Variable is named location in the memory with its type definition.

<br>

You can get the location in the memory with the & operator.

## Data types

### Void

Empty set of values, cannot be used as the type of variable.

### Integral

short: at least 16 bits

<br>

int: at least the same size as short (since -32768 until 32 767)

<br>

long: at least 32 bits, at least the same size as int

<br>

long long (since C++ 99): at least 64 bits, at least the same size as long

<br>

unsigned: unsigned short, unsigned int, unsigned long, unsigned long long

<br>

Octal: starts with 0

<br>

Hexadecimal: starts with 0x or 0X

<br>

char

<br>

wchar_t

<br>

bool

#### Floating-point

#### Combined data types

## Operators

### sizeof

## Class

Class is user defined type]

## Integrated development environments for C++

- IDEs for C++
            <li>Visual Studio Community</li>
<li>CLion</li>
<li>Code::Blocks</li>
<li>Eclipse</li>
<li>Netbeans</li>

### Visual Studio

Visual Studio is an integrated development environment developed by the Microsoft company and it is a
        closed-source- and proprietary software.

<br>

For development of Windows Phone 8, 8.1 or 10.0 applications Visual Studio 2015 is used.

<br>

For development of Windows Phone 7, 7.1 applications Visual Studio 2010 or Visual Studio 2012 is used.

## C++ Compilers

External link:

[https://en.wikipedia.org/wiki/Category:C%2B%2B_compilers](https://en.wikipedia.org/wiki/Category:C%2B%2B_compilers)

### Cfront

The first compiler was Cfront created by Bjarne Stroustrup in 1983.

<br>

Cfront converted C++ code into C, but the resulting output was not easily readable or understandable by humans.

- The generated C code was then converted by the C compiler to the machine code.

Later, new C++ compilers were created. These compilers converted C++ directly to the machine code.

### GCC

### Clang

### Microsoft Visual C++

## C++ Decompilers

### Ghidra

**Books:**

[https://www.amazon.com/Ghidra-Book-Definitive-Guide/dp/1718501021](https://www.amazon.com/Ghidra-Book-Definitive-Guide/dp/1718501021)

### IDA

[https://hex-rays.com/decompiler](https://hex-rays.com/decompiler)

## C++ Disassemblers

[https://en.wikipedia.org/wiki/List_of_disassemblers](https://en.wikipedia.org/wiki/List_of_disassemblers)

<br>

[https://en.wikipedia.org/wiki/Disassembler](https://en.wikipedia.org/wiki/Disassembler)

### Ghidra

Ghidra is an Disassembler and Decompiler developed by NSA and later published as a free and opensource software.

### IDA Free

IDA is the free version has the limited set of features

### Objdump

objdump is the part of GNU binutils

#### How to convert a x86 exe file to the Assembly language

`objdump -D -M intel your_file.exe > output.asm`

-D means to disassembly the whole file

<br>

-M intel sets the format of the assembly to Intel

## Steps to Create an Executable Program in C++

1. **Create the C++ source code in any text editor.**<br>

                This step is done by the programmer (human).
2. **Convert the C++ source code to object code (machine language).**<br>

                This step is done by the compiler.
3. **Link the object code with libraries.**<br>

                The result is an executable program. This step is done by the linker.

## History of C++ Standardization

### 1990

The work on the standardization of C++ started in 1990 by ANSI/ISO.

### 1991–1997

During the following years, several working drafts of the C++ standard were published.

### Before 1998

Before official standardization, many people recognized the latest versions of C++ published by Bell Labs as the de facto standard.

### 1998

The first official standard of C++ was published and is known as C++98.

## The Future of C++: 10, 100, and 1000 Years Ahead

### The Next 10 Years: Evolution and Adaptation

In the short term, C++ will continue evolving with regular standard updates every three years. The upcoming
            **C++26** and **C++29** are expected to refine the language further, focusing on:

- **Better safety features:** Improvements in memory safety, possibly integrating Rust-like
                borrow checking mechanisms.
- **Enhanced concurrency:** More efficient multi-threading and parallelism to utilize modern
                hardware architectures.
- **Improved modularity:** Widespread adoption of C++ modules for better compilation speeds
                and cleaner codebases.
- **Integration with AI and ML:** Libraries and language features that optimize C++ for
                artificial intelligence and machine learning applications.
- **More functional programming features:** Expanding features like coroutines and concepts
                to support functional programming paradigms.

### The Next 100 Years: The Role of C++ in a Post-Classical Computing Era

As computing paradigms shift, C++ will need to adapt to entirely new architectures. Some potential
            transformations include:

- **Quantum Computing:** C++ may evolve to support quantum programming models, integrating
                libraries and language features to work alongside quantum processors.
- **AI-Driven Development:** AI-assisted coding tools may redefine how developers interact
                with C++, making manual memory management obsolete through automated optimization techniques.
- **Post-Silicon Computing:** As new materials replace traditional silicon, C++ will likely
                adapt to leverage hardware advances in ways that maintain its performance edge.
- **Universal Compilation:** Future compilers might optimize C++ code in real-time across
                different computing paradigms, ensuring seamless execution on both classical and quantum systems.
- **Self-Optimizing Code:** C++ programs may become self-modifying and self-optimizing, using
                AI to rewrite parts of their own source code to maintain efficiency.

### The Next 1000 Years: The Legacy of C++ in a Post-Human World

Predicting the state of technology 1000 years into the future is speculative, but here are some possibilities
            for C++'s long-term role:

- **Intergalactic Computing:** If humanity colonizes other planets, C++ could be a core
                language for interstellar software, ensuring robust and efficient computing across vast distances.
- **Biological Integration:** C++ may evolve to interact with biological computing systems,
                enabling programming interfaces that communicate directly with synthetic or enhanced human cognition.
- **Post-Human AI Systems:** Advanced AI might continue to use C++ as a foundational language
                for self-replicating and self-evolving software.
- **Timeless Digital Preservation:** C++ could become part of a universal computing standard,
                ensuring that knowledge and legacy software remain readable and executable for thousands of years.
- **Virtual Reality as Reality:** If humanity transitions to a fully simulated or virtual
                existence, C++ (or a descendant language) could be the foundation for simulated universes and AI-driven
                reality models.

#### Conclusion

C++ has continuously adapted over the past 40+ years, and there is no reason to believe it won’t continue
            evolving for the next millennium. Whether through performance optimizations, new computing paradigms, or
            AI-driven development, C++ is poised to remain one of the most influential languages far into the future.
            While it may not exist in its current form in 1000 years, its principles of efficiency, flexibility, and
            control over hardware will likely shape the foundation of future computing.

## Performance Comparison: Reimplementing a 2D Platformer (C++/DirectX 3 to Java/LibGDX)

### 1. Language Differences (C++ vs. Java)

- **C++**: A low-level language offering greater control over hardware and performance optimization. Games written in C++ often run faster due to direct memory and hardware management.
- **Java**: A higher-level language running on the Java Virtual Machine (JVM), introducing an abstraction layer between code and hardware. While modern JVMs (e.g., Java 11 with JIT compilation) reduce performance gaps, there may still be overhead compared to C++.

### 2. Graphics Libraries (DirectX 3 vs. LibGDX)

- **DirectX 3**: An older technology optimized for direct hardware access on 1998-era systems, allowing efficient rendering on limited hardware.
- **LibGDX**: A modern game development framework leveraging OpenGL or Vulkan (depending on the platform) and designed for cross-platform compatibility. While highly optimized, LibGDX may introduce performance overhead on lower-end systems due to JVM and API abstractions.

### 3. Platform Performance

- **C++/DirectX 3**: Specifically tuned for older platforms with close integration to 1990s-era hardware, yielding optimal performance.
- **Java/LibGDX**: Designed for modern platforms and devices, which might result in slight inefficiencies compared to the low-level optimizations available in C++.

### 4. Memory Management

- **C++**: Provides full control over memory allocation and deallocation, allowing developers to optimize performance to the smallest detail.
- **Java**: Utilizes a **Garbage Collector (GC)** for memory management. While modern GCs are highly efficient, frequent allocation/deallocation patterns might introduce latency and occasional performance dips.

### 5. Rendering and FPS

- At the target **20 FPS** with a resolution of **640x480**, this is trivial for modern systems. Both C++ and Java should easily achieve this performance. However, Java may experience slight slowdowns if the code is not carefully optimized due to JVM overhead and less direct access to rendering APIs.

### Conclusion

The performance of a Java/LibGDX implementation may be **slightly worse** than the original C++/DirectX 3 version due to:

- JVM overhead,
- less direct hardware access,
- and potential inefficiencies in library abstractions.

That said, for modern hardware and a well-written Java implementation, the performance difference should be negligible for a simple 2D platformer. Furthermore, the cross-platform support offered by LibGDX is a significant advantage that can outweigh minor performance trade-offs.

## Testing

There are several tools for testing C++ programs:

- Google Test
- Catch2
- Boost Test Library
- CppUnit

## Books

- The Design and Evolution of C++”
