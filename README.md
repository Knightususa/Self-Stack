# Stack Project

Проект реализует структуру данных "Стек" на языке C++ с поддержкой различных типов данных (int, double, char, struct) и цветным выводом в консоль.

## Структура файлов

```text
Self Stack/
├── Headers/
│   ├── dump.h          # Заголовок для отладочного дампа
│   ├── global.h        # Глобальные настройки, типы и макросы
│   ├── parser.h        # Заголовок для ввода/вывода
│   └── stack.h         # Заголовок для операций со стеком
├── Source/
│   ├── dump.cpp        # Реализация дампа
│   ├── main.cpp        # Точка входа
│   ├── parser.cpp      # Реализация ввода/вывода
│   └── stack.cpp       # Реализация операций со стеком
├── .gitattributes
└── main.exe            # Скомпилированный файл (Windows)
```
# Компиляция
Для сборки проекта используйте компилятор g++.
В зависимости от желаемого типа данных стека, добавьте соответствующий флаг:

### Тип
int (по умолчанию): без флагов

double: -DSTACK_T_DOUBLE

char: -DSTACK_T_CHAR

struct: -DSTACK_T_STRUCT
(содержит int, char, double)

### Дебаг режим и режимы защиты
-DON_CANARY_PROTECTION
включить канарейки в данные стэка и в сам стэк

-DON_HASH_PROTECTION
включить хэширование данных стэка и самого стэка


## Пример компиляции
```bash
g++ .\Source\main.cpp .\Source\parser.cpp .\Source\stack.cpp .\Source\dump.cpp -o main.exe
```
С флагом для double:

```bash
g++ .\Source\main.cpp .\Source\parser.cpp .\Source\stack.cpp .\Source\dump.cpp -DSTACK_T_DOUBLE -o main.exe
```
С флагом для struct:

```bash
g++ .\Source\main.cpp .\Source\parser.cpp .\Source\stack.cpp .\Source\dump.cpp -DSTACK_T_STRUCT -o main.exe
```
Для отладки (включение assert)
```bash
g++ .\Source\main.cpp .\Source\parser.cpp .\Source\stack.cpp .\Source\dump.cpp -DON_DEBUG -o main.exe
```
## Использование
После запуска программа предложит ввести команды:

init — инициализировать стек (запросит ёмкость)

push — добавить элемент

pop — удалить элемент

destroy — уничтожить стек

Цветной вывод помогает понять состояние стека.
