 /************************************************************************/
 /*                                                                      */
 /*                Centre for Speech Technology Research                 */
 /*                     University of Edinburgh, UK                      */
 /*                       Copyright (c) 1996,1997                        */
 /*                        All Rights Reserved.                          */
 /*                                                                      */
 /*  Permission is hereby granted, free of charge, to use and distribute */
 /*  this software and its documentation without restriction, including  */
 /*  without limitation the rights to use, copy, modify, merge, publish, */
 /*  distribute, sublicense, and/or sell copies of this work, and to     */
 /*  permit persons to whom this work is furnished to do so, subject to  */
 /*  the following conditions:                                           */
 /*   1. The code must retain the above copyright notice, this list of   */
 /*      conditions and the following disclaimer.                        */
 /*   2. Any modifications must be clearly marked as such.               */
 /*   3. Original authors' names are not deleted.                        */
 /*   4. The authors' names are not used to endorse or promote products  */
 /*      derived from this software without specific prior written       */
 /*      permission.                                                     */
 /*                                                                      */
 /*  THE UNIVERSITY OF EDINBURGH AND THE CONTRIBUTORS TO THIS WORK       */
 /*  DISCLAIM ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING     */
 /*  ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT  */
 /*  SHALL THE UNIVERSITY OF EDINBURGH NOR THE CONTRIBUTORS BE LIABLE    */
 /*  FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES   */
 /*  WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN  */
 /*  AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION,         */
 /*  ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF      */
 /*  THIS SOFTWARE.                                                      */
 /*                                                                      */
 /*************************************************************************/


#ifndef __EST_FRINGE_CLIENT_H__
#define __EST_FRINGE_CLIENT_H__

#include "EST_String.h"
#include "EST_rw_status.h"
#include "EST_TKVL.h"
#include "EST_Server.h"

/** A class providing mechanisms to talk to fringe.
  * 
  * @author Richard Caley <rjc@cstr.ed.ac.uk>
  * @version $Id: EST_FringeServer.h,v 1.2 2001/04/04 13:11:27 awb Exp $
  */
class EST_FringeServer : public EST_Server
{
public:

  class ResultHandler : public EST_Server::ResultHandler
  {
  public:
    ResultHandler();
    virtual void process(void);
    virtual ~ResultHandler();
  };
  
  /// Create a server connection by name, defaulting to "fringe", the default server name.
  EST_FringeServer(EST_String name="fringe");

  EST_FringeServer(EST_String name, ostream *trace);

  /// Create a server connection by explicitly saying where to connect to.
  EST_FringeServer(EST_String hostname, int port);
  EST_FringeServer(EST_String hostname, int port, ostream *trace);
  
  /// Destroy the connection.
  ~EST_FringeServer();

  virtual bool parse_command(const EST_String command,
			     EST_String &package,
			     EST_String &operation,
			     Args &arguments);

  virtual EST_String build_command(const EST_String package,
				   const EST_String operation,
				   const Args &arguments);

  virtual bool parse_result(const EST_String resultString,
			    Result &res);

  virtual EST_String build_result(const Result &res);
};

#endif

