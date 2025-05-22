# Practika
## Документация

### Класс: `QueueReconstructor`

Реализован в файле `QueueReconstructor.h`. Содержит один статический метод.

#### Метод: `reconstructQueue`

```cpp
static std::vector<std::vector<int>> reconstructQueue(std::vector<std::vector<int>>& people)
```

#### Описание:

Метод восстанавливает порядок людей в очереди по их росту и количеству человек перед ними, у которых рост больше или равен.

Каждый человек представлен парой чисел `[h, k]`, где:

* `h` — рост человека,
* `k` — количество людей с ростом ≥ `h`, стоящих перед ним в очереди.

#### Параметры:

* `people` — вектор векторов целых чисел (`std::vector<std::vector<int>>`), где каждый внутренний вектор содержит два элемента: `[h, k]`.

#### Возвращаемое значение:

* Вектор векторов целых чисел, представляющий восстановленную очередь в правильном порядке.

#### Логика работы:

1. Сортировка массива `people` по убыванию роста (`h`). Если рост одинаковый — по возрастанию `k`.
2. Итеративная вставка каждого человека на позицию `k` в результирующем векторе.

#### Пример:

Вход:

```cpp
{ {7,0}, {4,4}, {7,1}, {5,0}, {6,1}, {5,2} }
```

Результат:

```cpp
{ {5,0}, {7,0}, {5,2}, {6,1}, {4,4}, {7,1} }
```

---

### Пример использования

Файл: `QueueReconstruction.cpp`

```cpp
#include <iostream>
#include "QueueReconstructor.h"

int main() {
    std::vector<std::vector<int>> people = { {7,0},{4,4},{7,1},{5,0},{6,1},{5,2} };
    std::vector<std::vector<int>> result = QueueReconstructor::reconstructQueue(people);

    for (const auto& person : result) {
        std::cout << "[" << person[0] << "," << person[1] << "] ";
    }

    return 0;
}
```

Ожидаемый вывод:

```
[5,0] [7,0] [5,2] [6,1] [4,4] [7,1]
```

---

### Юнит-тестирование

Файл: `QueueReconstructionTest.cpp`

Юнит-тесты написаны с использованием **Microsoft Visual Studio Unit Test Framework**.

Проверяются следующие случаи:

* Базовые примеры из условия задачи
* Пустой входной массив
* Один человек в очереди
* Все люди одинакового роста с `k = 0` или `k > 0`
* Большие значения роста
* Устойчивость алгоритма при перестановке входных данных

Пример теста:

```cpp
TEST_METHOD(TestExample1)
{
    std::vector<std::vector<int>> input = { {7,0},{4,4},{7,1},{5,0},{6,1},{5,2} };
    std::vector<std::vector<int>> expected = { {5,0},{7,0},{5,2},{6,1},{4,4},{7,1} };
    auto result = QueueReconstructor::reconstructQueue(input);
    AssertEqualVectors(expected, result);
}
```

Для запуска тестов используйте:

* Меню **Test > Run All Tests** в Visual Studio

Функция `AssertEqualVectors` сравнивает содержимое двух двумерных векторов поэлементно.
