//========= Copyright © 2008-2023, Team Sandpit, All rights reserved. ============
//
// Purpose: Fake GoldSource engine implementation
//
// $NoKeywords: $
//================================================================================

#include "foolsgoldsource.h"

extern globalvars_t* gpGlobals;

#ifdef CLIENT_DLL
extern engine_studio_api_t IEngineStudio;
#endif // CLIENT_DLL

namespace foolsgoldsource
{
	Engine gEngine;

	Engine::Engine() :
		engineType( EngineType::ENGINE_25ANNIVERSARY ),
		bIsDedicatedServer( false ),
		bIsCareerMatch( false ),
		iCallsToClientCommand( 0 ),
#ifdef CLIENT_DLL
		triCullStyle( TRI_FRONT ),
#endif // CLIENT_DLL
		bIsFogOn( false ),
		iRenderer( RENDERER_SOFTWARE )
	{
		memset(&this->engineFunctions, 0, sizeof(enginefuncs_t));
		memset(&this->dllFunctions, 0, sizeof(DLL_FUNCTIONS));
		memset(&this->newDllFunctions, 0, sizeof(NEW_DLL_FUNCTIONS));

		// set up all the engine functions so they can be used
		this->engineFunctions.pfnPrecacheModel = pfnPrecacheModel;
		this->engineFunctions.pfnPrecacheSound = pfnPrecacheSound;
		this->engineFunctions.pfnSetModel = pfnSetModel;
		this->engineFunctions.pfnModelIndex = pfnModelIndex;
		this->engineFunctions.pfnModelFrames = pfnModelFrames;
		this->engineFunctions.pfnSetSize = pfnSetSize;
		this->engineFunctions.pfnChangeLevel = pfnChangeLevel;
		this->engineFunctions.pfnGetSpawnParms = pfnGetSpawnParms;
		this->engineFunctions.pfnSaveSpawnParms = pfnSaveSpawnParms;
		this->engineFunctions.pfnVecToYaw = pfnVecToYaw;
		this->engineFunctions.pfnVecToAngles = pfnVecToAngles;
		this->engineFunctions.pfnMoveToOrigin = pfnMoveToOrigin;
		this->engineFunctions.pfnChangeYaw = pfnChangeYaw;
		this->engineFunctions.pfnChangePitch = pfnChangePitch;
		this->engineFunctions.pfnFindEntityByString = pfnFindEntityByString;
		this->engineFunctions.pfnGetEntityIllum = pfnGetEntityIllum;
		this->engineFunctions.pfnFindEntityInSphere = pfnFindEntityInSphere;
		this->engineFunctions.pfnFindClientInPVS = pfnFindClientInPVS;
		this->engineFunctions.pfnEntitiesInPVS = pfnEntitiesInPVS;
		this->engineFunctions.pfnCreateEntity = pfnCreateEntity;
		this->engineFunctions.pfnSetOrigin = pfnSetOrigin;
		this->engineFunctions.pfnEmitSound = pfnEmitSound;
		this->engineFunctions.pfnEmitAmbientSound = pfnEmitAmbientSound;
		this->engineFunctions.pfnTraceSphere = pfnTraceSphere;
		this->engineFunctions.pfnServerCommand = pfnServerCommand;
		this->engineFunctions.pfnServerExecute = pfnServerExecute;
		this->engineFunctions.pfnClientCommand = pfnClientCommand;
		this->engineFunctions.pfnParticleEffect = pfnParticleEffect;
		this->engineFunctions.pfnLightStyle = pfnLightStyle;
		this->engineFunctions.pfnRandomLong = pfnRandomLong;
		this->engineFunctions.pfnAlertMessage = pfnAlertMessage;
		this->engineFunctions.pfnPvAllocEntPrivateData = pfnPvAllocEntPrivateData;
		this->engineFunctions.pfnAllocString = pfnAllocString;
		this->engineFunctions.pfnPEntityOfEntOffset = pfnPEntityOfEntOffset;
		this->engineFunctions.pfnEntOffsetOfPEntity = pfnEntOffsetOfPEntity;
		this->engineFunctions.pfnPEntityOfEntIndex = pfnPEntityOfEntIndex;
		this->engineFunctions.pfnFindEntityByVars = pfnFindEntityByVars;
		this->engineFunctions.pfnGetModelPtr = pfnGetModelPtr;
		this->engineFunctions.pfnNameForFunction = pfnNameForFunction;
		this->engineFunctions.pfnServerPrint = pfnServerPrint;
		this->engineFunctions.pfnGetGameDir = pfnGetGameDir;
		this->engineFunctions.pfnIsDedicatedServer = pfnIsDedicatedServer;
		this->engineFunctions.pfnPrecacheEvent = pfnPrecacheEvent;
		this->engineFunctions.pfnPlaybackEvent = pfnPlaybackEvent;
		this->engineFunctions.pfnIsCareerMatch = pfnIsCareerMatch;
		this->engineFunctions.pfnQueryClientCvarValue = pfnQueryClientCvarValue;
		this->engineFunctions.pfnQueryClientCvarValue2 = pfnQueryClientCvarValue2;
		this->engineFunctions.pfnCheckParm = pfnCheckParm;
		this->engineFunctions.pfnPEntityOfEntIndexAllEntities = pfnPEntityOfEntIndexAllEntities;

		this->dllFunctions.pfnClientCommand = ClientCommand;
		this->dllFunctions.pfnServerActivate = ServerActivate;

#ifdef CLIENT_DLL
		this->clientEngineFunctions.pTriAPI = &triangleApi;

		this->clientEngineFunctions.pfnRegisterVariable = pfnRegisterVariable;
		this->clientEngineFunctions.pfnAddCommand = pfnAddCommand;
		this->clientEngineFunctions.pfnHookUserMsg = pfnHookUserMsg;
		this->clientEngineFunctions.Con_DPrintf = Con_DPrintf;
		this->clientEngineFunctions.pfnGetGameDirectory = pfnGetGameDirectory;
		this->clientEngineFunctions.pfnGetCvarPointer = pfnGetCvarPointer;
		this->clientEngineFunctions.pfnGetLevelName = pfnGetLevelName;
		this->clientEngineFunctions.VGui_GetPanel = VGui_GetPanel;
		this->clientEngineFunctions.pTriAPI->CullFace = CullFace;
		this->clientEngineFunctions.pTriAPI->Fog = Fog;
		this->clientEngineFunctions.pTriAPI->FogParams = FogParams;

		this->engineStudioFunctions.GetCvar = pfnGetCvarPointer;
		this->engineStudioFunctions.GetChromeSprite = GetChromeSprite;
		this->engineStudioFunctions.GetModelCounters = GetModelCounters;
		this->engineStudioFunctions.StudioGetBoneTransform = StudioGetBoneTransform;
		this->engineStudioFunctions.StudioGetLightTransform = StudioGetLightTransform;
		this->engineStudioFunctions.StudioGetAliasTransform = StudioGetAliasTransform;
		this->engineStudioFunctions.StudioGetRotationMatrix = StudioGetRotationMatrix;
		this->engineStudioFunctions.IsHardware = IsHardware;
#endif // CLIENT_DLL

		// install the engine functions and global variables
		::g_engfuncs = this->engineFunctions;
		::gpGlobals = &this->globalVariables;

#ifdef CLIENT_DLL
		::gEngfuncs = this->clientEngineFunctions;
		::IEngineStudio = this->engineStudioFunctions;
#endif // CLIENT_DLL

		this->globalVariables.pStringBase = new char[Engine::iStringTableSize];
	}

