
#include "fmgr.h"

static fmgr_hook_type ah_original_fmgr_hook = NULL;

void ah_fmgr_hook(FmgrHookEventType event, FmgrInfo * flinfo, Datum *arg) ;

void ah_fmgr_hook(FmgrHookEventType event, FmgrInfo * flinfo, Datum *arg){

  elog(DEBUG1,"fmgr hook called");
  if (ah_original_fmgr_hook)
    ah_original_fmgr_hook(event,flinfo,arg);
}
