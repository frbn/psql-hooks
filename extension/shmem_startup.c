#include "storage/shmem.h"
#include "storage/ipc.h"



static shmem_startup_hook_type ah_original_shmem_startup_hook = NULL;

void ah_shmem_startup_hook(void);

void ah_shmem_startup_hook(void){

	elog(WARNING,"shmem_startup_hook called");

	if (ah_original_shmem_startup_hook){
		ah_original_shmem_startup_hook();
	}

}
