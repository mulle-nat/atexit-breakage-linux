# Shows a harmless but puzzling effect involving `atexit` on linux

Here the `atexit` callback is invoked multiple times. This is no problem, since 
the callback is shared among multiple processes and so multiple callbacks ensue.


## Build

Build with [mulle-make](//github.com/mulle-sde/mulle-make) or alternatively :

```
(
   mkdir build &&
   cd build &&
   cmake .. &&
   make
)
```

## Run

Use `ldd` to trigger the misbehaviour:

```
LD_PRELOAD="${PWD}/build/libld-preload.so" ldd ./build/main
```

## Output

```
load
unload
unload
unload
   linux-vdso.so.1 (0x00007ffd2b2bd000)
   /home/src/srcO/mulle-core/mulle-testallocator/research/ld-preload/build/libld-preload.so (0x00007f83853c1000)
   libc.so.6 => /lib/x86_64-linux-gnu/libc.so.6 (0x00007f838518c000)
   /lib64/ld-linux-x86-64.so.2 (0x00007f83853cd000)
unload
unload
```

---

## Other fun stuff to try

### gdb

Run program with gdb

```
LD_PRELOAD="${PWD}/build/libld-preload.so" gdb build/main 
```

will output 

```
load
load
unload
```

### lldb

Run program with lldb

```
LD_PRELOAD="${PWD}/build/libld-preload.so" lldb build/main 
```

will output 

```
load
load
load
unload
load
unload
```


