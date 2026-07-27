// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 3
// =============================================================================
//
// TASK: Array Statistics Calculator
//
// Write a C++ program that reads a collection of numbers from the user
// and computes key statistical values using separate functions.
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT / OUTPUT EXAMPLE
// -----------------------------------------------------------------------------
//
//   How many numbers? 5
//   Enter number 1: 4
//   Enter number 2: 7
//   Enter number 3: 2
//   Enter number 4: 9
//   Enter number 5: 1
//
//   Results:
//   Sum:     23
//   Average: 4.6
//   Maximum: 9
//   Minimum: 1
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - You MUST implement each calculation in its own function (see scaffold).
// - You may NOT use any standard library functions like accumulate(), max(),
//   or min(). Implement the logic yourself using loops.
// - N must be a positive integer. If the user enters 0 or a negative number,
//   print an error message and stop.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
using namespace std;

// Function to calculate the total
int findTotal(int values[], int size) {
  int total = 0;

  for (int i = 0; i < size; i++) {
      total += values[i];
  }

  return total;
}

// Function to calculate the average
double findAverage(int values[], int size) {
  return (double)findTotal(values, size) / size;
}

// Function to find the largest value
int findLargest(int values[], int size) {
  int largest = values[0];

  for (int i = 1; i < size; i++) {
      if (values[i] > largest) {
          largest = values[i];
      }
  }

  return largest;
}

// Function to find the smallest value
int findSmallest(int values[], int size) {
  int smallest = values[0];

  for (int i = 1; i < size; i++) {
      if (values[i] < smallest) {
          smallest = values[i];
      }
  }

  return smallest;
}

int main() {
  int count;

  cout << "How many numbers? ";
  cin >> count;

  if (count <= 0) {
      cout << "Error: Number of values must be greater than 0." << endl;
      return 0;
  }

  int numbers[count];

  for (int i = 0; i < count; i++) {
      cout << "Enter number " << i + 1 << ": ";
      cin >> numbers[i];
  }

  cout << "\nResults:" << endl;
  cout << "Sum:     " << findTotal(numbers, count) << endl;
  cout << "Average: " << findAverage(numbers, count) << endl;
  cout << "Maximum: " << findLargest(numbers, count) << endl;
  cout << "Minimum: " << findSmallest(numbers, count) << endl;

  return 0;
}