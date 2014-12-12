---
layout: page
title: Documentation
permalink: /documentation/
---
**Knossos** Manual
======================

Contents
--------

<div class="row">

<div class="four columns">

1.  Preparing your Dataset
2.  Knossos Installation
3.  Knossos Starter
    1.  Add Dataset
    2.  Profile
    3.  Remove Dataset
    4.  Select dataset
    5.  Supercube edge
    6.  Synchronize on start
4.  Knossos
    1. Branch points
        1.  Add branch point
        2.  Jump to branch point
        3.  Remove branch point
    2.  Coordinates
        1.  Copy coordinates
    3.  Edit Skeleton (menu)
        1.  Work Mode
            1.  Add node (a)
            2.  Link with active node (w)
            3.  Drop nodes
        2. Skeleton statistics ...
        3.  Clear Skeleton
        4.  File (menu)
            1. Open... -> Open Skeleton File
                1.  Merge with Open Skeleton
            2.  Open recent Skeleton File (open recent file)
            3.  Save (Ctrl+s) -> Save Skeleton File [save file]
                1.  Standard save folder (for skeleton files)
            4.  Save as ...
        5.  Help (menu)
            1.  About
        6.  Shortcuts

</div>

<div class="four columns">

4.  3.  7.  tesi

</div>

</div>

<div class="row">

<div class="four columns">

|   |    |
|:--:|:---|
| 3.7 | Keyboard layout [Keys, functional keys]
| 3.8 | Moving [scrolling, panning]
| 3.9 | Nodes [skeleton nodes, skeleton points]
| 3.9.1 | Activate nodes [active node, reactivate nodes]
| 3.9.2 | Add nodes [place nodes]
| 3.9.3 | Connect nodes [make segment]
| 3.9.4 | Delete node [remove node]
| 3.9.5 | Delete segment [remove segment]
| 3.9.6 | Move node [reposition node, drag node]
| 3.9.7 | Node ID
| 3.10 | Preferences (menu)
| 3.10.1 | Load Custom Preferences
| 3.10.2 | Save Custom Preferences As
| 3.10.3 | Dataset Navigation
| 3.10.4 | Synchronization
| 3.10.4.1 | Synchronization Settings
| 3.10.5 | Data Saving Options
| 3.10.6 | Viewport Setting
| 3.11 | Synchronization [synchronize Knossos]
| 3.12 | Tools window
| 3.12.1 | Quick
| 3.12.1.1 | Active Tree ID
| 3.12.1.2 | Active Node ID
| 3.12.1.3 | Comments
| 3.12.1.4 | Branch Points
| 3.12.2 | Trees
| 3.12.2.1 |Active Tree ID
| 3.12.2.2 |Delete Active Tree
| 3.12.2.3 |New Tree (C)
| 3.12.2.4 |Merge Trees
| 3.12.2.5 |Split Trees By Connected Components
| 3.12.3 | Nodes
| 3.12.3.1 | Active Node ID
| 3.12.3.2 | Jump to Node (s)
| 3.12.3.3 | Delete node (Del)
| 3.12.3.4 | Link node with (Shift+Click)
| 3.12.3.5 | Comment
| 3.12.3.6 | Node Radius
| 3.12.3.7 | Locking

</div>

<div class="four columns">

