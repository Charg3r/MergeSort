#include <iostream>
#include <vector>

using namespace std;

// Method that rearranges and orders the array.

void merge(vector<int> &array, int left, int middle, int right) {

    int leftElements = middle - left + 1;
    int rightElements = right - middle;

    vector<int> tempLeft(leftElements);
    vector<int> tempRight(rightElements);

    for(int i = 0; i < leftElements; i++)
        tempLeft[i] = array[left + i];
    for(int j = 0; j < rightElements; j++)
        tempRight[j] = array[middle + 1 + j];

    int i = 0, j = 0, k = left;

    while(i < leftElements && j < rightElements) {
        if(tempLeft[i] <= tempRight[j]) {
            array[k] = tempLeft[i];
            i++;
        } else {
            array[k] = tempRight[j];
            j++;
        }
        k++;
    }

    // Check if there are no numbers left

    while(i < leftElements) {
        array[k] = tempLeft[i];
        i++; k++;
    }

    while(j < rightElements) {
        array[k] = tempRight[j];
        j++; k++;
    }
}

// Recursive method that divides the array into single pieces.

void mergeSort(vector<int> &array, int left, int right) {

    if (left >= right)
        return;
    
    int middle = (left + right)  / 2;

    mergeSort(array, left, middle);
    mergeSort(array, middle+1, right);
    merge(array, left, middle, right);
}

// Method that prints the array.

void printList(vector<int> array) {
    
    for(int i = 0; i < array.size(); i++) 
        cout << array[i] << " ";
    cout << endl;
}


int main() {

    vector<int> array = {1,5,9,2,7,8,3,4,10};

    printList(array);
    mergeSort(array, 0, array.size() - 1);
    printList(array);

    return 1;
}