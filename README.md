# get_next_line

A C function that returns a file descriptor's contents one line at a time. You call it again and
again until it returns `NULL`. It works on files, standard input and anything else you can `read()`
from. Part of the 42 Madrid common core.

What makes it interesting is the **static variable**: `read()` hands back chunks of `BUFFER_SIZE` bytes
that rarely end on a newline, so whatever is left after the line has to survive until the next call,
without leaking memory.

**Grade: 125/100** (with bonus)

## Usage

```c
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

int main(void)
{
    int   fd = open("tests/lore.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);   // the line keeps its '\n'
        free(line);
    }
    close(fd);
    return (0);
}
```

```bash
cc -D BUFFER_SIZE=42 main.c get_next_line.c get_next_line_utils.c
```

`BUFFER_SIZE` defaults to 10 and can be set at compile time, from 1 up to very large values. Pass
`0` as the descriptor to read from standard input.

## Bonus

`get_next_line_bonus.c` can read from **several file descriptors at once**, alternating between
them, without losing its place in any. It keeps one leftover buffer per descriptor in a single static
array.

```bash
cc -D BUFFER_SIZE=42 main.c get_next_line_bonus.c get_next_line_utils_bonus.c
```

## Files

| File | Contents |
|---|---|
| `get_next_line.c` / `.h` | The function |
| `get_next_line_utils.c` | String helpers |
| `*_bonus.c` / `*_bonus.h` | The version with multiple descriptors |
| `tests/` | Edge-case inputs: empty file, one character, only newlines, a giant line… |

## Testing

[Francinette](https://github.com/xicodomingues/francinette): `paco` passes every standard test. In
strict mode two tests can time out. Give them more time with `paco -s -tm 1000000`.

---

Made by **Juan Bautista Delorme** (`jdelorme`) at 42 Madrid ·
[Portfolio](https://juandelorme-portfolio.volmer.es) · [LinkedIn](https://www.linkedin.com/in/jdelorme/) · [42 intra](https://profile.intra.42.fr/users/jdelorme)
