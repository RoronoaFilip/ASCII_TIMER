# ITP-Praktikum-Project
>**Project for Introduction to Programming from FMI Semester 1**  
>Link to the Docs Document [here](https://github.com/RoronoaFilip/ITP-Praktikum-Project/blob/workflow/09-Project%20_ASCII%20timer_%202021.docx)  

<h1 align = "center">
  СУ „Св. Климент Охридски“, ФМИ 
</h1>
<h5 align = "center">
  Специалност „Софтуерно Инженерство“
</h5>
<h2 align = "center">
  Увод в програмирането (практикум)  
</h2>
<p align = "center">
  2021-2022 г.
</p>
  
### Задание за курсов проект № 9 - ASCII timer
Да се напише програма, която реализира четирицифрен таймер, размерът на цифрите на който е 11х10 символа (ASCII art).  

При стартиране на програмата да се въвежда от потребителя число (брой секунди), след което таймерът започва да отброява оставащото време във формат <ЧАСОВЕ:МИНУТИ:СЕКУНДИ>.  

### **_Звукови сигнали/команди:_**
При нулиране на таймера да се възпроизвежда звуков сигнал.  

### **Визуализация:** 
* Таймерът да се визуализира центриран спрямо прозорец на конзолата с размери 80х25 символа.  
* Всяка цифра да се изобразява с помощта на съответния ASCII символ (виж примера).
* Всяка цифра да се изобразява с различен цвят, който да се избира по случаен принцип.
* При оставащи по-малко от 15 минути да се оцветяват всички цифри в жълто.
* При оставащо време по-малко от 1 минути да се оцветяват всички цифри в червено.
* При оставащо време по-малко от 10 секунди, всички цифри да примигват.

## Пример: 
#### **Визуализацията на таймера може да изглежда така:**  

* hh/mm/ss - hours : minutes : seconds  
![Image for Hours:Minutes:Seconds](/ReadMeImages/HoursMinutesSeconds.png)

* mm/ss - minutes : seconds  
![Image for Minutes:Seconds](/ReadMeImages/MinutesSeconds.png)

* only seconds  
![Image for Seconds](/ReadMeImages/Seconds.png)  

#  

## The Way the Timer works:  
* Each Digit has a specific Pattern, which is saved via Functions in print_number.cpp.
* Each Digit get's printed based on that Pattern and the Line the Printing is on.(A Loop for the Number of the Line)  
* The Functions get the Line Number and that Line from the Pattern get's printed.  
* It works even if the Hours are more than 100 but the Timer isn't centered as the Instructions specify.
## Used Libraries:
* iostream - Input, Output
* Windows.h - Coloring, Sleep
* ctime - Reset rand()  

## Valid Inputs:  
* 1000000000
* 1000000
* 100000
* 10000
* 1000
* 100

## Invalid Inputs:
* If the Input has atleast 1 Character other than a Number  

## Used Tests:  
> ##### ***These Inputs are Invalid, but it's easier to read***
* 3 600 000| -> 1000 Hours (Transform to 3 Digit Hours) Centering Test  
* 360 000--|--> 100 Hours (Transform to 2 Digit Hours) Centering Test
* 36 000---|--> 10 Hours (Transform to single Digit Hours) Centering Test
* 3 600----|---> 1 Hours (Transform to minutes) Centering Test
* 600------|--> 10 Minutes
* 60-------|----> 1 Minute
##
* 72 000---|--> 20 Hours (Transform to 10<=hours<=19) Centering Test
* 43 200---|--> 12 Hours (Transform to 11 hours) Centering Test
* 39 600---|--> 11 Hours (Transform to 10 hours) Centering Test
##
* 900------|--> 15 Minutes (Color Yellow)
* 720------|--> 12 Minutes (Transform to 11 Minutes) Centering Test
* 660------|--> 11 Minutes (Transform to 10 Minutes) Centering Test
* 600------|--> 10 Minutes (Transform to single Digit Minutes) Centering Test
* 60-------|--> 1 Minute (Color Red)
##
* 20 -> 20 Seconds Centering Test
* 11 -> 11 Seconds Centering Test
* 1<=Input<=10 -> Blinking
##
