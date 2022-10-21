#include "postgres.h"
#include "libpq/auth.h"
#include "fmgr.h"
#include "utils/elog.h"

//ClientAuthentication_hook
#include "auth.c"

//ExecutorEnd_hook
#include "executor_end.c"

PG_MODULE_MAGIC;

/* Function definitions */

void _PG_init(void);
void _PG_fini(void);



// Called upon extension load.
void _PG_init(void)
{
    //--------------------------
    // ClientAuthentication_hook
    
    // Save the original hook value.
    ah_original_client_auth_hook = ClientAuthentication_hook;
    // Register our handler.
    ClientAuthentication_hook = ah_auth_delay_checks;
    //--------------------------
    
    //--------------------------
    // ExecutorEnd_hook
    ah_prev_ExecutorEnd = ExecutorEnd_hook;
    ExecutorEnd_hook = ah_ExecutorEnd;
    //--------------------------
    
    
}

// Called with extension unload.
void _PG_fini(void)
{

    //--------------------------
    // ClientAuthentication_hook

    // Return back the original hook value.
    ClientAuthentication_hook = ah_original_client_auth_hook;
    //--------------------------
    
    //--------------------------
    // ExecutorEnd_hook
    ExecutorEnd_hook = ah_prev_ExecutorEnd;
    
    //--------------------------



}
