#include "asm.h"

extern int resW;
extern int virtualResW;
extern int resH;
extern int fullScreen;
extern float SWFscale;
extern float SWFscaleX;
extern float SWFscaleY;
extern int skipWarning;
extern unsigned char* itemFile;
extern int itemFileSize;
extern float UIdividerX;
extern float UIdividerY;
extern float UIscaleX;
extern float UIscaleVirtualX;
extern float UIscaleY;
extern float UIscale;
extern int itemUseDialogX;
extern int itemUseDialogY;
extern char logItBuf[0x400];

extern int _EAX, _ECX, _EDX, _EBX, _EDI, _ESI;
extern float float1, float2, float3, float4, float5;
extern int int1, int2;
extern float *_a1;
extern float *_a2;
extern float *_a3;
extern char textBuf[0x1000];
extern unsigned int isClosed;

placeStringFunc placeStringGame = (placeStringFunc)(0x004FD760);
createUIElementObjectFunc createUIElementObjectOrig = (createUIElementObjectFunc)(0x004FD760);
createUIElementFunc createUIElementOrig = (createUIElementFunc)(0x00404250);
positionUIElementFunc positionUIElementOrig = (positionUIElementFunc)(0x004042F0);
interactionUIElementFunc interactionUIElementOrig = (interactionUIElementFunc)(0x004F49E0);
positionInteractionUIFunc positionInteractionUIOrig = (positionInteractionUIFunc)(0x004F48E0);

