# Push Swap

A sorting algorithm we built together that sorts a stack of integers using two stacks (A and B) with a limited set of operations. **Written with AI code generation assistance.**

## What We Built

Push Swap takes a list of unsorted integers and sorts them using only two stacks and specific operations (push, swap, rotate). The challenge: do it with the minimum number of moves possible.

### The Challenge
- **Input**: Random integers (space-separated or individual args)
- **Goal**: Sort stack A in ascending order
- **Rules**: Only use push, swap, and rotate operations on two stacks
- **Constraint**: No duplicate values allowed
- **Validation**: Reject non-integer or malformed input

## Our Algorithm: The Turkish Algorithm

We chose a **cost-based greedy approach** that works in three phases:

### Phase 1: Smart Pushing
We figured out that instead of pushing random elements, we calculate the "cost" of each move:
- How many rotations to bring an element to the top of stack A?
- How many rotations to bring its target position to the top of stack B?
- Pick the cheapest overall move and execute it

**Why this matters**: We can rotate both stacks simultaneously with `dr` and `drr` operations, so sometimes it's faster to rotate both at once.

### Phase 2: Handle the Last 3
Once we're down to 3 elements in A, we use hardcoded sorting logic (`sort3()`) because there are only 6 possible permutations—we handle each one directly.

### Phase 3: Rebuild Stack A
We push everything back from B to A, each element going to its correct position. For each element in B, we find where it belongs in A (the smallest number larger than it), rotate A to that position, then push it on top.

**The insight**: By handling the return journey strategically, we keep the operation count low.

## Algorithm Flow

**Entry point** (`main.c` → `push_swap.c`):
1. Parse arguments (handle both `"1 2 3"` and `1 2 3` formats)
2. Validate: Are they numbers? Any duplicates?
3. Convert to linked list (stack A)
4. Route based on size:
   - ≤2 elements: `s()` (swap only)
   - 3 elements: `sort3()` (6 hardcoded cases)
   - 4+ elements: `turkalg()` (cost-based algorithm)

**The algorithm** (`turkalg.c`):
- Loop: pick cheapest element to push to B until only 3 left
- Sort those 3
- Push everything back from B to A in order

### Memory Layout
- Only 2 stacks exist at runtime: `*astack` and `*bstack` (local in `turkalg()`)
- All allocations tied to linked list nodes via `malloc(sizeof(t_stack))`
- No global state—fully stack-based

## Build & Run

### Get It Built
```bash
make          # Compile everything
make clean    # Remove temp files
make fclean   # Full clean
make re       # Rebuild from scratch
```

### Try It Out
```bash
# Space-separated
./push_swap "3 2 1 0"

# Multiple arguments
./push_swap 5 2 8 1 9

# See what happens with unsorted numbers
./push_swap 42 17 63 29 81
```

The program outputs the operations we performed. Pipe it to see how many it takes:
```bash
./push_swap "3 2 1" | wc -l    # Count operations
./push_swap 5 4 3 2 1 | wc -l  # Worst case
```

### Valid Operations We Use
| Op | What it does |
|----|---|
| `sa` / `sb` | Swap top 2 of stack A or B |
| `pa` / `pb` | Push top of one stack onto the other |
| `ra` / `rb` | Rotate up (move top to bottom) |
| `rra` / `rrb` | Rotate down (move bottom to top) |
| `rr` / `rrr` | Do both stacks at once (saves moves!) |

## Project Structure

```
push_swap/
├── main.c                    # Entry point, argument parsing, cleanup
├── push_swap.c               # Main logic & validation
├── turkalg.c                 # The core algorithm
├── turkalg_back.c            # Phase 3 logic
├── cheap_and_cost_find.c     # Cost calculation magic
├── rotate.c                  # Rotation optimization
├── smallsort.c               # Hardcoded 3-element sorts
├── single_operations.c       # Single stack ops
├── double_operations.c       # Dual stack ops
├── helper.c                  # Utilities & list functions
├── min_max_find.c            # Find min/max quickly
├── push_swap.h               # All declarations
├── libft/                    # Our utility library
└── Makefile                  # Build rules
```

## The Data Structure We Use

```c
typedef struct s_stack {
    ssize_t      num;      // The actual number
    int          index;    // Where it is (0 = top)
    t_stack     *next;     // Next in the list
    t_stack     *tar;      // Where it's going in the other stack
    int          cost;     // How expensive to move it
    t_stack     *min;      // Reference to smallest
    t_stack     *max;      // Reference to largest
}
```

We use linked lists because they're perfect for stack operations (add/remove from head).

## Code Patterns & How We're Organizing

### Linked List Operations
All use custom implementations (not libft):
- `ft_lstadd_back()`: Recursive append (safe for our sizes)
- `ft_lstlast()`: Find tail (O(n))
- `second_to_last()`: Rotate helper (O(n))
- **Pattern**: Always update head via double pointer `**stack`

### Operation Functions
All operations:
1. Modify stack structure
2. Call `write(1, "op\n", len)` to output operation
3. Take operation name as parameter: `r(head, "ra\n")` vs `r(head, "rb\n")`

```c
void r(t_stack **head, char *op) {
    // Rotate: move top to bottom
    // Then: write(1, op, 3);
}
```

