
/*********************************************************************************************

    This is public domain software that was developed by or for the U.S. Naval Oceanographic
    Office and/or the U.S. Army Corps of Engineers.

    This is a work of the U.S. Government. In accordance with 17 USC 105, copyright protection
    is not available for any work of the U.S. Government.

    Neither the United States Government, nor any employees of the United States Government,
    nor the author, makes any warranty, express or implied, without even the implied warranty
    of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE, or assumes any liability or
    responsibility for the accuracy, completeness, or usefulness of any information,
    apparatus, product, or process disclosed, or represents that its use would not infringe
    privately-owned rights. Reference herein to any specific commercial products, process,
    or service by trade name, trademark, manufacturer, or otherwise, does not necessarily
    constitute or imply its endorsement, recommendation, or favoring by the United States
    Government. The views and opinions of authors expressed herein do not necessarily state
    or reflect those of the United States Government, and shall not be used for advertising
    or product endorsement purposes.
*********************************************************************************************/


/****************************************  IMPORTANT NOTE  **********************************

    Comments in this file that start with / * ! or / / ! are being used by Doxygen to
    document the software.  Dashes in these comment blocks are used to create bullet lists.
    The lack of blank lines after a block of dash preceeded comments means that the next
    block of dash preceeded comments is a new, indented bullet list.  I've tried to keep the
    Doxygen formatting to a minimum but there are some other items (like <br> and <pre>)
    that need to be left alone.  If you see a comment that starts with / * ! or / / ! and
    there is something that looks a bit weird it is probably due to some arcane Doxygen
    syntax.  Be very careful modifying blocks of Doxygen comments.

*****************************************  IMPORTANT NOTE  **********************************/



/*  gsfMonitor class definitions.  */

#ifndef GSFMONITOR_H
#define GSFMONITOR_H

#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <getopt.h>
#include <cmath>

#include "nvutility.h"
#include "pfm.h"
#include "fixpos.h"
#include "pfm_extras.h"
#include "nvmap.hpp"
#include "ABE.h"
#include "gsf.h"
#include "check_flag.h"
#include "version.hpp"

#ifdef NVWIN3X
    #include "windows_getuid.h"
#endif

#include <QtCore>
#include <QtGui>
#if QT_VERSION >= 0x050000
#include <QtWidgets>
#endif


class gsfMonitor:public QMainWindow
{
  Q_OBJECT 


public:

  gsfMonitor (int32_t *argc = 0, char **argv = 0, QWidget *parent = 0);
  ~gsfMonitor ();


protected:

  int32_t             key;

  uint32_t            kill_switch;

  char                progname[256];

  QSharedMemory       *abeShare;

  ABE_SHARE           *abe_share;

  QTextEdit           *listBox;

  int32_t             width, height, window_x, window_y;

  QPushButton         *bRestoreDefaults; 

  uint8_t             force_redraw, lock_track;

  uint32_t            ac[1];

  int32_t             pos_format;

  QButtonGroup        *bGrp;

  QDialog             *prefsD;

  QToolButton         *bQuit, *bPrefs;

  QFont               font;                       //  Font used for all ABE GUI applications


  void envin ();
  void envout ();

  void closeEvent (QCloseEvent *);


protected slots:

  void slotResize (QResizeEvent *e);
  
  void trackCursor ();

  void slotHelp ();

  void slotQuit ();

  void slotPrefs ();
  void slotPosClicked (int id);
  void slotClosePrefs ();

  void slotRestoreDefaults ();
  
  void about ();
  void aboutQt ();


 private:

};

#endif
