/* date = March 27th 2022 4:51 pm */

#ifndef WIN32_TIMER_H
#define WIN32_TIMER_H

struct W32_Timer
{
    LARGE_INTEGER counts_per_second;
    LARGE_INTEGER begin_frame;
    b32 is_sleep_granular;
};


internal b32  W32_TimerInit(W32_Timer *timer);
internal void W32_TimerBeginFrame(W32_Timer *timer);
internal void W32_TimerEndFrame(W32_Timer *timer, f64 milliseconds_per_frame);

#endif //WIN32_TIMER_H
