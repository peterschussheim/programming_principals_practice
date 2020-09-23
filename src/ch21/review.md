Chapter 21

# Review

### 1. What are examples of useful STL algorithms?

copy, copy_if, find, find_if, for_each, swap, reverse, remove_if, sort, accumulate,
inner_product.

### 2. What does find() do? Give at least five examples.

`find()` searches for a given value in a sequence specified as a pair of iterators.
Besides simply searching a sequence for a specific value, `find()` can be used to
determine the existance of a value (target) by comparing the result of `find()`
to the source container `end()` method.  Because `find()` specifies a common 
interface of iterators (InputIt and ForwardIt), we can apply the algorithm to 
any sequence which implements the relevant iterators.  Additionally, besides 
simply scanning from the start to end of a given container, users may specify a 
range to search in.

### 3. What does count_if() do?

`count_if()` is a variation of `count()` which lets users specify a unary predicate.
In practice, one may use it in a program to, for example, count the number of
uppercase charcters in a document which are either "A", "L" or "Z".

### 4. What does sort(b,e) use as its sorting criterion?

`sort(b,e)` uses by default, non-descending ordering, ex: `a < e`.

### 5. How does an STL algorithm take a container as an input argument?

A pair of iterators: `InputIter` and `ForwardIter`.

### 6. How does an STL algorithm take a container as an output argument?

We specify the output argument of an STL algorithm via a single ForwardIter to 
its first element.

### 7. How does an STL algorithm usually indicate “not found” or “failure”?

Returns a ForwardIter to one past the last element in the sequence, ex:

```cpp
if(p != vd.end()) {
    // success
} else {
    // failure or not found
}
```

### 8. What is a function object?

A function object is an object which behaves like a regular function in the sense 
that is can be called using the function call operator or application operator 
and additionally stores data which can be states another way as some "state" to 
be used to compare values when passed to an algorithm.  The basic formula to 
write a function object is best summarized with an example:

```cpp
class F {
  S s;    // state
public:
  F(const S& ss) :s{ss} { // establish initial state }
  T operator()(const S& ss) const
  {
    // do something with ss to s
    // return a value of type T, which is often void, bool, or S
  }
  const S& state() const { return s; }   // reveal state
  void reset(const S& ss) {s = ss; }     // reset state
};
```

### 9. In which ways does a function object differ from a function?

A function object stores some data or state.

### 10. What is a predicate?

A predicate is a function which checks its argument(s) against some criteria 
and returns a boolean.

### 11. What does accumulate() do?

Given some sequence of elements from a container (InputIter, ForwardIter), and an
initial value, `accumulate()` returns the sum of the sequence `[first,last)` by
applying `opterator+()` to each element.  An overloaded version of `accumulate()`
accepts a `BinaryOperation` from the user which allows for other arithematic 
operations.

### 12. What does inner_product() do?

`inner_product()` returns the result of multiplying each element with identical 
subscripts or "indices" from two sequences..

### 13. What is an associative container? Give at least three examples.

An associative container is an ordered container which provides efficient lookup
of some value using a key, for example: `int p_cost = price_map[widget_9779];`.
Examples from the STL include `map`, `unordered_map`, `set`, and `multimap`.

### 14. Is list an associative container? Why not?

No, a `list` is not an associative container because it does not provide lookup 
using a key, only linear search.

### 15. What is the basic ordering property of binary tree?

Given a binary tree node with a root node and left, right children nodes, all 
nodes to the left of the root node are less than the root node's key and all 
nodes to the right of the root node are greater than the root node's key.

### 16. What (roughly) does it mean for a tree to be balanced?

A tree is balanced when each sub-tree has approximately as many nodes as every 
other sub-tree that's equally far from the root.  This minimizes the average 
number of nodes we need to look at to reach a desired node.

### 17. How much space per element does a map take up?

`std::map` stores its key, value and two pointers to its left and right children 
nodes.  The actual amount of memory used is implementation-dependent.

### 18. How much space per element does a vector take up?

Just the amount of space the underlying vector is templated to.  Note, this is 
also implementation-dependent.

### 19. Why would anyone use an unordered_map when an (ordered) map is available?

When keys are strings and (obviously) ordering is not important.

### 20. How does a set differ from a map?

A `set` is and ordered container of keys whereas a `map` is an ordered container
 of (key, value) pairs.

### 21. How does a multimap differ from a map ?

`multimap` allows duplicate keys.

### 22. Why use a copy() algorithm when we could “just write a simple loop”?

Future maintenance of code, common interface, abstraction, potential reduction 
of bugs relating to range errors from hand-written loops, and potential performance 
optimizations.

### 23. What is a binary search?

Binary search is an algorithm which is used to determine the existance of an element 
within a container.  The core idea is to (assuming we are looking for the value `x`): 

- begin at the middle element of the sequence
  - if the element equals `x`, we found it
  - if the element's value is less than `x`, any element with value `x` must be located 
    to the right, so we look at the right half of the sequence (calling the binary 
    search on that half).
  - if the value of `x` is less than the elemen's value, any element with value 
    `x` must be to the left, so we look at the left half (calling binary search on the left half).
  - if we reach the last element (going left or right) without finding `x`, then
    we know there is no element in the sequence with that value.