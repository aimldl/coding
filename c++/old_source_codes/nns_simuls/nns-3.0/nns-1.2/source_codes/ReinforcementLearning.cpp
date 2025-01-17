#include  "ReinforcementLearning.hpp"
#include  "Config.hpp"
#include  <cmath>  // For ceil

//==============================================================================
//                     Definition of static variables
//==============================================================================

int
ReinforcementLearning::maxNumberOfEpisodes_;

vdouble
ReinforcementLearning::rewardVector_;

double
ReinforcementLearning::alpha_;

double
ReinforcementLearning::gamma_;

double
ReinforcementLearning::epsilon_;

string
ReinforcementLearning::updateMethod_;

string
ReinforcementLearning::actionCriterion_;

//==============================================================================
//                        Static Public functions
//==============================================================================

// IMPORTANT! RUN THESE FUNCTIONS BEFORE THIS CLASS IS CONSTRUCTED!!!
void
ReinforcementLearning::configure( Config& configObj )
{
  cout << "ReinforcementLearning::configure()" << endl;

  maxNumberOfEpisodes_ = configObj.get_rlObj_().get_maxNumberOfEpisodes_();
  rewardVector_        = configObj.get_rlObj_().get_rewardVector_();
  alpha_               = configObj.get_rlObj_().get_alpha_();
  gamma_               = configObj.get_rlObj_().get_gamma_();
  epsilon_             = configObj.get_rlObj_().get_epsilon_();
  updateMethod_        = configObj.get_rlObj_().get_updateMethod_();
  actionCriterion_     = configObj.get_rlObj_().get_actionCriterion_();

}
// IMPORTANT! RUN THESE FUNCTIONS BEFORE THIS CLASS IS CONSTRUCTED!!!

//==============================================================================
//                        Static Private functions
//==============================================================================
//==============================================================================
//                            Public functions
//==============================================================================

ReinforcementLearning::ReinforcementLearning()
{
}

ReinforcementLearning::~ReinforcementLearning()
{
}

void
ReinforcementLearning::initialize()
{
}

void
ReinforcementLearning::initializeQ_()
{
  assert( (numOfStates_>0) && (numOfActions_>0) );
  assert( !actionCriterion_.empty() );

  Q_ = new double* [ numOfStates_ ];
  for ( int s = 0; s < numOfStates_; s++ )
    Q_[s] = new double [ numOfActions_ ];

  // Design issue: the values in Q_ needs to be randomized.
  //   When the values are set to zero and an egreedy algorithm is selected,
  //   no updates will result in an infinite loop
  for ( int s = 0; s < numOfStates_; s++ )
    for ( int a = 0; a < numOfActions_; a++ )
    {
      if ( actionCriterion_ == "egreedy" )
      Q_[s][a] = 0.0;
      else if ( actionCriterion_ == "greedy" )
        Q_[s][a] = rv_.uniform();
    }
}

void
ReinforcementLearning::runSimulation( bool showProgressBar )
{

}
//==============================================================================
//                            Protected functions
//==============================================================================

int
ReinforcementLearning::chooseAction( int state, string actionCriterion )
{
  assert( !actionCriterion.empty() );

  int action;

  if ( actionCriterion == "egreedy" )
    action = eGreedy( state );
  else if ( actionCriterion == "greedy" )
  action = argmax( Q_[ state ] );  // This is a greedy action

  return action;
}

int
ReinforcementLearning::eGreedy( int state )
{
  int    action;
  double randomNumber = rv_.uniform();

  if ( randomNumber >= epsilon_ )  //// This is a greedy action
    action = argmax( Q_[ state ] );
  else
    action = rv_.uniformInteger( 0,numOfActions_-1 );

  return action;
}

// Get the first max count
int
ReinforcementLearning::argmax( double* vector )
{
  int    maxCount = 0;
  double maxValue = vector[0];

  for ( int ii = 1; ii < numOfActions_; ii++ )
  {
    if ( vector[ii] > maxValue )
    {
      maxValue = vector[ii];
      maxCount = ii;
    }
  }
  return maxCount;
}

void
ReinforcementLearning::logErrorProfileHeader()
{
  eout << "Simulation configuration" << "\n"
       << "  alpha_               = " << alpha_ << "\n"
       << "  gamma_               = " << gamma_ << "\n"
       << "  epsilon_             = " << epsilon_ << "\n"
       << "  updateMethod_        = " << updateMethod_ << "\n"
//       << "  moveOption_          = " << moveOption_ << "\n"
       << "  actionCriterion_     = " << actionCriterion_ << "\n"
       << "  maxNumberOfEpisodes_ = " << maxNumberOfEpisodes_ << "\n";

  for ( int i=0; i<rewardVector_.size(); i++ )
    eout << "  rewardVector_[" << i << "]     = " << rewardVector_.at(i) << "\n";
  eout << endl;
  eout << "episode" << "\t" << "totalRewards" << endl;
}

//==============================================================================
//                            Private functions
//==============================================================================
