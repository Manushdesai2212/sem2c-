/* THIS PROGRAM IS PREPARED BY 24CE025 Manush desai
   Date of Modification- 1 May 2025
   6.3 MERGING AND SORTING AN ARRAY*/

   #include <iostream>
   using namespace std;
   
   // Function to merge two sorted arrays
   int* mergeSortedArrays(int* arr1, int size1, int* arr2, int size2, int& mergedSize) {
       mergedSize = size1 + size2;
       int* mergedArr = new int[mergedSize];
   
       int i = 0, j = 0, k = 0;
   
       // Merge while both arrays have elements
       while (i < size1 && j < size2) {
           if (arr1[i] <= arr2[j])
               mergedArr[k++] = arr1[i++];
           else
               mergedArr[k++] = arr2[j++];
       }
   
       // Copy any remaining elements
       while (i < size1)
           mergedArr[k++] = arr1[i++];
       while (j < size2)
           mergedArr[k++] = arr2[j++];
   
       return mergedArr;
   }
   
   int main() {
       int size1, size2;
   
       // User input for array 1
       cout << "Enter size of first sorted array: ";
       cin >> size1;
       int* arr1 = new int[size1];
       cout << "Enter " << size1 << " elements (sorted): ";
       for (int i = 0; i < size1; ++i) {
           cin >> arr1[i];
       }
   
       // User input for array 2
       cout << "Enter size of second sorted array: ";
       cin >> size2;
       int* arr2 = new int[size2];
       cout << "Enter " << size2 << " elements (sorted): ";
       for (int i = 0; i < size2; ++i) {
           cin >> arr2[i];
       }
   
       // Merge arrays
       int mergedSize;
       int* mergedArray = mergeSortedArrays(arr1, size1, arr2, size2, mergedSize);
   
       // Display merged array
       cout << "Merged Sorted Array: ";
       for (int i = 0; i < mergedSize; ++i) {
           cout << mergedArray[i] << " ";
       }
       cout << endl;
   
       // Free dynamically allocated memory
       delete[] arr1;
       delete[] arr2;
       delete[] mergedArray;
   
       cout << endl << "Manush desai 24CE025" << endl;
   }