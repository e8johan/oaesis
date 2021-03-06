#ifndef	__GLOBAL__
#define	__GLOBAL__

#include "srv_appl_info.h"
#include "types.h"

#define	STKSIZE	4096

typedef struct globalvars {
  int     vid;	      /* physical vdi id of the screen */
  WORD    vmode;
  WORD    vmodecode;
  RECT    screen;     /* size of physical screen */	

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

  AP_LIST_REF applmenu;
  AP_LIST_REF accmenu;
	
  WORD    arrowrepeat;
	
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

  WORD    srvpid;
}GLOBALVARS;

extern GLOBALVARS	globals;

/*
** Description
** Initialize global variables
**
** 1999-01-09 CG
*/
void
srv_init_global (WORD physical);


/*
** Description
** Close down
**
** 1999-01-09 CG
*/
void
srv_exit_global (void);

#endif

