#include  "CliffWalkingProblem.hpp"
#include  "Location.hpp"
#include  <cmath>  // For ceil

// CliffWalkingProblem.cpp
// Created on: Apr 8, 2011
//     Author: tk424


//==============================================================================
//                     Definition of static variables
//==============================================================================
string
CliffWalkingProblem::moveOption_;

//==============================================================================
//                        Static Public functions
//==============================================================================

// IMPORTANT! RUN THESE FUNCTIONS BEFORE THIS CLASS IS CONSTRUCTED!!!
void
CliffWalkingProblem::configure( Config& configObj )
{
  cout << "CliffWalkingProblem::configure()" << endl;

  assert( configObj.get_simulationsObj_().get_taskType_() == "test_cliff_walking" );

  GridWorld::configure( configObj );
  moveOption_ = configObj.get_rlObj_().get_moveOption_();

  ReinforcementLearning::configure( configObj );
}
// IMPORTANT! RUN THESE FUNCTIONS BEFORE THIS CLASS IS CONSTRUCTED!!!

//==============================================================================
//                        Static Private functions
//==============================================================================
//==============================================================================
//                            Public functions
//==============================================================================

CliffWalkingProblem::CliffWalkingProblem()
{
}

CliffWalkingProblem::~CliffWalkingProblem()
{
}

void
CliffWalkingProblem::initialize()
{
  grid_.initialize();
  numOfStates_ = grid_.get_numOfGrids_();

    if ( moveOption_ == "standard_move" )
    numOfActions_ = 4;  // up, down, left, right, so four actions.
  else if ( moveOption_ == "kings_move" )
    numOfActions_ = 8;  // up, down, left, right, top-right, top-left, bottom-right, bottom-left
  else if ( moveOption_ == "kings_move_with_pause" )
    numOfActions_ = 9;  // up, down, left, right, top-right, top-left, bottom-right, bottom-left+ pause

  tout << "  moveOption_   = " << moveOption_ << endl;
  showStateIndexMapping();
  tout << "  numOfStates_  = " << numOfStates_ << endl;
  tout << "  numOfActions_ = " << numOfActions_ << endl;

  initializeQ_();
}

void
CliffWalkingProblem::logResults()
{
  showGridWorldOutput();
  logGridWorldOutput();
  show_policy_();
  showQ_();
}

void
CliffWalkingProblem::runSimulation( bool showProgressBar )
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
CliffWalkingProblem::runQLearning( bool showProgressBar, int resolution )
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
    currentLocation = grid_.get_startPosition_();  // Get the initial state of this episode

    // Initialize Q(s,a) arbitrarily. Done in function initialize().
    do  // Repeat (for each episode)
    {
      s                      = getStateIndex( currentLocation );

      // Choose an action a from the current state s using a policy derived from Q, e.g. e-greedy
      a                      = chooseAction( s, actionCriterion_ );

      // Take action a, observe r, s'
      nextLocation           = getNewLocation( a, currentLocation );
      r                      = observeReward( nextLocation );
      if ( !grid_.isWithinBoundary( nextLocation ) )
        nextLocation         = currentLocation;
      s_                     = getStateIndex( nextLocation );

      // Choose a' from s' using policy derived from Q, e.g. e-greedy
      a_                     = argmax( Q_[s_] );  // This is different from SARSA. Q-learning chooses an greedy action.
      Q_[s][a]               = Q_[s][a] + alpha_*( r + gamma_*Q_[s_][a_] - Q_[s][a] );

      // s <- s'
      currentLocation        = nextLocation;

      totalRewards += r;
    } while ( !isTerminal( currentLocation ) );

    isNotTerminal_episode = ( episode < maxNumberOfEpisodes_ );
    eout << episode << "\t" << totalRewards << endl;
    episode++;

    if ( showProgressBar && ( (episode-1) % resolution ) == 0 )  // (episode-1) because of episode++;
      cout << "===";
  }
}

// How to deal with an action that goes out of boundary is an issue!!!

void
CliffWalkingProblem::runSARSA( bool showProgressBar, int resolution )
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
}

bool
CliffWalkingProblem::isTerminal( Location currentLocation )
{
  return ( ( grid_.isDestination(currentLocation) || grid_.isCliff(currentLocation) ) );
}

// Hashing to map the 2D state to 1D
//#define INDEX(x_,y_,N_) ( (x_)+(N_)*(y_) )
//#define X(state_,N_)  ( (state_) % (N_) )
//#define Y(state_,N_)  ( (int) ( (state_) / (N_) ) )
// grid_.get_size_(0) is the size of x

