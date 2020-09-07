#pragma once

class IGameImports;

class GameImportsLocal final : public IGameImports 
{
public:
	GameImportsLocal() = default;
	virtual ~GameImportsLocal() = default;

	void			AddConsoleCommand( const char* commandName ) override;
	void			RemoveConsoleCommand( const char* commandName ) override;
	void			SendClientCommand( const char* s ) override;
	void			ConsoleVariable_Register( vmCvar_t* cvar, const char* name, const char* value, int flags ) override;
	void			ConsoleVariable_Update( vmCvar_t* cvar ) override;
	void			ConsoleVariable_Set( const char* name, const char* value ) override;
	int				ConsoleVariable_GetInteger( const char* name ) override;
	void			ConsoleVariable_GetString( const char* name, char* buffer, int bufferSize ) override;

	void			LocateGameData( sharedEntity_t* gEnts, int numEntities, int sizeOfEntity, playerState_t* client, int sizeOfClient ) override;

	void			DropClient( int clientNum, const char* reason ) override;
	void			SendServerCommand( int clientNum, const char* commandText ) override;

	void			SetConfigString( int num, const char* string ) override;
	void			GetConfigString( int num, char* buffer, int bufferSize ) override;

	void			GetUserInfo( int num, char* buffer, int bufferSize ) override;
	void			SetUserInfo( int num, const char* buffer ) override;

	void			GetServerInfo( char* buffer, int bufferSize ) override;

	void			SetBrushModel( sharedEntity_t* ent, const char* name ) override;

	void			Trace( trace_t* results, const vec3_t start, const vec3_t mins, const vec3_t maxs, const vec3_t end, int passEntityNum, int contentmask ) override;
	void			TraceCapsule( trace_t* results, const vec3_t start, const vec3_t mins, const vec3_t maxs, const vec3_t end, int passEntityNum, int contentmask ) override;

	int				PointContents( const vec3_t point, int passEntityNum ) override;

	bool			IsInPVS( const vec3_t p1, const vec3_t p2 ) override;
	bool			InPVSIgnorePortals( const vec3_t p1, const vec3_t p2 ) override;

	void			AdjustAreaPortalState( sharedEntity_t* ent, bool open ) override;
	bool			AreasConnected( int area1, int area2 ) override;

	void			LinkEntity( sharedEntity_t* ent ) override;
	void			UnlinkEntity( sharedEntity_t* ent ) override;

	int				EntitiesInBox( const vec3_t mins, const vec3_t maxs, int* list, int maxcount ) override;
	bool			EntityContact( vec3_t mins, vec3_t maxs, const sharedEntity_t* ent ) override;
	bool			EntityContactCapsule( vec3_t mins, vec3_t maxs, const sharedEntity_t* ent ) override;

	int				BotAllocateClient( void ) override;
	void			BotFreeClient( int clientNum ) override;
	void			GetUsercmd( int clientNum, usercmd_t* cmd ) override;

	int				DebugPolygonCreate( int color, int numPoints, vec3_t* points ) override;
	void			DebugPolygonDelete( int id ) override;
};