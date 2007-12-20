/****************************************************************************/
/// @file    MSDetectorControl.h
/// @author  Daniel Krajzewicz
/// @date    2005-09-15
/// @version $Id$
///
//	missingDescription
/****************************************************************************/
// SUMO, Simulation of Urban MObility; see http://sumo.sourceforge.net/
// copyright : (C) 2001-2007
//  by DLR (http://www.dlr.de/) and ZAIK (http://www.zaik.uni-koeln.de/AFS)
/****************************************************************************/
//
//   This program is free software; you can redistribute it and/or modify
//   it under the terms of the GNU General Public License as published by
//   the Free Software Foundation; either version 2 of the License, or
//   (at your option) any later version.
//
/****************************************************************************/
#ifndef MSDetectorControl_h
#define MSDetectorControl_h


// ===========================================================================
// included modules
// ===========================================================================
#ifdef _MSC_VER
#include <windows_config.h>
#else
#include <config.h>
#endif

#include <string>
#include <vector>
#include <utils/common/NamedObjectCont.h>
#include <microsim/output/e2_detectors/MSE2Collector.h>
#include <microsim/output/e2_detectors/MS_E2_ZS_CollectorOverLanes.h>
#include <microsim/output/e3_detectors/MSE3Collector.h>
#include <microsim/output/MSInductLoop.h>
#include "MSDetector2File.h"

#ifdef HAVE_MESOSIM
#include <mesosim/MEInductLoop.h>
#endif


// ===========================================================================
// class definitions
// ===========================================================================
/**
 * @class MSDetectorControl
 */
class MSDetectorControl
{
public:
    typedef NamedObjectCont< MSInductLoop*> LoopDict;
#ifdef HAVE_MESOSIM
    typedef NamedObjectCont< MEInductLoop*> MELoopDict;
#endif
    typedef NamedObjectCont< MSE2Collector*> E2Dict;
    typedef NamedObjectCont< MSE3Collector*> E3Dict;
    typedef NamedObjectCont< MS_E2_ZS_CollectorOverLanes* > E2ZSOLDict;

    typedef std::vector< MSInductLoop*> LoopVect;
#ifdef HAVE_MESOSIM
    typedef std::vector< MEInductLoop*> MELoopVect;
#endif
    typedef std::vector< MSE2Collector*> E2Vect;
    typedef std::vector< MSE3Collector*> E3Vect;
    typedef std::vector< MS_E2_ZS_CollectorOverLanes* > E2ZSOLVect;

public:
    MSDetectorControl();

    ~MSDetectorControl();

    void close(SUMOTime step);

    MSInductLoop *findInductLoop(const std::string &id);

    void add(MSInductLoop *il, OutputDevice& device,
             int splInterval);
#ifdef HAVE_MESOSIM
    void add(MEInductLoop *il, OutputDevice& device,
             int splInterval);
#endif

    void add(MSE2Collector *e2, OutputDevice& device,
             int splInterval);

    void add(MS_E2_ZS_CollectorOverLanes *e2ol, OutputDevice& device,
             int splInterval);

    /// adds an e2 detector coupled to an extern output impulse giver
    void add(MSE2Collector *e2);

    /// adds an e2ol detector coupled to an extern output impulse giver
    void add(MS_E2_ZS_CollectorOverLanes *e2ol);

    void add(MSE3Collector *e3, OutputDevice& device,
             int splInterval);

    MSDetector2File &getDet2File();

    void resetInterval(MSDetectorFileOutput *il, SUMOTime interval);

    LoopVect getLoopVector() const;
    E2Vect getE2Vector() const;
    E3Vect getE3Vector() const;
    E2ZSOLVect getE2OLVector() const;

    void writeOutput(SUMOTime step);


protected:
    LoopDict myLoops;
#ifdef HAVE_MESOSIM
    MELoopDict myMesoLoops;
#endif
    E2Dict myE2Detectors;
    E3Dict myE3Detectors;
    E2ZSOLDict myE2OverLanesDetectors;
    MSDetector2File myDetector2File;

};


#endif

/****************************************************************************/