	Engine::~Engine() noexcept
	{
		if( this->globalVariables.pStringBase )
		{
			delete[] this->globalVariables.pStringBase;
			this->globalVariables.pStringBase = nullptr;
		}

		for( size_t i = 0; i < this->clientCvars.size(); i++ )
		{
			shared_ptr<cvar_t> cvar = this->clientCvars[i];

			delete[] cvar->name;
		}
	}

	/// <summary>
	/// Clear everything back to a known good state. Ideally we'd just initialise a new Engine class per-test but the way this has
	/// all been architected is to have a global engine that a bunch of functions can call back to.
	/// </summary>
	void Engine::Initialise()
	{
		this->edicts.clear();
		this->models.clear();
		this->sounds.clear();
		this->events.clear();

		this->executedClientCommands.clear();
		this->executedServerCommands.clear();

		for (size_t i = 0; i < this->clientCvars.size(); i++)
		{
			shared_ptr<cvar_t> cvar = this->clientCvars[i];

			delete[] cvar->name;
		}

		this->clientCvars.clear();
		this->clientCommands.clear();
		this->userMessages.clear();

		this->iCallsToClientCommand = 0;

		this->globalVariables.maxClients = 32;

		memset(const_cast<char*>(this->globalVariables.pStringBase), 0, Engine::iStringTableSize);
		// start allocating at offset 1 so that checks against string_t with value 0 work
		// TODO: is this how the engine works?
		this->iStringTableOffset = 1;

		this->SetGameDirectory("valve");

		this->iMaxEdicts = 1024;

		// TODO: is edict_t* 0 is worldspawn?
		for (int i = 0; i <= this->globalVariables.maxClients; i++)
		{
			// TODO: player spawning should happen later - and call one of the server-side callbacks?
			shared_ptr<edict_t> edict = std::make_shared<edict_t>();
			edict->free = 0;
			edict->v.classname = ALLOC_STRING("player");
			edict->v.netname = 0;
			edict->v.flags = FL_CLIENT;
			this->edicts.push_back(edict);
		}

		pfnRegisterVariable(const_cast<char*>("cl_himodels"), const_cast<char*>("0"), 0);
		pfnRegisterVariable(const_cast<char*>("developer"), const_cast<char*>("1"), 0);
		pfnRegisterVariable(const_cast<char*>("r_drawentities"), const_cast<char*>("1"), 0);
	}

