#include "fmgr.h"


static needs_fmgr_hook_type ah_original_needs_fmgr_hook = NULL;


bool ah_needs_fmgr_hook (Oid fn_oid);

bool ah_needs_fmgr_hook (Oid fn_oid){

  bool _result;

  elog(DEBUG1, "needs_fmgr_hook_type called");

  if (ah_original_needs_fmgr_hook){
    _result = ah_original_needs_fmgr_hook(fn_oid);
  }else{
    _result = needs_fmgr_hook(fn_oid);
  }
  return _result;
}
