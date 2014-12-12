---
layout: page
title: Getting started
permalink: /start/
---
Preparing datasets
==================

**Knossos** needs image data in a special format. The `knossos_cuber` is a Python script that is used to convert an image dataset into this format. You can download the script here: [knossos_cuber]({{ "/downloads/knossos_cuber.zip" | prepend: site.baseurl }}).

To be able to run the Python script, make sure you have the following dependencies installed:

*   numpy
*   scipy
*   Pillow
*   PyQt4 (if you use the GUI, more about that below)

Those dependencies can usually be instead using `pip`.

There are two ways to run the script: From the Command-Line or by using the GUI.

If you run the script from the Command-Line, you get the following output:

    $ python knossos_cuber.py
    Usage: knossos_cuber.py [input directory] [output directory] [tif|jpg|png]
    Example: knossos_cuber.py input output tif

The script expects 3 options:

1.  The folder to your image dataset,
2.  the destination folder,
3.  and the file format of your images.

At present, `*.tif`, `*.jpg`, and `*.png` files are supported.

Running the script from the Command-Line with these 3 options will result in `knossos_cuber` using a default configuration on your image data. If you need to adjust some settings, right now it is best to use the GUI for that:

    $ python knossos_cuber_gui.py

Make sure to look at the following options:

1.  Specifiy the paths of `source` and `target` directory.
2.  Select the format of your image files in the drop-down menu.

    (Right now, `Source dimensions x` and `y` do not need to be filled in, since the script will get the dimensions from the image itself.)
3.  Click on the "Advanced" tab to see and adjust more options. Additional information for every option can be viewed by hovering over it.

Start the job and check the output console for the job's progress. After it has finished, start **Knossos** and load the generated `.conf` file. It should be located in the `mag1` directory inside the destination folder.

* * *

**Knossos** Quickstart Guide
============================

Moving around
-------------

**Knossos'** main window is split into four parts ("viewports"):

*   The first three viewports represent each `x/y/z` plain respectively.
*   The fourth viewport displays a 3D view on the data.
*   Click and drag in a viewport to move along that plane.
*   Press `d/f` or scroll to move orthogonally.
*   Zoom in our out with `Ctrl+Scroll` (for the 3D viewport: only `Scroll`).


Skeletonization
---------------

**Knossos'** main feature, skeletonization, is used to accurately reconstruct an object by tracing nodes and segments:

*   Nodes are placed with a right-click. Consecutive nodes are automatically connected with a segment.
*   Open the *Tree View* (`Windows - Annotation Window`) for an overview of your current skeleton.



* * *


Saving/Autosaving/Loading
-------------------------
*   Before you start tracing, choose a folder and a file name for your skeleton data by pressing "File" and "Save as" in the menu bar of KNOSSOS.
*   The skeleton data will be saved automatically every five minutes if changes have been made.
*   Skeleton files can be loaded into KNOSSOS by choosing "File" and "Load". Alternatively, you can also choose between recently saved files by pressing "Files" and "Recent Files".


Basic Viewport Handling
-----------------------
*   To move through the dataset place the mouse cursor in one of the three slice plane viewports and
    *   press "f" or "d" or use the arrow keys: Moves one layer forward or backward.
    *   Press "f" or "d" in combatination with "SHIFT": Jumps ten layers forward or backward.
    *   Press "e" or "r": Moves x layers forward or backward, where x can be defined under "Preferences" -> "Dataset *  Navigation" -> "Walk frames".
    *   move the mouse wheel up or down to slowly move through the dataset.
    *   Press the left mouse button
        *   and pull the stack in the desired destination (if "View" -> "Work Mode" is "Drag Dataset").
        *   and KNOSSOS centers on that point (if "View" -> "Work Mode" is "Recenter on Click").
*   To translate/rotate in the skeleton viewport press and hold the left/right mouse button inside the skeleton viewport and drag.
*   To zoom into the dataset or into the skeleton viewport place the mouse cursor in one of the four viewports and press "i" or "o" to zoom in/out.
*   To resize or move the viewports use the two buttons inside the viewports. To restore the standard positions and sizes click the button "Use Standard Positions and Sizes" in the "Viewport Settings" window, where you can also toggle the buttons' visibility.


Skeleton tracing
----------------
*   Nodes are placed by a right click in one of the three slice plane viewports and are automatically linked to the last node. To just "drop" nodes without linking you have to change the work mode via "Edit Skeleton" and "Work Mode" in the menu bar.
*   The currently active node can be recognized by its number which appears beside the point or via the Tools window.
*   You can activate a node by holding down the "SHIFT" button and left-clicking it or by simply entering the desired node ID in the „Active Node ID“ field of the "tools" window. Press "x"/"x"+"SHIFT" in one of the viewports to activate the next/previous node. To change the active tree press "y" or "SHIFT" + "y".
*   To jump to the active node press "s" or click on "Jump to node" in the Tools window.
*   You can delete the active node by pressing "DEL" on your keyboard or by clicking on "Delete Node" in the Tools window.
*   If you want to reposition a node, simply click on the node with the middle mouse button and drag it to another position. The node does not have to be your active node.
*   You can add branch nodes by holding "CTRL" when pressing the right mouse button. To transform a normal node to a branch node press "b" or choose "Push Branch Node" in the Tools window. To jump to the last placed branch node, press "j" or use "Pop & Jump" in the Tools window. This transforms the branch node to a normal node.
*   Different node colors indicate different node types:
*   Blue: Branch node
*   Yellow: Commented node (will be blue, if it is also a branch node)
*   Red: Normal node
*   To link two non-connected nodes or to unlink two connected nodes activate one of them, hold "ALT" and left click the second node or hold "SHIFT" and click on the second node with the mouse wheel. Alternatively this can also be done in the Tools window.
*   If you want to delete a huge part of the skeleton, isolate this part by unlinking the corresponding nodes and pressing "Split Last Component From Tree". This divides this tree in two trees; using "Delete Active Tree" deletes this part. The Button "Merge Trees" merges two trees into one tree.


Comments
--------
*   You can add a comment on every tree and on every node by using the textboxes in the Tools window.
*   If you use some comments regularly, you can enter them in the Comment Tools window and add them to the active node by pressing "F1" - "F5".
*   In the Comment Tools window you can also change the comment preferences. In addition, there is a summary of all comments of the whole skeleton.

![comments]()


Overview Keyboard Shortcuts
---------------------------

<div class="row">

<div class="six columns">

|        |          |
|:------:|:---------|
| Arrow keys / f / d | move one layer
| SHIFT + Arrow keys / f / d | jump ten layers
| r / e | move ten layers
| i / o | zoom in / out
| b / j | create / jump to branch node
| s | jump to active node
| DEL | delete active node

</div>

<div class="six columns">

|        |          |
|:------:|:---------|
| x, SHIFT + x | next / previous node
| c | new tree
| y | next tree
| a / w | switch work mode to add / link node
| F1 - F5 | add user defined comments to node
| n / p | next / previous commented node
| 1 | enable / disable skeleton overlay
| 3 | draw / hide viewport crosshairs
| CTRL + v | paste coordinates
| CTRL + s | save skeleton

</div>

</div>