int
CliffWalkingProblem::getStateIndex( Location loc )
{
  return ( loc.x + loc.y * grid_.get_size_(0) );
}

int
CliffWalkingProblem::getStateIndex( int x, int y )
{
  return ( x + y * grid_.get_size_(0) );
}

/*
int
CliffWalkingProblem::chooseAction( Location currentLocation, string actionCriterion )
{
  int state = getStateIndex( currentLocation );

  return chooseAction( state, actionCriterion );
}
*/

int
CliffWalkingProblem::greedy( Location currentLocation )
{
  int state = getStateIndex( currentLocation );

  return policy_[ state ];
}

int
CliffWalkingProblem::eGreedy( Location currentLocation )
{
  int    action;
  double randomNumber = rv_.uniform();

  if ( trace4dbg_ )
  {
    dout << "s=" << getStateIndex( currentLocation ) << ", x=" << currentLocation.x << " " << "y=" << currentLocation.y << endl;
    show_policy_dout();
    showQ_dout();
  }

  if ( randomNumber >= epsilon_ )
  {
    action = greedy( currentLocation );
    if ( trace4dbg_ )  dout << "a=" << action << ", greedy" << endl;
  }
  else
  {
    action = rv_.uniformInteger( 0,numOfActions_-1 );
    if ( trace4dbg_ )  dout << "a=" << action << ", random"<< endl;
  }

  return action;
}

double
CliffWalkingProblem::observeReward( Location loc )
{
  double reward;

  if ( rewardVector_.size()==4 )
  {
         if ( grid_.isDestination( loc ) )
      reward = rewardVector_[0];  // e.g. 500
    else if ( !grid_.isWithinBoundary(  loc  ) )
      reward = rewardVector_[2];  // e.g. -10
    else if ( grid_.isCliff( loc ) )
      reward = rewardVector_[3];  // e.g. -500
    else  // Roaming around within the boundary
      reward = rewardVector_[1];  // e.g. -1
  } else if ( rewardVector_.size()==2 )
  {
    if ( grid_.isCliff(  loc  ) )
      reward = rewardVector_[1];  // e.g. -100.0
    else
      reward = rewardVector_[0];  // e.g. -1.0
  }

  if ( trace4dbg_ )  dout << "r=" << reward << endl;

  return reward;
}

Location
CliffWalkingProblem::getNewLocation( int action, Location currentLocation )
{
  Location deviation;
  Location newLocation;

  if ( moveOption_ == "standard_move" )
    deviation = standardMove( action );
  else if ( moveOption_ == "kings_move" )
    deviation = kingsMove( action );
  else if ( moveOption_ == "kings_move_with_pause" )
    deviation = kingsMoveWithPause( action );

  newLocation = currentLocation + deviation;

  if ( trace4dbg_ )
  {
    dout << "(" << newLocation.x << "," << newLocation.y << ")="
         << "(" << currentLocation.x << "," << currentLocation.y << ")+(" << deviation.x << "," << deviation.y << ")";
  }

  return newLocation;
}

Location
CliffWalkingProblem::standardMove( int action )
{
  Location deviation;

       if ( action == 0 ) deviation.set(  0, 1 );  // up
  else if ( action == 1 ) deviation.set(  0,-1 );  // down
  else if ( action == 2 ) deviation.set( -1, 0 );  // left
  else if ( action == 3 ) deviation.set(  1, 0 );  // right

  return deviation;
}

Location
CliffWalkingProblem::kingsMove( int action )
{
  Location deviation;

       if ( action == 0 ) deviation.set(  0, 1 );  // up
  else if ( action == 1 ) deviation.set(  0,-1 );  // down
  else if ( action == 2 ) deviation.set( -1, 0 );  // left
  else if ( action == 3 ) deviation.set(  1, 0 );  // right
  else if ( action == 4 ) deviation.set( -1, 1 );  // top-left
  else if ( action == 5 ) deviation.set(  1, 1 );  // top-right
  else if ( action == 6 ) deviation.set( -1,-1 );  // bottom-left
  else if ( action == 7 ) deviation.set(  1,-1 );  // bottom-right

  return deviation;
}

