#include <iostream>
#include <cstdlib> 
#include <ctime> 
#include <chrono> 


void InsertSort(int arr[], int size) {
    int item, j;

    for (int i = 1; i < size; i++) {
        item = arr[i];
        j = i - 1;

        while (j != 0 && arr[j] > item) {
            arr[j + 1] = arr[j];
            j -= 1;
        }

        arr[j+1] = item;
    }
}

void SelectionSort(int arr[], int size) {
    int min;

    for (int i = 0; i < size - 1; i++) {
        min = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        std::swap(arr[i], arr[min]);
    }
}

void BubbleSort(int arr[], int size) {
    int a, b, temp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}


void MergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        MergeSort(arr, left, mid);

        MergeSort(arr, mid + 1, right);

        int n1 = mid - left + 1;
        int n2 = right - mid;   

        int* L = new int[n1];
        int* R = new int[n2];

        for (int i = 0; i < n1; i++) {
            L[i] = arr[left + i];
        }
        for (int i = 0; i < n2; i++) {
            R[i] = arr[mid + 1 + i];
        }

        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
            } else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }

        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }

        while (j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }

        delete[] L;
        delete[] R;
    }
}


void CreateHeap(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;  
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        CreateHeap(arr, n, largest);
    }
}

void HeapSort(int arr[], int size) {
    for (int i = size / 2 - 1; i >= 0; i--) {
        CreateHeap(arr, size, i);
    }

    for (int i = size - 1; i >= 1; i--) {
        std::swap(arr[0], arr[i]);  
        CreateHeap(arr, i, 0); 
    }
}

int Partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;  
            std::swap(arr[i], arr[j]); 
        }
    }

    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

void QuickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = Partition(arr, low, high);

        QuickSort(arr, low, pi - 1);
        QuickSort(arr, pi + 1, high);
    }
}

int main() {
    int size = 0, option;

    std::cout << "Menu\n 1. Insert Sort\n 2. Selection Sort\n 3. Bubble Sort\n 4. Merge Sort\n 5. Heap Sort\n 6. Quick Sort" << std::endl;
    
    std::cout << "Selecciones una opcion: ";
    std::cin >> option;

    std::cout << "Ingrese el tamano del arreglo: ";
    std:: cin >> size;

    srand(time(0));

    int* arr = new int[size];

    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 100 + 1; 
    }

    auto start = std::chrono::high_resolution_clock::now();

    switch (option)
    {
        case 1:
            std::cout << "Insert Sort" << std::endl;
            InsertSort(arr, size);
        break;
        case 2:
            std::cout << "Selection Sort" << std::endl;
            SelectionSort(arr, size);
        break;
        case 3:
            std::cout << "Bubble Sort" << std::endl;
            BubbleSort(arr, size);
        break;
        case 4:
            std::cout << "Merge Sort" << std::endl;
            MergeSort(arr, 0, (sizeof(arr) / sizeof(arr[0]) - 1));
        break;
        case 5:
            std::cout << "Heap Sort" << std::endl;
            HeapSort(arr, size);
        break;
        case 6:
            std::cout << "Quick Sort" << std::endl;
            QuickSort(arr, 0, size - 1);
        break;
    
    default:
        break;
    }


    //InsertSort(arr, size);
    //SelectionSort(arr, size);
    //BubbleSort(arr, size);
    //MergeSort(arr, 0, (sizeof(arr) / sizeof(arr[0]) - 1));
    //HeapSort(arr, size);
    //QuickSort(arr, 0, size - 1);

    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> duration = end - start;

    std::cout << "Tiempo de ejecucion: " << duration.count() << " segundos." << std::endl;
    
    /*for (int i = 0; i < size; i++) {
        std::cout << arr[i] << std::endl;
    }*/
    return 0;
}