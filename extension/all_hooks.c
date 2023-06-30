#include "postgres.h"
#include "libpq/auth.h"
#include "fmgr.h"
#include "utils/elog.h"

//ClientAuthentication_hook
#include "auth.c"


// Executor

// executeCheckPerms_hook
#include "executorcheckperms.c"

//ExecutorStart_hook
#include "executor_start.c"

//ExecutorRun_hook
#include "executor_run.c"

//ExecutorFinish_hook
#include "executor_finish.c"

//ExecutorEnd_hook
#include "executor_end.c"


// planner_hook
#include "planner.c"

// ProcessUtility_hook
#include "processutility.c"


// emit_log_hook
#include "emitlog.c"



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
	elog(WARNING,"hooking: ClientAuthentication_hook");
    ah_original_client_auth_hook = ClientAuthentication_hook;

    // Register our handler.
    ClientAuthentication_hook = ah_auth_delay_checks;
    //--------------------------

    //--------------------------
    // ExecutorEnd_hook
	elog(WARNING,"hooking: emit_log_hook");
    ah_original_ExecutorEnd = ExecutorEnd_hook;
    ExecutorEnd_hook = ah_ExecutorEnd;
    //--------------------------

    //--------------------------
    // planner_hook
    if (planner_hook != ah_planner_hook){
		elog(WARNING,"hooking: planner_hook");
        ah_original_planner_hook = planner_hook;
        planner_hook = ah_planner_hook;
    }
    //--------------------------
    // ProcessUtility_hook
    if (ProcessUtility_hook != ah_process_utility){
		elog(WARNING,"hooking: ProcessUtility_hook");
        ah_original_ProcessUtility_hook = ProcessUtility_hook;
        ProcessUtility_hook = ah_process_utility;
    }


    //--------------------------
    // ExecutorStart_hook
    if (ExecutorStart_hook != ah_ExecutorStart_hook){
  		elog(WARNING,"hooking: ExecutorStart_hook");
  		ah_original_ExecutorStart_hook = ExecutorStart_hook;
  		ExecutorStart_hook = ah_ExecutorStart_hook;
  	}

    //ExecutorRun_hook
    if (ExecutorRun_hook != ah_ExecutorRun_hook){
      elog(WARNING,"hooking: ExecutorRun_hook");
      ah_original_ExecutorRun_hook = ExecutorRun_hook;
      ExecutorRun_hook = ah_ExecutorRun_hook;
    }

	// ExecutorCheckPerms_hook
	if (ExecutorCheckPerms_hook != ah_ExecutorCheckPerms_hook){
		elog(WARNING,"hooking: ExecutorCheckPerms_hook");
		ah_original_ExecutorCheckPerms_hook = ExecutorCheckPerms_hook;
		ExecutorCheckPerms_hook = ah_ExecutorCheckPerms_hook;
	}

  //ExecutorFinish_hook_type
  if (ExecutorFinish_hook != ah_ExecutorFinish_hook){
    elog(WARNING,"hooking: ExecutorFinish_hook");
    ah_original_ExecutorFinish_hook = ExecutorFinish_hook;
    ExecutorFinish_hook = ah_ExecutorFinish_hook;
  }
    //--------------------------
	// emit_log_hook
	if (emit_log_hook != ah_original_emit_log_hook){
		elog(WARNING,"hooking: hooking emit_log");
		ah_original_emit_log_hook = emit_log_hook;
		emit_log_hook = ah_emit_log_hook;
	}
    //--------------------------

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
	// emit_log_hook
	emit_log_hook = ah_original_emit_log_hook;

    //--------------------------
}