void __fastcall createUIElementObject(void* _this, void* edx, int posx, int posy)
{
	D3DSURFACE_DESC desc;
	using GetDescFunc = void(__stdcall*)(void*, int, void*);
	GetDescFunc GetDesc = *(GetDescFunc*)((**(int**)((int)_this + 0x60)) + 0x38);

	posx = (int)(((float)posx / 640.0f) * (float)resW);
	posy = (int)(((float)posy / 480.0f) * (float)resH);
	*(int*)((int)_this + 0x6C) = posx;
	*(int*)((int)_this + 0x70) = posy;

	GetDesc(*(int**)((int)_this + 0x60), 0, &desc);

	auto width = (((float)desc.Width / 640.0f) * resW);
	auto height = (((float)desc.Height / 480.0f) * resH);

	createUIElementOrig((void *)((int)_this + 0x78), edx, (float)posx, (float)posy, width, height, 0, -1, -1);
}
void __fastcall createUIElementObject_43(void* _this, void* edx, int posx, int posy)
{
	D3DSURFACE_DESC desc;
	using GetDescFunc = void(__stdcall*)(void*, int, void*);
	GetDescFunc GetDesc = *(GetDescFunc*)((**(int**)((int)_this + 0x60)) + 0x38);

	posx = (int)(((float)posx / 640.0f) * (float)virtualResW);
	posy = (int)(((float)posy / 480.0f) * (float)resH);

	posx += (int)((resW / 2.0f) - ((float)virtualResW / 2.0f));

	*(int*)((int)_this + 0x6C) = posx;
	*(int*)((int)_this + 0x70) = posy;

	GetDesc(*(int**)((int)_this + 0x60), 0, &desc);

	auto width = (((float)desc.Width / 640.0f) * (float)virtualResW);
	auto height = (((float)desc.Height / 480.0f) * (float)resH);

	createUIElementOrig((void*)((int)_this + 0x78), edx, (float)posx, (float)posy, width, height, 0, -1, -1);
}
void __fastcall createUIElementObject_AutoScale(void* _this, void* edx, int posx, int posy)
{
	D3DSURFACE_DESC desc;
	using GetDescFunc = void(__stdcall*)(void*, int, void*);
	GetDescFunc GetDesc = *(GetDescFunc*)((**(int**)((int)_this + 0x60)) + 0x38);

	*(int*)((int)_this + 0x6C) = posx;
	*(int*)((int)_this + 0x70) = posy;

	GetDesc(*(int**)((int)_this + 0x60), 0, &desc);

	auto width = (((float)desc.Width / 640.0f) * (float)resW);
	auto height = (((float)desc.Height / 480.0f) * (float)resH);

	createUIElementOrig((void*)((int)_this + 0x78), edx, (float)posx, (float)posy, width, height, 0, -1, -1);
}
void __fastcall createUIElementObject_AutoScale_43(void* _this, void* edx, int posx, int posy)
{
	D3DSURFACE_DESC desc;
	using GetDescFunc = void(__stdcall*)(void*, int, void*);
	GetDescFunc GetDesc = *(GetDescFunc*)((**(int**)((int)_this + 0x60)) + 0x38);

	*(int*)((int)_this + 0x6C) = posx;
	*(int*)((int)_this + 0x70) = posy;

	GetDesc(*(int**)((int)_this + 0x60), 0, &desc);

	auto width = (((float)desc.Width / 640.0f) * (float)virtualResW);
	auto height = (((float)desc.Height / 480.0f) * (float)resH);

	createUIElementOrig((void*)((int)_this + 0x78), edx, (float)posx, (float)posy, width, height, 0, -1, -1);
}
void __fastcall createUIElementObject_Scale(void* _this, void* edx, int posx, int posy)
{
	D3DSURFACE_DESC desc;
	using GetDescFunc = void(__stdcall*)(void*, int, void*);
	GetDescFunc GetDesc = *(GetDescFunc*)((**(int**)((int)_this + 0x60)) + 0x38);

	*(int*)((int)_this + 0x6C) = posx;
	*(int*)((int)_this + 0x70) = posy;

	GetDesc(*(int**)((int)_this + 0x60), 0, &desc);

	auto width = ((float)desc.Width * UIscale);
	auto height = ((float)desc.Height * UIscale);

	createUIElementOrig((void*)((int)_this + 0x78), edx, (float)posx, (float)posy, width, height, 0, -1, -1);
}
void __fastcall createUIElementObject_Scale_Reposition(void* _this, void* edx, int posx, int posy)
{
	D3DSURFACE_DESC desc;
	using GetDescFunc = void(__stdcall*)(void*, int, void*);
	GetDescFunc GetDesc = *(GetDescFunc*)((**(int**)((int)_this + 0x60)) + 0x38);

	posx = (int)((float)posx * UIscale);
	posy = (int)((float)posy * UIscale);
	*(int*)((int)_this + 0x6C) = posx;
	*(int*)((int)_this + 0x70) = posy;

	GetDesc(*(int**)((int)_this + 0x60), 0, &desc);

	auto width = ((float)desc.Width * UIscale);
	auto height = ((float)desc.Height * UIscale);

	createUIElementOrig((void*)((int)_this + 0x78), edx, (float)posx, (float)posy, width, height, 0, -1, -1);
}
void __fastcall createUIElementObject_Scale_Reposition_BottomLeft(void* _this, void* edx, int posx, int posy)
{
	auto yOffset = -((480.0f - posy) * UIscale);
	D3DSURFACE_DESC desc;
	using GetDescFunc = void(__stdcall*)(void*, int, void*);
	GetDescFunc GetDesc = *(GetDescFunc*)((**(int**)((int)_this + 0x60)) + 0x38);

	posx = (int)((float)posx * UIscale);
	posy = resH + (int)yOffset;
	*(int*)((int)_this + 0x6C) = posx;
	*(int*)((int)_this + 0x70) = posy;

	GetDesc(*(int**)((int)_this + 0x60), 0, &desc);

	auto width = ((float)desc.Width * UIscale);
	auto height = ((float)desc.Height * UIscale);

	createUIElementOrig((void*)((int)_this + 0x78), edx, (float)posx, (float)posy, width, height, 0, -1, -1);
}
void __fastcall createUIElement(void* _this, void* edx, float posx, float posy, float width, float height, int param_6, int param_7, int param_8)
{
	posx = (posx / 640.0f) * (float)resW;
	posy = (posy / 480.0f) * (float)resH;
	width = (width / 640.0f) * (float)resW;
	height = (height / 480.0f) * (float)resH;
	createUIElementOrig(_this, edx, posx, posy, width, height, param_6, param_7, param_8);
}
void __fastcall createUIElement_43(void* _this, void* edx, float posx, float posy, float width, float height, int param_6, int param_7, int param_8)
{
	posx = (posx / 640.0f) * (float)virtualResW;
	posy = (posy / 480.0f) * (float)resH;
	width = (width / 640.0f) * (float)virtualResW;
	height = (height / 480.0f) * (float)resH;
	
	posx += (resW / 2.0f) - ((float)virtualResW / 2.0f);

	createUIElementOrig(_this, edx, posx, posy, width, height, param_6, param_7, param_8);
}
void __fastcall createUIElement_Scale_Reposition(void* _this, void* edx, float posx, float posy, float width, float height, int param_6, int param_7, int param_8)
{
	auto xOffset = -((640.0f - posx) * UIscale);
	auto yOffset = -((480.0f - posy) * UIscale);
	width *= UIscale;
	height *= UIscale;
	posx = ((posx / 640.0f) * (float)resW) + xOffset;
	posy = ((posy / 480.0f) * (float)resH) + yOffset;
	createUIElementOrig(_this, edx, posx, posy, width, height, param_6, param_7, param_8);
}
void __fastcall createUIElement_Scale_Reposition_TopLeft(void* _this, void* edx, float posx, float posy, float width, float height, int param_6, int param_7, int param_8)
{
	posx *= UIscale;
	posy *= UIscale;
	width *= UIscale;
	height *= UIscale;
	createUIElementOrig(_this, edx, posx, posy, width, height, param_6, param_7, param_8);
}
void __fastcall createUIElement_Scale_Reposition_BottomLeft(void* _this, void* edx, float posx, float posy, float width, float height, int param_6, int param_7, int param_8)
{
	auto yOffset = -((480.0f - posy) * UIscale);
	width *= UIscale;
	height *= UIscale;
	posx *= UIscale;
	posy = (float)resH + yOffset;
	createUIElementOrig(_this, edx, posx, posy, width, height, param_6, param_7, param_8);
}
void __fastcall createUIElement_Scale_Reposition_BottomRight(void* _this, void* edx, float posx, float posy, float width, float height, int param_6, int param_7, int param_8)
{
	auto xOffset = -((640.0f - posx) * UIscale);
	auto yOffset = -((480.0f - posy) * UIscale);
	width *= UIscale;
	height *= UIscale;
	posx = (float)resW + xOffset;
	posy = (float)resH + yOffset;
	createUIElementOrig(_this, edx, posx, posy, width, height, param_6, param_7, param_8);
}
void __fastcall createUIElement_AutoScale(void* _this, void* edx, float posx, float posy, float width, float height, int param_6, int param_7, int param_8)
{
	width = (width / 640.0f) * (float)resW;
	height = (height / 480.0f) * (float)resH;
	createUIElementOrig(_this, edx, posx, posy, width, height, param_6, param_7, param_8);
}
void __fastcall createUIElement_AutoScale_43(void* _this, void* edx, float posx, float posy, float width, float height, int param_6, int param_7, int param_8)
{
	width = (width / 640.0f) * (float)virtualResW;
	height = (height / 480.0f) * (float)resH;
	createUIElementOrig(_this, edx, posx, posy, width, height, param_6, param_7, param_8);
}
void __fastcall createUIElement_AutoScale_Handle(void* _this, void* edx, float posx, float posy, float width, float height, int param_6, int param_7, int param_8)
{
	width = (width / 640.0f) * (float)virtualResW;
	height = (height / 480.0f) * (float)resH;
	posx -= ((1.0f / 640.0f) * ((((float)virtualResW - 640.0f) * 36.0f) + (float)virtualResW));
	posy -= (2.0f / 480.0f) * (float)resH;
	createUIElementOrig(_this, edx, posx, posy, width, height, param_6, param_7, param_8);
}
void __fastcall createUIElement_AutoScale_TeamName(void* _this, void* edx, float posx, float posy, float width, float height, int param_6, int param_7, int param_8)
{
	width = (width / 640.0f) * (float)virtualResW;
	height = (height / 480.0f) * (float)resH;
	posx -= ((1.0f / 640.0f) * ((((float)virtualResW - 640.0f) * 36.0f) + (float)virtualResW));
	posy -= (4.0f / 480.0f) * (float)resH;
	createUIElementOrig(_this, edx, posx, posy, width, height, param_6, param_7, param_8);
}
void __fastcall createUIElement_Scale(void* _this, void* edx, float posx, float posy, float width, float height, int param_6, int param_7, int param_8)
{
	width *= UIscale;
	height *= UIscale;
	createUIElementOrig(_this, edx, posx, posy, width, height, param_6, param_7, param_8);
}
void __fastcall positionUIElement(void* _this, void* edx, float posx, float posy, int type)
{
	posx = (posx / 640.0f) * (float)resW;
	posy = (posy / 480.0f) * (float)resH;
	positionUIElementOrig(_this, edx, posx, posy, type);
}
void __fastcall positionUIElement_Reposition(void* _this, void* edx, float posx, float posy, int type)
{
	posx = posx * UIscale;
	posy = posy * UIscale; 
	positionUIElementOrig(_this, edx, posx, posy, type);
}
void __fastcall interactionUIElement(void* _this, void* edx, int posx, int posy, int width, int height)
{
	posx = (int)(((float)posx / 640.0f) * (float)resW);
	posy = (int)(((float)posy / 480.0f) * (float)resH);
	width = (int)(((float)width / 640.0f) * (float)resW);
	height = (int)(((float)height / 480.0f) * (float)resH);

	uiInteractBoundary(_this, edx, posx, posy, width, height);
	createUIElementOrig((void*)((int)_this + 0x24), edx, (float)posx, (float)posy, (float)width, (float)height, 0, -1, -1);
}
void __fastcall interactionUIElement_43(void* _this, void* edx, int posx, int posy, int width, int height)
{
	posx = (int)(((float)posx / 640.0f) * (float)virtualResW);
	posy = (int)(((float)posy / 480.0f) * (float)resH);
	width = (int)(((float)width / 640.0f) * (float)virtualResW);
	height = (int)(((float)height / 480.0f) * (float)resH);

	posx += (int)(((float)resW / 2.0f) - ((float)virtualResW / 2.0f));

	uiInteractBoundary(_this, edx, posx, posy, width, height);
	createUIElementOrig((void*)((int)_this + 0x24), edx, (float)posx, (float)posy, (float)width, (float)height, 0, -1, -1);
}
void __fastcall interactionUIElement_Scale(void* _this, void* edx, int posx, int posy, int width, int height)
{
	width = (int)((float)width * UIscale);
	height = (int)((float)height * UIscale);
	
	uiInteractBoundary(_this, edx, posx, posy, width, height);
	createUIElementOrig((void*)((int)_this + 0x24), edx, (float)posx, (float)posy, (float)width, (float)height, 0, -1, -1);
}
void __fastcall interactionUIElement_Scale_Reposition(void* _this, void* edx, int posx, int posy, int width, int height)
{
	auto xOffset = -((640 - posx) * UIscale);
	auto yOffset = -((480 - posy) * UIscale);
	width = (int)((float)width * UIscale);
	height = (int)((float)height * UIscale);
	posx = (int)((((float)posx / 640.0f) * (float)resW) - xOffset);
	posy = (int)((((float)posy / 480.0f) * (float)resH) - yOffset);

	uiInteractBoundary(_this, edx, posx, posy, width, height);
	createUIElementOrig((void*)((int)_this + 0x24), edx, (float)posx, (float)posy, (float)width, (float)height, 0, -1, -1);
}
void __fastcall interactionUIElement_Scale_Reposition_TopLeft(void* _this, void* edx, int posx, int posy, int width, int height)
{
	width = (int)((float)width * UIscale);
	height = (int)((float)height * UIscale);
	posx = (int)((float)posx * UIscale);
	posy = (int)((float)posy * UIscale);
	
	uiInteractBoundary(_this, edx, posx, posy, width, height);
	createUIElementOrig((void*)((int)_this + 0x24), edx, (float)posx, (float)posy, (float)width, (float)height, 0, -1, -1);
}
void __fastcall interactionUIElement_Scale_Reposition_BottomRight(void* _this, void* edx, int posx, int posy, int width, int height)
{
	auto xOffset = -((640 - posx) * UIscale);
	auto yOffset = -((480 - posy) * UIscale);
	width = (int)((float)width * UIscale);
	height = (int)((float)height * UIscale);
	posx = resW + (int)xOffset;
	posy = resH + (int)yOffset;

	uiInteractBoundary(_this, edx, posx, posy, width, height);
	createUIElementOrig((void*)((int)_this + 0x24), edx, (float)posx, (float)posy, (float)width, (float)height, 0, -1, -1);
}
void __fastcall moveUIElement(void* _this, void* edx, int posx, int posy)
{
	posx = (int)(((float)posx / 640.0f) * (float)resW);
	posy = (int)(((float)posy / 480.0f) * (float)resH);

	positionInteractionUIOrig(_this, edx, posx, posy);
	positionUIElementOrig((void*)((int)_this + 0x24), edx, (float)posx, (float)posy, 1);
}
void __fastcall moveUIElement_43(void* _this, void* edx, int posx, int posy)
{
	posx = (int)(((float)posx / 640.0f) * (float)virtualResW);
	posy = (int)(((float)posy / 480.0f) * (float)resH);

	posx += (int)(((float)resW / 2.0f) - ((float)virtualResW / 2.0f));

	positionInteractionUIOrig(_this, edx, posx, posy);
	positionUIElementOrig((void*)((int)_this + 0x24), edx, (float)posx, (float)posy, 1);
}
void __fastcall moveUIElement_Position(void* _this, void* edx, int posx, int posy)
{
	posx = (int)((float)posx * UIscale);
	posy = (int)((float)posy * UIscale);

	positionInteractionUIOrig(_this, edx, posx, posy);
	positionUIElementOrig((void*)((int)_this + 0x24), edx, (float)posx, (float)posy, 1);
}
void __fastcall placeUIElement(void* _this, void* edx, char* uiElementLabel, float width, float height, int param_4)
{
	using placeUIElementFunc = void(__fastcall*)(void*, void*, char*, float, float, int);
	placeUIElementFunc placeUIElementOrig = (placeUIElementFunc)0x00416D00;

	float adjustedWidth = ((width / 640.0f) * (float)virtualResW);
	float adjustedHeight = ((height / 480.0f) * (float)resH);

	placeUIElementOrig(_this, edx, uiElementLabel, adjustedWidth, adjustedHeight, param_4);
}
void __fastcall uiInteractBoundary(void* _this, void* edx, int posx, int posy, int width, int height)
{
	HRGN hrgn;
	*(int*)((int)_this + 0x1c) = height;
	*(int*)((int)_this + 0x18) = width;
	*(int*)((int)_this + 0x10) = posx;
	*(int*)((int)_this + 0x14) = posy;
	hrgn = CreateRectRgn(posx, posy, width + posx, height + posy);
	if (*(HGDIOBJ*)((int)_this + 4) != NULL) {
		DeleteObject(*(HGDIOBJ*)((int)_this + 4));
		*(HRGN*)((int)_this + 4) = hrgn;
	}
	else
		*(HRGN*)((int)_this + 4) = hrgn;
}
void __fastcall createTextbox(void* _this, void* edx, float posx, float posy)
{
	HRGN handle = *(HRGN*)((int)_this + 0xE10);

	posx = (posx / 640.0f) * (float)resW;
	posy = (posy / 480.0f) * (float)resH;

	if (handle != NULL)
		OffsetRgn(handle, (int)posx, (int)posy);
	createUIElementObject_AutoScale((void*)((int)_this + 0xB3C), edx, (int)posx, (int)posy);
}
void __fastcall createTextbox_43(void* _this, void* edx, float posx, float posy)
{
	HRGN handle = *(HRGN*)((int)_this + 0xE10);

	posx = (posx / 640.0f) * (float)virtualResW;
	posy = (posy / 480.0f) * (float)resH;

	posx += ((float)resW / 2.0f) - ((float)virtualResW / 2.0f);

	if (handle != NULL)
		OffsetRgn(handle, (int)posx, (int)posy);
	createUIElementObject_AutoScale_43((void*)((int)_this + 0xB3C), edx, (int)posx, (int)posy);
}
void __fastcall createTextbox_Scale_Reposition_TopLeft(void* _this, void* edx, float posx, float posy)
{
	HRGN handle = *(HRGN*)((int)_this + 0xE10);
	posy = posy * UIscale;
	posx = posx * UIscale;

	if (handle != NULL)
		OffsetRgn(handle, (int)posx, (int)posy);

	createUIElementObject_Scale((void*)((int)_this + 0xB3C), edx, (int)posx, (int)posy);
}
void __fastcall createTextboxCarat(void* _this, void* edx, int caratpos)
{
	using UnknownFunc = void(__fastcall*)(void*);
	using UnknownFunc2 = int(*)();
	UnknownFunc unknownfunction = *(UnknownFunc*)0x004FB790;
	
	int positioninstring;
	int stringlength;
	void* object = (void*)((int)_this + 0x68);
	float characterwidth = (float)*(int*)((int)_this + 0xb7c);
	int posx = *(int*)((int)_this + 0xba8);
	int posy = *(int*)((int)_this + 0xbac);
	int height = *(int*)((int)_this + 0xb54);
	
	if (*(int*)0x00696178 != caratpos) {
		*(int*)0x00696178 = caratpos;
	}
	stringlength = caratpos - *(int*)((int)_this + 0xE0C);
	if (stringlength < 0) {
		*(int*)((int)_this + 0xE0C) = *(int*)((int)_this + 0xE0C) - stringlength;
		stringlength = 0;
		unknownfunction(_this);
	}
	positioninstring = *(int*)((int)_this + 0xE08);
	if (positioninstring < stringlength) {
		*(int*)((int)_this + 0xE0C) = *(int*)((int)_this + 0xE0C) + (stringlength - positioninstring);
		unknownfunction(_this);
		stringlength = positioninstring;
	}
	
	characterwidth = (characterwidth / 640.0f) * (float)virtualResW;
	auto calculatedposx = (characterwidth * (float)stringlength) + (float)posx;
	createUIElement_AutoScale_43(object, edx, calculatedposx, (float)posy, 1.0, (float)height, 0, -1, -1);
}
void __fastcall SwfMatrixConstruct(SWFUI* _this, void* edx, D3D_MATRIX* d3dMatrix, float localX, float localY, float layerZ)
{
	using matrixMultiplyFunc = void(__stdcall*)(D3D_MATRIX*, float, float, float);
	matrixMultiplyFunc matrixMultiply = (matrixMultiplyFunc)0x00556B74;
	using unknownFunc = void(__stdcall*)(D3D_MATRIX*, D3D_MATRIX*, D3D_MATRIX*);
	unknownFunc unknownfunc = (unknownFunc)0x0055623E;

	memset(d3dMatrix, 0, sizeof(D3D_MATRIX));
	D3D_MATRIX stackMatrix = { 0 };
	
	stackMatrix.W = 1.0;
	stackMatrix.ScaleZ = 1.0;
	stackMatrix.ScaleY = 1.0;
	stackMatrix.ScaleX = 1.0;

	d3dMatrix->W = 1.0;
	d3dMatrix->ScaleZ = 1.0;
	d3dMatrix->ScaleY = 1.0;
	d3dMatrix->ScaleX = 1.0;
	
	d3dMatrix->ScaleX = _this->ScaleX;
	d3dMatrix->SkewY = _this->SkewY;
	d3dMatrix->SkewX = _this->SkewX;
	d3dMatrix->ScaleY = _this->ScaleY;
	d3dMatrix->TransX = _this->TransX;
	d3dMatrix->TransY = _this->TransY;
	
	matrixMultiply(&stackMatrix, localX, localY, layerZ);
	unknownfunc(d3dMatrix, d3dMatrix, &stackMatrix);
}
void __fastcall SwfMatrixConstruct_Stretch(SWFUI* _this, void* edx, D3D_MATRIX* d3dMatrix, float localX, float localY, float layerZ)
{
	using matrixMultiplyFunc = void(__stdcall*)(D3D_MATRIX*, float, float, float);
	matrixMultiplyFunc matrixMultiply = (matrixMultiplyFunc)0x00556B74;
	using unknownFunc = void(__stdcall*)(D3D_MATRIX*, D3D_MATRIX*, D3D_MATRIX*);
	unknownFunc unknownfunc = (unknownFunc)0x0055623E;
	
	memset(d3dMatrix, 0, sizeof(D3D_MATRIX));
	D3D_MATRIX stackMatrix = { 0 };

	float scaledUiWidth = (640.0f * SWFscaleY);
	float xOffsetTwips = (((float)resW - scaledUiWidth) / 2.0f) * PIXELS_TO_TWIPS;
	float adjustedLocalX = localX * SWFscaleY;
	float adjustedLocalY = localY * SWFscaleY;

	d3dMatrix->TransX = (_this->TransX * SWFscaleY) + xOffsetTwips;
	d3dMatrix->TransY = (_this->TransY * SWFscaleY);
	
	float screenX = d3dMatrix->TransX + (localX * SWFscaleY);
	float uiLeft = xOffsetTwips;
	float uiRight = xOffsetTwips + (640.0f * PIXELS_TO_TWIPS * SWFscaleY);

	d3dMatrix->ScaleX = _this->ScaleX;
	d3dMatrix->ScaleY = _this->ScaleY;
	d3dMatrix->ScaleZ = 1.0f;
	d3dMatrix->SkewX = _this->SkewX;
	d3dMatrix->SkewY = _this->SkewY;
	d3dMatrix->W = 1.0f;

	stackMatrix.ScaleX = 1.0f;
	stackMatrix.ScaleY = 1.0f;
	stackMatrix.ScaleZ = 1.0f;
	stackMatrix.W = 1.0f;

	matrixMultiply(&stackMatrix, adjustedLocalX, adjustedLocalY, layerZ);
	unknownfunc(d3dMatrix, d3dMatrix, &stackMatrix);
}
void __fastcall SwfMatrixConstruct_Centered(SWFUI* _this, void* edx, D3D_MATRIX* d3dMatrix, float localX, float localY, float layerZ)
{
	using matrixMultiplyFunc = void(__stdcall*)(D3D_MATRIX*, float, float, float);
	matrixMultiplyFunc matrixMultiply = (matrixMultiplyFunc)0x00556B74;
	using unknownFunc = void(__stdcall*)(D3D_MATRIX*, D3D_MATRIX*, D3D_MATRIX*);
	unknownFunc unknownfunc = (unknownFunc)0x0055623E;

	memset(d3dMatrix, 0, sizeof(D3D_MATRIX));
	D3D_MATRIX stackMatrix = { 0 };

	float xOffsetTwips = (((float)resW - (640.0f * SWFscaleY)) / 2.0f) / UIscaleY;
	
	stackMatrix.W = 1.0;
	stackMatrix.ScaleZ = 1.0;
	stackMatrix.ScaleY = 1.0;
	stackMatrix.ScaleX = 1.0;

	d3dMatrix->W = 1.0;
	d3dMatrix->ScaleZ = 1.0;
	d3dMatrix->ScaleY = 1.0;
	d3dMatrix->ScaleX = 1.0;

	d3dMatrix->ScaleX = _this->ScaleX;
	d3dMatrix->SkewY = _this->SkewY;
	d3dMatrix->SkewX = _this->SkewX;
	d3dMatrix->ScaleY = _this->ScaleY;

	d3dMatrix->TransX = _this->TransX + xOffsetTwips;
	d3dMatrix->TransY = _this->TransY;

	matrixMultiply(&stackMatrix, localX, localY, layerZ);
	unknownfunc(d3dMatrix, d3dMatrix, &stackMatrix);
}
void __fastcall SwfDrawPrimitive(void* _this, void* edx, LPDIRECT3DDEVICE8 pDevice, D3DPRIMITIVETYPE PrimitiveType, UINT StartVertex, UINT PrimitiveCount)
{
	D3DVIEWPORT8 originalViewport;
	bool viewportModified = false;
	if (SUCCEEDED(pDevice->GetViewport(&originalViewport)))
	{
		D3DVIEWPORT8 uiViewport = originalViewport;
		uiViewport.X = (DWORD)((resW - virtualResW) / 2.0f);
		uiViewport.Width = (DWORD)virtualResW;

		pDevice->SetViewport(&uiViewport);
		viewportModified = true;
	}

	pDevice->DrawPrimitive(PrimitiveType, StartVertex, PrimitiveCount);

	if (viewportModified)
		pDevice->SetViewport(&originalViewport);
}
void __fastcall SwfDrawPrimitive_Stretch(void* _this, void* edx, LPDIRECT3DDEVICE8 pDevice, D3DPRIMITIVETYPE PrimitiveType, UINT StartVertex, UINT PrimitiveCount)
{
	if (PrimitiveCount == 0)
	{
		SwfDrawPrimitive(_this, edx, pDevice, PrimitiveType, StartVertex, PrimitiveCount);
		return;
	}
	LPDIRECT3DVERTEXBUFFER8 pStreamData = nullptr;
	UINT stride = 0;
	float offsetX = ((float)resW - (640.0f * SWFscaleY)) / 2.0f;

	if (SUCCEEDED(pDevice->GetStreamSource(0, &pStreamData, &stride)))
	{
		if (stride == sizeof(TransformedVertex) && pStreamData != nullptr)
		{
			BYTE* pVertices = nullptr;
			if (SUCCEEDED(pStreamData->Lock(0, 0, &pVertices, D3DLOCK_NOOVERWRITE)))
			{
				UINT vertexCount = PrimitiveCount * 3; // Assuming triangles; adjust based on PrimitiveType
				if (PrimitiveType == D3DPT_TRIANGLESTRIP || PrimitiveType == D3DPT_TRIANGLEFAN)
					vertexCount = PrimitiveCount + 2;
				
				TransformedVertex* vertices = (TransformedVertex*)pVertices;
				for (UINT i = StartVertex; i < (StartVertex + vertexCount); ++i)
				{
					vertices[i].x = (vertices[i].x * SWFscaleX) + offsetX;
					vertices[i].y *= SWFscaleY;
				}
				pStreamData->Unlock();
			}
		}
		pStreamData->Release();
	}

	SwfDrawPrimitive(_this, edx, pDevice, PrimitiveType, StartVertex, PrimitiveCount);
}
void __fastcall SwfDrawPrimitive_Stretch_Second(void* _this, void* edx, LPDIRECT3DDEVICE8 pDevice, D3DPRIMITIVETYPE PrimitiveType, UINT StartVertex, UINT PrimitiveCount)
{
	// 1. Calculate our scaling and offset values
	float scale = (float)resH / 480.0f;
	float scaledWidth = 640.0f * scale;
	float offsetX = ((float)resW - scaledWidth) / 2.0f;

	// 2. Create a transformation matrix that will process on the GPU hardware
	D3DMATRIX scaleMatrix = {
		scale,   0.0f,    0.0f, 0.0f,
		0.0f,    scale,   0.0f, 0.0f,
		0.0f,    0.0f,    1.0f, 0.0f,
		offsetX, 0.0f,    0.0f, 1.0f  // Translation happens here
	};

	// 3. Tell D3D to apply this matrix to the vertices automatically
	// For XYZRHW vertices, we apply this to the World matrix or Texture matrix 
	// depending on how the game engine driver processes them.
	pDevice->SetTransform(D3DTS_WORLD, &scaleMatrix);

	// 4. Draw instantly (GPU handles the math, CPU does zero work)
	pDevice->DrawPrimitive(PrimitiveType, StartVertex, PrimitiveCount);

	// 5. Restore the Identity matrix so the rest of the game doesn't get distorted
	D3DMATRIX identityMatrix = {
		1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
	};
	pDevice->SetTransform(D3DTS_WORLD, &identityMatrix);
}
void __fastcall SwfGetMouseState(void* _this, void* edx, int* pOutX, int* pOutY, int* pOutClickState)
{
	using GetMouseStateFunc = void(__fastcall*)(void*, void*, int*, int*, int*);
	GetMouseStateFunc GetMouseStateOrig = (GetMouseStateFunc)0x005075D0;
	GetMouseStateOrig(_this, edx, pOutX, pOutY, pOutClickState);

	if (pOutX != nullptr && pOutY != nullptr)
	{
		float leftWall = (float)(resW - virtualResW) / 2.0f;
		float shiftedX = (float)(*pOutX) - leftWall;
		*pOutX = (int)(shiftedX / SWFscale);
		*pOutY = (int)((float)(*pOutY) / SWFscale);
	}
}
unsigned int __fastcall ButtonInteract(void* _this, void* edx, int MouseX, int MouseY, int Width, int Height)
{
	int relativeMouseX;
	int relativeMouseY;

	if (Width == -1)
		Width = *(int*)(*(int*)(*(int*)((int)_this + 0x200C) + 100) + 0x08);
	if (Height == -1)
		Height = *(int*)(*(int*)(*(int*)((int)_this + 0x200C) + 100) + 0x0C);

	relativeMouseX = MouseX - *(short*)_this;
	relativeMouseY = MouseY - *(short*)((int)_this + 2);

	if ((((-1 < relativeMouseX) && (relativeMouseX < Width)) && (-1 < relativeMouseY)) && (relativeMouseY < Height))
	{
		return (unsigned int)((*(byte*)((int)_this + (relativeMouseX >> 3) + 4 + ((Width + 7) >> 3) * relativeMouseY) & (byte)(1 << ((byte)relativeMouseX & 7))) != 0);
	}
	return (unsigned int)_this & 0xFFFFFF00;
}
unsigned int __fastcall ButtonInteract43(void* _this, void* edx, int MouseX, int MouseY, int Width, int Height)
{
	int relativeMouseX;
	int relativeMouseY;

	if (Width == -1)
		Width = *(int*)(*(int*)(*(int*)((int)_this + 0x200C) + 100) + 0x08);
	if (Height == -1)
		Height = *(int*)(*(int*)(*(int*)((int)_this + 0x200C) + 100) + 0x0C);

	float scaleX = (float)virtualResW / 640.0f;
	float scaleY = (float)resH / 480.0f;
	int scaledWidth = (int)(Width * scaleX);
	int scaledHeight = (int)(Height * scaleY);

	relativeMouseX = MouseX - *(short*)_this;
	relativeMouseY = MouseY - *(short*)((int)_this + 2);

	if ((((-1 < relativeMouseX) && (relativeMouseX < scaledWidth)) && (-1 < relativeMouseY)) && (relativeMouseY < scaledHeight))
	{
		int unscaledRelativeX = (int)(relativeMouseX / scaleX);
		int unscaledRelativeY = (int)(relativeMouseY / scaleY);

		return (unsigned int)((*(byte*)((int)_this + (unscaledRelativeX >> 3) + 4 + ((Width + 7) >> 3) * unscaledRelativeY) & (byte)(1 << ((byte)unscaledRelativeX & 7))) != 0);
	}
	return (unsigned int)_this & 0xFFFFFF00;
}
void adjustfloats(float* x, float* y)
{
	if (x)
		*x = (*x / 640.0f) * resW;
	if (y)
		*y = (*y / 480.0f) * resH;
}
void adjustfloats43(float* x, float* y)
{
	if (x)
		*x = (*x / 640.0f) * (resH * SCREEN_RATIO_4_3);
	if (y)
		*y = (*y / 480.0f) * resH;
}
void adjustfloatsN(float* x, float* y)
{
	if (x)
		*x *= UIscale;
	if (y)
		*y *= UIscale;
}
void adjustfloatsNBR(float* x, float* y)
{
	if (x)
	{
		auto xOffset = -((640.0f - *x) * UIscale);
		*x = resW + xOffset;
	}
	if (y)
	{
		auto yOffset = -((480.0f - *y) * UIscale);
		*y = resH + yOffset;
	}
}
void adjustints(int* x, int* y)
{
	if (x)
		*x = (int)(((float)*x / 640.0f) * (float)resW);
	if (y)
		*y = (int)(((float)*y / 480.0f) * (float)resH);
}
void adjustints43(int* x, int* y)
{
	if (x)
		*x = (int)(((float)*x / 640.0f) * ((float)resH * SCREEN_RATIO_4_3));
	if (y)
		*y = (int)(((float)*y / 480.0f) * (float)resH);
}
void adjustints43Center(int* x, int* y)
{
	if (x)
	{
		*x = (int)(((float)*x / 640.0f) * ((float)resH * SCREEN_RATIO_4_3));
		*x += (resW - virtualResW) / 2;
	}
	if (y)
		*y = (int)(((float)*y / 480.0f) * (float)resH);
}
void adjustintsN(int* x, int* y)
{
	if (x)
		*x = (int)((float)*x * UIscale);
	if (y)
		*y = (int)((float)*y * UIscale);
}
void adjustintsNTC(int* x, int* y)
{
	if (x)
		*x = (int)((float)*x * UIscale);
	if (y)
		*y = (int)((float)*y * UIscale);
}
void __fastcall addressbookTextbox(void* _this, void* edx, int posx, int posy)
{
	using uiInteractBoundaryFunc = void(__fastcall*)(void*, void*, int, int, int, int);
	using unknownFunc = void(__fastcall*)(void*, void*, int, int);
	using textboxFunc = void(__fastcall*)(void*, void*, float, float);
	using setInteractAreaFunc = void(__fastcall*)(void*, void*, int, int, int, int);
	uiInteractBoundaryFunc uiInteractBoundary = (uiInteractBoundaryFunc)0x004F48A0;
	unknownFunc unknown = (unknownFunc)0x004FCB40;
	textboxFunc textbox = (textboxFunc)0x004FBB10;
	setInteractAreaFunc setInteractArea = (setInteractAreaFunc)0x004FDA00;

	int* objectPosx = (int*)((int)_this + 0xAD94);
	int* objectPosy = (int*)((int)_this + 0xAD98);
	int* objectWidth = (int*)((int)_this + 0xAD9C);
	int* objectHeight = (int*)((int)_this + 0xADA0);
	void* interactObject = (void*)((int)_this + 0xADA4);
	void* unknownObject = (void*)((int)_this + 0xA75C);
	void* textboxObject = (void*)((int)_this + 0x97C4);
	void* interactAreaObject = (void*)((int)_this + 0xA5EC);

	auto scaleValue = [](int a) { return (int)((float)a * UIscale); };
	auto scaleValueF = [](float a) { return a * UIscale; };

	*objectPosx = posx + scaleValue(479);
	*objectPosy = posy + scaleValue(25);
	uiInteractBoundary(interactObject, edx, scaleValue(482), scaleValue(25), *objectWidth, *objectHeight);
	unknown(unknownObject, edx, 623, 25);
	textbox(textboxObject, edx, scaleValueF(487.0f), scaleValueF(3.0f));
	setInteractArea(interactAreaObject, edx, scaleValue(487), scaleValue(3), scaleValue(128), scaleValue(16));
}

