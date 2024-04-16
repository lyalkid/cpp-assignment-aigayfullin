``` bash
g++ -shared myLabrary.cpp -o libmath.so
```

``` bash
 g++ main.cpp -L . -lmath -o main
```

``` bash
LD_LIBRARY_PATH=. ./main 
```
