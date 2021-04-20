# math_server

## Что нужно почитать перед разработкой?

### Conventional commits
[Правила оформления коммитов](https://gist.github.com/qoomon/5dfcdf8eec66a051ecd85625518cfd13)

### Google test
[Написание тестов](https://gist.github.com/qoomon/5dfcdf8eec66a051ecd85625518cfd13)

## Установка

Перед установкой убедитесь, что у вас стоит git, [cmake](https://cmake.org) и [nodejs](https://nodejs.org/en/) (нужен для проверки текстов коммитов)

Необходимо поставить `git-conventional-commits`:
```shell
npm install --global git-conventional-commits
```

Далее клонируем сам репозиторий
```shell
git clone git@github.com:PovezloPovezlo/math_server.git
```

Появится папка `math_server`. 
Заходим в нее и пишем 
```shell
git config core.hooksPath '.git-hooks'
```

Готово

## Как делать правки?
[как делать коммиты](https://www.youtube.com/watch?v=DMQA0BhVDZk)

[как делать пуш](https://www.youtube.com/watch?v=6N6JFynR0gM) (не забудьте учитывать то, что пушить надо в ветку своей команды)

## Процесс разработки 
После того, как реализовали свою часть, пушите в ветку своей команды.

Главный по команде должен будет сделать код-ревью, дабы отсеить большниство ошибок и не тратить лишнее время архитектора

Когда пройдено первое код-ревью, то вызываете архитектора, и он проводит код-ревью. 

Если второе код-ревью пройдено, то ваш код попадает в `master` ветку и можно сказать код готов. 