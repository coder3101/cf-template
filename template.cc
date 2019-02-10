

// #define FAST_EXECUTION
// #define INTERACTIVE_MODE

#include <algorithm>
#include <cstdio>
#include <map>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <cmath>
// add more headers here depending upon the need.

#ifndef ONLINE_JUDGE
#define WATCH(key, val) \
  printf("Watched %s ->  %s \n", key, std::to_string(val).c_str());
#define WATCH_CONTAINER(key, val)                              \
  printf("Watched %s : ", key);                                \
  for (auto e : val) printf(" %s", std::to_string(e).c_str()); \
  printf("\n");
#define WATCH_MAP(map)                                    \
  printf("Watching Map\n");                               \
  for (auto e : map)                                      \
    printf("%s -> %s\n", std::to_string(e.first).c_str(), \
           std::to_string(e.second).c_str());             \
  printf("\n");
#else
#define WATCH(key, val) \
  do {                  \
  } while (false);
#define WATCH_CONTAINER(key, val) \
  do {                            \
  } while (false);
#define WATCH_MAP(map) \
  do {                 \
  } while (false);
#endif

#ifdef FAST_EXECUTION
#pragma GCC optimize("O3")
#endif

#define ENDL ("\n")
#define REPEAT(i, n) for (i = 0; i < n; i++)
#define REPEAT_BY(i, n, k) for (i = 0; i < n; i += k)
#define REPEAT_REV(i, n) for (i = n - 1; i >= 0; i--)
#define REPEAT_REV_BY(i, n, k) for (i = n - 1; i >= 0; i -= k)
#define MAX_OF(x, y) x > y ? x : y
#define MIN_OF(x, y) x > y ? y : x
#define SORT(A) std::sort(A.begin(), A.end());
#define REVERSE(A) std::reverse(A.begin(), A.end());
#define SORT_ONLY(a, b) std::sort(a, b);
#define REVERSE_ONLY(a, b) std::reverse(a, b);
#define ANY(container, result, condition) \
  result = false;                         \
  for (const auto &e : container)         \
    if (condition(e)) {                   \
      result = true;                      \
      break;                              \
    }
#define ALL(container, result, condition) \
  result = true;                          \
  for (const auto &e : container)         \
    if (!condition(e)) {                  \
      result = false;                     \
      break;                              \
    }
#define READ_AND_REPEAT(t, a) \
  scanf("%d", &a);            \
  REPEAT(t, a)
#ifdef INTERACTIVE_MODE
#define iprint(...)    \
  printf(__VA_ARGS__); \
  fflush(stdout);
#else
#define iprint(...) printf(__VA_ARGS__);
#endif

#define LL long long
#define L long
#define ULL unsigned long long
#define I int
#define D double
#define UI unsigned int
#define VEC(i) std::vector<i>
#define MAP(a, b) std::map<a, b>
#define UMAP(a, b) std::unordered_map<a, b>

int main() {

  // Your Code goes here...
  
  return 0;
}
