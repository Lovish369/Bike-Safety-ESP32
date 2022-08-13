#include <vector>
#include <string>

#include "config.h"

namespace config{
  /*std::vector<std::string> LABELS_NAMES = {
     "Pushup",
     "Pushup_Incorrect",
     "Squat",
     "Situp",
     "Situp_Incorrect",
     "Jumping",
     "Lunge"
  };*/

std::vector<std::string> LABELS_NAMES = {
     "STRAIGHT",
     "BUMP",
     "LEFT",
     "RIGHT",
     "STOP",
       
   };

   int N_FEATURES = 7;
   int SEGMENT_TIME_SIZE = 104;
}