|   |    |
|:--:|:---|
| 3.13 | Trees [Skeleton]
| 3.13.1 | Add tree [new tree, new skeleton]
| 3.13.2 | Delete tree [remove tree, delete skeleton]
| 3.13.3 | Merge trees [merge skeletons]
| 3.13.4 | Split trees [separate trees, split skeleton]
| 3.13.5 | Tree ID
| 3.14 | View (menu)
| 3.14.1 | Work Mode
| 3.14.1.1 | Drag Dataset
| 3.14.1.2 | Recenter on Click
| 3.14.2 | Dataset Statistics
| 3.14.3 | Zoom...
| 3.14.3.1 | Viewport Zooming
| 3.15 | Viewport
| 3.15.1 | Viewport xy (red viewport)
| 3.15.2 | Viewport yz (blue viewport)
| 3.15.3 | Viewport xz (green viewport)
| 3.15.4 | 3D Viewport
| 3.16 | Viewport Settings
| 3.16.1 | General
| 3.16.1.1 | Skeleton Visualization
| 3.16.1.2 | Skeleton Rendering Model
| 3.16.2 | Slice Plane Viewports
| 3.16.2.1 | Skeleton Overlay
| 3.16.2.2 | Voxel Filtering
| 3.16.2.3 | Dataset color lookup table
| 3.16.2.4 | Dataset Dynamic Range (Contrast)
| 3.16.2.5 | Object ID Overlay
| 3.16.3 | Skeleton Viewport
| 3.16.3.1 | Dataset Visualization
| 3.16.3.2 | Skeleton Display Modes
| 3.16.3.3 | 3D View
| 3.17 | Windows (menu)
| 3.17.1 | Tools window
| 3.17.2 | Log window
| 3.18 | Zooming
| 3.18.1 | Zooming Slice Viewports
| 3.18.2 | Zooming 3D Viewport

</div>





</div>

Preparing your Dataset

MATLAB™ code that automates the following steps is available on the download page.

Datasets have to be in a cube format, that is, split into raw 8-bit binary files, 128 * 128 * 128 bytes = 2 MiB each. The file names have to be named like this, for example:
SomeName_x0000_y0032_z0020.raw
where you need to replace the x, y and z values with the appropriate position of the cube. They are then placed in a nested directory hierarchy. For the example above, the file would have to go into a directory named
YourData\x0000\y0032\z0020\
Then, you can use the configknossos.pyw python script that is in the tools\ folder in your knossos install directory to generate the knossos.conf configuration file. A file called knossos.conf has to be generated and placed in the YourData\ directory, and should looks like this:
experiment name "YourData";
boundary x 10000;
boundary y 10000;
boundary z 10000;
scale x 20.0;
scale y 20.0;
scale z 20.0;
magnification 1;
Where the boundaries are the edge length of your volume in voxels and the scales are the size of your voxels in nanometers. Set magnification to 1 unless you have multiple downscaled versions of the same dataset that you want to work with simultaneously.
Knossos Starter

When starting Knossos, you are asked in the Knossos Starter window to select a dataset, give a profile name and choose a value for Supercube edge, before you run Knossos.

Add Dataset

You can add a new dataset by clicking on the "+"-Button.
A window opens where you are asked to choose the dataset folder. Click on "Ok" after you selected the folder.
Profile

You can put in your name below "Profile" to load your Knossos profile (or to create it if the name has not been used before).
Knossos saves all your settings in Knossos under this name (assuming you close Knossos appropriately).
You can reload them with this name the next time you start Knossos.
Remove Dataset

If you want to remove a dataset from the Knossos starter menue, simply select it and click on the "-"-Button to remove it.
Select dataset

In order to run Knossos you have to select a dataset which will then be loaded.
Select a dataset in the upper field (if you started Knossos for the first time or if your directories have changed, you first have to add a dataset) and then press the "Run"-Button to load Knossos with the selected dataset.
Supercube edge

Here you can optionally choose how many cubes there will be loaded per viewport.
The higher the number, the more cubes will be loaded. However this will then require more memory.
Change the Supercube Edge to 5 (requires 250 MB RAM) at each start. The setting 7 (686 MB RAM-Speicher) or 3 (54 MB RAM) is also possible, but 5 is optimal for tracing.
Synchronize on start

Activate this check mark to directly synchronize Knossos at the beginning.
You also need to activate this if you want to synchronize two or more datasets on your own computer.
In this way, two Knossos windows will open, each loaded with one dataset. Upon tracing, the skeleton (and everything else) will also be traced/done in the other Knossos window.
To do this, activate the checkmark and choose afterwards two (or more) datasets by selecting them with your left mouse button while simultaneously holding down CTRL.
To learn more about synchronization, see here.
Knossos

Branch points [branchpoints]

Branch points help you to relocate important nodes in your skeleton.
Mainly this feature is used to find a location where the cell divides into two branches. Because you can only follow one branch, you have to find the other later on to trace it.
Branch points are stacked. This means that new branch points will be stacked onto the old ones in the branch point file and when you jump to them you first come to the newer branch points and afterwards to the older ones.
Add branch point

