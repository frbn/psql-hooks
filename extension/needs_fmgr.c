#include "fmgr.h"


static needs_fmgr_hook_type ah_original_needs_fmgr_hook = NULL;


bool ah_needs_fmgr_hook (Oid fn_oid);

bool ah_needs_fmgr_hook (Oid fn_oid){

  elog(DEBUG1, "needs_fmgr_hook_type called");
  return true;
  // if (ah_original_needs_fmgr_hook){
  //   return ah_original_needs_fmgr_hook(fn_oid);
  // }else{
  //   return needs_fmgr_hook(fn_oid);
  // }
}