### Cost Calculation (Our Secret Sauce)
Three-stage process in `push_cheapest()`:
1. `find_targets()`: Each node in source finds best match in destination
2. `calculate_costs()`: Compute moves needed (index-based + median comparison)
3. `get_cheapest()`: Sum costs, return minimum

**Index Rule**: If `index <= median`, use forward rotate; else reverse rotate

### Input Parsing
- **2 args**: `ft_split(argv[1], ' ')` returns dynamically allocated array
- **3+ args**: `copy_without_first(argv)` manually duplicates argv[1..n]
- **Both return**: NULL-terminated `char**` array (must be freed)

### Error Handling
- Returns `-1` for allocation failures
- Returns `1` for invalid input (non-numbers, duplicates)
- Cleans all memory before returning

## Key Functions We Wrote

| Function | What it does | File |
|----------|---|---|
| `turkalg()` | Main loop pushing cheapest | turkalg.c |
| `find_best_target()` | Find where element goes | cheap_and_cost_find.c |
| `calculate_moves()` | How many rotations needed | cheap_and_cost_find.c |
| `get_cheapest()` | Sum costs, find minimum | cheap_and_cost_find.c |
| `execute_moves()` | Do the rotations smartly | turkalg.c |
| `rotate_both()` | Use dr/drr together | rotate.c |
| `sort3()` | Hardcoded 6 cases | smallsort.c |
| `check()` | Validate input | push_swap.c |
| `convert()` | Build linked list | push_swap.c |
| `check_double()` | Detect duplicates | main.c |

## Conventions We're Following

- **ssize_t everywhere**: Handles negatives and edge cases like `-2147483648`
- **Custom utilities**: We have our own `ft_atoi()`, linked list functions (don't use stdlib)
- **Double pointers for modification**: `void func(t_stack **stack)` means we modify the head
- **Only write() for output**: No printf—POSIX compliance
- **Always check NULL**: Before freeing or dereferencing
- **nodecount(t_stack **stack)**: Pass as double pointer for consistency

## Memory Management

We're strict about cleaning up:
- `free_stack()` - Deallocate the whole linked list
- `free_args()` - Deallocate parsed arguments
- Every error path cleans up before returning

No memory leaks. We made sure of it.

## When You Want to Add Something

### New operation?
1. Write it in `single_operations.c` or `double_operations.c`
2. Add declaration to `push_swap.h`
3. Make sure it calls `write(1, "op_name\n", len)` at the end
4. Example: `s()` swaps top 2, then outputs "sa\n" or "sb\n"

### Better cost logic?
1. Modify `find_best_target()` to find targets differently
2. Update `calculate_moves()` if rotation cost changes
3. Test with `make_index()` calls before AND after all rotations

### Fix a bug?
- **Stale indices**: Call `make_index()` after any rotation
- **Wrong target**: Debug `find_best_target()` by printing `node->num` and `tar->num`
- **Segfault**: Check NULL in functions that take stacks
- **Memory leak**: Trace `malloc()` calls—every one needs a matching `free()`

## Testing & Debugging

```bash
make                          # Build (debug symbols with -g)
./push_swap "3 2 1"          # Run a test
./push_swap 5 4 3 2 1        # Multiple args
./push_swap "invalid"        # Should error gracefully
echo $?                       # Check return code
```

**Common Issues**:
- Double push without reindex → stale indices
- Missing `make_index()` after rotation → cost calculation wrong
- Stack NULL check missing → segfault on edge cases

**Pro tip**: Pipe to `wc -l` to count operations:
```bash
./push_swap "5 4 3 2 1" | wc -l
```

## What We Learned

The hardest parts:
1. Keeping indices accurate after every rotation
2. Balancing between double rotations and single rotations
3. Finding the true "cheapest" move without exploring exponentially many options

The wins:
- The cost calculation is clean and understandable
- Double rotations save significant operation counts
- Hardcoding the 3-element cases was way faster than general logic

## Edge Cases We Handle

- Empty stack or single element
- Already sorted (no output)
- Duplicates (error)
- Negative numbers (custom atoi handles them)
- Very large numbers (`ssize_t` prevents overflow issues)
- Space-separated vs. multiple arguments

## Performance Reality Check

- **O(n²)** for cost calculation in worst case (nested loops in `find_best_target()`)
- **O(n)** per rotation (have to walk the list to reindex)
- For **100 elements**, you'll see ~500-600 operations (not optimal, but reasonable)
- Turkalg is **not mathematically optimal** (some inputs need >O(n log n) ops)
- **Trade-off**: Simple greedy logic vs. complex optimal search

We trade optimality for simplicity—this algorithm is easy to understand and modify.

## Our Approach

- **Modular design**: Each operation type lives in its own file
- **Custom utilities**: Implemented our own `ft_atoi()`, linked list functions
- **Strict compilation**: `-Wall -Wextra -Werror` catches everything
- **Readable code**: Anyone should understand what each function does
- **With AI help**: Code generation sped up development while we handled review and refinement

---

**Remember**: When you're stuck, add print statements to see what `index`, `cost`, and `tar->num` look like. That usually reveals the bug.

**Note**: This was written with AI code generation—we used it to accelerate development while maintaining code quality and algorithm correctness through careful review.