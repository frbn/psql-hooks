// ClientAuthentication_hook
#include "postgres.h"
#include "libpq/auth.h"
#include "fmgr.h"
#include "utils/elog.h"

// We store previously assigned hook pointer in a global variable.
static ClientAuthentication_hook_type original_client_auth_hook=NULL;

static void auth_delay_checks(Port *port, int status);

// Our hook implementation.
static void auth_delay_checks(Port *port, int status)
{
    // If any other extension registered its own hook handler,
    // call it before performing our own logic.
    if (original_client_auth_hook)
        original_client_auth_hook(port, status);

    // If authentication failed, we wait for one second before returning
    // control to the caller.
	elog(WARNING, "auth hook called");
	if (status != STATUS_OK)
    {
        pg_usleep(1000000L);
    }
}

