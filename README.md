# ft_printf
It is library that contains ft_printf, a function that will mimic the original printf.

Place [libft](https://github.com/tksx1227/libft) in the root directory and use it.

## Description
ft_printf is interpret the following format rules.

`%[flags][minimum field width].[precision][conversion specifier]`

* Flags: `'-', '0', '#', ' ', '+'`

* Specifier: `'c', 's', 'p', 'd', 'i', 'u', 'x', 'X', '%'`

## Usage
Compile and use as below.

```bash
$ make
$ gcc -Wall -Wextra -Werror <file_name> -I<include_path> -L<library_path> -lftprintf
$ ./a.out
```

ft_printf can be used in the same way as printf as shown below.

```c
/* Use ft_printf */
ft_printf("<%c>\n", 'A');
ft_printf("<%s>\n", "Hello World!!!");
ft_printf("<%d>\n", 42);
ft_printf("<%x>\n", 123456789);
ft_printf("<%%>\n");
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
include ft_printf.h and compile your code with libftprintf.a.

```c
/* main.c */
#include "ft_printf.h"

int main(void)
{
  ft_printf("<%10.5d>, <%010d>\n", 42, 42);
  ft_printf("<%+d>, <% d>\n", 42, 42);
  ft_printf("<%-10x>, <%#10x>\n", 42, 42);
  return (0);
}
```

```bash
$ make
$ gcc -Wall -Wextra -Werror main.c -I./includes -L./ -lftprintf
$ ./a.out
```

The output looks like this.

```planetext
<     00042>, <0000000042>
<+42>, < 42>
<2a        >, <      0x2a>
```
