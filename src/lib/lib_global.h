#ifndef	__GLOBAL__
#define	__GLOBAL__

#include	"types.h"

#define	STKSIZE	4096


/*
** global_common contains variables that are global across applications.
*/
typedef struct global_common {
  WORD    vid;	      /* physical vdi id of the screen */
  WORD    vmode;
  WORD    vmodecode;
  LONG    video;
  RECT    screen;     /* size of physical screen */	
  WORD    num_planes; /* number of bitplanes in the display */

  WORD    realmove;   /* if set realtime moving of windows is enabled */
  WORD    realsize;
  WORD    realslide;  /* if set realtime sliding of windows is enabled */
  WORD    wind_appl;  /* show application name in window mover */

  WORD fsel_extern;    /* set 1 to enable extern fileselectors */
  WORD fsel_sorted;    /* set 1 to have sorted directories with internal fileselecto r*/

  WORD graf_mbox;      /* set 1 to enable graf_mbox/graf_movebox */
  WORD graf_growbox;   /* set 1 to enable graf_growbox */
  WORD graf_shrinkbox; /* set 1 to enable graf_shrinkbox */

  WORD aes_trace;      /* set 1 to trace aes calls */

  WORD    num_pens;   /* number of available vdi pens */

  AP_LIST *applmenu;
  AP_LIST *accmenu;
	
  WORD    mouse_x;
  WORD    mouse_y;
  WORD    mouse_button;
	
  WORD    arrowrepeat;
  ULONG   time;
	
  WORD    cswidth;
  WORD    csheight;
  WORD    bswidth;
  WORD    bsheight;

  WORD    clwidth;
  WORD    clheight;
  WORD    blwidth;
  WORD    blheight;

  WORD    fnt_small_id; /* id & size of system fonts */
  WORD    fnt_small_sz;
  WORD    fnt_regul_id;
  WORD    fnt_regul_sz;

  WORD    icon_width;   /* Width of iconified window */
  WORD    icon_height;  /* Height of iconified window */

  OBJECT  *aiconstad;
  OBJECT  *alerttad;
  OBJECT  *deskbgtad;
  OBJECT  *fiseltad;
  OBJECT  *informtad;
  OBJECT  *menutad;
  OBJECT  *mouseformstad;
  OBJECT  *pmenutad;
  BYTE    **fr_string;

  /* Window elements resource and counters */
  OBJECT  * windowtad;
  WORD      elemnumber;
  WORD      tednumber;

  BYTE    mousename[30];
	
  WORD    mouse_owner;
  WORD    mouse_mode;

  WORD    srvpid;
  WORD    evntpid;
  WORD    applpid;

  OBJC_COLORWORD top_colour[20];
  OBJC_COLORWORD untop_colour[20];
}GLOBAL_COMMON;

/*
** global_appl contains variables that are global within a special application
*/
typedef struct global_appl {
  GLOBAL_COMMON * common;
  WORD            vid;
  void          * windows;
}GLOBAL_APPL;

void	init_global(WORD physical);
void	exit_global(void);

#ifdef MINT_TARGET
GLOBAL_COMMON * get_global_common (void);
GLOBAL_APPL   * get_globals (WORD apid);
#else
extern GLOBAL_APPL global_appl;
#define get_globals(apid) (&global_appl)
extern GLOBAL_COMMON global_common;
#define get_global_common() (&global_common)
#endif

#endif