void __declspec(naked) positionUIElement2()
{
	__asm {
		mov eax, [esp + 08h];
		push esi;
		mov esi, ecx;
		push eax;
		mov ecx, [esp + 0Ch];
		push ecx;
		mov ecx, esi;
		call_imm(004F48E0h);
		SaveECX();
		mov eax, dword ptr[esp + 0Ch];
		mov int1, eax;
		mov eax, dword ptr[esp + 08h];
		mov int2, eax;
	}

	adjustInts(&int2, &int1);

	__asm {
		RestoreECX();
		mov eax, int2;
		mov dword ptr[esp + 08h], eax;
		mov eax, int1;
		mov dword ptr[esp + 0Ch], eax;
		fild dword ptr[esp + 0Ch];
		push 01h;
		push ecx;
		fstp dword ptr[esp];
		fild dword ptr[esp + 10h];
		push ecx;
		lea ecx, [esi + 24h];
		fstp dword ptr[esp];
		call_imm(004042F0h);
		pop esi;
		ret 0008h;
	}
}
void __declspec(naked) positionUIElement3()
{
	__asm {
		SaveECX();
		mov eax, dword ptr[esp + 04h];
		mov float1, eax;
		mov eax, dword ptr[esp + 08h];
		mov float2, eax;
	}

	adjustFloats(&float1, &float2);

	__asm {
		mov eax, float1;
		mov dword ptr ds : [esp + 04h], eax;
		mov eax, float2;
		mov dword ptr ds : [esp + 08h], eax;
		RestoreECX();
		fld dword ptr ds : [esp + 04h];
		fsub dword ptr ds : [005B542Ch];
		fld dword ptr ds : [esp + 08h];
		fsub dword ptr ds : [005B542Ch];
		mov eax, ecx;
		mov ecx, dword ptr ds : [esp + 0Ch];
		cmp ecx, 04h;
		fstp dword ptr ds : [esp + 08h];
		je _00404326;
		lea ecx, dword ptr ds : [ecx + ecx * 2];
		fsub dword ptr ds : [eax + ecx * 8];
		fld dword ptr ds : [esp + 08h];
		fsub dword ptr ds : [eax + ecx * 8 + 04h];
		lea ecx, dword ptr ds : [eax + ecx * 8];
		jmp _00404343;
	_00404326:
		fld dword ptr ds : [eax + 48h];
		fadd dword ptr ds : [eax];
		fmul dword ptr ds : [005B542Ch];
		fsubp st(1), st(0);
		fld dword ptr ds : [eax + 4Ch];
		fadd dword ptr ds : [eax + 04h];
		fmul dword ptr ds : [005B542Ch];
		fsubr dword ptr ds : [esp + 08h];
	_00404343:
		mov ecx, 00000004;
	_00404348:
		fld st(1);
		fadd dword ptr ds : [eax];
		add eax, 18h;
		dec ecx;
		fstp dword ptr ds : [eax - 18h];
		fld st(0);
		fadd dword ptr ds : [eax - 14h];
		fstp dword ptr ds : [eax - 14h];
		jne _00404348;
		fstp st(0);
		fstp st(0);
		ret 000Ch;
	}
}
void __declspec(naked) adjustUI()
{
	__asm {
		push esi;
		push edi;
		mov edi, [esp + 0Ch];
		mov esi, ecx;
		fld dword ptr[edi];
		fmul dword ptr[edi + 10h];
		fld dword ptr[edi + 04h];
		fmul dword ptr[edi + 0Ch];
		fsubp st(1), st(0);
		fcom dword ptr ds : [005B53ECh];
		fnstsw ax;
		test ah, 40h;
		je _00512C4E;
		fstp st(0);
		call_imm(00512800h);
		fld dword ptr[edi + 08h];
		fchs;
		fstp dword ptr[esi + 08h];
		fld dword ptr[edi + 14h];
		mov _a1, edi;
		add _a1, 08h;
		mov _a2, edi;
		add _a2, 14h;
		SaveEAX();
		SaveECX();
		SaveEDX();
	}

	//sprintf(&textBuf[0], "%.2f, %.2f\n", *_a1, *_a2);
	//OutputDebugStringA(&textBuf[0]);

	__asm {
		RestoreEAX();
		RestoreECX();
		RestoreEDX();
		fchs;
		fstp dword ptr[esi + 14h];
		pop edi;
		pop esi;
		ret 0004h;
	_00512C4E:
		fdivr dword ptr ds : [005B53E8h];
		fld st(0);
		fmul dword ptr[edi + 10h];
		fstp dword ptr[esi];
		fld st(0);
		fmul dword ptr[edi];
		fstp dword ptr[esi + 10h];
		fld st(0);
		fmul dword ptr[edi + 04h];
		fchs;
		fstp dword ptr[esi + 04h];
		fmul dword ptr[edi + 0Ch];
		fchs;
		fstp dword ptr[esi + 0Ch];
		fld dword ptr[esi + 04h];
		fmul dword ptr[edi + 14h];
		fld dword ptr[edi + 08h];
		fmul dword ptr[esi];
		faddp st(1), st(0);
		fchs;
		fstp dword ptr[esi + 08h];
		fld dword ptr[esi + 10h];
		fmul dword ptr[edi + 14h];
		fld dword ptr[edi + 08h];
		fmul dword ptr[esi + 0Ch];
		pop edi;
		faddp  st(1), st(0);
		fchs;
		fstp dword ptr[esi + 14h];
		mov _a1, esi;
		add _a1, 08h;
		mov _a2, esi;
		add _a2, 14h;
		mov _a3, esi;
		add _a3, 0Ch;
		SaveEAX();
		SaveECX();
		SaveEDX();
	}

	//sprintf(&textBuf[0], "%.2f, %.2f, %.2f\n", *_a1, *_a2, *_a3);
	//OutputDebugStringA(&textBuf[0]);

	__asm {
		RestoreEAX();
		RestoreECX();
		RestoreEDX();
		pop esi;
		ret 0004h;
	}
}
void __declspec(naked) scaleUIElement()
{
	SaveECX();
	SaveEDX();
	__asm {
		mov eax, dword ptr ds : [esp + 0Ch];
		mov int1, eax;
		mov eax, dword ptr ds : [esp + 10h];
		mov int2, eax;
		mov eax, dword ptr ds : [ecx + 000000C4h];
		mov float1, eax;
		mov eax, dword ptr ds : [ecx + 000000CCh];
		mov float2, eax;
	}
	adjustInts(&int2, &int1);
	adjustFloats(&float2, &float1);
	RestoreECX();
	RestoreEDX();
	__asm {
		mov eax, int1;
		mov dword ptr ds : [esp + 0Ch], eax;
		mov eax, int2;
		mov dword ptr ds : [esp + 10h], eax;
		mov eax, float1;
		mov dword ptr ds : [ecx + 000000C4h], eax;
		mov eax, float2;
		mov dword ptr ds : [ecx + 000000CCh], eax;
		mov eax, dword ptr ds : [esp + 04h];
		mov edx, dword ptr ds : [esp + 08h];
		fild dword ptr[esp + 0Ch]; // X
		mov[ecx + 000000ACh], eax;
		mov eax, [esp + 0Ch]; // X
		mov[ecx + 000000B0h], edx;
		mov edx, [esp + 10h];	// Y
		mov[ecx + 000000B4h], eax;
		mov[ecx + 000000B8h], edx;
		fld dword ptr[ecx + 000000C4h]; // X * 20
		fsub dword ptr[ecx + 000000C0h];
		fmul dword ptr ds : [00605590h];
		fdivp st(1), st(0);
		fild dword ptr[esp + 10h]; // Y
		fld dword ptr[ecx + 000000CCh]; // Y * 20
		fsub dword ptr[ecx + 000000C8h];
		fmul dword ptr ds : [00605590h];
		fdivp st(1), st(0);
		fstp dword ptr[esp + 0Ch]; // X
		fcom dword ptr[esp + 0Ch];
		fnstsw ax;
		test ah, 01h;
		je _005084E6;
		mov eax, [esp + 0Ch];
		fstp st(0);
		mov[ecx + 000000BCh], eax;
		ret 0010h;
	_005084E6:
		fstp dword ptr[ecx + 000000BCh];
		ret 0010h;
	}
}
void __fastcall placeString(void* obj, int unused, int x, int y)
{
	int adjustX = (int)(((float)x / 640.0f) * resW);
	int adjustY = (int)(((float)y / 480.0f) * resH);

	placeStringGame(obj, unused, adjustX, adjustY);
}
void __fastcall placeStringLeftAlign(void* obj, int unused, int x, int y)
{
	int adjustX = x;
	int adjustY = (int)(((float)y / 480.0f) * resH);

	placeStringGame(obj, unused, adjustX, adjustY);
}
void __fastcall placeStringRightAlign(void* obj, int unused, int x, int y)
{
	int adjustX = resW - (640 - x);
	int adjustY = (int)(((float)y / 480.0f) * resH);

	placeStringGame(obj, unused, adjustX, adjustY);
}
void __declspec(naked) exitFix()
{
	__asm
	{
		mov eax, dword ptr ds : [ebp - 3Ch];
		cmp eax, WM_CLOSE;
		je _sbolexit;
		cmp eax, WM_QUIT;
		je _sbolexit;
		cmp eax, WM_DESTROY;
		je _sbolexit;
		cmp eax, WM_NCLBUTTONDOWN;
		je _countClose;
		mov isClosed, 0;
	_loop:
		jmp_imm(0041C1CDh);
	_sbolexit:
		jmp_imm(0041C214h);
	_countClose:
		mov eax, isClosed;
		inc eax;
		mov isClosed, eax;
		cmp eax, 30;
		je _sbolexit;
		jmp _loop;
	}
}
void __declspec(naked) getTireBrakePrice()
{
	__asm
	{
		movsx eax, byte ptr ds : [esi + 6];
		push eax;
		mov ecx, edi;
		call getPFileTireBrakePriceMultipler;
		movsx ecx, bl;
		push ecx;
		mov ecx, edi;
		mov ebp, eax;
		call getPFileTireBrakePrice;
		movsx edx, byte ptr ds : [esi + 6];
		xor ecx, ecx;
		pop edi;
		mov cx, word ptr ds : [eax + edx * 2];
		pop esi;
		mov eax, ecx;
		imul eax, ebp;
		pop ebp;
		pop ebx;
		ret;
	}
}
void __declspec(naked) getPFileTireBrakePriceMultipler()
{
	__asm
	{	// Default multiplier for tires and brakes is 0 in file so hardcoding return of 1. Can edit P.DAT in future
		//mov eax, dword ptr ds : [ecx + 04h];
		//lea ecx, dword ptr ds : [eax + eax * 4];
		//lea ecx, dword ptr ds : [eax + ecx * 8];
		//lea edx, dword ptr ds : [ecx + ecx * 4];
		//mov ecx, dword ptr ds : [esp + 04];
		//lea eax, dword ptr ds : [eax + edx * 4];
		//lea edx, dword ptr ds : [ecx + eax * 2];
		//mov ecx, dword ptr ds : [006FB758h];
		//mov ax, word ptr ds : [ecx + edx * 2 + 00000C70h];
		mov eax, 00000001h;
		ret 0004h;
	}
}
void __declspec(naked) getPFileTireBrakePrice()
{
	__asm
	{
		mov eax, dword ptr ds : [ecx + 04];
		lea ecx, dword ptr ds : [eax + eax * 4];
		lea ecx, dword ptr ds : [eax + ecx * 8];
		lea edx, dword ptr ds : [ecx + ecx * 4];
		lea ecx, dword ptr ds : [eax + edx * 4];
		mov eax, dword ptr ds : [esp + 04]; // Selection
		mov edx, 0Ah; // TireBrake Entry Size
		imul eax, edx;
		mov edx, eax;
		mov eax, dword ptr ds : [006FB758h];
		lea edx, dword ptr ds : [eax + edx];
		lea eax, dword ptr ds : [edx + ecx * 4 + 000000C70h]; // TireBrake Offset
		ret 0004;
	}
}
void __declspec(naked) setTexturePositions()
{
	SaveECX();
	__asm {
		mov eax, [esp + 04h];
		mov int1, eax;
		mov eax, [esp + 08h];
		mov int2, eax;
	}
	int1 = (resW / 2) - (320 - (int1));
	int2 = (resH / 2) - (240 - (int2));
	RestoreECX();
	__asm {
		mov eax, int1;
		push esi;
		mov esi, ecx;
		mov ecx, int2;
		mov dword ptr ds : [esi + 18h], ecx;
		mov dword ptr ds : [esi + 14h], eax;
		add ecx, 00000090h;
		add eax, 0Ch;
		push ecx;
		mov ecx, dword ptr ds : [esi + 00015CB4h];
		push eax;
		call_imm(004FD760h);
		mov eax, dword ptr ds : [esi + 18h];
		mov ecx, dword ptr ds : [esi + 14h];
		add eax, 000000A0h;
		add ecx, 0Ch;
		push eax;
		push ecx;
		mov ecx, dword ptr ds : [esi + 00015CB8h];
		call_imm(004FD760h);
		push 000000F8h;
		push 38h;
		lea ecx, dword ptr ds : [esi + 00018760h];
		call_imm(0045B600h);
		pop esi;
		ret 0008h;
	}
}
void __declspec(naked) setItemUsePosition()
{
	__asm {
		mov eax, itemUseDialogY;
		push eax;
		mov eax, itemUseDialogX;
		push eax;
		mov ecx, ebp;
		call_imm(0045D6B0h);
		ret;
	}
}
void __declspec(naked) drawString()
{
	__asm {
		sub esp, 28h;
		mov eax, dword ptr ds : [esp + 2Ch];
		push esi;
		mov esi, ecx;
		mov ecx, dword ptr ds : [esp + 34h];
		mov dword ptr ds : [esi + 6Ch], eax;
		mov eax, dword ptr ds : [esi + 60h];
		mov dword ptr ds : [esi + 70h], ecx;
		lea ecx, dword ptr ds : [esp + 0Ch];
		mov edx, dword ptr ds : [eax];
		push ecx;
		push 00h;
		push eax;
		call dword ptr[edx + 38h];
		mov edx, dword ptr ds : [esp + 28h];
		mov eax, dword ptr ds : [esp + 24h];
		push 0FFh;
		mov dword ptr ds : [esp + 08h], edx;
		mov dword ptr ds : [esp + 0Ch], 00000000;
		push 0FFh;
		fild qword ptr[esp + 0Ch];
		push 00h;
		push ecx;
		mov dword ptr ds : [esp + 14h], eax;
		mov dword ptr ds : [esp + 18h], 00000000;
		fstp dword ptr[esp];
		fild qword ptr[esp + 14h];
		push ecx;
		fstp dword ptr[esp];
		fild dword ptr[esi + 70h];
		push ecx;
		fstp dword ptr[esp];
		fild dword ptr[esi + 6Ch];
		push ecx;
		lea ecx, dword ptr ds : [esi + 78h];
		fstp dword ptr[esp];
		call createUIElement;
		pop esi;
		add esp, 28h;
		ret 0008h;
	}
}
void __declspec(naked) directxScene()
{
	_asm {
		mov edx, dword ptr ds : [00630E08h]; // Clear colour
		mov eax, dword ptr ds : [006EAAE0h]; // Direct 3D Device
		push 00h;
		push 3F800000h;
		mov ecx, dword ptr ds : [eax];
		push edx;
		push 03h;
		push 00h;
		push 00h;
		push eax;
		call dword ptr ds : [ecx + 00000090h];
		mov eax, dword ptr ds : [006EAAE0h];
		push eax;
		mov ecx, dword ptr ds : [eax];
		call dword ptr ds : [ecx + 00000088h];
		test eax, eax;
		jnge _cleanup;
		SaveECX();
	}
	directxCustom();
	//call directxCustom;
	__asm {
		RestoreECX();
		mov ecx, dword ptr ds : [006EBA30h];
		call_imm(00416A90h);
		mov ecx, dword ptr ds : [006EBBF4h];
		call_imm(004E8F30h);
		mov ecx, dword ptr ds : [006EBBF0h];
		call_imm(004E1910h);
		call_imm(00404FD0h);
		mov eax, dword ptr ds : [006EAAE0h];
		push eax;
		mov edx, dword ptr ds : [eax];
		call dword ptr[edx + 0000008Ch];
	_cleanup:
		call_imm(00405020h);
		mov ecx, dword ptr ds : [esp + 04h];
		call_imm(0041BA10h);
		push 00h;
		push 02h;
		push 006F7FD0h;
		call_imm(0051FA90h);
		add esp, 0Ch;
		ret;
	}
}
void __declspec(naked) adjustXAxis()
{
	__asm {
		mov eax, dword ptr ds : [eax + ecx + 00000248h];
		mov int1, eax;
	}
	adjustXAxisValue(&int1);
	__asm {
		mov eax, int1;
		ret;
	}
}
void __declspec(naked) directxReturn()
{
	__asm {
		call_imm(00404FD0h);
		ret;
	}
}
void adjustFloats(float* x, float* y)
{
	/*
	if (x) *x = (float)floor((*x / 640.0f) * resW);
	if (y) *y = (float)floor((*y / 480.0f) * resH);
	*/
	if (x) *x = (float)(((double)*x / 640.0) * resW);
	if (y) *y = (float)(((double)*y / 480.0) * resH);
}
void adjustInts(int* x, int* y)
{
	/*
	if (x) *x = (int)((*x / 640.0f) * resW);
	if (y) *y = (int)((*y / 480.0f) * resH);
	*/
	if (x) *x = (int)(((double)*x / 640.0) * resW);
	if (y) *y = (int)(((double)*y / 480.0) * resH);

}
void adjustXAxisValue(int* x)
{
	//if (*x < 100 && *x > -100 && *x != 0)
	//	*x = 0;
#ifdef _DEBUG
	int2 = *x;
#endif
	if ((*x > 0 && *x < 75) || (*x < 0 && *x > -75))
		*x = 0;
	else if ((*x > 0 && *x < 100) || (*x < 0 && *x > -100))
		*x = (int)((double)*x * 0.1);
	else if ((*x > 0 && *x < 300) || (*x < 0 && *x > -300))
		*x = (int)((double)*x * 0.3);
	else if ((*x > 0 && *x < 600) || (*x < 0 && *x > -600))
		*x = (int)((double)*x * 0.6);
	else if ((*x > 0 && *x < 800) || (*x < 0 && *x > -800))
		*x = (int)((double)*x * 0.8);
#ifdef _DEBUG
	snprintf(logItBuf, sizeof(logItBuf), "X Axis: %d, Adjusted: %d\n", int2, *x);
	OutputDebugStringA(logItBuf);
#endif
}
void NOPSpace(unsigned location, unsigned int count)
{
	__asm {
		mov edi, location;
		mov ecx, count;
		mov eax, 0x90;
		rep stosb;
	}
}
void insertFunction(int addrPtr, void* function, int nopCount, functionType ft)
{
	unsigned char FT = 0xE9;
	if (ft == FT_CALL) FT = 0xE8;
	NOPSpace(addrPtr, nopCount);
	*(int*)(addrPtr + 1) = ((int)function - addrPtr) - 5;
	*(unsigned char*)addrPtr = FT;
}
void setFunction(int addrPtr, void* function)
{
	*(int*)(addrPtr) = ((int)function);
}