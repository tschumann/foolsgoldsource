//========= Copyright © 2008-2023, Team Sandpit, All rights reserved. ============
//
// Purpose: Fake GoldSource engine definitions
//
// $NoKeywords: $
//================================================================================

#ifndef _FOOLSGOLDSOURCE_H_
#define _FOOLSGOLDSOURCE_H_

#include <cstring>
#include <cctype>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

#ifdef CLIENT_DLL
#define VECTOR_H // cl_dll/util_vector.h and dlls/vector.h define fairly similar classes - define the dlls/vector.h header guard to stop redefinition errors
#include "hud.h"
#include "r_studioint.h"
#include "triangleapi.h"
#include "VGUI_App.h"
#include "VGUI_Panel.h"
#include "VGUI_Scheme.h"
#endif // CLIENT_DLL

#include "extdll.h"
#include "enginecallback.h"

using std::cout;
using std::endl;
using std::shared_ptr;
using std::string;
using std::vector;

const int RENDERER_SOFTWARE = 0;
const int RENDERER_OPENGL = 1;

namespace foolsgoldsource
{
	typedef void (*commandFunction)(void);

	struct event_t
	{
		unsigned short iIndex;
		string strEventFileName;
		int iType;
	};

	struct clientCommand_t
	{
		unsigned int iIndex;
		string strCommandName;
		commandFunction pfnFunction;
	};

	struct userMessage_t
	{
		unsigned int iIndex;
		string strMessageName;
#ifdef CLIENT_DLL
		pfnUserMsgHook pfnFunction;
#endif // CLIENT_DLL
	};

	enum class EngineType
	{
		ENGINE_SDKv10,
		ENGINE_SDKv20,
		ENGINE_SDKv21,
		ENGINE_SDKv22,
		ENGINE_SDKv23,
		ENGINE_STEAM,
		ENGINE_CRYOFFEAR,
		ENGINE_CROSSPLATFORM,
		ENGINE_SVENGINE,
		ENGINE_25ANNIVERSARY
	};

	class Engine
	{
	public:
		Engine();
		~Engine() noexcept;

		void Reset();

		const enginefuncs_t GetServerEngineFunctions() const;
		const globalvars_t GetServerGlobalVariables() const;
		const DLL_FUNCTIONS *GetDLLFunctions() const;
		const NEW_DLL_FUNCTIONS GetNewDLLFunctions() const;

#ifdef CLIENT_DLL
		const cl_enginefunc_t GetClientEngineFunctions() const;
#endif // CLIENT_DLL

		const string GetGameDirectory() const;
		void SetGameDirectory( const string& strGameDir );
		bool GetIsDedicatedServer() const;
		void SetIsDedicatedServer( const bool bIsDedicatedServer );
		bool GetIsCareerMatch() const;
		void SetIsCareerMatch( const bool bIsCareerMatch );

		void SetMaxClients( const unsigned int iMaxClients );

#ifdef CLIENT_DLL
		TRICULLSTYLE GetTriCullStyle() const;
		void SetTriCullStyle( const TRICULLSTYLE triCullStyle );
#endif // CLIENT_DLL

		bool GetIsFogOn() const;
		void SetIsFogOn( const bool bIsFogOn );

		int GetRenderer() const;
		void SetRenderer( const int iRenderer );

		const char* GetString( string_t offset );

		// below shouldn't be public because the game doesn't have access to them

		// TODO: below be in some server struct?
		vector<shared_ptr<edict_t>> edicts;
		vector<string> models;
		vector<string> sounds;
		vector<event_t> events;
		int iMaxEdicts;
		vector<string> executedClientCommands;
		vector<string> executedServerCommands;

		vector<shared_ptr<cvar_t>> clientCvars;
		vector<clientCommand_t> clientCommands;
		vector<userMessage_t> userMessages;

		// TODO: should probably be private
		unsigned int iCallsToClientCommand;

		// TODO: how does the engine track this?
		unsigned int iStringTableOffset;

		const static unsigned int iStringTableSize = 2048;
	private:
		enginefuncs_t engineFunctions;
		globalvars_t globalVariables;
		DLL_FUNCTIONS dllFunctions;
		NEW_DLL_FUNCTIONS newDllFunctions;

#ifdef CLIENT_DLL
		triangleapi_t triangleApi;
		cl_enginefunc_t clientEngineFunctions;
		engine_studio_api_t engineStudioFunctions;
#endif // CLIENT_DLL

		EngineType engineType;

		string strGameDir;

		bool bIsDedicatedServer;
		bool bIsCareerMatch;

#ifdef CLIENT_DLL
		TRICULLSTYLE triCullStyle;
#endif // CLIENT_DLL
		bool bIsFogOn;
		int iRenderer;
	};

	class Util
	{
	public:
		static string tolowercase( const string& str );
	};

	extern Engine gEngine;

