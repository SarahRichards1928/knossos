#ifndef PYTHONPROXY_H
#define PYTHONPROXY_H

#include <QObject>
#include <QList>
#include "knossos-global.h"

class PythonProxy : public QObject
{
    Q_OBJECT
public:
    explicit PythonProxy(QObject *parent = 0);

signals:

public slots:
    QList<int> getOcPixel(QList<int> Dc, QList<int> pxInDc);
    QList<int> getPosition();
};

#endif // PYTHONPROXY_H
