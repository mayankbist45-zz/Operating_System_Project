# Operating System Project

This is a sample problem solving using Round Robin algorithm in C language

## Problem Statement

Sudesh Sharma is a linux expert who wants to have an online system where he can
handle student queries. Since there can be multiple requests at any time he wishes
to dedicate a fixed amount of time to every request so that everyone gets a fair
share of his time. He will log into the System from 10am to 12am only. He wants to
have separate requests queues for students and faculty. Implement a strategy for the
same. The summary at the end of the session should include the total time he spent on
handling queries and average query time.

### Prerequisites

You just need a C compiler to use the program

```
gcc main.c -o output
./output
```

## Running the tests

Test Case Format
```
Total Number of test cases
Total number of faculties(F)
F lines containing
Pid, Time of Arrival, Burst Time
..
..
Total number of students(S)
S lines containing
Pid, Time of Arrival, Burst Time
..
..
```

```
1
2
54 10:10 6
32 10:08 8
2
12 10:08 8
65 10:45 68
```

## Contributing

Feel free to give suggestions and improvements.

## Authors

* **Mayank Bist** - *Initial work* - [mayankbist45](https://github.com/mayankbist45)

See also the list of [contributors](https://github.com/your/project/contributors) who participated in this project.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE.md) file for details.
