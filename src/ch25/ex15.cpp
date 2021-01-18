// Measure the time (§26.6.1) it takes to allocate 10,000 objects of random
// sizes in the [1000:0)-byte range using new ; then measure the time it takes
// to deallocate them using delete . Do this twice, once deallocating in the
// reverse order of allocation and once deallocating in random order. Then,
// do the equivalent for allocating 10,000 objects of size 500 bytes from a
// pool and freeing them. Then, do the equivalent of allocating 10,000 ob-
// jects of random sizes in the [1000:0)-byte range on a stack and then free
// them (in reverse order). Compare the measurements. Do each measure-
// ment at least three times to make sure the results are consistent.