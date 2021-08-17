#include <iostream>
#include <vector>

using namespace std;

void printList(vector<int> list) {
    for(int i = 0; i < list.size(); i++) 
        cout << list[i] << " ";
    cout << endl;
}

void merge(vector<int> &list, int left, int middle, int right) {

    int leftElements = middle - left + 1;
    int rightElements = right - middle;

    vector<int> tempLeft(leftElements);
    vector<int> tempRight(rightElements);

    for(int i = 0; i < leftElements; i++)
        tempLeft[i] = list[left + i];
    for(int j = 0; j < rightElements; j++)
        tempRight[j] = list[middle + 1 + j];

    int i = 0, j = 0, k = left;

    while(i < leftElements && j < rightElements) {
        if(tempLeft[i] <= tempRight[j]) {
            list[k] = tempLeft[i];
            i++;
        } else {
            list[k] = tempRight[j];
            j++;
        }
        k++;
    }

    while(i < leftElements) {
        list[k] = tempLeft[i];
        i++; k++;
    }

    while(j < rightElements) {
        list[k] = tempRight[j];
        j++; k++;
    }
}

void mergeSort(vector<int> &list, int left, int right) {

    if (left >= right)
        return;
    
    int middle = (left + right) / 2;

    mergeSort(list, left, middle);
    mergeSort(list, middle+1, right);
    merge(list, left, middle, right);
}

int main() {

    vector<int> list = {1,5,9,2,7,8,3,4};

    printList(list);
    mergeSort(list, 0, list.size() - 1);
    printList(list);

    return 1;
}