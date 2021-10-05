#ifndef ALBUMLISTWIDGET_H
#define ALBUMLISTWIDGET_H

#include <QWidget>
#include <QItemSelectionModel>

namespace Ui {
class AlbumListWidget;
}

class AlbumModel;
class AlbumListWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AlbumListWidget(QWidget *parent = nullptr);
    ~AlbumListWidget();

    void SetModel(AlbumModel* Model);
    void SetSelectionModel(QItemSelectionModel* SelectionModel);

private slots:
    void CreateAlbum();
private:
    Ui::AlbumListWidget *ui;
    AlbumModel* m_AlbumModel;
};

#endif // ALBUMLISTWIDGET_H
