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
void Test6()
uninitializedInt is uninitialized!
uninitializedInt:  2
```
##
```
$ ./main.out | sha256
5a95a74714850b5ea995cde4cb15b8674a3371c4a9c7766b632c55208f5cf96e
```
