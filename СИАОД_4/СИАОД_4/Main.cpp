#include <iostream>

using namespace std;

void quickSort(int* arr, int size) {
    int i = 0;
    int j = size - 1;
    int mid = arr[size / 2];

    do {
        while (arr[i] < mid) {
            i++;
        }
        while (arr[j] > mid) {
            j--;
        }
        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    } while (i <= j);


    if (j > 0) {
        quickSort(arr, j + 1);
    }
    if (i < size) {
        quickSort(&arr[i], size - i);
    }
}

void reverseSort(int* arr, int size) {
    quickSort(arr, size);
    int middle = size / 2;
    for (int i = 0; i < middle; i++) {
        swap(arr[i], arr[size - i - 1]);

    }
}

void search(int* arr, int symbol, int size) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == symbol) {
            cout << "»ндекс: " << i;
            break;
        }
    }
}

int main() {
    setlocale(0, "Rus");
    int size;
    cout << "¬ведите размер массива: ";
    cin >> size;
    int* arr = new int[size];

    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }

    int symbol;
    cout << "¬ведите число дл€ поиска не больше 100: ";
    cin >> symbol;
    while (symbol > 100) {
        cout << "¬ведите другое число" << endl;
        cin >> symbol;
    }
    cout << "¬ведите цифру дл€ вида поиска числа в массиве:\n\
        1 - поиск в массиве отсортированном массиве по возрастанию\n\
        2 - поиск в массиве отсортированном массиве по убыванию\n\
        3 - поиск в неотсортированном массиве" << endl;
    string choice;
    cin >> choice;

    if (choice == "1") {
        quickSort(arr, size);
        cout << "»ндекс элемента в массиве: ";
        search(arr, symbol, size);
    }
    if (choice == "2") {
        reverseSort(arr, size);
        search(arr, symbol, size);
    }
    if (choice == "3") {

        search(arr, symbol, size);
    }
}