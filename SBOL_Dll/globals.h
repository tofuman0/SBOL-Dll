#pragma once
#define MAX_MESG_LEN	4096
#define DEBUG_LOG

// Used to store the pointer to the save game function - Unused space hopefully - Only used with offline.dll
#define SHARED_SPACE_PTR_ADDR		0x005B53CC
#define SHARED_SPACE_LOCK			0x4B434F4C
#define SHARED_SPACE_UNLOCK			0x00000000

#pragma pack(1)
typedef struct st_SharedSpace {
	typedef struct st_Entity {
		bool IsMasterLocked() { return (master == SHARED_SPACE_LOCK); }
		void LockMaster() { master = SHARED_SPACE_LOCK; }
		void UnlockMaster() { master = SHARED_SPACE_UNLOCK; }
		bool IsSlaveLocked() { return (slave == SHARED_SPACE_LOCK); }
		void LockSlave() { slave = SHARED_SPACE_LOCK; }
		void UnlockSlave() { slave = SHARED_SPACE_UNLOCK; }
		uint32_t master = SHARED_SPACE_UNLOCK;
		uint32_t slave = SHARED_SPACE_UNLOCK;
		void* sharedptr = nullptr;
	} ENTITY;
	const uint32_t magic = 0x55464F54;
	ENTITY savegame;
	ENTITY reserved2;
	ENTITY reserved3;
	ENTITY reserved4;
	ENTITY reserved5;
	ENTITY reserved6;
	ENTITY reserved7;
	ENTITY reserved8;
} SHAREDSPACE;
#pragma pack()
