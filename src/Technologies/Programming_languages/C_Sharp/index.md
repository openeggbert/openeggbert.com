---
title: C Sharp
breadcrumb:
- label: Technologies
  href: Technologies/index.html
- label: Programming languages
  href: Technologies/Programming_languages/index.html
subpages:
- label: Go Up
  href: Technologies/Programming_languages/index.html
---

> **Note:**
> 
>  The correct title of this article is 
> 
> **C#**
> 
> . The substitution of
>             the 
> 
> **#**
> 
>  symbol is due to technical limitations.
>

## What is C#?

**C#** (pronounced "C-sharp") is a modern, general-purpose, high-level programming language
            developed by Microsoft. It supports multiple programming paradigms, including object-oriented, functional,
            and component-oriented programming.

- Designed for productivity, safety, and strong software engineering principles.
- Has a syntax and design philosophy similar to Java.
- Invented by **Anders Hejlsberg**, along with **Scott Wiltamuth** and **Peter
                Golde**.
- First released in **2000** as part of Microsoft’s .NET initiative.
- Continually evolving, with each new version adding powerful features like LINQ, async/await, pattern
                matching, and records.
- Official documentation: [learn.microsoft.com/dotnet/csharp](https://learn.microsoft.com/en-us/dotnet/csharp/)

## C# Runtimes

C# code requires a runtime environment to execute. These runtimes provide services such as memory management,
            just-in-time compilation, and exception handling.

- **.NET Framework:** The original runtime for C#, now discontinued. It was Windows-only and
                closed-source.
- **Mono:** An open-source, cross-platform C# compiler and runtime, started in 2004 to bring
                .NET to Linux and mobile devices.
- **.NET Core / .NET:** A modern, open-source, cross-platform runtime developed by Microsoft.
                Initially called .NET Core (2016), the platform was unified under the ".NET" name starting from .NET 5
                in 2020.

## C# in the Web Browser

Several projects allow C# to run inside web browsers using transpilation or WebAssembly:

- **Bridge.NET:** Converts C# code into JavaScript.
- **CSHTML5:** Converts C# and XAML into HTML5/JavaScript.
- **Blazor:** A Microsoft framework that allows C# code to run in the browser via
                WebAssembly. [Blazor
                    official site](https://dotnet.microsoft.com/en-us/apps/aspnet/web-apps/blazor)

## C# in Speedy Blupi for Windows Phone

The Windows Phone version of **Speedy Blupi** was written in **C# 4.0**, though
            not all language features were used. C# 4.0 was released in 2010, three years before the game launched.

## Popular C# Decompilers

Decompilers allow developers to inspect compiled .NET assemblies (typically in IL - Intermediate Language)
            and convert them back to readable C# code.

### DnSpy

A powerful .NET debugger and decompiler, now maintained as a community project.<br>
 [GitHub: dnSpyEx/dnSpy](https://github.com/dnSpyEx/dnSpy)

### ILSpy

An open-source .NET decompiler with support for metadata inspection and PDF export.<br>
 [GitHub: ICSharpCode/ILSpy](https://github.com/icsharpcode/ILSpy)

### Telerik JustDecompile

A once-popular C# decompiler from Telerik. It has since been discontinued.<br>
 [Archived site](https://www.telerik.com/products/decompiler.aspx)

## Recommended C# Books

- *Programming C# 4.0* by Ian Griffiths
- *C# 4.0 in a Nutshell* by Joseph Albahari & Ben Albahari
- *Pro C# 2010 and the .NET 4 Platform* by Andrew Troelsen
- *Essential C# 4.0* by Mark Michaelis

## .NET Compact Framework 4.0

The **.NET Compact Framework 4.0** is a streamlined version of the full .NET Framework designed
            for embedded systems and mobile devices with limited resources.

### Key Differences from Full .NET Framework:

1. **Target Platforms:**<br>
 .NET CF targets mobile devices and embedded systems (e.g.,
                Windows Mobile, PDAs), whereas the full .NET Framework targets desktops and servers.
2. **Size and Optimization:**<br>
 .NET CF is significantly smaller and optimized for devices
                with limited RAM, storage, and CPU power.
3. **API Coverage:**<br>
 .NET CF includes only a subset of the full .NET libraries. Notably:
  - No WPF (Windows Presentation Foundation)
  - Limited WCF (Windows Communication Foundation) support
  - Partial support for ADO.NET and other advanced features
4. **Garbage Collection:**<br>
 GC in .NET CF is designed to be lighter and more
                memory-efficient, though it may result in different performance characteristics than desktop GC.
5. **UI Support:**<br>
 Uses basic Windows Forms. WPF is not supported due to hardware
                limitations.
6. **Performance:**<br>
 Optimized for fast startup and low resource consumption. Code must be
                written with memory and CPU usage in mind.
7. **Portability:**<br>
 Applications built for .NET CF are not compatible with the full .NET
                Framework without modification.
8. **Development Tools:**<br>
 Visual Studio (up to 2010) with specific templates is required.
                Support has been phased out in modern development environments.

### Summary:

- **.NET CF** is a specialized version of the .NET Framework, ideal for older mobile and
                embedded systems.
- **.NET Framework** is for full-featured desktop and server applications.
- Modern development for mobile now typically uses **.NET MAUI** or **Xamarin**,
                which have superseded .NET CF.

## Running C Sharp code in web browser

### Blazor

Blazor is

[open source](Article_does_not_yet_exist_or_link_is_broken/index.html)

web framework, which can compiles

[C#](Article_does_not_yet_exist_or_link_is_broken/index.html)

to

[WASM](Article_does_not_yet_exist_or_link_is_broken/index.html)

and then it can run in a

[web browser](Article_does_not_yet_exist_or_link_is_broken/index.html)

.

#### External links

- [https://en.wikipedia.org/wiki/Blazor](https://en.wikipedia.org/wiki/Blazor)

### Bridge.NET

Bridge.NET is a open source C# to JavaScript Compiler.

<br>

**Official website (dead link):**

[http://bridge.net](http://bridge.net)

Archived at:

[https://web.archive.org/web/20210502211824/https://bridge.net/](https://web.archive.org/web/20210502211824/https://bridge.net/)

<br>

Bridge.NET is no more under active development.

<br>

There is a fork of Bridge.NET named H5. Its Github repository is:

[https://github.com/curiosity-ai/h5](https://github.com/curiosity-ai/h5)

### JSIL

JSIL is a compiler that converts .NET applications and libraries from CIL bytecode into standards-compliant
        JavaScript, which can run in any modern browser or JavaScript runtime. Unlike other JavaScript cross-compilers,
        JSIL generates JavaScript that is easy to debug while preserving the original .NET code's behavior and
        structure. Supporting most .NET-based languages, it works seamlessly with C# and VB.NET, with partial support
        for F#. The compiler handles nearly all .NET runtime features, including pointers and P/Invoke, and can
        translate most of the open-source Base Class Library (BCL).

## Comparison of C Sharp and Java

C# and Java are similar programming languages, but have some differences.

### Structures in C# vs. Classes in Java

- In C#, struct is a value type, meaning it gets copied when assigned or passed to a method.
- In Java, there are no structures—only classes, which are always reference types.

#### Solution:

- Replace struct in C# with a class in Java. Remember that Java classes behave as references, so they won’t be copied automatically.
- If you need value-type behavior, implement a copy method (e.g., clone() or a copy constructor).

```
public class MyStruct {
   private int value;
   public MyStruct(int value) {
       this.value = value;
   }
   public MyStruct copy() { // Copy method
       return new MyStruct(this.value);
   }
   public int getValue() {
       return value;
   }
   public void setValue(int value) {
       this.value = value;
   }
}

```

### Handling References

- In **C#**, you can use `ref` or `out` to pass variables by reference, allowing methods to modify their values.
- In **Java**, there’s no equivalent feature, but you can achieve similar functionality using wrappers.

**Solution:**

- Define a simple wrapper class:

```
public class Ref<T> {
   public T value;
   public Ref(T value) {
       this.value = value;
   }
}

```

- Use the wrapper to mimic ref behavior:

```
public static void modifyValue(Ref<Integer> ref) {
       ref.value += 10;
   }
   public static void main(String[] args) {
       Ref<Integer> myValue = new Ref<>(5);
       modifyValue(myValue);
       System.out.println(myValue.value);  // Output: 15
   }

```

### Object Properties

- **C#** supports properties for classes and structs with automatic `get` and `set` accessors:

```
public int Value { get; set; }
```

- **Java** uses explicit getter and setter methods:

To convert C# code to Java: Convert properties to methods

```
public class MyStruct {
       private int value;
       public int getValue() {
           return value;
       }
       public void setValue(int value) {
           this.value = value;
       }
   }

```

### Delegates and Events

#### C# has delegates and events for callbacks:

```
public delegate void MyDelegate(string message);
public event MyDelegate MyEvent;

```

#### Java doesn’t have delegates. Use interfaces or lambdas instead:

```
public interface MyEventListener {
   void onEvent();
}
public class MyClass {
   private List<MyEventListener> listeners = new ArrayList<>();
   public void addListener(MyEventListener listener) {
       listeners.add(listener);
   }
   public void fireEvent() {
       for (MyEventListener listener : listeners) {
           listener.onEvent();
       }
   }
}

```

### Nullable Value Types

#### C# supports nullable value types with Nullable<T> or the ? syntax:

```
int? nullableInt = null;
```

#### Java uses wrapper classes like Integer for nullability:

```
Integer nullableInt = null;
```

### LINQ

#### LINQ in C# provides powerful querying and data manipulation:

```
var filtered = myList.Where(x => x > 10).ToList();
```

#### In Java, use the Stream API:

```
List<Integer> filtered = myList.stream()
                              .filter(x -> x > 10)
                              .collect(Collectors.toList());

```

### Operator Overloading

#### C# supports operator overloading:

```
public static MyClass operator +(MyClass a, MyClass b) {
   return new MyClass(a.Value + b.Value);
}

```

#### Java does not. Use methods instead:

```
public MyClass add(MyClass other) {
   return new MyClass(this.value + other.value);
}

```

### Using Statement

#### C# has the using statement for automatic resource management:

```
using (var stream = new FileStream("file.txt")) {
   // ...
}

```

#### Java uses try-with-resources:

```
try (FileInputStream stream = new FileInputStream("file.txt")) {
   // ...
}

```

### Static Classes

#### C# allows static classes:

```
public static class MyUtils {
   public static int Add(int a, int b) => a + b;
}

```

#### In Java, use a class with private constructors and static methods:

```
public class MyUtils {
   private MyUtils() {}
   public static int add(int a, int b) {
       return a + b;
   }
}

```

### Namespaces vs. Packages

#### C# uses namespace for code organization:

```
namespace MyApp.Utilities {
   public class MyClass { }
}

```

#### Java uses package and requires a matching directory structure:

```
package myapp.utilities;
public class MyClass { }

```

### Enums

#### C# enums can have explicit values:

```
public enum Color {
   Red = 1,
   Green = 2,
   Blue = 3
}

```

#### Java enums do not support explicit values directly:

```
public enum Color {
   RED, GREEN, BLUE
}

```

### Interfaces and Default Methods

#### C# supports default implementations in interfaces:

```
public interface IMyInterface {
   void DoSomething() => Console.WriteLine("Default implementation");
}

```

#### Java also supports default methods, but only from Java 8 onward:

```
public interface MyInterface {
   default void doSomething() {
       System.out.println("Default implementation");
   }
}

```

### String Interpolation

#### C# supports string interpolation:

```
string message = $"Hello, {name}!";
```

#### In Java, use String.format or concatenation:

```
String message = String.format("Hello, %s!", name);
```

### Exceptions

C# does not distinguish between checked and unchecked exceptions.

Java requires checked exceptions (IOException, SQLException, etc.) to be handled or declared with throws.

### Dynamic Typing

C# supports dynamic typing with the dynamic keyword.

Java does not have a direct equivalent. Use reflection or Object.

### Definition of multidimensional array

C#: `int [1,2]`

Java: `int[1][2]`

## MAUI

.NET MAUI is cross-platform framework used to create C# apps with graphical user interface.

<br>

MAUI supports Windows, MacOS, Android, iOS (but not Linux).

## External links

**Official website:**

[http://jsil.org/](http://jsil.org/)

## Roslyn

Roslyn is .Net compiler, which also provides C# classes to analyse C# source code.

<br>

**Github:**

[https://github.com/dotnet/roslyn](https://github.com/dotnet/roslyn)
