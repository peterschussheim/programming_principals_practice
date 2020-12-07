# Chapter 25 - Review

1. What is an embedded system? Give ten examples, out of which at least
three should not be among those mentioned in this chapter.

An embedded system is a "computer" which may not be immediately recognizable
as a computer, moreover, embedded systems may comprise multiple subsystems 
which when discussed in the context of a larger system, enable interesting
features enabled by computers.

Examples of embedded systems include (1) cars, (2) mobile phones, (3) televisions,
(4) calculators, (5) electric toothbrushes, (6) electric shavers, (7) cable TV
boxes, (8) network routers, (9) digital voice recorders, and (10) industrial
measurement devices.

2. What is special about embedded systems? Give five concerns that are
common.

Reliability is critical, resources are limited, (often,) real-time response is
critical and required, downtime is often minimal (5 minute downtime per 20 years)
or forbidden and lastly, hands-on maintenance is often totally unfeasible or 
rare.

3. Define predictability in the context of embedded systems.

An operation is said to be "predictable" in this context if it takes the same
amount of time to execute every time it is executed on a given computer and if 
all such operations take the same amount of time to execute.

4. Why can it be hard to maintain and repair an embedded system?


5. Why can it be a poor idea to optimize a system for performance?


6. Why do we prefer higher levels of abstraction to low-level code?


7. What are transient errors? Why do we particularly fear them?


8. How can we design a system to survive failure?


9. Why can’t we prevent every failure?


10. What is domain knowledge? Give examples of application domains.

11. Why do we need domain knowledge to program embedded systems?


12. What is a subsystem? Give examples.


13. From a C++ language point of view, what are the three kinds of storage?

14. When would you like to use the free store?

15. Why is it often infeasible to use the free store in an embedded system?

16. When can you safely use new in an embedded system?

17. What is the potential problem with std::vector in the context of embed-
ded systems?

18. What is the potential problem with exceptions in the context of embed-
ded systems?

19. What is a recursive function call? Why do some embedded systems pro-
grammers avoid them? What do they use instead?

20. What is memory fragmentation?

21. What is a garbage collector (in the context of programming)?
22. What is a memory leak? Why can it be a problem?
23. What is a resource? Give examples.
24. What is a resource leak and how can we systematically prevent it?
25. Why can’t we easily move objects from one place in memory to another?
26. What is a stack?
27. What is a pool?
28. Why doesn’t the use of stacks and pools lead to memory fragmentation?
29. Why is reinterpret_cast necessary? Why is it nasty?
30. Why are pointers dangerous as function arguments? Give examples.
31. What problems can arise from using pointers and arrays? Give examples.
32. What are alternatives to using pointers (to arrays) in interfaces?
33. What is “the first law of computer science”?
34. What is a bit?
35. What is a byte?
36. What is the usual number of bits in a byte?
37. What operations do we have on sets of bits?
38. What is an “exclusive or” and why is it useful?
39. How can we represent a set (sequence, whatever) of bits?
40. How do we conventionally number bits in a word?
41. How do we conventionally number bytes in a word?
42. What is a word?
43. What is the usual number of bits in a word?
44. What is the decimal value of 0xf7 ?
45. What sequence of bits is 0xab ?
46. What is a bitset and when would you need one?
47. How does an unsigned int differ from a signed int ?
48. When would you prefer an unsigned int to a signed int ?
49. How would you write a loop if the number of elements to be looped over
was very high?
50. What is the value of an unsigned int after you assign –3 to it?
51. Why would we want to manipulate bits and bytes (rather than higher-
level types)?
52. What is a bitfield?
53. For what are bitfields used?
54. What is encryption (enciphering)? Why do we use it?
55. Can you encrypt a photo?