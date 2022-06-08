#include <iostream>


void merge_sort (int*, int, int);
void merge (int*, int, int, int);


int main() {

	int arr[6] = {1, 8, 7, 4, 5, 6};
	merge_sort(arr, 0, 5);

	for(auto a: arr) {
		std::cout << a << " ";
	}



    return 0;
}

void merge_sort (int* arr, int start, int end) {
    if (start < end) {
        int mid = start + (end - start) / 2;
        merge_sort (arr, start, mid);
        merge_sort (arr, mid + 1, end);
        merge (arr, start, mid, end);
    }
}

void merge (int* arr, int start, int mid, int end) {
	int temp[end - start + 1];
	int left_index = start;
	int right_index = mid + 1;
	int temp_index = 0;
	while(left_index <= mid && right_index <= end) {
		if(arr[left_index] <= arr[right_index]) {
			temp[temp_index] = arr[left_index];
			left_index++;
			temp_index++;
		} else {
			temp[temp_index] = arr[right_index];
			right_index++;
			temp_index++;
		}
	}
	while(left_index <= mid) {
		temp[temp_index] = arr[left_index];
		left_index++;
		temp_index++;
	}

	while(right_index <= end) {
		temp[temp_index] = arr[right_index];
		right_index++;
		temp_index++;
	}

	for(int i = start; i <= end; i++) {
		arr[i] = temp[i - start];
	}
}
