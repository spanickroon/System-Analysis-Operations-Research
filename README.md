# System-analysis-operations-research

## Task 1. Алгоритм Дейкстры.
### Input file name: input.txt
### Output file name: output.txt
### Time limit: 1 s
### Memory limit: 64 MB

```
Задан неориентированный взвешенный псевдограф, вершины которого — числа от 1 до n. Требуется найти кратчайшую цепь между вершинами 1 и n. Гарантируется, что (1, n) - цепь существует.
```

### Input

```
В первой строке содержатся целые числа n и m (1 ≤ n ≤ 200 000, 0 ≤ m ≤ 300 000), где n — число вершин, а m — число рёбер в псевдографе. Далее в m строках содержатся сами рёбра, по одному в строке. Каждое ребро задается тремя числами ui, vi, wi (1 ≤ ui, vi ≤ n, 0 ≤ wi ≤ 11111), где ui, vi — это концы ребра, а wi — его длина. 
```

### Output

```
Выведите одно число — длину кратчайшей цепи.
```

---

## Task 2. Максимальный поток.
### Input file name: flow.in
### Output file name: flow.out
### Time limit: 2 s
### Memory limit: 64 MB

```
Задан ориентированный граф с M вершинами и N рёбрами. Для каждого ребра задана его пропускная способность Cj (1 ≤ j ≤ N). Среди вершин выделены источник и сток.

Требуется определить максимальный поток из источника в сток.
```

### Input

```
Первая строка входного файла содержит величины M и N (2 ≤ M ≤ 1000, 1 ≤ N ≤ 10000).
Во второй строке файла записаны значения s и t – номера источника и стока соответственно (1 ≤ s, t ≤ M, s ≠ t).
Каждая из последующих N строк описывает одно ребро и содержит три числа: номер начальной и конечной вершины, а также пропускную способность этого ребра. Величины Cj — целые, положительные, не превосходящие 100.
Нумерация вершин начинается с единицы.
```

### Output

```
Выведите в первой строке величину потока, поступающего в сток, а в последующих N строках — поток, проходящий по каждому реб flow.outру.
Порядок задания величин потока должен соответствовать порядку описания рёбер во входном файле.
Если задача допускает несколько решений, выведите любое из них.
```

---

## Task 3. Нефть.
### Input file name: input.txt
### Output file name: output.txt
### Time limit: 1-4 s
### Memory limit: нет

```
В некоторой стране имеются n нефтяных вышек, i-я из которых способна выкачать до ai тысяч баррелей нефти в сутки, и m нефтеперерабатывающих заводов, каждый из которых, в свою очередь, способен переработать до bj тысяч баррелей нефти в сутки. Заводы и вышки связаны трубопроводами; ввиду различных причин стоимость транспортировки одной тысячи баррелей от i-й вышки к j-му заводу составляет cij денежных единиц; объём перекачки не ограничен.

Учитывая, что вышки и заводы должны находится в производственном балансе, т. е. вся выкачиваемая нефть должна быть вовремя переработана (излишки нигде не должны сливаться или накапливаться), какое максимальное количество нефти в сутки может перерабатывать данная инфраструктура? На данный вопрос ответить относительно легко, поэтому нас интересует лишь величина минимальных возможных затрат среди всех максимальных по объёму перерабатываемой нефти решений.
```

### Input

```
В первой строке находятся целые числа n и m (1 ≤ n, m ≤ 300) — число вышек и заводов соответственно. Во второй строке через пробел перечислены n целых чисел — значения ai (1 ≤ ai ≤ 30000). В третьей строке через пробел перечислены m целых чисел — значения bj (1 ≤ bj ≤ 30000). Сумма всех ai равна сумме всех bj. В последующих n строках по m целых чисел записаны стоимости транспортировки; j-е число в (i + 3)-й строке задаёт значение cij (1 ≤ cij ≤ 109).
```

### Output

```
В единственной строке выведите одно целое число — минимальную величину затрат на транспортировку при условии максимизации объёма переработки.
```

