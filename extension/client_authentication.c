
static ClientAuthentication_hook_type ah_original_client_authentication_hook = NULL;

static void ah_ClientAuthentication_hook(Port * port, int status);


void ah_ClientAuthentication_hook(Port * port, int status){

   // If any other extension registered its own hook handler,
    // call it before performing our own logic.
    if (ah_original_client_authentication_hook)
        ah_original_client_authentication_hook(port, status);

    // If authentication failed, we wait for one second before returning
    // control to the caller.
    if (status != STATUS_OK)
    {
      elog(WARNING,"ah_ClientAuthentication_hook status KO");
    }else{
      elog(WARNING,"ah_ClientAuthentication_hook called OK");
    }
}
