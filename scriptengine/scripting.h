#ifndef SCRIPTING_H
#define SCRIPTING_H

#include <QObject>
#include <QThread>
#include <PythonQt/PythonQt.h>
#ifdef QtAll
#include <PythonQt/PythonQt_QtAll.h>
#endif
#include <PythonQt/PythonQtClassInfo.h>
#include <PythonQt/PythonQtPythonInclude.h>
#include <PythonQt/PythonQtStdIn.h>

class ColorDecorator;
class FloatCoordinateDecorator;
class CoordinateDecorator;
class TreeListDecorator;
class NodeListDecorator;
class NodeCommentDecorator;
class SegmentListDecorator;
class MeshDecorator;
class SkeletonProxy;
class TransformDecorator;
class PointDecorator;
class Highlighter;
class QSettings;
class PythonQtObjectPtr;

void PythonQtInit();

/** This class intializes the python qt engine */
class Scripting : public QObject
{
    Q_OBJECT
public:
    explicit Scripting();
    CoordinateDecorator *coordinateDecorator;
    FloatCoordinateDecorator *floatCoordinateDecorator;
    ColorDecorator *colorDecorator;
    TreeListDecorator *treeListDecorator;
    NodeListDecorator *nodeListDecorator;
    NodeCommentDecorator *nodeCommentDecorator;
    SegmentListDecorator *segmentListDecorator;
    MeshDecorator *meshDecorator;
    SkeletonProxy *skeletonProxy;
    TransformDecorator *transformDecorator;
    PointDecorator *pointDecorator;
    Highlighter *highlighter;
signals:

public slots:
    static void addScriptingObject(const QString &name, QObject *obj);
    void saveSettings(const QString &key, const QVariant &value);
    void executeFromUserDirectory();
    void changeWorkingDirectory();
    void addWidgets(PythonQtObjectPtr &context);
protected:
    QSettings *settings;
};

#endif // SCRIPTING_H
