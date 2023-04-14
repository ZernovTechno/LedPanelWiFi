![PROJECT_PHOTO](https://github.com/vvip-68/LedPanelWiFi/blob/main/proj_img.jpg)
# Крутая WiFi панель / гирлянда на esp8266 своими руками
* [Описание проекта](#chapter-0)
* [Папки проекта](#chapter-1)
* [Схемы подключения](#chapter-2)
* [Инструменты](#chapter-3)
* [Как скачать и прошить](#chapter-4)
* [Полезная информация](#chapter-5)

<a id="chapter-0"></a>
## Описание проекта
  
Этот проект является продолжением и развитием проекта ["Крутая WiFi панель / гирлянда на esp8266 своими руками"](https://github.com/vvip-68/GyverPanelWiFi), 
который был зафиксирован на версии 1.13. В отличие от версии 1.13, версия 1.14+ имеет возможность управления через Web-интерфейс, что несомненно
должно порадовать владельцев iPhone и тех, кому не подходит по каким-то причнам управление через Android-приложение.

Что может огорчить - версия 1.14 несовместима с Android-приложением от предыдущей версии, а новое приложение пока еще никто не написал.
Сама прошивка всё так же поддерживает управление через UDP и MQTT каналы, но приложения управления через эти каналы пока что нет.
Если вы управляли своей гирляндой удаленно через MQTT с андроид приложения из проекта - вам лучше оставаться не предыдущей версии. 

Основное назначение проекта - настенные экраны больших размеров или гирлянды на широкие балконы.
Полный функционал реализуется для матриц с размерами от 23x11. Для матриц меньших размеров существуют некоторые ограничения,
связаные с невозможностью отображения часов крупным шрифтом 5x7 для которого требуется матрица не менее 23 пикселей по ширине.
Для матриц менее 23 колонок шириной в часах может использоваться только шрифт 3x5 для которого достаточно 15 колонок. 
Для функции "Бегущая строка" минимальная высота матрицы - 8 пикселей. 
Таким образом, заводские матрицы размером 16x16 прекрасно подходят для сборки часов-будильника со спецэффектамми, а
заводские матрицы 32x8 - для мини-бегущей строки-информатора.

Матрицы могут собираться в сборки, состоящие из заводских матриц одинакового или разного размера. Так, для бегущей строки можно 
собрать матрицу 64x8, 96x8 или 128x8. Единственное ограничение на размеры матрицы - не более 128 диодов по ширине и высоте.

Общее количество светодиодов, которые поддерживает прошивка зависит от типа используемого микроконтроллера. 

Для плат на базе микроконтроллера **ESP8266** общее количество диодов не должно превышать **768**. 
При бОльшем количестве светодиодов в матрице ввиду малого объема доступной оперативной памяти устройство будет работать нестабильно
при управлении через Web-интерфейс. Страница управления может не открываться в браузере или открытие страницы может приводить
к перезагрузке микроконтроллера.

Платы на базе микроконтроллера ESP32 имеют существенно больший объем доступной оперативной памяти и могут управлять матрицами 
значительно большего размера. 

### Железо
- Проект собран на базе микроконтроллера ESP8266 в лице платы NodeMCU или Wemos D1 mini (неважно, какую из этих плат использовать) для матриц с общим количеством диодов не более 768
- Реализована поддержка микроконтроллера ESP32, имеющего больший размер оперативной памяти и быстродействие, что позволяет управлять матрицами с большим количеством светодиодов
- Матрица может быть реализована на адресной ленте или отдельных светодиодах серии WS8212/WS8213, спаянных в нити гирлянды проводами
- Также для компактных панелей может использоваться соединение нескольких гибких адресных матриц 8x8, 16×16, 32x8 состоящих из 64/256 диодов с плотностью 100 штук на метр, что позволяет 
  легко получить панели размерами 32х16, 48x16, 64x16 и так далее (до 128 по ширине и/или высоте).
- Система управляется со смартфона или компьютера через Web-интерфейс, открытый в любом современном браузере. 
  Телефон или компьютер должны находиться в локальной сети или ваш роутер должен иметь "белый" IP и настроен проброс портов от роутера до устройства.
  Также доступно управление “оффлайн” с кнопки на корпусе (сенсорная кнопка на TTP223 или любая физическая кнопка с нормально разомкнутыми контактами)
- В случае реализации проекта в виде большой настенной матрицы поддерживается функционал будильника-рассвет и индикация текущего времени на индикаторе TM1637, 
  что позволяет в ночное время полностью выключать саму матрицу, оставляя возможность отображения текущего времени на этом индикаторе
- При наличии подключенного MP3 DFPlayer будильник-рассвет может воспроизводить звуки рассвета, файлы которых помещене на microSD карту в плеере.
- Поддерживается загрузка файлов анимации формата \*.out программы Glediator с microSD-карты.

### Фишки
 - Более 40 крутых эффектов с поддержкой отображения часов или текста бегущей строки поверх эффектов
 - Составление списка любимых эффектов и задания порядка их отображения или включения воспроизведения в случайном порядке
 - 4 интерактивные игры: Лабиринт, Змейка, Тетрис, Арканоид
 - Рисование на матрице PixelArt - управление со страницы в браузере
 - Сохранение нарисованных изображения на SD-карте или во внутренней памяти микроконтроллера
 - Загрузка сохраненных изображений на матрицу и на страницу Web-интерфейса в браузере для редактирования
 - Слайд-шоу из нарисованных вами картинок в эффекте "Слайды"
 - Редактирование и создание картинок пользователя пригодных для загрузки на матрицу в утилите ["JinxFramer"](https://github.com/vvip-68/LedPanelWiFi/wiki/JinxFramer---редактор-анимации,-роликов,-картинок).
 - Регулировка яркости эффектов относительно яркости часов или текста бегущей строки, отображаемых поверх эффектов - ползунок "Контрастность".
 - Возможность задания до 36 разных [текстовых строк](https://github.com/vvip-68/LedPanelWiFi/wiki/Настройка-бегущей-строки), задание порядка их "воспроизведения" a также параметров отображения.
   Тексты задаются из программы на смартфоне без необходимости перепрошивки контроллера.
   [Как настроить.](https://github.com/vvip-68/LedPanelWiFi/wiki/Настройка-бегущей-строки)
 - Поддержка текста бегущей строки с отображением оставшегося до события времени, например: "До Нового года осталось 5 дней 12 часов"
   и после наступления события - вывод специального текста, например: "С Новым годом!!!"
 - Текст бегущей строки может отображаться различными цветами внутри одной строки
 - Поддержка в бегущей строке шрифтов трех размеров: малый (5x8 точек), средний (8х13 точек), большой (10х16 точек) - [настраивается](https://github.com/vvip-68/LedPanelWiFi/wiki/Большие-буквы-в-бегущей-строке) в скетче при компиляции проекта
 - Поддержка символов украинского, литовского и некоторых других языков (в этом случае - размер шрифта 5x11. 8x17, 10x20 точек)
 - Настройка скорости и вариаций отображения для каждого эффекта
 - Поддержка эффектов анимации, подготовленных в программе [“Jinx!”](https://github.com/vvip-68/LedPanelWiFi/wiki/Экспорт-эффектов-анимации-из-ПО-Jinx!), сохраненных на SD карту
 - Редактирование роликов анимации с SD-карты в утилите ["JinxFramer"](https://github.com/vvip-68/LedPanelWiFi/wiki/JinxFramer---редактор-анимации,-роликов,-картинок).
 - [Создание кадров для эффекта "Анимация"](https://github.com/vvip-68/LedPanelWiFi/wiki/Добавление-своей-анимации--к-эффекту-Анимация) в утилите "JinxFramer" для последующего экспорта кода, пригодного для включения в скетч проекта.
 - Работа системы как в локальной сети, так и в режиме “точки доступа”
 - Система получает точное время из Интернета
 - Управление кнопкой: смена режима, настройка яркости, вкл/выкл, отображение текущего IP адреса устройства
 - Режим будильник-рассвет: менеджер будильников на неделю в приложении. Звуковые эффекты, сопровождающие рассвет
 - Отображение текущего времени на индикаторе TM1637
 - Отображение текущего времени на матрице поверх эффектов
 - Отображение текстовых сообщений на матрице поверх эффектов или на одноцветном фоне, заданном в макросе {B} внутри текста бегущей строки
 - Настройка сервера синхронизации времени из Web-приложения
 - Установка текущего времени из Web-приложения вручную, если не удалось подключиться к серверу времени NTP или нет доступа в Интернет
 - Задание в настройках часового пояса не кратного целым часам, например - 5:30, что актуально для некоторых стран, например Индии.
 - Два режима работы индикатора времени TM1637 - светится постоянно или выключается вместе с панелью
 - Пока время не получено с сервера NTP - на индикаторе TM1637 отображается --:-- вне зависимости от настройки
   "Выключать индикатор при выключении панели"
 - Поддержка звука будильника / звука рассвета звуковой платой MP3 DFPlayer
 - Настройки сетевого подключения (SSID и пароль, статический IP) задаются в Web-приложении и сохраняются в памяти микроконтроллера
 - Если не удается подключиться к сети (неверный пароль или имя сети) - автоматически создается точка подключения
   с именем PanelAP, пароль 12341234, IP 192.168.4.1. Подключившись к точке доступа из Web-интерфейса
   можно настроить параметры сети. Если после задания параметров сети WiFi соединение установлено - 
   в приложении на смартфоне виден IP адрес подключения к сети WiFi.
 - Отображение текущего IP адреса устройства на индикаторе TM1637 или на матрице в режиме бегущей строки
 - Быстрое включение популярных режимов из приложения
 - Четыре программируемых по времени режима, позволяющие, например, настроить автоматическое выключение панели в ночное время
   и автоматическое включение панели вечером в назначенное время
 - Два специальных режима времени - "Рассвет" и "Закат". Время рассвета и заката на текущий день берется с сервера погоды при получении текущих погодных условия и температуры
 - Получение текущей температуры воздуха и погоды с сервера Яндекс.Погода или OpenWeatherMap. Полученные данные могут отображаться в бегущей строке или в режиме отображения времени вместе с часами
   Код региона (города) указывается в настройках в программе на смартфоне. Настройка погоды - [тут](https://github.com/vvip-68/LedPanelWiFi/wiki/Настройка-получения-информации-о-погоде)  
 - Поддержка [составных матриц](https://github.com/vvip-68/LedPanelWiFi/wiki/Сборная-матрица), собранных из стандартных матриц 8x8, 16x16, 8x32 в одну матрицу большого размера.
 - [Настройка](https://github.com/vvip-68/LedPanelWiFi/wiki/Сборная-матрица) размеров матрицы (ширины и высоты), а также способ ее подключения - угол, направление из угла задаются в Web-приложении
   без необходимости перепрошивки микроконтроллера.
 - Возможность работы со сборными матрицами, собранными из сегментов любых размеров, с любым способом подключения (угол, направление из угла, зигзаг/параллельная).
 - Синхронизация эффектов между устройствами. Может быть создано до 10 групп устройств, количество устройств в группе - не ограничено.
 - Беспроводная трансляция эффектов на матрицу устройств из специализированных программ типа *Jinx!*, *Wixen Lights*, *xLights* и подобных по протоколу *sACN Streaming ACN E1.31 DMX*  


#### Эффекты:
 - Цветная лампа - заливка панели белым или другим выбранным цветом
 - Снегопад
 - Блуждающий кубик
 - Пейнтбол
 - Радуга (горизонтальная, вертикальная, диагональная, вращающаяся)
 - Огонь
 - The Matrix
 - Шарики
 - Конфетти
 - Звездопад
 - Шумовые эффекты с разными цветовыми палитрами (шум Перлина)
 - Плавная смена цвета заливки панели
 - Светлячки
 - Водоворот
 - Мерцание
 - Северное сияние
 - Циклон
 - Тени (меняющийся теневой рисунок на матрице)
 - Демо-версия игры Тетрис - автоигра без возможности управления
 - Демо-версия игры Лабиринт - автоигра без возможности управления
 - Демо-версия игры Змейка - автоигра без возможности управления
 - Демо-версия игры Арканоид - автоигра без возможности управления
 - Демо-версия игры Эволюция (симулятор жизни) - автоигра без возможности управления
 - Движущийся синус
 - Палитра (лоскутное одеяло) 
 - Имитация графического индикатора спектра, движущегося "в такт музыке" 
 - Вышиванка
 - Дождь
 - Камин
 - Стрелки
 - Погода (слайдшоу или отображение текущих погодных условия)
 - Отображение анимированных картинок
 - Фоновые узоры (нотки, сердечки, снежинки, зигзаги и т.п.)
 - Звезды - вспышки крестообразных "звезд" по всему полю матрицы
 - Штора - имитация светодиодной шторы на окне
 - Кубик Рубика + патнашки - вращающиеся / сдвигающиеся полосы и "плашки"
 - Трафик - разнонаправленное движение полосок по полю матрицы
 - Слайды - слайдшоу из PixelArt картинок, нарисованных пользователем
 - Анимация с SD карты - проигрывание роликов, подготовленных в ПО Jinx!

#### Интерактивные игры:

 - Лабиринт
 - Змейка
 - Тетрис
 - Арканоид

### Кнопка управления режимами, последовательность переключения:
#### Будильник сработал, идет рассвет или мелодия пробуждения
- Любое нажатие кнопки отключает будильник
#### Долгое удержание кнопки 
- При включенной панели - плавное изменение яркости
- При выключенной панели - включение яркой белой панели освещения (только для сборки типа "Лампа" - DEVICE_TYPE == 0)
#### Однократное нажатие кнопки
- Включение / выключение панели. При включении возобновляется режим на котором панель была выключена.
#### Двухкратное нажатие кнопки
- Ручной переход к следующему режиму
#### Трехкратное нажатие кнопки
- Включение демо-режима с автоматической сменой режимов по циклу
#### Четырехкратное нажатие кнопки
- Включение яркой белой панели освещения из любого режима, даже если панель была "выключена" /для сборки типа "Лампа"/  
  Отображение IP адреса панели на матрице и на индикаторе TM1637, если подключение к локальной WiFi сети установлено  /для сборки типа "Панель"/  
#### Пятикратное нажатие кнопки
- На индикаторе TM1637 и на матрице отображается IP адрес панели, если подключение к локальной WiFi сети установлено /для сборки типа "Лампа"/

<a id="chapter-1"></a>
## Папки
**ВНИМАНИЕ! Если это твой первый опыт работы с Arduino, читай [инструкцию](#chapter-4)**
- **Android** - файлы с приложениями, примерами для Android и MIT App Inventor
- **firmware** - прошивки
- **libraries** - библиотеки проекта.
- **pics** - примеры картинок для загрузки / отображении на матрице
- **schemes** - схемы подключения компонентов
- **sounds** - звуковые файлы будильника для размещения на SD-карте
- **tools** - полезные утилиты, Jinx! и другие
- **wiki** - файлы раздела wiki-страниц GitHub 

<a id="chapter-2"></a>
## Схема

Варианты схем с различным набором компонент, для микроконтроллеров **ESP8266** - NodeMCU, Wemos d1 mini, **ESP32** представлены [здесь](https://github.com/vvip-68/LedPanelWiFi/wiki/Варианты-устройств.-Схемы.).

![SCHEME](https://github.com/vvip-68/LedPanelWiFi/blob/master/schemes/schemes.png)

Вариант релизации от [Дмитрия (7918514)](https://github.com/7918514) - схемы, фотографии сборки и готового изделия, печатные платы - все материалы доступны по [ссылке](https://disk.yandex.ru/d/fIo2UEuKpR54hg) в папке "Монстр".

<a id="chapter-3"></a>
## Вам скорее всего пригодится
* [Всё для пайки (паяльники и примочки)](http://alexgyver.ru/all-for-soldering/)
* [Недорогие инструменты](http://alexgyver.ru/my_instruments/)
* [Все существующие модули и сенсоры Arduino](http://alexgyver.ru/arduino_shop/)
* [Электронные компоненты](http://alexgyver.ru/electronics/)
* [Аккумуляторы и зарядные модули](http://alexgyver.ru/18650/)

<a id="chapter-4"></a>
## Как скачать и прошить
* [Первые шаги с Arduino](http://alexgyver.ru/arduino-first/) - ультра подробная статья по началу работы с Arduino, ознакомиться первым делом!
* Скачать архив с проектом
> На главной странице проекта (где ты читаешь этот текст) вверху справа зелёная кнопка **Clone or download**, вот её жми, там будет **Download ZIP**
* Разархивировать скачанный проект в отдельную папку
* Установить ядро системы для используемого микроконтроллера - [инструкция](https://github.com/vvip-68/LedPanelWiFi/wiki/Пошаговая-инструкция-подготовки-среды-для-проекта)  
* Скопировать библиотеки из папки проекта libraries в  
`C:\Program Files (x86)\Arduino\libraries\` (Windows x64)  
`C:\Program Files\Arduino\libraries\` (Windows x86)
* **Подключить внешнее питание 5 Вольт**
* Подключить Arduino к компьютеру
* Открыть в Arduino IDE главный файл прошивки - LedPanelWiFi_v1.14.ino
* Настроить IDE (COM порт, модель Arduino, как в статье выше)
* Настроить что нужно по проекту
* Нажать загрузить
* Загрузить содержимое папки firmware/data в файловую систему микроконтроллера - [инструкция](https://github.com/vvip-68/LedPanelWiFi/wiki/Загрузка-изображений-в-файловую-систему-МК)
* Подключиться к созданной WiFi точке доступа PanelAP
* Открыть в браузере Web-страницу настройки и управления по адресу 192.168.4.1
* Настроить физические размеры и способ подключения матрицы, настроить подключение к локальной WiFi сети
* После перезагрузки устройства оно подключится к локальной сети с заданным вами IP адресом
* Открыть в браузере Web-страницу настройки и управления по заданному вами адресу
* Настроить параметры эффектов, бегущей строки, будильников и так далее
* Пользоваться  

**Подробная инструкция [тут](https://github.com/vvip-68/LedPanelWiFi/wiki/Пошаговая-инструкция-подготовки-среды-для-проекта)**

## Важно
Если проект не собирается (ошибки компиляции) или собирается, но работает неправильно (например вся матрица светится белым и ничего не происходит) - проверьте версии библиотек. 
Используйте библиотеки из папки libraries проектаю
Данный проект рассчитан на работу с версиями ядра плат ESP8266 версии 2.7.4, ESP32 версии 2.0.6 и библиотеки FastLED версии 3.4.0 или более новой - 3.5.0;

**Не используйте библиотеку поддержки плат ESP8266 (ядро) версии 3.x.х и ESP32 версии отличной от 2.0.6 - с ними проект работать не будет ввиду несовместимости с библиотекой FаstLED указанных версий**

Если в качестве микроконтроллера вы используете Wemos D1 - в менеджере плат для компиляции все равно выбирайте **"NodeMCU v1.0 (ESP-12E)"**, в противном случае, 
если выберете плату Wemos D1 (xxxx) - может работать нестабильно, настройки не будут сохраняться в EEPROM, параметры подключения к локальной сети будут сбрасываться 
каждый раз при перезагрузке, плата вместо подключения к локальной сети будет каждый раз создавать точку доступа, пин вывода сигнала на матрицу будет
переключаться с указанного в настройках D2 на физический D4 - не будет вывода изображения на матрицу.

Прошивка использует для работы и хранения настроек - файловую систему микроконтроллера. В вариантах компиляции в настройках в меню Arduino IDE "Инструменты" 
- для микроконтроллера ESP8266 в пункте "Flash Size" обязательно должен быть выбран вариант с выделением места под файловую систему не менее 1.5 Mбайт, 
  например "4MB (FS:2MB, OTA:~1019KB)" для ESP8266  
- для микроконтроллера ESP32 в пункте "Partition Scheme" например вариант "Default 4MB with spiffs (1.2MB APP/1.5MB SPIFFS)"  

Для возможности обновления прошивки "по воздуху" (Over The Air, OTA) - вариант разметки файловой системы должен включать в себя опцию ОТА для ESP8266 или APP для ESP32



<a id="chapter-5"></a>
## Полезная информация
* [Cайт Alex Gyver](http://alexgyver.ru/)
* [Канал Alex Gyver на YouTube](https://www.youtube.com/channel/UCgtAOyEQdAyjvm9ATCi_Aig?sub_confirmation=1)
* [YouTube канал про Arduino](https://www.youtube.com/channel/UC4axiS76D784-ofoTdo5zOA?sub_confirmation=1)
* [Видеоуроки по пайке](https://www.youtube.com/playlist?list=PLOT_HeyBraBuMIwfSYu7kCKXxQGsUKcqR)
* [Видеоуроки по Arduino](http://alexgyver.ru/arduino_lessons/)