	const enginefuncs_t Engine::GetServerEngineFunctions() const
	{
		return this->engineFunctions;
	}

	const globalvars_t Engine::GetServerGlobalVariables() const
	{
		return this->globalVariables;
	}

	const DLL_FUNCTIONS *Engine::GetDLLFunctions() const
	{
		return &this->dllFunctions;
	}

	const NEW_DLL_FUNCTIONS Engine::GetNewDLLFunctions() const
	{
		return this->newDllFunctions;
	}

#ifdef CLIENT_DLL
	const cl_enginefunc_t Engine::GetClientEngineFunctions() const
	{
		return this->clientEngineFunctions;
	}
#endif // CLIENT_DLL

	const string Engine::GetGameDirectory() const
	{
		return this->strGameDir;
	}

	void Engine::SetGameDirectory( const string& strGameDir )
	{
		this->strGameDir = strGameDir;
	}

	bool Engine::GetIsDedicatedServer() const
	{
		return this->bIsDedicatedServer;
	}

	void Engine::SetIsDedicatedServer( const bool bIsDedicatedServer )
	{
		this->bIsDedicatedServer = bIsDedicatedServer;
	}

	bool Engine::GetIsCareerMatch() const
	{
		return this->bIsCareerMatch;
	}

	void Engine::SetIsCareerMatch( const bool bIsCareerMatch )
	{
		this->bIsCareerMatch = bIsCareerMatch;
	}

#ifdef CLIENT_DLL
	TRICULLSTYLE Engine::GetTriCullStyle() const
	{
		return this->triCullStyle;
	}