You can make a node a branch point by simply pressing B on your keyboard when the node is activated. The color of the node turns blue.
Another possibility is to hold down CTRL while clicking with your right mouse button onto a new position. A node will be added which is simultaneously marked as branch point. This node does not automatically become active (in comparison to normal node placing)
Jump to branch point

Press J on your keyboard to jump to the last made branch point. The marking as a branch point is automatically removed. If you want to keep it, press again B on your keyboard.
Another possibility is to click on Pop and (J)ump in the tools window. See Branch Point(tools window) for further information.
Remove branch point

A branch point is removed at the time you jump to it.
Coordinates [enter coordinates, enter seedpoint, paste seedpoint, paste coordinates]


In the upper right section of Knossos, you can enter the x-,y-,z-coordinates of a location you want to move to, e.g. to find the seedpoint of your tracing.
Simply type in the coordinates each one in the corresponding coordinate field, or simply copy your coordinates from the excel file (separated by blanks, e.g. 100 100 100) and click on the Paste button left from the coordinate fields or press V on your keyboard while holding down CTRL.
Copy coordinates

If you want to extract the coordinates of your current location, click on the Copy-Button left from the coordinate fields. The coordinates will be copied to your clipboard, separated with blanks.
Edit Skeleton (menu)

Work Mode

Here you can choose between different types of placing a node.
Add node (a)

This work mode does not connect the first node you place with any previously active node. Further placed nodes will be connected as usual. Pressing "a" on your keyboard will do the same.
Link with active node (w)

This is the normal work mode, where each new placed node will be connected to the previously active node (and becomes the next active node).
Drop nodes

This work mode simply places single nodes without connecting them. This is a special work mode which you do only need if you want to drop "node clouds" e.g. for glia cells.
Skeleton Statistics...

This feature is not yet implemented.
Clear Skeleton

This menu item will clear the whole cube from any skeleton you traced/loaded. You will be asked by a dialog if you really want to do this. =)
File (menu)

Open... -> Open Skeleton File [open file]

Under "File" -> "Open..." a window opens where you can choose a skeleton file from your computer to be loaded into Knossos.
Browse through your folders on the left side and choose a file on the right side. Then click on "OK"
Merge with Open Skeleton

If you do not want the current skeleton to be replaced by the one you are opening, choose Merge with Open Skeleton below the "OK"-button.
Note: The two skeletons will have the same tree IDs! If you want to give them again different IDs, see here.
Open recent Skeleton File (open recent file)

This menu item will show you a list of recently loaded skeleton files (with the directory where they lie).
Note: Here you don't have the option to merge this skeleton with the currently loaded one. If you like to do that, see here
Save (CTRL+s) -> Save Skeleton File [save file]

Here you can save your current skeletons on your computer. Pressing s on your keyboard while holding down CTRL will do the same.
Standard save folder (for skeleton files)

