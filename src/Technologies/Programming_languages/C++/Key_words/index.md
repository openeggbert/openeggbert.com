---
title: Key words
breadcrumb:
- label: Technologies
  href: Technologies/index.html
- label: Programming languages
  href: Technologies/Programming_languages/index.html
- label: C++
  href: Technologies/Programming_languages/C++/index.html
- label: Key words
  href: Technologies/Programming_languages/C++/Key_words/index.html
subpages:
- label: Go Up
  href: Technologies/Programming_languages/C++/index.html
---

## Understanding Keywords in C++

Keywords are reserved words in C++ that have a predefined meaning in the language. These words cannot be used as identifiers (like variable names, function names, or class names) because they serve a special purpose within the language’s syntax. C++ is a rich, complex language, and its keywords define the core structure of the language, such as data types, control structures, and object-oriented programming concepts.

In this article, we’ll explore the most important C++ keywords, breaking them down into categories for clarity.

## Complete List of C++ Keywords

The following is a complete list of reserved keywords in the C++ language. These keywords were introduced in C++ and are currently part of the language's syntax. They cannot be used as identifiers (variable names, function names, etc.).

The keywords are divided into groups based on the C++ version in which they were introduced:

- **C++98** (and earlier) contains the keywords available from the beginning.
- **C++11** introduces a significant number of new keywords.
- **C++14** and **C++17** do not introduce any new keywords.
- **C++20** introduces a few new keywords for concepts and coroutines.

### Keywords in C++98 (and earlier)

and, and_eq, asm, auto, bitand, bitor, break, case, catch, char, class, compl, const, const_cast, continue, decltype, default, delete, do, double, dynamic_cast, else, enum, explicit, export, extern, false, float, for, friend, goto, if, inline, int, long, mutable, namespace, new, not, not_eq, operator, or, or_eq, private, protected, public, register, reinterpret_cast, return, short, signed, sizeof, static, static_cast, struct, switch, template, this, throw, true, try, typedef, typeid, typename, union, unsigned, using, virtual, void, volatile, wchar_t, while, xor, xor_eq

### Keywords in C++11

alignas, alignof, auto, constexpr, decltype, delete, nullptr, noexcept, static_assert, thread_local

### Keywords in C++14

No new keywords were introduced in C++14.

### Keywords in C++17

No new keywords were introduced in C++17.

### Keywords in C++20

concept, co_await, co_return, co_yield, requires

### Keywords Introduced in C++23

- **import**: Used to include modules, facilitating better modularity and faster compilation times.
- **module**: Defines a module, a collection of code and data that can be imported by other parts of a program.
- **pre** (anticipated): Expected to be introduced in C++26, likely related to preconditions or similar concepts.
- **post** (anticipated): Also expected in C++26, likely pertaining to postconditions or related features.
- **trivially_relocatable_if_eligible** (anticipated): A proposed keyword for C++26, potentially indicating trivially relocatable types under certain conditions.

### Keywords Introduced in C++26 (Anticipated)

- **hazard_pointer** (anticipated): A proposed feature for lock-free concurrent programming, allowing threads to safely access shared objects.
- **rcu** (anticipated): User-space Read-Copy-Update, a synchronization mechanism aimed at improving performance in multithreaded applications.

## 1. Control Flow Keywords

Control flow keywords help manage the execution flow of programs. These keywords determine how loops, conditionals, and function execution are handled in C++ programs.

### if

Used to make decisions based on conditions.

```
if (x > 0) {
    // do something
}

```

### else

```
if (x > 0) {
    // do something
} else {
    // do something else
}

```

### switch, case, default

```
switch (x) {
    case 1:
        // do something
        break;
    case 2:
        // do something else
        break;
    default:
        // default case
        break;
}

```

### for, while, do

#### for

```
for (int i = 0; i < 10; ++i) {
    // loop body
}

```

#### while

```
while (x < 10) {
    // loop body
}

```

#### do

```
do {
    // loop body
} while (x < 10);

```

### break

```
while (true) {
    if (x == 5) {
        break; // exit the loop
    }
}

```

### continue

```
for (int i = 0; i < 10; ++i) {
    if (i == 5) {
        continue; // skip the rest of the loop when i is 5
    }
}

```

## 2. Data Type Keywords

### int

```
int x = 5;

```

### char

```
char c = 'A';

```

### float, double

```
float f = 3.14f;
double d = 3.14159;

```

### bool

```
bool flag = true;

```

### void

```
void function() {
    // no return value
}

```

## 3. Storage Class Keywords

### static

```
static int count = 0;

```

### extern

```
extern int count;

```

### register

```
register int count;

```

### mutable

```
class MyClass {
public:
    mutable int x;
};

```

## 4. Object-Oriented Programming Keywords

### class

```
class MyClass {
public:
    int x;
    void display() {
        std::cout << x << std::endl;
    }
};

```

### struct

```
struct MyStruct {
    int x;
};

```

### public, private, protected

```
class MyClass {
private:
    int x;
public:
    void setX(int val) {
        x = val;
    }
};

```

### virtual

```
virtual void display();

```

### override

```
void display() override;

```

### new, delete

```
int* p = new int(5);
delete p;

```

### this

```
class MyClass {
public:
    void print() {
        std::cout << this << std::endl;
    }
};

```

### friend

```
class MyClass {
private:
    int x;
public:
    friend void show(MyClass&);
};

```

## 5. Other Keywords

### return

```
return 5;

```

### const

```
const int x = 10;

```

### sizeof

```
std::cout << sizeof(int);

```

### typeid

```
typeid(x).name();

```

### namespace

```
namespace MyNamespace {
    int x = 5;
}

```

### template

```
template <typename T>
T add(T a, T b) {
    return a + b;
}

```

## Conclusion

C++ keywords form the foundation of the language’s syntax and control structures. Understanding these keywords is essential for writing correct and efficient C++ programs. From managing control flow to defining data types and implementing object-oriented principles, the variety of keywords enables a flexible and powerful programming environment. As you continue learning and practicing C++, you’ll encounter more advanced uses of these keywords, including templates, lambda functions, and type inference.
