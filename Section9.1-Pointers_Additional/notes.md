# A more comprehensive pointers section
> I'm gonna be using the <a href="https://www.youtube.com/watch?v=zuegQmMdy8M">FreeCodeCamp C++ Pointers course</a> for this :)

## 1. What is a Pointer?
A pointer is a variable that stores the memory address of another variable.<br>
For example: Let us say we have a variable: `int x = 4` at address `204`. The size of this variable will be 4 bytes (4B) in most modern compilers such as g++.<br>
We can now have another variable, say `p` at address `205`, which is a **pointer** to `x`. It will store the value of the memory address of `x`, and using some operators on `p`, we can access the value of `x`.<br>

### 1.1 Syntax of pointers
A normal (data) variable is declared as follows:
```cpp
int x = 10;
// type varName = value; (declaration and initialization)
// type varName; (declaration only)
```
A pointer (address) variable would be declared as follows:
```cpp
int *p = &x;
// type *varName = &varToGetPointerTo; (declaration and initialization)
// type *varName; (declaration only)
```

> Remember that the datatype of a pointer should match that of the variable it points to. Therefore, `int *myPointer` can only point to an integer, `float *anotherPointer` can only point to a floating-point variable and so on.

If we print a declared pointer,
```cpp
int x = 10;
int *p = &x;
std::cout << p;   // Output: 204
```
It will output the memory address of the variable it points to, in this case, `x` whose address is `204`.<br>
We can also print directly the address of a variable like this:
```cpp
int x = 10;
std::cout << &x;   // Output: 204
```
Pointer vars also have their own memory addresses.
```cpp
int x = 10;
int *p = &x;
std::cout << &p;   // Output: 205
```
But can you access the data stored in a data variable using a pointer to it? Yes. You only have to place an asterisk `*` before the name of the pointer.
```cpp
int x = 10;
int *p = &x;
std::cout << *p;   // Output: 10 (value stored in x)
```
<br>
Setting a pointer to the address of a variable using the `&` symbol is called **referencing**. Accessing the data stored in a variable using a pointer to it is called **dereferencing**.
<br><br>

> The asterisk (`*`) refers to the *value* at a given pointer.
---
### Recap so far
- Pointers are variables that store memory addresses of other variables and can refer to them.
- Variables can be declared as pointers by prefixing the name with an asterisk (`*`).
- Pointers can be initialized with the memory address of another variable. This address can be found using the ampersand (`&`) symbol, for example: `int x = 10, *p; p = &x;`
- Printing a pointer directly (without *dereferencing*) will print the memory address of the pointer. Dereferencing the pointer by prefixing with an asterisk (`*`) will print the value at the memory address stored in the pointer.
---
### A small exercise :)
> Give the outputs of the following programs:
```cpp
int x, *p;
std::cout << p << std::endl;
std::cout << (int) p;
```
The output in the above case will be a hexadecimal value for the first line and an integral value for the second. The two outputs will equate in value.<br>
For example, the output could be
```cpp
// <stdout>
0x401a20
4200992
// The two values are equal. 401a20 in hex = 4200992 in decimal.
```
```cpp
int x = 69;
int *p;
p = &x;
std::cout << p << std::endl << *p << std::endl;
if (&x == p && *p == x)
{
    std::cout << "Pointers work :D";
}
// The output could be, for example:
/*
<stdout>

0x61ff08
69
Pointers work :D
*/
```

### 1.2 Why are pointers strongly typed?
Pointers must be declared with type names; i.e they are strongly typed. This is because a pointer is meant to be able to <br>
dereference the value at the address stored in itself. Illustrated: <br>
In most modern day compilers, datatypes are given sizes as follows: <br>
1. `int`: `4B`
2. `char`: `1B`
3. `float`: `4B`
4. `double`: `8B`

Taking an integer as example, say `int a = 1025;` It may be stored as follows:<br>

**Byte Number** | **Value Stored** | **Address (int)**     | **Address (hex)** |
----------      | ---------        | --------              | --------          |
`Byte 3`        | `00000000`       | `6422283`             | `61ff08`          |
`Byte 2`        | `00000000`       | `6422282`             | `61ff09`          |
`Byte 1`        | `00000100`       | `6422281`             | `61ff0a`          |
`Byte 0`        | `00000001`       | `6422280`             | `61ff0b`          |

Now, when we access the variable with a pointer:<br>
```cpp
int a = 1025;
int *p = &a;
std::cout << p << std::endl;   // Output: 200
std::cout << *p << std::endl;  // Output: 1025
```
The pointer is specified as type `int`, same as the variable it points to. When we print the address in the pointer, it outputs the address
of `Byte 0`, i.e. `200`. This means, `p` points to an `int` *starting at address `200`*.<br>
When we dereference the pointer `p`, the `int` type tells the compiler to look at 4 bytes, *starting at address `200`*, since an `int` occupies `4B` of space.<br>
Similarly, a `char` pointer will look at 1 byte, a `double` pointer will look at 8 bytes etc.