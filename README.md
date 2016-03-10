# Ruby wrapper class for statvfs function 

**if you need to recompile C class run**

```
ruby extconf.rb
```
this will creake make file <br>
**then run make command to compile C classes**
```
make 
```
Init StatVFS class
```
@stat = StatVFS.new # you can pass custom path 
@stat.info # returns Hash of statvfs values
```
