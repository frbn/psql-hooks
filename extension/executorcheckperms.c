#include "executor/executor.h"

static ExecutorCheckPerms_hook_type ah_original_ExecutorCheckPerms_hook = NULL;
static bool ah_ExecutorCheckPerms_hook (List*, bool );

static bool ah_ExecutorCheckPerms_hook (List* tableList, bool abort){

	elog(DEBUG1, "ExecutorCheckPerms_hook called");

	return true;
}
