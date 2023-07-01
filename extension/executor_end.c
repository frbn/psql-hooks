#include <postgres.h>

#include <access/heapam.h>
#include <catalog/namespace.h>
#include <miscadmin.h>
#include <executor/executor.h>
#include <optimizer/planner.h>
#include <storage/bufmgr.h>
#include <utils/builtins.h>
#include <utils/guc.h>
#include <optimizer/optimizer.h>
#include <lib/ilist.h>

static ExecutorEnd_hook_type ah_original_ExecutorEnd_hook = NULL;

void ah_ExecutorEnd_hook(QueryDesc *q);

void ah_ExecutorEnd_hook(QueryDesc *q)
{
    elog(DEBUG1,"ExecutorEnd hook called");
  if (ah_original_ExecutorEnd_hook)
    ah_original_ExecutorEnd_hook(q);
  else
    standard_ExecutorEnd(q);
}
