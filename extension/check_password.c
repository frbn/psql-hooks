#include "commands/user.h"


static check_password_hook_type ah_original_check_password_hook = NULL;

void ah_check_password_hook(const char *username, const char *shadow_pass, PasswordType password_type, Datum validuntil_time, bool validuntil_null);


void ah_check_password_hook(const char *username, const char *shadow_pass, PasswordType password_type, Datum validuntil_time, bool validuntil_null){

  elog(WARNING,"check_password_hook called");

	if (ah_original_check_password_hook){
		ah_original_check_password_hook(username, shadow_pass, password_type, validuntil_time, validuntil_null);
	}

}