Location
CliffWalkingProblem::kingsMoveWithPause( int action )
{
  Location deviation;

       if ( action == 0 ) deviation.set(  0, 1 );  // up
  else if ( action == 1 ) deviation.set(  0,-1 );  // down
  else if ( action == 2 ) deviation.set( -1, 0 );  // left
  else if ( action == 3 ) deviation.set(  1, 0 );  // right
  else if ( action == 4 ) deviation.set( -1, 1 );  // top-left
  else if ( action == 5 ) deviation.set(  1, 1 );  // top-right
  else if ( action == 6 ) deviation.set( -1,-1 );  // bottom-left
  else if ( action == 7 ) deviation.set(  1,-1 );  // bottom-right
  else if ( action == 8 ) deviation.set(  0, 0 );  // pause

  return deviation;
}


void
CliffWalkingProblem::show_policy_()
{
  int s;  // state index

  tout << "void CliffWalkingProblem::show_policy_()" << endl;
  for ( int y=grid_.get_size_(1)-1; y>=0; y-- )
  {
    tout << "  ";
  for ( int x=0; x<grid_.get_size_(0); x++ )
  {
    s = getStateIndex(x,y);
    tout << policy_[s] << " ";
  }
  tout << endl;
  }
}

void
CliffWalkingProblem::show_policy_dout()
{
  int s;  // state index

  dout << "void CliffWalkingProblem::show_policy_dout()" << endl;
  for ( int y=grid_.get_size_(1)-1; y>=0; y-- )
  {
    dout << "  ";
  for ( int x=0; x<grid_.get_size_(0); x++ )
  {
    s = getStateIndex(x,y);
    dout << policy_[s] << " ";
  }
  dout << endl;
  }
}

void
CliffWalkingProblem::showQ_()
{
  tout << "void CliffWalkingProblem::showQ_()" << endl;

  for ( int s = numOfStates_-1; s >=0 ; s-- )
  {
    tout << "  ";
    for ( int a = 0; a < numOfActions_; a++ )
      tout << Q_[s][a] << " ";
    tout << " " << s << endl;
  }

  tout << "\n"
       << "   ";
  for ( int a = 0; a < numOfActions_; a++ )
  {
    if ( a < 9 )
      tout << a << " ";
    else  // Assume a has, at most, two digits.
      tout << a;
  }
  tout << endl;
  tout << "    a" << endl;
}

void
CliffWalkingProblem::showQ_dout()
{
  dout << "void CliffWalkingProblem::showQ_dout()" << endl;

  for ( int s = numOfStates_-1; s >=0 ; s-- )
  {
    dout << "  ";
    for ( int a = 0; a < numOfActions_; a++ )
      dout << Q_[s][a] << " ";
    dout << " " << s << endl;
  }

  dout << "\n"
       << "   ";
  for ( int a = 0; a < numOfActions_; a++ )
  {
    if ( a < 9 )
      dout << a << " ";
    else  // Assume a has, at most, two digits.
      dout << a;
  }
  dout << endl;
  dout << "    a" << endl;
}

// This is a function to verify if function getStateIndex works properly.
// Do not delete this function unless function getStateIndex is deleted.

void
CliffWalkingProblem::showStateIndexMapping()
{
  tout << "void CliffWalkingProblem::showStateIndexMapping()" << endl;

  for ( int y=grid_.get_size_(1)-1; y>=0; y-- )
  {
    tout << "  ";
  for ( int x=0; x<grid_.get_size_(0); x++ )
      tout << getStateIndex(x,y) << " ";
  tout << endl;
  }
}

void
CliffWalkingProblem::showGridWorldOutput()
{
  cout << "\n"
       << "  Policies: " << updateMethod_ << ", " << moveOption_ << ", " << actionCriterion_
       << "\n" << endl;
  for ( int y=grid_.get_size_(1)-1; y>=0; y-- )
  {
    cout << "  ";
  for ( int x=0; x<grid_.get_size_(0); x++ )
    cout << a2u(x,y) << " ";
    cout << " " << y << endl;
  }
  cout << "\n  ";
  for ( int x=0; x<grid_.get_size_(0); x++ )
  {
    if ( x < 9 ) cout << x << " ";  // This must be 9, not 10.
    else         cout << x;
  }
  cout << endl;

  cout << "\n"
       << "  Double arrow: source node, e.g.\u21d1: move up\n"
       << "  An arrow: intermediate nodes, e.g.\u2191: move up\n"
       << "  D: destination node\n"
       << "  \u2588: cliff\n"
       << "\n" << endl;
}

