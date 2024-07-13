#pragma once
#define MAX_MESG_LEN	4096
#define DEBUG_LOG

struct FontObject {
	HGDIOBJ _hgdiobj1;
	HGDIOBJ _hgdiobj2;
	HDC _hdc;
	char buffer[0x200];
};

HFONT bgmHFont = CreateFont(
	-10,
	0,
	0,
	0,
	FW_NORMAL,
	0,
	0,
	0,
	SHIFTJIS_CHARSET,
	OUT_CHARACTER_PRECIS,
	CLIP_CHARACTER_PRECIS,
	NONANTIALIASED_QUALITY,
	MONO_FONT,
	TEXT("ＭＳ ゴシック")
);