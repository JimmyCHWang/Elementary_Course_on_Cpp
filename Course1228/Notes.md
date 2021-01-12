Agenda

- Recursion
- IO
  - `iostream`
  - Input
  - Output (Optional)
- File IO
  - `freopen()`
  - `ifstream` / `ofstream`

---

## Recursion

I always like this joke of the definition of recursion:

> Recursion: Please refer to [Recursion].

If you don't understand this joke, you might thought it is weird that why some word is referring to itself.

The fact is that the word *Recursion* refers to the behavior that one calls itself. Specifically in programming, it refers to the behavior that one function calls itself within it. For example:

```c++
int factorial(int N) {
    if (N == 0) return 1;
    return N * factorial(N-1);
}
```

The function `factorial()` takes an integer `N`, and it is expected to calculate the factorial of N, i.e. $N!$.

We have the condition that $0!=1$. Thus when N equals to 0, we return the result as 1.

Otherwise, we might not know the result now, but it is possible to get the result if we go a little bit deeper. We know the recurrence of factorial is:
$$
N! = N \times (N-1)!
$$
Thus we could turn the question of "find $N!$" to "find $(N-1)!$". Once we find the latter, we multiply the value $N$ by it and get our result. 

Let's check a graph and see what happened when we want to find `factorial(4)`.

![factorial_call](D:\2020_Fall\Monday_Lesson\Course1228\factorial_call.png)

Although we use recursion to call a function itself for many times, it cannot call itself unconditionally: a good recursion function must have somewhere to **terminate**. (Also called **base case**) Our `factorial()` function would stop recursion once it reaches `f(0)`. The following is a bad recursion function example:

```c++
void infinite() {
    infinite();
}
```

Each time calling the function will occupy some memory, thus it technically could not call infinitely: once the program occupys too much memory, your operating system would "kill" you program. 

This example would also tell you that even your recursion function has somewhere to stop, it still has some limit and your function should not go deeper once all of your resource is used.

Let's check another example of Recursion. We are given an integer array. Let's try finding the maximum number and the minimum number of that array.

Although it is true that using a `for` loop is extremely easy (in fact, the factorial example is the same: using non-recursion version is more straightforward), it is still a good practice to see how recursion works.

We first define the structure we want to use. Our target is a pair of maximum and minimum numbers, so let's create it:

```c++
struct maxmin {
    int max;
    int min;
};
```

Let's introduce our algorithm (*the way to solve a question*) first. This algorithm is somewhat similar to what we called the "binary search" (but different).

We're given an array of integers. That's too long to solve, so I decide to split that array into two. We later calculate the max and min of the first half, and then the max and min of the second half. We could assume that the max of the whole array is the maximum of two maxes from the two halves, similar the min of the whole array is the minimum of two mins from the two halves. Written in pseudocode as:

```
find_maxmin(Array A):
	maxmin left = find_maxmin(left half of A);
	maxmin right = find_maxmin(right half of A);
	int max_of_A = max(left.max, right.max);
	int min_of_A = min(left.min, right.min);
	return {max_of_A, min_of_A};
```

And we should think of our base case. In other words, when does this function ends. We suggest that case is when there's only 1 element in our array. In that case the maximum and the minimum are all itself.

```c++
find_maxmin(Array A):
	if (A has only 1 element) {
        return {A[0], A[0]}; // A[0] is the only element in A
    }
	maxmin left = find_maxmin(left half of A);
	maxmin right = find_maxmin(right half of A);
	int max_of_A = max(left.max, right.max);
	int min_of_A = min(left.min, right.min);
	return {max_of_A, min_of_A};
```

It is fine to create a new array and pass the new one in the next *layer* of recursion. However, that would cost too much memory. A better solution right here is to access the elements *inline*. Inline means we operate on the original array instead of creating copies of the array. The most useful technique of *inline access* is to pass the **indexes** of the original array.

```c++
maxmin find_maxmin (int A[], int l, int r);
```

Therefore we could express the middle of the array as `A[(l+r)/2]`.  Let's call `m = (l+r)/2`. The left half of A is `A[ l .. m ]`, and the right half is `A [ m+1 .. r ]`.

We could also express the length of A as `r-l+1`. If `l==r`, it means the array `A` has only 1 element. Note that the element here is either `a[l]` or `a[r]`, but not `a[0]`.

Wrapping up everything, we could form the following function:

```c++
maxmin find_maxmin (int A[], int l, int r) {
    if (l == r) {
        return {A[l], A[l]}; // A[l] is the only element in A
    }
    int m = (l+r)/2;
    maxmin left = find_maxmin(A, l, m);
	maxmin right = find_maxmin(A, m+1, r);
    int max_of_A = max(left.max, right.max);
	int min_of_A = min(left.min, right.min);
    return {max_of_A, min_of_A};
}
```

