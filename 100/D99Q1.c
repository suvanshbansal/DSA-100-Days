/*
Problem: Given a target distance and cars’ positions & speeds, compute the number of car fleets reaching the destination.
Sort cars by position in descending order and calculate time to reach target.
*/
#include <stdio.h>
#include <stdlib.h>

// Structure for car
typedef struct {
    int position;
    int speed;
} Car;

// Compare function: sort by position descending
int compare(const void *a, const void *b)
{
    return ((Car *)b)->position - ((Car *)a)->position;
}

// Function to count car fleets
int carFleet(int target, int position[], int speed[], int n)
{
    // Step 1: Create car array
    Car *cars = (Car *)malloc(n * sizeof(Car));
    for (int i = 0; i < n; i++) {
        cars[i].position = position[i];
        cars[i].speed = speed[i];
    }

    // Step 2: Sort by position descending
    qsort(cars, n, sizeof(Car), compare);

    int fleets = 0;
    double lastTime = 0.0;

    // Step 3: Process cars
    for (int i = 0; i < n; i++)
    {
        double time = (double)(target - cars[i].position) / cars[i].speed;

        // If this car takes more time, it forms a new fleet
        if (time > lastTime)
        {
            fleets++;
            lastTime = time;
        }
    }

    free(cars);
    return fleets;
}

// Driver code
int main()
{
    int target = 12;
    int position[] = {10, 8, 0, 5, 3};
    int speed[]    = { 2, 4, 1, 1, 3};
    int n = sizeof(position) / sizeof(position[0]);

    printf("Number of car fleets: %d\n", carFleet(target, position, speed, n));
    return 0;
}