	void Engine::SetTriCullStyle( const TRICULLSTYLE triCullStyle )
	{
		this->triCullStyle = triCullStyle;
	}
#endif // CLIENT_DLL

	bool Engine::GetIsFogOn() const
	{
		return this->bIsFogOn;
	}

	void Engine::SetIsFogOn( const bool bIsFogOn )
	{
		this->bIsFogOn = bIsFogOn;
	}

	int Engine::GetRenderer() const
	{
		return this->iRenderer;
	}

	void Engine::SetRenderer( const int iRenderer )
	{
		this->iRenderer = iRenderer;
	}

	void Engine::SetMaxClients( const unsigned int iMaxClients )
	{
		this->globalVariables.maxClients = (signed int)iMaxClients;
	}

	const char* Engine::GetString( string_t offset )
	{
		return (const char*)(gpGlobals->pStringBase + (unsigned int)(offset));
	}

	string Util::tolowercase( const string& str )
	{
		string lowerCased = str;

		for( unsigned int i = 0; i < str.length(); i++ )
		{
			// not ideal but this is how the engine would be doing it
			lowerCased[i] = tolower(str[i]);
		}

		return lowerCased;
	}

	//////////////////////////////
	// Fake enginefuncs_t below //
	//////////////////////////////

	int pfnPrecacheModel(char* s)
	{
		printf("Precaching %s\n", s);

		// TODO: store more than just a string
		gEngine.models.push_back(string(s));

		return gEngine.models.size() - 1;
	}

	int pfnPrecacheSound(char* s)
	{
		printf("Precaching %s\n", s);

		gEngine.sounds.push_back(string(s));

		return gEngine.sounds.size() - 1;
	}

	void pfnSetModel(edict_t* e, const char* m)
	{
		// TODO: excessive calls will overflow the string table - is this what the engine does?
		e->v.model = ALLOC_STRING(m);
	}

	int pfnModelIndex(const char* m)
	{
		for (unsigned int i = 0; i < gEngine.models.size(); i++)
		{
			if (gEngine.models[i] == Util::tolowercase(string(m)))
			{
				return i;
			}
		}

		// TODO: not right - crash instead?
		return -1;
	}

	int pfnModelFrames(int modelIndex)
	{
		string model = gEngine.models[modelIndex];

		// TODO: return the correct value
		return 0;
	}

	void pfnSetSize(edict_t* e, const float* rgflMin, const float* rgflMax)
	{
		// TODO: check this
		e->v.mins.x = rgflMin[0];
		e->v.mins.y = rgflMin[1];
		e->v.mins.z = rgflMin[2];
		e->v.maxs.x = rgflMax[0];
		e->v.maxs.y = rgflMax[1];
		e->v.maxs.z = rgflMax[2];
	}

	void pfnChangeLevel(char* s1, char* s2)
	{
		// TODO: set this->globalVariables.mapname
	}

	void pfnGetSpawnParms(edict_t* ent)
	{
		// TODO: does nothing?
		return;
	}

	void pfnSaveSpawnParms(edict_t* ent)
	{
		// TODO: does nothing?
		return;
	}

	float pfnVecToYaw(const float* rgflVector)
	{
		// TODO:
		return 0.0f;
	}

	void pfnVecToAngles(const float* rgflVectorIn, float* rgflVectorOut)
	{
		// TODO:
	}

	void pfnMoveToOrigin( edict_t* ent, const float* pflGoal, float dist, int iMoveType )
	{
		ent->v.origin.x = pflGoal[0];
		ent->v.origin.y = pflGoal[1];
		ent->v.origin.z = pflGoal[2];
	}

	void pfnChangeYaw( edict_t* ent )
	{
		// TODO:
	}

	void pfnChangePitch( edict_t* ent )
	{
		// TODO:
	}

	edict_t* pfnFindEntityByString( edict_t* pEdictStartSearchAfter, const char* pszField, const char* pszValue )
	{
		return nullptr;
	}

