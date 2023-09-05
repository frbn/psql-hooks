#include "utils/elog.h"

static emit_log_hook_type ah_original_emit_log_hook = NULL;

static void ah_emit_log_hook(ErrorData* );

void ah_emit_log_hook(ErrorData * eData){

  static bool in_hook = false;

	if (ah_original_emit_log_hook){
		ah_original_emit_log_hook(eData);
	}

	// elog(WARNING, "ah_emit_log_hook called");

	if (! in_hook){
		in_hook = true;
		// elog(WARNING, "ah_emit_log_hook called");
	  in_hook = false;
	}


}
