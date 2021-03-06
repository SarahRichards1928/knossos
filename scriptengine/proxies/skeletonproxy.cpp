#include "knossos-global.h"
#include "viewer.h"
#include "eventmodel.h"
#include "skeletonproxy.h"
#include "functions.h"
#include "skeletonizer.h"
#include "widgets/mainwindow.h"
#include <QApplication>
#include <QFile>

SkeletonProxySignalDelegate *signalDelegate = new SkeletonProxySignalDelegate();

SkeletonProxy::SkeletonProxy(QObject *parent) :
    QObject(parent)
{

}

treeListElement *SkeletonProxy::tree_with_previous_id(int tree_id) {
    treeListElement *tree = Skeletonizer::findTreeByTreeID(tree_id);
    return Skeletonizer::getTreeWithPrevID(tree);
}

treeListElement *SkeletonProxy::tree_with_next_id(int tree_id) {
    treeListElement *tree = Skeletonizer::findTreeByTreeID(tree_id);
    return Skeletonizer::getTreeWithNextID(tree);
}

bool SkeletonProxy::move_to_next_tree() {
    bool isSuccess = false;
    Skeletonizer::singleton().moveToNextTree(&isSuccess);
    return isSuccess;
}

bool SkeletonProxy::move_to_previous_tree() {
    bool isSuccess = false;
    Skeletonizer::singleton().moveToPrevTree(&isSuccess);
    return isSuccess;
}

treeListElement *SkeletonProxy::find_tree_by_id(int tree_id) {
    return Skeletonizer::findTreeByTreeID(tree_id);
}

treeListElement *SkeletonProxy::first_tree() {
    return state->skeletonState->firstTree;
}

bool SkeletonProxy::delete_tree(int tree_id) {
   if (!Skeletonizer::singleton().delTree(tree_id)) {
       emit echo(QString("could not delete the tree with id %1").arg(tree_id));
       return false;
   }
   return true;
}

bool SkeletonProxy::merge_trees(int tree_id, int other_tree_id) {
    if (!Skeletonizer::singleton().mergeTrees(tree_id, other_tree_id)) {
       emit echo (QString("Skeletonizer::mergeTrees failed!"));
       return false;
    }
    return true;
}

nodeListElement *SkeletonProxy::find_node_by_id(int node_id) {
    return Skeletonizer::findNodeByNodeID(node_id);
}

bool SkeletonProxy::move_node_to_tree(int node_id, int tree_id) {
    nodeListElement *node = Skeletonizer::findNodeByNodeID(node_id);
    Skeletonizer::singleton().selectNodes({node});
    if (!Skeletonizer::singleton().moveSelectedNodesToTree(tree_id)) {
        emit echo (QString("Skeletonizer::moveSelectedNodesToTree failed!"));
        return false;
    }
    return true;
}

nodeListElement *SkeletonProxy::find_nearby_node_from_tree(int tree_id, int x, int y, int z) {
    treeListElement *tree = Skeletonizer::findTreeByTreeID(tree_id);
    Coordinate coord(x, y, z);
    return Skeletonizer::findNearbyNode(tree, coord);
}

nodeListElement *SkeletonProxy::find_node_in_radius(int x, int y, int z) {
    Coordinate coord(x, y, z);
    return Skeletonizer::findNodeInRadius(coord);
}

nodeListElement *SkeletonProxy::node_with_prev_id(int node_id, bool same_tree) {
    nodeListElement *node = Skeletonizer::findNodeByNodeID(node_id);
    return Skeletonizer::getNodeWithPrevID(node, same_tree);
}

nodeListElement *SkeletonProxy::node_with_next_id(int node_id, bool same_tree) {
    nodeListElement *node = Skeletonizer::findNodeByNodeID(node_id);
    return Skeletonizer::getNodeWithNextID(node, same_tree);
}

bool SkeletonProxy::edit_node(int node_id, float radius, int x, int y, int z, int in_mag) {
    if (!Skeletonizer::singleton().editNode(node_id, 0, radius, x, y, z, in_mag)) {
        emit echo (QString("Skeletonizer::editNode failed!"));
        return false;
    }
    return true;
}

int SkeletonProxy::skeleton_time() {
    return state->skeletonState->skeletonTime;
}

QString SkeletonProxy::skeleton_file() {
    return state->viewer->window->annotationFilename;
}