	int pfnGetEntityIllum( edict_t* pEnt )
	{
		return 0;
	}

	edict_t* pfnFindEntityInSphere( edict_t* pEdictStartSearchAfter, const float* org, float rad )
	{
		return nullptr;
	}

	edict_t* pfnFindClientInPVS( edict_t* pEdict )
	{
		return nullptr;
	}

	edict_t* pfnEntitiesInPVS( edict_t* pplayer )
	{
		return nullptr;
	}

	edict_t* pfnCreateEntity()
	{
		shared_ptr<edict_t> edict = std::make_shared<edict_t>();
		edict->free = 0;

		gEngine.edicts.push_back(edict);

		return edict.get();
	}

	void pfnSetOrigin( edict_t* e, const float* rgflOrigin )
	{
		e->v.origin[0] = rgflOrigin[0];
		e->v.origin[1] = rgflOrigin[1];
		e->v.origin[2] = rgflOrigin[2];
	}

	void pfnEmitSound( edict_t* entity, int channel, const char* sample, float volume, float attenuation, int fFlags, int pitch )
	{
		// TODO: check if sound exists
	}

	void pfnEmitAmbientSound( edict_t* entity, float* pos, const char* samp, float vol, float attenuation, int fFlags, int pitch )
	{
		// TODO: check if sound exists
	}

	void pfnTraceSphere( const float* v1, const float* v2, int fNoMonsters, float radius, edict_t* pentToSkip, TraceResult* ptr )
	{
		fprintf( stderr, "pfnTraceSphere is not implemented\n" );

		// NOTE: causes the engine to exit, so do the same here to discourage use
		exit( 1 );
	}

	void pfnServerCommand( char* str )
	{
		gEngine.executedServerCommands.push_back( string(str) );
	}

	void pfnServerExecute( void )
	{
		// TODO: what does this do?
	}

	void pfnClientCommand( edict_t* pEdict, char* szFmt, ... )
	{
		va_list argptr;
		char buffer[1024];

		va_start(argptr, szFmt);
		vsprintf(buffer, szFmt, argptr);
		va_end(argptr);

		gEngine.executedClientCommands.push_back( string(buffer) );
	}

	void pfnParticleEffect( const float* org, const float* dir, float color, float count )
	{
		// TODO: do nothing?
	}

	void pfnLightStyle( int style, char* val )
	{
		// TODO: do nothing?
	}

	int32 pfnRandomLong( int32 lLow, int32 lHigh )
	{
		return rand() % lHigh + lLow;
	}

	void pfnAlertMessage( ALERT_TYPE atype, char *szFmt, ... )
	{
		va_list argptr;
		char buffer[1024];

		va_start( argptr, szFmt );
		vsprintf( buffer, szFmt, argptr );
		va_end( argptr );

		printf( "%s", buffer);
	}

	void* pfnPvAllocEntPrivateData( edict_t* pEdict, int32 cb )
	{
		pEdict->pvPrivateData = malloc( cb );

		return pEdict->pvPrivateData;
	}

	int pfnAllocString( const char* szValue )
	{
		globalvars_t globalVars = gEngine.GetServerGlobalVariables();
		// get the next unassigned part of the string table
		const char* pCurrentOffset = globalVars.pStringBase + gEngine.iStringTableOffset;
		// copy the new string to the next unassigned part of the string table
		strncpy( (char*)pCurrentOffset, szValue, strlen(szValue) );

		// get the newly assigned string's location
		int iCurrentOffset = gEngine.iStringTableOffset;
		// update the location of the next unassigned part of the string table (add 1 to terminate the string)
		gEngine.iStringTableOffset += strlen(szValue) + 1;
		// return the newly assigned string's location
		return iCurrentOffset;
	}

	edict_t* pfnPEntityOfEntOffset( int iEntOffset )
	{
		if( (unsigned int)iEntOffset >= gEngine.edicts.size() )
		{
			return nullptr;
		}
		else
		{
			return gEngine.edicts[iEntOffset].get();
		}
	}

