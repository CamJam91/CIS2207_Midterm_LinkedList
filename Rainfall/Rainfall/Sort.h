#include<vector>
#include "Utilities.h"
using namespace std;

template<typename T>
class Sort {
private:
	static void selectionSortHelper(vector<T>& list, int lowerBound, int upperBound) {
		for (int count = list.size() - 1; count > 0; count--) {
			int highest = count;
			for (int nestCount = count - 1; nestCount > -1; nestCount--) {
				if (list[nestCount] > list[highest]) {
					highest = nestCount;
				}
			}
			swap(list[highest], list[count]);
		}
	}
	static void mergeSortHelper(vector<T>& list, int first, int last, const int SIZE) {
		if (first < last) {
			//recursively splits the array
			int mid = first + (last - first) / 2; //find the middle of the array
			mergeSortHelper(list, first, mid, SIZE); //smaller caller on the first half
			mergeSortHelper(list, mid + 1, last, SIZE); //smaller caller on the second half

			//merges them after recursive calls finish
			merge(list, first, mid, last, SIZE);
		}
	}

	static void merge(vector<T>& list, int first, int mid, int last, const int SIZE) {
		int* tempList = new int[SIZE]; //create temporary array to hold sorted values

		//split the array into two subarrays
		int first1 = first; //very first
		int last1 = mid; //middle so lest of first half
		int first2 = mid + 1; //first of second half
		int last2 = last; //very last

		int index = first1; //this is used to copy the real array to the temop so it needs to start at the beginning of the real array
		while ((first1 <= last1) && (first2 <= last2)) { //first half of the array still needs to be sorted 
			if (list[first1] <= list[first2]) { //
				tempList[index] = list[first1];
				first1++;
			}
			else {
				tempList[index] = list[first2];
				first2++;
			}
			index++;
		}

		while (first1 <= last1) {
			tempList[index] = list[first1];
			first1++;
			index++;
		}

		while (first2 <= last2) {
			tempList[index] = list[first2];
			first2++;
			index++;
		}

		for (index = first; index <= last; index++) {
			list[index] = tempList[index];
		}
	}

	static void quickSortHelper(vector<T>& list, int lowerBound, int upperBound) {
		if (lowerBound < upperBound) {
			int partitionIndex = partition(list, lowerBound, upperBound);

			if (partitionIndex > lowerBound) {
				quickSortHelper(list, lowerBound, partitionIndex - 1);
			}
			if (partitionIndex < upperBound) {
				quickSortHelper(list, partitionIndex + 1, upperBound);
			}
		}
	}

	static void radixHelper(vector<T>& list) {
		T upperBound = Utility::getUpperBound(list);

		for (int place = 1; upperBound / place > 0; place *= 10) {
			countSort(list, place);
		}
	}

	static void countSort(vector<T>& list, T place) {
		const T upper = 10;
		T* output = new T[list.size()];
		T temp[upper] = { 0 };

		for (int count = 0; count < upper; ++count)
			temp[count] = 0;

		for (int count = list.size()-1; count >= 0; count--)
			temp[(list[count] / place) % 10]++;

		for (int count = 1; count < upper; count++)
			temp[count] += temp[count - 1];

		for (int count = list.size()-1; count >= 0; count--) {
			output[temp[(list[count] / place) % 10] - 1] = list[count];
			temp[(list[count] / place) % 10]--;
		}

		for (int count = 0; count < list.size(); count++)
			list[count] = output[count];
	}

	static int partition(vector<T>& list, int lowerBound, int upperBound) {
		int pivot = list[upperBound];
		int index = (lowerBound - 1);

		for (int count = lowerBound; count <= upperBound-1; count++) {
			if (list[count] <= pivot) {
				index++;
				swap(list[index], list[count]);
			}
		}

		swap(list[index + 1], list[upperBound]);
		return (index + 1);
	}



	static void swap(T& a, T& b) {
		T temp = a;
		a = b;
		b = temp;
	}

public:
	//sortHelper does the heavy lifting, this calls without user having to enter extra parameters and returns if the vector was sorted
	static bool selectionSort(vector<T>& list) {
		if (list.size() < 2) { return false; } //list is too small to sort
		selectionSortHelper(list, 0, list.size());
		return true;
	}

	static bool bubbleSort(vector<T>& list) {
		if (list.size() < 2) { return false; }
		bool sorted = false;
		while (!sorted) {
			sorted = true;
			for (int count = 0; count < list.size() - 1; count++) {
				if (list[count] > list[count + 1]) {
					swap(list[count], list[count + 1]);
					sorted = false;
				}
			}
		}
		return true;
	}

	static bool insertionSort(vector<T>& list) {
		if (list.size() < 2) { return false; }
		for (int unsorted = 1; unsorted < list.size(); unsorted++) {
			T insert = list[unsorted];
			int loc = unsorted;
			while ((loc > 0) && (list[loc - 1] > insert)) {
				list[loc] = list[loc - 1];
				loc--;
			}
			list[loc] = insert;
		}
		return true;
	}

	static bool mergeSort(vector<T>& list) {
		if (list.size() < 2) { return false; }
		mergeSortHelper(list, 0, list.size()-1, list.size());
		return true;
	}

	static bool quickSort(vector<T>& list) {
		if (list.size() < 2) { return false; }
		quickSortHelper(list, 0, list.size()-1);
		return true;
	}

	static bool radixSort(vector<T>& list) {
		if (list.size() < 2) { return false; }
		radixHelper(list);
		return true;
	}


};