---

## Task 4. Путешествия дяди Бени.
### Input file name: стандартный ввод
### Output file name: стандартный ввод
### Time limit: 1 s
### Memory limit: 1024 MB

```
Дядя Беня — очень серьезный человек. Но как и всем людям, дяде Бене нужен отдых. Поэтому дядя Беня решил отправиться в путешествие.
Совсем недавно дядя Валера (пожилой изобретатель, 54 года) предложил ему испытать новое изобретение — телепорт. К сожалению, у телепорта существуют трущиеся детали, поэтому он не может служить вечно. Дядя Валера рассчитал, что после k-го использования телепорт сломается, и предупредил дядю Беню об этом. Теперь, когда у дяди Бени уже есть телепорт, он решил применить его в своем следующем путешествии.
Дядя Беня составил список из nnn городов, которые он хочет посетить, причем ровно один раз. Так же он знает информацию о дорогах связывающих эти города (их всего m). Все дороги являются двунаправленными. Любая пара городов может быть связана напрямую не более чем одной дорогой.
Теперь, когда у дяди Бени есть вся информация, он хочет составить оптимальный маршрут. Однако у этого маршрута есть ограничения. К примеру, дядя Беня находится в городе a и хочет попасть в город b. Он может пойти (или проехать) по дороге, пройдя (или проехав) расстояние равное длине дороги, либо он может воспользоваться телепортом, пройдя при этом нулевое расстояние. Нужно учесть, что дядя Беня может начать свой маршрут с абсолютно любого города и завершить в абсолютно любом.
Так как у дяди Бени много других дел, он просит вас найти длину кратчайшего маршрута.
```

### Input

```
В первой строке даны три числа n, m, k (1≤n≤16, 0≤m≤n(n−1)/2, 0≤k≤16) — количество городов, количество дорог, и максимальное количество использований телепорта соответственно.
Далее идут nnn строк, где в (i+1)-ой строке указано название i-го города. Названия городов состоят только из строчных латинских букв [a-z]. Длинна каждого названия находится в пределах [1;32].
Далее идут mmm строк, где в (n+i+1)-ой строке указано описание i-ой дороги. Описание дороги соответствует формату: <Название города> <Название города> <Длина дороги>. Длина дороги является натуральным числом, не превышающим 10^6.
```

### Output

```
В единственной строке вас просят вывести число — длину кратчайшего пути. Если такого пути не существует, требуется вывести «-1».
```

---

## Task 5. Манипуляции дяди Бени.
### Input file name: стандартный ввод
### Output file name: стандартный ввод
### Time limit: 1 s
### Memory limit: 1024 MB

```
Дядя Беня — очень известный (в узких кругах, конечно) манипулятор. Совсем недавно в его руки попалась очень интересная карта конкурирующей компании. На ней были нанесены nnn городов, а также m однонаправленных дорог. Карта была построена таким образом, что не найдется такой пары городов a и b, что существует простой путь из вершины a в вершину b, а также из вершины b в вершину a.
На карте, помимо городов и дорог, был выписан маршрут поставки некоторого груза из города под номером 1 в город под номером n. Дядя Беня решил избавиться от конкурентов, изменив этот маршрут так, чтобы его стоимость была максимальной, тем самым причинив конкурентам большие убытки.
Так как дядя Беня очень серьезный человек, он просит вас найти стоимость максимального пути.
```

### Input

```
В первой строке задано два целых числа nnn и mmm — количество городов и количество дорог соответсвенно.
В следующих m строках задано по три целых числа ai, bi​ и wi​ — город из которого исходит дорога, город, в который дорога входит и стоимость дороги соответсвенно.
1≤n,m≤2⋅10^5
1≤ai,bi≤n1
1≤wi≤10^9
Гарантируется, что путь из вершины 1 в вершину nnn существует всегда.
```

### Output

```
В единственной строке выведие одно целое число — ответ на задачу.
```

---