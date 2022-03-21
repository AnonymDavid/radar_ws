// ######################################
// #			START OF EGOLF			#
// ######################################



/**
 * Message EGOLF SPEED id.
 */
#define ID_EGOLF_SPEED                           0x11E
#define GET_EGOLF_SPEED_KPH(buf) (0 \
	| (uword)(+(uword)((buf[5] >> 0) & 0xff) << 8) \
	| (ubyte)(+(ubyte)((buf[6] >> 0) & 0xff) << 0) \
)
#define CALC_EGOLF_SPEED_KPH(x, fmt) \
	((x) * fmt * 0.0078125)
	
/**
 * Message EGOLF_ACC_PEDAL id.
 */
#define ID_ACC_PEDAL                            	0x391
#define GET_ACC_PEDAL(buf) (0 \
	| (ubyte)(+(ubyte)((buf[4] >> 0) & 0xff) << 0) \
)
#define CALC_GPS_YAW_X_YAW(x, fmt) \
	((x) * fmt * 0.61 + (-21.96))
	
/**
 * Message EGOLF STEERING id.
 */
#define ID_STEERING                           0x086
#define GET_STEERING(buf) (0 \
	| (uword)(+(uword)((buf[2] >> 0) & 0xff) << 5) \
	| (ubyte)(+(ubyte)((buf[3] << 3) & 0xff) >> 3) \
)
#define CALC_STEERING(x, fmt) \
	((x) * fmt * 0.1)
	
/**
 * Message BRAKE_PEDAL id.
 */
#define ID_BRAKE_PEDAL                           0xB3
#define GET_BRAKE_PEDAL(buf) (0 \
	| (ubyte)(+(ubyte)((buf[3] >> 0) & 0xff) << 0) \
)
#define CALC_BRAKE_PEDAL(x, fmt) \
	((x) * 0.952380952380952 + (-0.9524))
	

// ##################################
// #			END OF EGOLF			#
// ##################################
