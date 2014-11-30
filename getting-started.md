---
layout: page
title: Getting started
permalink: /start/
---
Preparing datasets
==================

**Knossos** needs image data in a special format. The `knossos_cuber` (packaged with **Knossos'** installer) is used to convert images into this format. Currently, `.tif` and `RAW` image files are supported.

![KNOSSOS CUBBBBBERRR](knossos_cuber.png)

Make sure the following options are set:

1.  `source` and `target` directory.
    *   The source directory may only contain the image data which must be alphabetically ordered.
2.  The images' pixel dimensions (if you use `RAW` files).
3.  `x/y/z` scalings of your research data.
4.  The compression type (`JPEG/JPEG2000`)
    *   If you choose `JPEG2000` compression, specify the path `path/to/openjpeg/bin/image_to_j2k` [(download *OpenJPEG* here)](http://www.openjpeg.org/index.php?menu=download). Adjust *Compression Quality* and *Gauss filter* according to the chosen compression type.

(Additional information for every option can be viewed by hovering over it.)

Start the job and check the Output Console for the job's progress. After it has finished, start **Knossos** and load the generated `.conf` file.

* * *

**Knossos** Quickstart Guide
============================

**Knossos'** main window is split into four parts ("viewports"):

*   The first three viewports represent each `x/y/z` plain respectively.
*   The fourth viewport displays a 3D view on the data.

![**Knossos'** main window](main_window.png)

An image dataset can be loaded into **Knossos** by selecting its `.conf` file in `File - Load Dataset...`

![Loading image data into **Knossos**](load_dataset.png)

Moving around
-------------

*   Click and drag in a viewport to move along that plane.
*   Press `d/f` or scroll to move orthogonally.
*   Zoom in our out with `Ctrl+Scroll` (for the 3D viewport: only `Scroll`).

Skeletonization
---------------

**Knossos'** main feature, skeletonization, is used to accurately reconstruct an object by tracing nodes and segments:

*   Nodes are placed with a right-click. Consecutive nodes are automatically connected with a segment.
*   Open the *Tree View* (`Windows - Annotation Window`) for an overview of your current skeleton.
