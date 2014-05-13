#ifndef SEGMENTATIONTAB_H
#define SEGMENTATIONTAB_H

#include <functional>

#include <QAbstractTableModel>
#include <QLabel>
#include <QTableView>
#include <QVBoxLayout>
#include <QWidget>

#include "segmentation.h"

class SegmentationObjectModel : public QAbstractTableModel {
Q_OBJECT
    std::vector<std::reference_wrapper<Segmentation::Object>> objectCache;
public:
    int rowCount(const QModelIndex & parent = QModelIndex()) const override;
    int columnCount(const QModelIndex & parent = QModelIndex()) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const override;
    void recreate();
};

class SegmentationTab : public QWidget {
Q_OBJECT
    QVBoxLayout layout;
    SegmentationObjectModel objectModel;
    QTableView objectesTable;
    QLabel objectCountLabel;
    QLabel subobjectCountLabel;
    QHBoxLayout bottomHLayout;
public:
    explicit SegmentationTab(QWidget & parent);
    void updateLabels();
};

#endif // SEGMENTATIONTAB_H
