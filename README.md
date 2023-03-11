Random Suggestions Mod
==========================

This mod is a prototype of random ideas from the `#suggestions` channel on the TPT Discord

**Additions:**

**OBMA** - *Obamium. Indestructible heat insulator. Edible.*

An indestructible heat insulator. Does not conduct SPRK. When eaten by STKM regenerates him to full health (ObamaCare).

**GRTM** - *Gravitonium. A liquid GPMP, gravity varies with temperature.*

Although the gravity produced is much weaker than GPMP's, and it can only maintain a temperature between +-256 C. It has low heat 
conductivity, when repelling it becomes bluish, when attracting becomes more green.

**GRPH** - *Graphite. Slow conductor, slows down neutrons*

- At around 4000 C instantly bursts into flame
- Begins turning into CO2 at 3600 C and emitting small plasma sparks
- Only conducts SPRK 1px at a time
- High heat conductivity
- Electrolyzes water into CO2 and H2
- Brittle, like TUNG depends on pressure difference. Additional resistance can be gained by heating up the GRPH
- Slows down neutrons inside it
- Converts molten IRON into molten METL
- Purifies WATR -> DSTW and SLTW -> DSTW + SALT
- Thin (1px thin) wires superconduct < 100 K

**GRPP** - *Graphite Powder.*

Same properties as graphite, but its auto-ignition temperature is 300 C lower. Also if it's over 3000 C and 20 pressure it will slowly
resolidify into solid graphite.

**HEC2** - *Instant heat conductor, because someone complained HEAC was slow.*

What it says on the tin.


The Powder Toy - January 2023
==========================

