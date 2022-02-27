# ft_dprintf
It is library that contains ft_dprintf, a function that will mimic the original dprintf.

## Description
ft_dprintf interprets the following format rules.

`%[flags][minimum field width].[precision][conversion specifier]`

- Flags : `'-', '0', '#', ' ', '+'`
    - `'-'` : Left justified.
    - `'0'` : Zero padding.
    - `'#'` : Alternate form.
    - `' '` : Negative field width flag.
    - `'+'` : Negative field width flag.

- Conversion specifier : `'c', 's', 'p', 'd', 'i', 'u', 'x', 'X', '%'`
    - `%c` : Prints a single character.
    - `%s` : Prints a string.
    - `%p` : The void * pointer argument has to be printed in hexadecimal format.
    - `%d` : Prints a decimal (base 10) number.
    - `%i` : Prints an integer in base 10.
    - `%u` : Prints an unsigned decimal (base 10) number.
    - `%x` : Prints a number in hexadecimal (base 16) lowercase format.
    - `%X` : Prints a number in hexadecimal (base 16) uppercase format.
    - `%%` : Prints a percent sign.

## Usage
Compile and use as below.

```bash
$ make
$ gcc -Wall -Wextra -Werror <file_name> -I<include_paths> -L<library_path> -lftdprintf
$ ./a.out
```

ft_dprintf can be used in the same way as dprintf as shown below.

```c
/* Use ft_dprintf */
ft_dprintf(1, "/* Output */\n");
ft_dprintf(1, "<%c>\n", 'A');
ft_dprintf(1, "<%s>\n", "Hello World!!!");
ft_dprintf(1, "<%d>\n", 42);
ft_dprintf(1, "<%x>\n", 123456789);
ft_dprintf(1, "<%%>\n");
```

```planetext
/* Output */
<A>
<Hello World!!!>
<42>
<75bcd15>
<%>
```

## Example
Include ft_dprintf.h and compile your code with libftdprintf.a.

```c:main.c
/* main.c */
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "ft_dprintf.h"

int main(void)
{
  int fd;
  
  fd = open("ret.txt", O_WRONLY);
  if (fd == -1)
  {
    ft_dprintf(2, "File open error.\n");
    return (1);
  }
  ft_dprintf(fd, "<%10.5d>, <%010d>\n", 42, 42);
  ft_dprintf(fd, "<%+d>, <% d>\n", 42, 42);
  ft_dprintf(fd, "<%-10x>, <%#10x>\n", 42, 42);
  close(fd);
  return (0);
}
```

```bash
$ make
$ gcc -Wall -Wextra -Werror main.c -Ilibft/includes -Iincludes -Llib -lftdprintf
$ ./a.out
```

The following is output to ret.txt.

```planetext:ret.txt
<     00042>, <0000000042>
<+42>, < 42>
<2a        >, <      0x2a>
```
