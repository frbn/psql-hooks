#include "optimizer/planner.h"


static planner_hook_type ah_original_planner_hook  = NULL;


static PlannedStmt *
ah_planner_hook(Query *parse, const char *query_st, int cursorOptions, ParamListInfo boundp)
{
  PlannedStmt *result;

  elog(DEBUG1, "planner hook called");

  if (ah_original_planner_hook){
		result = ah_original_planner_hook(parse,query_st,cursorOptions, boundp);
	}
	else
	{
		result = standard_planner(parse, query_st, cursorOptions, boundp);
	}
	return result;


}
