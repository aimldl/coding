#ifndef  __RLGOENGINE_HPP_
#define  __RLGOENGINE_HPP_

#include  "Config.hpp"
#include  "Myiostream.hpp"
#include  "ReinforcementLearning.hpp"
#include  "GoBoard.hpp"

using namespace std;

//==============================================================================
//                              Type Definitions
//==============================================================================
typedef vector<double> vdouble;

//==============================================================================
//                             Forward Declaration
//==============================================================================

//==============================================================================
//                              Class Declaration
//==============================================================================

class      RLGoEngine : public ReinforcementLearning
{
public:
           RLGoEngine();
          ~RLGoEngine();
  static
  void     configure( Config& configObj );  // IMPORTANT! RUN THESE FUNCTIONS BEFORE THIS CLASS IS CONSTRUCTED!!!

  void     initialize();
  void     runSimulation( bool showProgressBar );

private:
  void     runSARSA( bool showProgressBar, int resolution );
  void     runQLearning( bool showProgressBar, int resolution );

  bool     isTerminal();
};

#endif

//==============================================================================
//                                  Comments
//==============================================================================
// RLGoEngine.hpp
// Created on: Apr 9, 2011
//     Author: tk424
