---
layout: page
title: Getting started
permalink: /start/
---
Preparing datasets
==================

**Knossos** needs image data in a special format. The `knossos_cuber` is a Python script that is used to convert an image dataset into this format. You can download the script here: [knossos_cuber](<a href="{{ "/downloads/knossos_cuber.zip" | prepend: site.baseurl }}">).

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
