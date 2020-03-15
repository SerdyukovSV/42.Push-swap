#!/bin/sh
# this script has been written by Eddy 
#
#		colors
#
# Создан 17-го Июль 2009 года в 10:43
#
echo "
********* СВОЙСТВА **********
Название стиля 		| Код
------------------------|----
Сбросить все свойства 	| 0
Повышенная яркость 	| 1
Пониженная яркость 	| 2
Подчеркнутый		| 4
Нормальная яркость 	| 5
Инвертированный 	| 7
Скрытый 		| 8
********** ЦВЕТА ***********
Название цвета 	|Текст	|Фон
----------------|-------|---
Черный		| 30	| 40
Красный 	| 31	| 41
Зеленый 	| 32	| 42
Желтый		| 33 	| 43
Синий		| 34 	| 44
Маджента 	| 35	| 45
Циановый 	| 36	| 46
Белый		| 37 	| 47
----------------------------
Цвета задаются в формате [свойство;цвет_текста;цвет_фона] (можно указывать только один пар.),
например: \033[37;40m - белый текст на черном фоне
"
HEADER="\t\t"
for B in `seq 40 47`
do
	HEADER=`echo -e "$HEADER Фон $B\t\c"`
done

for A in 1 2 4 5 7 8 9
	do
	echo -e "\033[0m\n\n Свойство $A:\n$HEADER\c"
	for B in `seq 30 38`
		do
		echo -e "\n Текст $B\t\c"
		for C in `seq 40 47`
			do
				echo -e "\033[$A;$B;$C""m Буквы\t\c"
			done
		echo -e "\033[0m\c"
		done
	done
echo -e "\033[0m\n\n"