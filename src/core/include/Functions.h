/*
 *	 TwitCrusader-GUI++ - Twitter Client For Linux Desktop
 *		Copyright (C) 2011  TwitCrusader Team
 *
 *		This program is free software: you can redistribute it and/or modify
 *		it under the terms of the GNU General Public License as published by
 *		the Free Software Foundation, either version 3 of the License, or
 *		(at your option) any later version.
 *
 *		This program is distributed in the hope that it will be useful,
 *		but WITHOUT ANY WARRANTY; without even the implied warranty of
 *		MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *		GNU General Public License for more details.
 *
 *		You should have received a copy of the GNU General Public License
 *		along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 *
 *		WebSite: http://www.twitcrusader.org/
 * 		Development Guidelines: http://dev.twitcrusader.org/
 *		Follow on Twitter: @teamtwc
 * 		IRC: chat.freenode.net at #teamtwc
 * 		E-mail: teamtwc@twitcrusader.org
 *
 */

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <fstream>
#include <gtkmm.h>
#include <libnotify/notify.h>

#include "GetHTTP.h"
#include "Version.h"
#include "../../gui/include/Icons.h"

using  namespace std;

namespace TwitCrusader {

class Functions {

public:

	static string readRawTextFile(string fileName);
	static vector<Glib::ustring> readTextFileLinebyLine(string fileName);
	static bool shellParameters (int argc, char **argv);
	static string DownloadVersion();
	static void notifySystem(string Message);

};
}
#endif /* FUNCTIONS_H_ */
