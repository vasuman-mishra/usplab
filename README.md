
# USP LAB Programs

This repository contains the unix shell programming lab programs with the commands to execute

Check all the text files create and used in the various programs aswell





## Execution(to be put in terminal)

1a.c

```bash
  cc 1a.c
  ./a.out test.txt
```
1b.c

```bash
  cc 1b.c
  ./a.out test.txt
```

2a.c

```bash
  cc 2a.c
  ./a.out test.txt
```

2b.c

```bash
  cc 2b.c
  ./a.out test.txt
```
3a.c

```bash
  cc 3a.c
  ./a.out
```
3b.c

```bash
  cc 3b.c
  ./a.out
```
4a.c

It deletes the text file, hence make test.txt again after execution
```bash
  cc 4a.c
  ./a.out test.txt
```
4b.c

Change the name of interpreter file from 4binterpreter.sh(in 4bmain.c) to as required

Change the name of echoall.c file from 4bechoall.c to as required in interpreter.sh file
```bash
  gcc -o 4bechoall 4bechoall.c
  chmod +x 4binterpreter.sh
  cc 4bmain.c
  ./a.out
```
 5a.c
 
 After calling stat function we can see change parameter displayed is same
 ```bash
  cc 5a.c
  ./a.out test.txt test2.txt
  stat test.txt
  stat test2.txt
```

 5b.c
 
 After calling stat function we can see change parameter displayed is same
 ```bash
  cc 5b.c
  ./a.out
```
 6a.c
 
 Create an empty file in the directory

 Program will delete it(cross check with ls)
 ```bash
  cc 6a.c
  ./a.out
```

6b.c

 ```bash
  cc 6b.c
  ./a.out test3.txt
```
Open a new terminal and then run the program again

```bash
  cc 6b.c
  ./a.out test3.txt
```

7a.c 

```bash
  cc 7a.c
  ./a.out
```

7b.c 

```bash
  cc 7b.c
  ./a.out source.txt destination.txt
```
8a.c is same as 6a.c 

8b.c

Create an example.txt file

```bash
  vi example.txt
  cc 8b.c
  ./a.out
```
9a.c 

Change file names as you want

```bash
  cc 9aumask.c
  ./a.out
  cc 9achmod.c
  ./a.out
```
9b.c 

Create testfile.txt 
```bash
  cc 9b.c
  ./a.out
```

10.a

```bash
  cc 10.c
  ./a.out
```

10.b

```bash
  cc 10.b
  ./a.out
```





