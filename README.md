# math_server

## Что нужно почитать перед разработкой?

### Google test
[Написание тестов](https://gist.github.com/qoomon/5dfcdf8eec66a051ecd85625518cfd13)

### Структуры данных
[Используемые в работе структуры данных](https://github.com/PovezloPovezlo/math_server/tree/master/src/base)

## Установка

Перед установкой убедитесь, что у вас стоит git, 
[cmake](https://cmake.org), 
jsoncpp (если у вас стоит Python или Visual Studio, он должен стоять),
uuid

Далее клонируем сам репозиторий
```shell script
git clone git@github.com:PovezloPovezlo/math_server.git
```

Появится папка `math_server`. 

Заходим в `math_server/lib`

Там пишем 
```shell script
git clone https://github.com/an-tao/drogon.git
```

Заходим в папку `drogon`
И в ней прописываем 
```shell script
git submodule update --init --recursive
```

Возвращаемся в `math_server`

Готово, можно приступать к работе 

## Как делать правки?
[как делать коммиты](https://www.youtube.com/watch?v=DMQA0BhVDZk)

[как делать пуш](https://www.youtube.com/watch?v=6N6JFynR0gM) (не забудьте учитывать то, что пушить надо в ветку своей команды)

## Процесс разработки 
После того, как реализовали свою часть, пушите в ветку своей команды.

Главный по команде должен будет сделать код-ревью, дабы отсеить большинство ошибок и не тратить лишнее время архитектора

Когда пройдено первое код-ревью, то вызываете архитектора, и он проводит код-ревью. 

Если второе код-ревью пройдено, то ваш код попадает в `master` ветку и можно сказать код готов. 