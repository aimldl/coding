#include  "RLGoEngine.hpp"
#include  "Location.hpp"
#include  <cmath>  // For ceil

// RLGoEngine.cpp
// Created on: Apr 9, 2011
//     Author: tk424

//==============================================================================
//                     Definition of static variables
//==============================================================================

//==============================================================================
//                        Static Public functions
//==============================================================================

// IMPORTANT! RUN THESE FUNCTIONS BEFORE THIS CLASS IS CONSTRUCTED!!!
void
RLGoEngine::configure( Config& configObj )
{
  assert( configObj.get_simulationsObj_().get_taskType_() == "td_go" );

  ReinforcementLearning::configure( configObj );
}
// IMPORTANT! RUN THESE FUNCTIONS BEFORE THIS CLASS IS CONSTRUCTED!!!

//==============================================================================
//                        Static Private functions
//==============================================================================
//==============================================================================
//                            Public functions
//==============================================================================

RLGoEngine::RLGoEngine()
{
}

RLGoEngine::~RLGoEngine()
{
}

void
RLGoEngine::initialize()
{
  numOfStates_  = 2;
  numOfActions_ = 4;

//  showStateIndexMapping();
  tout << "  numOfStates_  = " << numOfStates_ << endl;
  tout << "  numOfActions_ = " << numOfActions_ << endl;

  initializeQ_();
}

void
RLGoEngine::runSimulation( bool showProgressBar )
{
  int      resolution, numOfBars;  // PROGRESS BAR
  double   resolDivisor;           // PROGRESS BAR

  // The progress bar has about 20 bins to show the progress.
  // 100 is too long to display in the terminal.
  if ( showProgressBar )
  {
    resolDivisor = 20.0;
    resolution   = ( int ) ceil( ( double ) maxNumberOfEpisodes_ / resolDivisor );
    numOfBars    = ( int ) ( double )       maxNumberOfEpisodes_ / ( double ) resolution;

    cout << "\n  Running a simulation..." << "\n    0%";
    for ( int i = 0; i < numOfBars; i++ )
      cout << "   ";
    cout << "100%" << "\n    |";
  }

       if ( updateMethod_ == "sarsa" )     runSARSA( showProgressBar,resolution );
  else if ( updateMethod_ == "qlearning" ) runQLearning( showProgressBar,resolution );

  if ( showProgressBar )
    cout << "|\n" << "  Simulation is done." << endl;
}

//==============================================================================
//                            Protected functions
//==============================================================================
//==============================================================================
//                            Private functions
//==============================================================================

// Take an action a and observe reward r and the next state s'
// Design issue: Which one should come first: observeReward or takeAction?
//               Note takeAction may cause nextLocation=currentLocation.
//               If observeReward comes first, the reward for currentLocation? It seems wrong.

void
RLGoEngine::runQLearning( bool showProgressBar, int resolution )
{
  bool     isNotTerminal_episode  = true;  // Terminal condition is not met. If true, next loop; o.w., loop is over.
  int      episode                = 0;

  int      s;       // Index for the current state
  int      a;       // Index for the current action
  double   r;       // Index for reward
  int      s_;      // Index for the next state
  int      a_;      // Index for the next action

  double   totalRewards;
  Location currentLocation;
  Location nextLocation;

  logErrorProfileHeader();

  while ( isNotTerminal_episode )
  {
    totalRewards    = 0.0;
//    currentLocation = grid_.get_startPosition_();  // Get the initial state of this episode
//
//    // Initialize Q(s,a) arbitrarily. Done in function initialize().
//    do  // Repeat (for each episode)
//    {
//      s                      = getStateIndex( currentLocation );
//
//      // Choose an action a from the current state s using a policy derived from Q, e.g. e-greedy
//      a                      = chooseAction( s, actionCriterion_ );
//
//      // Take action a, observe r, s'
//      nextLocation           = getNewLocation( a, currentLocation );
//      r                      = observeReward( nextLocation );
//      if ( !grid_.isWithinBoundary( nextLocation ) )
//        nextLocation         = currentLocation;
//      s_                     = getStateIndex( nextLocation );
//
//      // Choose a' from s' using policy derived from Q, e.g. e-greedy
//      a_                     = argmax( Q_[s_] );  // This is diffnerent from SARSA. Q-learning chooses an greedy action.
//      Q_[s][a]               = Q_[s][a] + alpha_*( r + gamma_*Q_[s_][a_] - Q_[s][a] );
//
//      // s <- s'
//      currentLocation        = nextLocation;
//
//      totalRewards += r;
//    } while ( !isTerminal( currentLocation ) );

    isNotTerminal_episode = ( episode < maxNumberOfEpisodes_ );
    eout << episode << "\t" << totalRewards << endl;
    episode++;

    if ( showProgressBar && ( (episode-1) % resolution ) == 0 )  // (episode-1) because of episode++;
      cout << "===";
  }
}

// How to deal with an action that goes out of boundary is an issue!!!

void
RLGoEngine::runSARSA( bool showProgressBar, int resolution )
{
  bool     isNotTerminal_episode  = true;  // Terminal condition is not met. If true, next loop; o.w., loop is over.
  int      episode                = 0;

  int      s;       // Index for the current state
  int      a;       // Index for the current action
  double   r;       // Index for reward
  int      s_;      // Index for the next state
  int      a_;      // Index for the next action

  double   totalRewards;
  Location currentLocation;
  Location nextLocation;

  logErrorProfileHeader();
/*
  while ( isNotTerminal_episode )
  {
  totalRewards    = 0.0;
    currentLocation = grid_.get_startPosition_();  // Get the initial state of this episode
    s               = getStateIndex( currentLocation );

    // Choose an action a from the current state s using a policy derived from Q, e.g. e-greedy
    a               = chooseAction( s, actionCriterion_ );  // This is different from Q-learning.
    // Initialize Q(s,a) arbitrarily. Done in function initialize().
    do  // Repeat (for each episode)
    {
      // Take action a, observe r, s'
      nextLocation           = getNewLocation( a, currentLocation );
      r                      = observeReward( nextLocation );
      if ( !grid_.isWithinBoundary( nextLocation ) )
        nextLocation         = currentLocation;
      s_                     = getStateIndex( nextLocation );

      // Choose a' from s' using policy derived from Q, e.g. e-greedy
      a_                     = chooseAction( s_, actionCriterion_ );  // This is different from Q-learning.
      Q_[s][a]               = Q_[s][a] + alpha_*( r + gamma_*Q_[s_][a_] - Q_[s][a] );

      // s <- s'; a <- a'
      currentLocation        = nextLocation;
      a                      = a_;  // This is different from Q-learning.

      s                      = getStateIndex( currentLocation );  // Without this, infinite loop!
      totalRewards += r;
    } while ( !isTerminal( currentLocation ) );

    isNotTerminal_episode = ( episode < maxNumberOfEpisodes_ );
    eout << episode << "\t" << totalRewards << endl;
    episode++;

    if ( showProgressBar && ( (episode-1) % resolution ) == 0 )  // (episode-1) because of episode++;
      cout << "===";
  }
  */
}
