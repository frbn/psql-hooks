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

static ExecutorEnd_hook_type ah_prev_ExecutorEnd = NULL;

static void
ah_ExecutorEnd(QueryDesc *q)
{
    elog(WARNING,"ExecutorEnd hook called");
  if (ah_prev_ExecutorEnd)
    ah_prev_ExecutorEnd(q);
  else
    standard_ExecutorEnd(q);
}