bool SkeletonProxy::annotation_load(const QString &filename, bool isMerge) {
    bool isSuccess = false;
    bool isMergePrevValue = state->skeletonState->mergeOnLoadFlag;
    QString tmpStr("");
    state->skeletonState->mergeOnLoadFlag = isMerge;
    emit signalDelegate->loadSkeleton(filename, tmpStr, &isSuccess);
    state->skeletonState->mergeOnLoadFlag = isMergePrevValue;
    if (!isSuccess) {
        emit echo(QString("could not load from %1").arg(filename));
        return false;
    }
    return true;
}

bool SkeletonProxy::annotation_save(const QString &filename) {
    bool isSuccess = false;
    emit signalDelegate->saveSkeleton(filename, &isSuccess);
    if (!isSuccess) {
        emit echo(QString("could not save to %1").arg(filename));
        return false;
    }
    return true;
}

// TEST LATER
void SkeletonProxy::export_converter(const QString &path) {
    QDir dir(path);
    if(!dir.exists()) {
        emit echo("path does not exist");
        return;
    }

    QFile targetFile(path + "converter.py");
    if(!targetFile.open(QIODevice::WriteOnly)) {
        emit echo("error creating a file in this path");
        return;
    }

    QTextStream stream(&targetFile);

    QFile converter(":/misc/python/converter.py");
    if(!converter.open(QIODevice::ReadOnly)) {
        emit echo("error while reading the converter from the resource directory");
        return;
    }

    stream << converter.readAll();

    converter.close();
    targetFile.close();

    emit echo("exported to (" + targetFile.fileName() + ")");

}

segmentListElement *SkeletonProxy::find_segment(int source_id, int target_id) {
    return Skeletonizer::findSegmentByNodeIDs(source_id, target_id);
}

bool SkeletonProxy::jump_to_active_node() {
    bool isSuccess = false;
    Skeletonizer::singleton().jumpToActiveNode(&isSuccess);
    return isSuccess;
}

bool SkeletonProxy::has_unsaved_changes() {
    return state->skeletonState->unsavedChanges;
}

void SkeletonProxy::delete_skeleton() {
    emit signalDelegate->clearSkeletonSignal();
}

bool SkeletonProxy::delete_segment(int source_id, int target_id) {
    if(!Skeletonizer::delSegment(source_id, target_id, NULL)) {
        emit echo(QString("could not delete the segment with source id %1 and target id %2").arg(source_id).arg(target_id));
        return false;
    }
    return true;
}

bool SkeletonProxy::delete_node(int node_id) {
    if (!Skeletonizer::singleton().delNode(node_id, NULL)) {
        emit echo(QString("could not delete the node with id %1").arg(node_id));
        return false;
    }
    return true;
}

bool SkeletonProxy::set_active_node(int node_id) {
    if (!Skeletonizer::singleton().setActiveNode(0, node_id)) {
        emit echo(QString("could not set the node with id %1 to active node").arg(node_id));
        return false;
    }
    return true;
}

nodeListElement *SkeletonProxy::active_node() {
    return state->skeletonState->activeNode;
}

bool SkeletonProxy::add_node(int node_id, int x, int y, int z, int parent_tree_id, float radius, int inVp, int inMag, int time) {
    Coordinate coordinate(x, y, z);
    if (!Skeletonizer::singleton().addNode(node_id, radius, parent_tree_id, &coordinate, inVp, inMag, time, false)) {
        emit echo(QString("could not add the node with node id %1").arg(node_id));
        return false;
    }
    return true;
}

QList<treeListElement *> *SkeletonProxy::trees() {
    QList<treeListElement *> *trees = new QList<treeListElement *>();
    treeListElement *currentTree = state->skeletonState->firstTree;
    while (currentTree) {
        trees->append(currentTree);
        currentTree = currentTree->next;
    }
    return trees;
}

// UNTESTED
bool SkeletonProxy::add_tree(int tree_id, float r, float g, float b, float a) {
    color4F color(r, g, b, a);
    treeListElement *theTree = Skeletonizer::singleton().addTreeListElement(tree_id, color);
    if (!theTree) {
        emit echo(QString("could not add the tree with tree id %1").arg(tree_id));
        return false;
    }
    return true;
}

bool SkeletonProxy::set_tree_comment(int tree_id, const QString &comment) {
    if (!Skeletonizer::singleton().addTreeComment( tree_id, comment.toLocal8Bit().data())) {
        emit echo(QString("could not set tree (id %1) comment").arg(tree_id));
        return false;
    }
    return true;
}

