#include "asm.h"

extern int resW;
extern int resH;
extern int fullScreen;
extern int skipWarning;
extern unsigned char* itemFile;
extern int itemFileSize;
extern float UIdividerX;
extern float UIdividerY;
extern float UIscaleX;
extern float UIscaleY;
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

void __declspec(naked) positionUIElement()
{
	__asm {
		SaveEAX();
		SaveECX();
		mov edx, dword ptr ds : [esp + 10h];
		mov float2, edx;
		mov edx, dword ptr ds : [esp + 0ch];
		mov float3, edx;
	}

	adjustFloats(&float3, &float2);

	__asm {
		mov edx, dword ptr ds : [esp + 08h];
		mov float4, edx;
		mov edx, dword ptr ds : [esp + 04h];
		mov float5, edx;
	}

	adjustFloats(&float5, &float4);

	__asm {
		mov eax, float2;
		mov dword ptr ds : [esp + 10h], eax;
		mov eax, float3;
		mov dword ptr ds : [esp + 0ch], eax;
		mov eax, float4;
		mov dword ptr ds : [esp + 08h], eax;
		mov eax, float5;
		mov dword ptr ds : [esp + 04h], eax;
		mov edx, dword ptr ds : [esp + 18h];
		RestoreEAX();
		or eax, 0FFFFFFFFh;
		cmp edx, eax;
		fld dword ptr ds : [esp + 04h];
		jne _00404267;
		fsub dword ptr ds : [005B542Ch];
		jmp _00404279;
	_00404267:
		fild dword ptr ds : [esp + 18h];
		fdivr dword ptr ds : [esp + 0Ch];
		fdivr dword ptr ds : [005B542Ch];
		fsubr dword ptr ds : [esp + 04h];
	_00404279:
		mov edx, dword ptr ds : [esp + 1Ch];
		fstp dword ptr ds : [esp + 04h];
		cmp edx, eax;
		jne _00404291;
		fld dword ptr ds : [esp + 08h];
		fsub dword ptr ds : [005B542Ch];
		jmp _004042A3;
	_00404291:
		fild dword ptr ds : [esp + 1Ch];
		fdivr dword ptr ds : [esp + 10h];
		fdivr dword ptr ds : [005B542Ch];
		fsubr dword ptr ds : [esp + 08h];
	_004042A3:
		fld st(0);
		fadd dword ptr ds : [esp + 10h];
		mov eax, dword ptr ds : [esp + 04h];
		mov edx, dword ptr ds : [esp + 14h];
		RestoreECX();
		mov dword ptr ds : [ecx], eax;
		mov dword ptr ds : [ecx + 18h], eax;
		mov dword ptr ds : [ecx + 08h], edx;
		mov dword ptr ds : [ecx + 20h], edx;
		fst dword ptr ds : [ecx + 04h];
		mov eax, dword ptr ds : [ecx + 04h];
		fld st(1);
		mov eax, edx;
		fstp dword ptr ds : [ecx + 1Ch];
		fld dword ptr ds : [esp + 04h];
		fadd dword ptr ds : [esp + 0Ch];
		mov dword ptr ds : [ecx + 38h], eax;
		mov dword ptr ds : [ecx + 50h], eax;
		fst dword ptr ds : [esp + 04h];
		fstp dword ptr ds : [ecx + 30h];
		mov edx, dword ptr ds : [esp + 04h];
		fstp dword ptr ds : [ecx + 34h];
		mov dword ptr ds : [ecx + 48h], edx;
		fstp dword ptr ds : [ecx + 4Ch];
		ret 001Ch;
	}
}
void __declspec(naked) logPositionUIElement()
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

	//debugIt("%u, %u", int2, int1);

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
		call positionUIElement; // positionUIElement
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
	if (x) *x = (float)floor((*x / 640.0f) * resW);
	if (y) *y = (float)floor((*y / 480.0f) * resH);
}
void adjustInts(int* x, int* y)
{
	if (x) *x = (int)((*x / 640.0f) * resW);
	if (y) *y = (int)((*y / 480.0f) * resH);
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
		*x *= 0.1;
	else if ((*x > 0 && *x < 300) || (*x < 0 && *x > -300))
		*x *= 0.3;
	else if ((*x > 0 && *x < 600) || (*x < 0 && *x > -600))
		*x *= 0.6;
	else if ((*x > 0 && *x < 800) || (*x < 0 && *x > -800))
		*x *= 0.8;
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
	*(int*)(addrPtr) = ((int)function - addrPtr) - 4;
}