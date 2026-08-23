# DSA Error Log

One row per problem. Solved or not.
Right-but-slow counts.

## Categories

- **A — Approach:** Didn't know / couldn't derive the approach
- **B — Speed:** Knew the approach but implemented too slowly
- **C — Bug / Edge Case:** Logic bug, missed edge case, overflow, invalid access
- **D — Misread:** Misunderstood or missed part of the specification
- **E — C++ / STL:** Syntax, API, iterator, type, comparator, STL friction

## Target Times

- Easy: < 10 min
- Medium: 15–25 min
- Hard implementation: < 35 min

---

## Problems

| Date | Problem | Difficulty | Time | Result | Cat | What happened | Rule for next time |
|---|---|---|---|---|---|---|---|
| 20 Aug | 1342 Reduce Number to Zero | Easy | 10m | AC | B | Correct, but too slow for a trivial implementation | Recognise simple simulation immediately |
| 20 Aug | 2285 Maximum Total Importance | Medium | — | AC | D | Built connected components even though graph structure wasn't needed | Write the objective mathematically before choosing an algorithm |
| 21 Aug | 68 Text Justification | Hard | — | AC | C | Added a word before checking whether it fit | Check the condition before modifying state |
| 23 Aug | 1801 Orders in Backlog | Medium | — | AC | C | Called `.top()` without checking whether the heap was empty | Check emptiness before `.top()`, `.front()`, `.back()`, or `.pop()` |
| 23 Aug | 703 Kth Largest in a Stream | Easy | ?m | AC | — | Clean | Fixed-size heap: push, then pop if `size() > k`. Min-heap, so the top *is* the kth largest |
| 23 Aug | 1046 Last Stone Weight | Easy | ?m | AC | — | Clean | Repeated-extremum shape: pop two, push the difference back, loop while `size() > 1` |
| 23 Aug | 215 Kth Largest in an Array | Medium | ?m | AC | — | Clean | Size-k min-heap is O(n log k). If you sorted, that's O(n log n) — slower, and the interviewer notices |
| 23 Aug | 973 K Closest Points | Medium | ?m | AC | — | Clean | Compare squared distances. Never `sqrt` — it costs time and introduces float error for no gain |


---

## Standing Rules

Rules that have appeared often enough that I want them in my head during an OA.

1. **Check emptiness before container access.**
2. **Use `long long` for potentially large accumulations.**
3. **Check a condition before changing state.**
4. **Write the objective mathematically before picking an algorithm.**
5. **For `&&`, put safety checks first because evaluation short-circuits left to right.**

---

## Category Tally

| Category | Count |
|---|---:|
| A — Approach | 0 |
| B — Speed | 1 |
| C — Bug / Edge | 2 |
| D — Misread | 1 |
| E — C++ / STL | 0 |
