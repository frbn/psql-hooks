#include "executor/executor.h"

static ExecutorCheckPerms_hook_type ah_original_ExecutorCheckPerms_hook = NULL;
bool ah_ExecutorCheckPerms_hook (List* , bool );

bool ah_ExecutorCheckPerms_hook (List* tableList, bool abort){
     
	elog(WARNING, "ExecutorCheckPerms_hook called");
	
	return true;
}
