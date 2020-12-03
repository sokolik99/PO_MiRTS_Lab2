
#include <bur/plctypes.h>

#ifdef _DEFAULT_INCLUDES
	#include <AsDefault.h>
#endif

void _CYCLIC ProgramCyclic(void)
{
	DoorStateMachine(&doorSM);
	ledSM.state = doorSM.state;
	LedStateMachine(&ledSM);
	stateMachine.speed = doorSM.speed;
	DriveStateMachine(&stateMachine);
}
 ;