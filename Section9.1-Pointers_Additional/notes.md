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

**Byte Number** | **Value Stored** | **Address (int)**     | **Address (hex)** |
----------------|------------------|-----------------------|-------------------|
`Byte 3`        | `00000000`       | `6422283`             | `61ff08`          |
`Byte 2`        | `00000000`       | `6422282`             | `61ff09`          |
`Byte 1`        | `00000100`       | `6422281`             | `61ff0a`          |
`Byte 0`        | `00000001`       | `6422280`             | `61ff0b`          |

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
|---------------|--------------------------|----------------------|
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

## 2. A pointer use-case: As function arguments (Call by value and call by reference)
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

Instead of doing this, we may **call by reference**. In that case, out `increment()` function would take a pointer or a reference as an argument. This will enable it to directly manipulate the value stored in a given memory address, thus fulfilling its purpose.

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
As you can see, this behaved as we needed it to. The `increment` function accesses the actual memory address of the variable and changes its value, which is made possible by calling the function by reference.

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
|---------------|--------------------------|----------------------|
| `myArray[0]`  | `200`                    | `c8`                 |
| `myArray[1]`  | `204`                    | `cc`                 |
| `myArray[2]`  | `208`                    | `d0`                 |
| `myArray[3[`  | `212`                    | `d4`                 |
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

### 3.1. Arrays as Function arguments

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