bool SkeletonProxy::set_active_tree(int tree_id) {
    if (!Skeletonizer::singleton().setActiveTreeByID(tree_id)) {
        emit echo(QString("could not set active tree (id %1)").arg(tree_id));
        return false;
    }
    return true;
}

bool SkeletonProxy::set_comment(int node_id, char *comment) {
    return Skeletonizer::singleton().setComment(comment, NULL, node_id);
}

bool SkeletonProxy::delete_comment(int node_id) {
    return Skeletonizer::singleton().delComment(NULL, node_id);
}

bool SkeletonProxy::add_segment(int source_id, int target_id) {
    if (!Skeletonizer::addSegment(source_id, target_id)) {
        emit echo(QString("could not add a segment with source id %1 and target id %2").arg(source_id).arg(target_id));
        return false;
    }
    return true;
}

bool SkeletonProxy::set_branch_node(int node_id) {
    nodeListElement *currentNode = Skeletonizer::findNodeByNodeID(node_id);
    if(NULL == currentNode) {
        emit echo(QString("no node with id %1 found").arg(node_id));
        return false;
    }
    if (!Skeletonizer::singleton().pushBranchNode(true, false, currentNode, 0)) {
        emit echo(QString("An unexpected error occured while adding a branch node"));
        return false;
    }
    return true;
}


QByteArray SkeletonProxy::readDc2Pointer(int x, int y, int z) {
    Coordinate position(x, y, z);
    Byte *data = Coordinate2BytePtr_hash_get_or_fail(state->Dc2Pointer[(int)std::log2(state->magnification)], position);
    if(!data) {
        emit echo(QString("no cube data found at Coordinate (%1, %2, %3)").arg(x).arg(y).arg(z));
        return QByteArray();
    }

    return QByteArray::fromRawData((const char*)data, state->cubeBytes);
}

int SkeletonProxy::readDc2PointerPos(int x, int y, int z, int pos) {
    Coordinate position(x, y, z);
    Byte *data = Coordinate2BytePtr_hash_get_or_fail(state->Dc2Pointer[(int)std::log2(state->magnification)], position);
    if(!data) {
        emit echo(QString("no cube data found at Coordinate (%1, %2, %3)").arg(x).arg(y).arg(z));
        return -1;
    }

    return data[pos];
}

bool SkeletonProxy::writeDc2Pointer(int x, int y, int z, char *bytes) {
    Coordinate position(x, y, z);
    Byte *data = Coordinate2BytePtr_hash_get_or_fail(state->Dc2Pointer[(int)std::log2(state->magnification)], position);
    if(!data) {
        emit echo(QString("no cube data found at Coordinate (%1, %2, %3)").arg(x).arg(y).arg(z));
        return false;
    }

    memcpy(data, bytes, state->cubeBytes);
    return true;
}

bool SkeletonProxy::writeDc2PointerPos(int x, int y, int z, int pos, int val) {
    Coordinate position(x, y, z);
    Byte *data = Coordinate2BytePtr_hash_get_or_fail(state->Dc2Pointer[(int)std::log2(state->magnification)], position);
    if(!data) {
        emit echo(QString("no cube data found at Coordinate (%1, %2, %3)").arg(x).arg(y).arg(z));
        return false;
    }

    data[pos] = val;
    return true;
}

QByteArray SkeletonProxy::readOc2Pointer(int x, int y, int z) {
    Coordinate position(x, y, z);
    Byte *data = Coordinate2BytePtr_hash_get_or_fail(state->Oc2Pointer[(int)std::log2(state->magnification)], position);
    if(!data) {
        emit echo(QString("no cube data found at Coordinate (%1, %2, %3)").arg(x).arg(y).arg(z));
        return QByteArray();
    }

    return QByteArray::fromRawData((const char*)data, state->cubeBytes * OBJID_BYTES);
}

quint64 SkeletonProxy::readOc2PointerPos(int x, int y, int z, int pos) {
    Coordinate position(x, y, z);
    quint64 *data = (quint64 *)Coordinate2BytePtr_hash_get_or_fail(state->Dc2Pointer[(int)std::log2(state->magnification)], position);
    if(!data) {
        emit echo(QString("no cube data found at Coordinate (%1, %2, %3)").arg(x).arg(y).arg(z));
        return -1;
    }

    return data[pos];
}

