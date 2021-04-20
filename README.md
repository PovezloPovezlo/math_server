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
В процессе...