project( ld-preload C)

add_library( ld-preload SHARED
src/ld-preload.c
)

add_executable( main
src/main.c
)
