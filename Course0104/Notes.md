Agenda

- Memory & Dynamic Allocation
  - Data Layout
  - Dynamic Memory Allocation (Heap Memory)
- Bitwise Operators
- Scope

---

## Memory & Dynamic Allocation

From our course 12/14, we know that we store data in memory, and the memory is a sequence of space for us to store bits of 0s and 1s. We could access the spaces using *memory address*. The address is a number.

Today we are going to take a deeper look at memory. Let's check the "data layout" first. This image shows you which piece of data is stored in where in the memory.

### Data Layout

![memoryLayoutC](D:\2020_Fall\Monday_Lesson\Course0104\memoryLayoutC.jpg)

> Source: https://www.geeksforgeeks.org/memory-layout-of-c-program/

Assume our data is placed in such a straight line. The memory with low addresses (i.e. small number addresses) are at the bottom, while the high addresses are at the top.

Starting from the small address, the first block is the memory for "instruction", i.e. your program codes. These codes are in machine codes (0s and 1s), not in C++, as we stated in the "compile process" notes.

The second block is called the "data segment". It is usually split into two parts, one is initialized, another is uninitialized. This part is for storing some global variables and static variables declared by the programmer. Sometimes also called "static memory".

The third block is called the "heap memory". It doesn't have a definite border, and can grow during the execution. In the times of C, when programmers want some memory but don't know the exact size until some input is given, or if the memory wasn't that large enough to declare everything in static memory, they will *dynamically allocate* some memory. This is called a heap memory. More to come in the next few chapters.

The fourth block is called the "stack memory". Similar to heap, it can grow during the execution, but **the growing direction is different**. Stack memory grows from high address to low address, while the heap memory grows the opposite direction. The stack memory is related to function calls. When you call some function, the program stores your temporary variables, function parameters, and return address into the stack.

### Dynamic Allocated Memory

Not sure if you've checked the homework last week. I gave a question about "linked list". To create a linked list, I used the following function:

```c++
// Just for convenience, following is the Node struct: 
struct Node {
	int value;
	Node *next;
};

Node *create_linkedlist(int *arr, int size) {
	if (size <= 0) return NULL;
	Node *head = (Node*) malloc(sizeof(struct Node));
	Node *curr = head;
	for (int i = 0; i < size-1; i++) {
		curr->value = arr[i];
		curr->next = (Node*) malloc(sizeof(struct Node));
		curr = curr->next;
	}
	curr->value = arr[size-1];
	curr->next = NULL;
	return head;	
}
```

I made a notification about "`->`" is an operator used for accessing a field of a struct that is pointed by some pointer. As a result, the only thing that might feel unfamiliar is the `malloc()` function here. In fact, this is exactly the way to allocate some memory during the execution.

The function `malloc()` is abbreviated from "**m**emory **alloc**ation". It allocates a piece of memory from the "heap memory" (i.e. heap grows). The size of growth equals to the number within the parameter (units in bytes).

```c++
// Generic:
void *ptr = malloc (/* bytes of memory want to alloc */);

// Example:
int *ptr_int = (int *) malloc(sizeof int);
```

Use explicit type conversion to convert your memory into the corresponding type.

Once you finished using this part of memory, you *should* return that part. This is called *deallocation*, or the jargon is *free* the memory.

Let's check the free process in that linked list program:

```c++
void destruct_linkedlist(Node *head) {
	if (head == NULL) return;
	Node *next = head->next;
	free(head);
	destruct_linkedlist(next);
	return;
}
```

You use `free()` with a pointer with corresponding type, you could free that part of memory.

## Bitwise Operators (Optional)

As the course is almost finished (about 2 weeks to go), let's talk about some miscellaneous things. This part is optional.

Let's talk about bitwise operators. Specifically: `&`, `|`, `~`, and `^`.

You might have notice the logical AND, OR operators are `&&` and `||`. Why we need to repeat those characters twice? Because we have some operators called bitwise AND and bitwise OR (also bitwise NOT). 

### bitwise AND (&)

The operator `&` is quite busy. In pointers, we introduced this operator is used for getting the address of an object (i.e. find the reference of that object). That is used for a "unary" operator, meaning it applies on a single variable / object.

`&` could also use as a binary operator, when applying to two integers. The bitwise `&` calculates the AND result of two integers. How? We turn these two integers into binary forms, and calculate the AND result of each bit, as the following image shows:

![BitwiseAnd](D:\2020_Fall\Monday_Lesson\Course0104\BitwiseAnd.png)

Only when the two bits in both number is 1, the bit in the result is 1. Otherwise the result is 0. The term *bitwise* means to calculate *bit by bit*.

You might argue: what could that help us? Well... sometimes they do, in embedded systems where memory is somewhat limited. Think of this, a 32-bit integer, if we use each of its bit as a switch (or like a `boolean` flag), we could have 32 switches. This saves a lot from 32 boolean variables (which costs 32 * 4 bytes). Nevertheless, these bitwise operators are seldom used now, unless for special purposes.

### bitwise OR ( | ), NOT (~), XOR (^)

Similar to bitwise AND, bitwise OR means to calculate OR bit by bit.

![BitwiseOr](D:\2020_Fall\Monday_Lesson\Course0104\BitwiseOr.png)

And bitwise NOT is a unary operator (same as logical NOT `!`), which flips every bit of a number.

![BitwiseNot](D:\2020_Fall\Monday_Lesson\Course0104\BitwiseNot.png)

You might notice that the number upon is 183, but also a `(-75)` next to it. This is because of the "two's complement" numbering system we use to represent numbers with 0s and 1s. Check [this page](https://en.wikipedia.org/wiki/Two%27s_complement) if you want to know more.

The last operator to introduce is XOR, or *exclusive-OR*. The result of exclusive OR is 1 only if the two bits are different (i.e. one of them is 1 and the other is 0). If the two bits are the same, the result is 0.

![BitwiseXor](D:\2020_Fall\Monday_Lesson\Course0104\BitwiseXor.png)

Side note: We also have operators called NAND, NOR, and XNOR, which is abbreviated from (NOT AND), (NOT OR), and (NOT XOR). They are less quite used today, but in engineering, using NAND and NOR are more efficient than AND and OR, because they took less CMOS transistors to implement.

### Shift Left (<<) and Shift Right (>>)

Technically these two operators are not "bitwise" operators, but they are used for manipulating bits as well, so they fall into this category. They are called shifting.

You've already used `<<` and `>>` in `cin` and `cout`, but actually the operators are getting *overwritten* in `<iostream>`. The real usage of `<<` and `>>` are for shifting bits. `(a << 3)` means shift the bits of `a` by 3 to the left.

![ShiftLeft](D:\2020_Fall\Monday_Lesson\Course0104\ShiftLeft.png)

Side Note: Things will get more complicated about "shift right". If you checked the two's complement link up there, you will understand the first bit is used for "sign bit". Turns out there are two different kinds of shifting: Logical Shift Right and Arithmetic Shift Right. C++ `>>` uses arithmetic version (which means shifting the sign bit instead of always shifting 0s).

---

## Scope

We talked a little about the block, or *compound statement* before (in Notes 201116). At that time, we said the `{}` symbols could take a number of statements into one statement.





## Homework

Under the student's request, no homework this week.