void
CliffWalkingProblem::logGridWorldOutput()
{
  tout << "  Policies: " << updateMethod_ << ", " << moveOption_ << ", " << actionCriterion_
       << "\n" << endl;
  for ( int y=grid_.get_size_(1)-1; y>=0; y-- )
  {
    tout << "  ";
  for ( int x=0; x<grid_.get_size_(0); x++ )
    tout << a2u(x,y) << " ";
    tout << " " << y << endl;
  }
  tout << "\n  ";
  for ( int x=0; x<grid_.get_size_(0); x++ )
  {
    if ( x < 9 ) tout << x << " ";  // This must be 9, not 10.
    else         tout << x;
  }
  tout << endl;

  tout << "\n"
       << "  Double arrow: source node, e.g.\u21d1: move up\n"
       << "  An arrow: intermediate nodes, e.g.\u2191: move up\n"
       << "  D: destination node\n"
       << "  \u2588: cliff\n"
       << "\n" << endl;
}

// Action to Unicode
//   Refer to http://en.wikipedia.org/wiki/Arrow_(symbol)

string
CliffWalkingProblem::a2u( int x, int y )
{
  string temp;
  int    s      = getStateIndex(x,y);  // state index
  int    action = argmax( Q_[ s ] );   // For off-policy training algorithm
  //int    action = policy_[s];         // For on-policy training algorithm

  if ( grid_.isSource(x,y) )
    temp = useDoubleArrow( action );
  else if ( grid_.isDestination(x,y) )
    temp = "D";  // useBlackArrow( action );
  else if ( grid_.isCliff(x,y) )
    temp = useFullBlock();
  else
    temp = useAnArrow( action );

  return temp;
}

// cout << "\u2588" << endl;  // Cliff for U+2588 █ Full block
string
CliffWalkingProblem::useFullBlock()
{
  return "\u2588";  // Unicode U+2588 █ Full block
}

// cout << "\u2191" << endl;  // Upwards arrow
// cout << "\u2193" << endl;  // downwards arrow
// cout << "\u2190" << endl;  // Leftwards arrow
// cout << "\u2192" << endl;  // rightwards arrow
// cout << "\u2196" << endl;  // North west arrow
// cout << "\u2197" << endl;  // North east arrow
// cout << "\u2198" << endl;  // South east arrow
// cout << "\u2199" << endl;  // South west arrow

string
CliffWalkingProblem::useAnArrow( int action )
{
       if ( action == 0 ) return "\u2191"; // Upwards arrow
  else if ( action == 1 ) return "\u2193"; // downwards arrow
  else if ( action == 2 ) return "\u2190"; // Leftwards arrow
  else if ( action == 3 ) return "\u2192"; // rightwards arrow
  else if ( action == 4 ) return "\u2196"; // North west arrow
  else if ( action == 5 ) return "\u2197"; // North east arrow
  else if ( action == 6 ) return "\u2199"; // South west arrow
  else if ( action == 7 ) return "\u2198"; // South east arrow
  else if ( action == 8 ) return " ";      // Pause
}

string
CliffWalkingProblem::useDoubleArrow( int action )
{
       if ( action == 0 ) return "\u21d1"; // Upwards double arrow
  else if ( action == 1 ) return "\u21d3"; // downwards double arrow
  else if ( action == 2 ) return "\u21d0"; // Leftwards double arrow
  else if ( action == 3 ) return "\u21d2"; // rightwards double arrow
  else if ( action == 4 ) return "\u21d6"; // North west double arrow
  else if ( action == 5 ) return "\u21d7"; // North east double arrow
  else if ( action == 6 ) return "\u21d9"; // South west double arrow
  else if ( action == 7 ) return "\u21d8"; // South east double arrow
  else if ( action == 8 ) return " ";      // Pause
}

// Refer to Unicode Supplemental Arrows-B at http://www.unicode.org/charts/PDF/U2B00.pdf

string
CliffWalkingProblem::useBlackArrow( int action )
{
       if ( action == 0 ) return "\u2b06"; // Upwards black arrow
  else if ( action == 1 ) return "\u2b07"; // downwards black arrow
  else if ( action == 2 ) return "\u2b05"; // Leftwards black arrow
  else if ( action == 3 ) return "\u27a1"; // rightwards black arrow
  else if ( action == 4 ) return "\u2b09"; // North west black arrow
  else if ( action == 5 ) return "\u2b08"; // North east black arrow
  else if ( action == 6 ) return "\u2b0b"; // South west black arrow
  else if ( action == 7 ) return "\u2b0a"; // South east black arrow
  else if ( action == 8 ) return " ";      // Pause
}
