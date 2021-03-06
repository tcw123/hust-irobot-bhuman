/**
 * BehaviorControl 2018 implementation of HeadControl
 */

#pragma once

#include "Modules/BehaviorControl/BehaviorControl/Tools/BehaviorOption.h"

#include "Representations/Infrastructure/FrameInfo.h"
#include "Representations/Infrastructure/GameInfo.h"
#include "Representations/Infrastructure/JointAngles.h"
#include "Representations/MotionControl/HeadMotionEngineOutput.h"
#include "Representations/Sensing/GroundContactState.h"
#include "Representations/Modeling/BallModel.h"
#include "Representations/MotionControl/MotionInfo.h"

#include "Tools/Cabsl.h"

BEHAVIOR_OPTION(HeadControl2018, BehaviorOptionInterface,
{,
    REQUIRES(BallModel),
    REQUIRES(MotionInfo),
  REQUIRES(FrameInfo),
  REQUIRES(GameInfo),
  REQUIRES(GroundContactState),
  REQUIRES(HeadMotionEngineOutput),
  REQUIRES(JointAngles),
  MODIFIES(HeadMotionRequest),
  MODIFIES(HeadControlMode),
    MODIFIES(MotionRequest),
});

class HeadControl2018 : public HeadControl2018Base, public Cabsl<HeadControl2018>
{
#include "Modules/BehaviorControl/BehaviorControl/Options/HeadControl/LookForward.h"
//#include "Modules/BehaviorControl/BehaviorControl/Options/HeadControl/LookAround.h"
//#include "Modules/BehaviorControl/BehaviorControl/Options/HeadControl/LookAtBall.h"
#include "Modules/BehaviorControl/BehaviorControl/Options/Output/HeadMotionRequest/SetHeadPanTilt.h"
//#include "Modules/BehaviorControl/BehaviorControl/Options/Output/HeadMotionRequest/SetHeadTargetOnGround.h"
//#include "Modules/BehaviorControl/BehaviorControl/Options/Output/MotionRequest/Stand.h"

public:
  HeadControl2018();

private:
  void execute() override;
};
