// Copyright 2021 NNTU-CS
int cbinsearch(int *arr, int size, int value) {
    int count = 0; // Инициализируем счетчик найденных элементов
    int left = 0; // Левая граница интервала
    int right = size - 1; // Правая граница интервала
    // Пока левая граница не пересекла правую
    while (left <= right) {
        int mid = left + (right - left) / 2; // Находим середину интервала
        if (arr[mid] == value) {
            // Если значение найдено, увеличиваем счетчик
            count++;
            // Проверяем соседние элементы на предмет дополнительных вхождений
            int left_idx = mid - 1;
            int right_idx = mid + 1;
            while (left_idx >= 0 && arr[left_idx] == value) {
                count++;
                left_idx--;
            }
            while (right_idx < size && arr[right_idx] == value) {
                count++;
                right_idx++;
            }
            break;
        } else if (arr[mid] < value) {
            left = mid + 1; // Сужаем интервал справа
        } else {
            right = mid - 1; // Сужаем интервал слева
        }
    }
    return count;
}