	// enginefuncs_t
	int pfnPrecacheModel( char* s );
	int pfnPrecacheSound( char* s );
	void pfnSetModel( edict_t* e, const char* m );
	int pfnModelIndex( const char* m );
	int pfnModelFrames( int modelIndex );
	void pfnSetSize( edict_t* e, const float* rgflMin, const float* rgflMax );
	void pfnChangeLevel( char* s1, char* s2 );
	void pfnGetSpawnParms( edict_t* ent );
	void pfnSaveSpawnParms( edict_t* ent );
	float pfnVecToYaw( const float* rgflVector );
	void pfnVecToAngles( const float* rgflVectorIn, float* rgflVectorOut );
	void pfnMoveToOrigin( edict_t* ent, const float* pflGoal, float dist, int iMoveType );
	void pfnChangeYaw( edict_t* ent );
	void pfnChangePitch( edict_t* ent );
	edict_t* pfnFindEntityByString( edict_t* pEdictStartSearchAfter, const char* pszField, const char* pszValue );
	int pfnGetEntityIllum( edict_t* pEnt );
	edict_t* pfnFindEntityInSphere( edict_t* pEdictStartSearchAfter, const float* org, float rad );
	edict_t* pfnFindClientInPVS( edict_t* pEdict );
	edict_t* pfnEntitiesInPVS( edict_t* pplayer );

	edict_t* pfnCreateEntity( void );

	void pfnSetOrigin( edict_t* e, const float* rgflOrigin );
	void pfnEmitSound( edict_t* entity, int channel, const char* sample, float volume, float attenuation, int fFlags, int pitch );
	void pfnEmitAmbientSound( edict_t* entity, float* pos, const char* samp, float vol, float attenuation, int fFlags, int pitch );

	void pfnTraceSphere( const float* v1, const float* v2, int fNoMonsters, float radius, edict_t* pentToSkip, TraceResult* ptr );

	void pfnServerCommand( char* str );
	void pfnServerExecute( void );
	void pfnClientCommand( edict_t* pEdict, char* szFmt, ... );
	void pfnParticleEffect( const float* org, const float* dir, float color, float count );
	void pfnLightStyle( int style, char* val );

	int32 pfnRandomLong( int32 lLow, int32 lHigh );

	void pfnAlertMessage( ALERT_TYPE atype, char *szFmt, ... );

	void* pfnPvAllocEntPrivateData( edict_t* pEdict, int32 cb );

	int pfnAllocString( const char* szValue );

	edict_t* pfnPEntityOfEntOffset( int iEntOffset );
	int pfnEntOffsetOfPEntity( const edict_t* pEdict );

	edict_t* pfnPEntityOfEntIndex( int iEntIndex );
	edict_t* pfnFindEntityByVars( struct entvars_s* pvars );
	void* pfnGetModelPtr( edict_t* pEdict );

	const char* pfnNameForFunction( uint32 function );

	void pfnServerPrint( const char* szMsg );

	void pfnGetGameDir( char *szGetGameDir );

	int pfnIsDedicatedServer( void );

	unsigned short pfnPrecacheEvent( int type, const char* psz );
	void pfnPlaybackEvent( int flags, const edict_t* pInvoker, unsigned short eventindex, float delay, float* origin, float* angles, float fparam1, float fparam2, int iparam1, int iparam2, int bparam1, int bparam2 );

	int pfnIsCareerMatch( void );

	void pfnQueryClientCvarValue( const edict_t* player, const char* cvarName );
	void pfnQueryClientCvarValue2( const edict_t* player, const char* cvarName, int requestID );
	int pfnCheckParm( const char* pchCmdLineToken, char** ppnext );
	edict_t* pfnPEntityOfEntIndexAllEntities( int iEntIndex );

	// DLL_FUNCTIONS
	void ClientCommand( edict_t* pEntity );

	void ServerActivate( edict_t* pEdictList, int edictCount, int clientMax );

	// cl_enginefunc_t
	struct cvar_s* pfnRegisterVariable( char* szName, char* szValue, int flags );

	int pfnAddCommand( char* cmd_name, void (*pfnEngSrc_function)(void) );
#ifdef CLIENT_DLL
	int pfnHookUserMsg( char* szMsgName, pfnUserMsgHook pfn );
#endif // CLIENT_DLL

	void Con_DPrintf(char* fmt, ...);

	const char* pfnGetGameDirectory( void );
	struct cvar_s* pfnGetCvarPointer( const char* szName );

	const char* pfnGetLevelName( void );

#ifdef CLIENT_DLL
	void* VGui_GetPanel();

	void CullFace( TRICULLSTYLE style );
#endif // CLIENT_DLL
	void Fog( float flFogColor[3], float flStart, float flEnd, int bOn );

	void FogParams( float flDensity, int iFogSkybox );

	// engine_studio_api_t
	struct model_s* GetChromeSprite( void );
	void GetModelCounters( int** s, int** a );

	float**** StudioGetBoneTransform( void );
	float**** StudioGetLightTransform( void );
	float*** StudioGetAliasTransform( void );
	float*** StudioGetRotationMatrix( void );

	int IsHardware( void );
}

#endif // _FOOLSGOLDSOURCE_H_
