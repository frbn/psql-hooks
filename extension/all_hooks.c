#include "postgres.h"
#include "libpq/auth.h"
#include "fmgr.h"
#include "utils/elog.h"

//ClientAuthentication_hook
#include "auth.c"

//ExecutorEnd_hook
#include "executor_end.c"

// planner_hook
#include "planner.c"

// ProcessUtility_hook
#include "processutility.c"

// executeCheckPerms_hook
#include "executorcheckperms.c"

PG_MODULE_MAGIC;

/* Function definitions */

void _PG_init(void);
void _PG_fini(void);



// Called upon extension load.
void _PG_init(void)
{
    elog(WARNING, "all_hooks init");
    //--------------------------
    // ClientAuthentication_hook
    
    // Save the original hook value.
    ah_original_client_auth_hook = ClientAuthentication_hook;
    // Register our handler.
    ClientAuthentication_hook = ah_auth_delay_checks;
    //--------------------------
    
    //--------------------------
    // ExecutorEnd_hook
    ah_original_ExecutorEnd = ExecutorEnd_hook;
    ExecutorEnd_hook = ah_ExecutorEnd;
    //--------------------------

    //--------------------------
    // planner_hook
    if (planner_hook != ah_planner_hook){
        ah_original_planner_hook = planner_hook;
        planner_hook = ah_planner_hook;
    }
    //--------------------------    
    // ProcessUtility_hook
    if (ProcessUtility_hook != ah_process_utility){        
        ah_original_ProcessUtility_hook = ProcessUtility_hook;
        ProcessUtility_hook = ah_process_utility;
    }
    
    
    //--------------------------    
	// ExecutorCheckPerms_hook
	if (ExecutorCheckPerms_hook != ah_ExecutorCheckPerms_hook){
		ah_original_ExecutorCheckPerms_hook = ExecutorCheckPerms_hook;
		ExecutorCheckPerms_hook = ah_ExecutorCheckPerms_hook;
	}
    //--------------------------    
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
    ExecutorEnd_hook = ah_original_ExecutorEnd;
    
    //--------------------------

    //--------------------------
    // planner_hook
    planner_hook = ah_original_planner_hook;
    
    //--------------------------
    // ProcessUtility_hook
    ProcessUtility_hook = ah_original_ProcessUtility_hook;
    
    //--------------------------
	// ExecutoCheckPerms_hook
	ExecutorCheckPerms_hook = ah_original_ExecutorCheckPerms_hook;
    //--------------------------


}
