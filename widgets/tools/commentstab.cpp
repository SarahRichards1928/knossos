#include "commentstab.h"
#include "widgets/GuiConstants.h"

#include <QColorDialog>
#include <QComboBox>
#include <QDebug>
#include <QHeaderView>
#include <QInputDialog>
#include <QPushButton>
#include <QSettings>
#include <QVBoxLayout>

void CommentsModel::fill() {
    beginResetModel();
    for(int i = 1; i < 11; ++i) {
        CommentSetting::comments.emplace_back(QString("F%0").arg(i));
    }
    endResetModel();
}

QVariant CommentsModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole) {
        return header[section];
    } else {
        return QVariant();  //return invalid QVariant
    }
}

QVariant CommentsModel::data(const QModelIndex & index, int role) const {
    if (index.isValid()) {
        const auto & comment = CommentSetting::comments[index.row()];
        if (index.column() == 2 && role == Qt::BackgroundRole) {
            return comment.color;
        } else if (role == Qt::DisplayRole || role == Qt::EditRole) {
            switch (index.column()) {
            case 0: return comment.shortcut;
            case 1: return comment.text;
            case 3: return comment.nodeRadius;
            }
        }
        return QVariant(); //return invalid QVariant
    }
    return QVariant(); //return invalid QVariant
}

bool CommentsModel::setData(const QModelIndex & index, const QVariant & value, int role) {
    if (index.isValid()) {
        auto & comment = CommentSetting::comments[index.row()];

        if (role == Qt::DisplayRole || role == Qt::EditRole) {
            switch (index.column()) {
            case 1: comment.text = value.toString(); break;
            case 3: {
                bool success = false;
                float radius = value.toFloat(&success);
                comment.nodeRadius = success ? radius : comment.nodeRadius;
                break;
            }
            default:
                return false;
            }
        }
        return true;
    }
    return true;
}

int CommentsModel::columnCount(const QModelIndex &) const {
    return header.size();
}

int CommentsModel::rowCount(const QModelIndex &) const {
    return CommentSetting::comments.size();
}

Qt::ItemFlags CommentsModel::flags(const QModelIndex & index) const {
    auto flags = QAbstractItemModel::flags(index);
    return (index.column() == 0) ? flags | Qt::ItemNeverHasChildren : flags | Qt::ItemIsEditable;
}

void CommentsTab::itemDoubleClicked(const QModelIndex &index) {
    auto & comment = CommentSetting::comments[index.row()];
    if (index.column() == 2) {
        auto color = QColorDialog::getColor(comment.color, this, "Select comment color", QColorDialog::ShowAlphaChannel);
        if (color.isValid() == QColorDialog::Accepted) {
            comment.color = color;
        }
    }
}


CommentsTab::CommentsTab(QWidget *parent) : QWidget(parent) {
    auto mainlayout = new QVBoxLayout();

    auto checkboxLayout = new QHBoxLayout();
    checkboxLayout->addWidget(&useCommentColorsCheckbox);
    checkboxLayout->addWidget(&useCommentRadiusCheckbox);
    QObject::connect(&useCommentColorsCheckbox, &QCheckBox::stateChanged, [](bool checked) { CommentSetting::useCommentColors = checked; });
    QObject::connect(&useCommentRadiusCheckbox, &QCheckBox::stateChanged, [](bool checked) { CommentSetting::useCommentNodeRadius = checked; });

    commentsTable.setModel(&commentModel);
    commentsTable.setAllColumnsShowFocus(true);
    commentsTable.header()->setStretchLastSection(false);
    commentsTable.header()->setSectionResizeMode(1, QHeaderView::Stretch);
    commentsTable.setSelectionMode(QAbstractItemView::ExtendedSelection);
    for (const auto & index : {0, 2, 3}) {
        commentsTable.resizeColumnToContents(index);
    }
    QObject::connect(&commentsTable, &QTreeView::doubleClicked, this, &CommentsTab::itemDoubleClicked);

    mainlayout->addLayout(checkboxLayout);
    mainlayout->addWidget(&commentsTable);
    setLayout(mainlayout);

    commentModel.fill();
}

CommentsTab::~CommentsTab() {}

void CommentsTab::loadSettings() {
    QSettings settings;
    settings.beginGroup(COMMENTS_TAB);
    for(int i = 0; i < 10; ++i) {
        CommentSetting::comments[i].text = settings.value(QString("comment%0").arg(i+1)).toString();
        CommentSetting::comments[i].color = settings.value(QString("color%0").arg(i+1), QColor(255, 255, 0, 255)).value<QColor>();
        CommentSetting::comments[i].nodeRadius = settings.value(QString("radius%0").arg(i+1), 1.5).toFloat();
    }
    useCommentColorsCheckbox.setChecked(settings.value(CUSTOM_COMMENT_COLOR, false).toBool());
    useCommentRadiusCheckbox.setChecked(settings.value(CUSTOM_COMMENT_NODERADIUS, false).toBool());
    settings.endGroup();
}

void CommentsTab::saveSettings() {
    QSettings settings;
    settings.beginGroup(COMMENTS_TAB);
    for(int i = 0; i < 10; ++i) {
        settings.setValue(QString("comment%0").arg(i+1), CommentSetting::comments[i].text);
        settings.setValue(QString("color%0").arg(i+1), CommentSetting::comments[i].color);
        settings.setValue(QString("radius%0").arg(i+1), CommentSetting::comments[i].nodeRadius);
    }

    settings.setValue(CUSTOM_COMMENT_COLOR, useCommentColorsCheckbox.isChecked());
    settings.setValue(CUSTOM_COMMENT_NODERADIUS, useCommentRadiusCheckbox.isChecked());
    settings.endGroup();
}
