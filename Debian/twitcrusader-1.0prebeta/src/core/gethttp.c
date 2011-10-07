/*
 *	TwitCrusader - Twitter Client For Linux Desktop
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

#include "inc/gethttp.h"


size_t write_function( void *ptr, size_t size, size_t nmemb, void *stream){

	debug_f_start("write_function");

	fwrite(ptr, size, nmemb, (FILE *)stream);
	return nmemb*size;
};

void get_single_CURL(char *url, char *file){

	debug_f_start("get_single_CURL");


	char *argv[2];
	argv[0]=(char *)malloc(sizeof(char)*255);
	strcpy(argv[0],url);
	argv[1]=(char *)malloc(sizeof(char)*255);
	strcpy(argv[1],file);

	pull_one_url(argv);
}


void *pull_one_url(void *argv){

	debug_f_start("pull_one_url");

	CURL *curl;
	FILE *destFile;

	char **argv2=(char **)argv;
	char *url=(char *)argv2[0];
	char *file=(char *)argv2[1];

	debug_var_char("url",url);
	debug_var_char("file",file);

	if(url!=NULL && file!=NULL){

		curl = curl_easy_init();

		if(curl) {

			curl_easy_setopt(curl, CURLOPT_URL, url);
			curl_easy_setopt(curl, CURLOPT_VERBOSE, 1);

			// Open the file to write the copied file to
			destFile = fopen(file,"w+b");

			// Tell libcurl where to write the file
			curl_easy_setopt(curl,CURLOPT_WRITEFUNCTION,write_function);
			curl_easy_setopt(curl,CURLOPT_WRITEDATA,destFile);
			curl_easy_perform(curl);

			/* always cleanup */
			fclose(destFile);
			curl_easy_cleanup(curl);
		}
	}

	return 0;
}