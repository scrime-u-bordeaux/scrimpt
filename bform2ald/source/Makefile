# ----------------------------------------------------------------------------
#
#  Copyright (C) 2008-2016 Fons Adriaensen <fons@linuxaudio.org>
#    
#  This program is free software; you can redistribute it and/or modify
#  it under the terms of the GNU General Public License as published by
#  the Free Software Foundation; either version 3 of the License, or
#  (at your option) any later version.
#
#  This program is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU General Public License for more details.
#
#  You should have received a copy of the GNU General Public License
#  along with this program.  If not, see <http://www.gnu.org/licenses/>.
#
# ----------------------------------------------------------------------------


PREFIX = /usr/local
VERSION = 0.1.0
CXXFLAGS += -O2 -Wall
CPPFLAGS += -DVERSION=\"$(VERSION)\" -DPREFIX=\"$(PREFIX)\"


all:	bform2ald makemulti


BFORM2ALD_O =	bform2ald.o impdata.o
bform2ald : LDLIBS += -lsndfile -lrt
bform2ald:	$(BFORM2ALD_O)
	g++ -o $@ $(BFORM2ALD_O) $(LDLIBS)


MAKEMULTI_O =	makemulti.o audiofile.o dither.o
makemulti : LDLIBS += -lsndfile -lrt
makemulti:	$(MAKEMULTI_O)
	g++ $(LDFLAGS) -o $@ $(MAKEMULTI_O) $(LDLIBS)


install:	all
	install -m 755 bform2ald $(PREFIX)/bin
	install -m 755 makemulti $(PREFIX)/bin

clean:
	/bin/rm -f *~ *.o *.a *.so bform2ald makemulti


