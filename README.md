# testmeof
ПОСТАНОВКА ЗАДАЧИ:
Координаты задаются в следующем виде:
/ - корневой объект;
//«имя объекта» - поиск объекта по уникальному имени от корневого (для
однозначности уникальность требуется в рамках дерева);
. - текущий объект;
«имя объекта 1»[/«имя объекта 2»] . . . - относительная координата от
текущего объекта, «имя объекта 1» подчиненный текущего;
/«имя объекта 1»[/«имя объекта 2»] . . . - абсолютная координата от
корневого объекта.
Примеры координат:
/
//ob_3
.
ob_2/ob_3
ob_2
/ob_1/ob_2/ob_3
Система содержит объекты пяти классов, не считая корневого. Номера
классов: 2,3,4,5,6.
Состав и иерархия объектов строиться посредством ввода исходных
данных. Ввод для построения дерева объектов строится следуюшим образом: 
первая строка - имя корневого объекта
Вторая и далее строки - Абсолютный путь к родителю создаваемого объекта, имя 
создаваемого объекта и номер класса в формате "абс_путь имя_объекта номер"
последняя строка - "endtree"
При построении дерева уникальность наименования относительно
множества непосредственно подчиненных объектов для любого головного объекта
соблюдены.
Добавить проверку допустимости исходной сборки. Собрать дерево
невозможно, если по заданной координате головной объект не найден (например,
ошибка в наименовании или еще не расположен на дереве объектов).
Система отрабатывает следующие команды:
SET «координата» – устанавливает текущий объект;
FIND «координата» – находит объект относительно текущего;
END – завершает функционирование системы (выполнение
программы).
Изначально, корневой объект для системы является текущим.
При вводе данных в названии команд ошибок нет. Условия уникальности
имен объектов для однозначной отработки соответствующих команд соблюдены.
---------------------
Особое условие - функциональная часть (т.е. не считая комментарии, имён 
классов и методов) файла main.cpp должна остаться неизменной.
---------------------