#include <stdio.h>
#include <stdlib.h>

static void  unload( void)
{
   fprintf( stderr, "%s\n", __PRETTY_FUNCTION__);
}


__attribute__((constructor))
static void  load( void)
{
   fprintf( stderr, "%s\n", __PRETTY_FUNCTION__);
   atexit( unload);
}

