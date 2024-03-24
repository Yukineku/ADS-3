// Copyright 2021 NNTU-CS

int cbinsearch(int *arr, int size, int value) {
  int count = 0; // счётчик
  int left = 0; // Левая граница интервала
  int right = size - 1; // Правая граница интервала

  // Пока левая граница не пересекла правую
  while (left <= right) {
      int mid = left + (right - left) / 2; // Находим середину интервала
      if (arr[mid] == value) {
          count++;
          // Проверяем соседние элементы на предмет дополнительных вхождений
          int leftFrMid = mid - 1;
          int rightFrMid = mid + 1;
          while (leftFrMid >= 0 && arr[leftFrMid] == value) {
              count++;
              leftFrMid--;
          }
          while (rightFrMid < size && arr[rightFrMid] == value) {
              count++;
              rightFrMid++;
          }
          break; // выход из цикла при нахождении всех элементов
      } else if (arr[mid] < value) {// значение справа
          left = mid + 1; // Сужаем интервал справа
      } else {
          right = mid - 1; // Сужаем интервал слева т.к значение слева
      }
  }
  return count; // Возвращаем количество найденных элементов
}
}
