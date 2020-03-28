/*
 * Problem Statement :-
 *      Sudesh Sharma is a linux expert who wants to have an online system where he can
 *      handle student queries. Since there can be multiple requests at any time he wishes
 *      to dedicate a fixed amount of time to every request so that everyone gets a fair
 *      share of his time. He will log into the System from 10am to 12am only. He wants to
 *      have separate requests queues for students and faculty. Implement a strategy for the
 *      same. The summary at the end of the session should include the total time he spent on
 *      handling queries and average query time.
 *
 * Author :-
 *      Mayank Bist (11814526)
 *
 * Solution Implemented :-
 *      Since we are planning to have different queues for students and faculties and each
 *      of them needs a fixed time quantum and in order to maximize the efficiency i will be
 *      calculating optimal time quantum to get the maximum efficiency in the shortest period
 *      of time.
 */

#include <stdio.h>

#define maxn 100010

int time_quanta = 2;

struct data {
    char name[50], arrival_time[50];
    int pid, at, burst_time, priority;
} data[110];

int valid(char s[]){
    for(int i = 0; i < 4;i++){
        if(i == 2)continue;
        if(isdigit(s[i]))
            return 0;
    }
    return 1;
}

void solve() {
    int no_of_faculty, no_of_students;

    int id = 0;
    printf("Enter the total number of faculties:");
    scanf("%d", &no_of_faculty);

    printf("Enter the details of each faculty\n");
    for (int i = 0; i < no_of_faculty; i++) {
        //Name of faculty
        printf("Enter faculty name:");
        scanf("%[^\n]s", data[id].name);

        //PID
        printf("Enter PID of %s", data[id].name);
        scanf("%d", &data[id].pid);

        //Entering the arrival time
        printf("Time format :- (hh::mm) in 24 hr format\n");
        printf("Enter arrival time:");
        scanf("%[^\n]s", data[id].arrival_time);

        while (!valid(data[id].arrival_time)) {
            printf("Time format :- (hh::mm) in 24 hr format\n");
            printf("Enter correct arrival time");
            scanf("%[^\n]s", data[id].arrival_time);
        }


        printf("")

        data[id].priority = 0;
        id++;
    }

    printf("Enter the total number of students:");
    scanf("%d", &no_of_students);

    printf("Enter the details of each student\n");
    for (int i = 0; i < no_of_faculty; i++) {
        //Name of faculty
        printf("Enter student name:");
        scanf("%[^\n]s", data[id].name);

        //PID
        printf("Enter PID of %s", data[id].name);
        scanf("%d", &data[id].pid);

        //Entering the arrival time
        printf("Time format :- (hh::mm) in 24 hr format\n");
        printf("Enter arrival time:");
        scanf("%d", &data[id].arrival_time);


        data[id].priority = 1;
        id++;
    }
}

//Write the input format in here to show the user how the input is handled
void input_format() {
    printf("Please follow the instructions below ");
}

int main() {
    int test_case;
    printf("Enter total number of test cases:");
    scanf("%d", &test_case);

    input_format();
    while (test_case--)
        solve();

    return 0;
}