#pragma once
int* resWidth[]{
	(int*)0x004122E6, // Window Width after start
	(int*)0x0041251B, // Window Width after start
	(int*)0x004A68C5, // 3d window width in game
	(int*)0x005C1684, // Window Width on start
	
	// Other 3d windows
	(int*)0x00452CE1,
	(int*)0x00453E7E,
	(int*)0x00453F43,
	(int*)0x00455386,
	(int*)0x004571BC,
	(int*)0x00458C3F,
	(int*)0x004631A6,
	(int*)0x00464F2F,
	(int*)0x00480E60,
	(int*)0x00482014,
	(int*)0x004879B3,
	(int*)0x00490498,
	(int*)0x004ACC73,
	(int*)0x004B00D7,
};

float* resWidthF[]{
	(float*)0x004E601D,
	(float*)0x0045CEB0, // Item black back
	(float*)0x004BC492, // Garage black back
	(float*)0x00434957,
	(float*)0x0045A6FA,
	(float*)0x0045B7CB,
	(float*)0x00470C01,
	(float*)0x0048A257,
	(float*)0x0049C78C,
	(float*)0x0049D2C2,
	//(float*)0x004E2451, // ?
	//(float*)0x004E27AE, // ?
	//(float*)0x004E33BD, // ?
	//(float*)0x004E3478, // ?
	//(float*)0x004E34C5, // ?
	//(float*)0x004E34E3, // ?
	//(float*)0x004E3501,	// ?
	//(float*)0x004E351F,	// ?
	//(float*)0x004E353D,	// ?
	//(float*)0x004E355B,	// ?
	//(float*)0x004E3579,	// ?
	//(float*)0x004E3597,	// ?
	//(float*)0x004E35B5,	// ?
	//(float*)0x004E35D3,	// ?
	//(float*)0x004E35F1,	// ?
	//(float*)0x004E360F,	// ?
	//(float*)0x004E362D,	// ?
	//(float*)0x004E364B,	// ?
	//(float*)0x004E5F52,	// ?
	//(float*)0x004E5FB3,	// ?
	//(float*)0x004E6057,	// ?
	//(float*)0x004F6C7C	// ?
};

int* resHeight[]{
	(int*)0x004122F6, // Window Height after start
	(int*)0x00412524, // Window Height after start
	(int*)0x004A68D0, // 3d window height in game
	(int*)0x005C1688, // Window Height on start

	// Other 3d windows
	(int*)0x00452CDC,
	(int*)0x00453E79,
	(int*)0x00453F3E,
	(int*)0x00455381,
	(int*)0x004571B7,
	(int*)0x00458C3A,
	(int*)0x004631A1,
	(int*)0x00464F2A,
	(int*)0x00480E5B,
	(int*)0x0048200F,
	(int*)0x004879A4,
	(int*)0x00490493,
	(int*)0x004ACC6E,
	(int*)0x004B00D2,
};

float* resHeightF[]{
	(float*)0x0045CEA5, // Item black back
	(float*)0x004BC487,	// Garage black back
	(float*)0x0043494C,
	(float*)0x0045A6F5,
	(float*)0x0045B7C0,
	(float*)0x00470BFC,
	(float*)0x0048A252,
	(float*)0x0049C787,
	(float*)0x0049D2BD,
	//(float*)0x00
	//(float*)0x00
	//(float*)0x00
	//(float*)0x00
};

int* centerJust[]{
	(int*)0x004DC601,
	(int*)0x004DC9A4,
	(int*)0x004DC3D9, // Garage dialog
	(int*)0x00443688, // Quit dialog
	(int*)0x0042661B, // Error dialog
	(int*)0x004263B8, // Error text
};

int* centerJustV[]{
	(int*)0x004DC3D4, // Garage dialog
	(int*)0x00443683, // Quit dialog
	(int*)0x00426623, // Error dialog
	(int*)0x004263B3, // Error text
};

int* rightJust[] {
	(int*)0x004DBBF6,
	(int*)0x004DBDAB,
	(int*)0x004DB509,
	(int*)0x004DB515,
	(int*)0x004DB521,
};

int* bottomJust[]{
	(int*)0x004DBCE9,
	(int*)0x004DB501,
	(int*)0x004D84D1,
	(int*)0x004D5CAD,
	(int*)0x004D5CFF,
	(int*)0x004D5D76,
	(int*)0x004D5DD4,
	(int*)0x004D5E23,
	(int*)0x004ABF7D,
	(int*)0x004DC60B,
	(int*)0x004DC9AB,
};

float* centerJustF[]{
	(float*)0x004DC9D1,
};

