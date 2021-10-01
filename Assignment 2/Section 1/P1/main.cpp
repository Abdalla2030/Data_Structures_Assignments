#include <iostream>
#include <cstdlib>
#include <fstream>
#include<vector>
#include<chrono>
#include<ostream>
using namespace std;
//merge function
void merge(int arr[], int start,int mid, int end){
    int n1 = mid - start + 1;
    int n2 = end - mid;
   int  L[n1];
    int  R[n2];
    int i = 0,j = 0;
    for(; i < n1; ++i){
        L[i] = arr[start+i];
    }
    for(; j < n2; ++j){
        R[j] = arr[mid+1+j];
    }
    int k = start;
    i = j = 0;
    while(i < n1 && j < n2){
        if(L[i] < R[j]){
            arr[k++] = L[i++];
        }
        else{
            arr[k++] = R[j++];
        }
    }
    while(i < n1){
        arr[k++] = L[i++];
    }
    while(j < n2){
        arr[k++] = R[j++];
    }

}
//merge sort
void mergeSort(int arr[], int start,int end){
    if(start < end){
        int mid = start + (end - start) /2;
        mergeSort(arr,start,mid);
        mergeSort(arr,mid+1,end);
        merge(arr,start,mid,end);
    }

}

//select pivot end element
int partionedEnd(int arr[], int start,int end){
    int pivot = arr[end];
    int i = start;
    for(int j = start;  j < end; ++j){
        if(arr[j] <= pivot){
            swap(arr[i],arr[j]);
            i++;
        }
    }
    swap(arr[i],arr[end]);
    return i;


}

//quicksort using end pivot
void quicksortEndPivot(int arr[], int start,int end){
    if(start < end){
        int index = partionedEnd(arr,start,end);
        quicksortEndPivot(arr,start,index-1);
        quicksortEndPivot(arr,index+1,end);

    }

}

//select pivot middle elemnt
int partitionMiddle(int arr[], int start, int end, int pivot){
    while(start <= end){
        while(arr[start] < pivot){
            start++;
        }

        while(arr[end] > pivot){
            end--;
        }

        if(start <= end){
            swap(arr[start], arr[end]);
            start++;
            end--;
        }
    }

    return start;
}

//quick sort using middle pivot
void quickSortMiddlePivot(int arr[], int start, int end){
    if(start < end){
        int pivot = arr[(start + end) / 2];

        int pivotInRightPlaceIndex = partitionMiddle(arr, start, end, pivot);

        quickSortMiddlePivot(arr, start, pivotInRightPlaceIndex - 1);
        quickSortMiddlePivot(arr, pivotInRightPlaceIndex, end);

    }
}

//create 3 arrays to store time of each algorithm for each size
double Merge[20],QuickEnd[20], QuickMid[20];
int main() {

    int index = 0;
    srand(time(0));

    for(int i = 5000; i <= 100000; i += 5000){
        int MAX_SIZE = i;
        //creat 3 arrays with the same size to hold the same data
        int nums1[MAX_SIZE],  nums2[MAX_SIZE], nums3[MAX_SIZE];

        for(int j = 0 ; j < MAX_SIZE; ++j){
            nums1[j] = rand();
            nums2[j] = nums1[j];
            nums3[j] = nums1[j];
        }

        double elapsed_time;
       // measure merge sort performance
        double start = clock();  //calculate start time
        mergeSort(nums1,0,MAX_SIZE-1);
        double end = clock();  //calculate end time
        elapsed_time = double(end-start) / CLOCKS_PER_SEC; // calculate total time
        Merge[index] = elapsed_time;//store the result

        // measure quick sort using end pivot  performance
        start = clock();//calculate start time
        quicksortEndPivot(nums2,0,MAX_SIZE-1);
        end = clock();//calculate end time
        elapsed_time = double(end-start) / CLOCKS_PER_SEC;// calculate total time
        QuickEnd[index] = elapsed_time;//store the result

        // measure quick sort using middle pivot  performance
        start = clock();//calculate start time
        quickSortMiddlePivot(nums3,0,MAX_SIZE-1);
        end = clock();//calculate end time
        elapsed_time = double(end-start) / CLOCKS_PER_SEC;// calculate total time
        QuickMid[index] = elapsed_time;
        index++;//store the result
    }

    //write the results to a file
    ofstream myFile;
    myFile.open("results.txt");
    if(myFile.is_open()){
        myFile<<"Size"<<"\t"<<"MergeSort"<<"\t"<<"QuickSortEnd"<<"\t\t"<<"QuickSortMiddle"<<"\n";

        for(int i = 0, SIZE = 5000 ; i < 20 ; ++i, SIZE+=5000){
            myFile<<SIZE<<"\t"<<Merge[i]<<"sec"<<"\t"<<QuickEnd[i]<<"sec"<<"\t\t\t"<<QuickMid[i]<<"sec"<<"\n";
        }
    }

    myFile.close();
    system("pause");
    return 0;
}


