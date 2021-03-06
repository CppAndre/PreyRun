#pragma once

// Credits to Ivan Molodetskikh (Yalter) and Chong Jiang Wei (Matherunner) for their interprocess.cpp from BunnymodXT (https://github.com/YaLTeR/BunnymodXT/blob/master/BunnymodXT/Windows/interprocess.cpp)

#include "Utility.hpp"

#define PREYSPLIT_PIPE_NAME "PreyRun-PreySplit"

class idStr;

namespace pr
{
	enum class MessageType : unsigned char
	{
		TIME = 0x00,
		EVENT = 0x01
	};

	enum class EventType : unsigned char
	{
		GAMEEND = 0x00,
		MAPCHANGE = 0x01,
		TIMER_RESET = 0x02,
		TIMER_START = 0x03,
		BOSS_KILL = 0x04,
		CUSTOM_SPLIT = 0x05
	};

	void InitPreySplitPipe();
	void ShutdownPreySplitPipe();

	void PreySplitMain();

	void WriteTime(const Time& time);

	void WriteGameEnd(const Time& time);
	void WriteMapChange(const Time& time, const idStr& map);
	void WriteTimerReset(const Time& time);
	void WriteTimerStart(const Time& time);
	void WriteBossKill(const Time& time, const idStr& boss);
	void WriteCustomSplit(const Time& time);

	Time GetTime();
} // End of namespace: pr