If you haven't saved a file yet using Save as... the file will be stored in the skeletonFiles folder of your Knossos installation directory using as file name a combination of the date and time when you started Knossos to do tracing.
If you have already stored a file in a specific folder and used a file name without ".000.nml" at the end, Knossos will save a new file in this folder using the previous file name and adding ".000.nml". If the file name already contains ".000.nml", Knossos will name the subsequent saved files ".001.nml", ".002.nml" and so on, given that you did not turn off the option Auto Increment Filename (for further information see Data Saving Options
Save as...

To specify the file name and the folder for your skeleton file, choose this menu item.
A window will open where you can browse to the desired folder (has already to be existent!) and save the file under the name given in the field File:.
Quit

This menu item will quit Knossos.
Warning: Since there is no warning dialog, be sure you have saved your proceedings!
Help (menu)

About

This menu item opens a window containing some developer information about Knossos.
Hot keys [Hotkey, Shortcuts, Short cuts]

There are some key combinations which might help you to be faster on Knossos:
SHIFT + Arrow keys: Moves dataset 10 planes into the corresponding direction instead of 1. For faster scrolling.
SHIFT + F / D: Moves dataset 10 planes forwards / backwards instead of 1. For faster perpendicular scrolling.
CTRL + S: Saves your skeleton in the same way as the autosaving feature does (auto increment number). See Save file.
CTRL + V: If you have copied the coordinates into clipboard you can use this to quickly paste them into Knossos and jump to that location. See Paste coordinates.
CTRL + mouse wheel: Zoom in and out of the three viewports or the 3D viewport (depending on where your mouse cursor currently is).
SHIFT + mouse wheel: Changes the node radius of the active node. See Node Radius for further information.
SHIFT + left mouse button click on node: Activate node
CTRL + right mouse button click in slice viewport: Add a node which is simultaneously marked as a branchpoint (but does not become an active node).
SHIFT + middle mouse button click on a node: Delete segment between the active and the clicked node. See Delete segment.
CTRL + middle mouse button click on a node: Add segment between the active and the clicked node. See Connect nodes.
The keyboard layout including the other functional keys can be found here.
Keyboard layout [Keys, functional keys]


Moving [scrolling, panning]

There are many ways in Knossos to move through the dataset. They are listed here in priority order:
You can use your left mouse button to either drag the dataset by clicking and pulling in one direction, or to recenter the view on the position you clicked (depending on the WorkMode you chose)
Use the arrow keys on your keyboard to move into the corresponding direction (depending on which slice viewport your mouse cursor is currently positioned).
Using the arrow keys while holding down SHIFT will move 10 planes instead of 1.
Use your mouse wheels to move perpendicularly to the viewport where your mouse cursor is currently positioned.
Using D and F on your keyboard will also move the dataset perpendicularly.
Using F/D while holding down SHIFT will perpendicularly move 10 planes instead of 1.
Placing a node using your right mouse button will recenter the view on the node. (Adding one using CTRL + right mouse button won't do so).
You can jump to the currently active node using S on your keyboard. See here for further information.
By entering a coordinate in the upper right coordinate fields you can jump to a desired location. See here for further information.
You can jump to a node previously marked as a branch point using J on your keyboard or using your Tool window.
You can search for nodes with comments using N and P on your keyboard or your Tool window.
There you can also search for a specific comment by typing it into the field Search for.
Nodes [skeleton nodes, skeleton points]

Activate nodes [active node, reactivate nodes]

The currently active node is highlighted by its node ID which is shown right near to the node.
New placed nodes will be connected to the currently active node, given that the option Link with active node is enabled (default).
Furthermore, several functions such as Delete node, Connect nodes/Make segment, Delete segment and Branchpoint are related to the currently active node.
You activate a node by clicking on it with your left mouse button while simultaneously having the SHIFT key on your keyboard pressed.
Another possibility is to choose the desired node ID in the tools window (see Tool Window).
Add nodes [place nodes]

You place a node by clicking with the right mouse button into one of the slice viewports.
The first node of a skeleton is always marked blue and gets the comment "First Node" automatically.
Furthermore, the program centers the viewport on the node you have just placed.
Further nodes you place will be automatically connected with the previously placed (or activated) node, given that the option Link with active node is enabled (default).
Connect nodes [make segment]

You can connect two nodes with each other by activating one of the two nodes and clicking on the other one with the middle mouse button while simultaneously holding down the CTRL key on your keyboard.
This is helpful, e.g. if you separated two skeleton parts by accident and you want to connect them again.
Another way is to activate one node, to enter the ID of the other node in the field right beside the button "Link Node with..." (in the Tools window, see Link node with) and afterwards clicking on the button "Link node with..." (see blue circles in next image)

Delete node [remove node]

You can delete a node by activating it and pressing DEL on your keyboard.
Another way is to click on Delete node (Del) in the tools window under "Nodes" (see Delete Node)
Delete segment [remove segment]

You can delete the connection (segment) between two nodes by activating one of them and clicking on the other with your middle mouse button while holding down the SHIFT key on your keyboard.
This is helpful if you want to separate two parts of your skeleton (to delete one of them or to make two trees according to Split Trees)
Move node [reposition node, drag node]

If you want to move a node (e.g. to bring it to the center of the cell), simply click on the node with the middle mouse button and drag it to another position. The node does not have to be your active node.
Node ID

The Node ID of each node is unique among all skeletons traced/loaded in the dataset. Each new added node gets a new ID, starting from 1. This enables you to relocate each node, e.g. by using the tools window (see Jump to node).
Preferences (menu)

Load Custom Preferences

Here, you can load your previously saved custom GUI preferences. A window will open and you are asked for the location of the xml-file.
Custom preferences contain your last used file and folder, the position of your windows, the size of Knossos, the look of your viewports etc.
Save Custom Preferences As

Here, you can save your current custom GUI preferences. A window will open and you are asked where to save the xml-file containing your preferences.
The xml-file contains your last used file and folder, the position of your windows, the size of Knossos, the look of your viewports etc.
Dataset Navigation

This will open an additional window, where you can change settings about how fast to navigate through the stack.
Movement Speed changes the speed of moving through the stack when using your arrow keys on the keyboard. The higher the value, the faster you are moving.
Jump Frames represents the amount of planes which will be moved when pressing once on your arrow keys. For example, a value of 100 will jump 100 planes into the direction according to your arrow key.
Remember, these two settings will only change the way of moving with your arrow keys.
Recentering Time [ms] sets the time it takes for the viewport to move from the current center position to the position you choosed with your left mouse button. Remember, this will only work if you choosed "Recenter on Click" as your preferred work mode (see [1]).
Synchronization

This will open a new window called Synchronization Settings:
To learn more about synchronization, see here.
Synchronization Settings

At the top of the window you see the connection status of Knossos (e.g. "No connection to server.").
In the field Remote Host you can enter the ip adress of the host you want to connect to.
In the field Remote Port you have to specify the port through which the connection should be initiated. Make sure your firewall does not block this port.
The buttons Connect and Disconnect will do what they say =) Use them to establish the synchronization connection to the other computer.
The other computer must also have Knossos openened and a connection established to the first computer.
Data Saving Options

Here you can change the way of automatically saving your proceedings.
Enabling the option Auto-Saving will save your skeletons on a time interval according to the field Saving Interval [min].
By default your data will be saved automatically every 5 minutes. You can change this by typing in another positive value.
The option Auto Increment Filename is enabled by default and will automatically increase the number "###.nml" in the filename at every saving step. Deactivating this will overwrite the saved files at every saving step.
Viewport Setting

See chapter Viewport Settings.
Synchronization [synchronize Knossos]

The Synchronization feature is mainly used, if you have same datasets but with different resolutions. Synchronization allows you to watch them simultaneously in multiple Knossos instances.
There are two types of synchronization: synchronization on the same computer or synchronization on different computers using a network connection.
If you want to use this on the same computer, use the Synchronize on start button in the Knossos starter menu.
You choose two or more datasets in the starter menu which will then all be loaded each in one Knossos instance. The instances will move and react simultaneously if you move or do tracing in one of them.
Opening many Knossos instances will of course need high computing power and RAM. Thus the performance might go down.
You can also synchronize (two!) computers over network. They will also move and react simultaneously.
To do this start Knossos on both computers each with a different dataset. The Knossos starter menu has to stay opened in the background!
In the preferences menu you then have to open the Synchronization Settings on both computers and enter in each case the IP adress and the open port of the other computer (port should be the same in both cases).
Afterwards click on connect.
If it does not work, make sure that the port is not blocked by the firewall of the computers.
Tools window

Under "Windows" --> "Tools" you can open an important, additional window with many features.
Quick

In the Quick section, the most important functions of the other sections are summarized.
Tree count counts the number of trees you have currently loaded/traced in the dataset, whereas Node count counts the overall number of nodes you have placed in the current dataset.
Active Tree ID

This shows you the currently active tree ID. This is the three which is also highlighted in red in all viewports. You can switch to another tree by typing in or toggling to another ID. However, if you want to go on tracing there, you still have to activate a node from this tree.
Active Node ID

This shows you the currently active node ID. You can switch to another node by typing in or toggling to another ID.
Below that you see the coordinates of the currently active node.
Comments

In the "Active Node ID" section you can also see the comment of the currently active node.
If you want to make a comment, just type it into the field Comments:.
If you want to search for a specific comment type it into the field Search for: and click on Find (N)ext or Find (P)revious. Pressing N or P on your keyboard will do the same.
Note: The first node of a tree you begin to trace has always automatically the comment "First Node".
Branch Points

Under #Nodes on Stack you can see how many branchpoints there have been placed yet.
Clicking on Push (B)ranch Node will transform the currently active node into a branchpoint. Pressing B on your keyboard will do the same.
Clicking on Pop and (J)ump will lead you to the last placed branchpoint which simultaneously becomes again a normal node. Pressing J on your keyboard will do the same.
Note: The first node of a tree you begin to trace is always automatically transformed into a branchpoint.
Trees

Tree Count shows you the overall number of trees loaded or/and traced by you in the current dataset.
Active Tree ID

This shows you the currently active tree ID. This is the three which is also highlighted in red in all viewports. You can switch to another tree by typing in or toggling to another ID. However, if you want to go on tracing there, you still have to activate a node from this tree.
Delete Active Tree

Clicking on Delete Active Tree will - suprisingly - delete the whole currently active tree. Since there will be no warning dialog and there is also no "Undo" feature, please be sure that you are doing the right.
New Tree (C)

Clicking on New Tree (C) will make a new tree (with new tree ID) when placing the next node. Pressing C on your keyboard will do the same.
Merge Trees

With the Merge Trees function you can give two trees the same ID. The ID you are typing into the field ID 1 is the ID which will be remained. The ID in field ID 2 will get the ID of the first field. After typing in both IDs click on Merge Trees
Split Trees By Connected Components

Clicking on Split Trees By Connected Components checks if the currently active tree consists of several separated trees (i.e. one group of nodes is not connected with another group of nodes). If this is the case, then each of these trees will get an individual (new) ID. For example, this feature can be used if you traced a very long branch and afterwards you recognize that this branch does not belong to your cell. It is easier to delete the first segment at the branchpoint, split the two trees with this function and delete the branch tree, than deleting every single node of the branch.
Nodes

Node Count shows you the overall number of nodes you placed (independent of trees) in the current dataset.
Active Node ID

This shows you the currently active node ID. You can switch to another node by typing in or toggling to another ID.
Jump to Node (s)

This button will center the viewports on the currently active node. In this way you can enter a node ID in the field above and jump to it. Pressing S on your keyboard will do the same.
Delete node (Del)

This button will delete the currently active node. Pressing Del on your keyboard will do the same.
Link node with (Shift+Click)

This button will make a segment between the currently active node and the node ID you entered into the field on the right side of the button. Holding down CTRL while clicking with the middle mouse button on another node, will do the same.
Comment

The comment function helps you to find specific nodes again without the need of writing down the ID. You can make a comment on a node and search for it again later on.
If you want to make a comment, just type it into the field Comments:.
If you want to search for a specific comment type it into the field Search for: and click on Find (N)ext or Find (P)revious. Pressing N or P on your keyboard will do the same.
Note: The first node of a tree you begin to trace has always automatically the comment "First Node".
Node Radius

Here you can change the radius of the node. This is normally not necessary, except for Volume Tracing jobs.
You can change the radius of the current node by either typing it into the field Active Node Radius(SHIFT+wheel) or by holding down the SHIFT key and turning the mouse wheel.
You can change the default node radius (when new nodes are placed) by typing in another value in the field Default Node Radius or by clicking on Use Last Radius as Default to use the last entered radius.
Locking

The Locking feature helps, if the task is to trace a cell only in a defined volume. Locking to a Node will prevent you from placing nodes outside the defined radius.
You can set the desired locking radius in the field Locking Radius. The unit is in voxels ("planes").
Clicking on Enable comment locking will activate the radius locking as soon as a node having the comment according to the text in the field below 'Lock to Nodes With Comment is searched using the comment search feature.
Another possibility is to Lock to Active Node. By clicking on this buton you are only able to place nodes in the defined radius around the currently active node.
Clicking on Disable Locking will disable the Locking feature.
Trees [Skeleton]

Add tree [new tree, new skeleton]

This feature helps you, if you have to trace more than one skeleton at the same time (e.g. tracing task "dense skeletonization").
You can start with a new skeleton/tree by pressing C on your keyboard. The next node you place will start the new tree. This tree has also a new tree ID.
There is also the possibilty to click on New Tree (C) in the tools window under "Trees" (see New Tree).
Delete tree [remove tree, delete skeleton]

You can delete a whole tree by clicking on Delete Active Tree in the tools window under "Trees" (see Delete Active Tree).
Warning 1:Since there will be no warning dialog and there is also no "Undo" feature, please be sure that you are doing the right.
Warning 2: If two skeletons/trees have the same ID (if you did not separate them by Split Trees or if you did not make a new tree for the second skeleton) then both will be deleted!
Merge trees [merge skeletons]

With the Merge Trees function you can give two trees the same ID.
This can be done in the tools windows under "Trees". For further information Merge Trees.
Split trees [separate trees, split skeleton]

There might be a case where you want to split a tree into two trees, e.g. if you traced a long branch and you recognize afterwards that it did not belong to your skeleton.
To do this, you need to separate both trees by deleting the node next to the branch point or by deleting the first segment of the branch (see Delete segment).
Afterwards click on Split Trees By Connected Components in the tools window under "Trees" which gives you different IDs (and color) for the two skeletons (see Split Trees.
Then you can delete the whole branch at once (see Delete skeleton).
Tree ID

The tree ID of a skeleton is normally unique among all skeletons traced/loaded in the dataset. Each new added tree gets a new ID and color.
To see the ID of the current active tree, see Active Tree ID
View (menu)

Work Mode

Here you can change the kind of moving through the stacks with your left mouse button. Choose the one which is more pleasant to you.
Drag Dataset

If you choose this option, you can move the stack by clicking (and holding) with your left mouse button on a slice viewport and dragging it into the desired direction.
Recenter on Click

If you choose this option, you can move the stack with your mouse by clicking on a location in the slice viewports with your left mouse button. The view recenters on this point.
Dataset Statistics

This feature is not yet implemented.
Zoom...

This menu item opens a new window (Viewport Zooming) where you can change the zoom for each viewport.
Using your mouse wheel on a viewport while holding down the CTRL key on your keyboard or pressing the I or O key on your keyboard will do the same, but simultaneaously for each slice viewport.
Viewport Zooming

Moving the bars right from Viewport XY, Viewport XZ or Viewport YZ to the left will zoom into the images. You can also enter a value between 0.02 and 1.00 in the field right from the bar.
Moving the bar right from Skeleton View to the right will zoom into the 3D skeleton viewport. You can also enter a value between 0.00 and 0.49 in the field right from the bar. You can also zoom further into the picture with CTRL + mouse wheel.
Clicking on All Defaults will set the zoom of each viewport back to default (1.00 or 0.00 respectively).
Viewport

When Knossos opens, the data can be observed by four different viewports.
The viewports show the black-white-grey volume image data. The dark area is the Extracellulary Matrix where an enzyme (HRP) is used to deposit heavy metal ions which cause high contrasts in electron microscopy based recordings. Hence, the bright area is intracellulary (intracellular organelles are not labeled here) and represents the neurons (or glia cells).
Viewport xy (red viewport)

The upper left viewport (with a red border) shows the x-y-plane of the stack.
By scrolling or using the D/F key you move into z-direction.
Viewport yz (blue viewport)

The upper right viewport (with a blue border) shows the y-z-plane of the stack.
By scrolling or using the D/F key you move into x-direction.
Viewport xz (green viewport)

The lower left viewport (with a green border) shows the x-z-plane of the stack.
By scrolling or using the D/F key you move into y-direction.
3D Viewport


The lower right viewport (with a black border) represents the 3D viewport.
The black borders represent the border of the dataset, on the edges you can see the voxel coordinates.
With the 3D viewport you can observe the development of your traced skeleton(s).
The three other viewports can be seen as 3 planes around the current viewports' center.
By scrolling you move in and out of the dataset, with the left mouse button you can pan through the stack and with the right mouse button you turn the stack around the currently active node.
Viewport Settings

Under "Preferences" --> "Viewport Settings" you can try the following additional settings.
General


Skeleton Visualization

The feature Light effects adds a virtual light source when rendering the skeleton. Hence, the skeleton looks more "3D". Choose the setting you like more.
The feature Highlight Active Tree is helpful if you have loaded multiple skeletons at the same time, because the currently active one is highlighted in turquoise.
The feature Show All Node IDs shows every node ID in the stack (and also in the 3D-Viewport). Hence, the active node is worse recognizable but maybe you may get along better.
The feature Override Node Radius changes all radii of the skeleton to the value in the field beside. This is useful at the most, if you want your volume tracing skeleton to be depicted as a point/line-skeleton.
The feature Edge <-> Node radius ratio changes the ratio of the edge size to the node size. In that way, you can visualize the nodes bigger than the segments or vice versa.
Skeleton Rendering Model

You can use this to switch between the 3D Skeleton (default setting) and simple Lines and Points (fast). The latter is faster, but the first one is more helpful for orientation.
Slice Plane Viewports

Skeleton Overlay

The option Enable Overlay (1) turns the rendering in the 3 slice plane viewports on (default) and off. Pressing 1 on your keyboard will do the same.
If you enable Highlight Intersections then the points at the skeleton where it intersects one of the other slice planes will be highlighted in black.
The value in Depth Cutoff sets how many planes before and after a skeleton you can already see it. The higher the value, the earlier the skeleton is shown in the viewports when approaching it.
Voxel Filtering

Dataset Linear Filtering (enabled by default) turns on the the filtering of the slices. The image looks smoother when this option is enabled.
Dataset color lookup table

This feature enables you to change the grey values of the data set into color values according to a "Color Lookup Table" (LUT). The format of this table is the ImageJ-format, supporting only 768 byte tables (3 bytes RGB colors for each of the 256 grey values)
To use this feature, first load a adequat lookup table by clicking on Load Color Lookup Table. A window will open where you are asked for the directory and file of the table.
Then click on Enable LUT and the dataset should change its color according to the table
Dataset Dynamic Range (Contrast)

Here the intensity values (i.e. the contrast) of the dataset can be adjusted. Because it is 8-bit greyscale the range goes from 0 to 255.
If you increase Bias (default 0), then the image gets brighter. If you decrease Range Delta, the image gets darker.
A good setting is 100 for both Bias and Range Delta.
Object ID Overlay

This feature is used to stain parts of the EM dataset with other colors by using a second "object id"-dataset.
However this feature is yet not fully implemented.
Enable Color Overlay will enable this feature.
Skeleton Viewport


Dataset Visualization

The buttons Show XY Plane, Show XZ Plane and Show YZ Plane switch the rendering of the grey planes in the 3D viewport around the current center of view on or off.
Skeleton Display Modes

Under "Skeleton Viewport" in the "Viewport Settings" you have the option to change the rendering of the skeleotn in the 3D viewport
Whole Skeleton displays all loaded/traced skeletons at full length in the 3D viewport.
Only Current Cube displays all loaded/traced skeletons, but only the part which lies in the current super cube.
Only Active Tree displays the complete tree of the skeleton which is currently active.
Hide Skeleton (fast) does not render any skeleton in the 3D viewport. This option is recommended, if your skeletons become very large and your computer gets slower and slower. Switching the trees off significantly improves the performance.
3D View

If Rotate Around Active node is activated (default) then the rotation in the 3D viewport (when holding down the right mouse button and moving) will be around the currently active node. Otherwise the view will rotate around the center of the dataset.
Windows (menu)

Under "Windows" you can open the Tools window or the Log window.
Tools window

See here for information about the Tools window
Log window

In this window, everything you are doing is logged (except moving around and other minor events).
If an error occurs it will also be displayed there. This can be very helpful if you don't know why something is not working or goes wrong at the moment.
Zooming

Zooming Slice Viewports

You can zoom into a slice viewport by either pressing I on your keyboard or holding down CTRL and moving your mouse wheel forward.
You can zoom out of a slice viewport by either pressing O on your keyboard or holding down CTRL and moving your mouse wheel backward.
The mouse cursor has to be placed over the viewport you want to zoom.
Another possibility to zoom is to use the Viewport Zooming window.
Zooming 3D Viewport

You can zoom in or out of the 3D viewport by holding down CTRL and moving your mouse wheel forward or backward respectively.
Another possibility to zoom is to use the Viewport Zooming window.