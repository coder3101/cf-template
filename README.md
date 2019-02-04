# Codeforces C++ Template

This is a simple C++ codeforces template which you can use in your submissions. It will help you save time, efforts and will let you focus more on algorithms, than on syntax. Please Note, it has been only tested on **GNU C++17** Compiler. Make sure to use it when submitting the your code. It may work on C++11 also, you can test and report back.



## Getting Started

Simply Open the `template.cc` file and start writing your solution. You can configure your program using following MACROS.

### Configuration Macro

* `FAST_EXECUTION` When you define this Macro, the Compiler will be forced to optimise the code to `O3` level. By default CF optimises to `O2` Level. This may speed up the execution of your program. To use this option

```c++
// uncomment this line at 6
// #define FAST_EXECUTION
```

* `INTERACTIVE_MODE` Some CF Problems are interactive, they expect your program to interactively produce output. i.e Next input is not provided unless an output is produced. For More info Google it. To make your program behave like Interactive Mode. Simply,

```cpp
// uncomment this line at 7
// #define INTERACTIVE_MODE  
```



Following Macros will help you debug better.

### WATCH Macro

The template consists of a macro named `WATCH` and `WATCH_CONTAINER`. It is a intelligent macro that **will print always except when running on CF judge** . 

- `WATCH(key, val)` Calling this macro prints a value pointed by `val` and along with some identifier `key` for your readability. `Key` must be a string and `val` can be any value that can be converted to string say float, int, double, bool etc..

  ```cpp
  // ... Suppose main is using the template
  int main(){
      int a = 0;
      a = 45;
      a = (a++) + (++a);
      WATCH("a is : ", a);
      return 0;
  }
  ```

  The above code when ran locally prints `a is : 92` but when ran on codeforces judge, it will not print anything. You can use them instead of print, for debugging.

- `WATCH_CONTAINER(key, val)` This is same as `WATCH` except that is can be used to watch the value of any container such as vector, array etc..

  ```cpp
  // ... Suppose main is using the template
  int main(){
      std::vector<int> a = {1,4,6,9};
      doSomething(a);
      WATCH_CONTAINER("Container is : "a);
      return 0;
  }
  ```

  The above code when executed produced `Container is 1 4 6 9` assuming the `doSomething` function does nothing to container. Same as `WATCH` it will produce nothing if ran on codeforces judge.



### iprint Macro

This stands for `intelligent print` (just a fancy name). This macro must be used to print the values you want. The syntax is exactly same as `printf()` just the name is different. When you print using this macro, it will guarantee to flush std-out when `INTERACTIVE_MODE` is defined. Also this is faster than conventional `std::cout`.

```cpp
// .. suppose main is using the template
int main(){
    iprint("Hello world\n");
    iprint("%d",56);
    iprint("%f is float and %d is int and so on", 2.1, 5);
    return 0;
}
```



### Helper Macros

These macros contain commonly defined functions such as sorting and reversing and other such functions. Here is a quick look at the operations on such macros

| Name                   | Description                                                  |
| ---------------------- | ------------------------------------------------------------ |
| `ENDL`                 | It is just for ending the line. It is faster than `std::endl`. Always prefer this over it. |
| `REPEAT(i,n)`          | It runs a `for` loop from 0 to n, where `i` is the loop variable. |
| `REPEAT_BY(i,n,k)`     | It runs a `for` loop from 0 to n after skipping `k` counts. `i` is the loop variable as usual. |
| `REPEAT_REV(i,n)`      | It runs a `for` loop from `n-1` to 0 (both inclusive).       |
| `REPEAT_REV_BY(i,n,k)` | Same as `REPEAT_BY` except that is runs in reverse order.    |
| `MAX_OF(x,y)`          | Returns maximum of x and y                                   |
| `MIN_OF(x,y)`          | Returns minimum of x and y                                   |
| `SORT(a)`              | Sorts a Container in ascending order.                        |
| `REVERSE(a)`           | Reverses the elements of a container.                        |
| `SORT_ONLY(a,b)`       | Partially sorts the container from [a, b). Where `a` and `b` are Random Access Iterators. |
| `REVERSE_ONLY(a,b)`    | Reverses partially the elements in between `a` and `b`       |
| `ANY(cn, res, pr)`     | Puts to res, a bool indicating if any element of the container satisfied the predicated pointed by pr. |
| `ALL(cn, res, pr)`     | Puts to res, a bool indicating if all element of the container satisfied the predicated pointed by pr. |

### Examples

* `ENDL`

  ```cpp
  int main(){
      iprint(ENDL);
      return 0;
  }
  // Prints a new line
  ```

* `REPEAT`

  ```cpp
  int main(){
      int i, n = 50;
      REPEAT(i, n){
          iprint("%d\n",i);
      }
      return 0;
  }
  // Prints 0 to 49 in new lines
  ```

* `REPEAT_BY`

  ```cpp
  int main(){
      int i, n = 20;
      REPEAT_BY(i, n, 2){
          iprint("%d\n",i+1);
      }
      return 0;
  }
  // Prints Table of 2 upto 20.
  ```

- ` REPEAT_REV`

  ```cpp
  int main(){
      int i, n = 50;
      REPEAT_REV(i, n){
          iprint("%d\n",i);
      }
      return 0;
  }
  // Prints 49 to 0 in new lines
  ```

- `REPEAT_REV_BY`

  ```cpp
    int main(){
        int i, n = 20;
        REPEAT_REV_BY(i, n, 2){
            iprint("%d\n",i+1);
        }
        return 0;
    }
    // Prints Table of 2 upto 20 in reverse order.
  ```
* `MAX_OF` and `MIN_OF`

  ```cpp
  int main(){
      int a = MAX_OF(4,6);
      float b = MIN_OF(78.5, 89.5);
      return 0;
  }
  // a gets 6 and b gets 78.5
  ```

* `SORT` and `REVERSE`

  ```cpp
  int main(){
      std::vector<int> a = {1,4,5,6,0};
      SORT(a);
      // a is now in asceding order
      REVERSE(a);
      // a is now in descending order
      WATCH_CONTAINER("a is : ", a);
      return 0;
  }
  // Prints 
  // a is 6 5 4 1 0
  ```

  

- **SORT_ONLY** and **REVERSE_ONLY** works the same way except that you pass `a.begin()` and `a.begin()+n` as argument, It will then sort or reverse only first `n` elements of vector/container `a`.

- `ANY` is used to check if at least one of the elements in the container satisfied the condition.

  ```cpp
  bool func(int v){
      return v >= 0;
  };
  
  int main(){
      std::vector<int> a = {1,5,0,9,-1};
      bool result;
      ANY(a, result, func);
      iprint("%d",result);
      return 0;
  }
  // Checks if any element in the vector is more than 0.
  ```

- `ALL` checks if all the elements satisfies the condition. It can be a lambda as well or any callable.

  ```cpp
  int main(){
      std::vector<int> a = {1,5,0,9,-1};
      bool result;
      ALL(a, result, [](int v){
         return  v >= 0;
      });
      return 0;
  }
  // Checks if all elements are positive or zero
  ```



### Types Shorthands

Finally we have following shorthand notations for primitive types.

```cpp
#define LL long long
#define L long
#define ULL unsigned long long
#define I int
#define D double
#define UI unsigned int
#define VEC(i) std::vector<i>
#define MAP(a, b) std::map<a, b>
#define UMAP(a, b) std::unordered_map<a, b>
```

To Create a Vector of int types you can write

```cpp
VEC(int) a;
```

