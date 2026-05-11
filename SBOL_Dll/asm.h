#pragma once
#ifndef ASM_HEADER
#define ASM_HEADER
#include <Windows.h>
#include <vector>
#include <functional>
#include "dx.h"
#include <math.h>
#include "globals.h"

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
void __fastcall createUIElementObject(void* _this, void* edx, int posx, int posy);
void __fastcall createUIElementObject_AutoScale(void* _this, void* edx, int posx, int posy);
void __fastcall createUIElementObject_Scale(void* _this, void* edx, int posx, int posy);
void __fastcall createUIElementObject_Scale_Reposition(void* _this, void* edx, int posx, int posy);
void __fastcall createUIElementObject_Scale_Reposition_BottomLeft(void* _this, void* edx, int posx, int posy);
void __fastcall createUIElement(void* _this, void* edx, float posx, float posy, float width, float height, int param_6, int param_7, int param_8);
void __fastcall createUIElement_43(void* _this, void* edx, float posx, float posy, float width, float height, int param_6, int param_7, int param_8);
void __fastcall createUIElement_Scale_Reposition(void* _this, void* edx, float posx, float posy, float width, float height, int param_6, int param_7, int param_8);
void __fastcall createUIElement_Scale_Reposition_TopLeft(void* _this, void* edx, float posx, float posy, float width, float height, int param_6, int param_7, int param_8);
void __fastcall createUIElement_Scale_Reposition_BottomLeft(void* _this, void* edx, float posx, float posy, float width, float height, int param_6, int param_7, int param_8);
void __fastcall createUIElement_Scale_Reposition_BottomRight(void* _this, void* edx, float posx, float posy, float width, float height, int param_6, int param_7, int param_8);
void __fastcall createUIElement_AutoScale(void* _this, void* edx, float posx, float posy, float width, float height, int param_6, int param_7, int param_8);
void __fastcall createUIElement_AutoScale_43(void* _this, void* edx, float posx, float posy, float width, float height, int param_6, int param_7, int param_8);
void __fastcall createUIElement_AutoScale_Handle(void* _this, void* edx, float posx, float posy, float width, float height, int param_6, int param_7, int param_8);
void __fastcall createUIElement_AutoScale_TeamName(void* _this, void* edx, float posx, float posy, float width, float height, int param_6, int param_7, int param_8);
void __fastcall createUIElement_Scale(void* _this, void* edx, float posx, float posy, float width, float height, int param_6, int param_7, int param_8);
void __fastcall positionUIElement(void* _this, void* edx, float posx, float posy, int type);
void __fastcall positionUIElement_Reposition(void* _this, void* edx, float posx, float posy, int type);
void __fastcall interactionUIElement(void* _this, void* edx, int posx, int posy, int width, int height);
void __fastcall interactionUIElement_Scale(void* _this, void* edx, int posx, int posy, int width, int height);
void __fastcall interactionUIElement_Scale_Reposition(void* _this, void* edx, int posx, int posy, int width, int height);
void __fastcall interactionUIElement_Scale_Reposition_TopLeft(void* _this, void* edx, int posx, int posy, int width, int height);
void __fastcall interactionUIElement_Scale_Reposition_BottomRight(void* _this, void* edx, int posx, int posy, int width, int height);
void __fastcall moveUIElement(void* _this, void* edx, int posx, int posy);
void __fastcall moveUIElement_Position(void* _this, void* edx, int posx, int posy);
void __fastcall uiInteractBoundary(void* _this, void* edx, int posx, int posy, int width, int height);
void __fastcall createTextbox(void* _this, void* edx, float posx, float posy);
void __fastcall createTextbox_Scale_Reposition_TopLeft(void* _this, void* edx, float posx, float posy);
void __fastcall createTextboxCarat(void* _this, void* edx, int caratpos);
void adjustfloats(float* x, float* y);
void adjustfloats43(float* x, float* y);
void adjustfloatsN(float* x, float* y);
void adjustfloatsNBR(float* x, float* y);
void adjustints(int* x, int* y);
void adjustintsN(int* x, int* y);
void adjustintsNTC(int* x, int* y);
void __fastcall addressbookTextbox(void* _this, void* edx, int posx, int posy);
void positionUIElement2();
void positionUIElement3();
void adjustUI();
void scaleUIElement();
void adjustXAxis();
void __fastcall placeString(void* obj, int unused, int x, int y);
void __fastcall placeStringLeftAlign(void* obj, int unused, int x, int y);
void __fastcall placeStringRightAlign(void* obj, int unused, int x, int y);
typedef void(__fastcall *placeStringFunc)(void* obj, int unused, int x, int y);
typedef void(__fastcall* createUIElementObjectFunc)(void* _this, void* edx, int posx, int posy);
typedef void(__fastcall *createUIElementFunc)(void* _this, void* edx, float posx, float posy, float width, float height, int param_6, int param_7, int param_8);
typedef void(__fastcall* positionUIElementFunc)(void* _this, void* edx, float posx, float posy, int type);
typedef void(__fastcall* interactionUIElementFunc)(void* _this, void* edx, int posx, int posy, int width, int height);
typedef void(__fastcall* PositionInteractionUIFunc)(void* _this, void* edx, int posx, int posy);
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
int notFullScreenMode();
int skipBootWarning();
void setTexturePositions();
void setItemUsePosition();
void drawString();
void directxScene();
void directxReturn();
#endif