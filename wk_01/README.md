# Challenge 1 - Week 1 Challenge: Build Your Own wc Tool! 🖥
Hey @everyone! Lets start our year-long coding challenge!

## The Challenge: Recreate the Unix wc Tool
This week, we're building our own version of the classic Unix command-line tool wc.

_-c_ option: Count bytes in a file
```
> new-wc -c test.txt
   342190 test.txt
```

_-l_ option: Count lines in a file
```
> new-wc -l test.txt
   7145 test.txt
```

_-w_ option: Count words in a file
```
> new-wc -w test.txt
   58164 test.txt
```

_-m_ option: Count characters in a file
```
> new-wc -m test.txt
   339292 test.txt
```

Default behavior: Combine -c, -l, and -w
```
> new-wc test.txt
   7145   58164  342190 test.txt
```
