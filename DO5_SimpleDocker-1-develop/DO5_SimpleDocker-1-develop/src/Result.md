# S21_Simple_Docker. Third project

## Part 1

Для начала требуется установить Docker, зарегистрироваться в Dockerhub. Рекомендую устанавливать Docker по ссылке:

[Установка докера](https://21-school-by-students.notion.site/Docker-install-on-school-iMacs-9354ef106a8a40c6b46a69cea0a11bf8 "Мануал от других студентов")

После установки скачиваем образ nginx `docker pull nginx:latest`
![Screenshot1.png](image/Screenshot1.png)

Проверяем наличие докер образа `docker image`. 
Проверяем, что образ запущен `docker ps`
![Screenshot41.png](image/Screenshot41.png)

Просматриваем информацию о контейнере и ищем ip порта, размер и порты
![Screenshot42.png](image/Screenshot42.png)
![Screenshot43.png](image/Screenshot43.png)
![Screenshot44.png](image/Screenshot44.png)

Останавливаем контейнер и проверяем, что он остановился 
![Screenshot4.png](image/Screenshot4.png)

Запускаем контейнер с портами 80 и 443 в контейнере, замапленными на такие же порты на локальной машине, через команду run
![Screenshot5.png](image/Screenshot5.png)

Проверяем, что страница доступна по адресу localhost:80
![Screenshot6.png](image/Screenshot6.png)

Перезапускаем докер контейнер командой `docker restart quizzical_mccarthy`
![Screenshot7.png](image/Screenshot7.png)

## Part 2
Проверяем наличие запущенных контейнеров и конфигурацию файла nginx.conf 
![Screenshot8.png](image/Screenshot8.png)

Добавляем параметры запускка по пути /status
![Screenshot9.png](image/Screenshot9.png)

Скопируем файл командой `docker cp` внутрь контейнера, указав пути до файла и до контейнера
![Screenshot10.png](image/Screenshot10.png)

Проверяем работоспособность по ссылку localhost/status
![Screenshot11.png](img/Screenshot11.png)

Экспортируем контейнер, останавливаем его и удаляем. Контейнер нельзя удалить, который находится в работе.
![Screenshot12.png](img/Screenshot12.png)
![Screenshot13.png](img/Screenshot13.png)

Импортируем контейнер обратно и запускаем его для проверки работоспособности
![Screenshot16.png](img/Screenshot16.png)

## Part 3
Код, позволяющий выводить на странице предоставлен на скрине
![Screenshot17.png](image/Screenshot17.png)

Добавляем параметры в nginx.conf для открытия новой страницы
![Screenshot18.png](image/Screenshot18.png)

Запустить написанный мини сервер через spawn-fcgi на порту 8080
![Screenshot19.png](image/Screenshot19.png)
также скопируем настройки и файл main.c в контейнер
Запуск через spawn-fcgi
![Screenshot20.png](image/Screenshot20.png)
![Screenshot21.png](image/Screenshot21.png)
![Screenshot22.png](image/Screenshot22.png)
![Screenshot23.png](image/Screenshot23.png)

Проверить, что в браузере по localhost:81 отдается написанная вами страничка
![Screenshot24.png](image/Screenshot24.png)

## Part 4

Dockerfile выглядит следующим образом:
![Screenshot25.png](image/Screenshot25.png)

Если Dockerfile прописан корректно, то при запуске сборки, она произойдёт корректно
![Screenshot26.png](image/Screenshot26.png)

Проверим образы и запустим контейнер
![Screenshot27.png](image/Screenshot27.png)
![Screenshot28.png](image/Screenshot28.png)

Собрать написанный докер образ через docker build при этом указав имя и тег

Проверить, что по localhost:80 доступна страничка написанного мини сервера
![Screenshot29.png](image/Screenshot29.png)

Запустить собранный докер образ с маппингом 81 порта на 80 на локальной машине и маппингом папки ./nginx внутрь контейнера по адресу, где лежат конфигурационные файлы nginx'а (см. Часть 2)
![Screenshot32.png](image/Screenshot32.png)

Дописать в ./nginx/nginx.conf проксирование странички /status, по которой надо отдавать статус сервера nginx
![Screenshot30.png](image/Screenshot30.png)

Перезапустить докер образ
![Screenshot33.png](image/Screenshot33.png)

Проверить, что теперь по localhost:80/status отдается страничка со статусом nginx
![Screenshot31.png](image/Screenshot31.png)

## Part 5

Для начала требуется установить dockle
![Screenshot35.png](image/Screenshot35.png)

После зайдём в dockerhub через терминал, сохраним наш образ и проверим его при помощи dockle
![Screenshot36.png](image/Screenshot36.png)

Исправим ошибки в Dockerfile и проверим повторно сборку dockle
![Screenshot37.png](image/Screenshot37.png)
![Screenshot38.png](image/Screenshot38.png)

Повторно правим имеющиеся ошибки и проверяем сборку повторно
![Screenshot39.png](image/Screenshot39.png)
![Screenshot40.png](image/Screenshot40.png)

## Part 6

Для сборки контейнера через docker-compose.yml требуется написать файл с таким же названием и указать откуда брать Dockerfile и куда производить сборку. В нашем случае мы берём его с пятой части и собираем там, где находится файл с  инструкцией.

![Screenshot45.png](image/Screenshot45.png)

Изменим run.sh
![Screenshot46.png](image/Screenshot46.png)

Проверим отсутсвие рабочих контейнеров
![Screenshot47.png](image/Screenshot47.png)

Для корректной сборки установим командой `brew install docker-compose`
![Screenshot48.png](image/Screenshot48.png)

Произведём сборку и поднимем контейнеры командами 
`docker-compose build`
`docker-compose up`
![Screenshot49.png](image/Screenshot49.png)
![Screenshot50.png](image/Screenshot50.png)

Убедимся, что сервер и прокси собрались и запустились
![Screenshot51.png](image/Screenshot51.png)

Проверим работу в браузере на локальном сервере
![Screenshot52.png](image/Screenshot52.png)

Также проверим запущенные контейнеры
![Screenshot53.png](image/Screenshot53.png)
