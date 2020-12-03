
#include <bur/plctypes.h>
#ifdef __cplusplus
	extern "C"
	{
#endif
	#include "DriveLib.h"
#ifdef __cplusplus
	};
#endif
/* TODO: Add your comment here */
void LedStateMachine(struct LedStateMachine* inst)
{
	switch(inst->state){
		case ST_UNKNOWN:
			if(inst->timer == 10){
				inst->led1 = !inst->led1;
				inst->led2 = !inst->led2;
				inst->led3 = !inst->led3;
				inst->led4 = !inst->led4;
				inst->timer = 0;
			}
			break;
		case ST_CLOSE:
			inst->led1 = 1;
			inst->led2 = 1;
			inst->led3 = 1;
			inst->led4 = 1;
			break;
		case ST_INIT:
		case ST_OPEN:
			inst->led1 = 0;
			inst->led2 = 0;
			inst->led3 = 0;
			inst->led4 = 0;
			break;
		case ST_ACC_POS:
		case ST_DEC_NEG:
			inst->led1 = 1;
			inst->led2 = 1;
			inst->led3 = 1;
			inst->led4 = 0;
			break;
		case ST_POS:
		case ST_NEG:
			inst->led1 = 1;
			inst->led2 = 1;
			inst->led3 = 0;
			inst->led4 = 0;
			break;
		case ST_DEC_POS:
		case ST_ACC_NEG:
			inst->led1 = 1;
			inst->led2 = 0;
			inst->led3 = 0;
			inst->led4 = 0;
			break;
	}
	inst->timer++;
}
