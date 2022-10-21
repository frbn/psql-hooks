#include "postgres.h"
#include "tcop/utility.h"


static ProcessUtility_hook_type ah_original_ProcessUtility_hook = NULL;


static void ah_process_utility(PlannedStmt *pstmt, const char *queryString,ProcessUtilityContext context,ParamListInfo params,QueryEnvironment *queryEnv,DestReceiver *dest,       char *completionTag){

        elog(WARNING,"ProcessUtility hook called");
    
    
    
}

