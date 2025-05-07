#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_ARRAY_SIZE 1000000
long long int compare_counter = 0;
int compare(const void* a, const void* b) {
	compare_counter++;
	int val1 = *(const int*)a;
	int val2 = *(const int*)b;
	return (val1 > val2) - (val1 < val2);
}
int is_sorted(int* arr, size_t size) {
	for (size_t i = 1; i < size; i++) 
		if (arr[i-1] > arr[i]) return 1;
	return 0;
}
void generate_sorted(int* arr, size_t size) {
	for (size_t i = 0; i < size; i++) arr[i] = i;
}
void generate_reversed(int* arr, size_t size) { 
	for (size_t i = 0; i < size; i++) arr[i] = size - i;
}
void generate_random(int* arr, size_t size) {
	for (size_t i = 0; i < size; i++) arr[i] = rand() % size;
}
void generate_same(int* arr, size_t size) {
	for (size_t i = 0; i < size; i++) arr[i] = 0;
}
void test(const char* message, void (*generate)(int*, size_t), size_t size) {
	int arr[size];
        generate(arr, size);
	compare_counter = 0;
	clock_t start = clock();
	qsort(arr, size, sizeof(int), compare);
	clock_t end = clock();
	printf("%s, time elapsed (seconds): %f, compare counter: %lld, ",
		       	message,
			(double)(end - start) / CLOCKS_PER_SEC,
			compare_counter);	
	is_sorted(arr, size) == 0 ? printf("OK\n\n") : printf("BAD\n\n");
}
int main() {
	srand(time(NULL));
	test("\nSorted array", generate_sorted, MAX_ARRAY_SIZE);
	test("Reversed array", generate_reversed, MAX_ARRAY_SIZE);
	test("Random array", generate_random, MAX_ARRAY_SIZE);
	test("Same array", generate_same, MAX_ARRAY_SIZE);
	return 0;
}
