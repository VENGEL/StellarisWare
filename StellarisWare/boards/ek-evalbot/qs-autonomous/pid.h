//*****************************************************************************
//
// pid.h - Prototypes for the PID feedback control algorithm.
//
// Copyright (c) 2011-2013 Texas Instruments Incorporated.  All rights reserved.
// Software License Agreement
// 
// Texas Instruments (TI) is supplying this software for use solely and
// exclusively on TI's microcontroller products. The software is owned by
// TI and/or its suppliers, and is protected under applicable copyright
// laws. You may not combine this software with "viral" open-source
// software in order to form a larger program.
// 
// THIS SOFTWARE IS PROVIDED "AS IS" AND WITH ALL FAULTS.
// NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT
// NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE. TI SHALL NOT, UNDER ANY
// CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR CONSEQUENTIAL
// DAMAGES, FOR ANY REASON WHATSOEVER.
// 
// This is part of revision 10636 of the Stellaris Firmware Development Package.
//
//*****************************************************************************

#ifndef __PID_H__
#define __PID_H__

//*****************************************************************************
//
// If building with a C++ compiler, make all of the definitions in this header
// have a C binding.
//
//*****************************************************************************
#ifdef __cplusplus
extern "C"
{
#endif

//*****************************************************************************
//
// This structure contains the internal state of the PID algorithm.
//
//*****************************************************************************
typedef struct
{
    //
    // The current value of the integrator.
    //
    long lIntegrator;

    //
    // The maximum allowable value of the integrator.
    //
    long lIntegMax;

    //
    // The minimum allowable value of the integrator.
    //
    long lIntegMin;

    //
    // The error from the previous call to the algorithm.  This is used for
    // determining the derivative of the error.
    //
    long lPrevError;

    //
    // The proportional gain factor.
    //
    long lPGain;

    //
    // The integral gain factor.
    //
    long lIGain;

    //
    // The derivative gain factor.
    //
    long lDGain;
}
tPIDState;

//*****************************************************************************
//
// PID module function prototypes.
//
//*****************************************************************************
extern void PIDInitialize(tPIDState *psState, long lIntegMax, long lIntegMin,
                          long lPGain, long lIGain, long lDGain);
extern void PIDGainPSet(tPIDState *psState, long lPGain);
extern void PIDGainISet(tPIDState *psState, long lIGain, long lIntegMax,
                        long lIntegMin);
extern void PIDGainDSet(tPIDState *psState, long lDGain);
extern void PIDReset(tPIDState *psState);
extern long PIDUpdate(tPIDState *psState, long lError);

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif // __PID_H__