bool SkeletonProxy::writeOc2Pointer(int x, int y, int z, char *bytes) {
    Coordinate position(x, y, z);
    Byte *data = Coordinate2BytePtr_hash_get_or_fail(state->Oc2Pointer[(int)std::log2(state->magnification)], position);
    if(!data) {
        emit echo(QString("no cube data found at Coordinate (%1, %2, %3)").arg(x).arg(y).arg(z));
        return false;
    }

    memcpy(data, bytes, state->cubeBytes * OBJID_BYTES);
    return true;
}

bool SkeletonProxy::writeOc2PointerPos(int x, int y, int z, int pos, quint64 val) {
    Coordinate position(x, y, z);
    quint64 *data = (quint64 *)Coordinate2BytePtr_hash_get_or_fail(state->Oc2Pointer[(int)std::log2(state->magnification)], position);
    if(!data) {
        emit echo(QString("no cube data found at Coordinate (%1, %2, %3)").arg(x).arg(y).arg(z));
        return false;
    }

    data[pos] = val;
    return true;
}

void SkeletonProxy::set_current_position(int x, int y, int z) {
    emit signalDelegate->userMoveSignal(x, y, z, USERMOVE_NEUTRAL, VIEWPORT_UNDEFINED);
}

Coordinate SkeletonProxy::get_current_position() {
    return state->viewerState->currentPosition;
}

// UNTESTED
bool SkeletonProxy::loadStyleSheet(const QString &filename) {
    QFile file(filename);
    if(!file.open(QIODevice::ReadOnly)) {
        emit echo("Error reading the style sheet file");
        return false;
    }

    QString design(file.readAll());

    qApp->setStyleSheet(design);
    file.close();
    return true;
}



QString SkeletonProxy::help() {
    return QString("This is the unique main interface between python and knossos. You can't create a separate instance of this object:" \
                   "\n\n skeleton_time() : return the skeleton time" \
                   "\n\n skeleton_file() : returns the file from which the current skeleton is loaded" \
                   "\n from_xml(filename) : loads a skeleton from a .nml file" \
                   "\n to_xml(filename) : saves a skeleton to a .nml file" \
                   "\n has_unsaved_changes() : self-explaining" \
                   "\n active_node() : returns the active node object" \
                   "\n delete_skeleton() : deletes the entire skeleton." \
                   "\n delete_tree(tree_id) : deletes the tree with the passed id. Returns a message if no such tree exists." \
                   "\n delete_active_tree() : deletes the active tree or informs about that no active tree could be deleted." \
                   "\n find_tree_by_id(tree_id) : returns the searched tree or returns None" \
                   "\n first_tree() : returns the first tree of the knossos skeleton" \
                   "\n tree_with_previous_id(tree_id) : returns the tree with a previous id or None" \
                   "\n tree_with_next_id(tree_id) : returns the tree with the next id or None" \
                   "\n trees() : returns a list of trees" \
                   "\n add_tree(tree_id, comment, r, g, b, a) : adds a new tree. All parameter are optional." \
                   "\n knossos will give the next free tree id and uses the color lookup table to determine a color" \
                   "\n merge_trees(id1, id2) : merges two different trees to a single one. " \
                   "\n move_to_next_tree() : moves the viewer to the next tree" \
                   "\n move_to_prev_tree() : moves the viewer to the previosu tree" \
                   "\n export_converter(path) : creates a python class in the path which can be used to convert between the NewSkeleton class and KNOSSOS." \
                   "\n set_branch_node(node_id) : sets the node with node_id to branch_node" \
                   "\n add_segment(source_id, target_id) : adds a segment for the nodes. Both nodes must be added before" \
                   "\n delete_active_node() : deletes the active node or informs about that no active node could be deleted" \
                   "\n delete_segment(source_id, target_id) : deletes a segment with source" \
                   "\n add_comment(node_id) : adds a comment for the node. Must be added before" \

                   "\n\t If does not mind if no color is specified. The lookup table sets this automatically." \
                   "\n\n add_node(node_id, x, y, z, parent_id (opt), radius (opt), viewport (opt), mag (opt), time (opt))" \
                   "\n\t adds a node for a parent tree where a couple of parameter are optional. " \
                   "\n\t if no parent_id is set then the current active node will be chosen." \

                   "\n cube_data_at(x, y, z) : returns the data cube at the viewport position (x, y, z) as a string containing 128 * 128 * 128 bytes (2MB) of grayscale values. " \
                   "\n move_to(x, y, z) : recenters the viewport coordinates to (x, y, z)" \
                   "\n save_working_directory(path) : saves the working directory from the console");
}
