### ruby wrapper class for statvfs function

See http://man7.org/linux/man-pages/man3/statvfs.3.html

Run the following command to generate make file:

```
ruby extconf.rb
```

then run `make` command to compile the source code


Now you can use StatVFS class
```
@stat = StatVFS.new # you can pass custom path 
@stat.info # returns Hash of statvfs values
```
