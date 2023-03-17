#include <stdio.h>

int main() {
  int rows_a, cols_a, rows_b, cols_b, i, j, k;

  // Get dimensions of matrices from user
  printf("Enter 2-dimensional array size: ");
  scanf("%d %d", &rows_a, &cols_a);
  scanf("%d %d", &rows_b, &cols_b);

  // Make sure the matrices can be multiplied
  if (cols_a != rows_b) {
    printf("Matrices cannot be multiplied\n");
    return 0;
  }

  // Get matrix elements from user
  int a[rows_a][cols_a], b[rows_b][cols_b], c[rows_a][cols_b];
  printf("Enter numbers for each element in two arrays:\n");
  for (i = 0; i < rows_a; i++) {
    for (j = 0; j < cols_a; j++) {
      scanf("%d", &a[i][j]);
    }
  }
  for (i = 0; i < rows_b; i++) {
    for (j = 0; j < cols_b; j++) {
      scanf("%d", &b[i][j]);
    }
  }

  // Multiply matrices
  for (i = 0; i < rows_a; i++) {
    for (j = 0; j < cols_b; j++) {
      c[i][j] = 0;
      for (k = 0; k < cols_a; k++) {
        c[i][j] += a[i][k] * b[k][j];
      }
    }
  }

  // Print result in specified format
  printf("Result after multiplication of two arrays:\n");
  for (i = 0; i < rows_a; i++) {
    for (j = 0; j < cols_b; j++) {
      printf("%d ", c[i][j]);
    }
    printf("\n");
  }

  return 0;
}

// solution-2
#include <stdio.h>

int main() {
  int x, y, *a, *b, temp;

  printf("Enter the value of x and y\n");
  scanf("%d%d", &x, &y);

  printf("Before Swapping\nx = %d\ny = %d\n", x, y);

  a = &x;
  b = &y;

  temp = *b;
  *b = *a;
  *a = temp;

  printf("After Swapping\nx = %d\ny = %d\n", x, y);

  return 0;
}

// solution-3
#include <stdio.h>

int main() {
  char str[100];

  printf("Enter a string: ");
  fgets(str, 100, stdin);

  printf("You entered: %s", str);

  return 0;
}

// solution-4
#include <stdio.h>

int factorial(int n) {
  if (n == 0) {
    return 1;
  } else {
    return n * factorial(n - 1);
  }
}

int main() {
  int n;

  printf("Enter a positive integer: ");
  scanf("%d", &n);

  if (n < 0) {
    printf("Error: Factorial is not defined for negative numbers.\n");
  } else {
    printf("The factorial of %d is %d.\n", n, factorial(n));
  }

  return 0;
}

// solution-5
#include <stdio.h>
#include <string.h>

void strrev(char *str) {
  int i, j;
  char temp;

  for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
    temp = str[i];
    str[i] = str[j];
    str[j] = temp;
  }
}

int main() {
  char str[100], rev[100];

  printf("Enter a string: ");
  scanf("%s", str);

  // make a copy of the string
  strcpy(rev, str);

  // reverse the copy
  strrev(rev);

  // compare the original and reversed strings
  if (strcmp(str, rev) == 0) {
    printf("The string is a palindrome.\n");
  } else {
    printf("The string is not a palindrome.\n");
  }

  return 0;
}

// solution-6
#include <stdio.h>

int main() {
  int size1, size2, mergedSize, i, j, k;

  // Input the size and elements of the first array
  printf("Enter the size of 1st array: ");
  scanf("%d", &size1);
  int arr1[size1];
  printf("Enter each element: ");
  for (i = 0; i < size1; i++) {
    scanf("%d", &arr1[i]);
  }

  // Input the size and elements of the second array
  printf("Enter the size of 2nd array: ");
  scanf("%d", &size2);
  int arr2[size2];
  printf("Enter each element: ");
  for (i = 0; i < size2; i++) {
    scanf("%d", &arr2[i]);
  }

  // Merge the arrays and exclude repeating elements
  mergedSize = size1 + size2;
  int merged[mergedSize];
  k = 0;
  for (i = 0; i < size1; i++) {
    merged[k] = arr1[i];
    k++;
  }
  for (i = 0; i < size2; i++) {
    int found = 0;
    for (j = 0; j < size1; j++) {
      if (arr2[i] == arr1[j]) {
        found = 1;
        break;
      }
    }
    if (!found) {
      merged[k] = arr2[i];
      k++;
    }
  }

  // Print the merged array
  printf("Result of merging: ");
  for (i = 0; i < k; i++) {
    printf("%d ", merged[i]);
  }
  printf("\n");

  return 0;
}

// solution-7
#include <stdio.h>

// Function to calculate the factorial of a number
int factorial(int n) {
  if (n == 0) {
    return 1;
  } else {
    return n * factorial(n - 1);
  }
}

// Function to calculate the binomial coefficient of n and k
int binomialCoefficient(int n, int k) {
  return factorial(n) / (factorial(k) * factorial(n - k));
}

int main() {
  int n, i, j;

  // Input the number of rows for the table
  printf("Enter the number of rows for the table: ");
  scanf("%d", &n);

  // Print the binomial coefficient table
  for (i = 0; i <= n; i++) {
    for (j = 0; j <= i; j++) {
      printf("%d ", binomialCoefficient(i, j));
    }
    printf("\n");
  }

  return 0;
}

// solution-8
#include <stdio.h>

int main() {
  int arr[100], n, i, j, k;

  // Input the size of the array and its elements
  printf("Enter the size of the array: ");
  scanf("%d", &n);
  printf("Enter %d elements: ", n);
  for (i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  // Remove duplicates
  for (i = 0; i < n; i++) {
    for (j = i + 1; j < n; j++) {
      if (arr[i] == arr[j]) {
        // Shift elements to left to overwrite duplicate
        for (k = j; k < n; k++) {
          arr[k] = arr[k + 1];
        }
        n--; // Decrease size of array
        j--; // Check same index again
      }
    }
  }

  // Print the updated array
  printf("Array after removing duplicates: ");
  for (i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  return 0;
}

// solution - 10
#include <math.h>
#include <stdio.h>

int main() {
  int n;
  double mean = 0, sum = 0, variance = 0, sd = 0;

  // Input the size of the set of numbers
  printf("Enter the size of the set: ");
  scanf("%d", &n);

  // Input the numbers and calculate their mean
  double arr[n];
  printf("Enter %d numbers:\n", n);
  for (int i = 0; i < n; i++) {
    scanf("%lf", &arr[i]);
    mean += arr[i];
  }
  mean /= n;

  // Calculate the variance and standard deviation
  for (int i = 0; i < n; i++) {
    sum += pow((arr[i] - mean), 2);
  }
  variance = sum / n;
  sd = sqrt(variance);

  printf("Mean: %.2lf\n", mean);
  printf("Variance: %.2lf\n", variance);
  printf("Standard Deviation: %.2lf\n", sd);

  return 0;
}
