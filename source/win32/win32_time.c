#include <Windows.h>
#include <timeapi.h>
#include "types.h"
#include "utils.h"
#include "os_time.h"
#include "win32_time.h"

#define TIMER_UNINITIALIZED 1

i64 win32_time_get_tick(void)
{
    static MMRESULT is_time_granular = TIMER_UNINITIALIZED;
    LARGE_INTEGER tick = { 0 };

    if (TIMER_UNINITIALIZED == is_time_granular)
        is_time_granular = timeBeginPeriod(1);
    ASSERT(TIMERR_NOERROR == is_time_granular);

    QueryPerformanceCounter(&tick);

    return (i64)tick.QuadPart;
}

i64 win32_time_get_frequency(void)
{
    // NOTE: Counts per second
    static LARGE_INTEGER frequency;

    if (!frequency.QuadPart)
        QueryPerformanceFrequency(&frequency);
    ASSERT(frequency.QuadPart);

    return (i64)frequency.QuadPart;
}

void win32_time_sleep(u32 milliseconds)
{
    Sleep(milliseconds);
}

void win32_time_now(OSSystemTime* os_system_time)
{
    SYSTEMTIME system_time = { 0 };

    GetSystemTime(&system_time);

    os_system_time->year         = system_time.wYear;
    os_system_time->month        = system_time.wMonth;
    os_system_time->day_of_week  = system_time.wDayOfWeek;
    os_system_time->day          = system_time.wDay;
    os_system_time->hour         = system_time.wHour;
    os_system_time->minute       = system_time.wMinute;
    os_system_time->second       = system_time.wSecond;
    os_system_time->milliseconds = system_time.wMilliseconds;
}