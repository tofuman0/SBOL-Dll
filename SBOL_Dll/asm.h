#pragma once
#ifndef ASM_HEADER
#define ASM_HEADER
#include <Windows.h>
#include "dx.h"
#include <math.h>

enum functionType {
	FT_CALL,
	FT_JUMP
};

#pragma region ASM Defines
#define call_imm(x) __asm \
{ \
__asm mov eax, x \
__asm call eax \
};
#define jmp_imm(x) __asm \
{ \
__asm mov eax, x \
__asm jmp eax \
};
#define SaveEAX __asm mov _EAX, eax;
#define RestoreEAX __asm mov eax, _EAX;
#define SaveECX __asm mov _ECX, ecx;
#define RestoreECX __asm mov ecx, _ECX;
#define SaveEDX __asm mov _EDX, edx;
#define RestoreEDX __asm mov edx, _EDX;
#define SaveEBX __asm mov _EBX, ebx;
#define RestoreEBX __asm mov ebx, _EBX;
#define SaveEDI __asm mov _EDI, edi;
#define RestoreEDI __asm mov edi, _EDI;
#define SaveESI __asm mov _ESI, esi;
#define RestoreESI __asm mov esi, _ESI;
#pragma endregion
void NOPSpace(unsigned location, unsigned int count);
void positionUIElement();
void positionUIElement2();
void positionUIElement3();
void logPositionUIElement();
void adjustUI();
void scaleUIElement();
void adjustXAxis();
void __fastcall placeString(void* obj, int unused, int x, int y);
void __fastcall placeStringLeftAlign(void* obj, int unused, int x, int y);
void __fastcall placeStringRightAlign(void* obj, int unused, int x, int y);
typedef void(__fastcall *placeStringFunc)(void* obj, int unused, int x, int y);
void exitFix();
void __cdecl windowMonitorThread(void* parg);
void getTireBrakePrice();
void getPFileTireBrakePriceMultipler();
void getPFileTireBrakePrice();
void adjustFloats(float* x, float* y);
void adjustInts(int* x, int* y);
void adjustXAxisValue(int* x);
void insertFunction(int addrPtr, void* function, int nopCount, functionType ft);
void setFunction(int addrPtr, void* function);
//void Log(char type, char* in);
//int debugLog(char *buffer, size_t count, const char *format, va_list argptr);
//int debugIt(const char *format, ...);
int fullScreenMode();
int skipBootWarning();
void setTexturePositions();
void setItemUsePosition();
void drawString();
void directxScene();
void directxReturn();
#endif