---

## IO

The term *IO* or "I/O" is the abbreviation of "Input / output". In modern C++, the IO is based on library `<iostream>`, which defines "input and output *stream*". The term *stream* indicates a sequence of characters waiting to read or write.

C++ provided a few "standard IO streams", and the most frequently used two are `cin` and `cout`. An easy way to understand them is that "You could read characters into your program using `cin`, and write characters to the screen using `cout`".

Let's first talk about input first.

### Input

Input indicates the characters you read from an input device. There are two main ways (as I could think of) to read in C++.

#### cin and >> operator

The `>>` operator is the most straight-forward way to read things, as you've already used for a few times. It is a convenient way to read in numbers and strings (without spaces). The `>>` operator is a *whitespace delimited* formatted input.

```c++
#include<iostream>
#include<string>
using namespace std;

int main() {
	string s;
	int a,b;
	
	cin >> s >> a >> b;
	cout << s << endl;
	cout << a << endl;
	cout << b << endl;
	
	return 0;
}	
```

Example Input:

```c++
George 14 3000
```

Example Output:

```
George
14
3000
```

#### getline

The `getline()` function in C++ is a good way to read a whole line of characters into a `string` object. In other words, `getline()` could help you read all characters until a *line feed* character (`\n`) appeared.

```c++
#include<iostream>
#include<string>
using namespace std;

int main() {
	string s;
		
	getline(cin, s);
    cout << s << endl;
    
    // Let's compare >> and getline()
    cin >> s;
    cout << s << endl;
	return 0;
}	
```

Example Input:

```
Mary has a little lamb
Mary has a little lamb

```

Example Output:

```
Mary has a little lamb
Mary
```

You could use another character as the delimiter (the character that tells you to stop). In that case, you should add a third parameter to `getline()`. For example, `getline(cin, s, ' ')` will stop reading until the first whitespace.

---

Output might be a little more complicated.

### Output (Optional)

Usually when we print out things, we want our results to be *formatted*. That's why for the output, we set a lot of "flags", or just options to print our values in some fancy ways.

![ioflags](D:\2020_Fall\Monday_Lesson\Course1228\ioflags.png)

> Source: https://en.cppreference.com/w/cpp/io/ios_base/flags

Which, I guess, really doesn't make much sense to you and to this class...

**Most of your operations can be done by using the `cout` and `<<` operator. Sometimes `endl` is used when you want to add a line feed ('\n' also works).**

One thing you might want to know is the *precision* (i.e. how many digits are generated) of floating points. The default precision is 6, but you could change that using `cout.precision()`.

When you use `cout.precision()` directly, it returns the current precision. If you put a parameter within the precision, you could set the new precision. Check the following example:

```c++
#include <iostream>
using namespace std;
int main()
{
    const double d = 1.2345678901234;
    cout << "The  default precision is " << cout.precision() << "\n\n";
    cout << "With default precision d is " << d << '\n';
    cout.precision(12);
    cout << "With high    precision d is " << d << '\n';
}
```

> Source: https://en.cppreference.com/w/cpp/io/ios_base/precision

Example Output:

```
The  default precision is 6
 
With default precision d is 1.23457
With high    precision d is 1.23456789012
```

Side note: once you change the formatting, including the precision of a stream, it would keep until you change it again. If you want to restore, you must make a copy of the original stream. You could copy the format using the `copyfmt()` function.

```c++
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    ios state(nullptr);

    cout << "The answer in decimal is: " << 42 << endl;

    state.copyfmt(cout); // save current formatting
    cout << "In hex: 0x" // now load up a bunch of formatting modifiers
        << hex
        << uppercase
        << setw(8)
        << setfill('0')
        << 42            // the actual value we wanted to print out
        << endl;
    cout.copyfmt(state); // restore previous formatting
}
```

---

## File IO

This part provides a small introduction on how to involve files on your disk. Here I provide two different ways.

### freopen()

`freopen()` is inherited from C. It uses something called file pointer, which is a pointer to a file. Although that is something old-fashioned, it has an interesting use in C++ if only one input and output file is involved.

We could use `freopen()` to replace a file with `stdin` or `stdout`. The latter two are file pointers provided in `<cstdio>` that indicates the standard input and standard output. To explain, this way is like my files are hijacking the standard IO.

The way of using `freopen`:

```c++
#include <cstdio>
using namespace std;
int main() {
    freopen("input.txt", "r", stdin); // for input, use "r" and stdin
    freopen("output.txt", "w", stdout); // for output, use "w" and stdout

    string s;
	while (!cin.eof()) { // if the input file is not end
        getline(cin, s);
        cout << s << endl;
    }
    
    // It doesn't matter if you don't write the following two lines, but it is a good habit.
    fclose(stdin);
    fclose(stdout);
    return 0;
}
```

