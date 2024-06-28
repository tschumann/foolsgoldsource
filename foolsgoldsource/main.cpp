//========= Copyright © 2008-2023, Team Sandpit, All rights reserved. ============
//
// Purpose: Empty program to test compilation
//
// $NoKeywords: $
//================================================================================

#include "../foolsgoldsource.h"

#ifdef CLIENT_DLL
cl_enginefunc_t gEngfuncs;
engine_studio_api_t IEngineStudio;
#endif // CLIENT_DLL

enginefuncs_t g_engfuncs;
globalvars_t* gpGlobals;

/**
 * Empty main function - the purpose of this project is to make sure the code compiles.
 */
int main()
{
	return 0;
}
