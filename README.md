# Система спасения для ракеты

> Letovo STEM, 9th grade, Challenge #2 

## Принцип работы системы

Стартовая высота равна 0. Система сохраняет максимальную относительную высоту, и если текущая высота меньше максимальной хотя бы на 1 метр (константа EPS), сервомотор совершает поворот и выбрасывает парашют.

## Установка

> Необходима среда разработки VS Code с установленным расширением Platformio и созданным проектом для Arduino Uno.

* В Platformio перейти в раздел Libraries и установить модуль Servo
* Установить модуль для работы с датчиками:
```bash
cd lib
git clone https://github.com/voltbro/VoltBroSensors.git
```
* Скачать данный код:
```bash
cd src
git clone https://github.com/letovo-stem-2026/rescue-system.git
```

## Использование

* Подключить барометр к I2C портам (SDA, SCL), питанию и земле. Остальные порты не подключать.
* Подключить сервомотор к digital порту 9 (константа SERVOPIN), питанию (обязательно 5V, на troyka shield это digital порты 8-13 с обозначением V2) и земле.
* Подключить Arduino к компьютеру, загрузить код. Далее можно подключить внешний аккумулятор и тестировать работу. По кнопке Reset на Arduino код перезапускается (возвращает сервомотор в исходное положение и сбрасывает высоту).