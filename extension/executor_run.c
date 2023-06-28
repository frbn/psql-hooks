/* ExecutorRun_hook (QueryDesc *queryDesc,
									   ScanDirection direction,
									   uint64 count,
									   bool execute_once);

*/

#include "executor/executor.h"

static ExecutorRun_hook_type ah_original_ExecutorRun_hook = NULL;

void ah_ExecutorRun_hook(QueryDesc *queryDesc,
									   ScanDirection direction,
									   uint64 count,
									   bool execute_once);

void ah_ExecutorRun_hook( QueryDesc *queryDesc, ScanDirection direction,
  uint64 count, bool execute_once){

    elog(DEBUG1, "ExecutorRun_hook called");

  if (ah_original_ExecutorRun_hook){
    ah_original_ExecutorRun_hook(queryDesc, direction, count, execute_once);

  }else{
      standard_ExecutorRun(queryDesc, direction, count, execute_once);
  }
}
