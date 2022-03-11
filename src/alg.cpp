// Copyright 2021 NNTU-CS

int cbinsearch(int *arr, int size, int value) {
  //  поместить сюда реализацию алгоритма
  void quickSort(int *arr, int first, int last) {
  if (first < last) {
    int left = first, right = last;
    int midle = arr[(left + right) / 2];
    do {
      while (arr[left] < midle) {
        ++left;
      }
      while (arr[right] > midle) {
        --right;
      }
      if (left <= right) {
        int Temp = arr[left];
        arr[left] = arr[right];
        arr[right] = Temp;
        ++left;
        --right;
      }
    } while (left < right);
    quickSort(arr, first, right);
    quickSort(arr, left, last);
  }
  return;
}

int cbinsearch(int *arr, int size, int value) {
  quickSort(arr, 0, size - 1);
  int count = 0, left = 0, right = size - 1;
  while (left < right) {
    int mid = (left + right) / 2;
    if (arr[mid] == value) {
      int tmp = mid;
      while (arr[tmp] == value) {
        ++count;
        ++tmp;
      }
      while (arr[mid - 1] == value) {
        ++count;
        --mid;
      }
      return count;
    } else if (arr[mid] > value) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }
  return 0; // если ничего не найдено
}