float* rightJustF[]{
	(float*)0x004DB217,
	(float*)0x004DB59F,
	(float*)0x004DB786,
	(float*)0x004DB82D,
	(float*)0x005F36F8,
	(float*)0x004DB939,
	(float*)0x004DB975,
	(float*)0x004DB9B1
};

float* bottomJustF[]{
	(float*)0x004DB212,
	(float*)0x004DB59A,
	(float*)0x004DB781,
	(float*)0x004DB828,
	(float*)0x004DBB16,
	(float*)0x004DBB74,
	(float*)0x004D5BA3,
	(float*)0x004D5BF2,
	(float*)0x004D5C41,
	(float*)0x004DC9CC,
	(float*)0x005F36F4,
	(float*)0x004DB934,
	(float*)0x004DB970,
	(float*)0x004DB9AC
};

//int* repositionAddr[]{
//	(int*)(0x0043F75A), // Loading Screen
//	(int*)(0x0045CEBA), // Itembox
//};

int* repositionAddr[]{
	//(int*)(0x004DBB8C),		  // Not battle related
	//(int*)(0x004265B0 + 0x25E), // Not battle related
	//(int*)(0x004265B0 + 0x2E9), // Not battle related
	//(int*)(0x00434910 + 0x17E), // Not battle related
	//(int*)(0x00434910 + 0x24F), // Not battle related
	//(int*)(0x00434910 + 0x3BB), // Not battle related
	//(int*)(0x00434910 + 0x40B), // Not battle related
	//(int*)(0x00434910 + 0x4AB), // Not battle related
	//(int*)(0x00434910 + 0x58),  // Not battle related
	//(int*)(0x00434910 + 0x590), // Not battle related
	//(int*)(0x00434910 + 0x5DF), // Not battle related
	//(int*)(0x00434910 + 0x62E), // Not battle related
	//(int*)(0x00434910 + 0x911), // Not battle related
	//(int*)(0x00434910 + 0x98E), // Not battle related
	//(int*)(0x00434910 + 0xA73), // Not battle related
	//(int*)(0x00434910 + 0xAD1), // Not battle related
	//(int*)(0x00434910 + 0xB17), // Not battle related
	//(int*)(0x00434910 + 0xB58), // Not battle related
	//(int*)(0x00434910 + 0xB9D), // Not battle related
	//(int*)(0x00434910 + 0xD34), // Not battle related
	//(int*)(0x00434910 + 0xD83), // Not battle related
	//(int*)(0x00434910 + 0xDD2), // Not battle related
	//(int*)(0x00434910 + 0xE21), // Not battle related
	//(int*)(0x00434910 + 0xE9F), // Not battle related
	//(int*)(0x004389F0 + 0x2A5), // Not battle related
	//(int*)(0x004389F0 + 0x2D1), // Not battle related
	(int*)(0x0043F4B0 + 0x2AA), // Loading Screen
	//(int*)(0x00440460 + 0x2AA), // Not battle related
	//(int*)(0x00440460 + 0x332), // Not battle related
	//(int*)(0x0044F2E0 + 0x5DB), // Not battle related
	//(int*)(0x0044F2E0 + 0x8B9), // Not battle related
	//(int*)(0x0044F2E0 + 0x98D), // Not battle related
	//(int*)(0x0044F2E0 + 0xA06), // Not battle related
	//(int*)(0x0044F2E0 + 0xA6F), // Not battle related
	//(int*)(0x0044F2E0 + 0xB51), // Not battle related
	//(int*)(0x0044F2E0 + 0xE41), // Not battle related
	//(int*)(0x0044F2E0 + 0xEE7), // Not battle related
	//(int*)(0x00450460 + 0x114), // Not battle related
	//(int*)(0x00450460 + 0x55F), // Not battle related
	//(int*)(0x004510D0 + 0x477), // Not battle related
	//(int*)(0x004510D0 + 0x5B3), // Not battle related
	//(int*)(0x004510D0 + 0x6C1), // Not battle related
	//(int*)(0x004510D0 + 0x7CF), // Not battle related
	//(int*)(0x004510D0 + 0x88F), // Not battle related
	//(int*)(0x004510D0 + 0x91B), // Not battle related
	//(int*)(0x004510D0 + 0x995), // Not battle related
	//(int*)(0x004510D0 + 0xA10), // Not battle related
	//(int*)(0x004510D0 + 0xA6E), // Not battle related
	//(int*)(0x004510D0 + 0xAE8), // Not battle related
	//(int*)(0x004510D0 + 0xB9F), // Not battle related
	//(int*)(0x00452030 + 0x1BA), // Not battle related
	//(int*)(0x00452030 + 0x868), // Not battle related
	//(int*)(0x00452030 + 0xD51), // Not battle related
	//(int*)(0x00454450 + 0x192), // Not battle related
	//(int*)(0x00454450 + 0x1D6), // Not battle related
	//(int*)(0x0045A510 + 0x209), // Not battle related
	//(int*)(0x0045A510 + 0x31D), // Not battle related
	//(int*)(0x0045A510 + 0x4A3), // Not battle related
	//(int*)(0x0045A510 + 0x51C), // Not battle related
	//(int*)(0x0045A510 + 0x5BF), // Not battle related
	//(int*)(0x0045A510 + 0x69F), // Not battle related
	//(int*)(0x0045ADB0 + 0x211), // Not battle related
	//(int*)(0x0045ADB0 + 0x300), // Not battle related

	(int*)(0x0045B660 + 0x177), // Item Use
	(int*)(0x0045B660 + 0x287), // Item Use
	(int*)(0x0045B660 + 0x3FE), // Item Use
	(int*)(0x0045B660 + 0x47A), // Item Use
	(int*)(0x0045B660 + 0x558), // Item Use
	(int*)(0x0045BC90 + 0xA0), // Item Use Cancel
	(int*)(0x0045BC90 + 0xF3), // Item Use Cancel
	(int*)(0x0045C1A0 + 0xB0), // Item Use Image
	(int*)(0x0045C270 + 0xE9), // Item Use Image
	(int*)(0x0045CE90 + 0x2A), // Item Box Black Back
	(int*)(0x0045D710 + 0x190),  // Item Box Frame
	(int*)(0x0045D710 + 0x20A),  // Item Box Frame
	(int*)(0x0045D710 + 0x2B5),  // Item Box Frame
	(int*)(0x0045D710 + 0x331),  // Item Box Frame
	(int*)(0x0045D710 + 0x3D3),  // Item Box Frame
	(int*)(0x0045D710 + 0xE1),   // Item Box Frame
	(int*)(0x0045DB50 + 0x9D),	 // Item Box Items Back
	(int*)(0x0045DDF0 + 0xFF),   // Item Box Items ???
	(int*)(0x0045DF20 + 0x193),  // Item Box Items ???
	(int*)(0x0045E130 + 0xEC),	 // Item Box Item Icon
	(int*)(0x0045E250 + 0xB7),	 // Item Box Item Name
	(int*)(0x0045F2D0 + 0x97),   // Item Box Close Button
	(int*)(0x0046F5D0 + 0x1DB),	 // Item Box Close Button
	(int*)(0x0046F5D0 + 0x2D7),	 // Item Box Close Button
	(int*)(0x0046F5D0 + 0x401),	 // Item Box Close Button
	//(int*)(0x004FD760 + 0x6B),	 // Draw String
	//(int*)(0x0046FCE0 + 0x240),	// Not battle related
	//(int*)(0x0046FCE0 + 0x376),	// Not battle related
	//(int*)(0x0046FCE0 + 0x4B7),	// Not battle related
	//(int*)(0x0046FCE0 + 0x55C),	// Not battle related
	//(int*)(0x00470800 + 0x420),	// Not battle related
	//(int*)(0x00470800 + 0x543),	// Not battle related
	//(int*)(0x00470800 + 0x5E0),	// Not battle related
	//(int*)(0x00470800 + 0x6BF),	// Not battle related
	//(int*)(0x00470800 + 0x7A5),	// Not battle related
	//(int*)(0x00470800 + 0x8B6),	// Not battle related
	//(int*)(0x00470800 + 0x9B1),	// Not battle related
	//(int*)(0x00470800 + 0xA65),	// Not battle related
	//(int*)(0x00470800 + 0xAFA),	// Not battle related
	//(int*)(0x00470800 + 0xB63),	// Not battle related
	//(int*)(0x00470800 + 0xC06),	// Not battle related
	//(int*)(0x00470800 + 0xCD3),	// Not battle related
	//(int*)(0x00470800 + 0xD4B),	// Not battle related
	//(int*)(0x00470800 + 0xDB5),	// Not battle related
	//(int*)(0x00470800 + 0xE1E),	// Not battle related
	//(int*)(0x00470800 + 0xE87),	// Not battle related
	//(int*)(0x004717F0 + 0x22F4),	// Not battle related
	//(int*)(0x004717F0 + 0x28FA),	// Not battle related
	//(int*)(0x004717F0 + 0x3C9C),	// Not battle related
	//(int*)(0x004717F0 + 0x425C),	// Not battle related
	//(int*)(0x004717F0 + 0x42C7),	// Not battle related
	//(int*)(0x004717F0 + 0x4391),	// Not battle related
	//(int*)(0x004717F0 + 0x4452),	// Not battle related
	//(int*)(0x004717F0 + 0x451F),	// Not battle related
	//(int*)(0x004717F0 + 0x45CD),	// Not battle related
	//(int*)(0x00477520 + 0x327),	// Not battle related
	//(int*)(0x00477520 + 0x39F),	// Not battle related
	//(int*)(0x00477520 + 0x442),	// Not battle related
	//(int*)(0x00477520 + 0x4E7),	// Not battle related
	//(int*)(0x00477520 + 0x5A4),	// Not battle related
	//(int*)(0x00477520 + 0x673),	// Not battle related
	//(int*)(0x00478810 + 0x289),	// Not battle related
	//(int*)(0x00478810 + 0x31A),	// Not battle related
	//(int*)(0x00478810 + 0x3C1),	// Not battle related
	//(int*)(0x00478810 + 0x54C),	// Not battle related
	//(int*)(0x00478E30 + 0x60),	// Not battle related
	//(int*)(0x0047A320 + 0x280),	// Not battle related
	//(int*)(0x0047A320 + 0x328),	// Not battle related
	//(int*)(0x0047A320 + 0x3DB),	// Not battle related
	//(int*)(0x0047A320 + 0x596),	// Not battle related
	//(int*)(0x0047B1C0 + 0x202),	// Not battle related
	//(int*)(0x0047B1C0 + 0x2EA),	// Not battle related
	//(int*)(0x0047B1C0 + 0x3F5),	// Not battle related
	//(int*)(0x0047B1C0 + 0x496),	// Not battle related
	//(int*)(0x0047DDA0 + 0x28C),	// Not battle related
	//(int*)(0x0047DDA0 + 0x325),	// Not battle related
	//(int*)(0x0047DDA0 + 0x3CD),	// Not battle related
	//(int*)(0x0047DDA0 + 0x4FF),	// Not battle related
	//(int*)(0x00484400 + 0x4E8),	// Not battle related
	//(int*)(0x00484400 + 0x61D),	// Not battle related
	//(int*)(0x00484400 + 0x755),	// Not battle related
	//(int*)(0x00484400 + 0x888),	// Not battle related
	//(int*)(0x00484400 + 0x9DA),	// Not battle related
	//(int*)(0x00484400 + 0xAC5),	// Not battle related
	//(int*)(0x00484400 + 0xBAE),	// Not battle related
	//(int*)(0x00484400 + 0xC1C),	// Not battle related
	//(int*)(0x00484400 + 0xD89),	// Not battle related
	//(int*)(0x00484400 + 0xDD1),	// Not battle related
	//(int*)(0x004859F0 + 0x1AC),	// Not battle related  
	//(int*)(0x004859F0 + 0x68),	// Not battle related
	//(int*)(0x00486880 + 0x13A),	// Not battle related
	//(int*)(0x00486A10 + 0x2AC),	// Not battle related
	//(int*)(0x00486A10 + 0x362),	// Not battle related
	//(int*)(0x00487EB0 + 0x1FF),	// Not battle related
	//(int*)(0x00488780 + 0x33D),	// Not battle related
	//(int*)(0x00489310 + 0x295),	// Not battle related
	//(int*)(0x00489310 + 0x332),	// Not battle related
	//(int*)(0x00489310 + 0x3E3),	// Not battle related
	//(int*)(0x00489310 + 0x514),	// Not battle related
	//(int*)(0x0048A020 + 0x25C),	// Not battle related
	//(int*)(0x0048A020 + 0x382),	// Not battle related
	//(int*)(0x0048A020 + 0x441),	// Not battle related
	//(int*)(0x0048A020 + 0x53B),	// Not battle related
	//(int*)(0x0048A020 + 0x5E1),	// Not battle related
	//(int*)(0x0048A020 + 0x690),	// Not battle related
	//(int*)(0x0048A020 + 0x76C),	// Not battle related
	//(int*)(0x0048A820 + 0x105F),	// Not battle related
	//(int*)(0x0048A820 + 0x114B),	// Not battle related
	//(int*)(0x0048A820 + 0x1651),	// Not battle related
	//(int*)(0x0048A820 + 0x16D8),	// Not battle related
	//(int*)(0x0048A820 + 0x177E),	// Not battle related
	//(int*)(0x0048A820 + 0x1870),	// Not battle related
	
	(int*)(0x0048C940 + 0x4C),	// Battle Win/Lose Texture
	(int*)(0x0048C940 + 0xB7),	// Battle Win/Lose Texture
	(int*)(0x0048CB60 + 0x3DF),	// Battle Result Value Labels
	(int*)(0x0048CB60 + 0x644),	// Battle Result Value Labels
	(int*)(0x0048CB60 + 0x759),	// Battle Result Value Labels	
	(int*)(0x0048D520 + 0x176),	// Battle Exp Percent Bar
	(int*)(0x0048D780 + 0x22F),	// Battle Something probably so will leave it enabled
	(int*)(0x0048D780 + 0x36A),	// Battle Something probably so will leave it enabled
	(int*)(0x0048D780 + 0x435),	// Battle Something probably so will leave it enabled  
	(int*)(0x0048DD60 + 0x193), // Itembox (not in course)
	(int*)(0x0048DD60 + 0x21E), // Itembox (not in course)	
	(int*)(0x0048E1B0 + 0x16E), // Battle Result Dialog 
	//(int*)(0x00497150 + 0x161), // Not Battle Related
	//(int*)(0x004983F0 + 0xD1),  // Not Battle Related
	//(int*)(0x00499130 + 0x1FE), // Not Battle Related
	//(int*)(0x00499130 + 0x44A), // Not Battle Related
	//(int*)(0x00499DE0 + 0x339), // Not Battle Related
	//(int*)(0x00499DE0 + 0x478), // Not Battle Related
	//(int*)(0x00499DE0 + 0x5E3), // Not Battle Related
	//(int*)(0x00499DE0 + 0x683), // Not Battle Related
	//(int*)(0x0049B080 + 0x37D), // Not Battle Related
	//(int*)(0x0049B080 + 0x510), // Not Battle Related
	//(int*)(0x0049B080 + 0x651), // Not Battle Related
	//(int*)(0x0049B080 + 0x8C2), // Not Battle Related
	//(int*)(0x0049B080 + 0x937), // Not Battle Related
	//(int*)(0x0049C5A0 + 0x20B), // Not Battle Related	
	//(int*)(0x0049C5A0 + 0x32E), // Not Battle Related
	//(int*)(0x0049C5A0 + 0x436), // Not Battle Related
	//(int*)(0x0049C5A0 + 0x557), // Not Battle Related
	//(int*)(0x0049C5A0 + 0x602), // Not Battle Related
	//(int*)(0x0049C5A0 + 0x6B9), // Not Battle Related
	//(int*)(0x0049D0B0 + 0x231), // Not Battle Related
	//(int*)(0x0049D0B0 + 0x354), // Not Battle Related
	//(int*)(0x0049D0B0 + 0x468), // Not Battle Related
	//(int*)(0x0049D0B0 + 0x5B6), // Not Battle Related
	//(int*)(0x0049D0B0 + 0x643), // Not Battle Related
	//(int*)(0x0049DB80 + 0x2CE), // Not Battle Related
	//(int*)(0x0049DB80 + 0x3CF), // Not Battle Related
	//(int*)(0x0049DB80 + 0x4E4), // Not Battle Related
	//(int*)(0x0049DB80 + 0x588), // Not Battle Related 
	//(int*)(0x0049E470 + 0x295), // Not battle related
	//(int*)(0x0049E470 + 0x3DD), // Not battle related
	//(int*)(0x0049E470 + 0x559), // Not battle related
	//(int*)(0x0049E470 + 0x5D1), // Not battle related
	//(int*)(0x0049E470 + 0x648), // Not battle related
	//(int*)(0x0049E470 + 0x6BC), // Not battle related
	//(int*)(0x0049E470 + 0x774), // Not battle related
	//(int*)(0x0049F270 + 0x1DB), // Not battle related
	//(int*)(0x0049F270 + 0x2C6), // Not battle related
	//(int*)(0x0049F270 + 0x3AF), // Not battle related
	//(int*)(0x0049F8E0 + 0x36C), // Not battle related
	//(int*)(0x0049F8E0 + 0x453), // Not battle related
	//(int*)(0x0049F8E0 + 0x50B), // Not battle related
	//(int*)(0x0049F8E0 + 0x657), // Not battle related
	//(int*)(0x0049F8E0 + 0x6BC), // Not battle related
	//(int*)(0x0049F8E0 + 0x7FB), // Not battle related
	//(int*)(0x0049F8E0 + 0x869), // Not battle related
	//(int*)(0x0049F8E0 + 0x9E0), // Not battle related
	//(int*)(0x0049F8E0 + 0xA6C), // Not battle related
	//(int*)(0x0049F8E0 + 0xB1B), // Not battle related
	//(int*)(0x004A0B70 + 0x23F), // Not battle related
	//(int*)(0x004A0B70 + 0x324), // Not battle related
	//(int*)(0x004A0B70 + 0x407), // Not battle related
	//(int*)(0x004A0B70 + 0x524), // Not battle related
	//(int*)(0x004A1600 + 0x312), // Not battle related
	//(int*)(0x004A1600 + 0x5E7), // Not battle related
	//(int*)(0x004A1600 + 0x660), // Not battle related
	//(int*)(0x004A1600 + 0x7C6), // Not battle related
	//(int*)(0x004A1600 + 0x839), // Not battle related
	//(int*)(0x004A1600 + 0x8B7), // Not battle related
	//(int*)(0x004A1600 + 0x99E), // Not battle related
	//(int*)(0x004A1600 + 0xA43), // Not battle related
	//(int*)(0x004A8D90 + 0x287), // Not battle related	
	(int*)(0x004A91B0 + 0x468), // 
	(int*)(0x004A91B0 + 0x4DB), // 
	(int*)(0x004A91B0 + 0x55F), // 
	//(int*)(0x004A9830 + 0x1D5), // Not Shop price
	(int*)(0x004AA150 + 0x119), // 
	(int*)(0x004AA150 + 0x146), // 
	(int*)(0x004AA150 + 0x1D7), // 
	(int*)(0x004AA150 + 0x208), // 
	(int*)(0x004AA490 + 0x118), // 
	(int*)(0x004AA490 + 0x145), // 
	(int*)(0x004AA490 + 0x1B6), // 
	(int*)(0x004AA490 + 0x1F7), // 
	(int*)(0x004AA770 + 0x5F),  // Battle '+' for EXP
	//(int*)(0x004AB050 + 0x32),  // not battle related
	//(int*)(0x004AB050 + 0x400), // not battle related
	//(int*)(0x004ADC80 + 0x358), // not battle related
	//(int*)(0x004ADC80 + 0x40E), // not battle related
	//(int*)(0x004B1100 + 0x1050),// not battle related
	//(int*)(0x004B1100 + 0x1184),// not battle related
	//(int*)(0x004B1100 + 0x13EC),// not battle related
	//(int*)(0x004B1100 + 0x1597),// not battle related
	//(int*)(0x004B1100 + 0x16E8),// not battle related
	//(int*)(0x004B1100 + 0x1872),// not battle related
	//(int*)(0x004B1100 + 0x19BA),// not battle related
	//(int*)(0x004B1100 + 0x1AEE),// not battle related
	//(int*)(0x004B1100 + 0x5D7), // not battle related
	//(int*)(0x004B1100 + 0x70F), // not battle related
	//(int*)(0x004B1100 + 0x86B), // not battle related
	//(int*)(0x004B1100 + 0x9A0), // not battle related
	//(int*)(0x004B1100 + 0xAE6), // not battle related
	//(int*)(0x004B1100 + 0xC55), // not battle related
	//(int*)(0x004B1100 + 0xDBB), // not battle related
	//(int*)(0x004B1100 + 0xF1C), // not battle related
	//(int*)(0x004B5220 + 0x31D), // not battle related
	//(int*)(0x004BC380 + 0x11E), // not battle related
	//(int*)(0x004BC380 + 0x232), // not battle related
	//(int*)(0x004BC380 + 0x2C2), // not battle related
	//(int*)(0x004BC380 + 0x357), // not battle related
	//(int*)(0x004BD090 + 0x107), // not battle related
	//(int*)(0x004BD260 + 0x13B), // not battle related
	(int*)(0x004BF6F0 + 0x1E3), // Warning Screens	
	//(int*)(0x004C1E30 + 0x10B),
	//(int*)(0x004C1E30 + 0x12C), // Tacho
	//(int*)(0x004C1E30 + 0x14D),
	//(int*)(0x004C1E30 + 0x172),
	//(int*)(0x004D2C80 + 0x9A),  // Not battle related
	//(int*)(0x004D83F0 + 0x452), // Not battle related
	//(int*)(0x004D83F0 + 0x9DF), // Not battle related
	//(int*)(0x004D83F0 + 0xA21), // Not battle related
	//(int*)(0x004DB1D0 + 0x4B),
	//(int*)(0x004DB1D0 + 0x8D), // Tacho
	//(int*)(0x004DB4F0 + 0x6E), // Gears Shift Assist
	//(int*)(0x004DB4F0 + 0xB3),	
	//(int*)(0x004DB750 + 0x3A), // Not battle related
	//(int*)(0x004DB800 + 0x31), // Not battle related
	//(int*)(0x004DB910 + 0x2D), // Not battle related
	//(int*)(0x004DB910 + 0x69), // Not battle related
	//(int*)(0x004DB910 + 0xA5), // Not battle related
	//(int*)(0x004DBAF0 + 0x3B), // Not battle related	
	//(int*)(0x004DBBE0 + 0x15D), // Gears Shift Assist
	//(int*)(0x004DBBE0 + 0x182), // Nothing visible
	//(int*)(0x004DBBE0 + 0x260),
	//(int*)(0x004DBBE0 + 0x2AF),
	//(int*)(0x004DC5E0 + 0xCD), // Not battle related
	//(int*)(0x004DC990 + 0x45), // Not battle related
	//(int*)(0x004DC990 + 0xAE), // Not battle related
	//(int*)(0x004DCEB0 + 0x1ED), // Not battle related
	//(int*)(0x004DCEB0 + 0x264), // Not battle related
	//(int*)(0x004DCEB0 + 0x2DB), // Not battle related
	//(int*)(0x004DCEB0 + 0x3A0), // Not battle related
	//(int*)(0x004DCEB0 + 0x42F), // Not battle related
	//(int*)(0x004DCEB0 + 0x4D5), // Not battle related
	//(int*)(0x004DCEB0 + 0x54C), // Not battle related
	//(int*)(0x004DCEB0 + 0x5C3), // Not battle related
	//(int*)(0x004DCEB0 + 0x6FA), // Not battle related
	//(int*)(0x004DCEB0 + 0x76E), // Not battle related
	//(int*)(0x004DD720 + 0x821), // Not battle related
	(int*)(0x004DE420 + 0x1A6), // Battle Bars Background
	(int*)(0x004DE420 + 0x26F), // Battle Bars Background
	(int*)(0x004DE420 + 0x2CC), // Battle Bars Background
	(int*)(0x004DE420 + 0x3C),	// Battle Bars Background
	(int*)(0x004DE420 + 0x82),	// Battle Bars Background
	(int*)(0x004DE420 + 0xCE),	// Battle Bars Background
	(int*)(0x004DF020 + 0x13D), // Battle Bars
	(int*)(0x004DF020 + 0xF0),	// Battle Bars
	(int*)(0x004DF240 + 0x179), // Battle Clock Background
	(int*)(0x004DF240 + 0x1DC), // Battle Clock Background
	(int*)(0x004DF240 + 0xAE),  // Battle Clock
	//(int*)(0x004DF6E0 + 0x6E), // Not battle related
	//(int*)(0x004DF8D0 + 0x7B), // Not battle related
	//(int*)(0x004E0710 + 0x173), // Not battle related
	//(int*)(0x004E0710 + 0x1BC), // Not battle related
	//(int*)(0x004E0710 + 0x1FC), // Not battle related
	//(int*)(0x004E0710 + 0x4B), // Nothing Visible 3
	//(int*)(0x004E0710 + 0x92), // Chat and Buttons Dialogs
	//(int*)(0x004F49E0 + 0x47), // Not battle related
	//(int*)(0x004F4F90 + 0x8E), // Not battle related
	//(int*)(0x004F4F90 + 0xBA), // Chat box left
	//(int*)(0x004F6BE0 + 0xAA), // Chat background
	//(int*)(0x004F6BE0 + 0xD9), // Address book back
	//(int*)(0x004F7F80 + 0x104), // Not battle related
	//(int*)(0x004F7F80 + 0x11F),	// Not battle related
	//(int*)(0x004F8150 + 0x1C1),	// Not battle related
	//(int*)(0x004F8150 + 0x1F9),	// Not battle related
	//(int*)(0x004F8560 + 0x10F),	// Not battle related
	//(int*)(0x004F8560 + 0x12E),	// Not battle related
	//(int*)(0x004F8560 + 0x1FF),	// Not battle related
	//(int*)(0x004F8560 + 0x217), // Address book back
	//(int*)(0x004F8560 + 0x2C8), // address book search
	//(int*)(0x004F8560 + 0x2E0),// Not battle related
	//(int*)(0x004F88B0 + 0x229),// Not battle related
	//(int*)(0x004F88B0 + 0x258),// Not battle related
	//(int*)(0x004FB070 + 0x163),// Not battle related
	//(int*)(0x004FB070 + 0x1A7),// Not battle related
	//(int*)(0x004FB070 + 0x62), // Not battle related
	//(int*)(0x004FB070 + 0x9C), // Not battle related
	//(int*)(0x004FB830 + 0x94), // Not battle related
	//(int*)(0x004FB8D0 + 0x5B), // Not battle related
	//(int*)(0x004FC140 + 0x23), // Not battle related
	//(int*)(0x004FC140 + 0x3C), // Not battle related
	//(int*)(0x004FC140 + 0x55), // Not battle related
	//(int*)(0x004FC140 + 0x6E), // address book search
	//(int*)(0x004FC140 + 0x87), // Not battle related
	//(int*)(0x004FC800 + 0x1CD),// Not battle related
	//(int*)(0x004FC800 + 0x1EC),// Not battle related
	//(int*)(0x004FC800 + 0x28B),// Not battle related
	//(int*)(0x004FC800 + 0x2AA),// Not battle related
	//(int*)(0x004FC800 + 0x328),// Not battle related
	//(int*)(0x004FC800 + 0xA9), // Not battle related
	//(int*)(0x004FC800 + 0xC8), // Not battle related
	//(int*)(0x004FCB40 + 0x93), // Not battle related
	//(int*)(0x004FCD40 + 0xE4), // Not battle related
	//(int*)(0x004FCD40 + 0xFD), // Not battle related
	//(int*)(0x004FD8D0 + 0x81), // Not battle related
	//(int*)(0x004FD990 + 0x2A), // Not battle related
	//(int*)(0x004FDAA0 + 0x45)  // Not battle related
};

