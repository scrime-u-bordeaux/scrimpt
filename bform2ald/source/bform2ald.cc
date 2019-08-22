// ----------------------------------------------------------------------------
//
//  Copyright (C) 2008-2016 Fons Adriaensen <fons@linuxaudio.org>
//    
//  This program is free software; you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation; either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.
//
// ----------------------------------------------------------------------------


#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <getopt.h>
#include "impdata.h"


enum { HELP };


static struct option options [] = 
{
    { "help",  0, 0, HELP  },
    { 0, 0, 0, 0 }
};


static void help (void)
{
    fprintf (stderr, "\nbform2ald %s\n", VERSION);
    fprintf (stderr, "(C) 2008-2016 Fons Adriaensen  <fons@linuxaudio.org>\n");
    fprintf (stderr, "Create a B-format ald file from one or more 4-ch audio files.\n");
    fprintf (stderr, "Each input file becomes a section in the ald file.\n");
    fprintf (stderr, "Usage: bform2ald <options> <input files> <output file>\n");
    fprintf (stderr, "Options:\n");
    fprintf (stderr, "  --help    Display this text\n");
    exit (1);
}


static void procoptions (int ac, char *av [])
{
    int k;

    while ((k = getopt_long (ac, av, "", options, 0)) != -1)
    {
	switch (k)
	{
        case '?':
	case HELP:
	    help ();
	    break;
 	}
    }
}


int main (int ac, char *av [])
{
    int            i, r, ninp;
    unsigned int   len;
    Impdata       *inp;
    Impdata        out;

    procoptions (ac, av);
    ninp = ac - optind - 1;
    if (ninp < 1)
    {
        fprintf (stderr, "Missing arguments, try --help.\n");
	return 1;
    }

    inp = new Impdata [ninp];
    av += optind;
    len = 0;

    for (i = 0; i < ninp; i++)
    {
	r = inp [i].sf_open_read (av [i]);
	if (r)
	{
	    fprintf (stderr, "Can't read '%s'\n", av [i]);
	    return 1;
	}
	if (inp [i].n_chan () != 4)
	{
	    fprintf (stderr, "'%s' is not a 4-ch file\n", av [i]);
	    return 1;
	}
	if (len < inp [i].n_fram ()) len = inp [i].n_fram ();
    }

    out.set_type (Impdata::TYPE_AMB_B4);
    out.set_rate (inp [0].rate_n (), inp [0].rate_d ());
    out.set_n_sect (ninp);
    out.set_n_fram (len);
    r = out.open_write (av [ninp]);
    if (r)
    {
	fprintf (stderr, "Can't create '%s'\n", av [ninp]);
	return 1;
    }
    out.alloc ();

    for (i = 0; i < ninp; i++)
    {
	out.clear ();
        inp [i].read_ext (len, out.data (0));
        inp [i].close ();
	out.write_sect (i);
    }

    out.deall ();
    out.close ();
    delete[] inp;

    return 0;
}

