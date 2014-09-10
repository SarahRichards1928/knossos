---
layout: page
title: Get started
permalink: /start/
---
<div>
Stack Generation
================

**Knossos** expects image data to be in a special cube format.
[This **Matlab** code]({{ "downloads/KNOSSOSmaker_gaussfilter.zip" }} | prepend: site.baseurl)
can be used to generate the appropriate data format from TIFF files.
</div>

<div>
**Knossos** datasets
====================

Example data stacks in the **Knossos** format can be found here:
<span class="button">[small (54 MB)]({{ "downloads/e1088_mag1_small.zip" | prepend: site.baseurl }})</span>
<span class="button">[large (400 MB)]({{ "downloads/e1088_mag1_large.zip" | prepend: site.baseurl}})</span>


*   After starting **Knossos**, navigate to "File - Load Dataset" and select the `e1088_mag1` folder.
*   Copy the following coordinates: `829 1090 832` (Ctrl-c) and paste them into **Knossos**
    (the "paste" button is located in the menu bar).
*   These steps take you directly to the center of the data stacks.
</div>


Retina Editions (Online Streaming)
==================================

We provide two special editions based on `KNOSSOS 3.4.2` that stream the retina datasets
`e2006` and `ek0563` over the internet. These versions do not require an
installation and do not require Python. Both datasets use image compression for
online streaming.

To run these special versions, download and extract one of these archives:
<span class="button">[e2006]({{ "downloads/KNOSSOS_Online_Version_e2006.zip" | prepend: site.baseurl }})</span>
<span class="button">[ek0563]({{ "downloads/KNOSSOS_Online_Version_ek0563.zip" | prepend: site.baseurl}})</span>

* * *

Then, simply run the `knossos.exe` file contained in the folders. Windows may
ask you for confirmation to run software from a source which could not be verified.

For convenience, you can create a Desktop shortcut to the **Knossos** executable
by right-clicking on it, choosing "Create Shortcut", and moving the shortcut to your Desktop.