---

### ifstream / ofstream

Similar to `iostream`, we have two different streams for files, `ifstream` for file input and `ofstream` for file output.

You could define an `ifstream` or `ofstream` object and `.open(<file_name>)` and use exactly the same as `cin` and `cout`. Check the following example:

```c++
#include <iostream>
using namespace std;
int main() {
    ifstream fin;
    ofstream fout;
    
    fin.open("input.txt");
    fout.open("output.txt");

    string s;
	while (!fin.eof()) { // if the input file is not end
        getline(fin, s);
        fout << s << endl;
    }
    
    // The following two lines are suggested before your program terminates.
    fin.close();
    fout.close();
    return 0;
}
```

Note, it is possible to combine the definition and open file (using something we called "constructor function").

```c++
ifstream fin ("input.txt");
ofstream fout ("output.txt");
```

---

## Homework

### Question 1. Is this sum possible?

You are given an array of **non-negative** integers, $A$. The array length is $N$.

You are also given a non-negative integer, $target$. Find out if there exists an subarray of $A$, such that the sum of that subarray is the exact same as the number $target$.

Print "True" if there exists such an subarray, otherwise print "False". (print your answer without quotation marks.)

---

#### Input Format

The first line contains two non-negative integers, $N$ and $target$, separated by a whitespace.

The second line contains $N$ non-negative integers, indicating the contents of array $A$.

#### Output Format

"True" or "False", without quotes. Add a *line feed* (`\n`) at the end.

#### Example 1 Input 

```
5 15
3 2 4 8 6
```

#### Example 1 Output

```
True
```

#### Example 1 Explain

$3+2+4+6 = 15$.

#### Example 2 Input

```
5 19
5 2 7 9 6
```

#### Example 2 Output

```
False
```

---

### Question 2. Linked List Preview

一个结构体类型（`struct`）中可以有指针指向同一个结构体类型。举例：

```c++
struct Node {
    int value;
    Node *next;
};
```

这里Node的一个field出现了一个Node指针。这个field叫做"next"。

英语中Node被称作“节点”。每个节点包括一个自身的值，以及指向下一个节点的一个指针。通过这个指针我们可以把若干个节点给“串”起来，这被称作链表（Linked List）。你可以参考下图理解一下。

![LinkedList](D:\2020_Fall\Monday_Lesson\Course1228\LinkedList.png)

你的第二题任务与链表相关。但别紧张……毕竟还没正式学这玩意，我不会让你去造链表或者对链表做什么奇怪的操作。

你的任务是对一个残缺的程序填空。整个程序会完成以下操作：

1. 从"input.txt"中读入若干个整数（数字个数未知，每个整数确保在`int`范围内），用空格隔开。将它们存放在数组里。
2. 将数组转化成链表。
3. 将链表的长度以及链表的每一项输出到"output.txt"里面，但是输出的每一项需要倒序输出。
4. 将链表销毁掉。

你的任务是完成第1步和第3步的操作。对于第3步的输出格式，输出文件的第一行应该为一个整数，表示链表长度；第二行应该包含若干个整数，表示倒序链表里的每一个值，用空格隔开（最后一个数后面可以有空格，也可以没有）。

你可以认为"input.txt"中最多有200个整数。同时，你应该考虑到输入文件中没有整数的情况。（参见Example 2）

#### Example 1 Input (input.txt)

```
8 5 13 6 77 4 2
```

#### Example 1 Output (output.txt)

```
7
2 4 77 6 13 5 8
```

#### Example 2 Input (input.txt)

```

```

#### Example 2 Output (output.txt)

```
0

```

随本讲义附有一份`linklist.cpp`。里面告诉了你可以更改的部分（用`---TASK---`和`-------`包含的部分），除此以外的部分严禁更改。

---

另外，有一个特殊的知识点。当我们有一个表示`struct`的指针时，访问它的元素可以有两种方法。按上面的`Node`举例，我们要访问`Node *s`的`value`：

```
s->value;
*(s).value;
```

这两种方法都是可以的，第一种更加常用一些。在第一种中，我们使用的运算符为`->`；第二种中我们先解引用了指针`s`获得了一个`struct Node`，所以我们可以用上节课介绍过的“点运算符”（`.`）来访问`value`。

但是`s.value`是错误的。因为`s`是一个指针，指针没有`.`运算符的操作。

`->`运算符可以嵌套使用。比如你想访问s的下一个节点的值，可以使用`s->next->value`。其中`s->next`表示下一个节点的指针，之后`->value`表示解引用那个指针的值。

