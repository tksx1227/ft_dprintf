# ft_printf
It is library that contains ft_printf, a function that will mimic the original printf.

Place libft in the root directory and use it.

[![tksx1227/libft - GitHub](https://gh-card.dev/repos/tksx1227/libft.svg?fullname=)](https://github.com/tksx1227/libft)

## Description
ft_printf interprets the following format rules.

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
    - `%p` : The `void *` pointer argument has to be printed in hexadecimal format.
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
$ gcc -Wall -Wextra -Werror <file_name> -I<include_path> -L<library_path> -lftprintf
$ ./a.out
```

ft_printf can be used in the same way as printf as shown below.

```c
/* Use ft_printf */
ft_printf("/* Output */\n");
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
Include ft_printf.h and compile your code with libftprintf.a.

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
