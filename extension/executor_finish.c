#include "executor/executor.h"

static ExecutorFinish_hook_type ah_original_ExecutorFinish_hook = NULL;

void ah_ExecutorFinish_hook(QueryDesc *queryDesc);


void ah_ExecutorFinish_hook(QueryDesc *queryDesc){

  elog(DEBUG1, "ExecutorFinish_hook called");
    if (ah_original_ExecutorFinish_hook){
    ah_original_ExecutorFinish_hook(queryDesc);
    }else{
      standard_ExecutorFinish(queryDesc);
  }
}
