#include "postgres.h"
#include "tcop/utility.h"


static ProcessUtility_hook_type ah_original_ProcessUtility_hook = NULL;

void ah_ProcessUtility_hook(PlannedStmt *pstmt, const char *queryString,bool readOnlyTree, ProcessUtilityContext context,ParamListInfo params,QueryEnvironment *queryEnv,DestReceiver *dest,QueryCompletion *completionTag);

void ah_ProcessUtility_hook(PlannedStmt *pstmt, const char *queryString,bool readOnlyTree, ProcessUtilityContext context,ParamListInfo params,QueryEnvironment *queryEnv,DestReceiver *dest,QueryCompletion *completionTag){

        elog(DEBUG1,"ProcessUtility hook called");
		if (ah_original_ProcessUtility_hook){
			ah_original_ProcessUtility_hook(pstmt, queryString,readOnlyTree,context,params,queryEnv,dest, completionTag);
    }else{
			standard_ProcessUtility(pstmt,queryString, readOnlyTree, context, params, queryEnv, dest, completionTag);
		}

}