	int pfnEntOffsetOfPEntity( const edict_t* pEdict )
	{
		// TODO: what is this function meant to return?
		return 1;
	}

	edict_t* pfnPEntityOfEntIndex( int iEntIndex )
	{
		edict_t* result;

		// TODO: is pfnPEntityOfEntOffset the same as EDICT_NUM?
		if( iEntIndex < 0 ||
			iEntIndex >= gEngine.iMaxEdicts ||
			( (result = pfnPEntityOfEntOffset( iEntIndex )) == nullptr || result->free || !result->pvPrivateData ) &&
			( iEntIndex >= gEngine.GetServerGlobalVariables().maxClients || result->free ) ) // this check on result fails if there are no edicts - never happens in GoldSource?
		{
			result = nullptr;
		}

		return result;
	}

	edict_t* pfnFindEntityByVars( struct entvars_s* pvars )
	{
		edict_t* result = nullptr;

		for( size_t i = 0; i < gEngine.edicts.size(); i++ )
		{
			edict_t* current = gEngine.edicts[i].get();

			if( &current->v == pvars )
			{
				result = current;
				break;
			}
		}

		return result;
	}

	void* pfnGetModelPtr( edict_t* pEdict )
	{
		// TODO: make it return something
		return nullptr;
	}

	const char* pfnNameForFunction( uint32 function )
	{
		// TODO: implement
		return nullptr;
	}

	void pfnServerPrint( const char* szMsg )
	{
		printf( "%s", szMsg );
	}

	void pfnGetGameDir( char *szGetGameDir )
	{
		strncpy( szGetGameDir, gEngine.GetGameDirectory().c_str(), gEngine.GetGameDirectory().size() + 1 );
	}

	int pfnIsDedicatedServer( void )
	{
		return gEngine.GetIsDedicatedServer();
	}

	unsigned short pfnPrecacheEvent( int type, const char* psz )
	{
		printf( "Precaching %s\n", psz );

		event_t event;
		// down-cast so that it's a valid index - should never have too many events anyway
		event.iIndex = (unsigned short)gEngine.events.size();
		event.strEventFileName = string(psz);
		event.iType = type;

		gEngine.events.push_back(event);

		return event.iIndex;
	}

	void pfnPlaybackEvent( int flags, const edict_t* pInvoker, unsigned short eventindex, float delay, float* origin, float* angles, float fparam1, float fparam2, int iparam1, int iparam2, int bparam1, int bparam2 )
	{
		bool bEventFound = false;

		for (unsigned int i = 0; i < gEngine.events.size(); i++)
		{
			if (gEngine.events[i].iIndex == eventindex)
			{
				bEventFound = true;
			}
		}

		if (!bEventFound)
		{
			// TODO: error out?
		}
	}

	int pfnIsCareerMatch( void )
	{
		return gEngine.GetIsCareerMatch();
	}

	void pfnQueryClientCvarValue( const edict_t* player, const char* cvarName )
	{
	}

	void pfnQueryClientCvarValue2( const edict_t* player, const char* cvarName, int requestID )
	{
	}

	int pfnCheckParm( const char* pchCmdLineToken, char** ppnext )
	{
		return 0;
	}

	edict_t* pfnPEntityOfEntIndexAllEntities( int iEntIndex )
	{
		edict_t* result;

		// TODO: is pfnPEntityOfEntOffset the same as EDICT_NUM?
		if( iEntIndex < 0 ||
			iEntIndex >= gEngine.iMaxEdicts ||
			( (result = pfnPEntityOfEntOffset( iEntIndex )) == nullptr || result->free || !result->pvPrivateData ) &&
			( iEntIndex > gEngine.GetServerGlobalVariables().maxClients || result->free ) ) // this check on result fails if there are no edicts - never happens in GoldSource?
		{
			result = nullptr;
		}

		return result;
	}

