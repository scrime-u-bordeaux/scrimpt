# SCRIMPT (scripts from [SCRIME](https://scrime.u-bordeaux.fr/))

1. Description:

 Automated update for Debian based systems with aditional audiovisual bundles

2. Installation:

 We recomend you install these sripts on the most recent version of your chosen Ubuntu based distribution. We also recomend you turn on the developpement option in your update manager.
 
 * Make sure you have git installed <br />
 ```sudo apt install git``` <br />
 * Choose a place to clone this repository and clone it with <br />
 ```git clone https://github.com/scrime-u-bordeaux/scrimpt.git``` <br />
 * cd into it <br />
 ```cd scrimpt``` <br />
 * Install it locally with  <br />
 ```./up --install``` <br />
 This will create a ```bin``` directory in your ```HOME``` if it dose'nt yet exist, donload and add the [kxstudio repository](https://kx.studio/Repositories), as well as compile and install Fonz Adriensen [utilities for use with Aliki](https://escuta.org/en/proj/research/ambiresources/item/227-making-impulse-responses-with-aliki.html) and Iain Mott's [binaural and UHJ render script](https://escuta.org/en/proj/research/ambiresources/item/229-b-format-to-binaural-uhj-stereo.html). the kxstudio repository adddition is sometimes error prone, altho if the first install fails, running the comand a second time often does the trick.
 * If you dind't have a ```bin``` directory in your ```HOME``` you will need to log out and back in for the scripts to be accessible from comand line. If evrything went well, you can now simply call ```up``` ```repos <program> <jobs>```
 ```bformat2ald``` or ```renderbinauralUHJ``` from the comand line. 
 * You can for exemple build and install ossia-score with <br />
 ```repos --score 8``` <br />
 You can also combine ```up``` and ```repos``` to make sure that a full upgrande is performed before the build, ie. <br />
 ```up --repos --ossia 8``` <br />
 The entire list of repository cen also be built with <br />
 ```repos --all 8``` <br />
 This will take a long while and require to enter your admin password a few times. make sure you give it as many jobs as possible with last argument (8 here). 
 
3. License.

 Up is free software. You can redistribute it and/or modify it under the
 terms of the GNU General Public License Version 2.0. as published by
 the Free Software Foundation. A copy of the GNU GPL 2.0 is provided with the
 software.

4. Contents of Help Page:

 Up -- Debian/Ubuntu Update Tool (Version 1.2)  -help

 Up is a tool that automates the update procedure for Debian and Ubuntu based
 Linux systems.

 Press "q" to exit this Help page.

 Commands:
    up = full system update.
    
    Running "up" with no options will update the apt cache and then perform a
    full distribution update automatically.

    up --remove = full system update with orphaned packages removed.
    up --clean = full system update with full cleanup.

    Adding the "--clean" option will invoke the apt commands to search for and
    remove locally cached packages that are no longer in the repositories and
    remove orphaned packages that are no longer needed by programs. 

    The "--remove" option only removes orphaned packages, leaving the apt cache
    alone. 

    up --help = shows this help page.

 By Joe Collins www.ezeelinux.com (GNU/General Public License version 2.0)
 
 Disclaimer:

 THIS SOFTWARE IS PROVIDED BY EZEELINUX “AS IS” AND ANY EXPRESS OR IMPLIED
 WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO
 EVENT SHALL EZEELINUX BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
 BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER
 IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 POSSIBILITY OF SUCH DAMAGE.

_EOF_

