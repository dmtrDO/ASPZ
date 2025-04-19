<hr>

# <p style="margin: 0;" align="center">Лабораторна робота №6</p>

## <p style="margin: -12px 0 6px 0;" align="center">Варіант 5</p>

<br>

> 5. Test Case #1: реалізуйте і відловіть доступ до неініціалізованої
змінної (наприклад, локальної int).

<br>

<p align='justify'>
     Для початку реалізуємо код з доступом до неініціалізованої змінної, для цього скористаємось кодом Test Case #1 з лекції (рисунок 1).
</p>

<p align='center'>
    <img src="img/1.png">
</p>
<p align='center'>
    Рисунок 1 - код з використанням неініціалізованої змінної
</p><br>

<p align='justify'>
    Для відловлення скористаємось тими інструментами, з якими нас ознайомили в лекції, а саме: Valgrind - інструмент для динамічного аналізу пам’яті та AddressSanitizer (ASan) - швидкий інструмент від Google для виявлення
    помилок пам’яті. Valgrind в мене встановлений з минулої лабораторної, з нього і почну (рисунок 2)
</p>

<p align='center'>
    <img src="img/2.png">
</p>
<p align='center'>
    Рисунок 2 - відловлення з Valgrind
</p><br>

<p align='justify'>
    Як бачимо, маємо таку ж саму помилку, як і в лекції:
</p>

> ***Conditional jump or move depends on uninitialised value(s).***

<p align='justify'>
    Крім того, сам компілятор при компіляції попереджає нас про використання неініціалізованої змінної:
</p>

> ***warning: 'x' is used uninitialized...***

<p align='justify'>
    Тепер відловимо з використанням ASan. Для цього скомпілюємо наш файл згідно з вказівками в лекції (рисунок 3).
</p>

</p>

<p align='center'>
    <img src="img/3.png">
</p>
<p align='center'>
    Рисунок 3 - компіляція з ASan
</p><br>

<p align='justify'>
    Помилка означає, що санітайзер не працює з виконуваними файлами, скомпільованими з включеним PIE (Position Independent Executable), а також при включеному ASLR (Address Space Layout Randomization).
    Для вирішення відключимо ASLR та компілюємо з прапорцем -no-pie (рисунок 4).
</p>

<p align='center'>
    <img src="img/4.png">
</p>
<p align='center'>
    Рисунок 4 - виправлення помилки
</p><br>

<p align='justify'>
    Тепер помилки немає і програма виконується, але ASan не зміг виявити ніяких помилок. Спочатку переконаємось, що ASan взагалі працює на прикладі з очевидною помилкою  (рисунок 5, 6).
</p>

<p align='center'>
    <img src="img/5.png">
</p>
<p align='center'>
    Рисунок 5 - код для тестування ASan
</p><br>

<p align='center'>
    <img src="img/6.png">
</p>
<p align='center'>
    Рисунок 6 - тестування ASan
</p><br>

<p align='justify'>
    Як бачиом, санітайзер дійсно працює та виявляє помилку з  подвійним звільненням пам'яті. Отже він не призначений для виявлення неініціалізованих змінних. Для цього можна використати MSan (Memory Sanitizer).
</p>

> https://github.com/google/sanitizers/wiki/MemorySanitizer

<p align='center'>
    <img src="img/7.png">
</p>
<p align='center'>
    Рисунок 7 - компіляція з MSan та запуск
</p><br>

<p align='justify'>
    Цей інструмент чітко відловлює такі моменти і видає нам попередження про використання неініціалізованого значення.
</p>
