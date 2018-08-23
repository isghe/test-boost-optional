# test-boost-optional
* [Compile](#compile)
* [Run](#run)
## Compile

```
$ g++ -std=c++11 -Wall -Wpedantic -Wextra -l boost_system main.cpp -o main.out
```

## Run
```
$ ./main.out
void Test1()
First
Second
Third
void Test2()
First
void Test3()
4
8
First
Second
First
Third
void Test4()
4
8
one
two
one
three
void Test5()
```
##
```
$ ./main.out | sha256
815374027b70f67ac340d46882815e2e841389c8e1e8f7185e200af60eacca96
```
