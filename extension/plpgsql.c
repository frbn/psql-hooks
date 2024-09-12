#include "plpgsql.h"

static PLpgSQL_plugin  *ah_original_plpgsql_plugin = NULL;

static void ah_func_init_hook(PLpgSQL_execstate *estate, PLpgSQL_function *func);
static void ah_func_beg_hook(PLpgSQL_execstate *estate, PLpgSQL_function *func);
static void ah_func_end_hook(PLpgSQL_execstate *estate, PLpgSQL_function *func);

static void ah_stmt_beg_hook(PLpgSQL_execstate * estate, PLpgSQL_stmt* stmt) ;
static void ah_stmt_end_hook(PLpgSQL_execstate * estate, PLpgSQL_stmt* stmt) ;

static PLpgSQL_plugin	ah_plugin_funcs = {
	ah_func_init_hook,
	ah_func_beg_hook,
	ah_func_end_hook,
	ah_stmt_beg_hook,
	ah_stmt_end_hook,
	NULL,
	NULL
};


// ---------------------------------------------------

static void ah_stmt_beg_hook(PLpgSQL_execstate * estate, PLpgSQL_stmt* stmt)
{
  elog(DEBUG1,"stmt_beg hook called");
}

static void ah_stmt_end_hook(PLpgSQL_execstate * estate, PLpgSQL_stmt* stmt)
{
  elog(DEBUG1,"stmt_end hook called");
}

static void ah_func_init_hook(PLpgSQL_execstate *estate, PLpgSQL_function *func)

{
  elog(DEBUG1,"func_init hook called");
}
static void ah_func_beg_hook(PLpgSQL_execstate *estate, PLpgSQL_function *func)
{
  elog(DEBUG1,"func_beg hook called");
}
static void ah_func_end_hook(PLpgSQL_execstate *estate, PLpgSQL_function *func)
{
  elog(DEBUG1,"func_end hook called");

}