	//////////////////////////////
	// Fake DLL_FUNCTIONS below //
	//////////////////////////////

	void ClientCommand( edict_t* pEntity )
	{
		gEngine.iCallsToClientCommand++;
	}

	void ServerActivate( edict_t* pEdictList, int edictCount, int clientMax )
	{
	}

	////////////////////////////////
	// Fake cl_enginefunc_t below //
	////////////////////////////////

	struct cvar_s* pfnRegisterVariable( char* szName, char* szValue, int flags )
	{
		shared_ptr<cvar_t> cvar = std::make_shared<cvar_t>();
		cvar->name = new char[16];
		strncpy( cvar->name, szName, strlen(szName) );
		cvar->name[strlen(szName)] = '\0';
		cvar->value = atof( szValue );
		cvar->flags = flags;

		gEngine.clientCvars.push_back(cvar);

		return cvar.get();
	}

	int pfnAddCommand( char* cmd_name, void (*pfnEngSrc_function)(void) )
	{
		clientCommand_t clientCommand;
		clientCommand.iIndex = gEngine.userMessages.size();
		clientCommand.strCommandName = string(cmd_name);
#ifdef CLIENT_DLL
		clientCommand.pfnFunction = pfnEngSrc_function;
#endif // CLIENT_DLL

		gEngine.clientCommands.push_back(clientCommand);

		return clientCommand.iIndex;
	}

#ifdef CLIENT_DLL
	int pfnHookUserMsg( char* szMsgName, pfnUserMsgHook pfn )
	{
		userMessage_t userMessage;
		userMessage.iIndex = gEngine.userMessages.size();
		userMessage.strMessageName = string(szMsgName);
		userMessage.pfnFunction = pfn;

		gEngine.userMessages.push_back(userMessage);

		return userMessage.iIndex;
	}
#endif // CLIENT_DLL

	void Con_DPrintf( char* fmt, ... )
	{
		va_list argptr;
		char buffer[1024];

		va_start( argptr, fmt );
		vsprintf( buffer, fmt, argptr );
		va_end( argptr );

		printf( "%s", buffer );
	}

	const char* pfnGetGameDirectory( void )
	{
		return gEngine.GetGameDirectory().c_str();
	}

	struct cvar_s* pfnGetCvarPointer( const char* szName )
	{
		for( size_t i = 0; i < gEngine.clientCvars.size(); i++ )
		{
			shared_ptr<cvar_t> cvar = gEngine.clientCvars[i];

			if( !strcmp( cvar->name, szName ) )
			{
				return cvar.get();
			}
		}

		return nullptr;
	}

	const char* pfnGetLevelName( void )
	{
		return "maps/test.bsp";
	}

#ifdef CLIENT_DLL
	void* VGui_GetPanel()
	{
		return new ::vgui::Panel();
	}

	void CullFace( TRICULLSTYLE style )
	{
		gEngine.SetTriCullStyle( style );
	}
#endif // CLIENT_DLL

	void Fog( float flFogColor[3], float flStart, float flEnd, int bOn )
	{
		gEngine.SetIsFogOn( bOn != 0 );
	}

	void FogParams( float flDensity, int iFogSkybox )
	{
	}

	////////////////////////////////////
	// Fake engine_studio_api_t below //
	////////////////////////////////////

	struct model_s* GetChromeSprite( void )
	{
		return nullptr;
	}

	void GetModelCounters( int** s, int** a )
	{
	}

	float**** StudioGetBoneTransform( void )
	{
		return nullptr;
	}

	float**** StudioGetLightTransform( void )
	{
		return nullptr;
	}

	float*** StudioGetAliasTransform( void )
	{
		return nullptr;
	}

	float*** StudioGetRotationMatrix( void )
	{
		return nullptr;
	}

	int IsHardware( void )
	{
		return gEngine.GetRenderer();
	}
}
