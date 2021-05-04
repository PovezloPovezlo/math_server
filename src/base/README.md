# Структуры данных

## Длинные числа: LongNumber
LongNumber - длинное целое число

### Создание

Ключевое слово `auto` перед именем переменной - автоматическое определение типа

```c++
LongNumber num("3435"); // через строку

auto zero = LongNumber::empty(); // получить ноль

LongNumber num(20, true); // число длиной 20 цифр, положительное
LongNumber negativeNum(23, false); // число длиной 23 цифр, отрицательное

auto num = (LongNumber)6; // 6 станет LongNumber
auto num = LongNumber::fromInt(6); // то же самое
```

### Свойства

#### Положительное ли число
```c++
num.isPositive; // без скобок, это не функция. true - положительное. false - отрицательное
```

### Функции

#### Длина числа
```c++
num.length(); // длина числа (сколько цифр)
```

#### Индекс старшей цифры
Индекс самой старшей цифры (в числе 1590 это будет цифра 1, и ее индекс будет 3)
```c++
num.lastElementIndex();
```

#### Доступ как к массиву
```c++
LongNumber num("128");
num[2]; // 1
num[0]; // 8
```

Если вы попытаетесь получить цифру под номером k, которой в числе нет (например число трехзначное, а вы пытаетесь получить n[6]), то вернет 0 (однако будьте аккуратны, так как в таком случае размер числа повысится, так как в коде при таком вызове должна предоставляться какая-то ячейка памяти).
Также можно сделать следующее
```c++
num[4] = 9; 
```
Тогда число будет 90128. 

#### Превратить в строку
```c++
LongNumber num("128");

num.toString(); // "128"
```

## Длинные числа: ULongNumber
ULongNumber - целые неотрицательные числа (натуральные числа с нулем)
ULongNumber наследует LongNumber, так что к нему свойственны все функции и свойства LongNumber

## Длинные числа: NLongNumber
NLongNumber - натуральные числа
NLongNumber наследует ULongNumber, так что к нему свойственны все функции и свойства LongNumber

## Рациональные числа: RationalFraction

### Создание

```c++
LongNumber numerator("числитель");
NLongNumber denominator("знаменатель");

RationalFraction num(numerator, denominator);

auto num = (RationalFraction)4; // Будет дробь 4/1

auto num = RationalFraction::empty(); // Будет дробь 0/1

auto num = RationalFraction::fromInt(4); // Будет дробь 4/1
auto num = RationalFraction::fromTwoInt(4, 6); // Будет дробь 4/6
```

### Свойства

#### Числитель
```c++
num.numerator // LongNumber
```

#### Знаменатель
```c++
num.denominator // NLongNumber
```

### Функции

#### Превратить в строку
```c++
auto numerator = (LongNumber) 4;
auto denominator = (NLongNumber) 5;

RationalFraction num(numerator, denominator);

num.toString(); // "4/5"
```

Если знаменатель 1, то мы можем его не учитывать
```c++
auto numerator = (LongNumber) 4;
auto denominator = (NLongNumber) 1;

RationalFraction num(numerator, denominator);

num.toString(); // "4"
```

Без разницы какой знаменатель, если числитель нулевой
```c++
auto numerator = (LongNumber) 0;
auto denominator = (NLongNumber) 4;

RationalFraction num(numerator, denominator);

num.toString(); // "0"
```

В будущем, когда пройдет 1 волна, будет еще так
```c++
auto numerator = (LongNumber) 4;
auto denominator = (NLongNumber) 6;

RationalFraction num(numerator, denominator);

num.toString(); // "2/3"
```

## Полином (многочлен): Polynomial

### Создание 
```c++
Polynomial p();
p.addElement(0, (RationalFraction)4); // добавляем элементы
p.addElement(1, (RationalFraction)4); 
p.addElement(2, (RationalFraction)3);
p.addElement(3, (RationalFraction)2);

// еще можно так
p.addElement(new PolynomialPair(4, (RationalFraction)1));
```

### Свойства

#### Прямой доступ к упорядоченному массиву коэффициентов
Очень рекомендуется его использовать для прохождения по полиному
Используйте begin() end() или rbegin() rend()
```c++
Polynomial p();

p.coefficients; // <--
```

### Функции

#### Превратить в строку

Если многочлен нулевой (есть только константа и она равна нулю), то будет просто "0"
```c++
Polynomial p();

p.toString(); // "0"
```

Если многочлен имеет константу равную нулю, но имеет ненулевые коэффициенты при x, то будет так
```c++
Polynomial p();
p.addElement(4, (RationalFraction)6);

p.toString(); // "6*x^4"
```

Если многочлен состоит из нескольких частей, то получится следующее
(обратите внимание что там нет знака +, там просто пробел)
```c++
Polynomial p();
p.addElement(0, (RationalFraction)4);
p.addElement(2, (RationalFraction)3);

p.toString(); // "3*x^2 4"
```

### Добавление элемента
```c++
Polynomial p();
p.addElement(0, (RationalFraction)4); 
p.addElement(степень, коэффициент); 
```

### Первый и последний элементы
Прежде чем ознакомиться с этими функциями, нужно ознакомиться 
со структурой `PolynomailPair*`

Это просто структура с полями `degree` (size_t) и `value` (RationalFraction)
Эти значения можно спокойно менять

```c++
Polynomial p();
p.addElement(0, (RationalFraction)4); 
p.addElement(1, (RationalFraction)5); 
p.addElement(2, (RationalFraction)6); 

p.firstElement(); // Будет PolynomialPair* с degree=0 и value=4
p.firstElement().degree; // 0
p.firstElement().value; // RationalFraction(numerator=4, denominator=1)

p.lastElement(); // Будет PolynomialPair* с degree=2 и value=6
p.lastElement().degree; // 2
p.lastElement().value; // RationalFraction(numerator=6, denominator=1)
```

### Получить элемент 
Обратите внимание, что если попытаетесь получить 
несуществующий элемент, то получите nullptr. 

Крайне не советую использовать метод `get`. Если захотите
его использовать, посоветуйтесь с архитектором
```c++
Polynomial p();
p.addElement(0, (RationalFraction)4); 
p.addElement(1, (RationalFraction)5); 
p.addElement(2, (RationalFraction)6); 

p.get(2); // PolynomialElement* с degree=2 и value=6
p.get(3); // nullptr
```

Есть более безопасный метод `getCoefficient`, используйте его. 
Он возвращает непосредственно коэффициент
```c++
Polynomial p();
p.addElement(0, (RationalFraction)4); 
p.addElement(1, (RationalFraction)5); 
p.addElement(2, (RationalFraction)6); 

p.getCoefficient(2); // RationalFraction(numerator=6, denominator=1)
```

### Обновление значения
Обратите внимание, что если вы установите нулевой 
коэффициент, то элемент будет удален
(но лучше для удаления использовать `remove`)

```c++
Polynomial p();
p.addElement(0, (RationalFraction)4); 
p.addElement(1, (RationalFraction)5); 
p.addElement(2, (RationalFraction)6); 

p.set(1, (RationalFraction)7);
```

### Удаление элемента
```c++
Polynomial p();
p.addElement(0, (RationalFraction)4); 
p.addElement(1, (RationalFraction)5); 
p.addElement(2, (RationalFraction)6); 

p.remove(1); // удалится 5*x^1
```