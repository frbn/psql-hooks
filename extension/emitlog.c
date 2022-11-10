#include "utils/elog.h"

emit_log_hook_type ah_original_emit_log_hook = NULL;
static void ah_emit_log_hook(ErrorData* );



static void ah_emit_log_hook(ErrorData * eData){

//TODO : explain why it doesn't work
	elog(WARNING, "emit_log_hook called");
	if (ah_original_emit_log_hook){
		ah_original_emit_log_hook(eData);
	}


}
