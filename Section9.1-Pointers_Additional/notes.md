# A more comprehensive pointers section
> I'm gonna be using the [FreeCodeCamp C++ Pointers course](https://www.youtube.com/watch?v=zuegQmMdy8M) for this :)

## 1. What is a Pointer?
A pointer is a variable that stores the memory address of another variable.

For example: Let us say we have a variable: `int x = 4` at address `204`. The size of this variable will be 4 bytes (4B) in most modern compilers such as g++.

We can now have another variable, say `p` at address `205`, which is a **pointer** to `x`. It will store the value of the memory address of `x`, and using some operators on `p`, we can access the value of `x`.


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
It will output the memory address of the variable it points to, in this case, `x` whose address is `204`.

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


Setting a pointer to the address of a variable using the `&` symbol is called **referencing**. Accessing the data stored in a variable using a pointer to it is called **dereferencing**.


> The asterisk (`*`) refers to the *value* at a given pointer.
---
### 1.2 Recap so far
- Pointers are variables that store memory addresses of other variables and can refer to them.
- Variables can be declared as pointers by prefixing the name with an asterisk (`*`).
- Pointers can be initialized with the memory address of another variable. This address can be found using the ampersand (`&`) symbol, for example: `int x = 10, *p; p = &x;`
- Printing a pointer directly (without *dereferencing*) will print the memory address of the pointer. Dereferencing the pointer by prefixing with an asterisk (`*`) will print the value at the memory address stored in the pointer.
---
### 1.3 A small exercise :)
> Give the outputs of the following programs:
```cpp
int x, *p;
std::cout << p << std::endl;
std::cout << (int) p;
```
The output in the above case will be a hexadecimal value for the first line and an integral value for the second. The two outputs will equate in value.

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

### 1.4 Why are pointers strongly typed?
Pointers must be declared with type names; i.e they are strongly typed. This is because a pointer is meant to be able to
dereference the value at the address stored in itself. 

In most modern day compilers, datatypes are given sizes as follows:

1. `int`: `4B`
2. `char`: `1B`
3. `float`: `4B`
4. `double`: `8B`

Taking an integer as example, say `int a = 1025;` It may be stored as follows:

| **Byte Number** | **Value Stored** | **Address (int)** | **Address (hex)** |
| --------------- | ---------------- | ----------------- | ----------------- |
| `Byte 3`        | `00000000`       | `6422283`         | `61ff08`          |
| `Byte 2`        | `00000000`       | `6422282`         | `61ff09`          |
| `Byte 1`        | `00000100`       | `6422281`         | `61ff0a`          |
| `Byte 0`        | `00000001`       | `6422280`         | `61ff0b`          |

Now, when we access the variable with a pointer:
```cpp
int a = 1025;
int *p = &a;
std::cout << p << std::endl;   // Output: 200
std::cout << *p << std::endl;  // Output: 1025
```
The pointer is specified as type `int`, same as the variable it points to. When we print the address in the pointer, it outputs the address
of `Byte 0`, i.e. `200`. This means, `p` points to an `int` *starting at address `200`*.

When we dereference the pointer `p`, the `int` type tells the compiler to look at 4 bytes, *starting at address `200`*, since an `int` occupies `4B` of space.

Similarly, a `char` pointer will look at 1 byte, a `double` pointer will look at 8 bytes etc.

### 1.5 Pointers to pointers
Pointers can also point to the address of other pointers. For example, let's take the following C++ code:
```cpp
#include <iostream>
using namespace std;

int main()
{
    int x = 5;
    int *p = &x;
    int **q = &p;

    cout << p << endl;
    cout << *p << endl;
    cout << q << endl;
    cout << *q << endl;
    cout << **q << endl;
}
```
For this example, let's say that the memory for each variable is allocated as follows:

| Variable Name | Memory Address (decimal) | Memory address (hex) |
| ------------- | ------------------------ | -------------------- |
| `(int) x`     | `200`                    | `c8`                 |
| `(int*) p`    | `210`                    | `d2`                 |
| `(int**) q`   | `220`                    | `dc`                 |

In this case, the variable `(int*) p` will store the address of variable `(int) x` (i.e. `200`), and the variable `(int**) q` will store the address of pointer `(int*) p`.
> Notice that pointers to pointers have the same datatype as the variable they point to, only with an added asterisk (`*`).

When we run the given code snippet, the output should be something like this:

```
200 (or 0xc8)
5
210 (or 0xd2)
200 (or 0xc8)
5
```
- The first print statement (`cout << p << endl;`) will print the address that the pointer `p` points to. In this case, that's the address of variable `x`, i.e. `0xc8`.
- The next statement (`cout << *p << endl;`) will print the *value* stored at the address that `p` points to; which in this case is the value of `x`, or `5`.
- The next statement (`cout << q << endl;`) will print the address stored at the pointer `q`, which obviously is a *pointer to a pointer*. In this case, it points to the address of `p`, i.e. `0xd2`.
- The next statement (`cout << *q << endl;`) will print the value stored at the address that `q` points to. Here, that's the value at `p`. `p` stores the address of our variable `x`, which is why this statement prints the address of `x`, i.e. `0xc8`.
- And the final statement (`cout << **q << endl;`) will print the value stored at `*q`. As explained in the previous point, `*q` is the address of `x`, so this line will print the *value of `x`*, i.e. `5`.
> Note that `**q` can also be written as `*(*q)`. using the order of operations in parentheses, you might find it easier to understand the last point.

### 1.6 Pointers to pointers to pointers (and more)
Similar to how we declared a pointer to a pointer above, we can declare pointers to pointers to pointers, simply by adding another asterisk.
```cpp
int x = 10;
int *p = &x;
int **q = &p;
int ***r = &q;
```
While printing any values stored in such pointers, we will just go up levels of pointer-abstraction as in the previous part, for example

```cpp
cout << r // prints the address that r points to, i.e. 0xdc
cout << *r // prints the value stored at the address 0xdc, i.e. 0xd2. This is the same as running cout << q;
cout << **r // prints the value stored at *r, i.e. 0xc8. This is the same as running cout << *q; or cout << p;
cout << ***r // prints the value stored at **r, i.e. 5. This is the same as cout << **q; or cout *p; or cout << x;
```
> That's it! That's all the basic concepts related to pointers. But you best believe there's more. We'll talk about a use-case next.

---

## 2. A pointer use-case: As function arguments (Call by value and call by address)
Let's take an example of a script:
```cpp
#include <iostream>
using namespace std;

void increment(int num)
{
    num += 1;
}

int main()
{
    int num = 10;
    increment(num);
    cout << num;

    return 0;
}
```

When we compile and run this script, we expect the value of `num` to have increased by 1. This, however, is not what happens. Why not?

Well, the variable `num` used inside our `increment()` function is not the same as the `num` inside the `main()` function. This can be observed by printing the memory addresses in each case:

```cpp
void increment(int num)
{
    num += 1;
    cout << "Address of num in increment func: " << &num << endl;
}

int main()
{
    int num = 10;
    cout << "Value of num before calling function: " << num << endl;
    increment(num);
    cout << "Address of num in main func: " << &num << endl;
    cout << "Value of num after calling function: " << num << endl;

    return 0;
}
```
On running this code, we might get an output as follows (exact addresses may vary)
```
Address of num in increment func: 0x61ff0c
Address of num in main func: 0x61ff0f
Value of num before calling function: 10
Value of num after calling function: 10
```
The exact addresses of the variables here doesn't really matter: The takeaway here is that the addresses are *different*, i.e. the variable in each case is not the same.

When a C/C++ program is executed, the machine gives a certain amount of memory in the RAM to it. This memory is sectioned off as follows:

![Memory Allocation Table C/C++](https://study.com/cimages/multimages/16/memory_alloc_cpp.png)

- The Program Code or Text section stores the instructions to be executed.
- The global or static section stores variables and functions which are in the Global scope; i.e. they can be accessed by all functions.
- Stack stores variables and functions in the Local scope; i.e. accessible only in the scope where they are declared.
- Memory allocated to the Program Code, Global and Stack sections is fixed, while memory is allocated *dynamically* to the Heap section.

So in the snippet above, the Stack section will have two separate spaces for our variables, one allocated to the `num` in the `main()` function and the other for `num` in the `increment()` function. We access each of these memory locations with different addresses in our program above.

This is called **calling by value**, i.e. calling the function using a value of our variable. In this case, calling by value won't be very helpful to us, as we want to mutate the actual value of the variable inside the `main` scope.

Instead of doing this, we may **call by address**. In that case, out `increment()` function would take a pointer as an argument. This will enable it to directly manipulate the value stored in a given memory address, thus fulfilling its purpose.


```cpp
void increment(int *ptr)
{
    (*ptr) += 1;
    cout << "Address of num in increment func: " << &*ptr << endl;
}

int main()
{
    int num = 10;
    cout << "Value of num before calling function: " << num << endl;
    
    increment(&num);
    cout << "Address of num in main func: " << &num << endl;
    cout << "Value of num after calling function: " << num << endl;

    return 0;
}
```

This will give us an output similar to: (Again, the exact memory address may vary)
```
Value of num before calling function: 10
Address of num in increment func: 0x61ff0c
Address of num in main func: 0x61ff0x
Value of num after calling function: 11
```
As you can see, this behaved as we needed it to. The `increment` function accesses the actual memory address of the variable and changes its value, which is made possible by calling the function by address.


We may even **call by reference**, i.e. accept references as parameters in the function and then pass in the variable inside the calling function. This will allow us to mutate the original value in the same way as calling by address. For example:


```cpp
void increment(int &num)
{
    num++;
    cout << "Address of num in increment func: " << &num << endl;
}

int main()
{
    int x = 10;
    increment(x);
    cout << "x = " << x << endl;
    cout << "Address of num in main func: " << &x << endl;

    return 0;
}
```

---
## 3. Pointers and Arrays
Pointers and Arrays in C/C++ are very closely related. Let's take an example to work through this part:
```cpp
#include <iostream>
using namespace std;

int main()
{
    int myArray[5] = {3, 6, 8, 9, 10};
}
```

We declared an integer array of length 5. In modern compilers, integers are given `4B` of storage. This means our array might look something like this in memory:

| Variable Name | Memory Address (decimal) | Memory address (hex) |
| ------------- | ------------------------ | -------------------- |
| `myArray[0]`  | `200`                    | `c8`                 |
| `myArray[1]`  | `204`                    | `cc`                 |
| `myArray[2]`  | `208`                    | `d0`                 |
| `myArray[3]`  | `212`                    | `d4`                 |
| `myArray[4]`  | `216`                    | `d8`                 |

> When we say the memory address is `204`, we mean that the integer is stored in 4 bytes, from `204` to `207` (inclusive).

Let's say we have another variable, other than the array stored in the same program:
```cpp
int x = 33;
```
This variable may be stored somewhere else in the memory, say address `0x12e`. Now, taking a pointer to `x`,

```cpp
int *p = &x;

cout << p << endl;
cout << *p << endl;

p++;
cout << p << endl;
cout << *p << endl;
```
Output:
```
0x12e
33
0x132
53648 (this is a garbage value)
```

`p` will initially store the address of `x`, i.e. `0x12e`. At this stage, `p` can be dereferenced to get the value of `x`, as is done in the second print statement.

When we increment `p`, it will now point to the address of the next integer, 4 bytes after `0x12e`, i.e. `0x132`. Dereferencing at this stage will give us a garbage value, as we have not stored anything at that address.

Now, if we try something similar with the array:
```cpp
int myArray[5] = {3, 6, 8, 9, 10};
int *q = &myArray[0];

cout << q << endl;
cout << *q << endl;

q++;
cout << q << endl;
cout << *q << endl;
```
Output:
```
0xc8
3
0xcc
6
```
In this case, pointer arithmetic makes sense. We know that arrays are stored as a collection of variables in adjacent memory locations, which is why incrementing the pointer in this snippet returns the address of the next element.

While it is fine to get the addresses of array elements in this way, it is worth noting that accessing the array as follows:
```cpp
cout << myArray;
```
will also give the address of the first element. We can set a pointer to an element of an array in this way:
```cpp
int myArray[5] = {3, 6, 8, 9, 10};
int *q = myArray;
```

This gives us a new way of accessing the addresses and values of array elements, without having to use the ampersand operator. The following script will print the addresses and values of the elements of an array.
```cpp
#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    int myArray[5] = {3, 6, 8, 9, 10};

    for (int i = 0; i < sizeof(myArray) / sizeof(int); ++i)
    {
        cout << "Address of element at index " << i << ": " << myArray + i << endl;
        cout << "Element at index " << i << ": " << *(myArray + i) << endl;

        // Address can also be printed as &myArray[i]
        // Element can also be printed as myArray[i]
    }

    return 0;
}
```
> Note: `sizeof()` gives the size (in bytes) that is allocated to a variable or datatype. `sizeof(myArray)` therefore returns `20` and `sizeof(int)` gives 4. Dividing the two will give us the length of the integer array. We may also use `sizeof(myArray[0])` here, which is better practice as we won't have to know the type of the array.

The above example uses pointer arithmetic to access each element of the array.

---

### 3.1 Arrays as Function arguments

When we try to pass an array as an argument to a function, we get some interesting behaviour. To see this, let's say we want a function to find the sum of all elements in an array:

```cpp
#include <iostream>
using namespace std;

int sumOfElements(int array[])
{
    int i, sum = 0, size = sizeof(array) / sizeof(array[0]);

    for (i = 0; i < size; i++)
    {
        sum += array[i];
    }

    return sum;
}

int main()
{
    int myArray[5] = {1, 2, 3, 4, 5};
    int mySum = sumOfElements(myArray);
    cout << "Sum of elements is " << mySum << endl;
}
```

We expect the output to be the sum of 1, 2, 3, 4, and 5; i.e. 15. However when this code is run, the output is 1.
```
Sum of elements is 1
```

Why is this? To understand, let us look at the memory allocation diagram again.

![Memory Allocation Table C/C++](https://study.com/cimages/multimages/16/memory_alloc_cpp.png)

Memory will be allocated inside the Stack for our program. The stack frame of the `main()` function will have two variables, namely `int myArray[5]` and `int mySum`. `myArray` will be given 20 bytes (as it is an integer array of length 5), and `mySum` will take 4 bytes.

Another stack frame will be created for the `sumOfElements` function. Since the array is a parameter of the function, we expect a copy of the array inside `main()` to be created inside `sumOfElements()`. While this may make intuitive sense, the compiler deals with it differently.

When you pass an array as an argument to a function, the C++ compiler will create a *reference* to that array inside the **called** function. So the compiler reads the above snippet like this:

```cpp
int sumOfElements(int *array[])  // The compiler will implicitly make a pointer to the parameter array.
{
    int i, sum = 0, size = sizeof(array) / sizeof(array[0]);

    for (i = 0; i < size; i++)
    {
        sum += array[i];
    }

    return sum;
}
```

As you may recall, referencing an array using its variable name will give us the address of the first element in the array. So in our function, `sizeof(array)` will give us the *size of the first element in the array, i.e. an integer*. Now, that line works the same way as:

```cpp
sizeof(array[0]) / sizeof(array[0]);
```

Which will, obviously, set our variable `size` to `1`.

The takeaway here, is that when you pass an array as an argument to a function, the C/C++ compiler does not make a copy of the array inside the function. It instead makes a *pointer* to that array, (and hence to the first element of the array), and increments the pointer whenever different elements of the array need to be accessed. The reason it works this way, is that arrays may be extremely long. Taking a copy of the entire array in all functions where it is passed will eat up a lot of memory and cause a drop in performance; referencing it instead is much more efficient.

Now, to get the value we expected at first, we see that we need to pass the length of the array as another argument to the function, as follows:

```cpp
#include <iostream>
using namespace std;

int sumOfElements(int array[], int size)
{
    int i, sum = 0;
    printf("Size of array in Bytes, will return size of int* (SOE): %d\nLength of array given as argument (SOE): %d\n", sizeof(array), size);

    for (i = 0; i < size; i++)
    {
        sum += array[i];
    }

    return sum;
}

int main()
{
    int myArray[5] = {1, 2, 3, 4, 5};
    int size = sizeof(myArray) / sizeof(myArray[0]);
    int mySum = sumOfElements(myArray, size);
    cout << "Sum of elements is " << mySum << endl;
}
```

The length of the array is being calculated in the `main()` function and being passed to the `sumOfElements()` function. Output:

```
Size of array in Bytes, will return size of int* (SOE): 4
Length of array given as argument (SOE): 5
Sum of elements is 15
```

> Note: There *are* some ways to calculate the length of a parameter array, using something called Templates in C++ (Part of the STL).

Finally: Since a parameter array is a pointer referencing an array, we are able to mutate (modify) the actual array from inside the function, as an advantage of calling by reference. This allows us to do interesting things like the following snippet which doubles the values inside an array. Note that the *return type* of the function `doubleArray()` is `void`, showing that we're directly mutating the value stored in the `main()` scope.

```cpp
#include <iostream>
using namespace std;

void doubleArray(int array[], int length)   // int array[] is the same as int *array[] here.
{
    for (int i = 0; i < length; i++)  // We are taking the length of the array as a parameter.
    {
        array[i] *= 2;   // same as array[i] = array[i] * 2
    }
}

int main()
{
    int myArray[5] = {1, 2, 3, 4, 5};
    int length = sizeof(myArray) / sizeof(myArray[0]);
    cout << "Original array: ";
    for (int i : myArray) {   // : is a new feature of C++ 11, which allows you to use a variable for the value of an array element instead of index
        cout << i << " ";
    }

    doubleArray(myArray, length);
    cout << "\nDoubled array: ";
    for (int j : myArray) {
        cout << j << " ";
    }
}
```

Output:

```
Original array: 1 2 3 4 5 
Doubled array: 2 4 6 8 10
```
---

### 3.2 Pointers and character arrays
When we talk about *strings* in C++, we need to think about character arrays. Strings are stored as arrays of individual characters.

In order to store a sting inside a character array, we must first have a character array of the required size. This must be greater than or equal to the size length of the string *plus 1*. For example, while storing a string "Lorem", we see that the string is 5 characters long, so we need a char array of length 6 at minimum.

```cpp
char myStr[6] = "Lorem";
```

We can see by printing this array using a for loop, that each character in the string "Lorem" is saved as an individual character inside the array:

```cpp
char myStr[6] = "Lorem";
for (char i : myStr)
{
    std::cout << i << std::endl;
}
```

But why do we need an extra byte of space in our array? Well, the last byte inside a character array is used by the compiler to determine *where the string terminates*. The compiler looks for a **null character** `('\0')` and assumes that the string ends at that character.

If we don't put a null character at the end of a string, garbage values stored next to the string will affect operations on it. This can be seen in the following example:

```cpp
char myCharArray[5];
myCharArray[0] = 'L';
myCharArray[1] = 'o';
myCharArray[2] = 'r';
myCharArray[3] = 'e';
myCharArray[4] = 'm';

cout << myCharArray << endl;
```

The output will be something like this:

```
Lorem�@
```

Which is our expected value, along with garbage at the end. To fix this, we'll have to append a '\0' char at the end of the array.

```cpp
char myCharArray[6];
myCharArray[0] = 'L';
myCharArray[1] = 'o';
myCharArray[2] = 'r';
myCharArray[3] = 'e';
myCharArray[4] = 'm';
myCharArray[5] = '\0';
```

> Note that when you declare a string while initialising it, as in `char myCharArray[6] = "Lorem";`, the compiler will implicitly add a `\0` character at the end. However, the array must still be of the proper length as discussed above.

It may be noticed, that all methods and functions that manipulate strings, expect them to be in the form of character arrays terminating with a null character. For example, the `strlen()` function in the `<cstring>` (or `<string.h>` in C) library.

```cpp
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char myStr[40] = "Lorem ipsum dolor";
    cout << "The string is " << strlen(myStr) << " characters long.";
}
```
Output:
```
The string is 17 characters long.
```

**Some things to remember:**

> Char arrays can be initialised at the time of declaration using string literals, for example `char c[3] = "hi";`

> A Character array cannot be initialised with a string literal after declaration on a separate line: `char c[3]; c = "hi";` would generate an error.

> While declaring and initialising on the same line, you can leave the size of the character array empty: `char c[] = "hi";` would be valid and the compiler would automatically find the correct size. You can also do this when using a character array as a function parameter.

> As you may recall from earlier sections, the `sizeof()` function will return the size of a variable in bytes. Since characters take up 1 byte of space, `sizeof(aCharArrayVariable)` will return the exact length of the character array. However, this will also include the null character at the end, so it will be equal to the length of the string + 1.

> A character array can also be initialised as a comma-separated list of individual characters. However null-termination will not be implicit in this case and you are expected to add a null character at the end. For example: `char c[3] = {'H', 'i', '\0'};`

> An array is similar to a pointer, but is not exactly the same.

Let's take a character array here, and initialise it with the string literal "Lorem".

```cpp
char myStr[] = "Lorem";
```

This may be stored in memory as follows:

| Character | Memory Address |
| --------- | -------------- |
| `'L'`     | `c8`           |
| `'o'`     | `c9`           |
| `'r'`     | `ca`           |
| `'e'`     | `cb`           |
| `'m'`     | `cc`           |
| `'\0'`    | `cd`           |

Taking a pointer to the above declared array:

```cpp
char *ptr = myStr;
```
Let us remember that using the name of an array returns the address of the first element. Therefore, the address `0xc8` gets stored in our pointer.

We can now use the pointer to refer to our array and perform operations on its values, like so:
```cpp
cout << ptr[0]; // prints 'L'
ptr[0] = 'K'; // changes string to "Korem"
```
This shows that referencing a pointer to an array as `ptr[i]` works the same way as `*(ptr + i)`. Referencing an array works in the same way, `myStr[i]` is the same as `*(myStr + i);`. This shows that arrays and pointers are used in similar ways.

But don't be mistaken, they are not exactly the same. For example, while you can set a pointer to point to an array like `char *ptr = myStr;`, you cannot set an array to a pointer. `myStr = ptr;` is invalid. You can also not perform arithmetic directly on arrays, so statements such as `myStr++;` are invalid, while `ptr++;` is valid, and will make the pointer point to address `0xc9`. Continuously incrementing the pointer will let you traverse the elements of an array.

> Arrays in function parameters act as pointers to the array, for the sake of optimisation.

In the following snippet:

```cpp
#include <cstdio>

void printStr(char str[])
{
    int i = 0;
    while (str[i] != '\0')
    {
        printf("%c", str[i]);
    }
}

int main()
{
    myStr = "Lorem Ipsum";
    printStr(myStr);
    return 0;
}
```

In the function `(void) printStr`, the parameter `char str[]` is treated as `char *str` by the compiler, and `str[i]` is treated as `*(str + i)`.

Since `str` is treated as a `char*`, we can rewrite the `printStr` function like this:
```cpp
void printStr(char str[])
{
    while (*str != '\0')
    {
        printf("%c", *str);
        str++;
    }
}
```
Pointer arithmetic on `str` is valid, as it is treated as a pointer, and not an array in the function.


### 3.21 Pointers & Character Arrays Contd.

Let us once again look at the printStr program from the previous subsection:

```cpp
void printStr(char str[])
{
    while (*str != '\0')
    {
        printf("%c", *str);
        str++;
    }
}

int main()
{
    char str[20] = "Lorem";
    printStr(str);

    return 0;
}
```

Looking once again at the memory allocation diagram:

![Memory Allocation Table C/C++](https://study.com/cimages/multimages/16/memory_alloc_cpp.png)

Whenever a function is called (in this case the `printStr` function), some amount of memory is allocated to the execution of that function in the *stack*. This is called the *stack frame* of that function. Let us say that in this case, address `0x64` to `0x96` is allocated to the `main` function.

All the local variables inside the `main` function will be allocated space inside the stack frame; i.e. `20B` for the `str` character array (size 20). Let us say, from address `0x64` to `0x78`. When the `printStr` function is called, the execution of `main` is paused, and the called function is allocated a stack frame on top of the calling function, let's say from `0x96` to `0xaa`.

The stack frame of the `printStr` function will also have a local variable `str`, of a pointer type. This will occupy `4B` of space, say from `0x9a` to `0x9d`. (Remember that the `str` variable in `main` and the one in `printStr` are not the same, they have different types, scopes and memory locations.)

When `printStr` is called, the address of variable `str` from `main` is passed to the called function. (Only the address of the first element is passed, as discussed before.)

Stepping through the snippet above, after the address of `str[0]` from `main` (i.e. `0x64` in our example) is passed to the called function, a char pointer at `0x9a` points to the address. While the value at the referenced address is not `\0`, the value is printed out. In this case, teh condition holds true and the first character in the array is printed.

When the pointer is incremented, the address it points to is incremented by the size of the datatype. In this case, that's `char`, i.e. `1B`. The pointer `str` now points to `0x65`, the address of `str[1]` from `main`. The condition is checked again and still holds true; the second character is printed.

This loop continues until `str` points to `0x69`, which has the value `'\0'` in it. When the condition is found to be false, the loop terminates and the execution of `main` is resumed. The stack frame for the `printStr` will also be deallocated, and may be reallocated later if the function is called again.

> It may be noted that you can accept a constant pointer using the `const` keyword in functions to make them immutable, if you do not want to alter the values stored in the pointer array. Example: `const char *ptr`


## 3.3 Pointers and multidimensional arrays
First let's revise how one-dimensional arrays are stored in memory.

They are stored as a contiguous block of memory, divided into adjacent cells, each of size depending on the type of the array. For an integer array of size 5, for example, it will occupy 20 bytes of space, divided into 5 cells of 4B each since a typical compiler stores integers in 4 bytes.

```cpp
int myArray[5]; // 20 bytes of space, 5 4-byte blocks
int *ptr = &myArray; // Points to the first item in array, myArray[0]

std::cout << p; // Prints address of myArray[0]
std::cout << *p; // Prints value of myArray[0]
std::cout << *(p + 2); // Prints value of myArray[2] (pointer arithmetic increments address it points to)

// Remember that you can simply use the name of the array variable, instead of using a pointer variable in all these cases. (*(A+x) == A[x], and (A+x) == &A[x])
// Also, you can equate a pointer to an array and not the other way 'round.
```

**Two Dimensional Array (2D)**

A two dimensional array is basically an array of arrays. Declared as follows:
```cpp
int twoDimensional[2][3];
```
This declares an integer array of length 2, and each item of that array is an integer array of length 3. The total size of this array will be 3 * 4 * 2 = 24 bytes. It will be stored in memory as follows: (Address values assumed)

| Address (int)   | Array item          | Value Stored             |
| --------------- | ------------------- | ------------------------ |
| `400-411 (400)` | `twoDimensional[0]` | `twoDimensional[0][0-2]` |
| `412-423 (412)` | `twoDimensional[1]` | `twoDimensional[1][0-2]` |

As we know, using the name of an array variable gives the address of its first element. In this case, lets say `int *p = twoDimensional;`.

However this will give a compilation error, since the `*p` pointer expects an integer type, but the first element of `twoDimensional` is actually an int array of length 3.

To create a pointer to a 2D array, we must write a statement like this:

```cpp
int (*ptr)[3] = twoDimensional;
```

This will work without errors, as the pointer now expects an int array of length 3 for its value.

Let's now look at some examples of pointer arithmetic on a 2D array, using the array and pointer as declared above:

> Note that in all these examples, the address has been given in decimal form for convenience. By default, C++ will show the address as a hexadecimal number unless you typecast or format it.

1. `std::cout << twoDimensional;`: This will print the address of the first element in the array, i.e. 400. Same as `cout << &twoDimensional[0];`
2. `std::cout << *twoDimensional;`: This will print the value stored at the address of the first element in the array, i.e. the address of the first element of the second dimension array: 400. Same as `cout << &twoDimensional[0][0];` or `cout << twoDimensional[0];`
3. `std::cout << twoDimensional + 1;`: This will print the address of the second element in the first-dimension array, i.e. 412. (See the table above for the reason). Same as `cout << &twoDimensional[1];`
4. `std::cout << *(twoDimensional + 1);`: This will print the value stored at the address of the second element in the first-dimension array, i.e the address of the first element of the second-dimension array inside `twoDimensional[1]`. Same as `cout << &twoDimensional[1][0]` or `cout << twoDimensional[1]`.
5. `std::cout << *(twoDimensional + 1) + 2;`: This will print the address of the second index of the second-dimensional array stored inside `twoDimensional[1]`. Same as `cout << &twoDimensional[1][2];` or `cout << twoDimensional[1] + 2;`
6. `std::cout << *(*twoDimensional + 1);`: `*twoDimensional` references the address of the first element of the second dimension of `twoDimensional[0]`, i.e. `twoDimensional[0][0]`. Adding 1 will reference `twoDimensional[0][1]`, and using `*` will print the value at that address. Theerefore this statement will print the integer value stored at `twoDimensional[0][1]`.
   
> For a 2-D array `A`, `A[i][j]` is the same as `*(A[i]) + j` or `*(*(A + i) + j)`. 

Some of the above examples can be seen in this snippet:

```cpp
#include <iostream>
using std::cout;
using std::endl;
// Tip: What I've done above (using std::cout; etc), is better practice than using namespace std directly, since it avoids polluting the workspace with
// variable names.

int main()
{
    int primesArray[2][3] = {{2, 3, 5}, {7, 9, 11}};
    cout << primesArray[0][2] << endl; // Expected value: 5

    int (*ptr)[3] = primesArray; // expects int array length = 3
    cout << ptr << endl; // Expected value: Address of primesArray[0] (0x61fef4 in test case)
    cout << *ptr << endl; // Expected value: Address of primesArray[0][0] (0x61fef4 in test case)
    cout << *ptr + 1 << endl; // Expected: Address of primesArray[0][1] (4 bytes higher than primesArray[0][0]) (0x61fef8 in test case)
    cout << *(ptr + 1) << endl; // Expected: Value at primesArray[1] = Address of primesArray[1][0] (12 bytes higher than primesArray[0][0]) (0x61ff00 in test)
    cout << *(*ptr + 1) << endl; // Expected: Value at primesArray[0][1] = 3

    cout << *(*(ptr + 1) + 2) << endl; // Expected: Value at primesArray[1][2] = 11

    return 0;
}
```

**3D Array**

Just like a 2D array is a collection of 1D arrays, a 3D array is a collection of 2D arrays. For example:

```cpp
int primes[2][2][3] = {{{2, 3, 5}, {7, 9, 11}}, {{13, 17, 19}, {23, 29, 31}}};
```

A pointer to an integer cannot accept the above array, it must be made to expect a 2D array of size 2x3:

```cpp
int (*ptr)[2][3] = primes;
```

This array may be arranged as follows:
| Address (int)   | Array item (1D) | Value Stored (2D) | Value Stored inside 2D array (3D) |
| --------------- | --------------- | ----------------- | --------------------------------- |
| `400-423 (400)` | `primes[0]`     | `primes[0][0-1]`  | `primes[0][0-1][0-2]`             |
| `424-447 (424)` | `primes[1]`     | `primes[1][0-1]`  | `primes[1][0-1][0-2]`             |

Now lets look at some print statements using the above array.

> Note that in all these examples, the address has been given in decimal form for convenience. By default, C++ will show the address as a hexadecimal number unless you typecast or format it.

1. `cout << ptr;` Gives the address of the first element of the first dimension, i.e. 400
2. `cout << *ptr;` Gives the value stored at the first address in the first dimension, i.e. `primes[0]`, which is a 2D array `primes[0][0-1]`, with address 400.
3. `cout << *ptr + 1;` Adds 1 to the value obtained in Statement (2) above, so it will output the address of `primes[0][1]`, which is 412. (This is because element `primes[0][0]` is an int array of length 3, and occupies 12 bytes.)
4. `cout << *(ptr + 1);` Will give the value stored at the second element of the first dimension. The value stored in `primes[1]` is the address of `primes[1][0-1]`, so the value will be 24 Bytes ahead of the value at Statement (1), i.e. 424.
5. `cout << *(*(*(ptr + 1) + 1) + 2);` This rather confusing-looking statement will print the value stored at the last index of the last 3rd dimensional array, i.e. the value stored at `primes[1][1][2]`, which is 31. You can understand this statement by working your way outwards starting from the ptr + 1 value in the printed value.

> ptr + 1 is the address of `primes[1]`. The value stored there is the address of `primes[1][0]`, to which we are adding 1. This references the address of `primes[1][1]`, and the asterisk outside the brackets will reference the value there. The value at `primes[1][1]` is the address of `primes[1][1][0]`, to which we add 2. This references the address of `primes[1][1][2]`. Finally, the outermost asterisk will give the *value* at `primes[1][1][2]`, which is 31 and gets printed out. Know that instead of working with so many nested references, you can simply use the 3D index of the array to print the value. `primes[1][1][3]` means the same thing as `*(*(*(ptr + 1) + 1) + 2)`, and can be used if you simply want to read/write the value in the array.

These statements can be seen in the following snippet:
```cpp
#include <iostream>
using std::cout;
using std::endl;

int main()
{
    int primes[2][2][3] = {{{2, 3, 5}, {7, 9, 11}}, {{13, 17, 19}, {23, 29, 31}}};
    int (*ptr)[2][3] = primes;

    cout << ptr << endl; // Expected: Address of primes[0] = 0x61fedc in test
    cout << *ptr << endl; // Expected: Value at primes[0] = Address of primes[0][0] = 0x61fedc in test
    cout << *ptr + 1 << endl; // Expected: Value at primes[0] + 1 = Address of primes[0][1] = 0x61fee8 in test
    cout << *(ptr + 1) << endl; // Expected: Value at primes[1] = Address of primes[1][0] = 0x61ef4 in test
    cout << *(*(*(ptr + 1) + 1) + 2) << endl; // Expected: Value at primes[1][1][2] = 31
    cout << primes[1][1][2] << endl; // Expected: Same value as previous statement, but this one is easier to write/read 

    return 0;
}
```

### 3.31 Passing Multidimensional Arrays to functions as arguments
We know that when a 1D array has to be passed to a function, we can write syntax like this: `int myFunction(int arrayArg[]) {}`, or this: `int myFunction(int *arrayArg) {}`. When we have to pass an array in more than 1 dimension, we can write something quite similar.

Say we have three arrays as defined below:

```cpp
int oneDim[2] = {23, 67};
int twoDim[2][2] = {{12, 54}, {34, 89}};
int threeDim[2][2][3] = {{{45, 89, 76}, {12, 11, 54}}, {{33, 56, 98}, {99, 32, 28}}};
```

To pass the `oneDim` array to a function, the parameter may be written like: `int func(oneDimArray[]) {}`. 

To pass the `twoDim` array, the parameter may be written like: `int func(twoDimArray[][2]) {}`. Note that while the size of the first dimension may be unspecified, the size of the second dimension must be specified. The variable `twoDim` cannot be passed to a function written like `int func(twoDimArray[][5]) {}`, for example.

Two pass the `threeDim` array, the parameter may be written like: `int func(threeDimArray[][2][3])`. Again, the length of the first dimension may be unspecified, but the length of the other dimensions must be specified.

> Note that the parameter `threeDimArray[][2][3]` may also be written like `(*threeDimArray)[2][3]`, and `twoDimArray[][2]` may also be written like `(*twoDimArray)[2]`.

## 4. Pointers and Dynamic Memory
As we learnt before, memory allocated to a program can be divided into four segments. These are the Code/Text segment, the Global/Static segment, the *Stack* and the *Heap*. All these segments have different purposes.

1. The *Code* segment is used to store the instructions which are to be executed during a program. This has a fixed size which is calculated during compilation.
2. The *Global* segment is used to store the global (or static) variables which are accessible throughout the program and remain accessible at all times during execution.
3. The *Stack* segment stores data related to function calls and variables with local scopes which can only be accessed inside specific functions. The size of the Stack is also fixed as calculated during compilation, and does not change during execution.
    > When you try to store data inside the stack, some of the space inside will get used up, and gets cleared after the scope is lost. However, if you try to store more and more data dynamically during execution inside the stack, the call stack may grow beyond the allocated size. Then the program faces a *Stack overflow* error, which will cause the application to crash.
4. The *Heap* is used as a free pool of memory, where data can be stored dynamically. More elaboration later.

Let's now see how the Code, Global and Stack segments work in action. See the following program:

```cpp
#include <iostream>
using std::cout;
using std::endl;

int total;

int sq(int x)
{
    return x * x;
}

int sqOfSum(int x, int y)
{
    return sq(x + y);
}

int main()
{
    int a = 4, b = 8;
    total = sqOfSum(a, b);
    cout << "Square of sum is " << total << endl;

    return 0;
}
```


![Memory structure diagram 1](https://i.imgur.com/DnVkv6a.png)
When the program starts executing, the main() function is at the top of the stack, and therefore is executed. Variables `(int) a` and `(int) b` are stored within its stack frame.

When we call `sqOfSum()`, the execution of `main()` is paused, that function is moved to the top of the stack and its local variables are stored. The `sqOfSum()` function calls another function `sq()` within itself. When that function is called, it is moved to the top of the stack and `sqOfSum()` is paused.

Once `sq()` has finished executing, it is *popped* from the stack and its local variables cleared. The execution of `sqOfSum()` is resumed. Once `sqOfSum()` reaches its return statement, it is also popped and `main()` is resumed. When `main()` reaches the `return 0;` statement, it is also popped and the stack is cleared. As there are no more functions to execute, all the memory given to the program is cleared and execution finishes.


There are some limitations, as may be obvious, to using the call stack to store data. For example, the stack operates on a fixed rule wherein the called function is pushed to the top and all others are paused. It is not possible to manipulate the execution scope in the stack.  Also, if you want a dynamically allocated datatype, such as an array that may grow during execution based on some rules or user inputs, the stack is not suitable for it; you need to define the array's size.

For such cases, the Heap segment is useful. Unlike the stack, heap does not have a fixed size, instead it may be seen as a pool of all the free memory available in the machine at the application's disposal. This makes dynamic memory allocation a possibility, as there is no need to know the size of a data structure at compile time. The heap can grow as long as there is any amount of memory left in the system. This also makes using the heap risky, as you may end up exhausting all the system memory through buggy code.

The heap is also called *dynamic memory*, as it can grow and shrink during execution. Using the heap in an application is called *dynamic memory allocation*. Let us now see how the heap is used in a C/C++ program.

> Note that 'heap' is also a type of data structure. The Heap segment of memory is not related in any way to the Heap Data Structure.
> There is also a data structure called the 'stack', but the Stack memory segment is actually an implementation of the Stack data structure. This is not the case with Heap.

### 4.1 Malloc, Calloc, Realloc, Free

To use dynamic memory in C/C++, we must know about four functions. These are:
1. `malloc()`
2. `calloc()`
3. `realloc()`
4. `free()`
   
C++ also has two operators related to dynamic memory, these are
1. `new`
2. `delete`

(The `new` and `delete` operators are not present in C)


#### 4.11 Malloc/new and Free/delete

Let us check out a program:

```cpp
#include <cstdlib>
#include <cstdio>

int main()
{
    int *p;
    p = (int *)malloc(sizeof(int)); // Allocate 4B for integer, use pointer p
    *p = 69;

    printf("The address that p points to: %d\nThe value stored there: %d\n", p, *p);
    free(p);
    printf("The address that p points to: %d\nThe value stored there (will be garbage now, after freeing): %d\n", p, *p);

    p = (int *)malloc(sizeof(int) * 3); // Allocate 12B for 3 integers in array, use pointer p
    p[0] = 69;
    p[1] = 4;
    p[2] = 20;

    printf("The address that p points to: %d\nThe values in array: ", p);
    for (int i = 0; i < 3; i++)
    {
        printf("%d ", *(p + i));
    }
    free(p);
    printf("\nThe address that p points to: %d\nThe value stored there (will be garbage now, after freeing): %d\n", p, *p);

    return 0;
}
```

> Note that the above code is written for C++, but uses C-style syntaxes and libraries. By changing the include statements to <stdio.h> and <stdlib.h>, the code can be made C-compatible.

In line 7, the `malloc` statement allocates a block of memory in the heap, of size 4B (integer). It returns a *void pointer* to that block of memory, which must then be typecast to `int *` so that it can be referenced by an int pointer.


Then we can store a value at that location by dereferencing it, as done in line 8.


We can then access the value and address the pointer points to as normal.


The `free` function will free up the block of dynamic memory that was previously allocated by `malloc`. It takes the address (in this case, an int pointer) as its argument.


After freeing the memory, the pointer still points to the same location, but the value at that location will be some garbage value.


`malloc` can also allocate blocks of memory for arrays. This is done by multiplying the size of one block by the number of elements required, as done in line 14 (`sizeof(int) * 3` will give value 8B). We again cast the returned value to the required `int` type. The array can then be accessed as usual using indices, and should be freed using the `free` function after we're done using it.


While the above code is perfectly fine, it follows C-standards. C++ offers operators `new` and `delete`, which perform roughly the same function as `malloc` and `free`. The advantage is that these are operators and not functions, which makes them faster. Let's now rewrite the above code to use these operators:

```cpp
#include <iostream>
using std::cout;
using std::endl;

int main()
{
    int *p;
    p = new int;
    *p = 69;

    cout << "The address that p points to: " << p << "\nThe value stored there: " << *p << endl;
    delete p;
    cout << "The address that p points to: " << p << "\nThe value stored there (garbage after deleting): " << *p << endl;

    p = new int[3];
    p[0] = 69;
    p[1] = 4;
    p[2] = 20;

    cout << "The address that p points to: " << p << "\nThe values in array: " << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << p[i] << " ";
    }
    delete[] p;
    cout << "\nThe address that p points to: " << p << "\nThe value stored there (garbage after deleting): " << *p << endl;

    return 0;
}
```

This code works exactly the same as the previous C-Style example. However, we have used the `new` and `delete` keywords (as well as `iostream` statements instead of `stdio`).


`new` works the same way as malloc, it allocates dynamic memory. However the difference is that `new` is type-safe, i.e. it takes the type as an argument and returns a pointer of the correct type. This eliminates the need to cast the return value into the required type. To allocate an array, we can use syntax such as `new int[<array_size>]`.


`delete` works the same way as `free`. To delete a pointer to a block of data (array), use square brackets, like `delete[] pointerVar;`.


#### 4.12 Calloc and Realloc

`calloc()` and `realloc()` are two other functions that deal with dynamic memory allocation. Let's first look at the working of `calloc()` using a code example:

```cpp
#include <iostream>
using std::cout;
using std::endl;

int main()
{
    int *ptr = (int *)calloc(1, sizeof(int));
    cout << "Address to which ptr points: " << ptr << "\nValue stored there after calloc: " << *ptr << endl;
    *ptr = 69;
    cout << "Value stored at *ptr after manual initialisation: " << *ptr << endl;
    free(ptr);

    int *ptr2 = (int *)calloc(3, sizeof(int));
    cout << "Address to which ptr2 points: " << ptr2 << "\nValue stored there after calloc:\n";
    for (int i = 0; i < 3; i++)
    {
        cout << ptr2[i] << " ";
    }

    ptr2[0] = 69;
    ptr2[1] = 4;
    ptr2[2] = 20;
    cout << "\nValues stored at ptr2 after initialisation:\n";
    for (int i = 0; i < 3; i++)
    {
        cout << ptr2[i] << " ";
    }
    free(ptr2);

    return 0;
}
```

`calloc()` is defined as: `void *calloc(size_t num, size_t size)`, which means we have to pass the number of memory blocks to be allocated, along with the size of each block (in line 7, `calloc(1, sizeof(int))` will allocate 1 block of 4B). `calloc` then returns a void pointer to the allocated memory, and then we cast it to the correct type.


One obvious difference between calloc and malloc is the passing of number of memory blocks as an argument. The other difference is that calloc will pre-initialise all the allocated memory blocks with value 0. This can be observed in the output of lines 15-18 in the above snippet.


Let's now look at the working of `realloc()`:

```cpp
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
    int *ptr1, *ptr2, *ptr3;
    ptr1 = (int *)malloc(sizeof(int) * 5);

    for (int i = 1; i <= 5; i++)
    {
        ptr1[i - 1] = i;
    }

    // Now what if we'd like to extend this by 5 more elements? Let's use a new pointer for that.
    ptr2 = (int *)realloc(ptr1, 2 * sizeof(int) * 5);

    cout << "\nPrevious block addr: " << ptr1 << "\nNew block addr: " << ptr2 << "\nValues at ptr2: ";

    for (int i = 0; i < 10; i++)
    {
        cout << ptr2[i] << " ";
    }

    // Now what if we want to reduce the size of this array?
    ptr3 = (int *)realloc(ptr1, sizeof(int) * 5);

    cout << "\nPrevious block addr: " << ptr2 << "\nNew block addr: " << ptr3 << "\nValues at ptr3: ";

    for (int i = 0; i < 5; i++)
    {
        cout << ptr3[i] << " ";
    }

    free(ptr1);
    free(ptr2);
    free(ptr3);

    return 0;
}
```

`realloc()` is defined as: `void *realloc(void *ptr, size_t)`.

It is used to reallocate blocks of memory, i.e. dynamically increase or decrease the size of a memory block. It takes two arguments: a pointer to the memory block which is to be manipulated, and an unsigned integral value for the size to which the block must be set.


As you can see, in line 17 of the snippet above, we call realloc on an int array of size 5. We change its size to `2 * sizeof(int) * 5`, which extends it to 40B, i.e. 10 integers.


When we print the values stored in this new block of 10 integers, the first five values are those which we initialised before, but the last 5 are garbage/unknown values, which tells us that realloc does not initialise the allocated block to any size.


Next, we changed the size back to 5 integers and used a new pointer to point to this array. The values there are again the original ones which we had initialised.


> In this example, I have stored reallocated values in different pointers. However, realloc is usually used to mutate the value of an original pointer, so it is okay to store these values in the same pointer. This is usually also more useful than using different ptrs.


> Note that if you store reallocated values in different pointers after reducing the size of the array, the original pointer will still point to the original block. In the code example above, after we set `ptr3 =  (int *)realloc(sizeof(int) * 5)`, `ptr2` would still point to the block of 10 integers that we had allocated in line 17. This behaviour can make pointers dangerous to work with sometimes, since reading/writing values at memory locations that have not been allocated to you is not safe, and might cause the program to crash or some other application's memory data to be overwritten. Always remember to be careful when dealing with memory!

> The following C snippet displays the functionality of malloc, realloc and free. Here, these functions have been used to create a dynamically expanding array, so that the user can input any number of elements to it. NOTE that such an implementation is redundant in C++, as you can simply use `std::vector` instead.

```c
#include <stdio.h>
#include <stdlib.h> /* for malloc and realloc */

int main(int argc, char** argv)
{
    int *arr = (int *)malloc(sizeof(int)); /* allocate 4B of memory (one integer) in heap */
    int num, count = 1;

    printf("Enter any number of integers, and 'ok' to confirm: ");
    while (scanf("%d", &num))
    {
        *(arr + count - 1) = num; // same as arr[count - 1] = num
        count++;
        arr = (int *)realloc(arr, (sizeof(int) * count)); // dynamically increase the size of the array by 1 each time, to allow for more values
    }

    printf("\nElements entered:");
    for (int i = 0; i < count - 1; i++) printf("%d ", arr[i]);

    return 0;
}
```


## 5. Pointers as function return types
Since a pointer is just another datatype, functions can be written to return memory addresses. This is useful when you don't want to take up too much memory in your function. Let's look at an example:


```cpp
#include <iostream>
using std::cout;
using std::endl;

int *add(int *num1, int *num2)
{
    int *sum = (int *)malloc(sizeof(int));
    *sum = *num1 + *num2;

    return sum;
}

int main()
{
    int num1 = 60;
    int num2 = 9;
    int *sum = add(&num1, &num2);

    cout << "sum is: " << *sum << endl;

    return 0;
}
```


In the example, we have defined a function `*add(int *, int *)` which takes two referential arguments and returns a pointer to integer. (This function is called by reference and teh return value is stored in a pointer in the main function)


But why have we used dynamic memory in the function there? This is because, when the called function is done executing in the stack, the memory it used is deallocated. When a different function is called in its place, the memory that it used may be allocated to the new called function. This will cause the value we stored in *sum to be overwritten. This may be observed if we don't use dynamic memory and call a different function before printing the sum in main:


```cpp
#include <iostream>
using std::cout;
using std::endl;

void sayHello()
{
    cout << "Hello World :)" << endl;
}

int *add(int *num1, int *num2)
{
    int *sum = *num1 + *num2;
    return sum;
}

int main()
{
    int num1 = 60;
    int num2 = 9;
    int *sum = add(&num1, &num2);

    sayHello();

    cout << "sum is: " << *sum << endl; // Output: Some garbage value, as the sum pointer has already been deallocated and value overwritten.

    return 0;
}
```


## 6. Pointers to Functions
Just as pointers can point to different primitive datatypes such as integers, characters etc, they can also point to the address of functions. What exactly is the address of a function? To understand this let's think about the way instructions are stored and executed in memory.


When we write code in a language such as C or C++, the compiler will generate machine code in binary that the computer can read and execute. These machine instructions are stored in the memory, within the *Code (or text)* segment. Each instruction has its own memory address and instructions are stored in a contiguous block, and executed one after the other. So for example, after a 4 byte instruction at address `204` is done executing, the machine moves on to the next instruction at `208`.


This order, can, however be changed if one of the instructions tells the machine to jump to a different instruction in memory. This is exactly what functions do.


Since functions are stored in memory just like any other value, they can be referenced by pointers. The syntax for function pointers is described in the example:

```cpp
#include <iostream>
using std::cout;
using std::endl;

int addNums(int a, int b)
{
    return a + b;
}

int main()
{
    int (*funcPtr)(int, int) = &addNums; // or just = addNums;
    int niceNumber = (*funcPtr)(60, 9); // or just funcPtr(60, 9);

    cout << niceNumber << endl;

    return 0;
}
```

### 6.1 Function pointers & Callbacks

In the previous section we wrote a snippet to illustrate how function pointers work. However, simply using a function pointer to dereference it and call the fucntion is pointless: we could just directly call the declared function instead. The real usecase of function pointers lies in the fact that, being pointers, they can be passed as arguments to functions. A function can accept a func pointer as an argument, and call-back to it later. Illustrated below:


```cpp
#include <iostream>

void sayHello(std::string name)
{
    std::cout << "Hello " << name;
}

void callingFunction(void (*funcptr)(std::string))
{
    funcptr("World");
}

int main()
{
    void (*ptr)(std::string) = &sayHello;
    callingFunction(ptr);
    // can also pass the pointer directly: callingFunction(sayHello); as name of function without () returns address
    return 0;
}
```

While this does show a use of function pointers, this is still not a very realistic use-case; `sayHello()` can also be called within the `main()` scope directly without using callbacks. Let us look at an actual scenario where callbacks are useful: Sorting Algorithms.


#### <big> 6.1.1 Bubble Sort (Without using callbacks) </big>

The [Bubble Sort Algorithm](https://en.wikipedia.org/wiki/Bubble_sort) (or sinking sort) is a simple sort algorithm that repeatedly iterates through an array, and swaps its elements if they are not in the correct order. This works by comparison logic, and is named "bubble sort" because of the way elements 'bubble' their way to the top of the array. This may be implemented as below:

```cpp
#include <iostream>
using std::cout;
using std::endl;

void bubbleSort(int array[], int length, bool ascDescFlag = true)
{
    int temp, i, j;
    for (i = 0; i < length; i++)
    {
        for (j = 0; j < length - 1; j++)
        {
            if (ascDescFlag) // ascending if ascDescFlag == true
            {
                if (array[j] > array[j + 1]) // sort ascending
                {
                    // swapping logic
                    temp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = temp;
                }
            }
            else // descending if ascDescFlag == false
            {
                if (array[j] < array[j + 1]) // sort descending
                {
                    // swapping logic
                    temp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = temp;
                }
            }
        }
    }
}

int main()
{
    int arr[] = {3, 1, 8, -3, 7, 9, 2, 4, 5, 2, 1, 8, 9, 2, 4, 5, 3};
    bubbleSort(arr, (sizeof(arr) / sizeof(arr[0])));
    for (auto i : arr)
    {
        cout << i << " ";
    }

    return 0;
}
```

This code works perfectly fine, and sorts the given array properly. However you will notice that we have to rewrite the comparison and swapping logic for both the ascending and descending sort logic, here:

```cpp
if (ascDescFlag) // ascending if ascDescFlag == true
{
    if (array[j] > array[j + 1]) // sort ascending
    {
        // swapping logic
        temp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = temp;
    }
}
else // descending if ascDescFlag == false
{
    if (array[j] < array[j + 1]) // sort descending
    {
        // swapping logic
        temp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = temp;
    }
}
```

#### <big> 6.1.2 Bubble Sort (using callbacks) </big>

All of this can be avoided by using callbacks. If you look at our logic here, if we want to sort ascending, we are checking to see if `array[j] > array[j + 1]`, and the opposite to sort descending. The logic for swapping the elements is the same in both the cases. This repetition can be avoided by writing separate comparison logic functions for ascending and descending sort, and passing them as arguments to the actual sorting function.


Since ascending requires `array[j] > array[j + 1]`, our logic could look like:

```cpp
bool ascending(int a, int b)
{
    return a > b;
}
```

And for descending which requires `array[j] < array[j + 1]`:

```cpp
bool descending(int a, int b)
{
    return a < b;
}
```

These can then be passed as pointers to the sorting function. The code can be rewritten as follows:


```cpp
#include <iostream>
using std::cout;

bool ascending(int a, int b)
{
    return a > b;
}

bool descending(int a, int b)
{
    return a < b;
}

void bubbleSort(int arr[], int length, bool (*compare)(int, int))
{
    int i, j, temp;

    for (i = 0; i < length; i++)
    {
        for (j = 0; j < length - 1; j++)
        {
            if (compare(arr[j], arr[j + 1]))
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int arr[] = {3, 4, 1, 5, 2};
    bubbleSort(arr, sizeof(arr) / sizeof(arr[0]), ascending /* or descending */); 

    for (auto i : arr)
        cout << i << " ";

    return 0;
}
```


Much cleaner, avoids repetition. As you can see, the `bubbleSort()` function now accepts a `bool` function pointer (`bool (*compare)(int, int)`), calls back to it for the comparison logic, and dynamically sorts both ascending and descending without having to repeat any code.


```cpp
if (compare(arr[j], arr[j + 1]))
{
    temp = arr[j];
    arr[j] = arr[j + 1];
    arr[j + 1] = temp;
}
```

`compare(arr[j], arr[j + 1])` will return `1` if the pointer passed was `&ascending`, and `0` otherwise. This allows for proper sorting of the given array.