Get the latest version [from the Powder Toy website](https://powdertoy.co.uk/Download.html).

To use online features such as saving, you need to [register an account](https://powdertoy.co.uk/Register.html).
You can also visit [the official TPT forum](https://powdertoy.co.uk/Discussions/Categories/Index.html).

Have you ever wanted to blow something up? Or maybe you always dreamt of operating an atomic power plant? Do you have a will to develop your own CPU? The Powder Toy lets you to do all of these, and even more!

The Powder Toy is a free physics sandbox game, which simulates air pressure and velocity, heat, gravity and a countless number of interactions between different substances! The game provides you with various building materials, liquids, gases and electronic components which can be used to construct complex machines, guns, bombs, realistic terrains and almost anything else. You can then mine them and watch cool explosions, add intricate wirings, play with little stickmen or operate your machine. You can browse and play thousands of different saves made by the community or upload your own – we welcome your creations!

There is a Lua API – you can automate your work or even make plugins for the game. The Powder Toy is free and the source code is distributed under the GNU General Public License, so you can modify the game yourself or help with development.

Build instructions
===========================================================================

See the _Powder Toy Development Help_ section [on the main page of the wiki](https://powdertoy.co.uk/Wiki/W/Main_Page.html).

Thanks
===========================================================================

* Stanislaw K Skowronek - Designed the original
* Simon Robertshaw
* Skresanov Savely
* cracker64
* Catelite
* Bryan Hoyle
* Nathan Cousins
* jacksonmj
* Felix Wallin
* Lieuwe Mosch
* Anthony Boot
* Me4502
* MaksProg
* jacob1
* mniip
* LBPHacker

Libraries and other assets used
===========================================================================

* [BSON](https://github.com/interactive-matter/bson-c)
* [bzip2](http://www.bzip.org/)
* [FFTW](http://fftw.org/)
* [JsonCpp](https://github.com/open-source-parsers/jsoncpp)
* [libcurl](https://curl.se/libcurl/)
* [libpng](http://www.libpng.org/pub/png/libpng.html)
* [Lua](https://www.lua.org/)
* [LuaJIT](https://luajit.org/)
* [Mallangche](https://github.com/JammPark/Mallangche)
* [mbedtls](https://www.trustedfirmware.org/projects/mbed-tls/)
* [SDL](https://libsdl.org/)
* [zlib](https://www.zlib.net/)

Instructions
===========================================================================

Click on the elements with the mouse and draw in the field, like in MS Paint. The rest of the game is learning what happens next.

Controls
===========================================================================

| Key                     | Action                                                          |
| ----------------------- | --------------------------------------------------------------- |
| TAB                     | Switch between circle/square/triangle brush                     |
| Space                   | Pause                                                           |
| Q / Esc                 | Quit                                                            |
| Z                       | Zoom                                                            |
| S                       | Save stamp (use with Ctrl when STK2 is out)                     |
| L                       | Load last saved stamp                                           |
| K                       | Stamp library                                                   |
| 0-9                     | Set view mode                                                   |
| P / F2                  | Save screenshot as .png                                         |
| E                       | Bring up element search                                         |
| F                       | Pause and step to next frame                                    |
| G                       | Increase grid size                                              |
| Shift + G               | Decrease grid size                                              |
| H                       | Show/Hide HUD                                                   |
| Ctrl + H / F1           | Show intro text                                                 |
| D / F3                  | Debug mode (use with Ctrl when STK2 is out)                     |
| I                       | Invert Pressure and Velocity map                                |
| W                       | Cycle gravity modes (use with Ctrl when STK2 is out)            |
| Y                       | Cycle air modes                                                 |
| B                       | Enter decoration editor menu                                    |
| Ctrl + B                | Toggle decorations on/off                                       |
| N                       | Toggle Newtonian Gravity on/off                                 |
| U                       | Toggle ambient heat on/off                                      |
| Ctrl + I                | Install powder toy, for loading saves/stamps by double clicking |
| Backtick                | Toggle console                                                  |
| =                       | Reset pressure and velocity map                                 |
| Ctrl + =                | Reset Electricity                                               |
| \[                      | Decrease brush size                                             |
| \]                      | Increase brush size                                             |
| Alt + \[                | Decrease brush size by 1                                        |
| Alt + \]                | Increase brush size by 1                                        |
| Ctrl + C/V/X            | Copy/Paste/Cut                                                  |
| Ctrl + Z                | Undo                                                            |
| Ctrl + Y                | Redo                                                            |
| Ctrl + Cursor drag      | Rectangle                                                       |
| Shift + Cursor drag     | Line                                                            |
| Middle click            | Sample element                                                  |
| Alt + Left click        | Sample element                                                  |
| Mouse scroll            | Change brush size                                               |
| Ctrl + Mouse scroll     | Change vertical brush size                                      |
| Shift + Mouse scroll    | Change horizontal brush size                                    |
| Shift + R               | Horizontal mirror for selected area when pasting stamps         |
| Ctrl + Shift + R        | Vertical mirror for selected area when pasting stamps           |
| R                       | Rotate selected area counterclockwise when pasting stamps       |

Command Line
---------------------------------------------------------------------------

| Command               | Description                                      | Example                                     |
| --------------------- | ------------------------------------------------ | --------------------------------------------|
| `scale:SIZE`          | Change window scale factor                       | `scale:2`                                   |
| `kiosk`               | Fullscreen mode                                  |                                             |
| `proxy:SERVER[:PORT]` | Proxy server to use                              | `proxy:wwwcache.lancs.ac.uk:8080`           |
| `open FILE`           | Opens the file as a stamp or game save           |                                             |
| `ddir DIRECTORY`      | Directory used for saving stamps and preferences |                                             |
| `ptsave:SAVEID`       | Open online save, used by ptsave: URLs           | `ptsave:2198`                               |
| `disable-network`     | Disables internet connections                    |                                             |
| `disable-bluescreen`  | Disable bluescreen handler                       |                                             |
| `redirect`            | Redirects output to stdout.txt / stderr.txt      |                                             |
| `cafile:CAFILE`       | Set certificate bundle path                      | `cafile:/etc/ssl/certs/ca-certificates.crt` |
| `capath:CAPATH`       | Set certificate directory path                   | `capath:/etc/ssl/certs`                     |
