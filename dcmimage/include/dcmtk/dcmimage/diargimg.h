/*
 *
 *  Copyright (C) 1996-2010, OFFIS e.V.
 *  All rights reserved.  See COPYRIGHT file for details.
 *
 *  This software and supporting documentation were developed by
 *
 *    OFFIS e.V.
 *    R&D Division Health
 *    Escherweg 2
 *    D-26121 Oldenburg, Germany
 *
 *
 *  Module:  dcmimage
 *
 *  Author:  Joerg Riesmeier
 *
 *  Purpose: DiARGBImage (Header)
 *
 *  Last Update:      $Author: joergr $
 *  Update Date:      $Date: 2010-10-21 08:55:45 $
 *  CVS/RCS Revision: $Revision: 1.12 $
 *  Status:           $State: Exp $
 *
 *  CVS/RCS Log at end of file
 *
 */


#ifndef DIARGIMG_H
#define DIARGIMG_H

#include "dcmtk/config/osconfig.h"

#include "dcmtk/dcmimage/dicoimg.h"


/*------------------------*
 *  forward declarations  *
 *------------------------*/

class DiLookupTable;


/*---------------------*
 *  class declaration  *
 *---------------------*/

/** Class for ARGB images
 */
class DiARGBImage
  : public DiColorImage
{

 public:

    /** constructor
     *
     ** @param  docu    pointer to dataset (encapsulated)
     *  @param  status  current image status
     */
    DiARGBImage(const DiDocument *docu,
                const EI_Status status);

    /** destructor
     */
    virtual ~DiARGBImage();

    /** process next couple of frames
     *
     ** @param  fcount  number of frames to be processed (0 = same number as before)
     *
     ** @return status, true if successful, false otherwise
     */
    virtual int processNextFrames(const unsigned long fcount);


 protected:

    /** initialize internal data structures and member variables
     */
    void Init();


 private:

    /// three color palettes for R, G and B
    DiLookupTable *Palette[3];

 // --- declarations to avoid compiler warnings

    DiARGBImage(const DiARGBImage &);
    DiARGBImage &operator=(const DiARGBImage &);
};


#endif


/*
 *
 * CVS/RCS Log:
 * $Log: diargimg.h,v $
 * Revision 1.12  2010-10-21 08:55:45  joergr
 * Added private undefined copy constructor and assignment operator in order to
 * avoid compiler warnings (reported by gcc with additional flags).
 *
 * Revision 1.11  2010-10-14 13:16:29  joergr
 * Updated copyright header. Added reference to COPYRIGHT file.
 *
 * Revision 1.10  2009-11-25 14:38:55  joergr
 * Adapted code for new approach to access individual frames of a DICOM image.
 *
 * Revision 1.9  2005/12/08 16:01:24  meichel
 * Changed include path schema for all DCMTK header files
 *
 * Revision 1.8  2003/12/17 18:07:12  joergr
 * Removed leading underscore characters from preprocessor symbols (reserved
 * symbols).
 *
 * Revision 1.7  2001/11/09 16:39:10  joergr
 * Updated/Enhanced comments.
 *
 * Revision 1.6  2001/06/01 15:49:26  meichel
 * Updated copyright header
 *
 * Revision 1.5  2000/03/08 16:21:48  meichel
 * Updated copyright header.
 *
 * Revision 1.4  1999/04/28 12:51:54  joergr
 * Corrected some typos, comments and formatting.
 *
 * Revision 1.3  1998/11/27 13:39:30  joergr
 * Added copyright message.
 *
 * Revision 1.2  1998/05/11 14:53:07  joergr
 * Added CVS/RCS header to each file.
 *
 *
 */
