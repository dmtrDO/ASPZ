<hr>

# <p style="margin: 0;" align="center">Лабораторна робота №12-13</p>
## <p align="center" style="margin: -14px 0 6px 0">Signaling</p>
<br>

<p align='justify'>
<strong>Handling Signals</strong> (рисунок 1, 2).
</p>
<p align='center'>
    <img src="img/1.png">
</p>
<p align='center'>
    Рисунок 1 - Код програми
</p><br>

<p align='center'>
    <img src="img/2.png">
</p>
<p align='center'>
    Рисунок 2 - Компіляція та виконання
</p><br>

<p align='justify'>
Як бачимо, тут обробляється SIGINT — натискання Ctrl+C не завершить програму, а виводить повідомлення:

> Caught signal 2

Щоб вийти можна натиснути Ctrl+Z, але в чому різниця ? Ця комбінація клавіш надсилає SIGSTOP і призупиняє виконання поточного процесу. Але процес переходить на виконання у фоновому режимі і для повного завершення потрібно ще написати:

> kill -9 PID

<a href="https://askubuntu.com/questions/510811/what-is-the-difference-between-ctrl-z-and-ctrl-c-in-the-terminal">https://askubuntu.com/questions/510811/what-is-the-difference-between-ctrl-z-and-ctrl-c-in-the-terminal</a><br><br>


<b>
A Simple C Program that Handles a Couple of Signals
</b>
 (рисунок 3, 4).
</p>

<p align='center'>
    <img src="img/3.png">
</p>
<p align='center'>
    Рисунок 3 - 
</p><br>

<p align='center'>
    <img src="img/4.png">
</p>
<p align='center'>
    Рисунок 4 - 
</p><br>

<p align='justify'>
??????
</p>



































<!-- 

<br><hr>

## <p style="margin: -12px 0 6px 0;" align="center">Варіант 5</p>

<br>

> 5. Напишіть багатопоточну програму, яка виконує критичну обчислювальну задачу, і у
випадку SIGSEGV відновлюється з останньої збереженої контрольної точки.

<br>


<p align='justify'>
    ???????????
</p>

<p align='center'>
    <img src="img/?.png">
</p>
<p align='center'>
    Рисунок ? - 
</p><br>

<p align='justify'>
    ??????????
</p>
 -->



