#include <stdio.h>
#include <stdlib.h>

int main() {
  char* ptr = malloc(5);
  free(ptr);
  printf("Enter some number: ");
  int choice = 0;
  scanf("%d", &choice);
  if (choice % 2 == 0) {
    free(ptr);
  }
  return 0;
}