![Logo](https://www.42network.org/wp-content/themes/e42-network/img/42-network-logo.svg)
# 📖 ABOUT GNL 📖

The Get Next Line (GNL) program is a simple and efficient utility in C for reading text from files, streams, or other input sources line by line. It is designed to provide a convenient way to process and manipulate data from various input sources while handling dynamic memory allocation efficiently.


## 📝 Instructions 📝
**Compile & use**

Compile the program by placing a main with the name of the file you need to read and its path in case it is not in the program folder itself.
It could be done by args easily from the console by setting fd to '0'.

Simple example:

```c
int main() 
{
    int fd;
    char *line;

    fd = open("example.txt", O_RDONLY);
    while ((line = get_next_line(fd)) != NULL) {
        printf("%s\n", line);
        free(line);
    }
    close(fd);

    return 0;
}
```
## 🔎 What's inside? 🔎

| Functions             | Other                                                              |
| ----------------- | ------------------------------------------------------------------ |
| get_next_line.c | get_next_line.h|
| get_next_line_utlis.c | get_next_line_bonus.h|
| get_next_line_bonus.c | tests|
| get_next_line_utils_bonus.c|


## ⚒️ Testing ⚒️

[![Francinette Tester 🔗](Francinette)](https://github.com/xicodomingues/francinette)

**To standart test, go to the library path and run:**

All standard tests should work perfectly. 
```bash
$ paco
```
**To strict test, go to the library path and run:**

The "strict" tests do work correctly, except for two specific tests that can give a timeout, you can increase the time and go for a coffee, like this:
```bash
$ paco -s -tm 1000000
```
You can also try some other tests that are located in ./tests folder.
## 🗒️ NOTES 🗒️

The bonus part of the project is included, the only difference with the normal program is that it allows reading different fds at the same time, stored with a single static variable.

## 🚀 About Me
I'm 42Network student at 42Madrid(Spain)

You I track my progress through the common core at: 

[![Intra 42 🔗]()](https://projects.intra.42.fr/projects/graph?login=jdelorme)

More about:

[![linkedin](https://img.shields.io/badge/linkedin-0A66C2?style=for-the-badge&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/juan-bautista-delorme-pinedo-000697264/)
