Agenda

- Compile Process of C++
- Preprocessors
- Header files
- Struct / class
  -  size of types and `sizeof`

---

## Compile Process of C++

First of all, congratulations. After a few lectures, you've already gained the basics of C++. Starting from this lecture, we'll going to cover a few conceptual ideas of C++. Most of this lecture's contents will focus on some "projects", that would involve **multiple files**.

We'll first take a closer look at how does your computer turns your C++ code into executable files, i.e. *exe programs*.

![GCC_CompilationProcess](D:\2020_Fall\Monday_Lesson\Course1221\GCC_CompilationProcess.png)

> Image Source: https://www.cnblogs.com/ericling/articles/11736681.html

Our project goes through 4 steps before it finally build our executable files. The executables are *Executable Machine Code* which are purely 0s and 1s that only the machine can read, and can be executed by the machines.

We first go through the process of *Preprocessing*. The headers and macros (haven't told yet, but in a minute) in our source codes get expanded.

The second step is the real *Compilation*. The compilation creates *assembly code*: a code that is a medium between the advanced programming languages (such as C++) and the machine codes (0s and 1s).

The third step, our assembler does the *assemble* work. The assembler turns our assembly code into machine codes (0s and 1s). Note that even we've already turned them into the machine codes, it doesn't mean they can execute.

The last step, which is linking, finally build up the executable. It links our machine code with other related libraries, and finally generates the exe file.

It might be a little difficult to understand. Theoretically, it doesn't matter if you don't remember or understand this process if you want to turn your C++ code into an executable -- a bunch of IDEs could help you on that.

----

## Preprocessors

Let's back to the *model* I told you at the beginning of the course:

```c++
#include <bits/stdc++.h>

...
```

It is time for us to introduce this strange line staring with `#`. The line is called *file inclusion*, and it can be recognized by the preprocessor.

All lines starting with the `#` sign can be recognized by the preprocessor. The mostly used two commands are `#include` and `#define`.

### #include

The command `#include <library>` and `#inlcude "header"` does the file inclusion. File inclusion is easy to handle collections of `#define` and declarations. This file inclusion line will be *replaced* by the contents in that file.

For example, we have two files of following. The first file is called `header.h`, and the second file is called `my_program.cpp`.

`header.h`:

```c++
#include <cstdio>
#include <cstdlib>
#include <cmath>
```

And we have `my_program.cpp`:

```c++
#include "header.h"

using namespace std;
int main() {
    ...;
}
```

After the preprocessor, the inclusion line in `my_program.cpp` will be replaced by the contents of `header.h`, in other words the following:

```c++
#include <cstdio>
#include <cstdlib>
#include <cmath>
// The line "#include "header.h" " gets replaced by its contents.
using namespace std;
int main() {
    ...;
}
```

The line `#include` will be used when you want to use some functions / declarations in the standard library, or you wrote a large project that has multiple source files / headers to handle. It is the suggested way to tie the declarations together for a large program.

The difference between the quoted include and the `<>` enclosed include is that the quoted one is used when you have some self-defined header files, while the `<>` one is used when you want to use the standard library.

### #define

The command `#define`, sometimes known as a macro, is used for substitution. The format is:

```c++
#define name replacement_text
```

This tells the preprocessor to replace every `name` in the code to `replacement_text`. The `name` in the define shall match the rule of identifier (i.e. it must be an identifier, or looks like a variable). The `replacement_text` is arbitrary, with no restrictions.

Normally the `replacement_text` is the rest of the line. In the case that one line is not enough, you could add a `\` at the end such that the remaining of the line would also be recognized as part of the replacement text.

For example:

```c++
#define ARRAY_LIMIT 1000
int a[ARRAY_LIMIT];
```

The program will replace the `ARRAY_LIMIT` into 1000. If in the following program the `ARRAY_LIMIT` appears again, they would also be replaced by 1000. They are live savers if some numbers (expressions) are used frequently. In fact, that is exactly what the word *macro* means: a shorthand for long expressions.

The macro define could also contain arguments, so the replacement can be different for different calls of the macro. Take an example of a macro version `max`:

```c++
#define max(A, B) ( (A > B) ? A : B )

int x = max(5+3, 4+2);
// Replaced as "int x = ( (5+3 > 4+2) ? 5+3 : 4+2) "
```

Also it is a good habit to add parentheses. Let's see what does the following snipped did wrong:

```c++
#define square(x) x * x

int x = square(3+1);
// Replaced as "int x = 3+1 * 3+1", which is 7 instead of 16, because 1*3 calculates first.
```

Side note: names could be undefined using `#undef`. Once you no longer need a macro, you could undefine it.

```c++
#define ARRAY_LIMIT 1000
int a[ARRAY_LIMIT];
...
#undef ARRAY_LIMIT
// Starting here, the ARRAY_LIMIT is no longer available.
int b[ARRAY_LIMIT]; // This will cause an compile error, since ARRAY_LIMIT is already undefined.
```

---

## Header Files

OK, here we finally come to the topic of header files. I've mentioned a few times of this word, but didn't introduce it until now. You finished all of your projects in a single file. However, as I already mentioned above, it is clearly possible to separate your program into different files. For large projects, it is a good habit to separate your different functions / structures / definitions into multiple files.

The idea of a header file is that it contains the definitions of some shared functions / structures. Header files contain the definitions only (i.e. no real codes or implementations). Remember the *function pre-declaration*? You could define a function first and implement that function later. What if two of your files want to use a same function or a same definition? It would be annoying if you have to copy your implementation twice or trying to include a source code (i.e. "\*.cpp" file), as it would increase your code scale. The best solution we found is to include the shared definitions only, written in the "\*.h" files, while put the implementations of those function definitions into different "\*.cpp" files. Check the example project in the same folder with this notes file. **Read "README.txt" first!**

For single file projects (i.e. all contents in one file), you could ignore the using of headers. As a result, you only need to understand & remember this part, since most of the questions and homework I provided to you require only 1 ".cpp" file.

---

## Struct / Class

You could self-define some structures in C++. The term *structure* is inherited from C, and its keyword is `struct`.

**Simply put, a `struct` could pack up some variables into a new type.** Let's see an example:

```c++
struct point2d {
    int x;
    int y;
}
```

Now you pack up two `int` variables into a new structure called `point2d`. Each variable is called a member of this struct (sometimes called a field, they mean the same). 

You could declare an object of `point2d` and use its contents as the following example shows you.

```c++
// Include <bits/stdc++.h> and the struct upon. Structs need to be declared before use. Unlike functions, there are no pre-declarations for structs.

int main() {
    struct point2d P;
    P.x = 10; // Access a member using the operator '.'
    P.y = 5;
    cout << sqrt((P.x * P.x) + (P.y * P.y)) << endl;
}
```

It is also possible to assign the values quickly when declaring an object:

```c++
struct point2d P {10, 5};
/*
	This has the exact same affect as line 4~6 of the previous snippet.
*/
```

As it is a new type, it is also possible to return such a type in a function:

```c++
struct point2d mirrored_point(struct point2d P) {
    return {P.y, P.x};
}

int main() {
    struct point2d pt {5, 8};
    struct point2d mirrored = mirrored_point(pt);
}
```

You could use the variables within a struct just as normal variables:

```c++
struct point2d pt {5, 8}; //pt.x = 5, pt.y = 8
pt.x += 10; //pt.x = 15;
```

You might notice that there are too many `struct` in the previous examples. Actually that is a feature from C, and people are really annoying about this - that's why in C++ you only need to write `struct` in the definition, and you could omit all `struct`s afterwards.

It is also possible to have a struct within a struct, or an array of structs.

```c++
struct circle {
    point2d center; // point2d is the struct above
    int radius;
}

circle Circles[100];
```

Because a struct is a new type, it also have a size. I didn't talk much about the size of types when I first introduced them, so let's talk about the size.

### Size of types, `sizeof`

We have different types for integers, such as `int`, `long`, `short`, `long long`, `undefined`, etc. They could store different numbers, so it is not surprising that they have different memory cost. To be honest, the size of each type is really dependent on the compiler specifications: meaning that the compiler defines that. Right now, we usually set the size of an `int` variable is **4 bytes** (=32 bits). To check the size of a type, you could use `sizeof( <typename> )` to find its size (in units of bytes).

```c++
int main() {
    cout << sizeof(int) << endl; 
    // check how many bytes of memory is required in order to store an int variable
}
```

Typically, the size of a struct is the sum of the size of all its members, but not always. We can only say that the size of a struct will be *at least* as large as the size of all the variables it contains. This is related to the data alignment in memory, and is (usually) not required to understand.

---

Another feature that is introduced in C++ is `class`. Class is somewhat a much more powerful (and more secure) struct. I might go back and introduce `class` if we have time to talk about Object Oriented Programming, but right now, `struct` is enough for use.

## Homework

### TBD



