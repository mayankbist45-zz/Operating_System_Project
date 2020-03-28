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
#include <limits.h>
#include <stdlib.h>
#include <windef.h>

//maxn means the maximum no of students and faculties we can have
#define maxn 100010

int time_quanta = 2;

typedef struct {
    char name[50], arrival_time[50];
    int pid, at, burst_time, priority, wt, id;
} data;
data faculty[maxn], student[maxn], q1[maxn], q2[maxn];

void calculate_time_in_seconds(data *d) {
    d->at = 0;
    int hr = 0, mn = 0;
    for (int i = 0; i < 2; i++)
        hr = hr * 10 + d->arrival_time[i] - '0';

    for (int i = 3; i < 5; i++)
        mn = mn * 10 + d->arrival_time[i] - '0';

    d->at = hr * 60 + mn;
}

int valid(char s[]) {
    for (int i = 0; i < 4; i++) {
        if (i == 2)continue;
        if (!isdigit(s[i]))
            return 0;
    }
    int hr = 0, mn = 0;
    for (int i = 0; i < 2; i++)
        hr = hr * 10 + s[i] - '0';

    for (int i = 3; i < 5; i++)
        mn = mn * 10 + s[i] - '0';

    if (hr < 10)
        return 0;
    return 1;
}

int comp(const void *a, const void *b) {
    data *A = (data *) a;
    data *B = (data *) b;
    return A->at < B->at;
}

void solve_queries(int f, int s) {
    // Since we are not given whom to prioritize we will consider
    // prioritizing faculty first that means if we have anything in left
    // faculty in queue we process it first and then we
    // go to the children queue


    qsort((void *) faculty, f, sizeof(faculty[0]), comp);
    qsort((void *) student, s, sizeof(student[0]), comp);

    int min_arrival_time = 10 * 60;//10:00AM
    int cur = min_arrival_time, id1 = 0, id2 = 0, st1 = 0, st2 = 0;

    int x1 = 0, y1, x2 = 0, y2;
    while (id1 < f || id2 < s) {
        if (id1 < f)
            while (faculty[id1].at <= cur && faculty[id1].burst_time != 0)
                q1[st1++] = faculty[id1++];

        if (id2 < s)
            while (student[id2].at <= cur && student[id1].burst_time != 0)
                q2[st2++] = student[id2++];

        y1 = st1 - 1;
        y2 = st2 - 1;

        while (x1 <= y1) {
            q1[x1].burst_time -= min(q1[x1].burst_time, time_quanta);
            cur += time_quanta;
            if (q1[x1].burst_time)
                q1[st1++] = q1[x1];
            else {

            }

            if (id1 < f)
                while (faculty[id1].at <= cur && faculty[id1].burst_time != 0)
                    q1[st1++] = faculty[id1++];

            if (id2 < s)
                while (student[id2].at <= cur && student[id1].burst_time != 0)
                    q2[st2++] = student[id2++];
            y2 = st2 - 1;
            y1 = st1 - 1;
            x1++;
        }

        while (x2 <= y2) {
            q2[x2].burst_time -= min(q2[x2].burst_time, time_quanta);
            cur += time_quanta;
            if (q2[x2].burst_time)
                q2[st2++] = q2[x2];

            if (id1 < f)
                while (faculty[id1].at <= cur && faculty[id1].burst_time != 0)
                    q1[st1++] = faculty[id1++];

            if (id2 < s)
                while (student[id2].at <= cur && student[id1].burst_time != 0)
                    q2[st2++] = student[id2++];
            y2 = st2 - 1;
            y1 = st1 - 1;
            x2++;
        }
    }

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
        scanf("%[^\n]s", faculty[id].name);

        //PID
        printf("Enter PID of %s", faculty[id].name);
        scanf("%d", &faculty[id].pid);

        //Entering the arrival time
        printf("Time format :- (hh::mm) in 24 hr format\n");
        printf("Enter arrival time:");
        scanf("%[^\n]s", faculty[id].arrival_time);

        while (!valid(faculty[id].arrival_time)) {
            printf("Time format :- (hh::mm) in 24 hr format\n");
            printf("Enter correct arrival time");
            scanf("%[^\n]s", faculty[id].arrival_time);
        }

        printf("Time should be in seconds\n");
        printf("Enter burst time:");
        scanf("%d", &faculty[id].burst_time);


        faculty[id].priority = 0;
        calculate_time_in_seconds(&faculty[id]);
        id++;
    }

    printf("Enter the total number of students:");
    scanf("%d", &no_of_students);

    id = 0;
    printf("Enter the details of each student\n");
    for (int i = 0; i < no_of_faculty; i++) {
        //Name of faculty
        printf("Enter student name:");
        scanf("%[^\n]s", student[id].name);

        //PID
        printf("Enter PID of %s", student[id].name);
        scanf("%d", &student[id].pid);

        //Entering the arrival time
        printf("Time format :- (hh::mm) in 24 hr format\n");
        printf("Enter arrival time:");
        scanf("%[^\n]s", student[id].arrival_time);

        while (!valid(student[id].arrival_time)) {
            printf("Time format :- (hh::mm) in 24 hr format\n");
            printf("Enter correct arrival time");
            scanf("%[^\n]s", student[id].arrival_time);
        }

        //Burst time
        printf("Time should be in seconds\n");
        printf("Enter burst time:");
        scanf("%d", &student[id].burst_time);

        student[id].priority = 1;
        id++;
    }
    solve_queries(no_of_faculty, no_of_students);
}

//Write the input format in here to show the user how the input is handled
void input_format() {
    printf("Please follow the instructions below:-\n");
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