#include "executor/executor.h"

static ExecutorStart_hook_type ah_original_ExecutorStart_hook = NULL;

void ah_ExecutorStart_hook (QueryDesc *queryDesc, int eflags);

void ah_ExecutorStart_hook (QueryDesc *queryDesc, int eflags){

	elog(DEBUG1, "ExecutorStart_hook called");

	if (ah_original_ExecutorStart_hook){
		ah_original_ExecutorStart_hook(queryDesc, eflags);
	}else{
		standard_ExecutorStart(queryDesc, eflags);
	}
}
