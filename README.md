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
  
  - `WATCH_MAP(map)` This is same as `WATCH` except that is can be used to watch the values of map such as std::map, std::unordered_map etc..

  ```cpp
  // ... Suppose main is using the template
  int main(){
      std::map<int,int> a;
      a[12] = 24;
      a[45] = 45;
      WATCH_MAP(a);
      return 0;
  }
  ```

  The above code when executed produced `Watched 12 -> 24 45 -> 45` Same as `WATCH` it will produce nothing if ran on codeforces judge.



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
| `REP(n)`          | It runs a `for` loop from 0 to n, where `t` is the loop variable leaked for indexing |
| `FOR(i,n)`        | It runs a `for` loop from 0 to n, with `i` being the loop variable    |
| `FFOR(i,j,n)`     | It runs a `for` loop from j to n, with `i` being the loop variable    |
| `FOR_S(i,n,k)`     | It runs a `for` loop from 0 to n after skipping `k` counts. `i` is the loop variable as usual. |
| `RFOR(i,n)`      | It runs a `for` loop from `n-1` to 0 (both inclusive).       |
| `RFOR_S(i,n,k)` | Same as `FOR_S` except that is runs in reverse order.    |
| `MAX_OF(x,y)`          | Returns maximum of x and y                                   |
| `MIN_OF(x,y)`          | Returns minimum of x and y                                   |
| `MIN_AT(arr)`          | Returns first index of minimum element in the container.     |
| `MAX_AT(arr)`          | Returns first index of maximum element in the container.     |
| `LCM(a,b)`             | Returns Least Common Multiple of `a` and `b`                 |
| `GCD(a,b)`             | Returns Highest Common Factor of `a` and `b`                 |
| `SORT(a)`              | Sorts a Container in ascending order.                        |
| `RSORT(a)`             | Sorts a Container in decreasing order.                       |
| `REVERSE(a)`           | Reverses the elements of a container.                        |
| `ANY(cn, res, pr)`     | Puts to res, a bool indicating if any element of the container satisfied the predicated pointed by pr. |
| `ALL(cn, res, pr)`     | Puts to res, a bool indicating if all element of the container satisfied the predicated pointed by pr. |
| `TESTCASE{...}`        | This macro takes reads a value from stdin and repeats everything in its block for that number of time  |

### Examples

* `ENDL`

  ```cpp
  int main(){
      iprint(ENDL);
      return 0;
  }
  // Prints a new line
  ```

* `REP`

  ```cpp
  int main(){
      int i, n = 50;
      REP(n){
          iprint("%d\n",t);
      }
      return 0;
  }
  // Prints 0 to 49 in new lines
  ```

* `REPEAT_BY`

  ```cpp
  int main(){
      int i, n = 20;
      FOR_S(i, n, 2){
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
      RFOR(i, n){
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
        RFOR_S(i, n, 2){
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

* `SORT`, `REVERSE`, `MAX_AT` and `MIN_AT`

  ```cpp
  int main(){
      std::vector<int> a = {1,4,5,6,0};
      SORT(a);
      assert(MIN_AT(a) == 0);
      // a is now in asceding order
      REVERSE(a);
      assert(MAX_AT(a) == 0);
      // a is now in descending order
      WATCH_CONTAINER("a is : ", a);
      return 0;
  }
  // Prints 
  // a is 6 5 4 1 0
  ```

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
- `TESTCASE` takes a input from stdin and repeats its block that number of times.

    ```cpp
    int main(){
        TESTCASE{
	   iprint("Hello world # %d",testcase);
	   // testcase is testcase variable
        }
	    return 0;
    }
    // Takes input from user and print hello world that many times.
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
#define STR std::string
#define VEC(i) std::vector<i>
#define MAP(a, b) std::map<a, b>
#define UMAP(a, b) std::unordered_map<a, b>
#defime SET(a) std::set<a>
#define USET(a) std::unordered_set<a>
#define MSET(a) std::multiset<a>
#define PAIR(a,b) std::pair<a,b>
#define PAIRI std::pair<int,int>
```

To Create a Vector of pair of int and string types you can write

```cpp
VEC(PAIR(I, STR)) a;
```

### IO Macros 
Generally speaking C style scanf and printf are faster than that of C++ `std::cout` and `std::cin`. In competitive programming every milisecond matters. So we have some general Input/Ouput macros for this task that under the hood uses those C API's for reading and writing to stdin and stdout. 

```cpp
#define READ_INT(n) // reads an int value to n
#define READ_STR(n) // reads a string to n
#define READ_LONG(n) // reads a long long value to n
#define WRITE_INT(n) // writes a int value n to stdout
#define WRITE_STR(n) // writes a string value to stdout
#define WRITE_LONG(n) // writes a long long to stdout
#define WRITE_VEC_I(n) // writes all content of vector of ints space separated to stdout
#define WRITE_VEC_LL(n) // same as above but with long long
```

Finally the template wouldn't be complete without these 
    - `pb` : push_back
    - `eb` : emplace_back
