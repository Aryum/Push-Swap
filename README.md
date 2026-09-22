# Push Swap

A sorting program restricted to two stacks and a small set of operations, meant to teach sorting-algorithm design under tight constraints — the goal isn't computational efficiency, but sorting the numbers in as few moves as possible.

## About

Push Swap takes a list of integers as arguments and must sort them in ascending order using only two stacks, `A` and `B`, and a limited set of stack operations. All numbers must end up sorted in stack `A`.

## Available operations

| Move | Description |
|:---:|---|
| `sa` | Swap the first two elements of stack A |
| `sb` | Swap the first two elements of stack B |
| `ss` | Equivalent to `sa` and `sb` at the same time |
| `pa` | Push the top of stack B onto stack A |
| `pb` | Push the top of stack A onto stack B |
| `ra` | Rotate stack A up (first element becomes last) |
| `rb` | Rotate stack B up (first element becomes last) |
| `rr` | Equivalent to `ra` and `rb` at the same time |
| `rra` | Reverse-rotate stack A (last element becomes first) |
| `rrb` | Reverse-rotate stack B (last element becomes first) |
| `rrr` | Equivalent to `rra` and `rrb` at the same time |

Each executed move is printed to the terminal.

## Compilation

```bash
make        # compiles the push_swap executable
make clean  # removes object files
make fclean # removes object files and the executable
make re     # recompiles everything from scratch
```

## Running

```bash
./push_swap 5 3 8 1 9 2
```

## My approach

The solution uses a **divide and conquer** strategy:

1. Numbers are split into chunks and pushed onto stack `B`, starting with the chunk of lowest values.
2. Once split, the chunks are pushed back onto stack `A` in sorted order.

### Optimizations

Beyond the base algorithm, a few optimizations were added to cut down on the number of moves:

- **Chunking two at a time** — chunks are pushed to stack `B` in pairs, with the lower of the two placed at the end of the stack, reducing repositioning later.
- **Look-ahead swaps** — when pushing numbers back, the algorithm checks whether it's cheaper to push the *next* number first and swap afterward, rather than always pushing in strict order.
- **Cheapest rotation direction** — before pushing a number between stacks, the algorithm checks whether a normal or reverse rotation gets it there in fewer moves.
- **Combined rotations** — whenever both stacks need to rotate in the same direction, `rr`/`rrr` is used instead of two separate moves.
