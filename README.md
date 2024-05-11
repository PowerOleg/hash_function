!сработало для отображения на gitHub: взял notepad++ открыл main.cpp и нажал convert to utf-8 



git config --local core.pager "iconv.exe -f cp1251 -t utf-8 | less"

$ git config --local i18n.commitEncoding utf8

$ git config --local i18n.logoutputencoding cp1251

сработало чтобы посмотреть разницу в gitBash:
чтобы постмореть разницу команда: git log -p -2




в VS для настроек компилятора пока только всё портит надо разбираться
#if(MSVC)
addcompileoptions("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
addcompileoptions("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")
#endif()
```

команда пока ненужна ls --show-control-chars
