
static ClientAuthentication_hook_type ah_original_client_authentication_hook = NULL;

static void ah_ClientAuthentication_hook(Port * port, int status);


void ah_ClientAuthentication_hook(Port * port, int status){

  elog(WARNING,"ah_ClientAuthentication_hook called");

}