int* repositionIntAddr[]{
	(int*)(0x004F8150 + 0x66),
	(int*)(0x004F8150 + 0xDA),
	(int*)(0x004F8150 + 0x127),
	(int*)(0x004F88B0 + 0x66),
	(int*)(0x004F88B0 + 0xDA),
	(int*)(0x004F88B0 + 0x134),
	(int*)(0x004F88B0 + 0x181),
	(int*)(0x004F88B0 + 0x1CE),
	(int*)(0x004FC800 + 0xED),
	(int*)(0x004FCB40 + 0x19),
	(int*)(0x004FCB40 + 0xC6),
};

int* drawStringAddr[]{
	//(int*)(0x00434910 + 0x37F),
	//(int*)(0x0043501A),
	//(int*)(0x0043507F),
	//(int*)(0x00434910 + 0x7E1),
	//(int*)(0x00434910 + 0x82D),
	//(int*)(0x00434910 + 0xC07),
	//(int*)(0x00434910 + 0xC5B),
	//(int*)(0x00434910 + 0xCAC),
	//(int*)(0x00434910 + 0xCFC),
	//(int*)(0x00440460 + 0x48),
	//(int*)(0x0044F2E0 + 0xBD9),
	//(int*)(0x0044F2E0 + 0xC3D),
	//(int*)(0x00450270 + 0xD2),
	//(int*)(0x00450270 + 0x11B),
	//(int*)(0x0045B660 + 0xA5),
	//(int*)(0x0045B660 + 0x136),

	(int*)(0x0045BC90 + 0x21D), // Item Use
	(int*)(0x0045BC90 + 0x27A), // Item Use

	//(int*)(0x0045CEF0 + 0x335),
	//(int*)(0x0045CEF0 + 0x38F),

	(int*)(0x0045D650 + 0x22), // Item Hover
	(int*)(0x0045D650 + 0x3D), // Item Hover
	
	//(int*)(0x004717F0 + 0x23E3),
	//(int*)(0x004717F0 + 0x2495),
	//(int*)(0x004717F0 + 0x2579),
	//(int*)(0x004717F0 + 0x2656),
	//(int*)(0x004717F0 + 0x2711),
	//(int*)(0x00477520 + 0x700),
	//(int*)(0x00478810 + 0x5D9),
	//(int*)(0x004859F0 + 0x12D),
	//(int*)(0x00497150 + 0x205),
	//(int*)(0x0049B080 + 0x772),
	//(int*)(0x0049B080 + 0x7D1),
	//(int*)(0x0049C5A0 + 0x755),
	//(int*)(0x0049C5A0 + 0x7AF),
	//(int*)(0x0049D0B0 + 0x6E5),
	//(int*)(0x0049D0B0 + 0x73F),

	//(int*)(0x0049E470 + 0x4CD),
	//(int*)(0x004A8D90 + 0x2FD),
	//(int*)(0x004A91B0 + 0x283),
	//(int*)(0x004AB050 + 0x470),
	//(int*)(0x004ABF40 + 0x45),
	//(int*)(0x004BC380 + 0xBD),
	//(int*)(0x004BD6E0 + 0x45),
	//(int*)(0x004D83F0 + 0x976),
	//(int*)(0x004DC5E0 + 0x149),
	//(int*)(0x004DE420 + 0x32D),
	//(int*)(0x004DE420 + 0x37B),
	//(int*)(0x004DE420 + 0x3C9),
	//(int*)(0x004DE420 + 0x419),
	//(int*)(0x004DE420 + 0x4A1),
	//(int*)(0x004DE420 + 0x4EE),
	//(int*)(0x004FBB10 + 0x44),
	//(int*)(0x004FBB60 + 0x32),
	//(int*)(0x004FD0E0 + 0x114),
	//(int*)(0x004FD9D0 + 0x1E),
	//(int*)(0x004FDA00 + 0x26)
};