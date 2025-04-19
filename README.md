
# Codeforces C++ Template

This is a simple C++ template for Codeforces that you can use in your submissions. It helps save time and effort, allowing you to focus more on algorithms than on syntax.  
**Note**: This template has been tested only with the **GNU C++17** compiler. Please make sure to use it when submitting your code. It may also work with C++11, but you'll need to test and confirm that yourself.

---

## Getting Started

Simply open the `template.cc` file and start writing your solution. You can configure the program using the following macros:

---

### Configuration Macros

- **`FAST_EXECUTION`**  
  Defining this macro forces the compiler to optimize your code at the `O3` level. By default, Codeforces uses `O2` optimization. This may improve execution speed.

  To enable this, uncomment the line at line 6:
  ```cpp
  // #define FAST_EXECUTION
  ```

- **`INTERACTIVE_MODE`**  
  Some Codeforces problems are interactive, meaning the input is only provided after your program produces an output. To enable interactive behavior:

  Uncomment the line at line 7:
  ```cpp
  // #define INTERACTIVE_MODE
  ```

---

### Debugging Macros

#### `WATCH` and `WATCH_CONTAINER`

These intelligent macros print debugging information **only when running locally**, not on the Codeforces judge.

- **`WATCH(key, val)`**  
  Prints the value pointed to by `val` with an identifier `key` for clarity. `key` must be a string, and `val` can be any printable type (e.g., `int`, `float`, `bool`, etc.).

  ```cpp
  int main(){
      int a = 0;
      a = 45;
      a = (a++) + (++a);
      WATCH("a is: ", a);
      return 0;
  }
  ```

  When run locally, this will print:  
  `a is: 92`  
  It prints nothing on the Codeforces judge.

- **`WATCH_CONTAINER(key, val)`**  
  Same as `WATCH`, but designed for containers like `vector`, `array`, etc.

  ```cpp
  int main(){
      std::vector<int> a = {1, 4, 6, 9};
      doSomething(a);
      WATCH_CONTAINER("Container is: ", a);
      return 0;
  }
  ```

  Output (locally):  
  `Container is: 1 4 6 9`

- **`WATCH_MAP(map)`**  
  Designed for `std::map`, `std::unordered_map`, etc.

  ```cpp
  int main(){
      std::map<int, int> a;
      a[12] = 24;
      a[45] = 45;
      WATCH_MAP(a);
      return 0;
  }
  ```

  Output (locally):  
  `Watched 12 -> 24 45 -> 45`

---

### `iprint` Macro

This stands for **intelligent print**. It mimics the behavior of `printf()` but ensures flushing of `stdout` when `INTERACTIVE_MODE` is defined. It's also faster than using `std::cout`.

```cpp
int main(){
    iprint("Hello world\n");
    iprint("%d", 56);
    iprint("%f is float and %d is int", 2.1, 5);
    return 0;
}
```

---

### Helper Macros

These macros simplify common operations:

| Name               | Description                                                                 |
|--------------------|-----------------------------------------------------------------------------|
| `ENDL`             | Faster line ending; preferred over `std::endl`                              |
| `REP(n)`           | Loop from 0 to n with loop variable `t` exposed                            |
| `FOR(i,n)`         | Loop from 0 to n with loop variable `i`                                     |
| `FFOR(i,j,n)`      | Loop from `j` to `n` with loop variable `i`                                 |
| `FOR_S(i,n,k)`     | Loop from 0 to `n`, skipping `k` steps                                      |
| `RFOR(i,n)`        | Reverse loop from `n-1` to 0                                                |
| `RFOR_S(i,n,k)`    | Reverse loop with a step of `k`                                             |
| `MAX_OF(x,y)`      | Returns maximum of x and y                                                  |
| `MIN_OF(x,y)`      | Returns minimum of x and y                                                  |
| `MIN_AT(arr)`      | Returns index of the minimum element                                        |
| `MAX_AT(arr)`      | Returns index of the maximum element                                        |
| `LCM(a,b)`         | Returns Least Common Multiple                                               |
| `GCD(a,b)`         | Returns Greatest Common Divisor                                             |
| `SORT(a)`          | Sorts container in ascending order                                          |
| `RSORT(a)`         | Sorts container in descending order                                         |
| `REVERSE(a)`       | Reverses the container                                                      |
| `ANY(c, r, p)`     | Sets `r` to true if **any** element in `c` satisfies predicate `p`          |
| `ALL(c, r, p)`     | Sets `r` to true if **all** elements in `c` satisfy predicate `p`           |
| `TESTCASE{...}`    | Repeats the block based on input number of test cases                       |

---

### Examples

- **`ENDL`**
  ```cpp
  iprint(ENDL); // Prints newline
  ```

- **`REP`**
  ```cpp
  REP(n) {
      iprint("%d\n", t);
  }
  ```

- **`FOR_S`**
  ```cpp
  FOR_S(i, n, 2){
      iprint("%d\n", i + 1);
  }
  ```

- **`RFOR`**
  ```cpp
  RFOR(i, n){
      iprint("%d\n", i);
  }
  ```

- **`RFOR_S`**
  ```cpp
  RFOR_S(i, n, 2){
      iprint("%d\n", i + 1);
  }
  ```

- **`MAX_OF`, `MIN_OF`**
  ```cpp
  int a = MAX_OF(4, 6);
  float b = MIN_OF(78.5, 89.5);
  ```

- **`SORT`, `REVERSE`, `MAX_AT`, `MIN_AT`**
  ```cpp
  std::vector<int> a = {1, 4, 5, 6, 0};
  SORT(a);
  assert(MIN_AT(a) == 0);
  REVERSE(a);
  assert(MAX_AT(a) == 0);
  WATCH_CONTAINER("a is: ", a);
  ```

- **`ANY`**
  ```cpp
  bool func(int v) { return v >= 0; }
  std::vector<int> a = {1, 5, 0, 9, -1};
  bool result;
  ANY(a, result, func);
  iprint("%d", result);
  ```

- **`ALL`**
  ```cpp
  std::vector<int> a = {1, 5, 0, 9, -1};
  bool result;
  ALL(a, result, [](int v) {
     return v >= 0;
  });
  ```

- **`TESTCASE`**
  ```cpp
  TESTCASE {
      iprint("Hello world # %d", testcase);
  }
  ```

---

### Type Shorthands

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
#define SET(a) std::set<a>
#define USET(a) std::unordered_set<a>
#define MSET(a) std::multiset<a>
#define PAIR(a,b) std::pair<a,b>
#define PAIRI std::pair<int,int>
```

To create a vector of `pair<int, string>`:

```cpp
VEC(PAIR(I, STR)) a;
```

---

### IO Macros

C-style `scanf` and `printf` are generally faster than `cin`/`cout`, which can be crucial in competitive programming.

```cpp
#define READ_INT(n)       // Reads an int value into n
#define READ_STR(n)       // Reads a string into n
#define READ_LONG(n)      // Reads a long long into n
#define WRITE_INT(n)      // Writes an int value to stdout
#define WRITE_STR(n)      // Writes a string to stdout
#define WRITE_LONG(n)     // Writes a long long to stdout
#define WRITE_VEC_I(n)    // Writes vector<int> contents space-separated
#define WRITE_VEC_LL(n)   // Writes vector<long long> contents space-separated
```

---

Finally, these commonly used macros are included:

- `pb` : shorthand for `push_back`
- `eb` : shorthand for `emplace_back`
