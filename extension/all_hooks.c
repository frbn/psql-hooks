#include "postgres.h"
#include "libpq/auth.h"
#include "fmgr.h"
#include "utils/elog.h"

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

//needs_fmgr_hook
#include "needs_fmgr.c"

//fmgr_hook
#include "fmgr.c"

// PLPGSQL
#include "plpgsql.c"

// planner_hook
#include "planner.c"

// ProcessUtility_hook
#include "processutility.c"

// emit_log_hook
#include "emit_log.c"

//check_password_hook
#include "check_password.c"

//ClientAuthentication_hook
#include "client_authentication.c"

//shmem_startup
#include "shmem_startup.c"

PG_MODULE_MAGIC;

/* Function definitions */

void _PG_init(void);
void _PG_fini(void);



// Called upon extension load.
void _PG_init(void)
{
	PLpgSQL_plugin **plugin_ptr;

	elog(WARNING, "all_hooks init");

	elog(WARNING,"hooking: plpgsql");
	/* Link us into the PL/pgSQL executor. */
	plugin_ptr = (PLpgSQL_plugin **)find_rendezvous_variable("PLpgSQL_plugin");
	ah_original_plpgsql_plugin = *plugin_ptr;
	*plugin_ptr = &ah_plugin_funcs;


  // shmem_startup_hook
  elog(WARNING,"hooking: shmem_startup_hook");
  ah_original_shmem_startup_hook = shmem_startup_hook;
  shmem_startup_hook = ah_shmem_startup_hook;

  // planner_hook
  elog(WARNING,"hooking: planner_hook");
  ah_original_planner_hook = planner_hook;
  planner_hook = ah_planner_hook;

  // ProcessUtility_hook
  elog(WARNING,"hooking: ProcessUtility_hook");
  ah_original_ProcessUtility_hook = ProcessUtility_hook;
  ProcessUtility_hook = ah_ProcessUtility_hook;

  // ExecutorStart_hook
  elog(WARNING,"hooking: ExecutorStart_hook");
  ah_original_ExecutorStart_hook = ExecutorStart_hook;
  ExecutorStart_hook = ah_ExecutorStart_hook;

  //ExecutorRun_hook
  elog(WARNING,"hooking: ExecutorRun_hook");
  ah_original_ExecutorRun_hook = ExecutorRun_hook;
  ExecutorRun_hook = ah_ExecutorRun_hook;

  //ExecutorEnd_hook
  elog(WARNING,"hooking: ExecutorEnd_hook");
  ah_original_ExecutorEnd_hook = ExecutorEnd_hook;
  ExecutorEnd_hook = ah_ExecutorEnd_hook;

  // ExecutorCheckPerms_hook
  elog(WARNING,"hooking: ExecutorCheckPerms_hook");
  ah_original_ExecutorCheckPerms_hook = ExecutorCheckPerms_hook;
  ExecutorCheckPerms_hook = ah_ExecutorCheckPerms_hook;

  //ExecutorFinish_hook_type
  elog(WARNING,"hooking: ExecutorFinish_hook");
  ah_original_ExecutorFinish_hook = ExecutorFinish_hook;
  ExecutorFinish_hook = ah_ExecutorFinish_hook;

  // needs_fmgr_hook
  elog(WARNING,"hooking: needs_fmgr_hook");
  ah_original_needs_fmgr_hook = needs_fmgr_hook;
  needs_fmgr_hook = ah_needs_fmgr_hook;

  // fmgr_hook
  elog(WARNING,"hooking: fmgr_hook");
  ah_original_fmgr_hook = fmgr_hook;
  fmgr_hook = ah_fmgr_hook;

  // check_password_hook
  elog(WARNING,"hooking: check_password_hook");
  ah_original_check_password_hook = check_password_hook;
  check_password_hook = ah_check_password_hook;

  // ClientAuthentication_hook
  elog(WARNING,"hooking: ClientAuthentication_hook");
  ah_original_client_authentication_hook = ClientAuthentication_hook;
  ClientAuthentication_hook = ah_ClientAuthentication_hook;

  // emit_log_hook
  elog(WARNING,"hooking: emit_log_hook");
  ah_original_emit_log_hook = emit_log_hook;
  emit_log_hook = ah_emit_log_hook;

}

// Called with extension unload.
void _PG_fini(void)
{
    // Return back the original hook value.

	PLpgSQL_plugin **plugin_ptr;
	plugin_ptr = (PLpgSQL_plugin **)find_rendezvous_variable("PLpgSQL_plugin");
	*plugin_ptr = ah_original_plpgsql_plugin;
	ah_original_plpgsql_plugin = NULL;

    ClientAuthentication_hook = ah_original_client_authentication_hook;
    ExecutorEnd_hook = ah_original_ExecutorEnd_hook;
    planner_hook = ah_original_planner_hook;
    ProcessUtility_hook = ah_original_ProcessUtility_hook;
    ExecutorStart_hook = ah_original_ExecutorStart_hook;
    ExecutorRun_hook = ah_original_ExecutorRun_hook;
    ExecutorEnd_hook = ah_original_ExecutorEnd_hook;
    ExecutorFinish_hook = ah_original_ExecutorFinish_hook;
    ExecutorCheckPerms_hook = ah_original_ExecutorCheckPerms_hook;
    emit_log_hook = ah_original_emit_log_hook;
    fmgr_hook = ah_original_fmgr_hook;
    check_password_hook = ah_original_check_password_hook;
    shmem_startup_hook = ah_original_shmem_startup_hook;
}
