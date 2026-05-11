#pragma once
#include "stdint.h"
#include "globals.h"

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

typedef struct st_replacefunction {
	void* function = nullptr;
	int* address = nullptr;
} REPLACEFUNCTION;
typedef struct st_adjustfloats {
	adjustFloatsFunc* function = nullptr;
	float* x = nullptr;
	float* y = nullptr;
	void AdjustFloats()
	{
		if (function)
			function(x, y);
	}
} ADJUSTFLOATS;
typedef struct st_adjustints {
	adjustIntsFunc* function = nullptr;
	int* x = nullptr;
	int* y = nullptr;
	void AdjustInts()
	{
		if (function)
			function(x, y);
	}
} ADJUSTINTS;
#pragma pack()